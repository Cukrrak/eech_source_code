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

union HAVOC_DAMAGE_FLAGS
{
	unsigned int
		flags;

	struct
	{
		unsigned int
			radar		  					:1,	// 1
			flir							:1,	// 2
			spare_1						:1,	// 3
			llltv					  		:1,	// 4
			laser_range_finder  		:1,	// 5
			spare_2						:1,	// 6
			radar_jammer				:1,	// 7
			infra_red_jammer	  		:1,	// 8
			spare_3						:1,	// 9
			navigation_computer 		:1,	// 10
			spare_4						:1,	// 11
			communications		  		:1,	// 12
			spare_5						:1,	// 13
			radar_warning_system		:1,	// 14
			spare_6						:1,	// 15
			head_up_display	  		:1,	// 16
			spare_7						:1,	// 17
			helmet_mounted_sight		:1,	// 18
			tv_display			  		:1,	// 19
			spare_8						:1,	// 20
			threat_warning_display	:1,	// 21
			night_vision_goggles		:1,	// 22
			gun_jammed					:1,	// 23
			lh_outer_pylon				:1,	// 24
			spare_9						:1,	// 25
			lh_inner_pylon				:1,	// 26
			rh_outer_pylon				:1,	// 27
			spare_10						:1,	// 28
			rh_inner_pylon				:1,	// 29
			chaff_dispenser			:1,	// 30
			spare_11						:1,	// 31
			flare_dispenser			:1;	// 32
	};
};

typedef union HAVOC_DAMAGE_FLAGS havoc_damage_flags;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern havoc_damage_flags
	havoc_damage;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void set_havoc_weapon_damage_status (void);

extern void fully_repair_havoc_damage (void);

extern void partially_repair_havoc_damage (void);

extern void repair_havoc_weapon_damage (void);

extern void damage_havoc (gunship_damage_levels damage_level);

extern void notify_havoc_avionics_of_dynamics_fault (unsigned int damage);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
