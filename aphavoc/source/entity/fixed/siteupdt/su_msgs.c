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

static int response_to_collision (entity_messages message, entity *receiver, entity *sender, va_list pargs)
{
	entity
		*aggressor;

	int
		total_damage_level;

	float
		damage_modifier;

	#if DEBUG_MODULE

	debug_log_entity_message (message, receiver, sender, pargs);

	#endif

	damage_modifier = va_arg (pargs, double);

	if (sender)
	{
		if (get_local_entity_type (sender) == ENTITY_TYPE_WEAPON)
		{
			aggressor = get_local_entity_parent (sender, LIST_TYPE_LAUNCHED_WEAPON);
		}
		else
		{
			aggressor = sender;
		}

		if (aggressor)
		{
			notify_keysite_structure_under_attack (receiver, aggressor);
		}
	}
	else
	{
		aggressor = NULL;
	}

	damage_client_server_entity (receiver, sender, damage_modifier);

	total_damage_level = get_local_entity_int_value (receiver, INT_TYPE_DAMAGE_LEVEL);

	if (total_damage_level <= 0)
	{
		if (aggressor)
		{
			if (get_local_entity_float_value (receiver, FLOAT_TYPE_FIXED_OBJECT_IMPORTANCE) >= 0.5)
			{
				if (get_local_entity_int_value (aggressor, INT_TYPE_PLAYER) == ENTITY_PLAYER_LOCAL)
				{
					inc_player_log_kills (get_global_gunship_side (), get_current_player_log (), receiver);
				}
				else if (get_local_entity_int_value (aggressor, INT_TYPE_PLAYER) == ENTITY_PLAYER_REMOTE)
				{
					transmit_entity_comms_message (ENTITY_COMMS_PLAYER_KILL, aggressor, receiver);
				}
			}
		}

		kill_client_server_entity (receiver);
	}

	return (TRUE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_articulate_loading_doors (entity_messages message, entity *receiver, entity *sender, va_list pargs)
{
	//
	// WATING FOR SOUND EFFECT DATA...
	//

	sound_sample_indices
		sample_index;

	vec3d
		*position;

	#if DEBUG_MODULE

	debug_log_entity_message (message, receiver, sender, pargs);

	#endif

	ASSERT (get_comms_model () == COMMS_MODEL_SERVER);

	position = get_local_entity_vec3d_ptr (receiver, VEC3D_TYPE_POSITION);

	ASSERT (position);

	sample_index = SOUND_SAMPLE_INDEX_HELICOPTER_DOORS;

	create_client_server_sound_effect_entity
	(
		get_local_sector_entity (position),
		ENTITY_SIDE_NEUTRAL,
		ENTITY_SUB_TYPE_EFFECT_SOUND_MISC,
		SOUND_CHANNEL_SOUND_EFFECT,
		SOUND_LOCALITY_ALL,
		NULL,												// position
		1.0,												// amplification
		1.0,												// Werewolf pitch
		TRUE,												// valid sound effect
		FALSE,											// looping
		1,													// sample count
		&sample_index									// sample index list
	);

	return (TRUE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if DEBUG_MODULE

static int response_to_link_child (entity_messages message, entity *receiver, entity *sender, va_list pargs)
{
	debug_log_entity_message (message, receiver, sender, pargs);

	return (TRUE);
}

#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if DEBUG_MODULE

static int response_to_unlink_child (entity_messages message, entity *receiver, entity *sender, va_list pargs)
{
	debug_log_entity_message (message, receiver, sender, pargs);

	return (TRUE);
}

#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if DEBUG_MODULE

static int response_to_link_parent (entity_messages message, entity *receiver, entity *sender, va_list pargs)
{
	debug_log_entity_message (message, receiver, sender, pargs);

	return (TRUE);
}

#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if DEBUG_MODULE

static int response_to_unlink_parent (entity_messages message, entity *receiver, entity *sender, va_list pargs)
{
	debug_log_entity_message (message, receiver, sender, pargs);

	return (TRUE);
}

#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_site_updatable_message_responses (void)
{
	overload_fixed_message_responses (ENTITY_TYPE_SITE_UPDATABLE);

	message_responses[ENTITY_TYPE_SITE_UPDATABLE][ENTITY_MESSAGE_COLLISION]						= response_to_collision;

	message_responses[ENTITY_TYPE_SITE_UPDATABLE][ENTITY_MESSAGE_ARTICULATE_LOADING_DOORS]	= response_to_articulate_loading_doors;

	#if DEBUG_MODULE

	message_responses[ENTITY_TYPE_SITE_UPDATABLE][ENTITY_MESSAGE_LINK_CHILD]		= response_to_link_child;

	message_responses[ENTITY_TYPE_SITE_UPDATABLE][ENTITY_MESSAGE_UNLINK_CHILD]		= response_to_unlink_child;

	message_responses[ENTITY_TYPE_SITE_UPDATABLE][ENTITY_MESSAGE_LINK_PARENT]		= response_to_link_parent;

	message_responses[ENTITY_TYPE_SITE_UPDATABLE][ENTITY_MESSAGE_UNLINK_PARENT]	= response_to_unlink_parent;

	#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
