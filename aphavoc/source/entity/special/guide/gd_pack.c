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

#define DEBUG_MODULE 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "project.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void pack_local_data (entity *en, pack_modes mode)
{
	
	ASSERT ((mode >= 0) && (mode < NUM_PACK_MODES));
	
	switch (mode)
	{
		////////////////////////////////////////
		case PACK_MODE_SERVER_SESSION:
		case PACK_MODE_CLIENT_SESSION:
		////////////////////////////////////////
		{
			guide
				*raw;

			raw = get_local_entity_data (en);

			pack_entity_type (get_local_entity_type (en));

			pack_entity_safe_ptr (en);

			//
			// pack data (in exactly the same order as the data is unpacked)
			//

			pack_int_value (en, INT_TYPE_ENTITY_SUB_TYPE, raw->sub_type);

			pack_list_root (en, LIST_TYPE_FOLLOWER, &raw->follower_root);

			pack_list_link (en, LIST_TYPE_CURRENT_WAYPOINT, &raw->current_waypoint_link);

			pack_list_link (en, LIST_TYPE_GUIDE, &raw->guide_link);

			pack_list_link (en, LIST_TYPE_GUIDE_STACK, &raw->guide_stack_link);

			// update link

			pack_int_value (en, INT_TYPE_GUIDE_POSITION_TYPE, raw->guide_position_type);

			if (guide_position_type_virtual [raw->guide_position_type])
			{
				pack_vec3d (en, VEC3D_TYPE_RELATIVE_POSITION, &raw->position);

				pack_entity_safe_ptr (raw->position_entity);
			}
			else
			{
				pack_vec3d (en, VEC3D_TYPE_POSITION, &raw->position);
			}

			pack_int_value (en, INT_TYPE_VALID_GUIDE_MEMBERS, raw->valid_guide_members);

			pack_int_value (en, INT_TYPE_CHECK_WAYPOINT_ACTION, raw->check_waypoint_action);

			pack_float_value (en, FLOAT_TYPE_VELOCITY, raw->velocity);

			//
			// guide criteria
			//
			{
				int
					loop,
					valid;

				for (loop = 0; loop < NUM_GUIDE_CRITERIA_TYPES; loop ++)
				{
					valid = raw->criteria [loop].valid;
	
					pack_int_value (en, INT_TYPE_VALID, valid);

					if (valid)
					{
						pack_float_value (en, FLOAT_TYPE_GUIDE_CRITERIA_VALUE, raw->criteria [loop].value);
					}
				}
			}

			break;
		}
		////////////////////////////////////////
		case PACK_MODE_BROWSE_SESSION:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case PACK_MODE_UPDATE_ENTITY:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void unpack_local_data (entity *en, entity_types type, pack_modes mode)
{
	ASSERT ((mode >= 0) && (mode < NUM_PACK_MODES));
	
	switch (mode)
	{
		////////////////////////////////////////
		case PACK_MODE_SERVER_SESSION:
		case PACK_MODE_CLIENT_SESSION:
		////////////////////////////////////////
		{
			int
				index;

			guide
				*raw;

			//
			// create entity
			//

			index = unpack_entity_safe_index ();

			en = get_free_entity (index);

			set_local_entity_type (en, type);

			raw = malloc_fast_mem (sizeof (guide));

			set_local_entity_data (en, raw);

			memset (raw, 0, sizeof (guide));

			//
			// unpack data (in exactly the same order as the data was packed)
			//

			raw->sub_type = unpack_int_value (en, INT_TYPE_ENTITY_SUB_TYPE);

			unpack_list_root (en, LIST_TYPE_FOLLOWER, &raw->follower_root);

			unpack_list_link (en, LIST_TYPE_CURRENT_WAYPOINT, &raw->current_waypoint_link);

			unpack_list_link (en, LIST_TYPE_GUIDE, &raw->guide_link);

			unpack_list_link (en, LIST_TYPE_GUIDE_STACK, &raw->guide_stack_link);

			// update link

			raw->guide_position_type = unpack_int_value (en, INT_TYPE_GUIDE_POSITION_TYPE);

			if (guide_position_type_virtual [raw->guide_position_type])
			{
				unpack_vec3d (en, VEC3D_TYPE_RELATIVE_POSITION, &raw->position);

				index = unpack_entity_safe_index ();

				raw->position_entity = get_local_entity_ptr (index);
			}
			else
			{
				unpack_vec3d (en, VEC3D_TYPE_POSITION, &raw->position);
			}

			raw->valid_guide_members = unpack_int_value (en, INT_TYPE_VALID_GUIDE_MEMBERS);

			raw->check_waypoint_action = unpack_int_value (en, INT_TYPE_CHECK_WAYPOINT_ACTION);

			raw->velocity = unpack_float_value (en, FLOAT_TYPE_VELOCITY);

			//
			// guide criteria
			//
			{
				int
					loop,
					valid;

				for (loop = 0; loop < NUM_GUIDE_CRITERIA_TYPES; loop ++)
				{
					valid = unpack_int_value (en, INT_TYPE_VALID);

					raw->criteria [loop].valid = valid;

					if (valid)
					{
						raw->criteria [loop].value = unpack_float_value (en, FLOAT_TYPE_GUIDE_CRITERIA_VALUE);
					}
				}
			}

			//
			// link into system
			//

			insert_local_entity_into_parents_child_list (en, LIST_TYPE_UPDATE, get_update_entity (), NULL);

			break;
		}
		////////////////////////////////////////
		case PACK_MODE_BROWSE_SESSION:
		////////////////////////////////////////
		{
			break;
		}
		////////////////////////////////////////
		case PACK_MODE_UPDATE_ENTITY:
		////////////////////////////////////////
		{
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_guide_pack_functions (void)
{
	fn_pack_local_entity_data[ENTITY_TYPE_GUIDE]         = pack_local_data;
	
	fn_unpack_local_entity_data[ENTITY_TYPE_GUIDE]       = unpack_local_data;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
