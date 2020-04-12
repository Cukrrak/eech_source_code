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

#define DEBUG_MODULE_FINE_DISPLAY_CAMERA_POSITION_ADJUSTMENT	0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static object_3d_instance
	*virtual_cockpit_inst3d_detail_level_normal_inst3d,
	*virtual_cockpit_inst3d_detail_level_glass_inst3d;
//	*virtual_cockpit_inst3d;

static object_3d_sub_instance
	// Master Warning Panel
	*eng1_out_lamp,
	*eng2_out_lamp,
	*low_rtr_rpm_lamp,
	*fire_lamp,
	*master_caution_lamp,
	// Pilot Display Unit
	// Rotor RPM
	// Red LEDs
	*rtr_rpm_red_led1,
	*rtr_rpm_red_led2,
	*rtr_rpm_red_led3,
	*rtr_rpm_red_led4,
	*rtr_rpm_red_led5,
	*rtr_rpm_red_led6,
	*rtr_rpm_red_led7,
	*rtr_rpm_red_led8,
	*rtr_rpm_red_led9,
	*rtr_rpm_red_led10,
	*rtr_rpm_red_led11,
	*rtr_rpm_red_led12,
	*rtr_rpm_red_led13,
	*rtr_rpm_red_led14,
	*rtr_rpm_red_led15,
	*rtr_rpm_red_led16,
	*rtr_rpm_red_led17,
	*rtr_rpm_red_led18,
	*rtr_rpm_red_led19,
	*rtr_rpm_red_led20,
	*rtr_rpm_red_led21,
	*rtr_rpm_red_led22,
	*rtr_rpm_red_led23,
	*rtr_rpm_red_led24,
	*rtr_rpm_red_led25,
	*rtr_rpm_red_led26,
	*rtr_rpm_red_led27,
	// Yellow LEDs
	*rtr_rpm_yellow_led1,
	*rtr_rpm_yellow_led2,
	*rtr_rpm_yellow_led3,
	*rtr_rpm_yellow_led4,
	*rtr_rpm_yellow_led5,
	*rtr_rpm_yellow_led6,
	*rtr_rpm_yellow_led7,
	*rtr_rpm_yellow_led8,
	*rtr_rpm_yellow_led9,
	// Green LEDs
	*rtr_rpm_green_led1,
	*rtr_rpm_green_led2,
	*rtr_rpm_green_led3,
	*rtr_rpm_green_led4,
	*rtr_rpm_green_led5,

	//L Eng RPM
	// Red LEDs
	*leng_rpm_red_led1,
	*leng_rpm_red_led2,
	*leng_rpm_red_led3,
	*leng_rpm_red_led4,
	*leng_rpm_red_led5,
	*leng_rpm_red_led6,
	*leng_rpm_red_led7,
	*leng_rpm_red_led8,
	*leng_rpm_red_led9,
	*leng_rpm_red_led10,
	*leng_rpm_red_led11,
	*leng_rpm_red_led12,
	*leng_rpm_red_led13,
	*leng_rpm_red_led14,
	*leng_rpm_red_led15,
	*leng_rpm_red_led16,
	*leng_rpm_red_led17,
	*leng_rpm_red_led18,
	*leng_rpm_red_led19,
	*leng_rpm_red_led20,
	*leng_rpm_red_led21,
	*leng_rpm_red_led22,
	*leng_rpm_red_led23,
	*leng_rpm_red_led24,
	*leng_rpm_red_led25,
	*leng_rpm_red_led26,
	*leng_rpm_red_led27,
	// Yellow LEDs
	*leng_rpm_yellow_led1,
	*leng_rpm_yellow_led2,
	*leng_rpm_yellow_led3,
	*leng_rpm_yellow_led4,
	*leng_rpm_yellow_led5,
	*leng_rpm_yellow_led6,
	*leng_rpm_yellow_led7,
	*leng_rpm_yellow_led8,
	*leng_rpm_yellow_led9,
	// Green LEDs
	*leng_rpm_green_led1,
	*leng_rpm_green_led2,
	*leng_rpm_green_led3,
	*leng_rpm_green_led4,
	*leng_rpm_green_led5,

	// R Eng RPM
	// Red LEDs
	*reng_rpm_red_led1,
	*reng_rpm_red_led2,
	*reng_rpm_red_led3,
	*reng_rpm_red_led4,
	*reng_rpm_red_led5,
	*reng_rpm_red_led6,
	*reng_rpm_red_led7,
	*reng_rpm_red_led8,
	*reng_rpm_red_led9,
	*reng_rpm_red_led10,
	*reng_rpm_red_led11,
	*reng_rpm_red_led12,
	*reng_rpm_red_led13,
	*reng_rpm_red_led14,
	*reng_rpm_red_led15,
	*reng_rpm_red_led16,
	*reng_rpm_red_led17,
	*reng_rpm_red_led18,
	*reng_rpm_red_led19,
	*reng_rpm_red_led20,
	*reng_rpm_red_led21,
	*reng_rpm_red_led22,
	*reng_rpm_red_led23,
	*reng_rpm_red_led24,
	*reng_rpm_red_led25,
	*reng_rpm_red_led26,
	*reng_rpm_red_led27,
	// Yellow LEDs
	*reng_rpm_yellow_led1,
	*reng_rpm_yellow_led2,
	*reng_rpm_yellow_led3,
	*reng_rpm_yellow_led4,
	*reng_rpm_yellow_led5,
	*reng_rpm_yellow_led6,
	*reng_rpm_yellow_led7,
	*reng_rpm_yellow_led8,
	*reng_rpm_yellow_led9,
	// Green LEDs
	*reng_rpm_green_led1,
	*reng_rpm_green_led2,
	*reng_rpm_green_led3,
	*reng_rpm_green_led4,
	*reng_rpm_green_led5,

	// L Eng TRQ
	// Green LEDs
	*leng_trq_green_led1,
	*leng_trq_green_led2,
	*leng_trq_green_led3,
	*leng_trq_green_led4,
	*leng_trq_green_led5,
	*leng_trq_green_led6,
	*leng_trq_green_led7,
	*leng_trq_green_led8,
	*leng_trq_green_led9,
	*leng_trq_green_led10,
	*leng_trq_green_led11,
	*leng_trq_green_led12,
	*leng_trq_green_led13,
	*leng_trq_green_led14,
	*leng_trq_green_led15,
	*leng_trq_green_led16,
	*leng_trq_green_led17,
	*leng_trq_green_led18,
	*leng_trq_green_led19,
	*leng_trq_green_led20,
	// Yellow LEDs
	*leng_trq_yellow_led1,
	*leng_trq_yellow_led2,
	*leng_trq_yellow_led3,
	*leng_trq_yellow_led4,
	*leng_trq_yellow_led5,
	*leng_trq_yellow_led6,
	// Red LEDs
	*leng_trq_red_led1,
	*leng_trq_red_led2,
	*leng_trq_red_led3,
	*leng_trq_red_led4,

	// R Eng TRQ
	// Green LEDs
	*reng_trq_green_led1,
	*reng_trq_green_led2,
	*reng_trq_green_led3,
	*reng_trq_green_led4,
	*reng_trq_green_led5,
	*reng_trq_green_led6,
	*reng_trq_green_led7,
	*reng_trq_green_led8,
	*reng_trq_green_led9,
	*reng_trq_green_led10,
	*reng_trq_green_led11,
	*reng_trq_green_led12,
	*reng_trq_green_led13,
	*reng_trq_green_led14,
	*reng_trq_green_led15,
	*reng_trq_green_led16,
	*reng_trq_green_led17,
	*reng_trq_green_led18,
	*reng_trq_green_led19,
	*reng_trq_green_led20,
	// Yellow LEDs
	*reng_trq_yellow_led1,
	*reng_trq_yellow_led2,
	*reng_trq_yellow_led3,
	*reng_trq_yellow_led4,
	*reng_trq_yellow_led5,
	*reng_trq_yellow_led6,
	// Red LEDs
	*reng_trq_red_led1,
	*reng_trq_red_led2,
	*reng_trq_red_led3,
	*reng_trq_red_led4,

	// Co-Pilot Display Unit
	// Rotor RPM
	// Red LEDs
	*cp_rtr_rpm_red_led1,
	*cp_rtr_rpm_red_led2,
	*cp_rtr_rpm_red_led3,
	*cp_rtr_rpm_red_led4,
	*cp_rtr_rpm_red_led5,
	*cp_rtr_rpm_red_led6,
	*cp_rtr_rpm_red_led7,
	*cp_rtr_rpm_red_led8,
	*cp_rtr_rpm_red_led9,
	*cp_rtr_rpm_red_led10,
	*cp_rtr_rpm_red_led11,
	*cp_rtr_rpm_red_led12,
	*cp_rtr_rpm_red_led13,
	*cp_rtr_rpm_red_led14,
	*cp_rtr_rpm_red_led15,
	*cp_rtr_rpm_red_led16,
	*cp_rtr_rpm_red_led17,
	*cp_rtr_rpm_red_led18,
	*cp_rtr_rpm_red_led19,
	*cp_rtr_rpm_red_led20,
	*cp_rtr_rpm_red_led21,
	*cp_rtr_rpm_red_led22,
	*cp_rtr_rpm_red_led23,
	*cp_rtr_rpm_red_led24,
	*cp_rtr_rpm_red_led25,
	*cp_rtr_rpm_red_led26,
	*cp_rtr_rpm_red_led27,
	// Yellow LEDs
	*cp_rtr_rpm_yellow_led1,
	*cp_rtr_rpm_yellow_led2,
	*cp_rtr_rpm_yellow_led3,
	*cp_rtr_rpm_yellow_led4,
	*cp_rtr_rpm_yellow_led5,
	*cp_rtr_rpm_yellow_led6,
	*cp_rtr_rpm_yellow_led7,
	*cp_rtr_rpm_yellow_led8,
	*cp_rtr_rpm_yellow_led9,
	// Green LEDs
	*cp_rtr_rpm_green_led1,
	*cp_rtr_rpm_green_led2,
	*cp_rtr_rpm_green_led3,
	*cp_rtr_rpm_green_led4,
	*cp_rtr_rpm_green_led5,

	//L Eng RPM
	// Red LEDs
	*cp_leng_rpm_red_led1,
	*cp_leng_rpm_red_led2,
	*cp_leng_rpm_red_led3,
	*cp_leng_rpm_red_led4,
	*cp_leng_rpm_red_led5,
	*cp_leng_rpm_red_led6,
	*cp_leng_rpm_red_led7,
	*cp_leng_rpm_red_led8,
	*cp_leng_rpm_red_led9,
	*cp_leng_rpm_red_led10,
	*cp_leng_rpm_red_led11,
	*cp_leng_rpm_red_led12,
	*cp_leng_rpm_red_led13,
	*cp_leng_rpm_red_led14,
	*cp_leng_rpm_red_led15,
	*cp_leng_rpm_red_led16,
	*cp_leng_rpm_red_led17,
	*cp_leng_rpm_red_led18,
	*cp_leng_rpm_red_led19,
	*cp_leng_rpm_red_led20,
	*cp_leng_rpm_red_led21,
	*cp_leng_rpm_red_led22,
	*cp_leng_rpm_red_led23,
	*cp_leng_rpm_red_led24,
	*cp_leng_rpm_red_led25,
	*cp_leng_rpm_red_led26,
	*cp_leng_rpm_red_led27,
	// Yellow LEDs
	*cp_leng_rpm_yellow_led1,
	*cp_leng_rpm_yellow_led2,
	*cp_leng_rpm_yellow_led3,
	*cp_leng_rpm_yellow_led4,
	*cp_leng_rpm_yellow_led5,
	*cp_leng_rpm_yellow_led6,
	*cp_leng_rpm_yellow_led7,
	*cp_leng_rpm_yellow_led8,
	*cp_leng_rpm_yellow_led9,
	// Green LEDs
	*cp_leng_rpm_green_led1,
	*cp_leng_rpm_green_led2,
	*cp_leng_rpm_green_led3,
	*cp_leng_rpm_green_led4,
	*cp_leng_rpm_green_led5,

	// R Eng RPM
	// Red LEDs
	*cp_reng_rpm_red_led1,
	*cp_reng_rpm_red_led2,
	*cp_reng_rpm_red_led3,
	*cp_reng_rpm_red_led4,
	*cp_reng_rpm_red_led5,
	*cp_reng_rpm_red_led6,
	*cp_reng_rpm_red_led7,
	*cp_reng_rpm_red_led8,
	*cp_reng_rpm_red_led9,
	*cp_reng_rpm_red_led10,
	*cp_reng_rpm_red_led11,
	*cp_reng_rpm_red_led12,
	*cp_reng_rpm_red_led13,
	*cp_reng_rpm_red_led14,
	*cp_reng_rpm_red_led15,
	*cp_reng_rpm_red_led16,
	*cp_reng_rpm_red_led17,
	*cp_reng_rpm_red_led18,
	*cp_reng_rpm_red_led19,
	*cp_reng_rpm_red_led20,
	*cp_reng_rpm_red_led21,
	*cp_reng_rpm_red_led22,
	*cp_reng_rpm_red_led23,
	*cp_reng_rpm_red_led24,
	*cp_reng_rpm_red_led25,
	*cp_reng_rpm_red_led26,
	*cp_reng_rpm_red_led27,
	// Yellow LEDs
	*cp_reng_rpm_yellow_led1,
	*cp_reng_rpm_yellow_led2,
	*cp_reng_rpm_yellow_led3,
	*cp_reng_rpm_yellow_led4,
	*cp_reng_rpm_yellow_led5,
	*cp_reng_rpm_yellow_led6,
	*cp_reng_rpm_yellow_led7,
	*cp_reng_rpm_yellow_led8,
	*cp_reng_rpm_yellow_led9,
	// Green LEDs
	*cp_reng_rpm_green_led1,
	*cp_reng_rpm_green_led2,
	*cp_reng_rpm_green_led3,
	*cp_reng_rpm_green_led4,
	*cp_reng_rpm_green_led5,

	// L Eng TRQ
	// Green LEDs
	*cp_leng_trq_green_led1,
	*cp_leng_trq_green_led2,
	*cp_leng_trq_green_led3,
	*cp_leng_trq_green_led4,
	*cp_leng_trq_green_led5,
	*cp_leng_trq_green_led6,
	*cp_leng_trq_green_led7,
	*cp_leng_trq_green_led8,
	*cp_leng_trq_green_led9,
	*cp_leng_trq_green_led10,
	*cp_leng_trq_green_led11,
	*cp_leng_trq_green_led12,
	*cp_leng_trq_green_led13,
	*cp_leng_trq_green_led14,
	*cp_leng_trq_green_led15,
	*cp_leng_trq_green_led16,
	*cp_leng_trq_green_led17,
	*cp_leng_trq_green_led18,
	*cp_leng_trq_green_led19,
	*cp_leng_trq_green_led20,
	// Yellow LEDs
	*cp_leng_trq_yellow_led1,
	*cp_leng_trq_yellow_led2,
	*cp_leng_trq_yellow_led3,
	*cp_leng_trq_yellow_led4,
	*cp_leng_trq_yellow_led5,
	*cp_leng_trq_yellow_led6,
	// Red LEDs
	*cp_leng_trq_red_led1,
	*cp_leng_trq_red_led2,
	*cp_leng_trq_red_led3,
	*cp_leng_trq_red_led4,

	// R Eng TRQ
	// Green LEDs
	*cp_reng_trq_green_led1,
	*cp_reng_trq_green_led2,
	*cp_reng_trq_green_led3,
	*cp_reng_trq_green_led4,
	*cp_reng_trq_green_led5,
	*cp_reng_trq_green_led6,
	*cp_reng_trq_green_led7,
	*cp_reng_trq_green_led8,
	*cp_reng_trq_green_led9,
	*cp_reng_trq_green_led10,
	*cp_reng_trq_green_led11,
	*cp_reng_trq_green_led12,
	*cp_reng_trq_green_led13,
	*cp_reng_trq_green_led14,
	*cp_reng_trq_green_led15,
	*cp_reng_trq_green_led16,
	*cp_reng_trq_green_led17,
	*cp_reng_trq_green_led18,
	*cp_reng_trq_green_led19,
	*cp_reng_trq_green_led20,
	// Yellow LEDs
	*cp_reng_trq_yellow_led1,
	*cp_reng_trq_yellow_led2,
	*cp_reng_trq_yellow_led3,
	*cp_reng_trq_yellow_led4,
	*cp_reng_trq_yellow_led5,
	*cp_reng_trq_yellow_led6,
	// Red LEDs
	*cp_reng_trq_red_led1,
	*cp_reng_trq_red_led2,
	*cp_reng_trq_red_led3,
	*cp_reng_trq_red_led4,

	// Central Display Unit
	// Fuel Quantity
	// Left Fuel Tank
	// Yellow LEDs
	*lfuel_tank_yellow1,
	*lfuel_tank_yellow2,
	*lfuel_tank_yellow3,
	*lfuel_tank_yellow4,
	// Green LEDs
	*lfuel_tank_green1,
	*lfuel_tank_green2,
	*lfuel_tank_green3,
	*lfuel_tank_green4,
	*lfuel_tank_green5,
	*lfuel_tank_green6,
	*lfuel_tank_green7,
	*lfuel_tank_green8,
	*lfuel_tank_green9,
	*lfuel_tank_green10,
	*lfuel_tank_green11,
	*lfuel_tank_green12,
	*lfuel_tank_green13,
	*lfuel_tank_green14,
	*lfuel_tank_green15,
	*lfuel_tank_green16,
	*lfuel_tank_green17,
	*lfuel_tank_green18,
	*lfuel_tank_green19,
	*lfuel_tank_green20,
	*lfuel_tank_green21,
	*lfuel_tank_green22,
	*lfuel_tank_green23,
	*lfuel_tank_green24,
	*lfuel_tank_green25,
	*lfuel_tank_green26,

	// Right Fuel Tank
	// Yellow LEDs
	*rfuel_tank_yellow1,
	*rfuel_tank_yellow2,
	*rfuel_tank_yellow3,
	*rfuel_tank_yellow4,
	// Green LEDs
	*rfuel_tank_green1,
	*rfuel_tank_green2,
	*rfuel_tank_green3,
	*rfuel_tank_green4,
	*rfuel_tank_green5,
	*rfuel_tank_green6,
	*rfuel_tank_green7,
	*rfuel_tank_green8,
	*rfuel_tank_green9,
	*rfuel_tank_green10,
	*rfuel_tank_green11,
	*rfuel_tank_green12,
	*rfuel_tank_green13,
	*rfuel_tank_green14,
	*rfuel_tank_green15,
	*rfuel_tank_green16,
	*rfuel_tank_green17,
	*rfuel_tank_green18,
	*rfuel_tank_green19,
	*rfuel_tank_green20,
	*rfuel_tank_green21,
	*rfuel_tank_green22,
	*rfuel_tank_green23,
	*rfuel_tank_green24,
	*rfuel_tank_green25,
	*rfuel_tank_green26,

	// NG Speed
	// Left Engine
	// Green LEDs
	*lng_spd_green1,
	*lng_spd_green2,
	*lng_spd_green3,
	*lng_spd_green4,
	*lng_spd_green5,
	*lng_spd_green6,
	*lng_spd_green7,
	*lng_spd_green8,
	*lng_spd_green9,
	*lng_spd_green10,
	*lng_spd_green11,
	*lng_spd_green12,
	*lng_spd_green13,
	*lng_spd_green14,
	*lng_spd_green15,
	*lng_spd_green16,
	*lng_spd_green17,
	*lng_spd_green18,
	*lng_spd_green19,
	*lng_spd_green20,
	*lng_spd_green21,
	*lng_spd_green22,
	*lng_spd_green23,
	*lng_spd_green24,
	// Yellow LEDs
	*lng_spd_yellow1,
	*lng_spd_yellow2,
	// Red LEDs
	*lng_spd_red1,
	*lng_spd_red2,
	*lng_spd_red3,
	*lng_spd_red4,

	// Right Engine
	// Green LEDs
	*rng_spd_green1,
	*rng_spd_green2,
	*rng_spd_green3,
	*rng_spd_green4,
	*rng_spd_green5,
	*rng_spd_green6,
	*rng_spd_green7,
	*rng_spd_green8,
	*rng_spd_green9,
	*rng_spd_green10,
	*rng_spd_green11,
	*rng_spd_green12,
	*rng_spd_green13,
	*rng_spd_green14,
	*rng_spd_green15,
	*rng_spd_green16,
	*rng_spd_green17,
	*rng_spd_green18,
	*rng_spd_green19,
	*rng_spd_green20,
	*rng_spd_green21,
	*rng_spd_green22,
	*rng_spd_green23,
	*rng_spd_green24,
	// Yellow LEDs
	*rng_spd_yellow1,
	*rng_spd_yellow2,
	// Red LEDs
	*rng_spd_red1,
	*rng_spd_red2,
	*rng_spd_red3,
	*rng_spd_red4,

	// TGT Temp
	// Left Engine
	// Green LEDs
	*ltgt_tmp_green1,
	*ltgt_tmp_green2,
	*ltgt_tmp_green3,
	*ltgt_tmp_green4,
	*ltgt_tmp_green5,
	*ltgt_tmp_green6,
	*ltgt_tmp_green7,
	*ltgt_tmp_green8,
	*ltgt_tmp_green9,
	*ltgt_tmp_green10,
	*ltgt_tmp_green11,
	*ltgt_tmp_green12,
	*ltgt_tmp_green13,
	*ltgt_tmp_green14,
	*ltgt_tmp_green15,
	*ltgt_tmp_green16,
	*ltgt_tmp_green17,
	*ltgt_tmp_green18,
	*ltgt_tmp_green19,
	*ltgt_tmp_green20,
	*ltgt_tmp_green21,
	*ltgt_tmp_green22,
	*ltgt_tmp_green23,
	// Yellow LEDs
	*ltgt_tmp_yellow1,
	*ltgt_tmp_yellow2,
	*ltgt_tmp_yellow3,
	// Red LEDs
	*ltgt_tmp_red1,
	*ltgt_tmp_red2,
	*ltgt_tmp_red3,
	*ltgt_tmp_red4,

	// Right Engine
	// Green LEDs
	*rtgt_tmp_green1,
	*rtgt_tmp_green2,
	*rtgt_tmp_green3,
	*rtgt_tmp_green4,
	*rtgt_tmp_green5,
	*rtgt_tmp_green6,
	*rtgt_tmp_green7,
	*rtgt_tmp_green8,
	*rtgt_tmp_green9,
	*rtgt_tmp_green10,
	*rtgt_tmp_green11,
	*rtgt_tmp_green12,
	*rtgt_tmp_green13,
	*rtgt_tmp_green14,
	*rtgt_tmp_green15,
	*rtgt_tmp_green16,
	*rtgt_tmp_green17,
	*rtgt_tmp_green18,
	*rtgt_tmp_green19,
	*rtgt_tmp_green20,
	*rtgt_tmp_green21,
	*rtgt_tmp_green22,
	*rtgt_tmp_green23,
	// Yellow LEDs
	*rtgt_tmp_yellow1,
	*rtgt_tmp_yellow2,
	*rtgt_tmp_yellow3,
	// Red LEDs
	*rtgt_tmp_red1,
	*rtgt_tmp_red2,
	*rtgt_tmp_red3,
	*rtgt_tmp_red4;

