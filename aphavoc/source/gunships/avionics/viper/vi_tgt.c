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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_viper_target_acquisition_systems (void)
{
	initialise_viper_eo ();

	initialise_viper_hms ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_viper_target_acquisition_systems (void)
{
	deinitialise_viper_eo ();

	deinitialise_viper_hms ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void deselect_viper_target_acquisition_system (target_acquisition_systems system)
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
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			deactivate_common_eo ();

			copy_eo_zoom(&viper_flir, &viper_dtv);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			deactivate_common_eo ();

			copy_eo_zoom(&viper_dtv, &viper_flir);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_HIDSS:
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

void select_viper_target_acquisition_system (target_acquisition_systems system)
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

	if (eo_is_tracking_point())
		eo_stop_tracking();
			
	deselect_viper_target_acquisition_system (target_acquisition_system);

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
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			if (!viper_damage.flir)
			{
				target_acquisition_system = system;

				activate_common_eo ();

				if (command_line_targeting_system_auto_page)
					select_viper_tads_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;
				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = viper_damage.flir;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			if (!viper_damage.dtv)
			{
				target_acquisition_system = system;

				activate_common_eo ();

				if (command_line_targeting_system_auto_page)
					select_viper_tads_mfd ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;
				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = viper_damage.dtv;

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_HIDSS:
		////////////////////////////////////////
		{
			if (!viper_damage.hidss)
			{
				target_acquisition_system = system;

				activate_common_hms ();

				if (hud_mode != HUD_MODE_WEAPON)
					previous_hud_mode = hud_mode;

				hud_mode = HUD_MODE_WEAPON;
			}

			damaged = viper_damage.hidss;

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

	play_common_cpg_target_acquisition_system_speech (new_system, old_system, damaged);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_viper_target_acquisition_system (void)
{
	switch (target_acquisition_system)
	{
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_OFF:
		////////////////////////////////////////
		{
			target_locked = FALSE;

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_OFF);

			slave_common_eo_to_current_target ();

			slave_viper_eo_to_current_target ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			update_viper_eo (&viper_flir);

			update_common_eo ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_FLIR);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			update_viper_eo (&viper_dtv);

			update_common_eo ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_DTV);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_HIDSS:
		////////////////////////////////////////
		{
			update_apache_hms ();

			update_common_hms ();

			update_weapon_lock_type (TARGET_ACQUISITION_SYSTEM_HIDSS);

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
			laser_on,
			los_to_target;

		source = get_gunship_entity ();

		target = get_local_entity_parent (source, LIST_TYPE_TARGET);

		//
		// laser on/off
		//

		laser_on = laser_is_active() && !viper_damage.laser_designator;

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
				case TARGET_ACQUISITION_SYSTEM_FLIR:
				case TARGET_ACQUISITION_SYSTEM_DTV:
				case TARGET_ACQUISITION_SYSTEM_HIDSS:
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
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void centre_viper_target_acquisition_system (void)
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
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		////////////////////////////////////////
		{
			centre_viper_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			centre_viper_eo ();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_HIDSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_viper_show_allied_targets (void)
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
		case TARGET_ACQUISITION_SYSTEM_HIDSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_viper_auto_target (void)
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
		case TARGET_ACQUISITION_SYSTEM_HIDSS:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void toggle_viper_lock_target (void)
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
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			toggle_eo_lock();

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_HIDSS:
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

void set_viper_lock_target (int lock)
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
		case TARGET_ACQUISITION_SYSTEM_FLIR:
		case TARGET_ACQUISITION_SYSTEM_DTV:
		////////////////////////////////////////
		{
			set_eo_lock(lock);

			break;
		}
		////////////////////////////////////////
		case TARGET_ACQUISITION_SYSTEM_HIDSS:
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
