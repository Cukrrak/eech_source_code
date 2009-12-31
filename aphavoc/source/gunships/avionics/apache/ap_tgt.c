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

#define DEBUG_MODULE	0

static target_aquistion_sources
	acquisition_source;

static vec3d
	acquisition_source_relative_position;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_apache_target_acquisition_systems (void)
{
	acquisition_source = TARGET_ACQUISITION_SOURCE_FXD;

	initialise_apache_radar ();

	initialise_apache_eo ();

	initialise_apache_hms ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_apache_target_acquisition_systems (void)
{
	deinitialise_apache_radar ();

	deinitialise_apache_eo ();

	deinitialise_apache_hms ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

target_aquistion_sources get_apache_acquisition_source(void)
{
	return acquisition_source;
}

void select_apache_acquisition_source(target_aquistion_sources acq_src)
{
	acquisition_source = acq_src;
}

static const char* acq_src_abbreviations[] = {
	"PHS",
	"GHS",
	"SKR",
	"RFI",
	"FCR",
	"FXD",
	"TADS",
	"TXX"
};

const char* get_apache_acquisition_source_abreviation(void)
{
	if (acquisition_source < TARGET_ACQUISITION_SOURCE_WAYPOINT_TARGET_POINT)
		return acq_src_abbreviations[acquisition_source];
	else
		return "";  // TODO
}

vec3d* get_acuisition_source_relative_position(void)
{
	return &acquisition_source_relative_position;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void deselect_apache_target_acquisition_system (target_acquisition_systems system)
{

	switch (system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			// laser is on in all modes but OFF in automatic mode
			if (!command_line_manual_laser_radar)
				set_laser_is_active(TRUE);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			if (!command_line_manual_laser_radar && get_global_avionics_realism() != AVIONICS_DETAIL_REALISTIC)
				deactivate_common_ground_radar ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			if (!command_line_manual_laser_radar && get_global_avionics_realism() != AVIONICS_DETAIL_REALISTIC)
				deactivate_common_air_radar ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			deactivate_common_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			deactivate_common_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			deactivate_common_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			deactivate_common_hms ();

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid target acquisition system = %d", system);

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void select_apache_target_acquisition_system (target_acquisition_systems system)
{
	target_acquisition_systems
		new_system,
		old_system;

	int
		damaged;

	new_system = system;
	old_system = target_acquisition_system;

	damaged = FALSE;

	reset_common_target_acquisition_system_keys ();

	deselect_apache_target_acquisition_system (target_acquisition_system);

	switch (system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			target_acquisition_system = system;

			set_gunship_target (NULL);

			if (!command_line_manual_laser_radar)
				set_laser_is_active(FALSE);

			#if 0

			hud_mode = previous_hud_mode;

			#endif

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			if (!apache_damage.radar)
			{
				target_acquisition_system = system;

				if (get_global_avionics_realism() != AVIONICS_DETAIL_REALISTIC)
					deactivate_common_air_radar();

				if (!command_line_manual_laser_radar)
					activate_common_ground_radar ();

				if (command_line_targeting_system_auto_page)
					select_apache_ground_radar_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = apache_damage.radar;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			if (!apache_damage.radar)
			{
				target_acquisition_system = system;

				if (get_global_avionics_realism() != AVIONICS_DETAIL_REALISTIC)
					deactivate_common_air_radar();

				if (!command_line_manual_laser_radar)
					activate_common_air_radar ();

				if (command_line_targeting_system_auto_page)
					select_apache_air_radar_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = apache_damage.radar;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			reset_mfd_mouse_buttons();

			if (!apache_damage.flir)
			{
				target_acquisition_system = system;

				activate_common_eo ();

				if (command_line_targeting_system_auto_page)
					select_apache_tads_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = apache_damage.flir;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			reset_mfd_mouse_buttons();

			if (!apache_damage.dtv)
			{
				target_acquisition_system = system;

				activate_common_eo ();

				if (command_line_targeting_system_auto_page)
					select_apache_tads_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = apache_damage.dtv;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			reset_mfd_mouse_buttons();

			if (!apache_damage.dvo)
			{
				target_acquisition_system = system;

				activate_common_eo ();

				if (command_line_targeting_system_auto_page)
					select_apache_tads_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = apache_damage.dvo;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			if (!apache_damage.ihadss)
			{
				target_acquisition_system = system;

				activate_common_hms ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = apache_damage.ihadss;

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid target acquisition system = %d", system);

			break;
		}
	}

	if (!command_line_manual_laser_radar)
		play_common_cpg_target_acquisition_system_speech (new_system, old_system, damaged);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void update_acquisition_source(void)
{
	switch (acquisition_source)
	{
	case TARGET_ACQUISITION_SOURCE_PHS:
	case TARGET_ACQUISITION_SOURCE_GHS:
	case TARGET_ACQUISITION_SOURCE_SKR:
	case TARGET_ACQUISITION_SOURCE_RFI:
	case TARGET_ACQUISITION_SOURCE_FCR:
	case TARGET_ACQUISITION_SOURCE_FXD:
		acquisition_source_relative_position.x = 0.0;
		acquisition_source_relative_position.y = 0.0;
		acquisition_source_relative_position.z = 1000.0;

		multiply_matrix3x3_vec3d(&acquisition_source_relative_position, current_flight_dynamics->attitude, &acquisition_source_relative_position);

		break;
	case TARGET_ACQUISITION_SOURCE_TADS:
		get_3d_unit_vector_from_heading_and_pitch(&acquisition_source_relative_position, eo_azimuth, eo_elevation);
		multiply_matrix3x3_vec3d(&acquisition_source_relative_position, current_flight_dynamics->attitude, &acquisition_source_relative_position);

		// multiply by 1000 to move focus point out some.  Minimizes problem of
		// EO point of view being a few meters ahead of pilot's viewpoint
		acquisition_source_relative_position.x *= 1000.0;
		acquisition_source_relative_position.y *= 1000.0;
		acquisition_source_relative_position.z *= 1000.0;

		break;
	case TARGET_ACQUISITION_SOURCE_WAYPOINT_TARGET_POINT:
		acquisition_source_relative_position.x = 0.0;
		acquisition_source_relative_position.y = 0.0;
		acquisition_source_relative_position.z = 1000.0;

		multiply_matrix3x3_vec3d(&acquisition_source_relative_position, current_flight_dynamics->attitude, &acquisition_source_relative_position);

		break;
	}
}

void update_apache_target_acquisition_system (void)
{
	update_common_radar(FALSE);

	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			target_locked = FALSE;

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_OFF);

			slave_common_eo_to_current_target ();

			slave_apache_eo_to_current_target ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			update_apache_ground_radar ();  // this only updates scan zones etc, only need to do it when radar is active

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_GROUND_RADAR);

			slave_common_eo_to_current_target ();

			slave_apache_eo_to_current_target ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			update_apache_air_radar ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_AIR_RADAR);

			slave_common_eo_to_current_target ();

			slave_apache_eo_to_current_target ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			update_apache_eo (&apache_flir);

			update_common_eo ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_FLIR);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			update_apache_eo (&apache_dtv);

			update_common_eo ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_DTV);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			update_apache_eo (&apache_dvo);

			update_common_eo ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_DVO);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			update_apache_hms ();

			update_common_hms ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_IHADSS);

			slave_common_eo_to_current_target ();

			slave_apache_eo_to_current_target ();

			break;
		}
	}

	////////////////////////////////////////
	//
	// radar / laser / los to target
	//
	////////////////////////////////////////

	{
		entity
			*source,
			*target;

		int
			radar_on,
			laser_on,
			los_to_target;

		source = get_gunship_entity ();

		target = get_local_entity_parent (source, LIST_TYPE_TARGET);

		//
		// radar on/off
		//

		radar_on = get_radar_active();

/*
		if (ground_radar_is_active() && ground_radar.sweep_mode != RADAR_SWEEP_MODE_SINGLE_INACTIVE)
			radar_on = TRUE;

		else if (air_radar_is_active() && air_radar.sweep_mode != RADAR_SWEEP_MODE_SINGLE_INACTIVE)
			radar_on = TRUE;
*/
		if (radar_on != get_local_entity_int_value (source, INT_TYPE_RADAR_ON))
			set_client_server_entity_int_value (source, INT_TYPE_RADAR_ON, radar_on);

		//
		// laser on/off
		//

		laser_on = laser_is_active() && !apache_damage.laser_designator;

		if (laser_on != get_local_entity_int_value (source, INT_TYPE_LASER_ON))
		{
			set_client_server_entity_int_value (source, INT_TYPE_LASER_ON, laser_on);
		}

		//
		// line of sight to target
		//

		if (target)
		{
			switch (target_acquisition_system)
			{
				case TARGET_ACQUISITION_SYSTEM_OFF:
				{
					los_to_target = FALSE;

					break;
				}
				case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
				case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
				{
					los_to_target = get_local_entity_int_value (target, INT_TYPE_GUNSHIP_RADAR_LOS_CLEAR);

					break;
				}
				case TARGET_ACQUISITION_SYSTEM_FLIR:
				case TARGET_ACQUISITION_SYSTEM_DTV:
				case TARGET_ACQUISITION_SYSTEM_DVO:
				{
					los_to_target = TRUE;

					break;
				}
				case TARGET_ACQUISITION_SYSTEM_IHADSS:
				{
					los_to_target = TRUE;

					break;
				}
			}
		}
		else
		{
			los_to_target = FALSE;
		}

		if (los_to_target != get_local_entity_int_value (source, INT_TYPE_LOS_TO_TARGET))
		{
			set_client_server_entity_int_value (source, INT_TYPE_LOS_TO_TARGET, los_to_target);
		}
	}

	// acquisition source
	update_acquisition_source();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void centre_apache_target_acquisition_system (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			centre_apache_ground_radar ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			centre_apache_air_radar ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			centre_apache_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			centre_apache_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			centre_apache_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_apache_show_allied_targets (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			air_radar.show_allied_targets ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_apache_auto_target (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			ground_radar.auto_target ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			air_radar.auto_target ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_apache_lock_target (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			ground_radar.target_locked ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			air_radar.target_locked ^= 1;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			toggle_eo_lock();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			hms_target_locked ^= 1;

			if (hms_target_locked)
			{
				if (in_cockpit && !query_TIR_active())
				{
					set_view_mode (VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET);
				}
				else
					set_eo_lock(TRUE);
			}
			else
			{
				if (get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_TRACK_TARGET)
				{
					select_padlock_view_event (PADLOCK_MODE_NONE);
				}
			}

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_apache_lock_target (int lock)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		////////////////////////////////////////
		{
			ground_radar.target_locked = lock;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			air_radar.target_locked = lock;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		case TARGET_ACQUISITION_SYSTEM_DVO:
		////////////////////////////////////////
		{
			set_eo_lock(lock);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
			hms_target_locked = lock;

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void apache_target_acquisition_system_misc_function1 (void)
{
	/*
	radar_params* radar = get_current_radar_params();

	radar->sweep_mode = RADAR_SWEEP_MODE_SINGLE;
	activate_common_radar();
	*/
	if (apache_damage.radar)
		set_radar_active(FALSE);
	else
		toggle_single_scan_active();
#if 0
	switch (target_acquisition_system)
	{
		case TARGET_ACQUISITION_SYSTEM_OFF:
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		case TARGET_ACQUISITION_SYSTEM_DVO:
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		{
/*
			if (ground_radar.sweep_mode == RADAR_SWEEP_MODE_CONTINUOUS)
			{
				if (ground_radar_is_active())
					ground_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_ACTIVE;
				else
					ground_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_INACTIVE;
			}
			else
			{
				set_radar_mode(ground_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_ACTIVE ? RADAR_MODE_GTM : RADAR_MODE_NONE);

				ground_radar.sweep_mode = RADAR_SWEEP_MODE_CONTINUOUS;
			}
*/
			break;
		}
		////////////////////////////////////////
		////////////////////////////////////////
		{
			if (apache_damage.radar)
			{
				set_radar_mode(RADAR_MODE_NONE);
			}
			else if (air_radar.sweep_mode == RADAR_SWEEP_MODE_CONTINUOUS)
			{
				if (air_radar_is_active())
					air_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_ACTIVE;
				else
					air_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_INACTIVE;
			}
			else
			{
				set_radar_mode(ground_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_ACTIVE ? RADAR_MODE_ATM : RADAR_MODE_NONE);

				air_radar.sweep_mode = RADAR_SWEEP_MODE_CONTINUOUS;
			}

			break;
		}
	}
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void apache_target_acquisition_system_misc_function2 (void)
{
	if (apache_damage.radar)
		set_radar_active(FALSE);
	else
		toggle_continuous_radar_active();

/*
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		case TARGET_ACQUISITION_SYSTEM_GROUND_RADAR:
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		case TARGET_ACQUISITION_SYSTEM_DVO:
		case TARGET_ACQUISITION_SYSTEM_IHADSS:
		////////////////////////////////////////
		{
/*
			if (ground_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_INACTIVE)
			{
				if (!apache_damage.radar)
				{
					ground_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_ACTIVE;
//					set_radar_mode(RADAR_MODE_GTM);
				}
			}
			else if (ground_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_ACTIVE)
			{
				ground_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_INACTIVE;
//				set_radar_mode(RADAR_MODE_NONE);
			}
			else if (!apache_damage.radar)
				toggle_ground_radar_active();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_AIR_RADAR:
		////////////////////////////////////////
		{
			if (air_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_INACTIVE)
			{
				if (!apache_damage.radar)
				{
					air_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_ACTIVE;
					set_radar_mode(RADAR_MODE_ATM);
				}
			}
			else if (air_radar.sweep_mode == RADAR_SWEEP_MODE_SINGLE_ACTIVE)
			{
				air_radar.sweep_mode = RADAR_SWEEP_MODE_SINGLE_INACTIVE;
				set_radar_mode(RADAR_MODE_NONE);
			}
			else if (!apache_damage.radar)
				toggle_air_radar_active();

			break;

		}
	}
	*/
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