static void animate_mh60l_virtual_cockpit (void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_blackhawk_virtual_cockpit (void)
{
	//
	// 3D instances
	//

	virtual_cockpit_inst3d_detail_level_normal_inst3d = construct_3d_object (OBJECT_3D_MH_60L_COCKPIT);

	virtual_cockpit_inst3d_detail_level_glass_inst3d = construct_3d_object (OBJECT_3D_MH_60L_COCKPIT);

	virtual_cockpit_inst3d = virtual_cockpit_inst3d_detail_level_normal_inst3d;

//	virtual_cockpit_inst3d = construct_3d_object(OBJECT_3D_MH_60L_COCKPIT);

	// Master Warning Panel

	eng1_out_lamp = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_PL_ENG1_OUT_LAMP_ON);
	eng2_out_lamp = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_PL_ENG2_OUT_LAMP_ON);
	low_rtr_rpm_lamp = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_PL_LOW_RTR_RPM_LAMP_ON);
	fire_lamp = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_PL_FIRE_LAMP_ON);
	master_caution_lamp = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_PL_MSTR_CAUT_LAMP_ON);

	// Pilot Display Unit
	// Rotor RPM
	// Red LEDs
	rtr_rpm_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED1);
	rtr_rpm_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED2);
	rtr_rpm_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED3);
	rtr_rpm_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED4);
	rtr_rpm_red_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED5);
	rtr_rpm_red_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED6);
	rtr_rpm_red_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED7);
	rtr_rpm_red_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED8);
	rtr_rpm_red_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED9);
	rtr_rpm_red_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED10);
	rtr_rpm_red_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED11);
	rtr_rpm_red_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED12);
	rtr_rpm_red_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED13);
	rtr_rpm_red_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED14);
	rtr_rpm_red_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED15);
	rtr_rpm_red_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED16);
	rtr_rpm_red_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED17);
	rtr_rpm_red_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED18);
	rtr_rpm_red_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED19);
	rtr_rpm_red_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED20);
	rtr_rpm_red_led21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED21);
	rtr_rpm_red_led22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED22);
	rtr_rpm_red_led23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED23);
	rtr_rpm_red_led24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED24);
	rtr_rpm_red_led25 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED25);
	rtr_rpm_red_led26 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED26);
	rtr_rpm_red_led27 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_RED27);
	// Yellow LEDs
	rtr_rpm_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW1);
	rtr_rpm_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW2);
	rtr_rpm_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW3);
	rtr_rpm_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW4);
	rtr_rpm_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW5);
	rtr_rpm_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW6);
	rtr_rpm_yellow_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW7);
	rtr_rpm_yellow_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW8);
	rtr_rpm_yellow_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_YELLOW9);
	// Green LEDs
	rtr_rpm_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_GRN1);
	rtr_rpm_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_GRN2);
	rtr_rpm_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_GRN3);
	rtr_rpm_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_GRN4);
	rtr_rpm_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTR_RPM_GRN5);

	// L Eng RPM
	// Red LEDs
	leng_rpm_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED1);
	leng_rpm_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED2);
	leng_rpm_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED3);
	leng_rpm_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED4);
	leng_rpm_red_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED5);
	leng_rpm_red_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED6);
	leng_rpm_red_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED7);
	leng_rpm_red_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED8);
	leng_rpm_red_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED9);
	leng_rpm_red_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED10);
	leng_rpm_red_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED11);
	leng_rpm_red_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED12);
	leng_rpm_red_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED13);
	leng_rpm_red_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED14);
	leng_rpm_red_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED15);
	leng_rpm_red_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED16);
	leng_rpm_red_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED17);
	leng_rpm_red_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED18);
	leng_rpm_red_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED19);
	leng_rpm_red_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED20);
	leng_rpm_red_led21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED21);
	leng_rpm_red_led22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED22);
	leng_rpm_red_led23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED23);
	leng_rpm_red_led24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED24);
	leng_rpm_red_led25 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED25);
	leng_rpm_red_led26 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED26);
	leng_rpm_red_led27 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_RED27);
	// Yellow LEDs
	leng_rpm_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW1);
	leng_rpm_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW2);
	leng_rpm_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW3);
	leng_rpm_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW4);
	leng_rpm_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW5);
	leng_rpm_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW6);
	leng_rpm_yellow_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW7);
	leng_rpm_yellow_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW8);
	leng_rpm_yellow_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_YELLOW9);
	// Green LEDs
	leng_rpm_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_GRN1);
	leng_rpm_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_GRN2);
	leng_rpm_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_GRN3);
	leng_rpm_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_GRN4);
	leng_rpm_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_RPM_GRN5);

	// R Eng RPM
	// Red LEDs
	reng_rpm_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED1);
	reng_rpm_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED2);
	reng_rpm_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED3);
	reng_rpm_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED4);
	reng_rpm_red_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED5);
	reng_rpm_red_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED6);
	reng_rpm_red_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED7);
	reng_rpm_red_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED8);
	reng_rpm_red_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED9);
	reng_rpm_red_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED10);
	reng_rpm_red_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED11);
	reng_rpm_red_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED12);
	reng_rpm_red_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED13);
	reng_rpm_red_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED14);
	reng_rpm_red_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED15);
	reng_rpm_red_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED16);
	reng_rpm_red_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED17);
	reng_rpm_red_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED18);
	reng_rpm_red_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED19);
	reng_rpm_red_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED20);
	reng_rpm_red_led21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED21);
	reng_rpm_red_led22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED22);
	reng_rpm_red_led23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED23);
	reng_rpm_red_led24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED24);
	reng_rpm_red_led25 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED25);
	reng_rpm_red_led26 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED26);
	reng_rpm_red_led27 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_RED27);
	// Yellow LEDs
	reng_rpm_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW1);
	reng_rpm_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW2);
	reng_rpm_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW3);
	reng_rpm_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW4);
	reng_rpm_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW5);
	reng_rpm_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW6);
	reng_rpm_yellow_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW7);
	reng_rpm_yellow_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW8);
	reng_rpm_yellow_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_YELLOW9);
	// Green LEDs
	reng_rpm_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_GRN1);
	reng_rpm_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_GRN2);
	reng_rpm_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_GRN3);
	reng_rpm_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_GRN4);
	reng_rpm_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_RPM_GRN5);

	// L Eng TRQ
	// Green LEDs
	leng_trq_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN1);
	leng_trq_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN2);
	leng_trq_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN3);
	leng_trq_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN4);
	leng_trq_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN5);
	leng_trq_green_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN6);
	leng_trq_green_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN7);
	leng_trq_green_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN8);
	leng_trq_green_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN9);
	leng_trq_green_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN10);
	leng_trq_green_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN11);
	leng_trq_green_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN12);
	leng_trq_green_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN13);
	leng_trq_green_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN14);
	leng_trq_green_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN15);
	leng_trq_green_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN16);
	leng_trq_green_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN17);
	leng_trq_green_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN18);
	leng_trq_green_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN19);
	leng_trq_green_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_GRN20);
	// Yellow LEDs
	leng_trq_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_YELLOW1);
	leng_trq_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_YELLOW2);
	leng_trq_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_YELLOW3);
	leng_trq_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_YELLOW4);
	leng_trq_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_YELLOW5);
	leng_trq_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_YELLOW6);
	// Red LEDs
	leng_trq_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_RED1);
	leng_trq_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_RED2);
	leng_trq_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_RED3);
	leng_trq_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LENG_TRQ_RED4);

	// R Eng TRQ
	// Green LEDs
	reng_trq_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN1);
	reng_trq_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN2);
	reng_trq_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN3);
	reng_trq_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN4);
	reng_trq_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN5);
	reng_trq_green_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN6);
	reng_trq_green_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN7);
	reng_trq_green_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN8);
	reng_trq_green_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN9);
	reng_trq_green_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN10);
	reng_trq_green_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN11);
	reng_trq_green_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN12);
	reng_trq_green_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN13);
	reng_trq_green_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN14);
	reng_trq_green_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN15);
	reng_trq_green_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN16);
	reng_trq_green_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN17);
	reng_trq_green_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN18);
	reng_trq_green_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN19);
	reng_trq_green_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_GRN20);
	// Yellow LEDs
	reng_trq_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_YELLOW1);
	reng_trq_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_YELLOW2);
	reng_trq_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_YELLOW3);
	reng_trq_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_YELLOW4);
	reng_trq_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_YELLOW5);
	reng_trq_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_YELLOW6);
	// Red LEDs
	reng_trq_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_RED1);
	reng_trq_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_RED2);
	reng_trq_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_RED3);
	reng_trq_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RENG_TRQ_RED4);

	// Co-Pilot Display Unit
	// Rotor RPM
	// Red LEDs
	cp_rtr_rpm_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED1);
	cp_rtr_rpm_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED2);
	cp_rtr_rpm_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED3);
	cp_rtr_rpm_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED4);
	cp_rtr_rpm_red_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED5);
	cp_rtr_rpm_red_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED6);
	cp_rtr_rpm_red_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED7);
	cp_rtr_rpm_red_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED8);
	cp_rtr_rpm_red_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED9);
	cp_rtr_rpm_red_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED10);
	cp_rtr_rpm_red_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED11);
	cp_rtr_rpm_red_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED12);
	cp_rtr_rpm_red_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED13);
	cp_rtr_rpm_red_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED14);
	cp_rtr_rpm_red_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED15);
	cp_rtr_rpm_red_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED16);
	cp_rtr_rpm_red_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED17);
	cp_rtr_rpm_red_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED18);
	cp_rtr_rpm_red_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED19);
	cp_rtr_rpm_red_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED20);
	cp_rtr_rpm_red_led21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED21);
	cp_rtr_rpm_red_led22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED22);
	cp_rtr_rpm_red_led23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED23);
	cp_rtr_rpm_red_led24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED24);
	cp_rtr_rpm_red_led25 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED25);
	cp_rtr_rpm_red_led26 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED26);
	cp_rtr_rpm_red_led27 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_RED27);
	// Yellow LEDs
	cp_rtr_rpm_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW1);
	cp_rtr_rpm_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW2);
	cp_rtr_rpm_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW3);
	cp_rtr_rpm_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW4);
	cp_rtr_rpm_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW5);
	cp_rtr_rpm_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW6);
	cp_rtr_rpm_yellow_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW7);
	cp_rtr_rpm_yellow_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW8);
	cp_rtr_rpm_yellow_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_YELLOW9);
	// Green LEDs
	cp_rtr_rpm_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_GRN1);
	cp_rtr_rpm_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_GRN2);
	cp_rtr_rpm_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_GRN3);
	cp_rtr_rpm_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_GRN4);
	cp_rtr_rpm_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RTR_RPM_GRN5);

	// L Eng RPM
	// Red LEDs
	cp_leng_rpm_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED1);
	cp_leng_rpm_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED2);
	cp_leng_rpm_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED3);
	cp_leng_rpm_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED4);
	cp_leng_rpm_red_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED5);
	cp_leng_rpm_red_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED6);
	cp_leng_rpm_red_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED7);
	cp_leng_rpm_red_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED8);
	cp_leng_rpm_red_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED9);
	cp_leng_rpm_red_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED10);
	cp_leng_rpm_red_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED11);
	cp_leng_rpm_red_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED12);
	cp_leng_rpm_red_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED13);
	cp_leng_rpm_red_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED14);
	cp_leng_rpm_red_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED15);
	cp_leng_rpm_red_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED16);
	cp_leng_rpm_red_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED17);
	cp_leng_rpm_red_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED18);
	cp_leng_rpm_red_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED19);
	cp_leng_rpm_red_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED20);
	cp_leng_rpm_red_led21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED21);
	cp_leng_rpm_red_led22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED22);
	cp_leng_rpm_red_led23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED23);
	cp_leng_rpm_red_led24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED24);
	cp_leng_rpm_red_led25 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED25);
	cp_leng_rpm_red_led26 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED26);
	cp_leng_rpm_red_led27 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_RED27);
	// Yellow LEDs
	cp_leng_rpm_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW1);
	cp_leng_rpm_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW2);
	cp_leng_rpm_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW3);
	cp_leng_rpm_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW4);
	cp_leng_rpm_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW5);
	cp_leng_rpm_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW6);
	cp_leng_rpm_yellow_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW7);
	cp_leng_rpm_yellow_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW8);
	cp_leng_rpm_yellow_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_YELLOW9);
	// Green LEDs
	cp_leng_rpm_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_GRN1);
	cp_leng_rpm_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_GRN2);
	cp_leng_rpm_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_GRN3);
	cp_leng_rpm_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_GRN4);
	cp_leng_rpm_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_RPM_GRN5);

	// R Eng RPM
	// Red LEDs
	cp_reng_rpm_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED1);
	cp_reng_rpm_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED2);
	cp_reng_rpm_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED3);
	cp_reng_rpm_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED4);
	cp_reng_rpm_red_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED5);
	cp_reng_rpm_red_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED6);
	cp_reng_rpm_red_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED7);
	cp_reng_rpm_red_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED8);
	cp_reng_rpm_red_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED9);
	cp_reng_rpm_red_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED10);
	cp_reng_rpm_red_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED11);
	cp_reng_rpm_red_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED12);
	cp_reng_rpm_red_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED13);
	cp_reng_rpm_red_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED14);
	cp_reng_rpm_red_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED15);
	cp_reng_rpm_red_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED16);
	cp_reng_rpm_red_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED17);
	cp_reng_rpm_red_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED18);
	cp_reng_rpm_red_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED19);
	cp_reng_rpm_red_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED20);
	cp_reng_rpm_red_led21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED21);
	cp_reng_rpm_red_led22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED22);
	cp_reng_rpm_red_led23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED23);
	cp_reng_rpm_red_led24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED24);
	cp_reng_rpm_red_led25 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED25);
	cp_reng_rpm_red_led26 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED26);
	cp_reng_rpm_red_led27 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_RED27);
	// Yellow LEDs
	cp_reng_rpm_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW1);
	cp_reng_rpm_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW2);
	cp_reng_rpm_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW3);
	cp_reng_rpm_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW4);
	cp_reng_rpm_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW5);
	cp_reng_rpm_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW6);
	cp_reng_rpm_yellow_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW7);
	cp_reng_rpm_yellow_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW8);
	cp_reng_rpm_yellow_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_YELLOW9);
	// Green LEDs
	cp_reng_rpm_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_GRN1);
	cp_reng_rpm_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_GRN2);
	cp_reng_rpm_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_GRN3);
	cp_reng_rpm_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_GRN4);
	cp_reng_rpm_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_RPM_GRN5);

	// L Eng TRQ
	// Green LEDs
	cp_leng_trq_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN1);
	cp_leng_trq_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN2);
	cp_leng_trq_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN3);
	cp_leng_trq_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN4);
	cp_leng_trq_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN5);
	cp_leng_trq_green_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN6);
	cp_leng_trq_green_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN7);
	cp_leng_trq_green_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN8);
	cp_leng_trq_green_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN9);
	cp_leng_trq_green_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN10);
	cp_leng_trq_green_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN11);
	cp_leng_trq_green_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN12);
	cp_leng_trq_green_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN13);
	cp_leng_trq_green_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN14);
	cp_leng_trq_green_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN15);
	cp_leng_trq_green_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN16);
	cp_leng_trq_green_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN17);
	cp_leng_trq_green_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN18);
	cp_leng_trq_green_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN19);
	cp_leng_trq_green_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_GRN20);
	// Yellow LEDs
	cp_leng_trq_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_YELLOW1);
	cp_leng_trq_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_YELLOW2);
	cp_leng_trq_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_YELLOW3);
	cp_leng_trq_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_YELLOW4);
	cp_leng_trq_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_YELLOW5);
	cp_leng_trq_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_YELLOW6);
	// Red LEDs
	cp_leng_trq_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_RED1);
	cp_leng_trq_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_RED2);
	cp_leng_trq_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_RED3);
	cp_leng_trq_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_LENG_TRQ_RED4);

	// R Eng TRQ
	// Green LEDs
	cp_reng_trq_green_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN1);
	cp_reng_trq_green_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN2);
	cp_reng_trq_green_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN3);
	cp_reng_trq_green_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN4);
	cp_reng_trq_green_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN5);
	cp_reng_trq_green_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN6);
	cp_reng_trq_green_led7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN7);
	cp_reng_trq_green_led8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN8);
	cp_reng_trq_green_led9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN9);
	cp_reng_trq_green_led10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN10);
	cp_reng_trq_green_led11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN11);
	cp_reng_trq_green_led12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN12);
	cp_reng_trq_green_led13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN13);
	cp_reng_trq_green_led14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN14);
	cp_reng_trq_green_led15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN15);
	cp_reng_trq_green_led16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN16);
	cp_reng_trq_green_led17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN17);
	cp_reng_trq_green_led18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN18);
	cp_reng_trq_green_led19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN19);
	cp_reng_trq_green_led20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_GRN20);
	// Yellow LEDs
	cp_reng_trq_yellow_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_YELLOW1);
	cp_reng_trq_yellow_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_YELLOW2);
	cp_reng_trq_yellow_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_YELLOW3);
	cp_reng_trq_yellow_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_YELLOW4);
	cp_reng_trq_yellow_led5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_YELLOW5);
	cp_reng_trq_yellow_led6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_YELLOW6);
	// Red LEDs
	cp_reng_trq_red_led1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_RED1);
	cp_reng_trq_red_led2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_RED2);
	cp_reng_trq_red_led3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_RED3);
	cp_reng_trq_red_led4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_CP_RENG_TRQ_RED4);

	// Central Display Unit
	// Fuel Quantity
	// Left Fuel Tank
	// Yellow LEDs
	lfuel_tank_yellow1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_YELLOW1);
	lfuel_tank_yellow2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_YELLOW2);
	lfuel_tank_yellow3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_YELLOW3);
	lfuel_tank_yellow4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_YELLOW4);
	// Green LEDs
	lfuel_tank_green1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN1);
	lfuel_tank_green2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN2);
	lfuel_tank_green3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN3);
	lfuel_tank_green4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN4);
	lfuel_tank_green5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN5);
	lfuel_tank_green6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN6);
	lfuel_tank_green7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN7);
	lfuel_tank_green8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN8);
	lfuel_tank_green9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN9);
	lfuel_tank_green10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN10);
	lfuel_tank_green11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN11);
	lfuel_tank_green12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN12);
	lfuel_tank_green13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN13);
	lfuel_tank_green14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN14);
	lfuel_tank_green15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN15);
	lfuel_tank_green16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN16);
	lfuel_tank_green17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN17);
	lfuel_tank_green18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN18);
	lfuel_tank_green19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN19);
	lfuel_tank_green20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN20);
	lfuel_tank_green21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN21);
	lfuel_tank_green22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN22);
	lfuel_tank_green23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN23);
	lfuel_tank_green24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN24);
	lfuel_tank_green25 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN25);
	lfuel_tank_green26 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LFUEL_GREEN26);

	// Right Fuel Tank
	// Yellow LEDs
	rfuel_tank_yellow1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_YELLOW1);
	rfuel_tank_yellow2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_YELLOW2);
	rfuel_tank_yellow3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_YELLOW3);
	rfuel_tank_yellow4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_YELLOW4);
	// Green LEDs
	rfuel_tank_green1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN1);
	rfuel_tank_green2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN2);
	rfuel_tank_green3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN3);
	rfuel_tank_green4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN4);
	rfuel_tank_green5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN5);
	rfuel_tank_green6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN6);
	rfuel_tank_green7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN7);
	rfuel_tank_green8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN8);
	rfuel_tank_green9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN9);
	rfuel_tank_green10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN10);
	rfuel_tank_green11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN11);
	rfuel_tank_green12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN12);
	rfuel_tank_green13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN13);
	rfuel_tank_green14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN14);
	rfuel_tank_green15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN15);
	rfuel_tank_green16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN16);
	rfuel_tank_green17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN17);
	rfuel_tank_green18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN18);
	rfuel_tank_green19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN19);
	rfuel_tank_green20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN20);
	rfuel_tank_green21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN21);
	rfuel_tank_green22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN22);
	rfuel_tank_green23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN23);
	rfuel_tank_green24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN24);
	rfuel_tank_green25 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN25);
	rfuel_tank_green26 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RFUEL_GREEN26);

	// NG Speed
	// Left Engine
	// Green LEDs
	lng_spd_green1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN1);
	lng_spd_green2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN2);
	lng_spd_green3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN3);
	lng_spd_green4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN4);
	lng_spd_green5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN5);
	lng_spd_green6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN6);
	lng_spd_green7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN7);
	lng_spd_green8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN8);
	lng_spd_green9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN9);
	lng_spd_green10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN10);
	lng_spd_green11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN11);
	lng_spd_green12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN12);
	lng_spd_green13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN13);
	lng_spd_green14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN14);
	lng_spd_green15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN15);
	lng_spd_green16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN16);
	lng_spd_green17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN17);
	lng_spd_green18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN18);
	lng_spd_green19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN19);
	lng_spd_green20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN20);
	lng_spd_green21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN21);
	lng_spd_green22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN22);
	lng_spd_green23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN23);
	lng_spd_green24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_GREEN24);
	// Yellow LEDs
	lng_spd_yellow1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_YELLOW1);
	lng_spd_yellow2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_YELLOW2);
	// Red LEDs
	lng_spd_red1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_RED1);
	lng_spd_red2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_RED2);
	lng_spd_red3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_RED3);
	lng_spd_red4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LNG_SPD_RED4);

	// Right Engine
	// Green LEDs
	rng_spd_green1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN1);
	rng_spd_green2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN2);
	rng_spd_green3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN3);
	rng_spd_green4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN4);
	rng_spd_green5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN5);
	rng_spd_green6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN6);
	rng_spd_green7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN7);
	rng_spd_green8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN8);
	rng_spd_green9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN9);
	rng_spd_green10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN10);
	rng_spd_green11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN11);
	rng_spd_green12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN12);
	rng_spd_green13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN13);
	rng_spd_green14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN14);
	rng_spd_green15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN15);
	rng_spd_green16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN16);
	rng_spd_green17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN17);
	rng_spd_green18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN18);
	rng_spd_green19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN19);
	rng_spd_green20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN20);
	rng_spd_green21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN21);
	rng_spd_green22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN22);
	rng_spd_green23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN23);
	rng_spd_green24 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_GREEN24);
	// Yellow LEDs
	rng_spd_yellow1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_YELLOW1);
	rng_spd_yellow2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_YELLOW2);
	// Red LEDs
	rng_spd_red1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_RED1);
	rng_spd_red2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_RED2);
	rng_spd_red3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_RED3);
	rng_spd_red4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RNG_SPD_RED4);

	// TGT Temp
	// Left Engine
	// Green LEDs
	ltgt_tmp_green1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN1);
	ltgt_tmp_green2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN2);
	ltgt_tmp_green3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN3);
	ltgt_tmp_green4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN4);
	ltgt_tmp_green5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN5);
	ltgt_tmp_green6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN6);
	ltgt_tmp_green7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN7);
	ltgt_tmp_green8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN8);
	ltgt_tmp_green9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN9);
	ltgt_tmp_green10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN10);
	ltgt_tmp_green11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN11);
	ltgt_tmp_green12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN12);
	ltgt_tmp_green13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN13);
	ltgt_tmp_green14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN14);
	ltgt_tmp_green15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN15);
	ltgt_tmp_green16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN16);
	ltgt_tmp_green17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN17);
	ltgt_tmp_green18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN18);
	ltgt_tmp_green19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN19);
	ltgt_tmp_green20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN20);
	ltgt_tmp_green21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN21);
	ltgt_tmp_green22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN22);
	ltgt_tmp_green23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_GREEN23);
	// Yellow LEDs
	ltgt_tmp_yellow1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_YELLOW1);
	ltgt_tmp_yellow2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_YELLOW2);
	ltgt_tmp_yellow3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_YELLOW3);
	// Red LEDs
	ltgt_tmp_red1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_RED1);
	ltgt_tmp_red2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_RED2);
	ltgt_tmp_red3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_RED3);
	ltgt_tmp_red4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_LTGT_TEMP_RED4);

	// Right Engine
	// Green LEDs
	rtgt_tmp_green1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN1);
	rtgt_tmp_green2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN2);
	rtgt_tmp_green3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN3);
	rtgt_tmp_green4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN4);
	rtgt_tmp_green5 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN5);
	rtgt_tmp_green6 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN6);
	rtgt_tmp_green7 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN7);
	rtgt_tmp_green8 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN8);
	rtgt_tmp_green9 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN9);
	rtgt_tmp_green10 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN10);
	rtgt_tmp_green11 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN11);
	rtgt_tmp_green12 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN12);
	rtgt_tmp_green13 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN13);
	rtgt_tmp_green14 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN14);
	rtgt_tmp_green15 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN15);
	rtgt_tmp_green16 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN16);
	rtgt_tmp_green17 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN17);
	rtgt_tmp_green18 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN18);
	rtgt_tmp_green19 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN19);
	rtgt_tmp_green20 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN20);
	rtgt_tmp_green21 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN21);
	rtgt_tmp_green22 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN22);
	rtgt_tmp_green23 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_GREEN23);
	// Yellow LEDs
	rtgt_tmp_yellow1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_YELLOW1);
	rtgt_tmp_yellow2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_YELLOW2);
	rtgt_tmp_yellow3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_YELLOW3);
	// Red LEDs
	rtgt_tmp_red1 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_RED1);
	rtgt_tmp_red2 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_RED2);
	rtgt_tmp_red3 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_RED3);
	rtgt_tmp_red4 = find_sub_object(virtual_cockpit_inst3d, OBJECT_3D_SUB_OBJECT_BH_RTGT_TEMP_RED4);

	//	create list of interactive scenes

	pilot_head_pitch_datum = get_blackhawk_pilot_head_pitch_datum ();

	co_pilot_head_pitch_datum = get_blackhawk_co_pilot_head_pitch_datum ();

	//
	// wipers and rain
	//

	initialise_blackhawk_virtual_cockpit_wiper_and_rain_effect ();

	//
	// crew animation
	//

	initialise_blackhawk_crew_animation ();

	//
	// canopy doors
	//

	initialise_blackhawk_virtual_cockpit_canopy_doors ();

	//
	// virtual cockpit cameras
	//

	initialise_common_virtual_cockpit_cameras ();

