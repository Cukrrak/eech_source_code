// 
// 	 Enemy Engaged RAH-66 Comanche Versus KA-52 Hokum
// 	 Copyright (C) 2000 Empire Interactive (Europe) Ltd,
// 	 677 High Road, North Finchley, London N12 0DA
// 
// 	 Please see the document LICENSE.TXT for the full licence agreement
// 
// 2. LICENCE
//  2.1 	
//  	Subject to the provisions of this Agreement we now grant to you the 
//  	following rights in respect of the Source Code:
//   2.1.1 
//   	the non-exclusive right to Exploit  the Source Code and Executable 
//   	Code on any medium; and 
//   2.1.2 
//   	the non-exclusive right to create and distribute Derivative Works.
//  2.2 	
//  	Subject to the provisions of this Agreement we now grant you the
// 	following rights in respect of the Object Code:
//   2.2.1 
// 	the non-exclusive right to Exploit the Object Code on the same
// 	terms and conditions set out in clause 3, provided that any
// 	distribution is done so on the terms of this Agreement and is
// 	accompanied by the Source Code and Executable Code (as
// 	applicable).
// 
// 3. GENERAL OBLIGATIONS
//  3.1 
//  	In consideration of the licence granted in clause 2.1 you now agree:
//   3.1.1 
// 	that when you distribute the Source Code or Executable Code or
// 	any Derivative Works to Recipients you will also include the
// 	terms of this Agreement;
//   3.1.2 
// 	that when you make the Source Code, Executable Code or any
// 	Derivative Works ("Materials") available to download, you will
// 	ensure that Recipients must accept the terms of this Agreement
// 	before being allowed to download such Materials;
//   3.1.3 
// 	that by Exploiting the Source Code or Executable Code you may
// 	not impose any further restrictions on a Recipient's subsequent
// 	Exploitation of the Source Code or Executable Code other than
// 	those contained in the terms and conditions of this Agreement;
//   3.1.4 
// 	not (and not to allow any third party) to profit or make any
// 	charge for the Source Code, or Executable Code, any
// 	Exploitation of the Source Code or Executable Code, or for any
// 	Derivative Works;
//   3.1.5 
// 	not to place any restrictions on the operability of the Source 
// 	Code;
//   3.1.6 
// 	to attach prominent notices to any Derivative Works stating
// 	that you have changed the Source Code or Executable Code and to
// 	include the details anddate of such change; and
//   3.1.7 
//   	not to Exploit the Source Code or Executable Code otherwise than
// 	as expressly permitted by  this Agreement.
// 



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "project.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define DEBUG_MODULE					0

#define MAX_SMOKE_TRAIL_POINTS	200

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void draw_smoke_sprites( entity *en );

static void draw_smoke_trails( entity *en );

static void draw_smoke_trail( entity *en, int start, int end, int number_of_slots );

static void get_smoke_sprite_display_values( smoke_list *raw, int index, float lifetime, object_3d_sprite *spr, smoke_list_data *smoke_info );

static void get_smoke_trail_display_values( smoke_list *raw, float lifetime, int trail_index, smoke_list_data *smoke_info, float alpha_modifier );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void calculate_smoke_trail_points( smoke_list *raw, int start, int end, int number_of_slots );

static void calculate_trail_point_vector( smoke_list *raw, int last_point, int this_point, int next_point, int num_points );

static float calculate_trail_point_rotation_angle( smoke_list *raw, int point_index );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int
	number_of_trail_points;

// each trail consists of 2 "ribbons"
static smoke_trail_data
	*trail_data[ 2 ];

static vec3d
	*trail_points;

static float
	*trail_lifetimes;

