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

static void set_local_ptr_value (entity *en, ptr_types type, void *ptr)
{
	guide
		*raw;

	#if DEBUG_MODULE

	debug_log_entity_args (ENTITY_DEBUG_LOCAL, ENTITY_DEBUG_PTR_VALUE, en, type, ptr);

	#endif

	raw = get_local_entity_data (en);

	switch (type)
	{
		////////////////////////////////////////
		case PTR_TYPE_POSITION_ENTITY:
		////////////////////////////////////////
		{
			raw->position_entity = ptr;

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal_invalid_ptr_type (en, type);

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void *get_local_ptr_value (entity *en, ptr_types type)
{
	guide
		*raw;

	void
		*ptr;

	#if DEBUG_MODULE

	debug_log_entity_args (ENTITY_DEBUG_LOCAL, ENTITY_DEBUG_PTR_VALUE, en, type, ptr);

	#endif

	raw = get_local_entity_data (en);

	switch (type)
	{
		////////////////////////////////////////
		case PTR_TYPE_POSITION_ENTITY:
		////////////////////////////////////////
		{
			ptr = raw->position_entity;

			break;
		}
		////////////////////////////////////////
		case PTR_TYPE_TASK_LEADER:
		////////////////////////////////////////
		{
			entity
				*group,
				*group_leader;

			//
			// Task Leader is the first member in the follower list UNLESS the group leader is one of the followers
			//

			group = get_local_entity_parent (en, LIST_TYPE_GUIDE_STACK);

			ASSERT (group);

			group_leader = get_local_entity_ptr_value (group, PTR_TYPE_GROUP_LEADER);

			if (group_leader)
			{
				if (get_local_entity_parent (group_leader, LIST_TYPE_FOLLOWER) == en)
				{
					ptr = group_leader;
				}
				else
				{
					ptr = get_local_entity_first_child (en, LIST_TYPE_FOLLOWER);
				}
			}
			else
			{
				ptr = NULL;
			}

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal_invalid_ptr_type (en, type);

			break;
		}
	}

	return (ptr);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_guide_ptr_value_functions (entity_types type)
{

	fn_set_local_entity_ptr_value				[ENTITY_TYPE_GUIDE][PTR_TYPE_POSITION_ENTITY]	= set_local_ptr_value;
	fn_get_local_entity_ptr_value				[ENTITY_TYPE_GUIDE][PTR_TYPE_POSITION_ENTITY]	= get_local_ptr_value;

	fn_get_local_entity_ptr_value				[ENTITY_TYPE_GUIDE][PTR_TYPE_TASK_LEADER]			= get_local_ptr_value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
