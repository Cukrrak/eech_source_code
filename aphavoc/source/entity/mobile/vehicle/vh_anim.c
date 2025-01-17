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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// LOADING DOORS
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#define VEHICLE_LOADING_DOORS_CLOSED_FLOAT_VALUE 					0.0

#define VEHICLE_LOADING_DOORS_OPENING_FLOAT_VALUE 						1.0

//#define VEHICLE_LOADING_DOORS_OPEN_FLOAT_VALUE						2.0

#define VEHICLE_LOADING_DOORS_CLOSING_FLOAT_VALUE						3.0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void animate_vehicle_loading_doors( entity *en )
{
	vehicle
		*raw;

	//
	// articulate the doors on the 3d objects
	//

	ASSERT( en );

	if (get_local_entity_int_value (en, INT_TYPE_OBJECT_DRAWN_ONCE_THIS_FRAME))
	{
		return;
	}

	if (get_local_entity_type (en) != ENTITY_TYPE_SHIP_VEHICLE)
	{
		//
		// Don't animate ship doors until we've sorted out what's happening with them
		//

		return;
	}

	raw = (vehicle *) get_local_entity_data( en );

	animate_entity_reversable_keyframed_sub_objects( raw->inst3d, OBJECT_3D_SUB_OBJECT_LOADING_DOOR, raw->loading_door_state );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_vehicle_loading_doors( entity *en )
{
	vehicle
		*raw;

	int
		door_state;

	//
	// updates the doors status ( regardless of whether the vehicle is drawn or not )
	//

	ASSERT( en );

	raw = (vehicle *) get_local_entity_data( en );

	door_state = update_entity_reversable_keyframed_value( en, &raw->loading_door_state, 0.5 );

	if ( ( in_flight_articulation_test ) && ( get_comms_model() == COMMS_MODEL_SERVER ) )
	{
		switch ( door_state )
		{
			//////////////////////////////////////////////////
			case 0:
			//////////////////////////////////////////////////
			{
				open_client_server_entity_loading_doors( en );

				break;
			}
			//////////////////////////////////////////////////
			case 2:
			//////////////////////////////////////////////////
			{
				close_client_server_entity_loading_doors( en );

				break;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// WEAPON SYSTEM READY
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#define VEHICLE_WEAPON_SYSTEM_READY_CLOSED_FLOAT_VALUE 						0.0

#define VEHICLE_WEAPON_SYSTEM_READY_OPENING_FLOAT_VALUE 							1.0

//#define VEHICLE_WEAPON_SYSTEM_READY_OPEN_FLOAT_VALUE							2.0

#define VEHICLE_WEAPON_SYSTEM_READY_CLOSING_FLOAT_VALUE							3.0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void animate_vehicle_weapon_system_ready( entity *en )
{
	vehicle
		*raw;

	//
	// articulate the "weapon system readies" on the 3d objects
	//

	ASSERT( en );

	if (get_local_entity_int_value (en, INT_TYPE_OBJECT_DRAWN_ONCE_THIS_FRAME))
	{
		return;
	}

	raw = (vehicle *) get_local_entity_data( en );

	animate_entity_reversable_keyframed_sub_objects( raw->inst3d, OBJECT_3D_SUB_OBJECT_WEAPON_SYSTEM_READY, raw->weapon_system_ready_state );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_vehicle_weapon_system_ready( entity *en )
{
	vehicle
		*raw;

	int
		wsr_state;

	//
	// updates the weapon system ready status ( regardless of whether the vehicle is drawn or not )
	//

	ASSERT( en );

	raw = (vehicle *) get_local_entity_data( en );

	wsr_state = update_entity_reversable_keyframed_value( en, &raw->weapon_system_ready_state, 0.5 );

	if ( in_flight_articulation_test )
	{
		switch ( wsr_state )
		{
			//////////////////////////////////////////////////
			case 0:
			//////////////////////////////////////////////////
			{
				open_entity_weapon_system_ready( en );

				break;
			}
			//////////////////////////////////////////////////
			case 2:
			//////////////////////////////////////////////////
			{
				close_entity_weapon_system_ready( en );

				break;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RADAR
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void animate_vehicle_radar( entity *en )
{
	vehicle
		*raw;

	//
	// articulate the radar on the 3d objects
	//

	ASSERT( en );

	if (get_local_entity_int_value (en, INT_TYPE_OBJECT_DRAWN_ONCE_THIS_FRAME))
	{
		return;
	}

	raw = (vehicle *) get_local_entity_data( en );

	animate_entity_simple_keyframed_sub_objects( raw->inst3d, OBJECT_3D_SUB_OBJECT_RADAR, raw->radar_rotation_state );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_vehicle_radar( entity *en )
{
	vehicle
		*raw;

	//
	// updates the radar rotation ( regardless of whether the vehicle is drawn or not )
	//

	ASSERT( en );

	raw = (vehicle *) get_local_entity_data( en );

	update_entity_simple_keyframed_value( en, &raw->radar_rotation_state, 0.16666 );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// HEAD-LIGHTS
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_vehicle_headlight_state (entity *en, int state)
{
	object_3d_instance
		*inst3d;

	ASSERT (en);

	inst3d = (object_3d_instance *) get_local_entity_ptr_value (en, PTR_TYPE_INSTANCE_3D_OBJECT);

	ASSERT (inst3d);

	set_sub_object_type_visible_status (inst3d, OBJECT_3D_SUB_OBJECT_EFFECT_HEADLIGHTS, state);

	set_local_entity_int_value (en, INT_TYPE_LIGHTS_ON, state);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