static float
	*trail_radius;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void draw_local_3d_object (entity *en, float range)
{

	smoke_list
		*raw;

	raw = get_local_entity_data (en);

	if ( smoke_list_draw_mode( raw->smoke_type ) == SMOKE_DRAW_TYPE_SPRITES )
	{
		draw_smoke_sprites( en );
	}
	else if ( smoke_list_draw_mode( raw->smoke_type ) == SMOKE_DRAW_TYPE_TRAILS )
	{
		draw_smoke_trails( en );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void draw_smoke_sprites( entity *en )
{

	smoke_list
		*raw;

	object_3d_sprite
		spr;

	float
		lifetime,
		dt;

	int
		ds,
		current,
		loop,
		number_of_slots;

	vec3d
		*smoke_pos;

	smoke_list_data
		*smoke_info;

	raw = get_local_entity_data( en );

	smoke_info = &(smoke_list_database[ raw->smoke_type ]);

	number_of_slots = raw->smoke_lifetime / raw->frequency;

	#if DEBUG_MODULE

	debug_log ("SMOKE LIST: drawing %d smoke puff(s)", raw->alive_count);

	#endif

	//
	// calculate the difference in "age" between successive slots
	//

	dt = raw->frequency;

	current = raw->head;

	for ( loop = 0 ; loop < number_of_slots ; loop ++ )
	{
		current --;

		if ( current < 0 )
		{
			current = number_of_slots - 1;
		}

		if ( !raw->valid[ current ] )
		{
			continue;
		}

		//
		// determine how long the current smoke puff has been "living"
		//

		ds = ( raw->tail - current ) - 1;

		if ( ds < 0 )
		{
			ds += number_of_slots;
		}

		//integer part
		lifetime = ds * dt;

		//fractional part
		lifetime += ( raw->frequency - raw->smoke_sleep );

//		debug_log( "Alive count %d ( num slots = %d ), ds = %d ( %d ), int lifetime = %f, lifetime = %f",
//							raw->alive_count, number_of_slots, ds, ( raw->tail - current ), ( ds * dt ), lifetime );

		lifetime = bound( lifetime, 0.0, raw->smoke_lifetime );

		//
		// set the sprite dependant on the lifetime
		//

		get_smoke_sprite_display_values( raw, current, lifetime, &spr, smoke_info );

		smoke_pos = &(raw->position[ current ]);

		memcpy (&(spr.position), smoke_pos, sizeof (vec3d));

		insert_object_into_3d_scene (OBJECT_3D_DRAW_TYPE_SPRITE, &spr);

	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void draw_smoke_trails (entity *en)
{
	smoke_list
		*raw;

	int
		start,
		end,
		current,
		number_of_slots;

	//
	// can only draw a trail if >1 point is "alive" ( EARLY OUT )
	//

	raw = get_local_entity_data( en );

	if ( raw->alive_count < 2 )
	{
		return;
	}

	number_of_slots = raw->smoke_lifetime / raw->frequency;

	start = raw->head;

	do
	{
		//
		// find start of a trail
		//

		if ( raw->valid[ start ] )
		{

			//
			// find end of the trail
			//

			current = start;
	
			while (TRUE)
			{
				end = current;
				
				current += 1;
				
				if ( current >= number_of_slots )
				{
					current = 0;
				}

				if ( ( !raw->valid[ current ] ) || ( current == raw->head ) )
				{
					//
					// found the end
					//

					break;
				}
			}

			if ( start != end )
			{
			
				//
				// we have a valid start and end, so draw a trail
				//

				draw_smoke_trail( en, start, end, number_of_slots );
			}

			start = end + 1;
		}
		else
		{
			start += 1;
		}

		if ( start >= number_of_slots )
		{
			start = 0;
		}
	}
	while ( start != raw->head );

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void draw_smoke_trail( entity *en, int start, int end, int number_of_slots )
{
	smoke_list
		*raw;

	float
		lifetime,
		alpha_modifier,
		zb,
		dt,
		texture_distance;

	int
		current,
		ds,
		frame,
		num_points,
		loop;

	vec3d
		*smoke_pos;

	screen
		*trail_texture;

	smoke_list_data
		*smoke_info;

	raw = get_local_entity_data( en );

	smoke_info = &(smoke_list_database[ raw->smoke_type ]);

	dt = raw->frequency;

	texture_distance = raw->texture_distance;

	current = start;

	num_points = end - start;

	if ( num_points < 0 )
	{
		num_points += number_of_slots;
	}

	for ( loop = 0 ; loop <= num_points ; loop ++ )
	{
		if ( loop >= MAX_SMOKE_TRAIL_POINTS )
		{
			debug_log( "smoke trail has > %d points ( %d )", MAX_SMOKE_TRAIL_POINTS, number_of_slots );

			return;
		}

		//
		// determine how long the current smoke puff has been "living"
		//

		smoke_pos = &(raw->position[ current ]);

		if ( ( smoke_info->lock_to_parent ) && ( loop == num_points ) && ( raw->generator_lifetime > 0.0 ) )
		{
			get_new_smoke_position (en, &(trail_points [loop]));

			lifetime = 0.0;		// shouldn't really be here as it might cause problems if there are more than 1 trail per smokelist
		}
		else
		{
			memcpy (&(trail_points[ loop ]), smoke_pos, sizeof (vec3d));

			ds = ( raw->tail - current ) - 1;

			if ( ds < 0 )
			{
				ds += number_of_slots;
			}

			//integer part
			lifetime = ds * dt;

			//fractional part
			lifetime += ( raw->frequency - raw->smoke_sleep );

			lifetime = bound( lifetime, 0.0, raw->smoke_lifetime );
		}

		// fade out the ends of the trail
		if ( loop == 0 )
		{
			alpha_modifier = 0.0 + ( 0.33 * ( raw->smoke_sleep / raw->frequency ) );
		}
		else if ( loop == 1 )
		{
			alpha_modifier = 0.33 + ( 0.33 * ( raw->smoke_sleep / raw->frequency ) );
		}
		else if ( loop == 2 )
		{
			alpha_modifier = 0.66 + ( 0.33 * ( raw->smoke_sleep / raw->frequency ) );
		}
		else
		{
			alpha_modifier = 1.0;
		}
	
		get_smoke_trail_display_values( raw, lifetime, loop, smoke_info, alpha_modifier );

		trail_lifetimes[ loop ] = lifetime;

		//
		// next point
		//

		current ++;

		if ( current >= number_of_slots )
		{
			current = 0;
		}
	}

	number_of_trail_points = 0;

	calculate_smoke_trail_points( raw, start, end, number_of_slots );

	if ( number_of_trail_points < 2 )
	{
		return;
	}

	convert_float_to_int (raw->current_frame, &frame);

	trail_texture = get_texture_animation_texture_pointer ( smoke_info->texture, frame );

	if ( smoke_info->additive )
	{
		zb = -50.0;
	}
	else
	{
		zb = 0.0;
	}

	insert_zbiased_smoke_trail_into_3d_scene ( number_of_trail_points, zb, smoke_info->additive, trail_texture, texture_distance, smoke_info->texture_size, trail_data[ 0 ] );

	if ( !smoke_info->flat )
	{
		insert_zbiased_smoke_trail_into_3d_scene ( number_of_trail_points, zb, smoke_info->additive, trail_texture, texture_distance, smoke_info->texture_size, trail_data[ 1 ] );
	}

	#if DEBUG_MODULE

	debug_log( "**************************************" );

	debug_log( "SL_DRAW : %d trail points", number_of_trail_points );

	for ( loop = 0 ; loop < number_of_trail_points ; loop ++ )
	{
		debug_log ("Alpha = %d", trail_data[ 0 ][ loop ].colour.alpha);
	}

	debug_log( "**************************************" );

	#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void calculate_smoke_trail_points( smoke_list *raw, int start, int end, int number_of_slots )
{
	int
		loop,
		num_points;

	ASSERT( start != end );

	num_points = end - start;

	if ( num_points < 0 )
	{
		num_points += number_of_slots;
	}

	num_points += 1;	// add 1 because start and end are INCLUSIVE

	for ( loop = 0 ; loop < num_points ; loop ++ )
	{
		calculate_trail_point_vector( raw, loop - 1, loop, loop + 1, num_points );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void calculate_trail_point_vector( smoke_list *raw, int last_point, int this_point, int next_point, int num_points )
{
	vec3d
		*last_pos,
		*next_pos,
		*this_pos,
		v,
		dl,
		dn,
		perpendicular;

	matrix3x3
		direction_matrix,
		rotation_matrix,
		m;

	float
		mag_dl,
		mag_dn,
		mag_v,
		radius,
		rotation_angle;

	smoke_list_data
		*smoke_info;

	smoke_info = &(smoke_list_database[ raw->smoke_type ]);

	//
	// if last_point and next_point both do not exist, bomb out - this function should not have been called
	//

	if ( ( last_point < 0 ) && ( next_point >= num_points ) )
	{
		debug_fatal("SMOKE LIST : trying to draw smoke trail with only 1 point");
	}


	radius = trail_radius[ this_point ];

	if ( radius <= 0.0 )
	{
		//
		// if the radius is less then 0, don't bother drawing the point
		//

		return;
	}
	
	this_pos = &trail_points[ this_point ];

	//
	// if last_point doesn't exist, return the perpendicular of this_point--->next_point
	//

	if ( last_point < 0 )
	{
		//
		// cheat by setting last-->this to the same as this-->next
		//

		next_pos = &trail_points[ next_point ];

		dl.x = next_pos->x - this_pos->x;
		dl.y = next_pos->y - this_pos->y;
		dl.z = next_pos->z - this_pos->z;
	}
	else
	{
		last_pos = &trail_points[ last_point ];

		dl.x = this_pos->x - last_pos->x;
		dl.y = this_pos->y - last_pos->y;
		dl.z = this_pos->z - last_pos->z;
	}

	//
	// if next_point doesn't exist, return the perpendicular of last_point--->this_point
	//

	if ( next_point >= num_points )
	{
		//
		// cheat by setting this-->next to the same as last-->this
		//

		last_pos = &trail_points[ last_point ];

		dn.x = this_pos->x - last_pos->x;
		dn.y = this_pos->y - last_pos->y;
		dn.z = this_pos->z - last_pos->z;
	}
	else
	{

		next_pos = &trail_points[ next_point ];

		dn.x = next_pos->x - this_pos->x;
		dn.y = next_pos->y - this_pos->y;
		dn.z = next_pos->z - this_pos->z;
	}

	//
	// if either last point == this point, or next point == this point, skip this point
	//

	mag_dl = get_3d_vector_magnitude( &dl );
	mag_dn = get_3d_vector_magnitude( &dn );

	if ( ( mag_dl == 0.0 ) || ( mag_dn == 0.0 ) )
	{
		return;
	}

	//
	// find the average of the two unit vectors
	//

	normalise_3d_vector_given_magnitude( &dl, mag_dl );
	normalise_3d_vector_given_magnitude( &dn, mag_dn );

	v.x = dl.x + dn.x;
	v.y = dl.y + dn.y;
	v.z = dl.z + dn.z;

	mag_v = get_3d_vector_magnitude( &v );

	if ( mag_v == 0.0 )
	{
		return;
	}

	normalise_3d_vector_given_magnitude( &v, mag_v );

	//
	// set points for each ribbon
	//

	//
	// find the perpendicular to the 3d vector
	//

	get_matrix3x3_from_unit_vec3d( direction_matrix, &v );

	if ( smoke_info->flat )
	{
		memcpy( m, direction_matrix, sizeof( matrix3x3 ) );
	}
	else
	{
		rotation_angle = calculate_trail_point_rotation_angle( raw, this_point );

		get_3d_transformation_matrix( rotation_matrix, 0.0, 0.0, rotation_angle );

		multiply_matrix3x3_matrix3x3( m, rotation_matrix, direction_matrix );
	}

	//
	// use xv an zv vectors as perpendicular ( multiply by the radius to get a distance out from the centre of the trail )
	//

	// ribbon #1 ( use xv vector )

	perpendicular.x = m[ 0 ][ 0 ] * radius;
	perpendicular.y = m[ 0 ][ 1 ] * radius;
	perpendicular.z = m[ 0 ][ 2 ] * radius;

	trail_data[ 0 ][ number_of_trail_points ].point1.x = this_pos->x + perpendicular.x;
	trail_data[ 0 ][ number_of_trail_points ].point1.y = this_pos->y + perpendicular.y;
	trail_data[ 0 ][ number_of_trail_points ].point1.z = this_pos->z + perpendicular.z;

	trail_data[ 0 ][ number_of_trail_points ].point2.x = this_pos->x - perpendicular.x;
	trail_data[ 0 ][ number_of_trail_points ].point2.y = this_pos->y - perpendicular.y;
	trail_data[ 0 ][ number_of_trail_points ].point2.z = this_pos->z - perpendicular.z;

	// ribbon #2 ( use yv vector )

	perpendicular.x = m[ 1 ][ 0 ] * radius;
	perpendicular.y = m[ 1 ][ 1 ] * radius;
	perpendicular.z = m[ 1 ][ 2 ] * radius;

	trail_data[ 1 ][ number_of_trail_points ].point1.x = this_pos->x + perpendicular.x;
	trail_data[ 1 ][ number_of_trail_points ].point1.y = this_pos->y + perpendicular.y;
	trail_data[ 1 ][ number_of_trail_points ].point1.z = this_pos->z + perpendicular.z;

	trail_data[ 1 ][ number_of_trail_points ].point2.x = this_pos->x - perpendicular.x;
	trail_data[ 1 ][ number_of_trail_points ].point2.y = this_pos->y - perpendicular.y;
	trail_data[ 1 ][ number_of_trail_points ].point2.z = this_pos->z - perpendicular.z;

	#if DEBUG_MODULE

	debug_log ("Point %d = %f, %f, %f", number_of_trail_points, this_pos->x, this_pos->y, this_pos->z);

	#endif

	number_of_trail_points ++;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static float calculate_trail_point_rotation_angle( smoke_list *raw, int point_index )
{

	float
		angle;

	//
	// the trail rotates through 45 degrees per second
	//

	angle = trail_lifetimes[ point_index ] * PI_OVER_FOUR;

	return wrap_angle( angle );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_smoke_sprite_display_values( smoke_list *raw, int index, float lifetime, object_3d_sprite *spr, smoke_list_data *smoke_info )
{
	float
		d,
		lifescale,
		red_start,
		green_start,
		blue_start,
		alpha_start,
		radius_start,
		red_end,
		green_end,
		blue_end,
		alpha_end,
		radius_end;

	int
		frame,
		result,
		number_of_frames;

	lifescale = lifetime / raw->smoke_lifetime;

	if ( lifescale < smoke_info->colour_change_1 )
	{
		red_start = (float)smoke_info->red_start;
		red_end = (float)smoke_info->red_1;

		green_start = (float)smoke_info->green_start;
		green_end = (float)smoke_info->green_1;

		blue_start = (float)smoke_info->blue_start;
		blue_end = (float)smoke_info->blue_1;

		alpha_start = (float)smoke_info->alpha_start;
		alpha_end = (float)smoke_info->alpha_1;

		radius_start = (float)smoke_info->radius_start;
		radius_end = (float)smoke_info->radius_1;

		d = lifescale / smoke_info->colour_change_1;
	}
	else if ( lifescale < smoke_info->colour_change_2 )
	{
		red_start = (float)smoke_info->red_1;
		red_end = (float)smoke_info->red_2;

		green_start = (float)smoke_info->green_1;
		green_end = (float)smoke_info->green_2;

		blue_start = (float)smoke_info->blue_1;
		blue_end = (float)smoke_info->blue_2;

		alpha_start = (float)smoke_info->alpha_1;
		alpha_end = (float)smoke_info->alpha_2;

		radius_start = (float)smoke_info->radius_1;
		radius_end = (float)smoke_info->radius_2;

		d = ( lifescale - smoke_info->colour_change_1 ) / ( smoke_info->colour_change_2 - smoke_info->colour_change_1 );
	}
	else
	{
		red_start = (float)smoke_info->red_2;
		red_end = (float)smoke_info->red_end;

		green_start = (float)smoke_info->green_2;
		green_end = (float)smoke_info->green_end;

		blue_start = (float)smoke_info->blue_2;
		blue_end = (float)smoke_info->blue_end;

		alpha_start = (float)smoke_info->alpha_2;
		alpha_end = (float)smoke_info->alpha_end;

		radius_start = (float)smoke_info->radius_2;
		radius_end = (float)smoke_info->radius_end;

		d = ( lifescale - smoke_info->colour_change_2 ) / ( 1.0 - smoke_info->colour_change_2 );
	}

	d = bound( d, 0.0, 1.0 );

	//
	// set sprites colour
	// 
	
	convert_float_to_int (red_start + (d * (red_end - red_start)), &result);
	spr->red = result;

	convert_float_to_int (green_start + (d * (green_end - green_start)), &result);
	spr->green = result;

	convert_float_to_int (blue_start + (d * (blue_end - blue_start)), &result);
	spr->blue = result;

	convert_float_to_int (alpha_start + ( d * (alpha_end - alpha_start)), &result);
	spr->alpha = result;

	//
	// set sprites size
	// 
	
	result = radius_start + ( d * ( radius_end - radius_start ) );

	spr->radius = result + raw->width_adjustment;

	//
	// set sprites texture
	// 

	number_of_frames = get_texture_animation_number_of_frames ( smoke_info->texture );

	convert_float_to_int (raw->current_frame, &frame);

	frame += index;

	while (frame >= number_of_frames) frame -= number_of_frames;

	spr->texture = get_texture_animation_texture_pointer ( smoke_info->texture, frame );

	spr->additive = smoke_info->additive;

	//
	// set sprites rotation
	// 

	spr->roll = wrap_angle (raw->start_rotation[ index ] + (lifescale * PI * 0.75));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_smoke_trail_display_values( smoke_list *raw, float lifetime, int trail_index, smoke_list_data *smoke_info, float alpha_modifier )
{
	float
		d,
		lifescale,
		red_start, green_start, blue_start, alpha_start, radius_start,
		red_end, green_end, blue_end, alpha_end, radius_end,
		red_result, green_result, blue_result, alpha_result;

	int
		temp,
		trail;


	lifescale = lifetime / raw->smoke_lifetime;

	if ( lifescale < smoke_info->colour_change_1 )
	{
		red_start = (float)smoke_info->red_start;
		red_end = (float)smoke_info->red_1;

		green_start = (float)smoke_info->green_start;
		green_end = (float)smoke_info->green_1;

		blue_start = (float)smoke_info->blue_start;
		blue_end = (float)smoke_info->blue_1;

		alpha_start = (float)smoke_info->alpha_start;
		alpha_end = (float)smoke_info->alpha_1;

		radius_start = (float)smoke_info->radius_start;
		radius_end = (float)smoke_info->radius_1;

		d = lifescale / smoke_info->colour_change_1;
	}
	else if ( lifescale < smoke_info->colour_change_2 )
	{
		red_start = (float)smoke_info->red_1;
		red_end = (float)smoke_info->red_2;

		green_start = (float)smoke_info->green_1;
		green_end = (float)smoke_info->green_2;

		blue_start = (float)smoke_info->blue_1;
		blue_end = (float)smoke_info->blue_2;

		alpha_start = (float)smoke_info->alpha_1;
		alpha_end = (float)smoke_info->alpha_2;

		radius_start = (float)smoke_info->radius_1;
		radius_end = (float)smoke_info->radius_2;

		d = ( lifescale - smoke_info->colour_change_1 ) / ( smoke_info->colour_change_2 - smoke_info->colour_change_1 );
	}
	else
	{
		red_start = (float)smoke_info->red_2;
		red_end = (float)smoke_info->red_end;

		green_start = (float)smoke_info->green_2;
		green_end = (float)smoke_info->green_end;

		blue_start = (float)smoke_info->blue_2;
		blue_end = (float)smoke_info->blue_end;

		alpha_start = (float)smoke_info->alpha_2;
		alpha_end = (float)smoke_info->alpha_end;

		radius_start = (float)smoke_info->radius_2;
		radius_end = (float)smoke_info->radius_end;

		d = ( lifescale - smoke_info->colour_change_2 ) / ( 1.0 - smoke_info->colour_change_2 );
	}

	d = bound( d, 0.0, 1.0 );

	//
	// set information
	// 
	
	red_result = red_start + ( d * ( red_end - red_start ) );

	green_result = green_start + ( d * ( green_end - green_start ) );

	blue_result = blue_start + ( d * ( blue_end - blue_start ) );

	//
	// special case for alpha value if trail point is last in the list ( i.e. index == alive_count - 1 )
	//

	alpha_result = alpha_start + ( d * ( alpha_end - alpha_start ) );

	alpha_result *= alpha_modifier;

	trail_radius[ trail_index ] = ( radius_start + ( d * ( radius_end - radius_start ) ) ) + raw->width_adjustment;

	for ( trail = 0 ; trail < 2 ; trail ++ )
	{
		convert_float_to_int (red_result, &temp);
		trail_data[ trail ][ trail_index ].colour.red = temp;

		convert_float_to_int (green_result, &temp);
		trail_data[ trail ][ trail_index ].colour.green = temp;

		convert_float_to_int (blue_result, &temp);
		trail_data[ trail ][ trail_index ].colour.blue = temp;

		convert_float_to_int (alpha_result, &temp);
		trail_data[ trail ][ trail_index ].colour.alpha = temp;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_smoke_list_draw_arrays (void)
{

	trail_data[ 0 ] = safe_malloc (sizeof (smoke_trail_data) * MAX_SMOKE_TRAIL_POINTS);
	trail_data[ 1 ] = safe_malloc (sizeof (smoke_trail_data) * MAX_SMOKE_TRAIL_POINTS);

	trail_points = safe_malloc (sizeof (vec3d) * MAX_SMOKE_TRAIL_POINTS);

	trail_lifetimes = safe_malloc (sizeof (float) * MAX_SMOKE_TRAIL_POINTS);

	trail_radius = safe_malloc (sizeof (float) * MAX_SMOKE_TRAIL_POINTS);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_smoke_list_draw_arrays (void)
{

	safe_free (trail_data[ 0 ]);
	safe_free (trail_data[ 1 ]);

	safe_free (trail_points);

	safe_free (trail_lifetimes);

	safe_free (trail_radius);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_smoke_list_draw_functions (void)
{
	fn_draw_local_entity_3d_object[ENTITY_TYPE_SMOKE_LIST]	= draw_local_3d_object;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

