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

static void set_local_int_value (entity *en, int_types type, int value)
{
	sound_effect
		*raw;

	#if DEBUG_MODULE

	debug_log_entity_args (ENTITY_DEBUG_LOCAL, ENTITY_DEBUG_INT_VALUE, en, type, value);

	#endif

	raw = get_local_entity_data (en);

	switch (type)
	{
		////////////////////////////////////////
		case INT_TYPE_SIDE:
		////////////////////////////////////////
		{
			raw->side = value;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_CHANNEL:
		////////////////////////////////////////
		{
			raw->sound_channel = value;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_EFFECT_LOOPING:
		////////////////////////////////////////
		{
			raw->looping = value;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_EFFECT_PANNING:
		////////////////////////////////////////
		{
			raw->panning = value;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_EFFECT_SEQUENCE_COUNT:
		////////////////////////////////////////
		{
			raw->sound_effect_sequence_count = value;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_LOCALITY:
		////////////////////////////////////////
		{
			raw->sound_locality = value;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_VALID_SOUND_EFFECT:
		////////////////////////////////////////
		{
			raw->valid_sound_effect = value;

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal_invalid_int_type (en, type);

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void set_remote_int_value (entity *en, int_types type, int value)
{
	#if DEBUG_MODULE

	debug_log_entity_args (ENTITY_DEBUG_REMOTE, ENTITY_DEBUG_INT_VALUE, en, type, value);

	#endif

	transmit_entity_comms_message (ENTITY_COMMS_INT_VALUE, en, type, value);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void set_server_int_value (entity *en, int_types type, int value)
{
	validate_client_server_local_fn ();

	set_local_int_value (en, type, value);

	validate_client_server_remote_fn ();

	set_remote_int_value (en, type, value);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void set_client_int_value (entity *en, int_types type, int value)
{
	if (get_comms_data_flow () == COMMS_DATA_FLOW_TX)
	{
		validate_client_server_remote_fn ();

		set_remote_int_value (en, type, value);
	}
	else
	{
		validate_client_server_local_fn ();

		set_local_int_value (en, type, value);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int get_local_int_value (entity *en, int_types type)
{
	sound_effect
		*raw;

	int
		value;

	raw = get_local_entity_data (en);

	switch (type)
	{
		////////////////////////////////////////
		case INT_TYPE_MAXIMUM_VOLUME:
		////////////////////////////////////////
		{
			// possibly store in entity ??

			ASSERT (raw->effect_index);

			value = application_sound_effects [raw->effect_index [0]].maximum_volume;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SIDE:
		////////////////////////////////////////
		{
			value = raw->side;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_CHANNEL:
		////////////////////////////////////////
		{
			value = raw->sound_channel;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_EFFECT_LOOPING:
		////////////////////////////////////////
		{
			value = raw->looping;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_EFFECT_PANNING:
		////////////////////////////////////////
		{
			value = raw->panning;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_EFFECT_RATE:
		////////////////////////////////////////
		{
			ASSERT (raw->effect_index);

			value = application_sound_effects [raw->effect_index [0]].rate;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_EFFECT_SEQUENCE_COUNT:
		////////////////////////////////////////
		{
			value = raw->sound_effect_sequence_count;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_SOUND_LOCALITY:
		////////////////////////////////////////
		{
			value = raw->sound_locality;

			break;
		}
		////////////////////////////////////////
		case INT_TYPE_VALID_SOUND_EFFECT:
		////////////////////////////////////////
		{
			value = raw->valid_sound_effect;

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal_invalid_int_type (en, type);

			break;
		}
	}

	return (value);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_sound_effect_int_value_functions (void)
{
	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_MAXIMUM_VOLUME]									= get_local_int_value;

	fn_set_local_entity_raw_int_value		[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SIDE]									= set_local_int_value;
	fn_set_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SIDE]									= set_local_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SIDE][COMMS_MODEL_SERVER]		= set_server_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SIDE][COMMS_MODEL_CLIENT]		= set_client_int_value;
	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SIDE]									= get_local_int_value;

	fn_set_local_entity_raw_int_value		[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_CHANNEL]										= set_local_int_value;
	fn_set_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_CHANNEL]										= set_local_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_CHANNEL][COMMS_MODEL_SERVER]			= set_server_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_CHANNEL][COMMS_MODEL_CLIENT]			= set_client_int_value;
	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_CHANNEL]										= get_local_int_value;

	fn_set_local_entity_raw_int_value		[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_LOOPING]							= set_local_int_value;
	fn_set_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_LOOPING]							= set_local_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_LOOPING][COMMS_MODEL_SERVER]	= set_server_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_LOOPING][COMMS_MODEL_CLIENT]	= set_client_int_value;
	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_LOOPING]							= get_local_int_value;

	fn_set_local_entity_raw_int_value		[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_PANNING]							= set_local_int_value;
	fn_set_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_PANNING]							= set_local_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_PANNING][COMMS_MODEL_SERVER]	= set_server_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_PANNING][COMMS_MODEL_CLIENT]	= set_client_int_value;
	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_PANNING]							= get_local_int_value;

	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_RATE]								= get_local_int_value;

	fn_set_local_entity_raw_int_value		[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_SEQUENCE_COUNT]								= set_local_int_value;
	fn_set_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_SEQUENCE_COUNT]								= set_local_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_SEQUENCE_COUNT][COMMS_MODEL_SERVER]	= set_server_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_SEQUENCE_COUNT][COMMS_MODEL_CLIENT]	= set_client_int_value;
	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_EFFECT_SEQUENCE_COUNT]								= get_local_int_value;

	fn_set_local_entity_raw_int_value		[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_LOCALITY]									= set_local_int_value;
	fn_set_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_LOCALITY]									= set_local_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_LOCALITY][COMMS_MODEL_SERVER]			= set_server_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_LOCALITY][COMMS_MODEL_CLIENT]			= set_client_int_value;
	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_SOUND_LOCALITY]									= get_local_int_value;

	fn_set_local_entity_raw_int_value		[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_VALID_SOUND_EFFECT]								= set_local_int_value;
	fn_set_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_VALID_SOUND_EFFECT]								= set_local_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_VALID_SOUND_EFFECT][COMMS_MODEL_SERVER]	= set_server_int_value;
	fn_set_client_server_entity_int_value	[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_VALID_SOUND_EFFECT][COMMS_MODEL_CLIENT]	= set_client_int_value;
	fn_get_local_entity_int_value				[ENTITY_TYPE_SOUND_EFFECT][INT_TYPE_VALID_SOUND_EFFECT]								= get_local_int_value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
