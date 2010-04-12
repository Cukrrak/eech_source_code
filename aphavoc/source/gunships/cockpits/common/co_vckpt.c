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

#define DEBUG_MODULE 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

object_3d_instance
	*virtual_cockpit_inst3d;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float
	pilot_head_pitch_datum,
	co_pilot_head_pitch_datum;

cockpit_switch
	*engine_start_switch_animation_object,
	*apu_start_switch_animation_object,
	*apu_stop_switch_animation_object;

static vec3d
	gunship_periscope_position[NUM_GUNSHIP_TYPES][2];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pre_initialise_common_virtual_cockpit (void)
{
	engine_start_switch_animation_object = NULL;
	apu_start_switch_animation_object = NULL;
	apu_stop_switch_animation_object = NULL;
}

void initialise_common_virtual_cockpit (void)
{
	initialise_common_virtual_cockpit_wiper_and_rain_effect ();
	
	memset(gunship_periscope_position, 0, sizeof(gunship_periscope_position));
	gunship_periscope_position[GUNSHIP_TYPE_HOKUM][0].x = -0.05f;
	gunship_periscope_position[GUNSHIP_TYPE_HOKUM][1].x =  0.05f;
	gunship_periscope_position[GUNSHIP_TYPE_HOKUM][0].y = -0.05f;
	gunship_periscope_position[GUNSHIP_TYPE_HOKUM][1].y =  0.05f;
	gunship_periscope_position[GUNSHIP_TYPE_HOKUM][0].z = 0.275;
	gunship_periscope_position[GUNSHIP_TYPE_HOKUM][1].z = 1.00;

	gunship_periscope_position[GUNSHIP_TYPE_APACHE][0].x = -0.05f;
	gunship_periscope_position[GUNSHIP_TYPE_APACHE][1].x =  0.05f;
	gunship_periscope_position[GUNSHIP_TYPE_APACHE][0].y = -0.080;
	gunship_periscope_position[GUNSHIP_TYPE_APACHE][1].y = -0.020;
	gunship_periscope_position[GUNSHIP_TYPE_APACHE][0].z = 0.175;
	gunship_periscope_position[GUNSHIP_TYPE_APACHE][1].z = 1.00;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_common_virtual_cockpit (void)
{
	deinitialise_common_virtual_cockpit_wiper_and_rain_effect ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_common_virtual_cockpit (void)
{
	update_common_virtual_cockpit_wiper_and_rain_effect ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void damage_virtual_cockpit_main_rotors (int seed)
{
	switch (get_global_gunship_type ())
	{
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		{
			damage_apache_virtual_cockpit_main_rotors (seed);

			break;
		}
		case GUNSHIP_TYPE_HAVOC:
		{
			damage_havoc_virtual_cockpit_main_rotors (seed);

			break;
		}
		case GUNSHIP_TYPE_COMANCHE:
		{
			damage_comanche_virtual_cockpit_main_rotors (seed);

			break;
		}
		case GUNSHIP_TYPE_HOKUM:
		{
			damage_hokum_virtual_cockpit_main_rotors (seed);

			break;
		}
		////Moje 030518 Start
		case GUNSHIP_TYPE_BLACKHAWK:
		{
			damage_blackhawk_virtual_cockpit_main_rotors (seed);

			break;
		}

		////Moje 030518 End
		////Moje 030612 Start
		case GUNSHIP_TYPE_HIND:
		{
			if (custom_3d_models.arneh_mi24v_cockpit)
				damage_hind_3d_cockpit_main_rotors (seed);
			else
				damage_hind_virtual_cockpit_main_rotors (seed);

			break;
		}
		////Moje 030612 End
		////Moje 030816 Start
		case GUNSHIP_TYPE_AH64A:
		{
			damage_ah64a_virtual_cockpit_main_rotors (seed);

			break;
		}
		case GUNSHIP_TYPE_KA50:
		{
			damage_ka50_virtual_cockpit_main_rotors (seed);
			break;
		}
		////Moje 030816 End
		// GCsDriver  08-12-2007
		default:
		{
			damage_default_virtual_cockpit_main_rotors (seed);

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void restore_virtual_cockpit_main_rotors (void)
{
	switch (get_global_gunship_type ())
	{
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		{
			restore_apache_virtual_cockpit_main_rotors ();

			break;
		}
		case GUNSHIP_TYPE_HAVOC:
		{
			restore_havoc_virtual_cockpit_main_rotors ();

			break;
		}
		case GUNSHIP_TYPE_COMANCHE:
		{
			restore_comanche_virtual_cockpit_main_rotors ();

			break;
		}
		case GUNSHIP_TYPE_HOKUM:
		{
			restore_hokum_virtual_cockpit_main_rotors ();

			break;
		}
		////Moje 030518 Start
		case GUNSHIP_TYPE_BLACKHAWK:
		{
			restore_blackhawk_virtual_cockpit_main_rotors ();

			break;
		}
		////Moje 030518 End
		////Moje 030612 Start
		case GUNSHIP_TYPE_HIND:
		{
			if (custom_3d_models.arneh_mi24v_cockpit)
				restore_hind_3d_cockpit_main_rotors ();
			else
				restore_hind_virtual_cockpit_main_rotors ();

			break;
		}
		////Moje 030612 End
		////Moje 030816 Start
		case GUNSHIP_TYPE_AH64A:
		{
			restore_ah64a_virtual_cockpit_main_rotors ();

			break;
		}
		case GUNSHIP_TYPE_KA50:
		{
			restore_ka50_virtual_cockpit_main_rotors ();
			break;
		}
		////Moje 030816 End
		// GCsDriver  08-12-2007
		default:
		{
			restore_default_virtual_cockpit_main_rotors ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int TIR_looking_in_periscope(void)
{
	gunship_types ship = get_global_gunship_type();

	float x, y, z;

	if (get_local_entity_int_value (get_pilot_entity (), INT_TYPE_CREW_ROLE) != CREW_ROLE_CO_PILOT)
		return FALSE;

	x = wide_cockpit_position[wide_cockpit_nr].x - current_custom_cockpit_viewpoint.x;
	y = wide_cockpit_position[wide_cockpit_nr].y - current_custom_cockpit_viewpoint.y;
	z = wide_cockpit_position[wide_cockpit_nr].z - current_custom_cockpit_viewpoint.z;

	if (pilot_head_heading < rad(-10.0) || pilot_head_heading > rad(10.0)
		|| pilot_head_pitch < rad(-30.0) || pilot_head_pitch > rad(10.0))
	{
		return FALSE;
	}

	if (gunship_periscope_position[ship][0].x < x &&
		gunship_periscope_position[ship][1].x > x &&
		gunship_periscope_position[ship][0].y < y &&
		gunship_periscope_position[ship][1].y > y &&
		gunship_periscope_position[ship][0].z < z &&
		gunship_periscope_position[ship][1].z > z)
	{
		return TRUE;	
	}

	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_virtual_cockpit_periscope_mask (int x_min, int x_max, int monoccular)
{
	vertex
		quad[4];

	real_colour
		colour,
		specular;

	float
		x_texture_limit = 1.0,
		y_texture_limit = 0.0;

	if (monoccular)
	{
		x_texture_limit = 0.6f;
		y_texture_limit = 0.15f;
	}

	set_3d_active_environment (main_3d_env);

	if (begin_3d_scene ())
	{
		colour.red		= 255;
		colour.green	= 255;
		colour.blue		= 255;
		colour.alpha	= 255;

		specular.red	= 0;
		specular.green	= 0;
		specular.blue	= 0;
		specular.alpha	= 255;

		set_d3d_transparency_on ();

		set_d3d_zbuffer_comparison (FALSE);

		set_d3d_culling (FALSE);

		set_d3d_texture_wrapping (0, FALSE);

		set_d3d_texture_filtering (FALSE);

		set_d3d_flat_shaded_textured_renderstate (get_system_texture_ptr (TEXTURE_INDEX_HOKUM_COCKPIT_WSO_SCOPE_VIEW));

		////////////////////////////////////////
		//
		// top left
		//
		////////////////////////////////////////

		quad[0].i 				= x_min;
		quad[0].j  				= full_screen_y_min;
		quad[0].z  				= 0.5;
		quad[0].q  				= 0.5;
		quad[0].u  				= 0.0;
		quad[0].v				= y_texture_limit;

		quad[1].i  				= full_screen_x_mid;
		quad[1].j  				= full_screen_y_min;
		quad[1].z  				= 0.5;
		quad[1].q  				= 0.5;
		quad[1].u  				= x_texture_limit;
		quad[1].v  				= y_texture_limit;

		quad[2].i				= full_screen_x_mid;
		quad[2].j  				= full_screen_y_mid;
		quad[2].z  				= 0.5;
		quad[2].q  				= 0.5;
		quad[2].u  				= x_texture_limit;
		quad[2].v  				= 1.0;

		quad[3].i  				= x_min;
		quad[3].j  				= full_screen_y_mid;
		quad[3].z  				= 0.5;
		quad[3].q  				= 0.5;
		quad[3].u				= 0.0;
		quad[3].v				= 1.0;

		quad[0].next_vertex	= &quad[1];
		quad[1].next_vertex	= &quad[2];
		quad[2].next_vertex	= &quad[3];
		quad[3].next_vertex	= NULL;

		draw_wbuffered_flat_shaded_textured_polygon (quad, colour, specular);

		////////////////////////////////////////
		//
		// bottom left
		//
		////////////////////////////////////////

		quad[0].i 				= x_min;
		quad[0].j  				= full_screen_y_mid;
		quad[0].z  				= 0.5;
		quad[0].q  				= 0.5;
		quad[0].u  				= 0.0;
		quad[0].v				= 1.0;

		quad[1].i  				= full_screen_x_mid;
		quad[1].j  				= full_screen_y_mid;
		quad[1].z  				= 0.5;
		quad[1].q  				= 0.5;
		quad[1].u  				= x_texture_limit;
		quad[1].v  				= 1.0;

		quad[2].i				= full_screen_x_mid;
		quad[2].j  				= full_screen_y_max;
		quad[2].z  				= 0.5;
		quad[2].q  				= 0.5;
		quad[2].u  				= x_texture_limit;
		quad[2].v  				= y_texture_limit;

		quad[3].i  				= x_min;
		quad[3].j  				= full_screen_y_max;
		quad[3].z  				= 0.5;
		quad[3].q  				= 0.5;
		quad[3].u				= 0.0;
		quad[3].v				= y_texture_limit;

		quad[0].next_vertex	= &quad[1];
		quad[1].next_vertex	= &quad[2];
		quad[2].next_vertex	= &quad[3];
		quad[3].next_vertex	= NULL;

		draw_wbuffered_flat_shaded_textured_polygon (quad, colour, specular);

		////////////////////////////////////////
		//
		// top right
		//
		////////////////////////////////////////

		quad[0].i 				= full_screen_x_mid;
		quad[0].j  				= full_screen_y_min;
		quad[0].z  				= 0.5;
		quad[0].q  				= 0.5;
		quad[0].u  				= x_texture_limit;
		quad[0].v				= y_texture_limit;

		quad[1].i  				= x_max;
		quad[1].j  				= full_screen_y_min;
		quad[1].z  				= 0.5;
		quad[1].q  				= 0.5;
		quad[1].u  				= 0.0;
		quad[1].v  				= y_texture_limit;

		quad[2].i				= x_max;
		quad[2].j  				= full_screen_y_mid;
		quad[2].z  				= 0.5;
		quad[2].q  				= 0.5;
		quad[2].u  				= 0.0;
		quad[2].v  				= 1.0;

		quad[3].i  				= full_screen_x_mid;
		quad[3].j  				= full_screen_y_mid;
		quad[3].z  				= 0.5;
		quad[3].q  				= 0.5;
		quad[3].u				= x_texture_limit;
		quad[3].v				= 1.0;

		quad[0].next_vertex	= &quad[1];
		quad[1].next_vertex	= &quad[2];
		quad[2].next_vertex	= &quad[3];
		quad[3].next_vertex	= NULL;

		draw_wbuffered_flat_shaded_textured_polygon (quad, colour, specular);

		////////////////////////////////////////
		//
		// bottom left
		//
		////////////////////////////////////////

		quad[0].i 				= full_screen_x_mid;
		quad[0].j  				= full_screen_y_mid;
		quad[0].z  				= 0.5;
		quad[0].q  				= 0.5;
		quad[0].u  				= x_texture_limit;
		quad[0].v				= 1.0;

		quad[1].i  				= x_max;
		quad[1].j  				= full_screen_y_mid;
		quad[1].z  				= 0.5;
		quad[1].q  				= 0.5;
		quad[1].u  				= 0.0;
		quad[1].v  				= 1.0;

		quad[2].i				= x_max;
		quad[2].j  				= full_screen_y_max;
		quad[2].z  				= 0.5;
		quad[2].q  				= 0.5;
		quad[2].u  				= 0.0;
		quad[2].v  				= y_texture_limit;

		quad[3].i  				= full_screen_x_mid;
		quad[3].j  				= full_screen_y_max;
		quad[3].z  				= 0.5;
		quad[3].q  				= 0.5;
		quad[3].u				= x_texture_limit;
		quad[3].v				= y_texture_limit;

		quad[0].next_vertex	= &quad[1];
		quad[1].next_vertex	= &quad[2];
		quad[2].next_vertex	= &quad[3];
		quad[3].next_vertex	= NULL;

		draw_wbuffered_flat_shaded_textured_polygon (quad, colour, specular);

		////////////////////////////////////////

		set_d3d_transparency_off ();

		set_d3d_zbuffer_comparison (TRUE);

		set_d3d_culling (TRUE);

		end_3d_scene ();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_switch(cockpit_switch* swch, float* position, float depress_length, float depress_time, float delay)
{
	swch->position = position;
	swch->initial_position = *position;
	swch->depress_length = depress_length * 2.0 / depress_time;
	swch->depress_time = depress_time;
	swch->delay = delay;
	swch->timer = 0.0;
}

void press_switch(cockpit_switch* swch)
{
	if (swch->timer <= 0.0)
		swch->timer = swch->depress_time + swch->delay; 
}

void animate_switch(cockpit_switch* swch)
{
	if (swch->timer <= 0.0)
		return;

	if (swch->timer < swch->depress_time)  // otherwise delay
	{
		float half_time = swch->depress_time / 2.0;

		if (swch->timer > half_time)  // pressing in
			*(swch->position) = swch->initial_position + (swch->depress_length * (swch->depress_time - swch->timer));
		else // rebounding out
			*(swch->position) = swch->initial_position + (swch->depress_length * swch->timer);
	}

	swch->timer -= get_delta_time();
}
