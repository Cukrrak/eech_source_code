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

eo_params
	hokum_flir,
	hokum_llltv,
	hokum_periscope;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_hokum_eo (void)
{
	eo_sensor									= TARGET_ACQUISITION_SYSTEM_FLIR;

	eo_azimuth									= rad (0.0);
	eo_min_azimuth								= rad (-110.0);
	eo_max_azimuth								= rad (110.0);
	eo_elevation								= rad (0.0);
	eo_min_elevation							= rad (-30.0);
	eo_max_elevation							= rad (10.0);
	eo_max_visual_range						= 5000.0;

	hokum_flir.field_of_view				= EO_FOV_WIDE;
	hokum_flir.min_field_of_view			= EO_FOV_NARROW;
	hokum_flir.max_field_of_view			= EO_FOV_WIDE;

	hokum_llltv.field_of_view				= EO_FOV_NARROW;
	hokum_llltv.min_field_of_view			= EO_FOV_NARROW;
	hokum_llltv.max_field_of_view			= EO_FOV_NARROW;

   hokum_periscope.field_of_view       = EO_FOV_WIDE;
	hokum_periscope.min_field_of_view	= EO_FOV_NARROW;
   hokum_periscope.max_field_of_view   = EO_FOV_WIDE;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_hokum_eo (void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_hokum_eo_centred_viewpoint (viewpoint *vp)
{
	entity
		*source;

	object_3d_instance
		*inst3d;

	object_3d_sub_object_search_data
		search;

	ASSERT (vp);

	source = get_gunship_entity ();

	inst3d = get_local_entity_ptr_value (source, PTR_TYPE_INSTANCE_3D_OBJECT);

	ASSERT (inst3d);

	get_local_entity_vec3d (source, VEC3D_TYPE_POSITION, &inst3d->vp.position);

	get_local_entity_attitude_matrix (source, &inst3d->vp.attitude);

	if (eo_sensor != TARGET_ACQUISITION_SYSTEM_PERISCOPE)
	{
		search.search_depth = 0;
		search.search_object = inst3d;
		search.sub_object_index = OBJECT_3D_SUB_OBJECT_KA52_SAMSHIT_VIEWPOINT;

		if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
		{
			get_3d_sub_object_world_viewpoint (search.result_sub_object, vp);
		}
		else
		{
			//
			// can happpen if the object is being destroyed
			//

			memcpy (&vp->position, &inst3d->vp.position, sizeof (vec3d));

			debug_log ("OBJECT_3D_SUB_OBJECT_KA52_SAMSHIT_VIEWPOINT missing from Hokum");
		}
	}
	else
	{
		search.search_depth = 0;
		search.search_object = inst3d;
		search.sub_object_index = OBJECT_3D_SUB_OBJECT_KA52_WSO_SCOPE_HEADING;

		if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
		{
			get_3d_sub_object_world_viewpoint (search.result_sub_object, vp);
		}
		else
		{
			//
			// can happpen if the object is being destroyed
			//

			memcpy (&vp->position, &inst3d->vp.position, sizeof (vec3d));

			debug_log ("OBJECT_3D_SUB_OBJECT_KA52_WSO_SCOPE_HEADING missing from Hokum");
		}
	}

	memcpy (&vp->attitude, &inst3d->vp.attitude, sizeof (matrix3x3));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_hokum_eo_relative_centred_viewpoint (viewpoint *vp)
{
	entity
		*source;

	object_3d_instance
		*inst3d;

	object_3d_sub_object_search_data
		search;

	ASSERT (vp);

	source = get_gunship_entity ();

	inst3d = get_local_entity_ptr_value (source, PTR_TYPE_INSTANCE_3D_OBJECT);

	ASSERT (inst3d);

	inst3d->vp.x = 0.0;
	inst3d->vp.y = 0.0;
	inst3d->vp.z = 0.0;

	get_local_entity_attitude_matrix (source, &inst3d->vp.attitude);

	if (eo_sensor != TARGET_ACQUISITION_SYSTEM_PERISCOPE)
	{
		search.search_depth = 0;
		search.search_object = inst3d;
		search.sub_object_index = OBJECT_3D_SUB_OBJECT_KA52_SAMSHIT_VIEWPOINT;

		if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
		{
			get_3d_sub_object_world_viewpoint (search.result_sub_object, vp);
		}
		else
		{
			//
			// can happpen if the object is being destroyed
			//

			memcpy (&vp->position, &inst3d->vp.position, sizeof (vec3d));

			debug_log ("OBJECT_3D_SUB_OBJECT_KA52_SAMSHIT_VIEWPOINT missing from Hokum");
		}
	}
	else
	{
		search.search_depth = 0;
		search.search_object = inst3d;
		search.sub_object_index = OBJECT_3D_SUB_OBJECT_KA52_WSO_SCOPE_HEADING;

		if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
		{
			get_3d_sub_object_world_viewpoint (search.result_sub_object, vp);
		}
		else
		{
			//
			// can happpen if the object is being destroyed
			//

			memcpy (&vp->position, &inst3d->vp.position, sizeof (vec3d));

			debug_log ("OBJECT_3D_SUB_OBJECT_KA52_WSO_SCOPE_HEADING missing from Hokum");
		}
	}

	memcpy (&vp->attitude, &inst3d->vp.attitude, sizeof (matrix3x3));

	//
	// fix up the instance position (just in case)
	//

	get_local_entity_vec3d (source, VEC3D_TYPE_POSITION, &inst3d->vp.position);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void inc_eo_field_of_view (eo_params *eo)
{
	ASSERT (eo);

	if (eo->field_of_view < eo->max_field_of_view)
	{
		eo->field_of_view++;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void fast_inc_eo_field_of_view (eo_params *eo)
{
	ASSERT (eo);

	eo->field_of_view = eo->max_field_of_view;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void dec_eo_field_of_view (eo_params *eo)
{
	ASSERT (eo);

	if (eo->field_of_view > eo->min_field_of_view)
	{
		eo->field_of_view--;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void fast_dec_eo_field_of_view (eo_params *eo)
{
	ASSERT (eo);

	eo->field_of_view = eo->min_field_of_view;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_hokum_eo (eo_params *eo)
{
	float
		fine_slew_rate,
		medium_slew_rate,
		coarse_slew_rate;

	ASSERT (eo);

	////////////////////////////////////////
	//
	// field of view
	//
	////////////////////////////////////////

	while (single_target_acquisition_system_inc_range_key)
	{
		dec_eo_field_of_view (eo);

		single_target_acquisition_system_inc_range_key--;
	}

	while (single_target_acquisition_system_inc_range_fast_key)
	{
		fast_dec_eo_field_of_view (eo);

		single_target_acquisition_system_inc_range_fast_key--;
	}

	////////////////////////////////////////

	while (single_target_acquisition_system_dec_range_key)
	{
		inc_eo_field_of_view (eo);

		single_target_acquisition_system_dec_range_key--;
	}

	while (single_target_acquisition_system_dec_range_fast_key)
	{
		fast_inc_eo_field_of_view (eo);

		single_target_acquisition_system_dec_range_fast_key--;
	}

	////////////////////////////////////////
	//
	// slew optics
	//
	////////////////////////////////////////

	switch (eo->field_of_view)
	{
		////////////////////////////////////////
		case EO_FOV_NARROW:
		////////////////////////////////////////
		{
			fine_slew_rate = rad (0.05) * get_delta_time ();

			medium_slew_rate = rad (0.25) * get_delta_time ();

			coarse_slew_rate = rad (1.0) * get_delta_time ();

			break;
		}
		////////////////////////////////////////
		case EO_FOV_MEDIUM:
		////////////////////////////////////////
		{
			fine_slew_rate = rad (0.5) * get_delta_time ();

			medium_slew_rate = rad (2.5) * get_delta_time ();

			coarse_slew_rate = rad (10.0) * get_delta_time ();

			break;
		}
		////////////////////////////////////////
		case EO_FOV_WIDE:
		////////////////////////////////////////
		{
			fine_slew_rate = rad (4.0) * get_delta_time ();

			medium_slew_rate = rad (20.0) * get_delta_time ();

			coarse_slew_rate = rad (80.0) * get_delta_time ();

			break;
		}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid field of view = %d", eo->field_of_view);

			break;
		}
	}

	////////////////////////////////////////

	if (continuous_target_acquisition_system_steer_left_fast_key)
	{
		eo_azimuth -= coarse_slew_rate;

		eo_azimuth = max (eo_azimuth, eo_min_azimuth);
	}
	else if (continuous_target_acquisition_system_steer_left_fine_key)
	{
		eo_azimuth -= fine_slew_rate;

		eo_azimuth = max (eo_azimuth, eo_min_azimuth);
	}
	else if (continuous_target_acquisition_system_steer_left_key)
	{
		eo_azimuth -= medium_slew_rate;

		eo_azimuth = max (eo_azimuth, eo_min_azimuth);
	}

	////////////////////////////////////////

	if (continuous_target_acquisition_system_steer_right_fast_key)
	{
		eo_azimuth += coarse_slew_rate;

		eo_azimuth = min (eo_azimuth, eo_max_azimuth);
	}
	else if (continuous_target_acquisition_system_steer_right_fine_key)
	{
		eo_azimuth += fine_slew_rate;

		eo_azimuth = min (eo_azimuth, eo_max_azimuth);
	}
	else if (continuous_target_acquisition_system_steer_right_key)
	{
		eo_azimuth += medium_slew_rate;

		eo_azimuth = min (eo_azimuth, eo_max_azimuth);
	}

	////////////////////////////////////////

	if (continuous_target_acquisition_system_steer_up_fast_key)
	{
		eo_elevation += coarse_slew_rate;

		eo_elevation = min (eo_elevation, eo_max_elevation);
	}
	else if (continuous_target_acquisition_system_steer_up_fine_key)
	{
		eo_elevation += fine_slew_rate;

		eo_elevation = min (eo_elevation, eo_max_elevation);
	}
	else if (continuous_target_acquisition_system_steer_up_key)
	{
		eo_elevation += medium_slew_rate;

		eo_elevation = min (eo_elevation, eo_max_elevation);
	}

	////////////////////////////////////////

	if (continuous_target_acquisition_system_steer_down_fast_key)
	{
		eo_elevation -= coarse_slew_rate;

		eo_elevation = max (eo_elevation, eo_min_elevation);
	}
	else if (continuous_target_acquisition_system_steer_down_fine_key)
	{
		eo_elevation -= fine_slew_rate;

		eo_elevation = max (eo_elevation, eo_min_elevation);
	}
	else if (continuous_target_acquisition_system_steer_down_key)
	{
		eo_elevation -= medium_slew_rate;

		eo_elevation = max (eo_elevation, eo_min_elevation);
	}

	////////////////////////////////////////

	while (single_target_acquisition_system_select_next_target_key)
	{
		select_next_eo_target ();

		single_target_acquisition_system_select_next_target_key--;
	}

	////////////////////////////////////////

	while (single_target_acquisition_system_select_previous_target_key)
	{
		select_previous_eo_target ();

		single_target_acquisition_system_select_previous_target_key--;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void centre_hokum_eo (void)
{
	eo_azimuth = rad (0.0);

	eo_elevation = rad (0.0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void animate_hokum_eo (object_3d_instance *inst3d)
{
	object_3d_sub_object_search_data
		search_heading,
		search_pitch;

	ASSERT (inst3d);

	//
	// Samshit-E
	//

	search_heading.search_depth = 0;
	search_heading.search_object = inst3d;
	search_heading.sub_object_index = OBJECT_3D_SUB_OBJECT_KA52_SAMSHIT_HEADING;

	if (find_object_3d_sub_object (&search_heading) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search_heading.result_sub_object->relative_heading = eo_azimuth;

		search_pitch.search_depth = 0;
		search_pitch.sub_object_index = OBJECT_3D_SUB_OBJECT_KA52_SAMSHIT_PITCH;

		if (find_object_3d_sub_object_from_sub_object (&search_heading, &search_pitch) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
		{
			search_pitch.result_sub_object->relative_pitch = -eo_elevation;
		}
	}

	//
	// Shkval-V
	//

	search_heading.search_depth = 0;
	search_heading.search_object = inst3d;
	search_heading.sub_object_index = OBJECT_3D_SUB_OBJECT_KA52_FLIR_HEADING;

	if (find_object_3d_sub_object (&search_heading) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search_heading.result_sub_object->relative_heading = eo_azimuth;
	}

	//
	// periscope
	//

	search_heading.search_depth = 0;
	search_heading.search_object = inst3d;
	search_heading.sub_object_index = OBJECT_3D_SUB_OBJECT_KA52_WSO_SCOPE_HEADING;

	if (find_object_3d_sub_object (&search_heading) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search_heading.result_sub_object->relative_heading = eo_azimuth;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void animate_hokum_virtual_cockpit_eo (object_3d_instance *inst3d)
{
	object_3d_sub_object_search_data
		search_heading,
		search_pitch;

	ASSERT (inst3d);

	//
	// Samshit-E
	//

	search_heading.search_depth = 0;
	search_heading.search_object = inst3d;
	search_heading.sub_object_index = OBJECT_3D_SUB_OBJECT_HOKUM_COCKPIT_SAMSHIT_HEADING;

	if (find_object_3d_sub_object (&search_heading) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search_heading.result_sub_object->relative_heading = eo_azimuth;

		search_pitch.search_depth = 0;
		search_pitch.sub_object_index = OBJECT_3D_SUB_OBJECT_HOKUM_COCKPIT_SAMSHIT_PITCH;

		if (find_object_3d_sub_object_from_sub_object (&search_heading, &search_pitch) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
		{
			search_pitch.result_sub_object->relative_pitch = -eo_elevation;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void slave_hokum_eo_to_current_target (void)
{
	if (eo_on_target)
	{
		switch (eo_sensor)
		{
			case TARGET_ACQUISITION_SYSTEM_FLIR:
			{
				hokum_flir.field_of_view = hokum_flir.min_field_of_view;

				break;
			}
			case TARGET_ACQUISITION_SYSTEM_LLLTV:
			{
				hokum_llltv.field_of_view = hokum_llltv.min_field_of_view;

				break;
			}
			case TARGET_ACQUISITION_SYSTEM_PERISCOPE:
			{
				hokum_periscope.field_of_view = hokum_periscope.min_field_of_view;

				break;
			}
		}
	}
	else
	{
		switch (eo_sensor)
		{
			case TARGET_ACQUISITION_SYSTEM_FLIR:
			{
				hokum_flir.field_of_view = hokum_flir.max_field_of_view;

				break;
			}
			case TARGET_ACQUISITION_SYSTEM_LLLTV:
			{
				hokum_llltv.field_of_view = hokum_llltv.max_field_of_view;

				break;
			}
			case TARGET_ACQUISITION_SYSTEM_PERISCOPE:
			{
				hokum_periscope.field_of_view = hokum_periscope.max_field_of_view;

				break;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
