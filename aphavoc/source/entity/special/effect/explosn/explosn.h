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

#define EXPLOSIVE_QUALITY_NONE		0
#define EXPLOSIVE_QUALITY_DUST		1
#define EXPLOSIVE_QUALITY_EXPLOSIVE	2
#define EXPLOSIVE_QUALITY_FLAMMABLE	4

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum
{
	EXPLOSIVE_POWER_NONE,
	EXPLOSIVE_POWER_LOW,
	EXPLOSIVE_POWER_MEDIUM,
	EXPLOSIVE_POWER_HIGH
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct EXPLOSION
{
	effect
		eff;

	object_3d_index_numbers
		object_3d_shape;

	float
		animation_frequency,				// how long the animation lasts ( from start to end keyframes )
		explosion_state,					// current keyframes ( 0.0 .. 1.0 )
		scale;

	unsigned char
		colour_red,
		colour_green,
		colour_blue,
		colour_alpha;

	list_link
		sector_link;
};

typedef struct EXPLOSION explosion;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "xp_creat.h"

#include "xp_dbase.h"

#include "xp_draw.h"

#include "xp_dstry.h"

#include "xp_float.h"

#include "xp_funcs.h"

#include "xp_int.h"

#include "xp_list.h"

#include "xp_msgs.h"

#include "xp_pack.h"

#include "xp_updt.h"

#include "xp_wpn.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern int create_meta_explosion( meta_explosion_types type, vec3d *position, entity *parent, int *entity_index_list );

extern int count_entities_in_meta_explosion( meta_explosion_types type );

extern void create_client_server_weapon_killed_explosion_effect (entity *en);

extern void create_client_server_object_killed_explosion_effect (entity *en);

extern void create_client_server_object_hit_ground_explosion_effect (entity *en, terrain_types terrain_type);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
