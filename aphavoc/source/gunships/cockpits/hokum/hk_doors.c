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

#define CANOPY_DOOR_STATE_UNINITIALISED	((float) (-1000.0))

#define CANOPY_DOOR_STATE_CLOSED				((float) (0.0))
#define CANOPY_DOOR_STATE_OPEN				((float) (1.0))

static float
	canopy_door_state;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static float get_canopy_doors_aiming_state (void)
{
	float
		aiming_state;

	ASSERT (get_gunship_entity ());

	ASSERT (current_flight_dynamics);

	if (get_local_entity_int_value (get_gunship_entity (), INT_TYPE_AIRBORNE_AIRCRAFT))
	{
		aiming_state = CANOPY_DOOR_STATE_CLOSED;
	}
	else
	{
		if (current_flight_dynamics->rotor_brake)
		{
			aiming_state = CANOPY_DOOR_STATE_OPEN;
		}
		else
		{
			aiming_state = CANOPY_DOOR_STATE_CLOSED;
		}
	}

	return (aiming_state);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_hokum_virtual_cockpit_canopy_doors (void)
{
	canopy_door_state = CANOPY_DOOR_STATE_UNINITIALISED;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void animate_hokum_virtual_cockpit_canopy_doors (void)
{
	int
		ejected;

	float
		aiming_state;

	object_3d_instance
		*inst3d;

	object_3d_sub_object_search_data
		search;

	ASSERT (virtual_cockpit_inst3d);

	if (canopy_door_state == CANOPY_DOOR_STATE_UNINITIALISED)
	{
		canopy_door_state = get_canopy_doors_aiming_state ();
	}

	aiming_state = get_canopy_doors_aiming_state ();

	if (aiming_state > canopy_door_state)
	{
		canopy_door_state += get_delta_time () * 0.5;

		if (canopy_door_state > CANOPY_DOOR_STATE_OPEN)
		{
			canopy_door_state = CANOPY_DOOR_STATE_OPEN;
		}
	}
	else if (aiming_state < canopy_door_state)
	{
		canopy_door_state -= get_delta_time () * 0.5;

		if (canopy_door_state < CANOPY_DOOR_STATE_CLOSED)
		{
			canopy_door_state = CANOPY_DOOR_STATE_CLOSED;
		}
	}

	animate_keyframed_sub_object_type (virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_CANOPY_DOORS, canopy_door_state);

	//
	// keep external 3D model in sync
	//

	inst3d = get_local_entity_ptr_value (get_gunship_entity (), PTR_TYPE_INSTANCE_3D_OBJECT);

	ASSERT (inst3d);

	animate_keyframed_sub_object_type (inst3d, OBJECT_3D_SUB_OBJECT_CANOPY_DOORS, canopy_door_state);

	//
	// ejected
	//

	ejected = get_local_entity_int_value (get_gunship_entity (), INT_TYPE_EJECTED);

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_CANOPY_DOORS;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search.result_sub_object->visible_object = !ejected;
	}

	search.search_depth = 1;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_CANOPY_DOORS;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search.result_sub_object->visible_object = !ejected;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
