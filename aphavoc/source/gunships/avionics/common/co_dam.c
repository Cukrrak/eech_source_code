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

int
	fire_extinguisher_used;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fully_repair_gunship_damage (void)
{
	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			fully_repair_apache_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			fully_repair_havoc_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			fully_repair_comanche_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			fully_repair_hokum_damage ();

			break;
		}
		////Moje 030518 Start
		case GUNSHIP_TYPE_BLACKHAWK:
		////////////////////////////////////////
		{
			fully_repair_blackhawk_damage ();

			break;
		}
		////Moje 030518 End
		////Moje 030612 Start
		////////////////////////////////////////
		case GUNSHIP_TYPE_HIND:
		////////////////////////////////////////
		{
			fully_repair_hind_damage ();
			break;
		}
		////Moje 020612 End
		////Moje 030816 Start
		case GUNSHIP_TYPE_AH64A:
		////////////////////////////////////////
		{
			fully_repair_ah64a_damage ();
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KA50:
		////////////////////////////////////////
		{
			fully_repair_ka50_damage ();
			break;
		}
		////Moje 020816 End
		////////////////////////////////////////
		case GUNSHIP_TYPE_VIPER:
		{
			fully_repair_viper_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KIOWA:
		////////////////////////////////////////
		{
			fully_repair_kiowa_damage ();

			break;
		}
		////////////////////////////////////////
		// GCsDriver  08-12-2007
		default:
		////////////////////////////////////////
		{
			fully_repair_default_damage ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void partially_repair_gunship_damage (void)
{
	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			partially_repair_apache_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			partially_repair_havoc_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			partially_repair_comanche_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			partially_repair_hokum_damage ();

			break;
		}
		////Moje 030817 Start
		case GUNSHIP_TYPE_BLACKHAWK:
		////////////////////////////////////////
		{
			partially_repair_blackhawk_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HIND:
		////////////////////////////////////////
		{
			partially_repair_hind_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_AH64A:
		////////////////////////////////////////
		{
			partially_repair_ah64a_damage ();
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KA50:
		////////////////////////////////////////
		{
			partially_repair_ka50_damage ();
			break;
		}
		////////////////////////////////////////
		////Moje 020817 End
		////////////////////////////////////////
		case GUNSHIP_TYPE_VIPER:
		////////////////////////////////////////
		{
			partially_repair_viper_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KIOWA:
		////////////////////////////////////////
		{
			partially_repair_kiowa_damage ();

			break;
		}

		////////////////////////////////////////
		// GCsDriver  08-12-2007
		default:
		////////////////////////////////////////
		{
			partially_repair_default_damage ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void repair_gunship_weapon_damage (void)
{
	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			repair_apache_weapon_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			repair_havoc_weapon_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			repair_comanche_weapon_damage ();

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			repair_hokum_weapon_damage ();

			break;
		}
		////Moje 030817 start
		case GUNSHIP_TYPE_BLACKHAWK:
		////////////////////////////////////////
		{
			repair_blackhawk_weapon_damage ();

			break;
		}
		case GUNSHIP_TYPE_HIND:
		////////////////////////////////////////
		{
			repair_hind_weapon_damage ();

			break;
		}
		case GUNSHIP_TYPE_AH64A:
		////////////////////////////////////////
		{
			repair_ah64a_weapon_damage ();
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KA50:
		////////////////////////////////////////
		{
			repair_ka50_weapon_damage ();
			break;
		}
		////Moje 030817 end
		case GUNSHIP_TYPE_VIPER:
		////////////////////////////////////////
		{
			repair_viper_weapon_damage ();
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KIOWA:
		////////////////////////////////////////
		{
			repair_kiowa_weapon_damage ();

			break;
		}
		////////////////////////////////////////

		////////////////////////////////////////
		// GCsDriver  08-12-2007
		default:
		////////////////////////////////////////
		{
			repair_default_weapon_damage ();

			break;
		}

	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void damage_gunship (gunship_damage_levels damage_level)
{
	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			damage_apache (damage_level);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			damage_havoc (damage_level);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			damage_comanche (damage_level);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			damage_hokum (damage_level);

			break;
		}
		////Moje 030817 start
		case GUNSHIP_TYPE_BLACKHAWK:
		////////////////////////////////////////
		{
			damage_blackhawk (damage_level);

			break;
		}
		case GUNSHIP_TYPE_HIND:
		////////////////////////////////////////
		{
			damage_hind (damage_level);

			break;
		}

		case GUNSHIP_TYPE_AH64A:
		////////////////////////////////////////
		{
			damage_ah64a (damage_level);
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KA50:
		////////////////////////////////////////
		{
			damage_ka50 (damage_level);
			break;
		}
		////Moje 030817 end
		////////////////////////////////////////
		case GUNSHIP_TYPE_VIPER:
		////////////////////////////////////////
		{
			damage_viper (damage_level);
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KIOWA:
		////////////////////////////////////////
		{
			damage_kiowa (damage_level);

			break;
		}

		////////////////////////////////////////
		// GCsDriver  08-12-2007
		default:
		////////////////////////////////////////
		{
			damage_default (damage_level);

			break;
		}

	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_gunship_comms_equipment_ok (void)
{
	int
		status;

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			status = !apache_damage.communications;

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			status = !havoc_damage.communications;

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			status = !comanche_damage.communications;

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			status = !hokum_damage.communications;

			break;
		}
		////Moje 030817 start
		////////////////////////////////////////
		case GUNSHIP_TYPE_BLACKHAWK:
		////////////////////////////////////////
		{
			status = !blackhawk_damage.communications;

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HIND:
		////////////////////////////////////////
		{
			status = !hind_damage.communications;

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_AH64A:
		////////////////////////////////////////
		{
			status = !ah64a_damage.communications;
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KA50:
		////////////////////////////////////////
		{
			status = !ka50_damage.communications;
			break;
		}
		////Moje 030817 end
		////////////////////////////////////////
		case GUNSHIP_TYPE_VIPER:
		////////////////////////////////////////
		{
			status = !viper_damage.communications;
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KIOWA:
		////////////////////////////////////////
		{
			status = !kiowa_damage.communications;

			break;
		}
		////////////////////////////////////////
		// GCsDriver  08-12-2007
		default:
		////////////////////////////////////////
		{
			//status = FALSE;
			status = !default_damage.communications;

			break;
		}
	}

	return (status);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void notify_avionics_of_dynamics_fault (unsigned int damage)
{
	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			notify_apache_avionics_of_dynamics_fault (damage);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			notify_havoc_avionics_of_dynamics_fault (damage);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			notify_comanche_avionics_of_dynamics_fault (damage);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			notify_hokum_avionics_of_dynamics_fault (damage);

			break;
		}
		////Moje 030817 start
		case GUNSHIP_TYPE_BLACKHAWK:
		////////////////////////////////////////
		{
			notify_blackhawk_avionics_of_dynamics_fault (damage);

			break;
		}
		case GUNSHIP_TYPE_HIND:
		////////////////////////////////////////
		{
			notify_hind_avionics_of_dynamics_fault (damage);

			break;
		}
		case GUNSHIP_TYPE_AH64A:
		////////////////////////////////////////
		{
			notify_ah64a_avionics_of_dynamics_fault (damage);
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KA50:
		////////////////////////////////////////
		{
			notify_ka50_avionics_of_dynamics_fault (damage);
			break;
		}
		////Moje 030817 end
		////////////////////////////////////////
		case GUNSHIP_TYPE_VIPER:
		////////////////////////////////////////
		{
			notify_viper_avionics_of_dynamics_fault (damage);
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KIOWA:
		////////////////////////////////////////
		{
			notify_kiowa_avionics_of_dynamics_fault (damage);

			break;
		}
		////////////////////////////////////////

		////////////////////////////////////////
		// GCsDriver  08-12-2007
		default:
		////////////////////////////////////////
		{
			notify_default_avionics_of_dynamics_fault (damage);

			break;
		}

	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void damage_client_server_entity_avionics (entity *en, gunship_damage_levels damage_level)
{
	ASSERT (en);

	if (get_local_entity_int_value (en, INT_TYPE_PLAYER) != ENTITY_PLAYER_AI)
	{
		if (en == get_gunship_entity ())
		{
			damage_gunship (damage_level);
		}
		else
		{
			transmit_entity_comms_message (ENTITY_COMMS_DAMAGE_PLAYER_AVIONICS, en, damage_level);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void fully_repair_local_entity_avionics (entity *en)
{
	ASSERT (en);

	if (en == get_gunship_entity ())
	{
		switch (get_global_gunship_type ())
		{
			////////////////////////////////////////
			// JB 030313 Fly any aircraft
//			default:
			case GUNSHIP_TYPE_APACHE:
			////////////////////////////////////////
			{
				fully_repair_apache_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, apache_damage.flags);

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_HAVOC:
			////////////////////////////////////////
			{
				fully_repair_havoc_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, havoc_damage.flags);

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_COMANCHE:
			////////////////////////////////////////
			{
				fully_repair_comanche_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, comanche_damage.flags);

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_HOKUM:
			////////////////////////////////////////
			{
				fully_repair_hokum_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, hokum_damage.flags);

				break;
			}
			////Moje 030817 start
			case GUNSHIP_TYPE_BLACKHAWK:
			////////////////////////////////////////
			{
				fully_repair_blackhawk_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, blackhawk_damage.flags);

				break;
			}
			case GUNSHIP_TYPE_HIND:
			////////////////////////////////////////
			{
				fully_repair_hind_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, hind_damage.flags);

				break;
			}
			case GUNSHIP_TYPE_AH64A:
			////////////////////////////////////////
			{
				fully_repair_ah64a_damage ();
				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, ah64a_damage.flags);
				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_KA50:
			////////////////////////////////////////
			{
				fully_repair_ka50_damage ();
				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, ka50_damage.flags);
				break;
			}
			////Moje 030817 end
			////////////////////////////////////////
			case GUNSHIP_TYPE_VIPER:
			////////////////////////////////////////
			{
				fully_repair_viper_damage ();
				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, viper_damage.flags);
				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_KIOWA:
			////////////////////////////////////////
			{
				fully_repair_kiowa_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, kiowa_damage.flags);

				break;
			}
			////////////////////////////////////////

			////////////////////////////////////////
			// GCsDriver  08-12-2007
			default:
			////////////////////////////////////////
			{
				fully_repair_default_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, default_damage.flags);

				break;
			}

		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void partially_repair_local_entity_avionics (entity *en)
{
	ASSERT (en);

	if (en == get_gunship_entity ())
	{
		switch (get_global_gunship_type ())
		{
			////////////////////////////////////////
			// JB 030313 Fly any aircraft
//			default:
			case GUNSHIP_TYPE_APACHE:
			////////////////////////////////////////
			{
				partially_repair_apache_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, apache_damage.flags);

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_HAVOC:
			////////////////////////////////////////
			{
				partially_repair_havoc_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, havoc_damage.flags);

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_COMANCHE:
			////////////////////////////////////////
			{
				partially_repair_comanche_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, comanche_damage.flags);

				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_HOKUM:
			////////////////////////////////////////
			{
				partially_repair_hokum_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, hokum_damage.flags);

				break;
			}
			////Moje 030817 start
			case GUNSHIP_TYPE_BLACKHAWK:
			////////////////////////////////////////
			{
				partially_repair_blackhawk_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, blackhawk_damage.flags);

				break;
			}
			case GUNSHIP_TYPE_HIND:
			////////////////////////////////////////
			{
				partially_repair_hind_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, hind_damage.flags);

				break;
			}
			case GUNSHIP_TYPE_AH64A:
			////////////////////////////////////////
			{
				partially_repair_ah64a_damage ();
				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, ah64a_damage.flags);
				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_KA50:
			////////////////////////////////////////
			{
				partially_repair_ka50_damage ();
				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, ka50_damage.flags);
				break;
			}
			////Moje 030817 end
			////////////////////////////////////////
			case GUNSHIP_TYPE_VIPER:
			////////////////////////////////////////
			{
				partially_repair_viper_damage ();
				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, viper_damage.flags);
				break;
			}
			////////////////////////////////////////
			case GUNSHIP_TYPE_KIOWA:
			////////////////////////////////////////
			{
				partially_repair_kiowa_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, kiowa_damage.flags);

				break;
			}
			////////////////////////////////////////

			////////////////////////////////////////
			// GCsDriver  08-12-2007
			default:
			////////////////////////////////////////
			{
				partially_repair_default_damage ();

				set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, default_damage.flags);

				break;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void load_gunship_avionics_damage (void)
{
	fire_extinguisher_used = 0;

	switch (get_global_gunship_type ())
	{
		////////////////////////////////////////
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			apache_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_apache_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load Apache damage: %x", apache_damage.flags);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			havoc_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_havoc_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load Havoc damage: %x", havoc_damage.flags);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			comanche_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_comanche_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load Comanche damage: %x", comanche_damage.flags);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			hokum_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_hokum_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load Hokum damage: %x", hokum_damage.flags);

			break;
		}
		////Moje 030817 start
		case GUNSHIP_TYPE_BLACKHAWK:
		////////////////////////////////////////
		{
			blackhawk_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_blackhawk_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load blackhawk damage: %x", blackhawk_damage.flags);

			break;
		}
		case GUNSHIP_TYPE_HIND:
		////////////////////////////////////////
		{
			hind_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_hind_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load Hind damage: %x", hind_damage.flags);

			break;
		}
		case GUNSHIP_TYPE_AH64A:
		////////////////////////////////////////
		{
			ah64a_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);
			set_ah64a_weapon_damage_status ();
			debug_colour_log (DEBUG_COLOUR_AMBER, "Load ah64a damage: %x", ah64a_damage.flags);
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KA50:
		////////////////////////////////////////
		{
			ka50_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_ka50_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load ka50 damage: %x", ka50_damage.flags);

			break;
		}
		////Moje 030817 end
		////////////////////////////////////////
		case GUNSHIP_TYPE_VIPER:
		////////////////////////////////////////
		{
			viper_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_viper_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load viper damage: %x", viper_damage.flags);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KIOWA:
		////////////////////////////////////////
		{
			kiowa_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_kiowa_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load Kiowa damage: %x", kiowa_damage.flags);

			break;
		}
		////////////////////////////////////////

		////////////////////////////////////////
		// GCsDriver  08-12-2007
		default:
		////////////////////////////////////////
		{
			default_damage.flags = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS);

			set_default_weapon_damage_status ();

			debug_colour_log (DEBUG_COLOUR_AMBER, "Load default damage: %x", default_damage.flags);

			break;
		}

	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void save_gunship_avionics_damage (unsigned gunship_type)
{
	switch (gunship_type)
	{
		////////////////////////////////////////
		// JB 030313 Fly any aircraft
//		default:
		case GUNSHIP_TYPE_APACHE:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, apache_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save Apache damage: %x", apache_damage.flags);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HAVOC:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, havoc_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save Havoc damage: %x", havoc_damage.flags);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_COMANCHE:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, comanche_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save Comanche damage: %x", comanche_damage.flags);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_HOKUM:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, hokum_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save Hokum damage: %x", hokum_damage.flags);

			break;
		}
		////Moje 030817 start
		case GUNSHIP_TYPE_BLACKHAWK:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, blackhawk_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save Blackhawk damage: %x", blackhawk_damage.flags);

			break;
		}
		case GUNSHIP_TYPE_HIND:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, hind_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save Hind damage: %x", hind_damage.flags);

			break;
		}
		case GUNSHIP_TYPE_AH64A:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, ah64a_damage.flags);
			debug_colour_log (DEBUG_COLOUR_AMBER, "Save ah64a damage: %x", ah64a_damage.flags);
			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KA50:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, ka50_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save ka50 damage: %x", ka50_damage.flags);

			break;
		}
		////Moje 0300817 end
		////////////////////////////////////////
		case GUNSHIP_TYPE_VIPER:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, viper_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save viper damage: %x", viper_damage.flags);

			break;
		}
		////////////////////////////////////////
		case GUNSHIP_TYPE_KIOWA:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, kiowa_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save Kiowa damage: %x", kiowa_damage.flags);

			break;
		}
		////////////////////////////////////////

		////////////////////////////////////////
		// GCsDriver  08-12-2007
		default:
		////////////////////////////////////////
		{
			set_local_entity_int_value (get_gunship_entity (), INT_TYPE_HELICOPTER_DAMAGE_FLAGS, default_damage.flags);

			debug_colour_log (DEBUG_COLOUR_AMBER, "Save default damage: %x", default_damage.flags);

			break;
		}
	}
	
	// SAVE FUEL SUPPLY LEVEL
	if (get_current_flight_dynamics ())
	{
		float fuel = get_current_flight_dynamics_fuel_weight ();
		set_client_server_entity_float_value (get_gunship_entity (), FLOAT_TYPE_FUEL_SUPPLY_LEVEL, fuel);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
