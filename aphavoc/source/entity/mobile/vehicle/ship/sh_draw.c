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

static void draw_local_3d_object (entity *en, float range)
{
	ship_vehicle
		*raw;

#ifndef OGRE_EE
	day_segment_types
		day_segment_type;
#endif

	raw = (ship_vehicle *) get_local_entity_data (en);

	//
	// update viewpoint
	//

	memcpy (&raw->vh.inst3d->vp.position, &raw->vh.mob.position, sizeof (vec3d));

	memcpy (&raw->vh.inst3d->vp.attitude, &raw->vh.mob.attitude, sizeof (matrix3x3));

	//
	// animate
	//

	animate_ship_rotors (en);

	animate_vehicle_loading_doors (en);

	animate_vehicle_radar (en);

	animate_vehicle_weapon_system_ready (en);

#ifndef OGRE_EE
	day_segment_type = (day_segment_types) get_local_entity_int_value (get_session_entity (), INT_TYPE_DAY_SEGMENT_TYPE);

	//
	// draw
	//

	raw->vh.inst3d->object_has_shadow = FALSE;

	if (active_3d_environment->render_filter == RENDER_INFRARED)
	{
		raw->vh.inst3d->object_diffuse_value = 80;
		raw->vh.inst3d->object_internal_lighting = raw->vh.inst3d->object_sprite_lights = FALSE;
	}
	else if (active_3d_environment->render_filter == RENDER_MONOCHROME)
	{
		raw->vh.inst3d->object_diffuse_value = 0; //32 * (1 - min(get_local_entity_float_value (en, FLOAT_TYPE_DEATH_TIMER), 1.5 * ONE_MINUTE) / (2 * ONE_MINUTE));
		raw->vh.inst3d->object_internal_lighting = raw->vh.inst3d->object_sprite_lights = FALSE;
	}
	else
	{
		animate_and_draw_entity_muzzle_flash_effect (en);

		raw->vh.inst3d->object_diffuse_value = 255;
		raw->vh.inst3d->object_internal_lighting = ((day_segment_type == DAY_SEGMENT_TYPE_NIGHT) || (day_segment_type == DAY_SEGMENT_TYPE_DUSK));
		raw->vh.inst3d->object_sprite_lights = raw->vh.inst3d->object_internal_lighting;
	}

	insert_object_into_3d_scene (OBJECT_3D_DRAW_TYPE_OBJECT, raw->vh.inst3d);
#else
	animate_and_draw_entity_muzzle_flash_effect (en);
	object_3d_draw (raw->vh.inst3d);
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_ship_vehicle_draw_functions (void)
{
	fn_draw_local_entity_3d_object[ENTITY_TYPE_SHIP_VEHICLE]	= draw_local_3d_object;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
