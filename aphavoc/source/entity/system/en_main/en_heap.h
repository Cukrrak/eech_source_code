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

extern int
	number_of_entities;

extern entity
	*entities,
	*first_free_entity,
	*first_used_entity;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ENTITY_INDEX_DONT_CARE 		(-1)

#define MAX_NUM_ENTITIES				(131072 * 4)

//
// index is signed therefore 1 extra bit required
//

#define NUM_ENTITY_INDEX_PACK_BITS	(20)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define get_local_entity_list() (first_used_entity)

////////////////////////////////////////
//
// THESE FUNCTIONS ARE NOT PROTECTED AGAINST (EN) == NULL
//
////////////////////////////////////////

#define get_local_entity_index(EN) ((EN) - entities)

#define get_local_entity_ptr(INDEX) (&entities[(INDEX)])

#define get_client_server_entity_random_number_seed(EN) ((EN) - entities)

////////////////////////////////////////
//
// THESE FUNCTIONS ARE PROTECTED AGAINST (EN) == NULL
//
////////////////////////////////////////

#define get_local_entity_safe_index(EN) ((EN) ? ((EN) - entities) : (ENTITY_INDEX_DONT_CARE))

//
// WARNING! If (INDEX) is a function it will get called twice which may cause problems.
//

#define get_local_entity_safe_ptr(INDEX) ((INDEX != ENTITY_INDEX_DONT_CARE) ? (&entities[(INDEX)]) : (NULL))

//
// use this function to get the index number of the next available entity
//

#define get_next_free_entity_index() (get_local_entity_safe_index (first_free_entity))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void initialise_entity_heap (int num_entities);

extern void reinitialise_entity_heap (void);

extern void deinitialise_entity_heap (void);

extern entity *get_free_entity (int index);

extern void set_free_entity (entity *en);

extern void pack_entity_safe_index (int index);

extern int unpack_entity_safe_index (void);

extern void pack_entity_safe_ptr (entity *en);

extern entity *unpack_entity_safe_ptr (void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
