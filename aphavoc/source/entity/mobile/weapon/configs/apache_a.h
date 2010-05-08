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

////Moje 030817 Changed "APACHE" to "AH64A" in the definitions below
////            Copied the Longbows load-out scheme and delteted those combos that included
////            the AGM114L_LONGBOW_HELLFIRE. According to the eech-manual the AH64-A only carries Laser HF

		////////////////////////////////////////////////////////////////////////////////
		//
		// ENTITY_SUB_TYPE_AIRCRAFT_AH64A_APACHE
		//
		////////////////////////////////////////////////////////////////////////////////

		#define LHS_HARDPOINT1							(AH64A_LHS_INNER_PYLON)
		#define RHS_HARDPOINT1 							(AH64A_RHS_INNER_PYLON)
		#define LHS_HARDPOINT2							(AH64A_LHS_OUTER_PYLON)
		#define RHS_HARDPOINT2							(AH64A_RHS_OUTER_PYLON)
		#define LHS_WING_TIP_MOUNT						(AH64A_LHS_WING_TIP_MOUNT)
		#define RHS_WING_TIP_MOUNT						(AH64A_RHS_WING_TIP_MOUNT)
		#define CHAIN_GUN_TURRET						(AH64A_CHAIN_GUN_TURRET)
		#define CHAFF_DISPENSER							(AH64A_CHAFF_DISPENSER)
		#define FLARE_DISPENSER							(AH64A_FLARE_DISPENSER)

		#define CHAIN_GUN_BARREL						(0)
		#define STINGER_TUBES							(0)
		#define HELLFIRE_RACK							(0)
		#define HYDRA_POD		  							(1)
		#define CHAFF_VECTOR								(0)
		#define FLARE_VECTOR								(0)

		#define NUM_CHAIN_GUN_ROUNDS					(1200)
		#define NUM_STINGER_MISSILES					(2)
		#define NUM_HELLFIRE_MISSILES					(4)
		#define NUM_HYDRA_ROCKETS						(19)
		#define NUM_CHAFFS								(30)
		#define NUM_FLARES								(30)

		#define CANNON_TURRET_HEADING_RATE			(rad (90.0))
		#define CANNON_TURRET_MIN_HEADING_LIMIT	(rad (-86.0))
		#define CANNON_TURRET_MAX_HEADING_LIMIT	(rad (86.0))
		#define CANNON_BARREL_PITCH_RATE				(rad (90.0))
		#define CANNON_BARREL_MIN_PITCH_LIMIT		(rad (-60.0))
		#define CANNON_BARREL_MAX_PITCH_LIMIT		(rad (11.0))

		#define HYDRA_POD_PITCH_RATE					(rad (20.0))
		#define HYDRA_POD_MIN_PITCH_LIMIT			(rad (-15.0))
		#define HYDRA_POD_MAX_PITCH_LIMIT			(rad (4.9))

		#define HYDRA_POD_ROTATE_INHIBIT_VELOCITY	(knots_to_metres_per_second (100.0))

		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_1
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 5
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_2
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_3
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_4
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_5
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_6
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_7
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_8
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_9
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},

		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_10
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_11
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_12
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_13
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_14
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_15
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_16
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_17
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 7
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},

		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_18
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_19
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_20
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},

		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_21
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},

		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_22
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_23
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_24
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT2,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_25
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},

		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_26
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_27
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_28
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_29
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 9
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},

		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_30
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				LHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_AGM114K_HELLFIRE_II,			// sub_type
				NUM_HELLFIRE_MISSILES,										// number
				RHS_HARDPOINT1,												// heading_depth
				HELLFIRE_RACK,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_31
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M255,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},
		////////////////////////////////////////
		//
		// WEAPON_CONFIG_TYPE_AH64A_APACHE_32
		//
		////////////////////////////////////////
		{
			// WEAPON PACKAGE 1
			{
				ENTITY_SUB_TYPE_WEAPON_CHAFF,								// sub_type
				NUM_CHAFFS,														// number
				CHAFF_DISPENSER,												// heading_depth
				CHAFF_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 2
			{
				ENTITY_SUB_TYPE_WEAPON_FLARE,								// sub_type
				NUM_FLARES,														// number
				FLARE_DISPENSER,												// heading_depth
				FLARE_VECTOR,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 3
			{
				ENTITY_SUB_TYPE_WEAPON_M230_30MM_ROUND,				// sub_type
				NUM_CHAIN_GUN_ROUNDS,										// number
				CHAIN_GUN_TURRET,												// heading_depth
				CHAIN_GUN_BARREL,												// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				1,																	// salvo_size
				CANNON_TURRET_HEADING_RATE,								// heading_rate
				CANNON_TURRET_MIN_HEADING_LIMIT,							// min_heading_limit
				CANNON_TURRET_MAX_HEADING_LIMIT,							// max_heading_limit
				CANNON_BARREL_PITCH_RATE,									// pitch_rate
				CANNON_BARREL_MIN_PITCH_LIMIT,							// min_pitch_limit
				CANNON_BARREL_MAX_PITCH_LIMIT,							// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_MEDIUM_CALIBRE_FLARED,						// muzzle_flash_type
			},
			// WEAPON PACKAGE 4
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				LHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 5
			{
				ENTITY_SUB_TYPE_WEAPON_AIM92_STINGER,					// sub_type
				NUM_STINGER_MISSILES,										// number
				RHS_WING_TIP_MOUNT,											// heading_depth
				STINGER_TUBES,													// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				FALSE,															// rotate
				1,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				rad (0.0),														// pitch_rate
				rad (0.0),														// min_pitch_limit
				rad (0.0),														// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				knots_to_metres_per_second (10000.0),					// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 6
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 7
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT1,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 8
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				LHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 9
			{
				ENTITY_SUB_TYPE_WEAPON_HYDRA70_M261,					// sub_type
				NUM_HYDRA_ROCKETS,											// number
				RHS_HARDPOINT2,												// heading_depth
				HYDRA_POD,														// pitch_depth
				0,																	// muzzle_depth
				FALSE,															// make_weapon_system_ready
				TRUE,																// rotate
				2,																	// salvo_size
				rad (0.0),														// heading_rate
				rad (0.0),														// min_heading_limit
				rad (0.0),														// max_heading_limit
				HYDRA_POD_PITCH_RATE,										// pitch_rate
				HYDRA_POD_MIN_PITCH_LIMIT,									// min_pitch_limit
				HYDRA_POD_MAX_PITCH_LIMIT,									// max_pitch_limit
				rad (0.0),														// muzzle_rotate_rate
				HYDRA_POD_ROTATE_INHIBIT_VELOCITY,						// rotate_inhibit_velocity
				0,																	// heading_share_mask
				0,																	// pitch_share_mask
				MUZZLE_FLASH_INVALID,										// muzzle_flash_type
			},
			// WEAPON PACKAGE 10
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 11
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 12
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 13
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 14
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 15
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 16
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 17
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 18
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 19
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 20
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 21
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 22
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 23
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 24
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 25
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 26
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 27
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 28
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 29
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 30
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 31
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
			// WEAPON PACKAGE 32
			{ENTITY_SUB_TYPE_WEAPON_NO_WEAPON},
		},

		#undef LHS_HARDPOINT1
		#undef RHS_HARDPOINT1
		#undef LHS_HARDPOINT2
		#undef RHS_HARDPOINT2
		#undef LHS_WING_TIP_MOUNT
		#undef RHS_WING_TIP_MOUNT
		#undef CHAIN_GUN_TURRET
		#undef CHAFF_DISPENSER
		#undef FLARE_DISPENSER

		#undef CHAIN_GUN_BARREL
		#undef STINGER_TUBES
		#undef HELLFIRE_RACK
		#undef HYDRA_POD
		#undef CHAFF_VECTOR
		#undef FLARE_VECTOR

		#undef NUM_CHAIN_GUN_ROUNDS
		#undef NUM_STINGER_MISSILES
		#undef NUM_HELLFIRE_MISSILES
		#undef NUM_HYDRA_ROCKETS
		#undef NUM_CHAFFS
		#undef NUM_FLARES

		#undef CANNON_TURRET_HEADING_RATE
		#undef CANNON_TURRET_MIN_HEADING_LIMIT
		#undef CANNON_TURRET_MAX_HEADING_LIMIT
		#undef CANNON_BARREL_PITCH_RATE
		#undef CANNON_BARREL_MIN_PITCH_LIMIT
		#undef CANNON_BARREL_MAX_PITCH_LIMIT

		#undef HYDRA_POD_PITCH_RATE
		#undef HYDRA_POD_MIN_PITCH_LIMIT
		#undef HYDRA_POD_MAX_PITCH_LIMIT

		#undef HYDRA_POD_ROTATE_INHIBIT_VELOCITY
