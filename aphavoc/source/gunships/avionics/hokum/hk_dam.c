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

hokum_damage_flags
	hokum_damage;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_hokum_weapon_damage_status (void)
{
	entity
		*en;

	entity_sub_types
		weapon_sub_type;

	en = get_gunship_entity ();

	set_client_server_entity_weapon_damage (en, HOKUM_CANNON_TURRET, ENTITY_SUB_TYPE_WEAPON_2A42_30MM_HE_ROUND, hokum_damage.gun_jammed);
	set_client_server_entity_weapon_damage (en, HOKUM_CANNON_TURRET, ENTITY_SUB_TYPE_WEAPON_2A42_30MM_AP_ROUND, hokum_damage.gun_jammed);

	set_client_server_entity_weapon_damage (en, HOKUM_LHS_OUTER_PYLON, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, hokum_damage.lh_outer_pylon);
	set_client_server_entity_weapon_damage (en, HOKUM_LHS_INNER_PYLON, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, hokum_damage.lh_inner_pylon);

	set_client_server_entity_weapon_damage (en, HOKUM_RHS_OUTER_PYLON, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, hokum_damage.rh_outer_pylon);
	set_client_server_entity_weapon_damage (en, HOKUM_RHS_INNER_PYLON, ENTITY_SUB_TYPE_WEAPON_NO_WEAPON, hokum_damage.rh_inner_pylon);

	set_client_server_entity_weapon_damage (en, HOKUM_LHS_CHAFF_DISPENSER, ENTITY_SUB_TYPE_WEAPON_CHAFF, hokum_damage.lh_chaff_dispensers);
	set_client_server_entity_weapon_damage (en, HOKUM_RHS_CHAFF_DISPENSER, ENTITY_SUB_TYPE_WEAPON_CHAFF, hokum_damage.rh_chaff_dispensers);

	set_client_server_entity_weapon_damage (en, HOKUM_LHS_FLARE_DISPENSER, ENTITY_SUB_TYPE_WEAPON_FLARE, hokum_damage.lh_flare_dispensers);
	set_client_server_entity_weapon_damage (en, HOKUM_RHS_FLARE_DISPENSER, ENTITY_SUB_TYPE_WEAPON_FLARE, hokum_damage.rh_flare_dispensers);

	//
	// check if selected weapon is still available, if not, select next
	//

	weapon_sub_type = get_local_entity_int_value (en, INT_TYPE_SELECTED_WEAPON);

	if (weapon_sub_type != ENTITY_SUB_TYPE_WEAPON_NO_WEAPON)
	{
		if (!get_local_entity_weapon_available (en, weapon_sub_type))
		{
			weapon_sub_type = get_next_available_weapon_sub_type (en);

			set_gunship_weapon (weapon_sub_type);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fully_repair_hokum_damage (void)
{
	set_hokum_text_display_text ("", "", "");

	fire_extinguisher_used = FALSE;

	////////////////////////////////////////

	hokum_damage.radar = FALSE;

	////////////////////////////////////////

	hokum_damage.flir = FALSE;

	////////////////////////////////////////

	hokum_damage.llltv = FALSE;

	////////////////////////////////////////

	hokum_damage.periscope = FALSE;

	////////////////////////////////////////

	hokum_damage.laser_designator = FALSE;

	////////////////////////////////////////

	hokum_damage.radar_jammer = FALSE;

	////////////////////////////////////////

	hokum_damage.infra_red_jammer = FALSE;

	////////////////////////////////////////

	hokum_damage.navigation_computer = FALSE;

	////////////////////////////////////////

	hokum_damage.communications = FALSE;

	////////////////////////////////////////

	hokum_damage.radar_warning_system = FALSE;

	////////////////////////////////////////

	hokum_damage.head_up_display = FALSE;

	////////////////////////////////////////

	hokum_damage.helmet_mounted_sight = FALSE;

	////////////////////////////////////////

	if (hokum_damage.pilot_lh_mfd)
	{
		hokum_damage.pilot_lh_mfd = FALSE;

		select_hokum_mfd_mode (HOKUM_MFD_MODE_OFF, HOKUM_MFD_LOCATION_PILOT_LHS);
	}

	////////////////////////////////////////

	if (hokum_damage.pilot_rh_mfd)
	{
		hokum_damage.pilot_rh_mfd = FALSE;

		select_hokum_mfd_mode (HOKUM_MFD_MODE_OFF, HOKUM_MFD_LOCATION_PILOT_RHS);
	}

	////////////////////////////////////////

	if (hokum_damage.co_pilot_lh_mfd)
	{
		hokum_damage.co_pilot_lh_mfd = FALSE;

		select_hokum_mfd_mode (HOKUM_MFD_MODE_OFF, HOKUM_MFD_LOCATION_CO_PILOT_LHS);
	}

	////////////////////////////////////////

	if (hokum_damage.co_pilot_rh_mfd)
	{
		hokum_damage.co_pilot_rh_mfd = FALSE;

		select_hokum_mfd_mode (HOKUM_MFD_MODE_OFF, HOKUM_MFD_LOCATION_CO_PILOT_RHS);
	}

	////////////////////////////////////////

	hokum_damage.night_vision_goggles = FALSE;

	////////////////////////////////////////

	hokum_damage.gun_jammed = FALSE;

	////////////////////////////////////////

	hokum_damage.lh_outer_pylon = FALSE;

	////////////////////////////////////////

	hokum_damage.lh_inner_pylon = FALSE;

	////////////////////////////////////////

	hokum_damage.rh_outer_pylon = FALSE;

	////////////////////////////////////////

	hokum_damage.rh_inner_pylon = FALSE;

	////////////////////////////////////////

	hokum_damage.lh_chaff_dispensers = FALSE;

	////////////////////////////////////////

	hokum_damage.rh_chaff_dispensers = FALSE;

	////////////////////////////////////////

	hokum_damage.lh_flare_dispensers = FALSE;

	////////////////////////////////////////

	hokum_damage.rh_flare_dispensers = FALSE;

	////////////////////////////////////////

	set_hokum_weapon_damage_status ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void partially_repair_hokum_damage (void)
{
	set_hokum_text_display_text ("", "", "");

	fire_extinguisher_used = FALSE;

	////////////////////////////////////////

	if (hokum_damage.radar)
	{
		hokum_damage.radar = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.flir)
	{
		hokum_damage.flir = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.llltv)
	{
		hokum_damage.llltv = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.periscope)
	{
		hokum_damage.periscope = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.laser_designator)
	{
		hokum_damage.laser_designator = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.radar_jammer)
	{
		hokum_damage.radar_jammer = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.infra_red_jammer)
	{
		hokum_damage.infra_red_jammer = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.navigation_computer)
	{
		hokum_damage.navigation_computer = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.communications)
	{
		hokum_damage.communications = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.radar_warning_system)
	{
		hokum_damage.radar_warning_system = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.head_up_display)
	{
		hokum_damage.head_up_display = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.helmet_mounted_sight)
	{
		hokum_damage.helmet_mounted_sight = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.pilot_lh_mfd)
	{
		hokum_damage.pilot_lh_mfd = frand1 () > 0.90;

		if (!hokum_damage.pilot_lh_mfd)
		{
			select_hokum_mfd_mode (HOKUM_MFD_MODE_OFF, HOKUM_MFD_LOCATION_PILOT_LHS);
		}
	}

	////////////////////////////////////////

	if (hokum_damage.pilot_rh_mfd)
	{
		hokum_damage.pilot_rh_mfd = frand1 () > 0.90;

		if (!hokum_damage.pilot_rh_mfd)
		{
			select_hokum_mfd_mode (HOKUM_MFD_MODE_OFF, HOKUM_MFD_LOCATION_PILOT_RHS);
		}
	}

	////////////////////////////////////////

	if (hokum_damage.co_pilot_lh_mfd)
	{
		hokum_damage.co_pilot_lh_mfd = frand1 () > 0.90;

		if (!hokum_damage.co_pilot_lh_mfd)
		{
			select_hokum_mfd_mode (HOKUM_MFD_MODE_OFF, HOKUM_MFD_LOCATION_CO_PILOT_LHS);
		}
	}

	////////////////////////////////////////

	if (hokum_damage.co_pilot_rh_mfd)
	{
		hokum_damage.co_pilot_rh_mfd = frand1 () > 0.90;

		if (!hokum_damage.co_pilot_rh_mfd)
		{
			select_hokum_mfd_mode (HOKUM_MFD_MODE_OFF, HOKUM_MFD_LOCATION_CO_PILOT_RHS);
		}
	}

	////////////////////////////////////////

	if (hokum_damage.night_vision_goggles)
	{
		hokum_damage.night_vision_goggles = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.gun_jammed)
	{
		hokum_damage.gun_jammed = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.lh_outer_pylon)
	{
		hokum_damage.lh_outer_pylon = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.lh_inner_pylon)
	{
		hokum_damage.lh_inner_pylon = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.rh_outer_pylon)
	{
		hokum_damage.rh_outer_pylon = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.rh_inner_pylon)
	{
		hokum_damage.rh_inner_pylon = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.lh_chaff_dispensers)
	{
		hokum_damage.lh_chaff_dispensers = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.rh_chaff_dispensers)
	{
		hokum_damage.rh_chaff_dispensers = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.lh_flare_dispensers)
	{
		hokum_damage.lh_flare_dispensers = frand1 () > 0.90;
	}

	////////////////////////////////////////

	if (hokum_damage.rh_flare_dispensers)
	{
		hokum_damage.rh_flare_dispensers = frand1 () > 0.90;
	}

	////////////////////////////////////////

	set_hokum_weapon_damage_status ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void repair_hokum_weapon_damage (void)
{
	set_hokum_text_display_text ("", "", "");

	hokum_damage.gun_jammed				= FALSE;
	hokum_damage.lh_outer_pylon  		= FALSE;
	hokum_damage.lh_inner_pylon  		= FALSE;
	hokum_damage.rh_outer_pylon  		= FALSE;
	hokum_damage.rh_inner_pylon  		= FALSE;
	hokum_damage.lh_chaff_dispensers	= FALSE;
	hokum_damage.rh_chaff_dispensers	= FALSE;
	hokum_damage.lh_flare_dispensers	= FALSE;
	hokum_damage.rh_flare_dispensers	= FALSE;

	set_hokum_weapon_damage_status ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void damage_systems (hokum_damage_flags damage)
{
	entity
		*en;

	en = get_gunship_entity ();

	////////////////////////////////////////

	if (damage.radar)
	{
		if (!hokum_damage.radar)
		{
			activate_hokum_master_caution ();

			hokum_damage.radar = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("RADAR", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_RADAR_FAILURE);

			if
			(
				(target_acquisition_system == TARGET_ACQUISITION_SYSTEM_GROUND_RADAR) ||
				(target_acquisition_system == TARGET_ACQUISITION_SYSTEM_AIR_RADAR)
			)
			{
				select_hokum_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
			}
		}
	}

	////////////////////////////////////////

	if (damage.flir)
	{
		if (!hokum_damage.flir)
		{
			activate_hokum_master_caution ();

			hokum_damage.flir = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("FLIR", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_FLIR_FAILURE);

			if (target_acquisition_system == TARGET_ACQUISITION_SYSTEM_FLIR)
			{
				select_hokum_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
			}
		}
	}

	////////////////////////////////////////

	if (damage.llltv)
	{
		if (!hokum_damage.llltv)
		{
			activate_hokum_master_caution ();

			hokum_damage.llltv = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("LLLTV", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_LLLTV_FAILURE);

			if (target_acquisition_system == TARGET_ACQUISITION_SYSTEM_LLLTV)
			{
				select_hokum_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
			}
		}
	}

	////////////////////////////////////////

	if (damage.periscope)
	{
		if (!hokum_damage.periscope)
		{
			activate_hokum_master_caution ();

			hokum_damage.periscope = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("PERISCOPE", "DAMAGED", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_PERISCOPE_DAMAGED);

			if (target_acquisition_system == TARGET_ACQUISITION_SYSTEM_PERISCOPE)
			{
				select_hokum_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
			}
		}
	}

	////////////////////////////////////////

	if (damage.laser_designator)
	{
		if (!hokum_damage.laser_designator)
		{
			activate_hokum_master_caution ();

			hokum_damage.laser_designator = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("LASER", "DESIGNATOR", "FAILURE");

			play_client_server_warning_message (en, SPEECH_SYSTEM_LASER_DESIGNATOR_FAILURE);
		}
	}

	////////////////////////////////////////

	if (damage.radar_jammer)
	{
		if (!hokum_damage.radar_jammer)
		{
			activate_hokum_master_caution ();

			hokum_damage.radar_jammer = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("RADAR", "JAMMER", "FAILURE");

			play_client_server_warning_message (en, SPEECH_SYSTEM_RADAR_JAMMER_FAILURE);

			if (get_local_entity_int_value (get_gunship_entity (), INT_TYPE_RADAR_JAMMER_ON))
			{
				set_client_server_entity_int_value (get_gunship_entity (), INT_TYPE_RADAR_JAMMER_ON, FALSE);
			}
		}
	}

	////////////////////////////////////////

	if (damage.infra_red_jammer)
	{
		if (!hokum_damage.infra_red_jammer)
		{
			activate_hokum_master_caution ();

			hokum_damage.infra_red_jammer = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("IR JAMMER", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_IR_JAMMER_FAILURE);

			if (get_local_entity_int_value (get_gunship_entity (), INT_TYPE_INFRA_RED_JAMMER_ON))
			{
				set_client_server_entity_int_value (get_gunship_entity (), INT_TYPE_INFRA_RED_JAMMER_ON, FALSE);
			}
		}
	}

	////////////////////////////////////////

	if (damage.navigation_computer)
	{
		if (!hokum_damage.navigation_computer)
		{
			activate_hokum_master_caution ();

			hokum_damage.navigation_computer = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("NAVIGATION", "COMPUTER", "FAILURE");

			play_client_server_warning_message (en, SPEECH_SYSTEM_NAV_COMPUTER_FAILURE);
		}
	}

	////////////////////////////////////////

	if (damage.communications)
	{
		if (!hokum_damage.communications)
		{
			activate_hokum_master_caution ();

			hokum_damage.communications = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("COMMS", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_COMMS_FAILURE);
		}
	}

	////////////////////////////////////////

	if (damage.radar_warning_system)
	{
		if (!hokum_damage.radar_warning_system)
		{
			activate_hokum_master_caution ();

			hokum_damage.radar_warning_system = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("RADAR", "WARNING", "FAILURE");

			play_client_server_warning_message (en, SPEECH_SYSTEM_RADAR_WARNING_FAILURE);
		}
	}

	////////////////////////////////////////

	if (!get_global_simple_avionics ())
	{
		if (damage.head_up_display)
		{
			if (!hokum_damage.head_up_display)
			{
				activate_hokum_master_caution ();

				hokum_damage.head_up_display = TRUE;

				dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

				set_hokum_text_display_text ("HUD", "FAILURE", "");

				play_client_server_warning_message (en, SPEECH_SYSTEM_HUD_FAILURE);
			}
		}
	}

	////////////////////////////////////////

	if (!get_global_simple_avionics ())
	{
		if (damage.helmet_mounted_sight)
		{
			if (!hokum_damage.helmet_mounted_sight)
			{
				activate_hokum_master_caution ();

				hokum_damage.helmet_mounted_sight = TRUE;

				dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

				set_hokum_text_display_text ("HMS", "FAILURE", "");

				play_client_server_warning_message (en, SPEECH_SYSTEM_HELMET_MOUNTED_SIGHT_FAILURE);

				if (target_acquisition_system == TARGET_ACQUISITION_SYSTEM_HMS)
				{
					select_hokum_target_acquisition_system (TARGET_ACQUISITION_SYSTEM_OFF);
				}
			}
		}
	}

	////////////////////////////////////////

	if (damage.pilot_lh_mfd)
	{
		if (!hokum_damage.pilot_lh_mfd)
		{
			activate_hokum_master_caution ();

			hokum_damage.pilot_lh_mfd = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("MFD", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_MFD_FAILURE);

			select_hokum_mfd_mode (HOKUM_MFD_MODE_DAMAGED, HOKUM_MFD_LOCATION_PILOT_LHS);
		}
	}

	////////////////////////////////////////

	if (damage.pilot_rh_mfd)
	{
		if (!hokum_damage.pilot_rh_mfd)
		{
			activate_hokum_master_caution ();

			hokum_damage.pilot_rh_mfd = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("MFD", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_MFD_FAILURE);

			select_hokum_mfd_mode (HOKUM_MFD_MODE_DAMAGED, HOKUM_MFD_LOCATION_PILOT_RHS);
		}
	}

	////////////////////////////////////////

	if (damage.co_pilot_lh_mfd)
	{
		if (!hokum_damage.co_pilot_lh_mfd)
		{
			activate_hokum_master_caution ();

			hokum_damage.co_pilot_lh_mfd = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("MFD", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_MFD_FAILURE);

			select_hokum_mfd_mode (HOKUM_MFD_MODE_DAMAGED, HOKUM_MFD_LOCATION_CO_PILOT_LHS);
		}
	}

	////////////////////////////////////////

	if (damage.co_pilot_rh_mfd)
	{
		if (!hokum_damage.co_pilot_rh_mfd)
		{
			activate_hokum_master_caution ();

			hokum_damage.co_pilot_rh_mfd = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("MFD", "FAILURE", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_MFD_FAILURE);

			select_hokum_mfd_mode (HOKUM_MFD_MODE_DAMAGED, HOKUM_MFD_LOCATION_CO_PILOT_RHS);
		}
	}

	////////////////////////////////////////

	if (damage.night_vision_goggles)
	{
		if (!hokum_damage.night_vision_goggles)
		{
			activate_hokum_master_caution ();

			hokum_damage.night_vision_goggles = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("NVG", "DAMAGED", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_NIGHT_VISION_GOGGLES_FAILURE);

			night_vision_system_active = FALSE;
		}
	}

	////////////////////////////////////////

	if (damage.gun_jammed)
	{
		if (!hokum_damage.gun_jammed)
		{
			activate_hokum_master_caution ();

			hokum_damage.gun_jammed = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("GUN", "JAMMED", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_GUN_JAMMED);
		}
	}

	////////////////////////////////////////

	if (damage.lh_outer_pylon)
	{
		if (!hokum_damage.lh_outer_pylon)
		{
			activate_hokum_master_caution ();

			hokum_damage.lh_outer_pylon = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("HARDPOINT", "DAMAGED", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.lh_inner_pylon)
	{
		if (!hokum_damage.lh_inner_pylon)
		{
			activate_hokum_master_caution ();

			hokum_damage.lh_inner_pylon = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("HARDPOINT", "DAMAGED", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.rh_outer_pylon)
	{
		if (!hokum_damage.rh_outer_pylon)
		{
			activate_hokum_master_caution ();

			hokum_damage.rh_outer_pylon = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("HARDPOINT", "DAMAGED", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.rh_inner_pylon)
	{
		if (!hokum_damage.rh_inner_pylon)
		{
			activate_hokum_master_caution ();

			hokum_damage.rh_inner_pylon = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("HARDPOINT", "DAMAGED", "");

			play_client_server_warning_message (en, SPEECH_SYSTEM_HARDPOINT_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.lh_chaff_dispensers)
	{
		if (!hokum_damage.lh_chaff_dispensers)
		{
			activate_hokum_master_caution ();

			hokum_damage.lh_chaff_dispensers = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("CHAFF", "DISPENSER", "DAMAGED");

			play_client_server_warning_message (en, SPEECH_SYSTEM_CHAFF_DISPENSER_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.rh_chaff_dispensers)
	{
		if (!hokum_damage.rh_chaff_dispensers)
		{
			activate_hokum_master_caution ();

			hokum_damage.rh_chaff_dispensers = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("CHAFF", "DISPENSER", "DAMAGED");

			play_client_server_warning_message (en, SPEECH_SYSTEM_CHAFF_DISPENSER_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.lh_flare_dispensers)
	{
		if (!hokum_damage.lh_flare_dispensers)
		{
			activate_hokum_master_caution ();

			hokum_damage.lh_flare_dispensers = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("FLARE", "DISPENSER", "DAMAGED");

			play_client_server_warning_message (en, SPEECH_SYSTEM_FLARE_DISPENSER_DAMAGED);
		}
	}

	////////////////////////////////////////

	if (damage.rh_flare_dispensers)
	{
		if (!hokum_damage.rh_flare_dispensers)
		{
			activate_hokum_master_caution ();

			hokum_damage.rh_flare_dispensers = TRUE;

			dynamics_damage_model (DYNAMICS_DAMAGE_AVIONICS, FALSE);

			set_hokum_text_display_text ("FLARE", "DISPENSER", "DAMAGED");

			play_client_server_warning_message (en, SPEECH_SYSTEM_FLARE_DISPENSER_DAMAGED);
		}
	}

	////////////////////////////////////////

	set_hokum_weapon_damage_status ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void damage_hokum (gunship_damage_levels damage_level)
{
	unsigned int
		damage;

	hokum_damage_flags
		hokum_damage;

	damage = 0;

	switch (damage_level)
	{
		case GUNSHIP_DAMAGE_LEVEL_LIGHT:
		{
			damage |= 1 << (rand16 () & 0x1f);

			break;
		}
		case GUNSHIP_DAMAGE_LEVEL_MEDIUM:
		{
			damage |= 1 << (rand16 () & 0x1f);
			damage |= 1 << (rand16 () & 0x1f);

			break;
		}
		case GUNSHIP_DAMAGE_LEVEL_HEAVY:
		{
			damage |= 1 << (rand16 () & 0x1f);
			damage |= 1 << (rand16 () & 0x1f);
			damage |= 1 << (rand16 () & 0x1f);

			break;
		}
		default:
		{
			debug_fatal ("Invalid damage_level = %d", damage_level);

			break;
		}
	}

	hokum_damage.flags = damage;

	damage_systems (hokum_damage);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void notify_hokum_avionics_of_dynamics_fault (unsigned int damage)
{
	if (damage & DYNAMICS_DAMAGE_MAIN_ROTOR)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("MAIN ROTOR", "DAMAGED", "");
	}

	if (damage & DYNAMICS_DAMAGE_TAIL_ROTOR)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("TAIL ROTOR", "DAMAGED", "");
	}

	if (damage & DYNAMICS_DAMAGE_LEFT_ENGINE)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("LEFT", "ENGINE", "DAMAGED");
	}

	if (damage & DYNAMICS_DAMAGE_RIGHT_ENGINE)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("RIGHT", "ENGINE", "DAMAGED");
	}

	if (damage & DYNAMICS_DAMAGE_LEFT_ENGINE_FIRE)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("LEFT", "ENGINE", "FIRE");
	}

	if (damage & DYNAMICS_DAMAGE_RIGHT_ENGINE_FIRE)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("RIGHT", "ENGINE", "FIRE");
	}

	if (damage & DYNAMICS_DAMAGE_LOW_HYDRAULICS)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("HYDRAULICS", "PRESSURE", "LOW");
	}

	if (damage & DYNAMICS_DAMAGE_STABILISER)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("STABILISER", "FAILURE", "");
	}

	if (damage & DYNAMICS_DAMAGE_FUEL_LEAK)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("FUEL LEAK", "", "");
	}

	if (damage & DYNAMICS_DAMAGE_LOW_OIL_PRESSURE)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("LOW OIL", "PRESSURE", "");
	}

	if (damage & DYNAMICS_DAMAGE_HIGH_OIL_PRESSURE)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("HIGH OIL", "PRESSURE", "");
	}

	if (damage & DYNAMICS_DAMAGE_UNDERCARRIAGE)
	{
		activate_hokum_master_caution ();

		set_hokum_text_display_text ("GEAR", "DAMAGED", "");
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
