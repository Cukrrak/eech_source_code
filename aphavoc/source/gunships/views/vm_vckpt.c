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

#define DEBUG_MODULE						0

#define DEBUG_MODULE_SEAT_SWITCHING	0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ROTATE_RATE	(rad (135.0))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static padlock_modes
	padlock_mode;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static float get_rotate_left_limit (void)
{
	float
		limit;

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			limit = rad (90.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			limit = rad (90.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			limit = rad (90.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			limit = rad (90.0);

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			limit = rad (0.0);

			break;
		}
	}

	return (limit);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static float get_rotate_right_limit (void)
{
	float
		limit;

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			limit = rad (-90.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			limit = rad (-90.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			limit = rad (-90.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			limit = rad (-90.0);

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			limit = rad (0.0);

			break;
		}
	}

	return (limit);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static float get_rotate_up_limit (void)
{
	float
		limit;

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			limit = rad (40.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			limit = rad (40.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			limit = rad (45.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			limit = rad (45.0);

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			limit = rad (0.0);

			break;
		}
	}

	return (limit);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static float get_rotate_down_limit (void)
{
	float
		limit;

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			limit = rad (-20.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			limit = rad (-20.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			limit = rad (-45.0);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			limit = rad (-45.0);

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			limit = rad (0.0);

			break;
		}
	}

	return (limit);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_virtual_cockpit_view (void)
{
	pilot_head_vp.position.x = MID_MAP_X;
	pilot_head_vp.position.y = MID_MAP_Y;
	pilot_head_vp.position.z = MID_MAP_Z;

	get_identity_matrix3x3 (pilot_head_vp.attitude);

	//
	// stored values
	//

	stored_pilot_head_heading = rad (0.0);
	stored_pilot_head_pitch = rad (0.0);

	stored_co_pilot_head_heading = rad (0.0);
	stored_co_pilot_head_pitch = rad (0.0);

	stored_pilot_view_mode = VIEW_MODE_VIRTUAL_COCKPIT;
	stored_co_pilot_view_mode = VIEW_MODE_VIRTUAL_COCKPIT;

	stored_pilot_padlock_mode = PADLOCK_MODE_NONE;
	stored_co_pilot_padlock_mode = PADLOCK_MODE_NONE;

	//
	// padlock
	//

	padlock_mode = PADLOCK_MODE_NONE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reinitialise_virtual_cockpit_view (void)
{
	pilot_head_vp.position.x = MID_MAP_X;
	pilot_head_vp.position.y = MID_MAP_Y;
	pilot_head_vp.position.z = MID_MAP_Z;

	get_identity_matrix3x3 (pilot_head_vp.attitude);

	//
	// stored values
	//

	stored_pilot_head_heading = rad (0.0);
	stored_pilot_head_pitch = rad (0.0);

	stored_co_pilot_head_heading = rad (0.0);
	stored_co_pilot_head_pitch = rad (0.0);

	stored_pilot_view_mode = VIEW_MODE_VIRTUAL_COCKPIT;
	stored_co_pilot_view_mode = VIEW_MODE_VIRTUAL_COCKPIT;

	stored_pilot_padlock_mode = PADLOCK_MODE_NONE;
	stored_co_pilot_padlock_mode = PADLOCK_MODE_NONE;

	//
	// padlock
	//

	if (get_gunship_entity ())
	{
		unlink_local_entity_children (get_gunship_entity (), LIST_TYPE_PADLOCK);
	}

	padlock_mode = PADLOCK_MODE_NONE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_virtual_cockpit_view (void)
{
	//
	// padlock
	//

	if (get_gunship_entity ())
	{
		unlink_local_entity_children (get_gunship_entity (), LIST_TYPE_PADLOCK);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_virtual_cockpit_view (void)
{
	if (adjust_view_left_key || joystick_pov_left)
	{
		pilot_head_heading += ROTATE_RATE * get_delta_time ();

		pilot_head_heading = min (get_rotate_left_limit (), pilot_head_heading);
	}
	else if (adjust_view_right_key || joystick_pov_right)
	{
		pilot_head_heading -= ROTATE_RATE * get_delta_time ();

		pilot_head_heading = max (get_rotate_right_limit (), pilot_head_heading);
	}

	if (adjust_view_up_key || joystick_pov_up)
	{
		pilot_head_pitch += ROTATE_RATE * get_delta_time ();

		pilot_head_pitch = min (get_rotate_up_limit (), pilot_head_pitch);
	}
	else if (adjust_view_down_key || joystick_pov_down)
	{
		pilot_head_pitch -= (ROTATE_RATE * get_delta_time ());

		pilot_head_pitch = max (get_rotate_down_limit (), pilot_head_pitch);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_virtual_cockpit_track_target_view (void)
{
	float
		old_heading,
		old_pitch,
		delta_heading,
		delta_pitch,
		frame_rotate_rate;

	entity
		*target;

	target = get_local_entity_parent (get_gunship_entity (), LIST_TYPE_TARGET);

	if (target)
	{
		old_heading = pilot_head_heading;

		old_pitch = pilot_head_pitch;

		get_pilot_head_heading_and_pitch_to_target (target);

		frame_rotate_rate = rad (45.0) * get_delta_time ();

		delta_heading = pilot_head_heading - old_heading;

		delta_heading = bound (delta_heading, -frame_rotate_rate, frame_rotate_rate);

		pilot_head_heading = old_heading + delta_heading;

		delta_pitch = pilot_head_pitch - old_pitch;

		delta_pitch = bound (delta_pitch, -frame_rotate_rate, frame_rotate_rate);

		pilot_head_pitch = old_pitch + delta_pitch;
	}
	else
	{
		frame_rotate_rate = rad (45.0) * get_delta_time ();

		delta_heading = bound (-pilot_head_heading, -frame_rotate_rate, frame_rotate_rate);

		pilot_head_heading += delta_heading;

		delta_pitch = bound (-pilot_head_pitch, -frame_rotate_rate, frame_rotate_rate);

		pilot_head_pitch += delta_pitch;

		if
		(
			(pilot_head_heading >= rad (-1.0)) &&
			(pilot_head_heading <= rad (1.0)) &&
			(pilot_head_pitch >= rad (-1.0)) &&
			(pilot_head_pitch <= rad (1.0))
		)
		{
			set_view_mode (VIEW_MODE_COCKPIT_PANEL_LEVEL_AHEAD);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_virtual_cockpit_crew_view (void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_virtual_cockpit_hud_view (void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_virtual_cockpit_periscope_view (void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_virtual_cockpit_display_view (void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_pilot_head_viewpoint (void)
{
	if (get_gunship_entity ())
	{
		switch (get_global_gunship_type ())
		{
			////////////////////////////////////////
			case GUNSHIP_TYPE_APACHE:
			////////////////////////////////////////
			{
				matrix3x3
					m;

				vec3d
					relative_position,
					world_relative_position;

				//
				// get aircraft position and attitude
				//

				get_local_entity_vec3d (get_gunship_entity (), VEC3D_TYPE_POSITION, &pilot_head_vp.position);

				get_local_entity_attitude_matrix (get_gunship_entity (), pilot_head_vp.attitude);

				relative_position.x = 0.0;
				relative_position.y = -1.2705;
				relative_position.z = 1.2325;

				multiply_matrix3x3_vec3d (&world_relative_position, pilot_head_vp.attitude, &relative_position);

				pilot_head_vp.position.x += world_relative_position.x;
				pilot_head_vp.position.y += world_relative_position.y;
				pilot_head_vp.position.z += world_relative_position.z;

				//
				// rotate view wrt pilot's head heading and pitch
				//

				get_arbitrary_rotation_matrix (m, &pilot_head_vp.yv, pilot_head_heading);

				multiply_matrix3x3_vec3d (&pilot_head_vp.xv, m, &pilot_head_vp.xv);

				multiply_matrix3x3_vec3d (&pilot_head_vp.zv, m, &pilot_head_vp.zv);

				get_arbitrary_rotation_matrix (m, &pilot_head_vp.xv, pilot_head_pitch);

				multiply_matrix3x3_vec3d (&pilot_head_vp.yv, m, &pilot_head_vp.yv);

				multiply_matrix3x3_vec3d (&pilot_head_vp.zv, m, &pilot_head_vp.zv);

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_HAVOC:
			////////////////////////////////////////
			{
				matrix3x3
					m;

				vec3d
					relative_position,
					world_relative_position;

				//
				// get aircraft position and attitude
				//

				get_local_entity_vec3d (get_gunship_entity (), VEC3D_TYPE_POSITION, &pilot_head_vp.position);

				get_local_entity_attitude_matrix (get_gunship_entity (), pilot_head_vp.attitude);

				relative_position.x = 0.0;
				relative_position.y = -0.86575;
				relative_position.z = 1.252;

				multiply_matrix3x3_vec3d (&world_relative_position, pilot_head_vp.attitude, &relative_position);

				pilot_head_vp.position.x += world_relative_position.x;
				pilot_head_vp.position.y += world_relative_position.y;
				pilot_head_vp.position.z += world_relative_position.z;

				//
				// rotate view wrt pilot's head heading and pitch
				//

				get_arbitrary_rotation_matrix (m, &pilot_head_vp.yv, pilot_head_heading);

				multiply_matrix3x3_vec3d (&pilot_head_vp.xv, m, &pilot_head_vp.xv);

				multiply_matrix3x3_vec3d (&pilot_head_vp.zv, m, &pilot_head_vp.zv);

				get_arbitrary_rotation_matrix (m, &pilot_head_vp.xv, pilot_head_pitch);

				multiply_matrix3x3_vec3d (&pilot_head_vp.yv, m, &pilot_head_vp.yv);

				multiply_matrix3x3_vec3d (&pilot_head_vp.zv, m, &pilot_head_vp.zv);

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_COMANCHE:
			////////////////////////////////////////
			{
				get_comanche_crew_viewpoint ();

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_HOKUM:
			////////////////////////////////////////
			{
				get_hokum_crew_viewpoint ();

				break;
			}
		}
	}
	else
	{
		pilot_head_vp.position.x = MID_MAP_X;
		pilot_head_vp.position.y = MID_MAP_Y;
		pilot_head_vp.position.z = MID_MAP_Z;

		get_identity_matrix3x3 (pilot_head_vp.attitude);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_pilot_head_heading_and_pitch_to_target (entity *target)
{
	float
		flat_range,
		heading,
		pitch;

	vec3d
		target_position,
		target_vector,
		offset_vector;

	ASSERT (target);

	pilot_head_heading = 0.0;

	pilot_head_pitch = 0.0;

	get_pilot_head_viewpoint ();

	if (!get_local_entity_int_value (target, INT_TYPE_IDENTIFY_WAYPOINT))
	{
		get_local_entity_target_point (target, &target_position);
	}
	else
	{
		//
		// assume that the target will only be a waypoint for padlock views
		//

		ASSERT (get_gunship_entity ());

		get_waypoint_display_position (get_gunship_entity (), target, &target_position);
	}

	target_vector.x = target_position.x - pilot_head_vp.position.x;
	target_vector.y = target_position.y - pilot_head_vp.position.y;
	target_vector.z = target_position.z - pilot_head_vp.position.z;

	multiply_transpose_matrix3x3_vec3d (&offset_vector, pilot_head_vp.attitude, &target_vector);

	heading = -atan2 (offset_vector.x, offset_vector.z);

	pilot_head_heading = bound (heading, get_rotate_right_limit (), get_rotate_left_limit ());

	flat_range = sqrt ((offset_vector.x * offset_vector.x) + (offset_vector.z * offset_vector.z));

	pitch = atan2 (offset_vector.y, flat_range);

	pilot_head_pitch = bound (pitch, get_rotate_down_limit (), get_rotate_up_limit ());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_virtual_cockpit_3d_view (void)
{
	ASSERT (get_gunship_entity ());

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			pre_render_comanche_virtual_cockpit_displays ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			pre_render_hokum_virtual_cockpit_displays ();

			break;
		}
	}

	set_pilots_full_screen_params (night_vision_system_active);

	draw_main_3d_scene (&main_vp);

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			if (get_global_draw_cockpit_graphics ())
			{
				set_pilots_full_screen_params (FALSE);

				draw_apache_external_virtual_cockpit
				(
					VIRTUAL_COCKPIT_STOWED_WIPER |
					VIRTUAL_COCKPIT_MOVING_WIPER |
					VIRTUAL_COCKPIT_ADI |
					VIRTUAL_COCKPIT_COMPASS |
					VIRTUAL_COCKPIT_RAIN_EFFECT |
					VIRTUAL_COCKPIT_MAIN_ROTOR,
					NULL
				);

				draw_apache_internal_virtual_cockpit
				(
					VIRTUAL_COCKPIT_COCKPIT |
					VIRTUAL_COCKPIT_LHS_MFD_DISPLAY |
					VIRTUAL_COCKPIT_RHS_MFD_DISPLAY |
					VIRTUAL_COCKPIT_UPFRONT_DISPLAY |
					VIRTUAL_COCKPIT_INSTRUMENT_NEEDLES
				);
			}
			else
			{
				if (get_global_draw_overlaid_instruments ())
				{
					draw_overlaid_apache_mfd (68.0, 412.0, 128.0, MFD_LOCATION_LHS);

					draw_overlaid_apache_mfd (572.0, 412.0, 128.0, MFD_LOCATION_RHS);
				}
			}

			draw_apache_hud ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			if (get_global_draw_cockpit_graphics ())
			{
				set_pilots_full_screen_params (FALSE);

				draw_havoc_external_virtual_cockpit
				(
					VIRTUAL_COCKPIT_STOWED_WIPER |
					VIRTUAL_COCKPIT_MOVING_WIPER |
					VIRTUAL_COCKPIT_ADI |
					VIRTUAL_COCKPIT_HSI |
					VIRTUAL_COCKPIT_COMPASS |
					VIRTUAL_COCKPIT_RAIN_EFFECT |
					VIRTUAL_COCKPIT_MAIN_ROTOR,
					NULL
				);

				draw_havoc_internal_virtual_cockpit
				(
					VIRTUAL_COCKPIT_COCKPIT |
					VIRTUAL_COCKPIT_HUD_GLASS |
					VIRTUAL_COCKPIT_HUD_DISPLAY |
					VIRTUAL_COCKPIT_CRT_DISPLAY |
					VIRTUAL_COCKPIT_EKRAN_DISPLAY |
					VIRTUAL_COCKPIT_INSTRUMENT_NEEDLES
				);
			}
			else
			{
				draw_external_havoc_hud ();

				if (get_global_draw_overlaid_instruments ())
				{
					draw_overlaid_havoc_mfd (68.0, 412.0, 128.0);

					draw_overlaid_threat_warning_display (int_full_screen_width - 64, int_full_screen_height - 84);
				}
			}

			draw_havoc_hms ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			set_pilots_full_screen_params (FALSE);

			draw_comanche_virtual_cockpit ();

			if (!get_global_draw_cockpit_graphics ())
			{
				if (get_global_draw_overlaid_instruments ())
				{
					draw_overlaid_comanche_mfd ();
				}
			}

			draw_comanche_hud ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			set_pilots_full_screen_params (FALSE);

			draw_hokum_virtual_cockpit ();

			if (!get_global_draw_cockpit_graphics ())
			{
				if (get_global_draw_overlaid_instruments ())
				{
					draw_overlaid_hokum_mfd ();
				}
			}

			draw_hokum_hms ();

			break;
		}
	}

	//
	// restore virtual cockpit 3D instance
	//

	get_pilot_head_viewpoint ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_virtual_cockpit_3d_crew_view (void)
{
	vec3d
		position;

	ASSERT (get_gunship_entity ());

	ASSERT (get_comanche_hokum_gunship ());

	ASSERT (virtual_cockpit_inst3d);

	ASSERT (get_crew_camera_index (get_crew_role ()) != OBJECT_3D_INVALID_CAMERA_INDEX);

	ASSERT (get_num_virtual_cockpit_cameras (get_crew_role ()) > 0);

	ASSERT (get_current_virtual_cockpit_camera (get_crew_role ()) != INVALID_VIRTUAL_COCKPIT_CAMERA);

	////////////////////////////////////////
	//
	// check if the gunship has been destroyed before the pilot's ejected
	//

	if (get_local_entity_int_value (get_gunship_entity (), INT_TYPE_EJECTED))
	{
		if (!get_local_entity_int_value (get_gunship_entity (), INT_TYPE_ALIVE))
		{
			set_external_view_entity (get_gunship_entity ());

			notify_local_entity (ENTITY_MESSAGE_SET_CAMERA_ACTION, get_camera_entity (), NULL, CAMERA_ACTION_EJECT);
		}
	}

	//
	////////////////////////////////////////

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			pre_render_comanche_virtual_cockpit_displays ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			pre_render_hokum_virtual_cockpit_displays ();

			break;
		}
	}

	//
	// get camera viewpoint
	//

	virtual_cockpit_inst3d->vp.x = 0.0;
	virtual_cockpit_inst3d->vp.y = 0.0;
	virtual_cockpit_inst3d->vp.z = 0.0;

	get_local_entity_attitude_matrix (get_gunship_entity (), virtual_cockpit_inst3d->vp.attitude);

	get_object_3d_camera_position (virtual_cockpit_inst3d, get_crew_camera_index (get_crew_role ()), get_current_virtual_cockpit_camera (get_crew_role ()), 0.0, &main_vp);

	position.x = -main_vp.x;
	position.y = -main_vp.y;
	position.z = -main_vp.z;

	multiply_transpose_matrix3x3_vec3d (&virtual_cockpit_inst3d->vp.position, main_vp.attitude, &position);

	get_local_entity_vec3d (get_gunship_entity (), VEC3D_TYPE_POSITION, &position);

	main_vp.x += position.x;
	main_vp.y += position.y;
	main_vp.z += position.z;

	//
	// draw view
	//

	set_crew_view_full_screen_params ();

	draw_main_3d_scene (&main_vp);

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			draw_comanche_virtual_cockpit ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			draw_hokum_virtual_cockpit ();

			break;
		}
	}

	//
	// restore virtual cockpit 3D instance
	//

	get_pilot_head_viewpoint ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_virtual_cockpit_3d_hud_view (void)
{
	ASSERT (get_gunship_entity ());

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			set_pilots_full_screen_params (night_vision_system_active);

			draw_main_3d_scene (&main_vp);

			if (get_global_draw_cockpit_graphics ())
			{
				set_pilots_full_screen_params (FALSE);

				draw_havoc_external_virtual_cockpit
				(
					VIRTUAL_COCKPIT_STOWED_WIPER |
					VIRTUAL_COCKPIT_MOVING_WIPER |
					VIRTUAL_COCKPIT_RAIN_EFFECT |
					VIRTUAL_COCKPIT_MAIN_ROTOR,
					NULL
				);

				draw_havoc_internal_virtual_cockpit
				(
					VIRTUAL_COCKPIT_COCKPIT |
					VIRTUAL_COCKPIT_HUD_GLASS
				);
			}
			else
			{
				if (get_global_draw_overlaid_instruments ())
				{
					draw_overlaid_havoc_mfd (68.0, 412.0, 128.0);

					draw_overlaid_threat_warning_display (int_full_screen_width - 64, int_full_screen_height - 84);
				}
			}

			draw_external_havoc_hud ();

			draw_havoc_hms ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			vec3d
				position;

			ASSERT (virtual_cockpit_inst3d);

			pre_render_hokum_virtual_cockpit_displays ();

			//
			// get camera viewpoint
			//

			virtual_cockpit_inst3d->vp.x = 0.0;
			virtual_cockpit_inst3d->vp.y = 0.0;
			virtual_cockpit_inst3d->vp.z = 0.0;

			get_local_entity_attitude_matrix (get_gunship_entity (), virtual_cockpit_inst3d->vp.attitude);

			get_object_3d_camera_position (virtual_cockpit_inst3d, OBJECT_3D_CAMERA_VIEW_STATIC_HUD, 0, 0.0, &main_vp);

			position.x = -main_vp.x;
			position.y = -main_vp.y;
			position.z = -main_vp.z;

			multiply_transpose_matrix3x3_vec3d (&virtual_cockpit_inst3d->vp.position, main_vp.attitude, &position);

			get_local_entity_vec3d (get_gunship_entity (), VEC3D_TYPE_POSITION, &position);

			main_vp.x += position.x;
			main_vp.y += position.y;
			main_vp.z += position.z;

			//
			// draw view
			//

			set_pilots_full_screen_params (night_vision_system_active);

			draw_main_3d_scene (&main_vp);

			set_pilots_full_screen_params (FALSE);

			draw_hokum_virtual_cockpit ();

			draw_hokum_hms ();

			break;
		}
	}

	//
	// restore virtual cockpit 3D instance
	//

	get_pilot_head_viewpoint ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_virtual_cockpit_3d_periscope_view (void)
{
	ASSERT (get_gunship_entity ());

	ASSERT (get_global_gunship_type () == GUNSHIP_TYPE_HOKUM);

	draw_hokum_virtual_cockpit_periscope_view ();

	draw_hokum_virtual_cockpit_periscope_mask ();

	draw_hokum_virtual_cockpit_periscope_symbology ();

	//
	// restore virtual cockpit 3D instance
	//

	get_pilot_head_viewpoint ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_virtual_cockpit_3d_display_view (void)
{
	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			set_pilots_full_screen_params (FALSE);

			draw_apache_internal_virtual_cockpit
			(
				VIRTUAL_COCKPIT_DISPLAY_VIEW |
				VIRTUAL_COCKPIT_COCKPIT |
				VIRTUAL_COCKPIT_LHS_MFD_DISPLAY |
				VIRTUAL_COCKPIT_RHS_MFD_DISPLAY
			);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			set_pilots_full_screen_params (FALSE);

			draw_havoc_internal_virtual_cockpit
			(
				VIRTUAL_COCKPIT_COCKPIT |
				VIRTUAL_COCKPIT_CRT_DISPLAY |
				VIRTUAL_COCKPIT_EKRAN_DISPLAY
			);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			pre_render_comanche_virtual_cockpit_displays ();

			set_pilots_full_screen_params (FALSE);

			get_comanche_display_viewpoint (get_view_mode ());

			draw_comanche_virtual_cockpit ();

			draw_comanche_full_screen_display ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			pre_render_hokum_virtual_cockpit_displays ();

			set_pilots_full_screen_params (FALSE);

			get_hokum_display_viewpoint (get_view_mode ());

			draw_hokum_virtual_cockpit ();

			draw_hokum_full_screen_display ();

			break;
		}
	}

	//
	// restore virtual cockpit 3D instance
	//

	get_pilot_head_viewpoint ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void store_pilot_seat_values (void)
{
	#if DEBUG_MODULE_SEAT_SWITCHING

	debug_filtered_log ("store_pilot_seat_values");

	#endif

	stored_pilot_head_heading = pilot_head_heading;
	stored_pilot_head_pitch = pilot_head_pitch;

	switch (get_view_mode ())
	{
		case VIEW_MODE_VIRTUAL_COCKPIT:
		case VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK:
		case VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET:
		case VIEW_MODE_VIRTUAL_COCKPIT_CREW:
		case VIEW_MODE_VIRTUAL_COCKPIT_HUD:
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_LHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_RHS_DISPLAY:
		{
			stored_pilot_view_mode = get_view_mode ();

			break;
		}
		default:
		{
			stored_pilot_view_mode = VIEW_MODE_VIRTUAL_COCKPIT;

			break;
		}
	}

	stored_pilot_padlock_mode = padlock_mode;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void restore_pilot_seat_values (void)
{
	#if DEBUG_MODULE_SEAT_SWITCHING

	debug_filtered_log ("restore_pilot_seat_values");

	#endif

	pilot_head_heading = stored_pilot_head_heading;
	pilot_head_pitch = stored_pilot_head_pitch;

	if (stored_pilot_view_mode == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK)
	{
		//
		// clear co-pilot padlock mode (if any) and set default mode (in case padlock not available)
		//

		set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT);

		select_padlock_view_event (stored_pilot_padlock_mode);
	}
	else if (!set_view_mode (stored_pilot_view_mode))
	{
		set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void store_co_pilot_seat_values (void)
{
	#if DEBUG_MODULE_SEAT_SWITCHING

	debug_filtered_log ("store_co_pilot_seat_values");

	#endif

	stored_co_pilot_head_heading = pilot_head_heading;
	stored_co_pilot_head_pitch = pilot_head_pitch;

	switch (get_view_mode ())
	{
		case VIEW_MODE_VIRTUAL_COCKPIT:
		case VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK:
		case VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET:
		case VIEW_MODE_VIRTUAL_COCKPIT_CREW:
		case VIEW_MODE_VIRTUAL_COCKPIT_PERISCOPE:
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_LHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_RHS_DISPLAY:
		{
			stored_co_pilot_view_mode = get_view_mode ();

			break;
		}
		default:
		{
			stored_co_pilot_view_mode = VIEW_MODE_VIRTUAL_COCKPIT;

			break;
		}
	}

	stored_co_pilot_padlock_mode = padlock_mode;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void restore_co_pilot_seat_values (void)
{
	#if DEBUG_MODULE_SEAT_SWITCHING

	debug_filtered_log ("restore_co_pilot_seat_values");

	#endif

	pilot_head_heading = stored_co_pilot_head_heading;
	pilot_head_pitch = stored_co_pilot_head_pitch;

	if (stored_co_pilot_view_mode == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK)
	{
		//
		// clear pilot padlock mode (if any) and set default mode (in case padlock not available)
		//

		set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT);

		select_padlock_view_event (stored_co_pilot_padlock_mode);
	}
	else if (!set_view_mode (stored_co_pilot_view_mode))
	{
		set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void switch_seat_position (void)
{
	entity
		*en;

	ASSERT (get_gunship_entity ());

	ASSERT (!get_apache_havoc_gunship ());

	if (get_time_acceleration () == 0)
	{
		return;
	}

	en = get_pilot_entity ();

	ASSERT (en);

	if (get_local_entity_int_value (en, INT_TYPE_CREW_ROLE) == CREW_ROLE_PILOT)
	{
		////////////////////////////////////////
		//
		// PILOT ---> CO-PILOT
		//
		////////////////////////////////////////

		set_local_entity_int_value (en, INT_TYPE_CREW_ROLE, CREW_ROLE_CO_PILOT);

		store_pilot_seat_values ();

		restore_co_pilot_seat_values ();
	}
	else
	{
		////////////////////////////////////////
		//
		// CO-PILOT ---> PILOT
		//
		////////////////////////////////////////

		set_local_entity_int_value (en, INT_TYPE_CREW_ROLE, CREW_ROLE_PILOT);

		store_co_pilot_seat_values ();

		restore_pilot_seat_values ();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_pilot_seat_position (void)
{
	ASSERT (get_gunship_entity ());

	ASSERT (!get_apache_havoc_gunship ());

	ASSERT (get_pilot_entity ());

	if (get_time_acceleration () == 0)
	{
		return;
	}

	if (get_crew_role () == CREW_ROLE_PILOT)
	{
		if (!in_cockpit)
		{
			restore_pilot_seat_values ();
		}
	}
	else
	{
		switch_seat_position ();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_co_pilot_seat_position (void)
{
	ASSERT (get_gunship_entity ());

	ASSERT (!get_apache_havoc_gunship ());

	ASSERT (get_pilot_entity ());

	if (get_time_acceleration () == 0)
	{
		return;
	}

	if (get_crew_role () == CREW_ROLE_CO_PILOT)
	{
		if (!in_cockpit)
		{
			restore_co_pilot_seat_values ();
		}
	}
	else
	{
		switch_seat_position ();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void leave_seat_position (view_modes new_view_mode, view_modes old_view_mode)
{
	if (!in_cockpit_flags[new_view_mode] && in_cockpit_flags[old_view_mode])
	{
		if (get_gunship_entity ())
		{
			if (!get_apache_havoc_gunship ())
			{
				if (get_pilot_entity ())
				{
					if (get_crew_role () == CREW_ROLE_PILOT)
					{
						store_pilot_seat_values ();
					}
					else
					{
						store_co_pilot_seat_values ();
					}
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// PADLOCK VIEWS
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

padlock_modes get_padlock_mode (void)
{
	return (padlock_mode);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// invoked via set_view_mode ()
//

void leave_padlock_view (void)
{
	if (get_gunship_entity ())
	{
		unlink_local_entity_children (get_gunship_entity (), LIST_TYPE_PADLOCK);
	}

	padlock_mode = PADLOCK_MODE_NONE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void display_padlock_message (padlock_modes mode)
{
	char
		s[200];

	switch (mode)
	{
		////////////////////////////////////////
		case PADLOCK_MODE_NONE:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid padlock mode = PADLOCK_MODE_NONE");

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_WINGMAN:
		////////////////////////////////////////
		{
			char
				pilot_name[200];

			entity
				*wingman,
				*group,
				*pilot;

			wingman = get_local_entity_first_child (get_gunship_entity (), LIST_TYPE_PADLOCK);

			ASSERT (wingman);

			group = get_local_entity_parent (wingman, LIST_TYPE_MEMBER);

			if (group)
			{
				sprintf (s, "%s %s 1-%d", get_trans ("Padlock wingman"), get_local_entity_string (group, STRING_TYPE_GROUP_CALLSIGN), get_local_entity_int_value (wingman, INT_TYPE_GROUP_MEMBER_ID));

				if (get_local_entity_int_value (wingman, INT_TYPE_PLAYER) != ENTITY_PLAYER_AI)
				{
					pilot = get_local_entity_first_child (wingman, LIST_TYPE_AIRCREW);

					while (pilot)
					{
						sprintf (pilot_name, " (%s)", get_local_entity_string (pilot, STRING_TYPE_PILOTS_NAME));

						strcat (s, pilot_name);

						pilot = get_local_entity_child_succ (pilot, LIST_TYPE_AIRCREW);
					}
				}

				set_status_message (s, STATUS_MESSAGE_TYPE_NONE);
			}
			else
			{
				set_status_message (get_trans ("Padlock wingman"), STATUS_MESSAGE_TYPE_NONE);
			}

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_AIR_THREAT:
		////////////////////////////////////////
		{
			entity
				*air_threat;

			air_threat = get_local_entity_first_child (get_gunship_entity (), LIST_TYPE_PADLOCK);

			ASSERT (air_threat);

			sprintf (s, "%s %s", get_trans ("Padlock air threat"), get_local_entity_string (air_threat, STRING_TYPE_FULL_NAME));

			set_status_message (s, STATUS_MESSAGE_TYPE_NONE);

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_GROUND_THREAT:
		////////////////////////////////////////
		{
			entity
				*ground_threat;

			ground_threat = get_local_entity_first_child (get_gunship_entity (), LIST_TYPE_PADLOCK);

			ASSERT (ground_threat);

			sprintf (s, "%s %s", get_trans ("Padlock ground threat"), get_local_entity_string (ground_threat, STRING_TYPE_FULL_NAME));

			set_status_message (s, STATUS_MESSAGE_TYPE_NONE);

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_MISSILE_THREAT:
		////////////////////////////////////////
		{
			entity
				*incoming;

			incoming = get_local_entity_first_child (get_gunship_entity (), LIST_TYPE_PADLOCK);

			ASSERT (incoming);

			sprintf (s, "%s %s", get_trans ("Padlock incoming"), get_local_entity_string (incoming, STRING_TYPE_FULL_NAME));

			set_status_message (s, STATUS_MESSAGE_TYPE_NONE);

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_WAYPOINT:
		////////////////////////////////////////
		{
			entity
				*waypoint;

			waypoint = get_local_entity_current_waypoint (get_gunship_entity ());

			ASSERT (waypoint);

			sprintf (s, "%s '%c'", get_trans ("Padlock waypoint"), get_local_entity_char_value (waypoint, CHAR_TYPE_TAG));

			set_status_message (s, STATUS_MESSAGE_TYPE_NONE);

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid padlock mode = %d", mode);

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int get_valid_wingman (entity *wingman)
{
	ASSERT (wingman);

	if (get_local_entity_int_value (wingman, INT_TYPE_VIEWABLE))
	{
		if (wingman != get_gunship_entity ())
		{
			return (TRUE);
		}
	}

	return (FALSE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static entity *get_first_wingman (void)
{
	entity
		*source,
		*group,
		*wingman;

	source = get_gunship_entity ();

	ASSERT (source);

	group = get_local_entity_parent (source, LIST_TYPE_MEMBER);

	if (group)
	{
		wingman = get_local_entity_first_child (group, LIST_TYPE_MEMBER);

		while (wingman)
		{
			if (get_valid_wingman (wingman))
			{
				break;
			}

			wingman = get_local_entity_child_succ (wingman, LIST_TYPE_MEMBER);
		}
	}
	else
	{
		wingman = NULL;
	}

	return (wingman);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static entity *get_next_wingman (void)
{
	entity
		*source,
		*group,
		*wingman;

	source = get_gunship_entity ();

	ASSERT (source);

	wingman = get_local_entity_first_child (source, LIST_TYPE_PADLOCK);

	//
	// check wingman is still a wingman
	//

	if (wingman)
	{
		if (get_local_entity_parent (wingman, LIST_TYPE_MEMBER) != get_local_entity_parent (source, LIST_TYPE_MEMBER))
		{
			wingman = NULL;
		}
	}

	//
	// find next wingman in list
	//

	if (wingman)
	{
		wingman = get_local_entity_child_succ (wingman, LIST_TYPE_MEMBER);

		while (wingman)
		{
			if (get_valid_wingman (wingman))
			{
				break;
			}

			wingman = get_local_entity_child_succ (wingman, LIST_TYPE_MEMBER);
		}
	}

	//
	// find first wingman in list
	//

	if (!wingman)
	{
		group = get_local_entity_parent (source, LIST_TYPE_MEMBER);

		if (group)
		{
			wingman = get_local_entity_first_child (group, LIST_TYPE_MEMBER);

			while (wingman)
			{
				if (get_valid_wingman (wingman))
				{
					break;
				}

				wingman = get_local_entity_child_succ (wingman, LIST_TYPE_MEMBER);
			}
		}
	}

	return (wingman);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int get_valid_air_threat (entity *threat, entity_sides source_side)
{
	ASSERT (threat);

	if (get_local_entity_int_value (threat, INT_TYPE_IDENTIFY_AIRCRAFT))
	{
		if (get_local_entity_int_value (threat, INT_TYPE_VIEWABLE))
		{
			if (source_side != get_local_entity_int_value (threat, INT_TYPE_SIDE))
			{
				return (TRUE);
			}
		}
	}

	return (FALSE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static entity *get_first_air_threat (void)
{
	entity
		*source,
		*threat,
		*closest_threat;

	entity_sides
		source_side;

	float
		range,
		closest_threat_range;

	vec3d
		*source_position,
		*threat_position;

	source = get_gunship_entity ();

	ASSERT (source);

	source_side = get_local_entity_int_value (source, INT_TYPE_SIDE);

	source_position = get_local_entity_vec3d_ptr (source, VEC3D_TYPE_POSITION);

	closest_threat = NULL;

	closest_threat_range = FLT_MAX;

	threat = get_local_entity_first_child (source, LIST_TYPE_TARGET);

	while (threat)
	{
		if (get_valid_air_threat (threat, source_side))
		{
			threat_position = get_local_entity_vec3d_ptr (threat, VEC3D_TYPE_POSITION);

			range = get_sqr_3d_range (source_position, threat_position);

			if (range < closest_threat_range)
			{
				closest_threat = threat;

				closest_threat_range = range;
			}
		}

		threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
	}

	return (closest_threat);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static entity *get_next_air_threat (void)
{
	entity
		*source,
		*threat;

	entity_sides
		source_side;

	source = get_gunship_entity ();

	ASSERT (source);

	source_side = get_local_entity_int_value (source, INT_TYPE_SIDE);

	threat = get_local_entity_first_child (source, LIST_TYPE_PADLOCK);

	//
	// check threat is still a threat
	//

	if (threat)
	{
		if (get_local_entity_parent (threat, LIST_TYPE_TARGET) != source)
		{
			threat = NULL;
		}
	}

	//
	// find next threat in list
	//

	if (threat)
	{
		threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);

		while (threat)
		{
			if (get_valid_air_threat (threat, source_side))
			{
				break;
			}

			threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
		}
	}

	//
	// find first threat in list
	//

	if (!threat)
	{
		threat = get_local_entity_first_child (source, LIST_TYPE_TARGET);

		while (threat)
		{
			if (get_valid_air_threat (threat, source_side))
			{
				break;
			}

			threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
		}
	}

	return (threat);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int get_valid_ground_threat (entity *threat, entity_sides source_side)
{
	ASSERT (threat);

	if (get_local_entity_int_value (threat, INT_TYPE_IDENTIFY_VEHICLE))
	{
		if (get_local_entity_int_value (threat, INT_TYPE_VIEWABLE))
		{
			if (source_side != get_local_entity_int_value (threat, INT_TYPE_SIDE))
			{
				return (TRUE);
			}
		}
	}

	return (FALSE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static entity *get_first_ground_threat (void)
{
	entity
		*source,
		*threat,
		*closest_threat;

	entity_sides
		source_side;

	float
		range,
		closest_threat_range;

	vec3d
		*source_position,
		*threat_position;

	source = get_gunship_entity ();

	ASSERT (source);

	source_side = get_local_entity_int_value (source, INT_TYPE_SIDE);

	source_position = get_local_entity_vec3d_ptr (source, VEC3D_TYPE_POSITION);

	closest_threat = NULL;

	closest_threat_range = FLT_MAX;

	threat = get_local_entity_first_child (source, LIST_TYPE_TARGET);

	while (threat)
	{
		if (get_valid_ground_threat (threat, source_side))
		{
			threat_position = get_local_entity_vec3d_ptr (threat, VEC3D_TYPE_POSITION);

			range = get_sqr_3d_range (source_position, threat_position);

			if (range < closest_threat_range)
			{
				closest_threat = threat;

				closest_threat_range = range;
			}
		}

		threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
	}

	return (closest_threat);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static entity *get_next_ground_threat (void)
{
	entity
		*source,
		*threat;

	entity_sides
		source_side;

	source = get_gunship_entity ();

	ASSERT (source);

	source_side = get_local_entity_int_value (source, INT_TYPE_SIDE);

	threat = get_local_entity_first_child (source, LIST_TYPE_PADLOCK);

	//
	// check threat is still a threat
	//

	if (threat)
	{
		if (get_local_entity_parent (threat, LIST_TYPE_TARGET) != source)
		{
			threat = NULL;
		}
	}

	//
	// find next threat in list
	//

	if (threat)
	{
		threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);

		while (threat)
		{
			if (get_valid_ground_threat (threat, source_side))
			{
				break;
			}

			threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
		}
	}

	//
	// find first threat in list
	//

	if (!threat)
	{
		threat = get_local_entity_first_child (source, LIST_TYPE_TARGET);

		while (threat)
		{
			if (get_valid_ground_threat (threat, source_side))
			{
				break;
			}

			threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
		}
	}

	return (threat);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int get_valid_missile_threat (entity *threat)
{
	ASSERT (threat);

	if (get_local_entity_int_value (threat, INT_TYPE_VIEWABLE_WEAPON))
	{
		return (TRUE);
	}

	return (FALSE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static entity *get_first_missile_threat (void)
{
	entity
		*source,
		*threat,
		*closest_missile;

	int
		overshot;

	float
		threat_range,
		threat_velocity,
		time_to_impact,
		closest_missile_time_to_impact,
		length,
		cos_error;

	vec3d
		*source_position,
		*threat_position,
		uvec_threat_to_target;

	matrix3x3
		*attitude;

	source = get_gunship_entity ();

	ASSERT (source);

	source_position = get_local_entity_vec3d_ptr (source, VEC3D_TYPE_POSITION);

	closest_missile = NULL;

	closest_missile_time_to_impact = 1000000.0;

	threat = get_local_entity_first_child (get_gunship_entity (), LIST_TYPE_TARGET);

	while (threat)
	{
		if (get_valid_missile_threat (threat))
		{
			threat_position = get_local_entity_vec3d_ptr (threat, VEC3D_TYPE_POSITION);

			threat_range = get_3d_range (source_position, threat_position);

			threat_velocity = get_local_entity_float_value (threat, FLOAT_TYPE_VELOCITY);

			time_to_impact = threat_range / max (threat_velocity, 1.0);

			//
			// guard against 'overshot target' to prevent spurious indications
			//

			overshot = FALSE;

			if (time_to_impact < 1.0)
			{
				uvec_threat_to_target.x = source_position->x - threat_position->x;
				uvec_threat_to_target.y = source_position->y - threat_position->y;
				uvec_threat_to_target.z = source_position->z - threat_position->z;

				length = get_3d_vector_magnitude (&uvec_threat_to_target);

				if (length > 1.0)
				{
					normalise_3d_vector_given_magnitude (&uvec_threat_to_target, length);

					attitude = get_local_entity_attitude_matrix_ptr (threat);

					cos_error = get_3d_unit_vector_dot_product ((vec3d *) &((*attitude) [2][0]), &uvec_threat_to_target);

					if (cos_error < 0.0)
					{
						overshot = TRUE;
					}
				}
				else
				{
					overshot = TRUE;
				}
			}

			if (!overshot)
			{
				if (time_to_impact < closest_missile_time_to_impact)
				{
					closest_missile = threat;

					closest_missile_time_to_impact = time_to_impact;
				}
			}
		}

		threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
	}

	return (closest_missile);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static entity *get_next_missile_threat (void)
{
	entity
		*source,
		*threat;

	source = get_gunship_entity ();

	ASSERT (source);

	threat = get_local_entity_first_child (source, LIST_TYPE_PADLOCK);

	//
	// check threat is still a threat
	//

	if (threat)
	{
		if (get_local_entity_parent (threat, LIST_TYPE_TARGET) != source)
		{
			threat = NULL;
		}
	}

	//
	// find next threat in list
	//

	if (threat)
	{
		threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);

		while (threat)
		{
			if (get_valid_missile_threat (threat))
			{
				break;
			}

			threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
		}
	}

	//
	// find first threat in list
	//

	if (!threat)
	{
		threat = get_local_entity_first_child (source, LIST_TYPE_TARGET);

		while (threat)
		{
			if (get_valid_missile_threat (threat))
			{
				break;
			}

			threat = get_local_entity_child_succ (threat, LIST_TYPE_TARGET);
		}
	}

	return (threat);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void select_padlock_view_event (padlock_modes mode)
{
	entity
		*source,
		*target;

	ASSERT (get_gunship_entity ());

	source = get_gunship_entity ();

	switch (mode)
	{
		////////////////////////////////////////
		case PADLOCK_MODE_NONE:
		////////////////////////////////////////
		{
			if (get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET)
			{
				//
				// padlock target is handled via VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET
				//

				if (get_apache_havoc_gunship_fixed_cockpit ())
				{
					target = get_local_entity_parent (source, LIST_TYPE_TARGET);

					if (target)
					{
						get_pilot_head_heading_and_pitch_to_target (target);
					}

					set_view_mode (get_nearest_fixed_cockpit_view (pilot_head_heading, pilot_head_pitch));
				}
				else
				{
					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT);
				}
			}
			else if (get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK)
			{
				//
				// cancel padlock
				//

				if (get_apache_havoc_gunship_fixed_cockpit ())
				{
					//
					// leave_padlock_view () tidies up padlock list and mode
					//

					set_view_mode (get_nearest_fixed_cockpit_view (pilot_head_heading, pilot_head_pitch));
				}
				else
				{
					//
					// leave_padlock_view () tidies up padlock list and mode
					//

					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT);
				}
			}

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_WINGMAN:
		////////////////////////////////////////
		{
			if ((get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK) && (padlock_mode == PADLOCK_MODE_WINGMAN))
			{
				//
				// padlock next wingman
				//

				target = get_next_wingman ();

				if (target)
				{
					unlink_local_entity_children (source, LIST_TYPE_PADLOCK);

					insert_local_entity_into_parents_child_list (target, LIST_TYPE_PADLOCK, source, NULL);

					display_padlock_message (mode);
				}
			}
			else
			{
				//
				// padlock first wingman
				//

				target = get_first_wingman ();

				if (target)
				{
					//
					// leave_padlock_view () tidies up padlock list and mode
					//

					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK);

					insert_local_entity_into_parents_child_list (target, LIST_TYPE_PADLOCK, source, NULL);

					padlock_mode = mode;

					display_padlock_message (mode);
				}
			}

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_AIR_THREAT:
		////////////////////////////////////////
		{
			if ((get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK) && (padlock_mode == PADLOCK_MODE_AIR_THREAT))
			{
				//
				// padlock next air threat
				//

				target = get_next_air_threat ();

				if (target)
				{
					unlink_local_entity_children (source, LIST_TYPE_PADLOCK);

					insert_local_entity_into_parents_child_list (target, LIST_TYPE_PADLOCK, source, NULL);

					display_padlock_message (mode);
				}
			}
			else
			{
				//
				// padlock first air threat
				//

				target = get_first_air_threat ();

				if (target)
				{
					//
					// leave_padlock_view () tidies up padlock list and mode
					//

					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK);

					insert_local_entity_into_parents_child_list (target, LIST_TYPE_PADLOCK, source, NULL);

					padlock_mode = mode;

					display_padlock_message (mode);
				}
			}

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_GROUND_THREAT:
		////////////////////////////////////////
		{
			if ((get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK) && (padlock_mode == PADLOCK_MODE_GROUND_THREAT))
			{
				//
				// padlock next ground threat
				//

				target = get_next_ground_threat ();

				if (target)
				{
					unlink_local_entity_children (source, LIST_TYPE_PADLOCK);

					insert_local_entity_into_parents_child_list (target, LIST_TYPE_PADLOCK, source, NULL);

					display_padlock_message (mode);
				}
			}
			else
			{
				//
				// padlock first ground threat
				//

				target = get_first_ground_threat ();

				if (target)
				{
					//
					// leave_padlock_view () tidies up padlock list and mode
					//

					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK);

					insert_local_entity_into_parents_child_list (target, LIST_TYPE_PADLOCK, source, NULL);

					padlock_mode = mode;

					display_padlock_message (mode);
				}
			}

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_MISSILE_THREAT:
		////////////////////////////////////////
		{
			if ((get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK) && (padlock_mode == PADLOCK_MODE_MISSILE_THREAT))
			{
				//
				// padlock next missile threat
				//

				target = get_next_missile_threat ();

				if (target)
				{
					unlink_local_entity_children (source, LIST_TYPE_PADLOCK);

					insert_local_entity_into_parents_child_list (target, LIST_TYPE_PADLOCK, source, NULL);

					display_padlock_message (mode);
				}
			}
			else
			{
				//
				// padlock first missile threat
				//

				target = get_first_missile_threat ();

				if (target)
				{
					//
					// leave_padlock_view () tidies up padlock list and mode
					//

					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK);

					insert_local_entity_into_parents_child_list (target, LIST_TYPE_PADLOCK, source, NULL);

					padlock_mode = mode;

					display_padlock_message (mode);
				}
			}

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_WAYPOINT:
		////////////////////////////////////////
		{
			if ((get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK) && (padlock_mode == PADLOCK_MODE_WAYPOINT))
			{
				target = get_local_entity_current_waypoint (source);

				if (target)
				{
					display_padlock_message (mode);
				}
			}
			else
			{
				target = get_local_entity_current_waypoint (source);

				if (target)
				{
					//
					// leave_padlock_view () tidies up padlock list and mode
					//

					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK);

					padlock_mode = mode;

					display_padlock_message (mode);
				}
			}

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid padlock mode = %d", mode);

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

entity *get_players_padlock (void)
{
	entity
		*target;

	target = NULL;

	if (get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET)
	{
		target = get_local_entity_parent (get_gunship_entity (), LIST_TYPE_TARGET);
	}
	else if (get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_PADLOCK)
	{
		switch (padlock_mode)
		{
			////////////////////////////////////////
			case PADLOCK_MODE_NONE:
			////////////////////////////////////////
			{
				debug_fatal ("Invalid padlock mode = PADLOCK_MODE_NONE");

				break;
			}
			////////////////////////////////////////
			case PADLOCK_MODE_WINGMAN:
			case PADLOCK_MODE_AIR_THREAT:
			case PADLOCK_MODE_GROUND_THREAT:
			case PADLOCK_MODE_MISSILE_THREAT:
			////////////////////////////////////////
			{
				target = get_local_entity_first_child (get_gunship_entity (), LIST_TYPE_PADLOCK);

				break;
			}
			////////////////////////////////////////
			case PADLOCK_MODE_WAYPOINT:
			////////////////////////////////////////
			{
				target = NULL;

				break;
			}
			////////////////////////////////////////
			default:
			////////////////////////////////////////
			{
				debug_fatal ("Invalid padlock mode = %d", padlock_mode);

				break;
			}
		}
	}

	return (target);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_virtual_cockpit_padlock_view (void)
{
	float
		old_heading,
		old_pitch,
		delta_heading,
		delta_pitch,
		frame_rotate_rate;

	entity
		*source,
		*target;

	source = get_gunship_entity ();

	ASSERT (source);

	switch (padlock_mode)
	{
		////////////////////////////////////////
		case PADLOCK_MODE_NONE:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid padlock mode = PADLOCK_MODE_NONE");

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_WINGMAN:
		case PADLOCK_MODE_AIR_THREAT:
		case PADLOCK_MODE_GROUND_THREAT:
		case PADLOCK_MODE_MISSILE_THREAT:
		////////////////////////////////////////
		{
			target = get_local_entity_first_child (source, LIST_TYPE_PADLOCK);

			break;
		}
		////////////////////////////////////////
		case PADLOCK_MODE_WAYPOINT:
		////////////////////////////////////////
		{
			target = get_local_entity_current_waypoint (source);

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid padlock mode = %d", padlock_mode);

			break;
		}
	}

	if (target)
	{
		old_heading = pilot_head_heading;

		old_pitch = pilot_head_pitch;

		get_pilot_head_heading_and_pitch_to_target (target);

		frame_rotate_rate = rad (45.0) * get_delta_time ();

		delta_heading = pilot_head_heading - old_heading;

		delta_heading = bound (delta_heading, -frame_rotate_rate, frame_rotate_rate);

		pilot_head_heading = old_heading + delta_heading;

		delta_pitch = pilot_head_pitch - old_pitch;

		delta_pitch = bound (delta_pitch, -frame_rotate_rate, frame_rotate_rate);

		pilot_head_pitch = old_pitch + delta_pitch;
	}
	else
	{
		frame_rotate_rate = rad (45.0) * get_delta_time ();

		delta_heading = bound (-pilot_head_heading, -frame_rotate_rate, frame_rotate_rate);

		pilot_head_heading += delta_heading;

		delta_pitch = bound (-pilot_head_pitch, -frame_rotate_rate, frame_rotate_rate);

		pilot_head_pitch += delta_pitch;

		if
		(
			(pilot_head_heading >= rad (-1.0)) &&
			(pilot_head_heading <= rad (1.0)) &&
			(pilot_head_pitch >= rad (-1.0)) &&
			(pilot_head_pitch <= rad (1.0))
		)
		{
			//
			// leave_padlock_view () tidies up padlock list and mode
			//

			set_view_mode (VIEW_MODE_COCKPIT_PANEL_LEVEL_AHEAD);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