//VJ 050208 cleaing up wideview
	wide_cockpit_nr = WIDEVIEW_BLACKHAWK_PILOT;
//VJ wideview mod, date: 20-mar-03
//start up in normal view because when you switch to wideview the parameters are read
	set_global_wide_cockpit(FALSE);

	// set up cockpit light
	{
		cockpit_light_colors colors[] = {COCKPIT_LIGHT_NONE, COCKPIT_LIGHT_YELLOW, COCKPIT_LIGHT_BLUE};
		initialise_cockpit_lights(colors, 3);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_blackhawk_virtual_cockpit (void)
{
	//
	// 3D instances
	//

	destruct_3d_object (virtual_cockpit_inst3d_detail_level_normal_inst3d);

	destruct_3d_object (virtual_cockpit_inst3d_detail_level_glass_inst3d);

//	destruct_3d_object (virtual_cockpit_engine_displays_inst3d);

	virtual_cockpit_inst3d = NULL;

	//
	// wipers and rain
	//

	deinitialise_blackhawk_virtual_cockpit_wiper_and_rain_effect ();

	//
	// crew animation
	//

	deinitialise_blackhawk_crew_animation ();

	//
	// virtual cockpit cameras
	//

	deinitialise_common_virtual_cockpit_cameras ();

	clear_head_movement_data();

	// remove cockpit lights
	deinitialise_cockpit_lights();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void animate_mh60l_virtual_cockpit (void)
{

}

void update_blackhawk_virtual_cockpit (void)
{
	int
		depth,
		draw_glass_cockpit,
		draw_controls,
		draw_crew,
		draw_pilot_cockpit,
		draw_co_pilot_cockpit;

	object_3d_sub_object_search_data
		search;

		////////////////////////////////////////
	//
	// sort out what to draw
	//
		////////////////////////////////////////

	switch (get_view_mode ())
		{
		case VIEW_MODE_VIRTUAL_COCKPIT_CREW:
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_LHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_RHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_LHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_RHS_DISPLAY:
		{
			draw_glass_cockpit = FALSE;

			break;
		}
		default:
		{
			draw_glass_cockpit = get_global_glass_cockpit ();

			break;
		}
	}

	draw_controls = !draw_glass_cockpit;

	if (get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_CREW)
	{
		draw_pilot_cockpit = TRUE;

		draw_co_pilot_cockpit = TRUE;
	}
	else
	{
		if (get_crew_role () == CREW_ROLE_PILOT)
		{
			draw_pilot_cockpit = TRUE;

			draw_co_pilot_cockpit = FALSE;
		}
		else
		{
			draw_pilot_cockpit = FALSE;

			draw_co_pilot_cockpit = TRUE;
		}
	}

	//
	// select 3D instance
	//

	if (draw_glass_cockpit)
	{
		if (virtual_cockpit_inst3d != virtual_cockpit_inst3d_detail_level_glass_inst3d)
		{
			virtual_cockpit_inst3d_detail_level_glass_inst3d->vp = virtual_cockpit_inst3d->vp;

			virtual_cockpit_inst3d = virtual_cockpit_inst3d_detail_level_glass_inst3d;
		}
}
	else
	{
		if (virtual_cockpit_inst3d != virtual_cockpit_inst3d_detail_level_normal_inst3d)
{
			virtual_cockpit_inst3d_detail_level_normal_inst3d->vp = virtual_cockpit_inst3d->vp;

			virtual_cockpit_inst3d = virtual_cockpit_inst3d_detail_level_normal_inst3d;
		}
	}

	//
	// draw cockpits
	//

	depth = 0;

	for (;;)
	{
		search.search_depth = depth;
		search.search_object = virtual_cockpit_inst3d;
		search.sub_object_index = OBJECT_3D_SUB_OBJECT_VISIBLE_TO_PILOT;

		if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
		{
			search.result_sub_object->visible_object = draw_pilot_cockpit;
		}
		else
		{
			break;
		}

		depth++;
}

	depth = 0;

	for (;;)
{
		search.search_depth = depth;
		search.search_object = virtual_cockpit_inst3d;
		search.sub_object_index = OBJECT_3D_SUB_OBJECT_VISIBLE_TO_WSO;

		if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
			search.result_sub_object->visible_object = draw_co_pilot_cockpit;
	}
		else
	{
			break;
	}

		depth++;
	}

	//
	// draw crew
	//

//VJ 050206: wideview improvement show other pilot when in wideview
	draw_crew = !(get_global_wide_cockpit () && wide_cockpit_nr == WIDEVIEW_BLACKHAWK_PILOT);

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_COMANCHE_PILOT_VISIBLE;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search.result_sub_object->visible_object = draw_crew;
	}

//VJ 050206: wideview improvement show other pilot when in wideview
	draw_crew = !(get_global_wide_cockpit () && wide_cockpit_nr == WIDEVIEW_BLACKHAWK_COPILOT);

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_COMANCHE_WSO_VISIBLE;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search.result_sub_object->visible_object = draw_crew;
	}

	//
	// draw controls
	//

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_COCKPIT_PILOT_JOYSTICK;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search.result_sub_object->visible_object = draw_controls;
	}

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_COCKPIT_PILOT_COLLECTIVE;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search.result_sub_object->visible_object = draw_controls;
}

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_COCKPIT_WSO_JOYSTICK;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
{
		search.result_sub_object->visible_object = draw_controls;
	}

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_COCKPIT_WSO_COLLECTIVE;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search.result_sub_object->visible_object = draw_controls;
	}

	////////////////////////////////////////
	//
	// update animations
	//
	////////////////////////////////////////

	//
	// crew animation
	//

