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

struct VEHICLE_DATA
{
	const char
		*full_name,
		*long_display_name,
		*short_display_name,
		*easy_display_name;

	object_3d_index_numbers
		default_3d_shape;

	entity_forces
		force;

	weapon_config_types
		default_weapon_config_type,
		min_weapon_config_type,
		max_weapon_config_type;

	entity_sub_types
		default_weapon_type;

	target_types
		target_type;

	target_symbol_types
		target_symbol_type;

	target_priority_types
		target_priority_type;

	force_info_catagories
		force_info_catagory;

	threat_types
		threat_type;

	view_categories
		view_category;

	view_types
		view_type;

	int
		map_icon;

	int
		carries_smoke_grenades;

	float
		chase_view_min_distance,
		chase_view_max_distance,
		chase_view_min_distance_test,
		chase_view_max_distance_test,
		cruise_velocity,
		axle_length,
		max_acceleration,
		max_turn_rate,
		g_max,
		power_output,
		recon_radius,
		target_scan_delay,
		air_scan_floor,
		air_scan_ceiling,
		air_scan_range,
		surface_scan_range,
		potential_surface_to_air_threat,
		potential_surface_to_surface_threat,
		ammo_economy,
		fuel_economy,
		armour_front,
		armour_side,
		armour_rear;

	int
		initial_damage_level,
		armor_level;

	unsigned int
		explosive_quality 	: NUM_EXPLOSIVE_QUALITY_BITS,
		explosive_power 		: NUM_EXPLOSIVE_POWER_BITS,
		offensive_capability	: 1,
		points_value			: 12;

	sound_sample_indices
		idle_sound_effect,
		moving_sound_effect;
};

typedef struct VEHICLE_DATA vehicle_data;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//VJ WUT mod bug, date: 26-mar-03
//remove "const" from definition
extern vehicle_data
	vehicle_database[NUM_ENTITY_SUB_TYPE_VEHICLES];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
