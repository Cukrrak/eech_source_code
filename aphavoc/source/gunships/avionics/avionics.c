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

static int
	initialised = FALSE;

static gunship_types
	gunship_type;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_avionics (void)
{
	ASSERT (!initialised);

	if (!get_gunship_entity ())
	{
		return;
	}

	initialised = TRUE;

	gunship_type = get_global_gunship_type ();

	switch (gunship_type)
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			load_gunship_avionics_damage ();

			initialise_common_hud ();

			initialise_common_mfd ();

			initialise_common_weapon_systems ();

			initialise_common_target_acquisition_systems ();

			initialise_common_night_vision_system ();

			initialise_apache_hud ();

			initialise_apache_mfd ();

			initialise_apache_weapon_systems ();

			initialise_apache_upfront_display ();

			initialise_apache_target_acquisition_systems ();

			initialise_apache_lamp_avionics ();

			initialise_apache_threat_warning_system ();

			//
			// push events after avionics have been initialised
			//

			push_event_overlay (set_common_avionics_events, "common avionics events");

			push_event_overlay (set_apache_avionics_events, "apache avionics events");

			push_event_overlay (set_gunship_view_mode_events, "gunship view mode events");

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			load_gunship_avionics_damage ();

			initialise_common_hud ();

			initialise_common_mfd ();

			initialise_common_weapon_systems ();

			initialise_common_target_acquisition_systems ();

			initialise_common_night_vision_system ();

			initialise_havoc_hud ();

			initialise_havoc_mfd ();

			initialise_havoc_ekran_display ();

			initialise_havoc_target_acquisition_systems ();

			initialise_havoc_lamp_avionics ();

			initialise_havoc_threat_warning_system ();

			//
			// push events after avionics have been initialised
			//

			push_event_overlay (set_common_avionics_events, "common avionics events");

			push_event_overlay (set_havoc_avionics_events, "havoc avionics events");

			push_event_overlay (set_gunship_view_mode_events, "gunship view mode events");

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			load_gunship_avionics_damage ();

			initialise_common_hud ();

			initialise_common_mfd ();

			initialise_common_weapon_systems ();

			initialise_common_target_acquisition_systems ();

			initialise_common_night_vision_system ();

			initialise_comanche_hud ();

			initialise_comanche_mfd ();

			initialise_comanche_weapon_systems ();

			initialise_comanche_target_acquisition_systems ();

			initialise_comanche_lamp_avionics ();

			initialise_comanche_threat_warning_system ();

			//
			// push events after avionics have been initialised
			//

			push_event_overlay (set_common_avionics_events, "common avionics events");

			push_event_overlay (set_comanche_avionics_events, "comanche avionics events");

			push_event_overlay (set_gunship_view_mode_events, "gunship view mode events");

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			load_gunship_avionics_damage ();

			initialise_common_hud ();

			initialise_common_mfd ();

			initialise_common_weapon_systems ();

			initialise_common_target_acquisition_systems ();

			initialise_common_night_vision_system ();

			initialise_hokum_hud ();

			initialise_hokum_mfd ();

			initialise_hokum_target_acquisition_systems ();

			initialise_hokum_lamp_avionics ();

			initialise_hokum_threat_warning_system ();

			//
			// push events after avionics have been initialised
			//

			push_event_overlay (set_common_avionics_events, "common avionics events");

			push_event_overlay (set_hokum_avionics_events, "hokum avionics events");

			push_event_overlay (set_gunship_view_mode_events, "gunship view mode events");

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_avionics (void)
{
	if (!initialised)
	{
		return;
	}

	initialised = FALSE;

	switch (gunship_type)
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			//
			// pop 'overlaid' target acquisition events first
			//

			deinitialise_common_target_acquisition_systems ();

			//
			// pop events before avionics are de-initialised
			//

			pop_event (set_gunship_view_mode_events);

			pop_event (set_apache_avionics_events);

			pop_event (set_common_avionics_events);

			save_gunship_avionics_damage ();

			deinitialise_common_hud ();

			deinitialise_common_mfd ();

			deinitialise_common_weapon_systems ();

			deinitialise_common_night_vision_system ();

			deinitialise_apache_hud ();

			deinitialise_apache_mfd ();

			deinitialise_apache_upfront_display ();

			deinitialise_apache_target_acquisition_systems ();

			deinitialise_apache_lamp_avionics ();

			deinitialise_apache_threat_warning_system ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			//
			// pop 'overlaid' target acquisition events first
			//

			deinitialise_common_target_acquisition_systems ();

			//
			// pop events before avionics are de-initialised
			//

			pop_event (set_gunship_view_mode_events);

			pop_event (set_havoc_avionics_events);

			pop_event (set_common_avionics_events);

			save_gunship_avionics_damage ();

			deinitialise_common_hud ();

			deinitialise_common_mfd ();

			deinitialise_common_weapon_systems ();

			deinitialise_common_night_vision_system ();

			deinitialise_havoc_hud ();

			deinitialise_havoc_mfd ();

			deinitialise_havoc_ekran_display ();

			deinitialise_havoc_target_acquisition_systems ();

			deinitialise_havoc_lamp_avionics ();

			deinitialise_havoc_threat_warning_system ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			//
			// pop 'overlaid' target acquisition events first
			//

			deinitialise_common_target_acquisition_systems ();

			//
			// pop events before avionics are de-initialised
			//

			pop_event (set_gunship_view_mode_events);

			pop_event (set_comanche_avionics_events);

			pop_event (set_common_avionics_events);

			save_gunship_avionics_damage ();

			deinitialise_common_hud ();

			deinitialise_common_mfd ();

			deinitialise_common_weapon_systems ();

			deinitialise_common_night_vision_system ();

			deinitialise_comanche_hud ();

			deinitialise_comanche_mfd ();

			deinitialise_comanche_target_acquisition_systems ();

			deinitialise_comanche_lamp_avionics ();

			deinitialise_comanche_threat_warning_system ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			//
			// pop 'overlaid' target acquisition events first
			//

			deinitialise_common_target_acquisition_systems ();

			//
			// pop events before avionics are de-initialised
			//

			pop_event (set_gunship_view_mode_events);

			pop_event (set_hokum_avionics_events);

			pop_event (set_common_avionics_events);

			save_gunship_avionics_damage ();

			deinitialise_common_hud ();

			deinitialise_common_mfd ();

			deinitialise_common_weapon_systems ();

			deinitialise_common_night_vision_system ();

			deinitialise_hokum_hud ();

			deinitialise_hokum_mfd ();

			deinitialise_hokum_target_acquisition_systems ();

			deinitialise_hokum_lamp_avionics ();

			deinitialise_hokum_threat_warning_system ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_avionics (void)
{
	if (!initialised)
	{
		return;
	}

	switch (gunship_type)
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			update_common_target_acquisition_systems ();

			update_apache_target_acquisition_system ();

			update_apache_weapon_systems ();

			update_apache_lamp_avionics ();

			update_apache_threat_warning_system ();

			update_apache_upfront_display ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			update_common_target_acquisition_systems ();

			update_havoc_target_acquisition_system ();

			update_havoc_weapon_systems ();

			update_havoc_lamp_avionics ();

			update_havoc_threat_warning_system ();

			update_havoc_ekran_display ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			update_common_target_acquisition_systems ();

			update_comanche_target_acquisition_system ();

			update_comanche_weapon_systems ();

			update_comanche_lamp_avionics ();

			update_comanche_threat_warning_system ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			update_common_target_acquisition_systems ();

			update_hokum_target_acquisition_system ();

			update_hokum_weapon_systems ();

			update_hokum_lamp_avionics ();

			update_hokum_threat_warning_system ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