//	update_blackhawk_crew_animation ();

	//
	// canopy doors
	//

	animate_blackhawk_virtual_cockpit_canopy_doors ();

	////////////////////////////////////////
	//
	// sort static hands
	//
	////////////////////////////////////////

	if (!draw_crew)
	{
		search.search_depth = 0;
		search.search_object = virtual_cockpit_inst3d;
		search.sub_object_index = OBJECT_3D_SUB_OBJECT_COCKPIT_PILOT_HAND_STATIC;

		if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
			search.result_sub_object->visible_object = FALSE;
	}

		search.search_depth = 0;
		search.search_object = virtual_cockpit_inst3d;
		search.sub_object_index = OBJECT_3D_SUB_OBJECT_COCKPIT_WSO_HAND_STATIC;

		if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
			search.result_sub_object->visible_object = FALSE;
		}
	}

	if (target_acquisition_system <= TARGET_ACQUISITION_SYSTEM_AIR_RADAR && view_mode != VIEW_MODE_EXTERNAL)
	{
		viewpoint pilot_head_attitude,
					pilot_head_pos;
		
//		get_3d_sub_object_viewpoint (find_sub_object(virtual_cockpit_inst3d, !get_local_entity_int_value (get_pilot_entity (), INT_TYPE_CREW_ROLE) ? OBJECT_3D_SUB_OBJECT_PILOT_HEAD : OBJECT_3D_SUB_OBJECT_WSO_HEAD),
//			&pilot_head_attitude, FALSE);
//		get_3d_sub_object_viewpoint (find_sub_object(virtual_cockpit_inst3d, !get_local_entity_int_value (get_pilot_entity (), INT_TYPE_CREW_ROLE) ? OBJECT_3D_SUB_OBJECT_PILOT_VIEWPOINT : OBJECT_3D_SUB_OBJECT_WSO_VIEWPOINT),
//			&pilot_head_pos, FALSE);

		get_pilot_local_viewpoint(&pilot_head_pos.position, &pilot_head_attitude.attitude, TRUE);
	}

	animate_mh60l_virtual_cockpit();

	// Engine Displays
	update_rtr_rpm_display();
	update_leng_rpm_display();
	update_reng_rpm_display();
	update_leng_trq_display();
	update_reng_trq_display();
	update_fuel_display();
	update_lng_speed_display();
	update_rng_speed_display();
	update_ltgt_temp_display();
	update_rtgt_temp_display();

	// Master Warning Panel
	update_master_warning_lamps();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pre_render_blackhawk_virtual_cockpit_displays (void)
			{
	switch (get_view_mode ())
				{
		case VIEW_MODE_VIRTUAL_COCKPIT_CREW:
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_LHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_RHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_LHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_RHS_DISPLAY:
					{
						break;
					}
		default:
		{
			if (!get_global_draw_cockpit_graphics ())
					{
				return;
			}

						break;
					}
	}

	draw_blackhawk_mfd ();

//	draw_blackhawk_chrono_on_texture ();

	if (get_view_mode () == VIEW_MODE_VIRTUAL_COCKPIT_CREW)
	{
		draw_blackhawk_hud_on_lens_texture ();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_blackhawk_virtual_cockpit (void)
					{
	int
		draw_main_rotors;

	object_3d_instance
		*inst3d;

	object_3d_sub_object_search_data
		search;

	switch (get_view_mode ())
	{
		case VIEW_MODE_VIRTUAL_COCKPIT_CREW:
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_LHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_RHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_LHS_DISPLAY:
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_RHS_DISPLAY:
		{
						break;
					}
		default:
		{
			if (!get_global_draw_cockpit_graphics ())
					{
				return;
			}

						break;
					}
				}

	//
	// lamps
	//

	draw_blackhawk_virtual_cockpit_lamps ();

	//
	// upfront
	//

	draw_blackhawk_upfront_display_on_texture();

	//
	// crew animation
	//

	set_blackhawk_crew_head_positions ();

	//
	// animate main rotors
	//

	inst3d = (object_3d_instance *) get_local_entity_ptr_value (get_gunship_entity (), PTR_TYPE_INSTANCE_3D_OBJECT);

	animate_helicopter_virtual_cockpit_main_rotors (get_gunship_entity (), virtual_cockpit_inst3d, inst3d);

	draw_main_rotors = TRUE;

	if (get_global_glass_cockpit ())
	{
		draw_main_rotors = FALSE;
	}
	else
	{
		if (get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_CREW)
		{
			if (get_helicopter_main_rotors_blurred (get_gunship_entity ()))
			{
				if (!get_global_blurred_main_rotors_visible_from_cockpit ())
				{
					draw_main_rotors = FALSE;
				}
			}
		}
		}

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = OBJECT_3D_SUB_OBJECT_MAIN_ROTOR_SHAFT;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
	{
		search.result_sub_object->visible_object = draw_main_rotors;
	}

	//
	// animate wipers
	//

	animate_blackhawk_wipers (virtual_cockpit_inst3d);

	//
	// draw 3D scene
	//

	set_3d_view_distances (main_3d_env, 10.0, 0.1, 1.0, 0.0);

	realise_3d_clip_extents (main_3d_env);

	recalculate_3d_environment_settings (main_3d_env);

		clear_zbuffer_screen ();

		if (begin_3d_scene ())
		{
			//
		// light direction is in world coordinates
			//

		light_3d_source
			*display_backlight,
			*cockpit_light;

		vec3d
			direction;

		matrix3x3
			m1,
			m2;
		
		float
			mfd_light_power = 0.0;

//VJ 050131 update on wideview mod, much better movement
		if (get_global_wide_cockpit () &&
			( get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_PILOT_LHS_DISPLAY &&
				get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_PILOT_RHS_DISPLAY &&
				get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_LHS_DISPLAY &&
				get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_RHS_DISPLAY )
			)
		{
				get_blackhawk_crew_viewpoint ();

				virtual_cockpit_inst3d->vp.x += wide_cockpit_position[wide_cockpit_nr].c.x;
				virtual_cockpit_inst3d->vp.y += wide_cockpit_position[wide_cockpit_nr].c.y;
				virtual_cockpit_inst3d->vp.z += wide_cockpit_position[wide_cockpit_nr].c.z;

				if (wide_cockpit_nr == WIDEVIEW_BLACKHAWK_PILOT)
					pilot_head_pitch_datum = rad ( wide_cockpit_position[wide_cockpit_nr].c.p );
				if (wide_cockpit_nr == WIDEVIEW_BLACKHAWK_COPILOT)
					co_pilot_head_pitch_datum = rad ( wide_cockpit_position[wide_cockpit_nr].c.p );

				set_3d_view_distances (main_3d_env, 10.0, 0.1, 1.0, 0.0);

		}

		//ataribaby 27/12/2008 new head g-force movement and vibration from main rotor
		if (get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_PILOT_LHS_DISPLAY &&
				get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_PILOT_RHS_DISPLAY &&
				get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_LHS_DISPLAY &&
				get_view_mode () != VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_RHS_DISPLAY)
			get_forces_acting_on_pilot(&virtual_cockpit_inst3d->vp.x, &virtual_cockpit_inst3d->vp.y, &virtual_cockpit_inst3d->vp.z, FALSE, TRUE);

			{

				//
				// airspeed
				//

				search.search_depth = 0;
				search.search_object = virtual_cockpit_inst3d;
				search.sub_object_index = OBJECT_3D_SUB_OBJECT_BH_IAS_NEEDLE;

				if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
				{
					float
					airspeed_needle_value;

					airspeed_needle_value = bound(knots (current_flight_dynamics->indicated_airspeed.value), 0.0, 250.0);

					airspeed_needle_value *= rad (180.0) / 160.0;

					search.result_sub_object->relative_roll = -airspeed_needle_value;
				}

				//
				// radar altimeter
				//

				search.search_depth = 0;
				search.search_object = virtual_cockpit_inst3d;
				search.sub_object_index = OBJECT_3D_SUB_OBJECT_BH_RDR_ALT_NEEDLE;

				if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
				{
					search.result_sub_object->relative_roll = get_blackhawk_virtual_cockpit_radar_altimeter_needle_value ();
				}

				//
				// barometric altimeter
				//

				search.search_depth = 0;
				search.search_object = virtual_cockpit_inst3d;
				search.sub_object_index = OBJECT_3D_SUB_OBJECT_BH_BAR_ALT_NEEDLE;

				if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
				{
					search.result_sub_object->relative_roll = get_blackhawk_virtual_cockpit_barometric_altimeter_needle_value ();
				}

				//
				// vertical speed
				//

				search.search_depth = 0;
				search.search_object = virtual_cockpit_inst3d;
				search.sub_object_index = OBJECT_3D_SUB_OBJECT_BH_VSI_NEEDLE;

				if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
				{
					search.result_sub_object->relative_roll = get_blackhawk_virtual_cockpit_vsi_needle_value ();
				}

				//
				// stabilator
				//

				search.search_depth = 0;
				search.search_object = virtual_cockpit_inst3d;
				search.sub_object_index = OBJECT_3D_SUB_OBJECT_BH_STAB_NEEDLE;

				if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
				{
					float
					stab_needle_value;

					stab_needle_value = bound((current_flight_dynamics->indicated_airspeed.value / 25 + 1.5), -10, 40);

					stab_needle_value *= rad (180.0) / 160.0;

					search.result_sub_object->relative_roll = -stab_needle_value;

					// TODO
//					if velocity < 40
//						stabilator needle at angle x
//					if velocity > 40 < 80
//						stabilator needle at angle y
//						etc etc
				}

				//
				// compass
				//

				search.search_depth = 0;
				search.search_object = virtual_cockpit_inst3d;
				search.sub_object_index = OBJECT_3D_SUB_OBJECT_APACHE_VIRTUAL_COCKPIT_COMPASS_HEADING_NULL;

				if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
				{
					search.result_sub_object->relative_heading = -current_flight_dynamics->heading.value;
				}

				//
				// clock
				//

				{
					float
						hours,
						minutes,
						seconds;

					//
					// only read clock values if drawing virtual cockpit needles to prevent speeding up clock debug values
					//

						get_blackhawk_virtual_cockpit_clock_hand_values (&hours, &minutes, &seconds);

					//
					// hour hand
					//

					search.search_depth = 0;
					search.search_object = virtual_cockpit_inst3d;
					search.sub_object_index = OBJECT_3D_SUB_OBJECT_APACHE_VIRTUAL_COCKPIT_CLOCK_HOUR_HAND;

					if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
					{
						search.result_sub_object->relative_roll = hours;
					}

					//
					// minute hand
					//

					search.search_depth = 0;
					search.search_object = virtual_cockpit_inst3d;
					search.sub_object_index = OBJECT_3D_SUB_OBJECT_APACHE_VIRTUAL_COCKPIT_CLOCK_MINUTE_HAND;

					if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
					{
						search.result_sub_object->relative_roll = minutes;
					}

					//
					// second hand
					//

					search.search_depth = 0;
					search.search_object = virtual_cockpit_inst3d;
					search.sub_object_index = OBJECT_3D_SUB_OBJECT_APACHE_VIRTUAL_COCKPIT_CLOCK_SECOND_HAND;

					if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
					{
						search.result_sub_object->relative_roll = seconds;
					}
				}
		}

		// set cockpit lights

		if (get_local_entity_int_value (get_pilot_entity (), INT_TYPE_CREW_ROLE) == CREW_ROLE_PILOT)
			mfd_light_power = (float)(get_blackhawk_mfd_mode(BLACKHAWK_MFD_LOCATION_PILOT_MAIN) % 2 + !!get_blackhawk_mfd_mode(BLACKHAWK_MFD_LOCATION_PILOT_MAIN) +
					get_blackhawk_mfd_mode(BLACKHAWK_MFD_LOCATION_CO_PILOT_MAIN) % 2 + !!get_blackhawk_mfd_mode(BLACKHAWK_MFD_LOCATION_CO_PILOT_MAIN)) / 4.0;
		else if (get_local_entity_int_value (get_pilot_entity (), INT_TYPE_CREW_ROLE) == CREW_ROLE_CO_PILOT)
			mfd_light_power = (float)(get_blackhawk_mfd_mode(BLACKHAWK_MFD_LOCATION_PILOT_MAIN) % 2 + !!get_blackhawk_mfd_mode(BLACKHAWK_MFD_LOCATION_PILOT_MAIN) +
					get_blackhawk_mfd_mode(BLACKHAWK_MFD_LOCATION_CO_PILOT_MAIN) % 2 + !!get_blackhawk_mfd_mode(BLACKHAWK_MFD_LOCATION_CO_PILOT_MAIN)) / 4.0;

		ASSERT(mfd_light_power >= 0.0 && mfd_light_power <= 1.0);
		
		if (mfd_light_power)
				{
			get_3d_transformation_matrix (m1, rad (0.0), rad (- 25.0), rad (0.0));
			multiply_matrix3x3_matrix3x3 (m2, m1, virtual_cockpit_inst3d->vp.attitude);
			
			direction.x = m2[2][0];
			direction.y = m2[2][1];
			direction.z = m2[2][2];
			
			display_backlight = create_light_3d_source (LIGHT_3D_TYPE_DIRECTIONAL, FALSE, &direction, 0, 0.1627 * mfd_light_power, 0.2039 * mfd_light_power, 0.1392 * mfd_light_power);
			insert_light_3d_source_into_3d_scene (display_backlight);
				}

		if (electrical_system_active() && cockpit_light_color_array[cockpit_light_color_index[0]])
				{
			light_colour cockpit_light_color = cockpit_light_color_table[cockpit_light_color_array[cockpit_light_color_index[0]]];

			get_3d_transformation_matrix (m1, rad (180), rad (45), 0.0);
			multiply_matrix3x3_matrix3x3 (m2, m1, virtual_cockpit_inst3d->vp.attitude);

			direction.x = m2[2][0];
			direction.y = m2[2][1];
			direction.z = m2[2][2];

			cockpit_light = create_light_3d_source (LIGHT_3D_TYPE_DIRECTIONAL, FALSE, &direction, 0, cockpit_light_color.red, cockpit_light_color.green, cockpit_light_color.blue);
			insert_light_3d_source_into_3d_scene (cockpit_light);
		}

		insert_relative_object_into_3d_scene (OBJECT_3D_DRAW_TYPE_ZBUFFERED_OBJECT, &virtual_cockpit_inst3d->vp.position, virtual_cockpit_inst3d);

		draw_3d_scene ();

		print_edit_wide_cockpit ();
		print_repairing_status();

		end_3d_scene ();

		// clear cockpit lights

		if (mfd_light_power)
		{
			remove_light_3d_source_from_3d_scene (display_backlight);
			destroy_light_3d_source (display_backlight);
			}

		if (electrical_system_active() && cockpit_light_color_array[cockpit_light_color_index[0]])
		{
			remove_light_3d_source_from_3d_scene (cockpit_light);
			destroy_light_3d_source (cockpit_light);
		}
	}

	move_edit_wide_cockpit ();

#if RECOGNITION_GUIDE
	set_3d_view_distances (main_3d_env, 10000.0, 100.0, 1.0, 0.0);
#else
	set_3d_view_distances (main_3d_env, 10000.0, 1.0, 1.0, 0.0);
#endif

		realise_3d_clip_extents (main_3d_env);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_blackhawk_crew_viewpoint (void)
		{
	object_3d_sub_object_search_data
		search_head,
		search_viewpoint;

	viewpoint
		vp;

	float
		head_pitch_datum;

			//
	// select head
			//

	if (get_local_entity_int_value (get_pilot_entity (), INT_TYPE_CREW_ROLE) == CREW_ROLE_PILOT)
	{
		search_head.sub_object_index = OBJECT_3D_SUB_OBJECT_PILOT_HEAD;

		search_viewpoint.sub_object_index = OBJECT_3D_SUB_OBJECT_PILOT_VIEWPOINT;

		head_pitch_datum = pilot_head_pitch_datum;
	}
	else
	{
		search_head.sub_object_index = OBJECT_3D_SUB_OBJECT_WSO_HEAD;

		search_viewpoint.sub_object_index = OBJECT_3D_SUB_OBJECT_WSO_VIEWPOINT;

		head_pitch_datum = co_pilot_head_pitch_datum;
	}

				//
	// rotate head
				//

	search_head.search_depth = 0;
	search_head.search_object = virtual_cockpit_inst3d;

	if (find_object_3d_sub_object (&search_head) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
				{
		search_head.result_sub_object->relative_heading = -pilot_head_heading;
		search_head.result_sub_object->relative_pitch = head_pitch_datum - pilot_head_pitch;

		if ((command_line_TIR_6DOF == TRUE)&&(query_TIR_active() == TRUE))	// Retro 6Feb2005
			search_head.result_sub_object->relative_roll = TIR_GetRoll() / 16383. * PI / 2.;	// Retro 6Feb2005
		else
			search_head.result_sub_object->relative_roll = 0.0;
				}
	else
				{
		debug_fatal ("Failed to locate crew's head in virtual cockpit");
				}

				//
	// get viewpoint (avoid jitter)
				//

	search_viewpoint.search_object = virtual_cockpit_inst3d;
	search_viewpoint.search_depth = 0;

	if (find_object_3d_sub_object (&search_viewpoint) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
				{
		virtual_cockpit_inst3d->vp.x = 0.0;
		virtual_cockpit_inst3d->vp.y = 0.0;
		virtual_cockpit_inst3d->vp.z = 0.0;

		get_local_entity_attitude_matrix (get_gunship_entity (), virtual_cockpit_inst3d->vp.attitude);

		get_3d_sub_object_world_viewpoint (&search_viewpoint, &vp);

		get_local_entity_vec3d (get_gunship_entity (), VEC3D_TYPE_POSITION, &pilot_head_vp.position);

		pilot_head_vp.x += vp.x;
		pilot_head_vp.y += vp.y;
		pilot_head_vp.z += vp.z;

		if ((command_line_TIR_6DOF == TRUE)&&(query_TIR_active() == TRUE))	// Retro 6Feb2005 (whole block)
				{
			matrix3x3 invAttitude;
			vec3d
				shiftVP, shiftWorld;

			// First lets find out the displacement the user wants.. this is in the user's viewsystem coords !!
			// Now store this info in a temp vect3d..
			shiftVP.x = current_custom_cockpit_viewpoint.x;
			shiftVP.y = current_custom_cockpit_viewpoint.y;
			shiftVP.z = current_custom_cockpit_viewpoint.z;

			// Now we need to convert our vec3d into world coords.. for this we need the inverse of the viewpoint attitude matrix..
			get_inverse_matrix (invAttitude, vp.attitude);
			// And rotate ! Voila, the result vec3d is now in world coords..
			multiply_transpose_matrix3x3_vec3d (&shiftWorld, invAttitude, &shiftVP);
			// Now apply that displacement.. BUT ONLY TO THE HEAD !!
			pilot_head_vp.x -= shiftWorld.x;
			pilot_head_vp.y -= shiftWorld.y;
			pilot_head_vp.z -= shiftWorld.z;
		}

		memcpy (pilot_head_vp.attitude, vp.attitude, sizeof (matrix3x3));

		vp.x = -vp.x;
		vp.y = -vp.y;
		vp.z = -vp.z;

		multiply_transpose_matrix3x3_vec3d (&virtual_cockpit_inst3d->vp.position, pilot_head_vp.attitude, &vp.position);

		if ((command_line_TIR_6DOF == TRUE)&&(query_TIR_active() == TRUE))	// Retro 6Feb2005 (whole block)
		{
			// Now shift the viewpoint (AND the model) by the positive displacement.. puts the cockpit back were it belongs..
			// but the viewpoint (the head) is in another place.. fini
			virtual_cockpit_inst3d->vp.x += current_custom_cockpit_viewpoint.x;
			virtual_cockpit_inst3d->vp.y += current_custom_cockpit_viewpoint.y;
			virtual_cockpit_inst3d->vp.z += current_custom_cockpit_viewpoint.z;
				}

			}
	else
	{
		debug_fatal ("Failed to locate crew's viewpoint in virtual cockpit");
		}
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void get_blackhawk_display_viewpoint (view_modes mode)
	{
	object_3d_sub_object_index_numbers
		index;

	object_3d_sub_object_search_data
		search;

	vec3d
		position;

	ASSERT (get_gunship_entity ());

	ASSERT (virtual_cockpit_inst3d);

	switch (mode)
			{
				////////////////////////////////////////
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_LHS_DISPLAY:
				////////////////////////////////////////
				{
			index = OBJECT_3D_SUB_OBJECT_COCKPIT_VIEW_MFD_FL;

					break;
				}
				////////////////////////////////////////
		case VIEW_MODE_VIRTUAL_COCKPIT_PILOT_RHS_DISPLAY:
				////////////////////////////////////////
				{
			index = OBJECT_3D_SUB_OBJECT_COCKPIT_VIEW_MFD_FR;

					break;
				}
				////////////////////////////////////////
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_LHS_DISPLAY:
				////////////////////////////////////////
				{
			index = OBJECT_3D_SUB_OBJECT_COCKPIT_VIEW_MFD_RL;

					break;
				}
				////////////////////////////////////////
		case VIEW_MODE_VIRTUAL_COCKPIT_CO_PILOT_RHS_DISPLAY:
				////////////////////////////////////////
				{
			index = OBJECT_3D_SUB_OBJECT_COCKPIT_VIEW_MFD_RR;

					break;
				}
		////////////////////////////////////////
		default:
		////////////////////////////////////////
		{
			debug_fatal ("Invalid view mode = %d", mode);

			break;
		}
	}

	virtual_cockpit_inst3d->vp.x = 0.0;
	virtual_cockpit_inst3d->vp.y = 0.0;
	virtual_cockpit_inst3d->vp.z = 0.0;

	////////////////////////////////////////
	//

	#if DEBUG_MODULE_FINE_DISPLAY_CAMERA_POSITION_ADJUSTMENT

	get_identity_matrix3x3 (virtual_cockpit_inst3d->vp.attitude);

	#else

	get_local_entity_attitude_matrix (get_gunship_entity (), virtual_cockpit_inst3d->vp.attitude);

	#endif

	//
	////////////////////////////////////////

	search.search_depth = 0;
	search.search_object = virtual_cockpit_inst3d;
	search.sub_object_index = index;

	if (find_object_3d_sub_object (&search) == SUB_OBJECT_SEARCH_RESULT_OBJECT_FOUND)
			{
		get_3d_sub_object_world_viewpoint (&search, &main_vp);
			}
			else
			{
		debug_fatal ("Failed to locate display viewpoint in virtual cockpit");
			}

	position.x = -main_vp.x;
	position.y = -main_vp.y;
	position.z = -main_vp.z;

	////////////////////////////////////////
	//

	#if DEBUG_MODULE_FINE_DISPLAY_CAMERA_POSITION_ADJUSTMENT
	{
		static float
			z_offset = 0.0;

		float
			dx,
			dy,
			dz;

		if (check_key (DIK_Q))
				{
			z_offset -= 0.0001;
			}

		if (check_key (DIK_A))
				{
			z_offset += 0.0001;
				}

		dx = main_vp.zv.x * z_offset;
		dy = main_vp.zv.y * z_offset;
		dz = main_vp.zv.z * z_offset;

		position.x += dx;
		position.y += dy;
		position.z += dz;

		debug_filtered_log ("offset=%.6f x=%.6f y=%.6f z=%.6f", z_offset, position.x, position.y, position.z);
	}
#endif

	//
	////////////////////////////////////////

	multiply_transpose_matrix3x3_vec3d (&virtual_cockpit_inst3d->vp.position, main_vp.attitude, &position);

	get_local_entity_vec3d (get_gunship_entity (), VEC3D_TYPE_POSITION, &position);

	main_vp.x += position.x;
	main_vp.y += position.y;
	main_vp.z += position.z;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void update_master_warning_lamps (void)
{
	eng1_out_lamp->visible_object = blackhawk_lamps.eng1_out;
	eng2_out_lamp->visible_object = blackhawk_lamps.eng2_out;
	low_rtr_rpm_lamp->visible_object = blackhawk_lamps.rotor_rpm;
	fire_lamp->visible_object = blackhawk_lamps.engine_fire;
	master_caution_lamp->visible_object = blackhawk_lamps.master_caution;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_rtr_rpm_display (void)
{
	// Pilot Display Unit
	// Red LEDs
	rtr_rpm_red_led1->visible_object = blackhawk_lamps.rtr_rpm_red_led1;
	rtr_rpm_red_led2->visible_object = blackhawk_lamps.rtr_rpm_red_led2;
	rtr_rpm_red_led3->visible_object = blackhawk_lamps.rtr_rpm_red_led3;
	rtr_rpm_red_led4->visible_object = blackhawk_lamps.rtr_rpm_red_led4;
	rtr_rpm_red_led5->visible_object = blackhawk_lamps.rtr_rpm_red_led5;
	rtr_rpm_red_led6->visible_object = blackhawk_lamps.rtr_rpm_red_led6;
	rtr_rpm_red_led7->visible_object = blackhawk_lamps.rtr_rpm_red_led7;
	rtr_rpm_red_led8->visible_object = blackhawk_lamps.rtr_rpm_red_led8;
	rtr_rpm_red_led9->visible_object = blackhawk_lamps.rtr_rpm_red_led9;
	rtr_rpm_red_led10->visible_object = blackhawk_lamps.rtr_rpm_red_led10;
	rtr_rpm_red_led11->visible_object = blackhawk_lamps.rtr_rpm_red_led11;
	rtr_rpm_red_led12->visible_object = blackhawk_lamps.rtr_rpm_red_led12;
	rtr_rpm_red_led13->visible_object = blackhawk_lamps.rtr_rpm_red_led13;
	rtr_rpm_red_led14->visible_object = blackhawk_lamps.rtr_rpm_red_led14;
	rtr_rpm_red_led15->visible_object = blackhawk_lamps.rtr_rpm_red_led15;
	rtr_rpm_red_led16->visible_object = blackhawk_lamps.rtr_rpm_red_led16;
	rtr_rpm_red_led17->visible_object = blackhawk_lamps.rtr_rpm_red_led17;
	rtr_rpm_red_led18->visible_object = blackhawk_lamps.rtr_rpm_red_led18;
	rtr_rpm_red_led19->visible_object = blackhawk_lamps.rtr_rpm_red_led19;
	rtr_rpm_red_led20->visible_object = blackhawk_lamps.rtr_rpm_red_led20;
	rtr_rpm_red_led21->visible_object = blackhawk_lamps.rtr_rpm_red_led21;
	rtr_rpm_red_led22->visible_object = blackhawk_lamps.rtr_rpm_red_led22;
	rtr_rpm_red_led23->visible_object = blackhawk_lamps.rtr_rpm_red_led23;
	rtr_rpm_red_led24->visible_object = blackhawk_lamps.rtr_rpm_red_led24;
	rtr_rpm_red_led25->visible_object = blackhawk_lamps.rtr_rpm_red_led25;
	rtr_rpm_red_led26->visible_object = blackhawk_lamps.rtr_rpm_red_led26;
	rtr_rpm_red_led27->visible_object = blackhawk_lamps.rtr_rpm_red_led27;
	// Yellow LEDs
	rtr_rpm_yellow_led1->visible_object = blackhawk_lamps.rtr_rpm_yellow_led1;
	rtr_rpm_yellow_led2->visible_object = blackhawk_lamps.rtr_rpm_yellow_led2;
	rtr_rpm_yellow_led3->visible_object = blackhawk_lamps.rtr_rpm_yellow_led3;
	rtr_rpm_yellow_led4->visible_object = blackhawk_lamps.rtr_rpm_yellow_led4;
	rtr_rpm_yellow_led5->visible_object = blackhawk_lamps.rtr_rpm_yellow_led5;
	rtr_rpm_yellow_led6->visible_object = blackhawk_lamps.rtr_rpm_yellow_led6;
	rtr_rpm_yellow_led7->visible_object = blackhawk_lamps.rtr_rpm_yellow_led7;
	rtr_rpm_yellow_led8->visible_object = blackhawk_lamps.rtr_rpm_yellow_led8;
	rtr_rpm_yellow_led9->visible_object = blackhawk_lamps.rtr_rpm_yellow_led9;
	// Green LEDs
	rtr_rpm_green_led1->visible_object = blackhawk_lamps.rtr_rpm_green_led1;
	rtr_rpm_green_led2->visible_object = blackhawk_lamps.rtr_rpm_green_led2;
	rtr_rpm_green_led3->visible_object = blackhawk_lamps.rtr_rpm_green_led3;
	rtr_rpm_green_led4->visible_object = blackhawk_lamps.rtr_rpm_green_led4;
	rtr_rpm_green_led5->visible_object = blackhawk_lamps.rtr_rpm_green_led5;

	// Co-Pilot Display Unit
	// Red LEDs
	cp_rtr_rpm_red_led1->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led1;
	cp_rtr_rpm_red_led2->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led2;
	cp_rtr_rpm_red_led3->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led3;
	cp_rtr_rpm_red_led4->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led4;
	cp_rtr_rpm_red_led5->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led5;
	cp_rtr_rpm_red_led6->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led6;
	cp_rtr_rpm_red_led7->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led7;
	cp_rtr_rpm_red_led8->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led8;
	cp_rtr_rpm_red_led9->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led9;
	cp_rtr_rpm_red_led10->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led10;
	cp_rtr_rpm_red_led11->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led11;
	cp_rtr_rpm_red_led12->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led12;
	cp_rtr_rpm_red_led13->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led13;
	cp_rtr_rpm_red_led14->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led14;
	cp_rtr_rpm_red_led15->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led15;
	cp_rtr_rpm_red_led16->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led16;
	cp_rtr_rpm_red_led17->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led17;
	cp_rtr_rpm_red_led18->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led18;
	cp_rtr_rpm_red_led19->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led19;
	cp_rtr_rpm_red_led20->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led20;
	cp_rtr_rpm_red_led21->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led21;
	cp_rtr_rpm_red_led22->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led22;
	cp_rtr_rpm_red_led23->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led23;
	cp_rtr_rpm_red_led24->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led24;
	cp_rtr_rpm_red_led25->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led25;
	cp_rtr_rpm_red_led26->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led26;
	cp_rtr_rpm_red_led27->visible_object = blackhawk_lamps.cp_rtr_rpm_red_led27;
	// Yellow LEDs
	cp_rtr_rpm_yellow_led1->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led1;
	cp_rtr_rpm_yellow_led2->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led2;
	cp_rtr_rpm_yellow_led3->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led3;
	cp_rtr_rpm_yellow_led4->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led4;
	cp_rtr_rpm_yellow_led5->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led5;
	cp_rtr_rpm_yellow_led6->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led6;
	cp_rtr_rpm_yellow_led7->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led7;
	cp_rtr_rpm_yellow_led8->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led8;
	cp_rtr_rpm_yellow_led9->visible_object = blackhawk_lamps.cp_rtr_rpm_yellow_led9;
	// Green LEDs
	cp_rtr_rpm_green_led1->visible_object = blackhawk_lamps.cp_rtr_rpm_green_led1;
	cp_rtr_rpm_green_led2->visible_object = blackhawk_lamps.cp_rtr_rpm_green_led2;
	cp_rtr_rpm_green_led3->visible_object = blackhawk_lamps.cp_rtr_rpm_green_led3;
	cp_rtr_rpm_green_led4->visible_object = blackhawk_lamps.cp_rtr_rpm_green_led4;
	cp_rtr_rpm_green_led5->visible_object = blackhawk_lamps.cp_rtr_rpm_green_led5;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_leng_rpm_display (void)
{
	// Pilot Display Unit
	// Red LEDs
	leng_rpm_red_led1->visible_object = blackhawk_lamps.leng_rpm_red_led1;
	leng_rpm_red_led2->visible_object = blackhawk_lamps.leng_rpm_red_led2;
	leng_rpm_red_led3->visible_object = blackhawk_lamps.leng_rpm_red_led3;
	leng_rpm_red_led4->visible_object = blackhawk_lamps.leng_rpm_red_led4;
	leng_rpm_red_led5->visible_object = blackhawk_lamps.leng_rpm_red_led5;
	leng_rpm_red_led6->visible_object = blackhawk_lamps.leng_rpm_red_led6;
	leng_rpm_red_led7->visible_object = blackhawk_lamps.leng_rpm_red_led7;
	leng_rpm_red_led8->visible_object = blackhawk_lamps.leng_rpm_red_led8;
	leng_rpm_red_led9->visible_object = blackhawk_lamps.leng_rpm_red_led9;
	leng_rpm_red_led10->visible_object = blackhawk_lamps.leng_rpm_red_led10;
	leng_rpm_red_led11->visible_object = blackhawk_lamps.leng_rpm_red_led11;
	leng_rpm_red_led12->visible_object = blackhawk_lamps.leng_rpm_red_led12;
	leng_rpm_red_led13->visible_object = blackhawk_lamps.leng_rpm_red_led13;
	leng_rpm_red_led14->visible_object = blackhawk_lamps.leng_rpm_red_led14;
	leng_rpm_red_led15->visible_object = blackhawk_lamps.leng_rpm_red_led15;
	leng_rpm_red_led16->visible_object = blackhawk_lamps.leng_rpm_red_led16;
	leng_rpm_red_led17->visible_object = blackhawk_lamps.leng_rpm_red_led17;
	leng_rpm_red_led18->visible_object = blackhawk_lamps.leng_rpm_red_led18;
	leng_rpm_red_led19->visible_object = blackhawk_lamps.leng_rpm_red_led19;
	leng_rpm_red_led20->visible_object = blackhawk_lamps.leng_rpm_red_led20;
	leng_rpm_red_led21->visible_object = blackhawk_lamps.leng_rpm_red_led21;
	leng_rpm_red_led22->visible_object = blackhawk_lamps.leng_rpm_red_led22;
	leng_rpm_red_led23->visible_object = blackhawk_lamps.leng_rpm_red_led23;
	leng_rpm_red_led24->visible_object = blackhawk_lamps.leng_rpm_red_led24;
	leng_rpm_red_led25->visible_object = blackhawk_lamps.leng_rpm_red_led25;
	leng_rpm_red_led26->visible_object = blackhawk_lamps.leng_rpm_red_led26;
	leng_rpm_red_led27->visible_object = blackhawk_lamps.leng_rpm_red_led27;
	// Yellow LEDs
	leng_rpm_yellow_led1->visible_object = blackhawk_lamps.leng_rpm_yellow_led1;
	leng_rpm_yellow_led2->visible_object = blackhawk_lamps.leng_rpm_yellow_led2;
	leng_rpm_yellow_led3->visible_object = blackhawk_lamps.leng_rpm_yellow_led3;
	leng_rpm_yellow_led4->visible_object = blackhawk_lamps.leng_rpm_yellow_led4;
	leng_rpm_yellow_led5->visible_object = blackhawk_lamps.leng_rpm_yellow_led5;
	leng_rpm_yellow_led6->visible_object = blackhawk_lamps.leng_rpm_yellow_led6;
	leng_rpm_yellow_led7->visible_object = blackhawk_lamps.leng_rpm_yellow_led7;
	leng_rpm_yellow_led8->visible_object = blackhawk_lamps.leng_rpm_yellow_led8;
	leng_rpm_yellow_led9->visible_object = blackhawk_lamps.leng_rpm_yellow_led9;
	// Green LEDs
	leng_rpm_green_led1->visible_object = blackhawk_lamps.leng_rpm_green_led1;
	leng_rpm_green_led2->visible_object = blackhawk_lamps.leng_rpm_green_led2;
	leng_rpm_green_led3->visible_object = blackhawk_lamps.leng_rpm_green_led3;
	leng_rpm_green_led4->visible_object = blackhawk_lamps.leng_rpm_green_led4;
	leng_rpm_green_led5->visible_object = blackhawk_lamps.leng_rpm_green_led5;

	// Co-Pilot Display Unit
	// Red LEDs
	cp_leng_rpm_red_led1->visible_object = blackhawk_lamps.cp_leng_rpm_red_led1;
	cp_leng_rpm_red_led2->visible_object = blackhawk_lamps.cp_leng_rpm_red_led2;
	cp_leng_rpm_red_led3->visible_object = blackhawk_lamps.cp_leng_rpm_red_led3;
	cp_leng_rpm_red_led4->visible_object = blackhawk_lamps.cp_leng_rpm_red_led4;
	cp_leng_rpm_red_led5->visible_object = blackhawk_lamps.cp_leng_rpm_red_led5;
	cp_leng_rpm_red_led6->visible_object = blackhawk_lamps.cp_leng_rpm_red_led6;
	cp_leng_rpm_red_led7->visible_object = blackhawk_lamps.cp_leng_rpm_red_led7;
	cp_leng_rpm_red_led8->visible_object = blackhawk_lamps.cp_leng_rpm_red_led8;
	cp_leng_rpm_red_led9->visible_object = blackhawk_lamps.cp_leng_rpm_red_led9;
	cp_leng_rpm_red_led10->visible_object = blackhawk_lamps.cp_leng_rpm_red_led10;
	cp_leng_rpm_red_led11->visible_object = blackhawk_lamps.cp_leng_rpm_red_led11;
	cp_leng_rpm_red_led12->visible_object = blackhawk_lamps.cp_leng_rpm_red_led12;
	cp_leng_rpm_red_led13->visible_object = blackhawk_lamps.cp_leng_rpm_red_led13;
	cp_leng_rpm_red_led14->visible_object = blackhawk_lamps.cp_leng_rpm_red_led14;
	cp_leng_rpm_red_led15->visible_object = blackhawk_lamps.cp_leng_rpm_red_led15;
	cp_leng_rpm_red_led16->visible_object = blackhawk_lamps.cp_leng_rpm_red_led16;
	cp_leng_rpm_red_led17->visible_object = blackhawk_lamps.cp_leng_rpm_red_led17;
	cp_leng_rpm_red_led18->visible_object = blackhawk_lamps.cp_leng_rpm_red_led18;
	cp_leng_rpm_red_led19->visible_object = blackhawk_lamps.cp_leng_rpm_red_led19;
	cp_leng_rpm_red_led20->visible_object = blackhawk_lamps.cp_leng_rpm_red_led20;
	cp_leng_rpm_red_led21->visible_object = blackhawk_lamps.cp_leng_rpm_red_led21;
	cp_leng_rpm_red_led22->visible_object = blackhawk_lamps.cp_leng_rpm_red_led22;
	cp_leng_rpm_red_led23->visible_object = blackhawk_lamps.cp_leng_rpm_red_led23;
	cp_leng_rpm_red_led24->visible_object = blackhawk_lamps.cp_leng_rpm_red_led24;
	cp_leng_rpm_red_led25->visible_object = blackhawk_lamps.cp_leng_rpm_red_led25;
	cp_leng_rpm_red_led26->visible_object = blackhawk_lamps.cp_leng_rpm_red_led26;
	cp_leng_rpm_red_led27->visible_object = blackhawk_lamps.cp_leng_rpm_red_led27;
	// Yellow LEDs
	cp_leng_rpm_yellow_led1->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led1;
	cp_leng_rpm_yellow_led2->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led2;
	cp_leng_rpm_yellow_led3->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led3;
	cp_leng_rpm_yellow_led4->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led4;
	cp_leng_rpm_yellow_led5->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led5;
	cp_leng_rpm_yellow_led6->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led6;
	cp_leng_rpm_yellow_led7->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led7;
	cp_leng_rpm_yellow_led8->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led8;
	cp_leng_rpm_yellow_led9->visible_object = blackhawk_lamps.cp_leng_rpm_yellow_led9;
	// Green LEDs
	cp_leng_rpm_green_led1->visible_object = blackhawk_lamps.cp_leng_rpm_green_led1;
	cp_leng_rpm_green_led2->visible_object = blackhawk_lamps.cp_leng_rpm_green_led2;
	cp_leng_rpm_green_led3->visible_object = blackhawk_lamps.cp_leng_rpm_green_led3;
	cp_leng_rpm_green_led4->visible_object = blackhawk_lamps.cp_leng_rpm_green_led4;
	cp_leng_rpm_green_led5->visible_object = blackhawk_lamps.cp_leng_rpm_green_led5;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_reng_rpm_display (void)
{
	// Pilot Display Unit
	// Red LEDs
	reng_rpm_red_led1->visible_object = blackhawk_lamps.reng_rpm_red_led1;
	reng_rpm_red_led2->visible_object = blackhawk_lamps.reng_rpm_red_led2;
	reng_rpm_red_led3->visible_object = blackhawk_lamps.reng_rpm_red_led3;
	reng_rpm_red_led4->visible_object = blackhawk_lamps.reng_rpm_red_led4;
	reng_rpm_red_led5->visible_object = blackhawk_lamps.reng_rpm_red_led5;
	reng_rpm_red_led6->visible_object = blackhawk_lamps.reng_rpm_red_led6;
	reng_rpm_red_led7->visible_object = blackhawk_lamps.reng_rpm_red_led7;
	reng_rpm_red_led8->visible_object = blackhawk_lamps.reng_rpm_red_led8;
	reng_rpm_red_led9->visible_object = blackhawk_lamps.reng_rpm_red_led9;
	reng_rpm_red_led10->visible_object = blackhawk_lamps.reng_rpm_red_led10;
	reng_rpm_red_led11->visible_object = blackhawk_lamps.reng_rpm_red_led11;
	reng_rpm_red_led12->visible_object = blackhawk_lamps.reng_rpm_red_led12;
	reng_rpm_red_led13->visible_object = blackhawk_lamps.reng_rpm_red_led13;
	reng_rpm_red_led14->visible_object = blackhawk_lamps.reng_rpm_red_led14;
	reng_rpm_red_led15->visible_object = blackhawk_lamps.reng_rpm_red_led15;
	reng_rpm_red_led16->visible_object = blackhawk_lamps.reng_rpm_red_led16;
	reng_rpm_red_led17->visible_object = blackhawk_lamps.reng_rpm_red_led17;
	reng_rpm_red_led18->visible_object = blackhawk_lamps.reng_rpm_red_led18;
	reng_rpm_red_led19->visible_object = blackhawk_lamps.reng_rpm_red_led19;
	reng_rpm_red_led20->visible_object = blackhawk_lamps.reng_rpm_red_led20;
	reng_rpm_red_led21->visible_object = blackhawk_lamps.reng_rpm_red_led21;
	reng_rpm_red_led22->visible_object = blackhawk_lamps.reng_rpm_red_led22;
	reng_rpm_red_led23->visible_object = blackhawk_lamps.reng_rpm_red_led23;
	reng_rpm_red_led24->visible_object = blackhawk_lamps.reng_rpm_red_led24;
	reng_rpm_red_led25->visible_object = blackhawk_lamps.reng_rpm_red_led25;
	reng_rpm_red_led26->visible_object = blackhawk_lamps.reng_rpm_red_led26;
	reng_rpm_red_led27->visible_object = blackhawk_lamps.reng_rpm_red_led27;
	// Yellow LEDs
	reng_rpm_yellow_led1->visible_object = blackhawk_lamps.reng_rpm_yellow_led1;
	reng_rpm_yellow_led2->visible_object = blackhawk_lamps.reng_rpm_yellow_led2;
	reng_rpm_yellow_led3->visible_object = blackhawk_lamps.reng_rpm_yellow_led3;
	reng_rpm_yellow_led4->visible_object = blackhawk_lamps.reng_rpm_yellow_led4;
	reng_rpm_yellow_led5->visible_object = blackhawk_lamps.reng_rpm_yellow_led5;
	reng_rpm_yellow_led6->visible_object = blackhawk_lamps.reng_rpm_yellow_led6;
	reng_rpm_yellow_led7->visible_object = blackhawk_lamps.reng_rpm_yellow_led7;
	reng_rpm_yellow_led8->visible_object = blackhawk_lamps.reng_rpm_yellow_led8;
	reng_rpm_yellow_led9->visible_object = blackhawk_lamps.reng_rpm_yellow_led9;
	// Green LEDs
	reng_rpm_green_led1->visible_object = blackhawk_lamps.reng_rpm_green_led1;
	reng_rpm_green_led2->visible_object = blackhawk_lamps.reng_rpm_green_led2;
	reng_rpm_green_led3->visible_object = blackhawk_lamps.reng_rpm_green_led3;
	reng_rpm_green_led4->visible_object = blackhawk_lamps.reng_rpm_green_led4;
	reng_rpm_green_led5->visible_object = blackhawk_lamps.reng_rpm_green_led5;

	// Co-Pilot Display Unit
	// Red LEDs
	cp_reng_rpm_red_led1->visible_object = blackhawk_lamps.cp_reng_rpm_red_led1;
	cp_reng_rpm_red_led2->visible_object = blackhawk_lamps.cp_reng_rpm_red_led2;
	cp_reng_rpm_red_led3->visible_object = blackhawk_lamps.cp_reng_rpm_red_led3;
	cp_reng_rpm_red_led4->visible_object = blackhawk_lamps.cp_reng_rpm_red_led4;
	cp_reng_rpm_red_led5->visible_object = blackhawk_lamps.cp_reng_rpm_red_led5;
	cp_reng_rpm_red_led6->visible_object = blackhawk_lamps.cp_reng_rpm_red_led6;
	cp_reng_rpm_red_led7->visible_object = blackhawk_lamps.cp_reng_rpm_red_led7;
	cp_reng_rpm_red_led8->visible_object = blackhawk_lamps.cp_reng_rpm_red_led8;
	cp_reng_rpm_red_led9->visible_object = blackhawk_lamps.cp_reng_rpm_red_led9;
	cp_reng_rpm_red_led10->visible_object = blackhawk_lamps.cp_reng_rpm_red_led10;
	cp_reng_rpm_red_led11->visible_object = blackhawk_lamps.cp_reng_rpm_red_led11;
	cp_reng_rpm_red_led12->visible_object = blackhawk_lamps.cp_reng_rpm_red_led12;
	cp_reng_rpm_red_led13->visible_object = blackhawk_lamps.cp_reng_rpm_red_led13;
	cp_reng_rpm_red_led14->visible_object = blackhawk_lamps.cp_reng_rpm_red_led14;
	cp_reng_rpm_red_led15->visible_object = blackhawk_lamps.cp_reng_rpm_red_led15;
	cp_reng_rpm_red_led16->visible_object = blackhawk_lamps.cp_reng_rpm_red_led16;
	cp_reng_rpm_red_led17->visible_object = blackhawk_lamps.cp_reng_rpm_red_led17;
	cp_reng_rpm_red_led18->visible_object = blackhawk_lamps.cp_reng_rpm_red_led18;
	cp_reng_rpm_red_led19->visible_object = blackhawk_lamps.cp_reng_rpm_red_led19;
	cp_reng_rpm_red_led20->visible_object = blackhawk_lamps.cp_reng_rpm_red_led20;
	cp_reng_rpm_red_led21->visible_object = blackhawk_lamps.cp_reng_rpm_red_led21;
	cp_reng_rpm_red_led22->visible_object = blackhawk_lamps.cp_reng_rpm_red_led22;
	cp_reng_rpm_red_led23->visible_object = blackhawk_lamps.cp_reng_rpm_red_led23;
	cp_reng_rpm_red_led24->visible_object = blackhawk_lamps.cp_reng_rpm_red_led24;
	cp_reng_rpm_red_led25->visible_object = blackhawk_lamps.cp_reng_rpm_red_led25;
	cp_reng_rpm_red_led26->visible_object = blackhawk_lamps.cp_reng_rpm_red_led26;
	cp_reng_rpm_red_led27->visible_object = blackhawk_lamps.cp_reng_rpm_red_led27;
	// Yellow LEDs
	cp_reng_rpm_yellow_led1->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led1;
	cp_reng_rpm_yellow_led2->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led2;
	cp_reng_rpm_yellow_led3->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led3;
	cp_reng_rpm_yellow_led4->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led4;
	cp_reng_rpm_yellow_led5->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led5;
	cp_reng_rpm_yellow_led6->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led6;
	cp_reng_rpm_yellow_led7->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led7;
	cp_reng_rpm_yellow_led8->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led8;
	cp_reng_rpm_yellow_led9->visible_object = blackhawk_lamps.cp_reng_rpm_yellow_led9;
	// Green LEDs
	cp_reng_rpm_green_led1->visible_object = blackhawk_lamps.cp_reng_rpm_green_led1;
	cp_reng_rpm_green_led2->visible_object = blackhawk_lamps.cp_reng_rpm_green_led2;
	cp_reng_rpm_green_led3->visible_object = blackhawk_lamps.cp_reng_rpm_green_led3;
	cp_reng_rpm_green_led4->visible_object = blackhawk_lamps.cp_reng_rpm_green_led4;
	cp_reng_rpm_green_led5->visible_object = blackhawk_lamps.cp_reng_rpm_green_led5;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_leng_trq_display(void)
{
	// Pilot Display Unit
	// Green LEDS
	leng_trq_green_led1->visible_object = blackhawk_lamps.leng_trq_green_led1;
	leng_trq_green_led2->visible_object = blackhawk_lamps.leng_trq_green_led2;
	leng_trq_green_led3->visible_object = blackhawk_lamps.leng_trq_green_led3;
	leng_trq_green_led4->visible_object = blackhawk_lamps.leng_trq_green_led4;
	leng_trq_green_led5->visible_object = blackhawk_lamps.leng_trq_green_led5;
	leng_trq_green_led6->visible_object = blackhawk_lamps.leng_trq_green_led6;
	leng_trq_green_led7->visible_object = blackhawk_lamps.leng_trq_green_led7;
	leng_trq_green_led8->visible_object = blackhawk_lamps.leng_trq_green_led8;
	leng_trq_green_led9->visible_object = blackhawk_lamps.leng_trq_green_led9;
	leng_trq_green_led10->visible_object = blackhawk_lamps.leng_trq_green_led10;
	leng_trq_green_led11->visible_object = blackhawk_lamps.leng_trq_green_led11;
	leng_trq_green_led12->visible_object = blackhawk_lamps.leng_trq_green_led12;
	leng_trq_green_led13->visible_object = blackhawk_lamps.leng_trq_green_led13;
	leng_trq_green_led14->visible_object = blackhawk_lamps.leng_trq_green_led14;
	leng_trq_green_led15->visible_object = blackhawk_lamps.leng_trq_green_led15;
	leng_trq_green_led16->visible_object = blackhawk_lamps.leng_trq_green_led16;
	leng_trq_green_led17->visible_object = blackhawk_lamps.leng_trq_green_led17;
	leng_trq_green_led18->visible_object = blackhawk_lamps.leng_trq_green_led18;
	leng_trq_green_led19->visible_object = blackhawk_lamps.leng_trq_green_led19;
	leng_trq_green_led20->visible_object = blackhawk_lamps.leng_trq_green_led20;
	// Yellow LEDs
	leng_trq_yellow_led1->visible_object = blackhawk_lamps.leng_trq_yellow_led1;
	leng_trq_yellow_led2->visible_object = blackhawk_lamps.leng_trq_yellow_led2;
	leng_trq_yellow_led3->visible_object = blackhawk_lamps.leng_trq_yellow_led3;
	leng_trq_yellow_led4->visible_object = blackhawk_lamps.leng_trq_yellow_led4;
	leng_trq_yellow_led5->visible_object = blackhawk_lamps.leng_trq_yellow_led5;
	leng_trq_yellow_led6->visible_object = blackhawk_lamps.leng_trq_yellow_led6;
	// Red LEDs
	leng_trq_red_led1->visible_object = blackhawk_lamps.leng_trq_red_led1;
	leng_trq_red_led2->visible_object = blackhawk_lamps.leng_trq_red_led2;
	leng_trq_red_led3->visible_object = blackhawk_lamps.leng_trq_red_led3;
	leng_trq_red_led4->visible_object = blackhawk_lamps.leng_trq_red_led4;

	// Co-Pilot Display Unit
	// Green LEDS
	cp_leng_trq_green_led1->visible_object = blackhawk_lamps.cp_leng_trq_green_led1;
	cp_leng_trq_green_led2->visible_object = blackhawk_lamps.cp_leng_trq_green_led2;
	cp_leng_trq_green_led3->visible_object = blackhawk_lamps.cp_leng_trq_green_led3;
	cp_leng_trq_green_led4->visible_object = blackhawk_lamps.cp_leng_trq_green_led4;
	cp_leng_trq_green_led5->visible_object = blackhawk_lamps.cp_leng_trq_green_led5;
	cp_leng_trq_green_led6->visible_object = blackhawk_lamps.cp_leng_trq_green_led6;
	cp_leng_trq_green_led7->visible_object = blackhawk_lamps.cp_leng_trq_green_led7;
	cp_leng_trq_green_led8->visible_object = blackhawk_lamps.cp_leng_trq_green_led8;
	cp_leng_trq_green_led9->visible_object = blackhawk_lamps.cp_leng_trq_green_led9;
	cp_leng_trq_green_led10->visible_object = blackhawk_lamps.cp_leng_trq_green_led10;
	cp_leng_trq_green_led11->visible_object = blackhawk_lamps.cp_leng_trq_green_led11;
	cp_leng_trq_green_led12->visible_object = blackhawk_lamps.cp_leng_trq_green_led12;
	cp_leng_trq_green_led13->visible_object = blackhawk_lamps.cp_leng_trq_green_led13;
	cp_leng_trq_green_led14->visible_object = blackhawk_lamps.cp_leng_trq_green_led14;
	cp_leng_trq_green_led15->visible_object = blackhawk_lamps.cp_leng_trq_green_led15;
	cp_leng_trq_green_led16->visible_object = blackhawk_lamps.cp_leng_trq_green_led16;
	cp_leng_trq_green_led17->visible_object = blackhawk_lamps.cp_leng_trq_green_led17;
	cp_leng_trq_green_led18->visible_object = blackhawk_lamps.cp_leng_trq_green_led18;
	cp_leng_trq_green_led19->visible_object = blackhawk_lamps.cp_leng_trq_green_led19;
	cp_leng_trq_green_led20->visible_object = blackhawk_lamps.cp_leng_trq_green_led20;
	// Yellow LEDs
	cp_leng_trq_yellow_led1->visible_object = blackhawk_lamps.cp_leng_trq_yellow_led1;
	cp_leng_trq_yellow_led2->visible_object = blackhawk_lamps.cp_leng_trq_yellow_led2;
	cp_leng_trq_yellow_led3->visible_object = blackhawk_lamps.cp_leng_trq_yellow_led3;
	cp_leng_trq_yellow_led4->visible_object = blackhawk_lamps.cp_leng_trq_yellow_led4;
	cp_leng_trq_yellow_led5->visible_object = blackhawk_lamps.cp_leng_trq_yellow_led5;
	cp_leng_trq_yellow_led6->visible_object = blackhawk_lamps.cp_leng_trq_yellow_led6;
	// Red LEDs
	cp_leng_trq_red_led1->visible_object = blackhawk_lamps.cp_leng_trq_red_led1;
	cp_leng_trq_red_led2->visible_object = blackhawk_lamps.cp_leng_trq_red_led2;
	cp_leng_trq_red_led3->visible_object = blackhawk_lamps.cp_leng_trq_red_led3;
	cp_leng_trq_red_led4->visible_object = blackhawk_lamps.cp_leng_trq_red_led4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_reng_trq_display(void)
{
	// Pilot Display Unit
	// Green LEDS
	reng_trq_green_led1->visible_object = blackhawk_lamps.reng_trq_green_led1;
	reng_trq_green_led2->visible_object = blackhawk_lamps.reng_trq_green_led2;
	reng_trq_green_led3->visible_object = blackhawk_lamps.reng_trq_green_led3;
	reng_trq_green_led4->visible_object = blackhawk_lamps.reng_trq_green_led4;
	reng_trq_green_led5->visible_object = blackhawk_lamps.reng_trq_green_led5;
	reng_trq_green_led6->visible_object = blackhawk_lamps.reng_trq_green_led6;
	reng_trq_green_led7->visible_object = blackhawk_lamps.reng_trq_green_led7;
	reng_trq_green_led8->visible_object = blackhawk_lamps.reng_trq_green_led8;
	reng_trq_green_led9->visible_object = blackhawk_lamps.reng_trq_green_led9;
	reng_trq_green_led10->visible_object = blackhawk_lamps.reng_trq_green_led10;
	reng_trq_green_led11->visible_object = blackhawk_lamps.reng_trq_green_led11;
	reng_trq_green_led12->visible_object = blackhawk_lamps.reng_trq_green_led12;
	reng_trq_green_led13->visible_object = blackhawk_lamps.reng_trq_green_led13;
	reng_trq_green_led14->visible_object = blackhawk_lamps.reng_trq_green_led14;
	reng_trq_green_led15->visible_object = blackhawk_lamps.reng_trq_green_led15;
	reng_trq_green_led16->visible_object = blackhawk_lamps.reng_trq_green_led16;
	reng_trq_green_led17->visible_object = blackhawk_lamps.reng_trq_green_led17;
	reng_trq_green_led18->visible_object = blackhawk_lamps.reng_trq_green_led18;
	reng_trq_green_led19->visible_object = blackhawk_lamps.reng_trq_green_led19;
	reng_trq_green_led20->visible_object = blackhawk_lamps.reng_trq_green_led20;
	// Yellow LEDs
	reng_trq_yellow_led1->visible_object = blackhawk_lamps.reng_trq_yellow_led1;
	reng_trq_yellow_led2->visible_object = blackhawk_lamps.reng_trq_yellow_led2;
	reng_trq_yellow_led3->visible_object = blackhawk_lamps.reng_trq_yellow_led3;
	reng_trq_yellow_led4->visible_object = blackhawk_lamps.reng_trq_yellow_led4;
	reng_trq_yellow_led5->visible_object = blackhawk_lamps.reng_trq_yellow_led5;
	reng_trq_yellow_led6->visible_object = blackhawk_lamps.reng_trq_yellow_led6;
	// Red LEDs
	reng_trq_red_led1->visible_object = blackhawk_lamps.reng_trq_red_led1;
	reng_trq_red_led2->visible_object = blackhawk_lamps.reng_trq_red_led2;
	reng_trq_red_led3->visible_object = blackhawk_lamps.reng_trq_red_led3;
	reng_trq_red_led4->visible_object = blackhawk_lamps.reng_trq_red_led4;

	// Co-Pilot Display Unit
	// Green LEDS
	cp_reng_trq_green_led1->visible_object = blackhawk_lamps.cp_reng_trq_green_led1;
	cp_reng_trq_green_led2->visible_object = blackhawk_lamps.cp_reng_trq_green_led2;
	cp_reng_trq_green_led3->visible_object = blackhawk_lamps.cp_reng_trq_green_led3;
	cp_reng_trq_green_led4->visible_object = blackhawk_lamps.cp_reng_trq_green_led4;
	cp_reng_trq_green_led5->visible_object = blackhawk_lamps.cp_reng_trq_green_led5;
	cp_reng_trq_green_led6->visible_object = blackhawk_lamps.cp_reng_trq_green_led6;
	cp_reng_trq_green_led7->visible_object = blackhawk_lamps.cp_reng_trq_green_led7;
	cp_reng_trq_green_led8->visible_object = blackhawk_lamps.cp_reng_trq_green_led8;
	cp_reng_trq_green_led9->visible_object = blackhawk_lamps.cp_reng_trq_green_led9;
	cp_reng_trq_green_led10->visible_object = blackhawk_lamps.cp_reng_trq_green_led10;
	cp_reng_trq_green_led11->visible_object = blackhawk_lamps.cp_reng_trq_green_led11;
	cp_reng_trq_green_led12->visible_object = blackhawk_lamps.cp_reng_trq_green_led12;
	cp_reng_trq_green_led13->visible_object = blackhawk_lamps.cp_reng_trq_green_led13;
	cp_reng_trq_green_led14->visible_object = blackhawk_lamps.cp_reng_trq_green_led14;
	cp_reng_trq_green_led15->visible_object = blackhawk_lamps.cp_reng_trq_green_led15;
	cp_reng_trq_green_led16->visible_object = blackhawk_lamps.cp_reng_trq_green_led16;
	cp_reng_trq_green_led17->visible_object = blackhawk_lamps.cp_reng_trq_green_led17;
	cp_reng_trq_green_led18->visible_object = blackhawk_lamps.cp_reng_trq_green_led18;
	cp_reng_trq_green_led19->visible_object = blackhawk_lamps.cp_reng_trq_green_led19;
	cp_reng_trq_green_led20->visible_object = blackhawk_lamps.cp_reng_trq_green_led20;
	// Yellow LEDs
	cp_reng_trq_yellow_led1->visible_object = blackhawk_lamps.cp_reng_trq_yellow_led1;
	cp_reng_trq_yellow_led2->visible_object = blackhawk_lamps.cp_reng_trq_yellow_led2;
	cp_reng_trq_yellow_led3->visible_object = blackhawk_lamps.cp_reng_trq_yellow_led3;
	cp_reng_trq_yellow_led4->visible_object = blackhawk_lamps.cp_reng_trq_yellow_led4;
	cp_reng_trq_yellow_led5->visible_object = blackhawk_lamps.cp_reng_trq_yellow_led5;
	cp_reng_trq_yellow_led6->visible_object = blackhawk_lamps.cp_reng_trq_yellow_led6;
	// Red LEDs
	cp_reng_trq_red_led1->visible_object = blackhawk_lamps.cp_reng_trq_red_led1;
	cp_reng_trq_red_led2->visible_object = blackhawk_lamps.cp_reng_trq_red_led2;
	cp_reng_trq_red_led3->visible_object = blackhawk_lamps.cp_reng_trq_red_led3;
	cp_reng_trq_red_led4->visible_object = blackhawk_lamps.cp_reng_trq_red_led4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_fuel_display (void)
{
	// Central Display Unit
	// Left Tank
	// Yellow LEDs
	lfuel_tank_yellow1->visible_object = blackhawk_lamps.lfuel_tank_yellow1;
	lfuel_tank_yellow2->visible_object = blackhawk_lamps.lfuel_tank_yellow2;
	lfuel_tank_yellow3->visible_object = blackhawk_lamps.lfuel_tank_yellow3;
	lfuel_tank_yellow4->visible_object = blackhawk_lamps.lfuel_tank_yellow4;
	// Green LEDs
	lfuel_tank_green1->visible_object = blackhawk_lamps.lfuel_tank_green1;
	lfuel_tank_green2->visible_object = blackhawk_lamps.lfuel_tank_green2;
	lfuel_tank_green3->visible_object = blackhawk_lamps.lfuel_tank_green3;
	lfuel_tank_green4->visible_object = blackhawk_lamps.lfuel_tank_green4;
	lfuel_tank_green5->visible_object = blackhawk_lamps.lfuel_tank_green5;
	lfuel_tank_green6->visible_object = blackhawk_lamps.lfuel_tank_green6;
	lfuel_tank_green7->visible_object = blackhawk_lamps.lfuel_tank_green7;
	lfuel_tank_green8->visible_object = blackhawk_lamps.lfuel_tank_green8;
	lfuel_tank_green9->visible_object = blackhawk_lamps.lfuel_tank_green9;
	lfuel_tank_green10->visible_object = blackhawk_lamps.lfuel_tank_green10;
	lfuel_tank_green11->visible_object = blackhawk_lamps.lfuel_tank_green11;
	lfuel_tank_green12->visible_object = blackhawk_lamps.lfuel_tank_green12;
	lfuel_tank_green13->visible_object = blackhawk_lamps.lfuel_tank_green13;
	lfuel_tank_green14->visible_object = blackhawk_lamps.lfuel_tank_green14;
	lfuel_tank_green15->visible_object = blackhawk_lamps.lfuel_tank_green15;
	lfuel_tank_green16->visible_object = blackhawk_lamps.lfuel_tank_green16;
	lfuel_tank_green17->visible_object = blackhawk_lamps.lfuel_tank_green17;
	lfuel_tank_green18->visible_object = blackhawk_lamps.lfuel_tank_green18;
	lfuel_tank_green19->visible_object = blackhawk_lamps.lfuel_tank_green19;
	lfuel_tank_green20->visible_object = blackhawk_lamps.lfuel_tank_green20;
	lfuel_tank_green21->visible_object = blackhawk_lamps.lfuel_tank_green21;
	lfuel_tank_green22->visible_object = blackhawk_lamps.lfuel_tank_green22;
	lfuel_tank_green23->visible_object = blackhawk_lamps.lfuel_tank_green23;
	lfuel_tank_green24->visible_object = blackhawk_lamps.lfuel_tank_green24;
	lfuel_tank_green25->visible_object = blackhawk_lamps.lfuel_tank_green25;
	lfuel_tank_green26->visible_object = blackhawk_lamps.lfuel_tank_green26;

	// Right Tank
	// Yellow LEDs
	rfuel_tank_yellow1->visible_object = blackhawk_lamps.rfuel_tank_yellow1;
	rfuel_tank_yellow2->visible_object = blackhawk_lamps.rfuel_tank_yellow2;
	rfuel_tank_yellow3->visible_object = blackhawk_lamps.rfuel_tank_yellow3;
	rfuel_tank_yellow4->visible_object = blackhawk_lamps.rfuel_tank_yellow4;
	// Green LEDs
	rfuel_tank_green1->visible_object = blackhawk_lamps.rfuel_tank_green1;
	rfuel_tank_green2->visible_object = blackhawk_lamps.rfuel_tank_green2;
	rfuel_tank_green3->visible_object = blackhawk_lamps.rfuel_tank_green3;
	rfuel_tank_green4->visible_object = blackhawk_lamps.rfuel_tank_green4;
	rfuel_tank_green5->visible_object = blackhawk_lamps.rfuel_tank_green5;
	rfuel_tank_green6->visible_object = blackhawk_lamps.rfuel_tank_green6;
	rfuel_tank_green7->visible_object = blackhawk_lamps.rfuel_tank_green7;
	rfuel_tank_green8->visible_object = blackhawk_lamps.rfuel_tank_green8;
	rfuel_tank_green9->visible_object = blackhawk_lamps.rfuel_tank_green9;
	rfuel_tank_green10->visible_object = blackhawk_lamps.rfuel_tank_green10;
	rfuel_tank_green11->visible_object = blackhawk_lamps.rfuel_tank_green11;
	rfuel_tank_green12->visible_object = blackhawk_lamps.rfuel_tank_green12;
	rfuel_tank_green13->visible_object = blackhawk_lamps.rfuel_tank_green13;
	rfuel_tank_green14->visible_object = blackhawk_lamps.rfuel_tank_green14;
	rfuel_tank_green15->visible_object = blackhawk_lamps.rfuel_tank_green15;
	rfuel_tank_green16->visible_object = blackhawk_lamps.rfuel_tank_green16;
	rfuel_tank_green17->visible_object = blackhawk_lamps.rfuel_tank_green17;
	rfuel_tank_green18->visible_object = blackhawk_lamps.rfuel_tank_green18;
	rfuel_tank_green19->visible_object = blackhawk_lamps.rfuel_tank_green19;
	rfuel_tank_green20->visible_object = blackhawk_lamps.rfuel_tank_green20;
	rfuel_tank_green21->visible_object = blackhawk_lamps.rfuel_tank_green21;
	rfuel_tank_green22->visible_object = blackhawk_lamps.rfuel_tank_green22;
	rfuel_tank_green23->visible_object = blackhawk_lamps.rfuel_tank_green23;
	rfuel_tank_green24->visible_object = blackhawk_lamps.rfuel_tank_green24;
	rfuel_tank_green25->visible_object = blackhawk_lamps.rfuel_tank_green25;
	rfuel_tank_green26->visible_object = blackhawk_lamps.rfuel_tank_green26;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_lng_speed_display(void)
{
	// NG Speed
	// Left Engine
	// Green LEDs
	lng_spd_green1->visible_object = blackhawk_lamps.lng_spd_green1;
	lng_spd_green2->visible_object = blackhawk_lamps.lng_spd_green2;
	lng_spd_green3->visible_object = blackhawk_lamps.lng_spd_green3;
	lng_spd_green4->visible_object = blackhawk_lamps.lng_spd_green4;
	lng_spd_green5->visible_object = blackhawk_lamps.lng_spd_green5;
	lng_spd_green6->visible_object = blackhawk_lamps.lng_spd_green6;
	lng_spd_green7->visible_object = blackhawk_lamps.lng_spd_green7;
	lng_spd_green8->visible_object = blackhawk_lamps.lng_spd_green8;
	lng_spd_green9->visible_object = blackhawk_lamps.lng_spd_green9;
	lng_spd_green10->visible_object = blackhawk_lamps.lng_spd_green10;
	lng_spd_green11->visible_object = blackhawk_lamps.lng_spd_green11;
	lng_spd_green12->visible_object = blackhawk_lamps.lng_spd_green12;
	lng_spd_green13->visible_object = blackhawk_lamps.lng_spd_green13;
	lng_spd_green14->visible_object = blackhawk_lamps.lng_spd_green14;
	lng_spd_green15->visible_object = blackhawk_lamps.lng_spd_green15;
	lng_spd_green16->visible_object = blackhawk_lamps.lng_spd_green16;
	lng_spd_green17->visible_object = blackhawk_lamps.lng_spd_green17;
	lng_spd_green18->visible_object = blackhawk_lamps.lng_spd_green18;
	lng_spd_green19->visible_object = blackhawk_lamps.lng_spd_green19;
	lng_spd_green20->visible_object = blackhawk_lamps.lng_spd_green20;
	lng_spd_green21->visible_object = blackhawk_lamps.lng_spd_green21;
	lng_spd_green22->visible_object = blackhawk_lamps.lng_spd_green22;
	lng_spd_green23->visible_object = blackhawk_lamps.lng_spd_green23;
	lng_spd_green24->visible_object = blackhawk_lamps.lng_spd_green24;
	// Yellow LEDs
	lng_spd_yellow1->visible_object = blackhawk_lamps.lng_spd_yellow1;
	lng_spd_yellow2->visible_object = blackhawk_lamps.lng_spd_yellow2;
	// Red LEDs
	lng_spd_red1->visible_object = blackhawk_lamps.lng_spd_red1;
	lng_spd_red2->visible_object = blackhawk_lamps.lng_spd_red2;
	lng_spd_red3->visible_object = blackhawk_lamps.lng_spd_red3;
	lng_spd_red4->visible_object = blackhawk_lamps.lng_spd_red4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_rng_speed_display(void)
{
	// Right Engine
	// Green LEDs
	rng_spd_green1->visible_object = blackhawk_lamps.rng_spd_green1;
	rng_spd_green2->visible_object = blackhawk_lamps.rng_spd_green2;
	rng_spd_green3->visible_object = blackhawk_lamps.rng_spd_green3;
	rng_spd_green4->visible_object = blackhawk_lamps.rng_spd_green4;
	rng_spd_green5->visible_object = blackhawk_lamps.rng_spd_green5;
	rng_spd_green6->visible_object = blackhawk_lamps.rng_spd_green6;
	rng_spd_green7->visible_object = blackhawk_lamps.rng_spd_green7;
	rng_spd_green8->visible_object = blackhawk_lamps.rng_spd_green8;
	rng_spd_green9->visible_object = blackhawk_lamps.rng_spd_green9;
	rng_spd_green10->visible_object = blackhawk_lamps.rng_spd_green10;
	rng_spd_green11->visible_object = blackhawk_lamps.rng_spd_green11;
	rng_spd_green12->visible_object = blackhawk_lamps.rng_spd_green12;
	rng_spd_green13->visible_object = blackhawk_lamps.rng_spd_green13;
	rng_spd_green14->visible_object = blackhawk_lamps.rng_spd_green14;
	rng_spd_green15->visible_object = blackhawk_lamps.rng_spd_green15;
	rng_spd_green16->visible_object = blackhawk_lamps.rng_spd_green16;
	rng_spd_green17->visible_object = blackhawk_lamps.rng_spd_green17;
	rng_spd_green18->visible_object = blackhawk_lamps.rng_spd_green18;
	rng_spd_green19->visible_object = blackhawk_lamps.rng_spd_green19;
	rng_spd_green20->visible_object = blackhawk_lamps.rng_spd_green20;
	rng_spd_green21->visible_object = blackhawk_lamps.rng_spd_green21;
	rng_spd_green22->visible_object = blackhawk_lamps.rng_spd_green22;
	rng_spd_green23->visible_object = blackhawk_lamps.rng_spd_green23;
	rng_spd_green24->visible_object = blackhawk_lamps.rng_spd_green24;
	// Yellow LEDs
	rng_spd_yellow1->visible_object = blackhawk_lamps.rng_spd_yellow1;
	rng_spd_yellow2->visible_object = blackhawk_lamps.rng_spd_yellow2;
	// Red LEDs
	rng_spd_red1->visible_object = blackhawk_lamps.rng_spd_red1;
	rng_spd_red2->visible_object = blackhawk_lamps.rng_spd_red2;
	rng_spd_red3->visible_object = blackhawk_lamps.rng_spd_red3;
	rng_spd_red4->visible_object = blackhawk_lamps.rng_spd_red4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_ltgt_temp_display(void)
{
	// Left Engine
	// Green LEDs
	ltgt_tmp_green1->visible_object = blackhawk_lamps.ltgt_tmp_green1;
	ltgt_tmp_green2->visible_object = blackhawk_lamps.ltgt_tmp_green2;
	ltgt_tmp_green3->visible_object = blackhawk_lamps.ltgt_tmp_green3;
	ltgt_tmp_green4->visible_object = blackhawk_lamps.ltgt_tmp_green4;
	ltgt_tmp_green5->visible_object = blackhawk_lamps.ltgt_tmp_green5;
	ltgt_tmp_green6->visible_object = blackhawk_lamps.ltgt_tmp_green6;
	ltgt_tmp_green7->visible_object = blackhawk_lamps.ltgt_tmp_green7;
	ltgt_tmp_green8->visible_object = blackhawk_lamps.ltgt_tmp_green8;
	ltgt_tmp_green9->visible_object = blackhawk_lamps.ltgt_tmp_green9;
	ltgt_tmp_green10->visible_object = blackhawk_lamps.ltgt_tmp_green10;
	ltgt_tmp_green11->visible_object = blackhawk_lamps.ltgt_tmp_green11;
	ltgt_tmp_green12->visible_object = blackhawk_lamps.ltgt_tmp_green12;
	ltgt_tmp_green13->visible_object = blackhawk_lamps.ltgt_tmp_green13;
	ltgt_tmp_green14->visible_object = blackhawk_lamps.ltgt_tmp_green14;
	ltgt_tmp_green15->visible_object = blackhawk_lamps.ltgt_tmp_green15;
	ltgt_tmp_green16->visible_object = blackhawk_lamps.ltgt_tmp_green16;
	ltgt_tmp_green17->visible_object = blackhawk_lamps.ltgt_tmp_green17;
	ltgt_tmp_green18->visible_object = blackhawk_lamps.ltgt_tmp_green18;
	ltgt_tmp_green19->visible_object = blackhawk_lamps.ltgt_tmp_green19;
	ltgt_tmp_green20->visible_object = blackhawk_lamps.ltgt_tmp_green20;
	ltgt_tmp_green21->visible_object = blackhawk_lamps.ltgt_tmp_green21;
	ltgt_tmp_green22->visible_object = blackhawk_lamps.ltgt_tmp_green22;
	ltgt_tmp_green23->visible_object = blackhawk_lamps.ltgt_tmp_green23;
	// Yellow LEDs
	ltgt_tmp_yellow1->visible_object = blackhawk_lamps.ltgt_tmp_yellow1;
	ltgt_tmp_yellow2->visible_object = blackhawk_lamps.ltgt_tmp_yellow2;
	ltgt_tmp_yellow3->visible_object = blackhawk_lamps.ltgt_tmp_yellow3;
	// Red LEDs
	ltgt_tmp_red1->visible_object = blackhawk_lamps.ltgt_tmp_red1;
	ltgt_tmp_red2->visible_object = blackhawk_lamps.ltgt_tmp_red2;
	ltgt_tmp_red3->visible_object = blackhawk_lamps.ltgt_tmp_red3;
	ltgt_tmp_red4->visible_object = blackhawk_lamps.ltgt_tmp_red4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_rtgt_temp_display(void)
{
	// Right Engine
	// Green LEDs
	rtgt_tmp_green1->visible_object = blackhawk_lamps.rtgt_tmp_green1;
	rtgt_tmp_green2->visible_object = blackhawk_lamps.rtgt_tmp_green2;
	rtgt_tmp_green3->visible_object = blackhawk_lamps.rtgt_tmp_green3;
	rtgt_tmp_green4->visible_object = blackhawk_lamps.rtgt_tmp_green4;
	rtgt_tmp_green5->visible_object = blackhawk_lamps.rtgt_tmp_green5;
	rtgt_tmp_green6->visible_object = blackhawk_lamps.rtgt_tmp_green6;
	rtgt_tmp_green7->visible_object = blackhawk_lamps.rtgt_tmp_green7;
	rtgt_tmp_green8->visible_object = blackhawk_lamps.rtgt_tmp_green8;
	rtgt_tmp_green9->visible_object = blackhawk_lamps.rtgt_tmp_green9;
	rtgt_tmp_green10->visible_object = blackhawk_lamps.rtgt_tmp_green10;
	rtgt_tmp_green11->visible_object = blackhawk_lamps.rtgt_tmp_green11;
	rtgt_tmp_green12->visible_object = blackhawk_lamps.rtgt_tmp_green12;
	rtgt_tmp_green13->visible_object = blackhawk_lamps.rtgt_tmp_green13;
	rtgt_tmp_green14->visible_object = blackhawk_lamps.rtgt_tmp_green14;
	rtgt_tmp_green15->visible_object = blackhawk_lamps.rtgt_tmp_green15;
	rtgt_tmp_green16->visible_object = blackhawk_lamps.rtgt_tmp_green16;
	rtgt_tmp_green17->visible_object = blackhawk_lamps.rtgt_tmp_green17;
	rtgt_tmp_green18->visible_object = blackhawk_lamps.rtgt_tmp_green18;
	rtgt_tmp_green19->visible_object = blackhawk_lamps.rtgt_tmp_green19;
	rtgt_tmp_green20->visible_object = blackhawk_lamps.rtgt_tmp_green20;
	rtgt_tmp_green21->visible_object = blackhawk_lamps.rtgt_tmp_green21;
	rtgt_tmp_green22->visible_object = blackhawk_lamps.rtgt_tmp_green22;
	rtgt_tmp_green23->visible_object = blackhawk_lamps.rtgt_tmp_green23;
	// Yellow LEDs
	rtgt_tmp_yellow1->visible_object = blackhawk_lamps.rtgt_tmp_yellow1;
	rtgt_tmp_yellow2->visible_object = blackhawk_lamps.rtgt_tmp_yellow2;
	rtgt_tmp_yellow3->visible_object = blackhawk_lamps.rtgt_tmp_yellow3;
	// Red LEDs
	rtgt_tmp_red1->visible_object = blackhawk_lamps.rtgt_tmp_red1;
	rtgt_tmp_red2->visible_object = blackhawk_lamps.rtgt_tmp_red2;
	rtgt_tmp_red3->visible_object = blackhawk_lamps.rtgt_tmp_red3;
	rtgt_tmp_red4->visible_object = blackhawk_lamps.rtgt_tmp_red4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
