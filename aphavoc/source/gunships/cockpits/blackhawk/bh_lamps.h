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

struct BLACKHAWK_LAMP_FLAGS
{
	unsigned int
	// Master Warning panel
		eng1_out					:1,
		eng2_out					:1,
		engine_fire					:1,
		apu_fire					:1,
		master_caution				:1,
		rotor_rpm					:1,

		engine_ignition				:1,
		apu_ignition				:1,
		engine_fire_extinguiser		:1,
		hydraulic_pressure			:1,
		oil_pressure				:1,
		oil_temperature				:1,
		overtorque					:1,
		fuel_low					:1,
		rotor_brake					:1,
		navigation_lights			:1,
		hover_hold					:1,
		altitude_hold				:1,
		auto_pilot					:1,
		laser						:1,
		ir_jammer					:1,
		auto_counter_measures		:1,
		ase_auto_page		 		:1,
		// TODO is this needed, as these MFDs don't get focus
		pilot_top_mfd_focus			:1,
		pilot_bottom_mfd_focus		:1,
		pilot_main_mfd_focus		:1,
		co_pilot_main_mfd_focus		:1,
//		co_pilot_rh_mfd_focus		:1;

		// Pilot Display Unit
		// Rotor RPM
		// Red LEDs
		rtr_rpm_red_led1 :1,
		rtr_rpm_red_led2 :1,
		rtr_rpm_red_led3 :1,
		rtr_rpm_red_led4 :1,
		rtr_rpm_red_led5 :1,
		rtr_rpm_red_led6 :1,
		rtr_rpm_red_led7 :1,
		rtr_rpm_red_led8 :1,
		rtr_rpm_red_led9 :1,
		rtr_rpm_red_led10 :1,
		rtr_rpm_red_led11 :1,
		rtr_rpm_red_led12 :1,
		rtr_rpm_red_led13 :1,
		rtr_rpm_red_led14 :1,
		rtr_rpm_red_led15 :1,
		rtr_rpm_red_led16 :1,
		rtr_rpm_red_led17 :1,
		rtr_rpm_red_led18 :1,
		rtr_rpm_red_led19 :1,
		rtr_rpm_red_led20 :1,
		rtr_rpm_red_led21 :1,
		rtr_rpm_red_led22 :1,
		rtr_rpm_red_led23 :1,
		rtr_rpm_red_led24 :1,
		rtr_rpm_red_led25 :1,
		rtr_rpm_red_led26 :1,
		rtr_rpm_red_led27 :1,
		// Yellow LEDs
		rtr_rpm_yellow_led1 :1,
		rtr_rpm_yellow_led2 :1,
		rtr_rpm_yellow_led3 :1,
		rtr_rpm_yellow_led4 :1,
		rtr_rpm_yellow_led5 :1,
		rtr_rpm_yellow_led6 :1,
		rtr_rpm_yellow_led7 :1,
		rtr_rpm_yellow_led8 :1,
		rtr_rpm_yellow_led9 :1,
		// Green LEDs
		rtr_rpm_green_led1 :1,
		rtr_rpm_green_led2 :1,
		rtr_rpm_green_led3 :1,
		rtr_rpm_green_led4 :1,
		rtr_rpm_green_led5 :1,

		// L Eng RPM
		// Red LEDs
		leng_rpm_red_led1   :1,
		leng_rpm_red_led2   :1,
		leng_rpm_red_led3   :1,
		leng_rpm_red_led4   :1,
		leng_rpm_red_led5   :1,
		leng_rpm_red_led6   :1,
		leng_rpm_red_led7   :1,
		leng_rpm_red_led8   :1,
		leng_rpm_red_led9   :1,
		leng_rpm_red_led10  :1,
		leng_rpm_red_led11  :1,
		leng_rpm_red_led12  :1,
		leng_rpm_red_led13  :1,
		leng_rpm_red_led14  :1,
		leng_rpm_red_led15  :1,
		leng_rpm_red_led16  :1,
		leng_rpm_red_led17  :1,
		leng_rpm_red_led18  :1,
		leng_rpm_red_led19  :1,
		leng_rpm_red_led20  :1,
		leng_rpm_red_led21  :1,
		leng_rpm_red_led22  :1,
		leng_rpm_red_led23  :1,
		leng_rpm_red_led24  :1,
		leng_rpm_red_led25  :1,
		leng_rpm_red_led26  :1,
		leng_rpm_red_led27  :1,
		// Yellow LEDs
		leng_rpm_yellow_led1 :1,
		leng_rpm_yellow_led2 :1,
		leng_rpm_yellow_led3 :1,
		leng_rpm_yellow_led4 :1,
		leng_rpm_yellow_led5 :1,
		leng_rpm_yellow_led6 :1,
		leng_rpm_yellow_led7 :1,
		leng_rpm_yellow_led8 :1,
		leng_rpm_yellow_led9 :1,
		// Green LEDs
		leng_rpm_green_led1 :1,
		leng_rpm_green_led2 :1,
		leng_rpm_green_led3 :1,
		leng_rpm_green_led4 :1,
		leng_rpm_green_led5 :1,

		// R Eng RPM
		// Red LEDs
		reng_rpm_red_led1   :1,
		reng_rpm_red_led2   :1,
		reng_rpm_red_led3   :1,
		reng_rpm_red_led4   :1,
		reng_rpm_red_led5   :1,
		reng_rpm_red_led6   :1,
		reng_rpm_red_led7   :1,
		reng_rpm_red_led8   :1,
		reng_rpm_red_led9   :1,
		reng_rpm_red_led10  :1,
		reng_rpm_red_led11  :1,
		reng_rpm_red_led12  :1,
		reng_rpm_red_led13  :1,
		reng_rpm_red_led14  :1,
		reng_rpm_red_led15  :1,
		reng_rpm_red_led16  :1,
		reng_rpm_red_led17  :1,
		reng_rpm_red_led18  :1,
		reng_rpm_red_led19  :1,
		reng_rpm_red_led20  :1,
		reng_rpm_red_led21  :1,
		reng_rpm_red_led22  :1,
		reng_rpm_red_led23  :1,
		reng_rpm_red_led24  :1,
		reng_rpm_red_led25  :1,
		reng_rpm_red_led26  :1,
		reng_rpm_red_led27  :1,
		// Yellow LEDs
		reng_rpm_yellow_led1 :1,
		reng_rpm_yellow_led2 :1,
		reng_rpm_yellow_led3 :1,
		reng_rpm_yellow_led4 :1,
		reng_rpm_yellow_led5 :1,
		reng_rpm_yellow_led6 :1,
		reng_rpm_yellow_led7 :1,
		reng_rpm_yellow_led8 :1,
		reng_rpm_yellow_led9 :1,
		// Green LEDs
		reng_rpm_green_led1 :1,
		reng_rpm_green_led2 :1,
		reng_rpm_green_led3 :1,
		reng_rpm_green_led4 :1,
		reng_rpm_green_led5 :1,

		// L Eng TRQ
		// Green LEDs
		leng_trq_green_led1 : 1,
		leng_trq_green_led2 : 1,
		leng_trq_green_led3 : 1,
		leng_trq_green_led4 : 1,
		leng_trq_green_led5 : 1,
		leng_trq_green_led6 : 1,
		leng_trq_green_led7 : 1,
		leng_trq_green_led8 : 1,
		leng_trq_green_led9 : 1,
		leng_trq_green_led10 : 1,
		leng_trq_green_led11 : 1,
		leng_trq_green_led12 : 1,
		leng_trq_green_led13 : 1,
		leng_trq_green_led14 : 1,
		leng_trq_green_led15 : 1,
		leng_trq_green_led16 : 1,
		leng_trq_green_led17 : 1,
		leng_trq_green_led18 : 1,
		leng_trq_green_led19 : 1,
		leng_trq_green_led20 : 1,
		// Yellow LEDs
		leng_trq_yellow_led1 : 1,
		leng_trq_yellow_led2 : 1,
		leng_trq_yellow_led3 : 1,
		leng_trq_yellow_led4 : 1,
		leng_trq_yellow_led5 : 1,
		leng_trq_yellow_led6 : 1,
		// Red LEDs
		leng_trq_red_led1 : 1,
		leng_trq_red_led2 : 1,
		leng_trq_red_led3 : 1,
		leng_trq_red_led4 : 1,

		// R Eng TRQ
		// Green LEDs
		reng_trq_green_led1 : 1,
		reng_trq_green_led2 : 1,
		reng_trq_green_led3 : 1,
		reng_trq_green_led4 : 1,
		reng_trq_green_led5 : 1,
		reng_trq_green_led6 : 1,
		reng_trq_green_led7 : 1,
		reng_trq_green_led8 : 1,
		reng_trq_green_led9 : 1,
		reng_trq_green_led10 : 1,
		reng_trq_green_led11 : 1,
		reng_trq_green_led12 : 1,
		reng_trq_green_led13 : 1,
		reng_trq_green_led14 : 1,
		reng_trq_green_led15 : 1,
		reng_trq_green_led16 : 1,
		reng_trq_green_led17 : 1,
		reng_trq_green_led18 : 1,
		reng_trq_green_led19 : 1,
		reng_trq_green_led20 : 1,
		// Yellow LEDs
		reng_trq_yellow_led1 : 1,
		reng_trq_yellow_led2 : 1,
		reng_trq_yellow_led3 : 1,
		reng_trq_yellow_led4 : 1,
		reng_trq_yellow_led5 : 1,
		reng_trq_yellow_led6 : 1,
		// Red LEDs
		reng_trq_red_led1 : 1,
		reng_trq_red_led2 : 1,
		reng_trq_red_led3 : 1,
		reng_trq_red_led4 : 1,

		// Co-Pilot Display Unit
		// Rotor RPM
		// Red LEDs
		cp_rtr_rpm_red_led1 :1,
		cp_rtr_rpm_red_led2 :1,
		cp_rtr_rpm_red_led3 :1,
		cp_rtr_rpm_red_led4 :1,
		cp_rtr_rpm_red_led5 :1,
		cp_rtr_rpm_red_led6 :1,
		cp_rtr_rpm_red_led7 :1,
		cp_rtr_rpm_red_led8 :1,
		cp_rtr_rpm_red_led9 :1,
		cp_rtr_rpm_red_led10 :1,
		cp_rtr_rpm_red_led11 :1,
		cp_rtr_rpm_red_led12 :1,
		cp_rtr_rpm_red_led13 :1,
		cp_rtr_rpm_red_led14 :1,
		cp_rtr_rpm_red_led15 :1,
		cp_rtr_rpm_red_led16 :1,
		cp_rtr_rpm_red_led17 :1,
		cp_rtr_rpm_red_led18 :1,
		cp_rtr_rpm_red_led19 :1,
		cp_rtr_rpm_red_led20 :1,
		cp_rtr_rpm_red_led21 :1,
		cp_rtr_rpm_red_led22 :1,
		cp_rtr_rpm_red_led23 :1,
		cp_rtr_rpm_red_led24 :1,
		cp_rtr_rpm_red_led25 :1,
		cp_rtr_rpm_red_led26 :1,
		cp_rtr_rpm_red_led27 :1,
		// Yellow LEDs
		cp_rtr_rpm_yellow_led1 :1,
		cp_rtr_rpm_yellow_led2 :1,
		cp_rtr_rpm_yellow_led3 :1,
		cp_rtr_rpm_yellow_led4 :1,
		cp_rtr_rpm_yellow_led5 :1,
		cp_rtr_rpm_yellow_led6 :1,
		cp_rtr_rpm_yellow_led7 :1,
		cp_rtr_rpm_yellow_led8 :1,
		cp_rtr_rpm_yellow_led9 :1,
		// Green LEDs
		cp_rtr_rpm_green_led1 :1,
		cp_rtr_rpm_green_led2 :1,
		cp_rtr_rpm_green_led3 :1,
		cp_rtr_rpm_green_led4 :1,
		cp_rtr_rpm_green_led5 :1,

		// L Eng RPM
		// Red LEDs
		cp_leng_rpm_red_led1   :1,
		cp_leng_rpm_red_led2   :1,
		cp_leng_rpm_red_led3   :1,
		cp_leng_rpm_red_led4   :1,
		cp_leng_rpm_red_led5   :1,
		cp_leng_rpm_red_led6   :1,
		cp_leng_rpm_red_led7   :1,
		cp_leng_rpm_red_led8   :1,
		cp_leng_rpm_red_led9   :1,
		cp_leng_rpm_red_led10  :1,
		cp_leng_rpm_red_led11  :1,
		cp_leng_rpm_red_led12  :1,
		cp_leng_rpm_red_led13  :1,
		cp_leng_rpm_red_led14  :1,
		cp_leng_rpm_red_led15  :1,
		cp_leng_rpm_red_led16  :1,
		cp_leng_rpm_red_led17  :1,
		cp_leng_rpm_red_led18  :1,
		cp_leng_rpm_red_led19  :1,
		cp_leng_rpm_red_led20  :1,
		cp_leng_rpm_red_led21  :1,
		cp_leng_rpm_red_led22  :1,
		cp_leng_rpm_red_led23  :1,
		cp_leng_rpm_red_led24  :1,
		cp_leng_rpm_red_led25  :1,
		cp_leng_rpm_red_led26  :1,
		cp_leng_rpm_red_led27  :1,
		// Yellow LEDs
		cp_leng_rpm_yellow_led1 :1,
		cp_leng_rpm_yellow_led2 :1,
		cp_leng_rpm_yellow_led3 :1,
		cp_leng_rpm_yellow_led4 :1,
		cp_leng_rpm_yellow_led5 :1,
		cp_leng_rpm_yellow_led6 :1,
		cp_leng_rpm_yellow_led7 :1,
		cp_leng_rpm_yellow_led8 :1,
		cp_leng_rpm_yellow_led9 :1,
		// Green LEDs
		cp_leng_rpm_green_led1 :1,
		cp_leng_rpm_green_led2 :1,
		cp_leng_rpm_green_led3 :1,
		cp_leng_rpm_green_led4 :1,
		cp_leng_rpm_green_led5 :1,

		// R Eng RPM
		// Red LEDs
		cp_reng_rpm_red_led1   :1,
		cp_reng_rpm_red_led2   :1,
		cp_reng_rpm_red_led3   :1,
		cp_reng_rpm_red_led4   :1,
		cp_reng_rpm_red_led5   :1,
		cp_reng_rpm_red_led6   :1,
		cp_reng_rpm_red_led7   :1,
		cp_reng_rpm_red_led8   :1,
		cp_reng_rpm_red_led9   :1,
		cp_reng_rpm_red_led10  :1,
		cp_reng_rpm_red_led11  :1,
		cp_reng_rpm_red_led12  :1,
		cp_reng_rpm_red_led13  :1,
		cp_reng_rpm_red_led14  :1,
		cp_reng_rpm_red_led15  :1,
		cp_reng_rpm_red_led16  :1,
		cp_reng_rpm_red_led17  :1,
		cp_reng_rpm_red_led18  :1,
		cp_reng_rpm_red_led19  :1,
		cp_reng_rpm_red_led20  :1,
		cp_reng_rpm_red_led21  :1,
		cp_reng_rpm_red_led22  :1,
		cp_reng_rpm_red_led23  :1,
		cp_reng_rpm_red_led24  :1,
		cp_reng_rpm_red_led25  :1,
		cp_reng_rpm_red_led26  :1,
		cp_reng_rpm_red_led27  :1,
		// Yellow LEDs
		cp_reng_rpm_yellow_led1 :1,
		cp_reng_rpm_yellow_led2 :1,
		cp_reng_rpm_yellow_led3 :1,
		cp_reng_rpm_yellow_led4 :1,
		cp_reng_rpm_yellow_led5 :1,
		cp_reng_rpm_yellow_led6 :1,
		cp_reng_rpm_yellow_led7 :1,
		cp_reng_rpm_yellow_led8 :1,
		cp_reng_rpm_yellow_led9 :1,
		// Green LEDs
		cp_reng_rpm_green_led1 :1,
		cp_reng_rpm_green_led2 :1,
		cp_reng_rpm_green_led3 :1,
		cp_reng_rpm_green_led4 :1,
		cp_reng_rpm_green_led5 :1,

		// L Eng TRQ
		// Green LEDs
		cp_leng_trq_green_led1 : 1,
		cp_leng_trq_green_led2 : 1,
		cp_leng_trq_green_led3 : 1,
		cp_leng_trq_green_led4 : 1,
		cp_leng_trq_green_led5 : 1,
		cp_leng_trq_green_led6 : 1,
		cp_leng_trq_green_led7 : 1,
		cp_leng_trq_green_led8 : 1,
		cp_leng_trq_green_led9 : 1,
		cp_leng_trq_green_led10 : 1,
		cp_leng_trq_green_led11 : 1,
		cp_leng_trq_green_led12 : 1,
		cp_leng_trq_green_led13 : 1,
		cp_leng_trq_green_led14 : 1,
		cp_leng_trq_green_led15 : 1,
		cp_leng_trq_green_led16 : 1,
		cp_leng_trq_green_led17 : 1,
		cp_leng_trq_green_led18 : 1,
		cp_leng_trq_green_led19 : 1,
		cp_leng_trq_green_led20 : 1,
		// Yellow LEDs
		cp_leng_trq_yellow_led1 : 1,
		cp_leng_trq_yellow_led2 : 1,
		cp_leng_trq_yellow_led3 : 1,
		cp_leng_trq_yellow_led4 : 1,
		cp_leng_trq_yellow_led5 : 1,
		cp_leng_trq_yellow_led6 : 1,
		// Red LEDs
		cp_leng_trq_red_led1 : 1,
		cp_leng_trq_red_led2 : 1,
		cp_leng_trq_red_led3 : 1,
		cp_leng_trq_red_led4 : 1,

		// R Eng TRQ
		// Green LEDs
		cp_reng_trq_green_led1 : 1,
		cp_reng_trq_green_led2 : 1,
		cp_reng_trq_green_led3 : 1,
		cp_reng_trq_green_led4 : 1,
		cp_reng_trq_green_led5 : 1,
		cp_reng_trq_green_led6 : 1,
		cp_reng_trq_green_led7 : 1,
		cp_reng_trq_green_led8 : 1,
		cp_reng_trq_green_led9 : 1,
		cp_reng_trq_green_led10 : 1,
		cp_reng_trq_green_led11 : 1,
		cp_reng_trq_green_led12 : 1,
		cp_reng_trq_green_led13 : 1,
		cp_reng_trq_green_led14 : 1,
		cp_reng_trq_green_led15 : 1,
		cp_reng_trq_green_led16 : 1,
		cp_reng_trq_green_led17 : 1,
		cp_reng_trq_green_led18 : 1,
		cp_reng_trq_green_led19 : 1,
		cp_reng_trq_green_led20 : 1,
		// Yellow LEDs
		cp_reng_trq_yellow_led1 : 1,
		cp_reng_trq_yellow_led2 : 1,
		cp_reng_trq_yellow_led3 : 1,
		cp_reng_trq_yellow_led4 : 1,
		cp_reng_trq_yellow_led5 : 1,
		cp_reng_trq_yellow_led6 : 1,
		// Red LEDs
		cp_reng_trq_red_led1 : 1,
		cp_reng_trq_red_led2 : 1,
		cp_reng_trq_red_led3 : 1,
		cp_reng_trq_red_led4 : 1,

		// Central Display Unit
		// Fuel Quantity
		// Left Fuel Tank
		// Yellow LEDs
		lfuel_tank_yellow1,
		lfuel_tank_yellow2,
		lfuel_tank_yellow3,
		lfuel_tank_yellow4,
		// Green LEDs
		lfuel_tank_green1,
		lfuel_tank_green2,
		lfuel_tank_green3,
		lfuel_tank_green4,
		lfuel_tank_green5,
		lfuel_tank_green6,
		lfuel_tank_green7,
		lfuel_tank_green8,
		lfuel_tank_green9,
		lfuel_tank_green10,
		lfuel_tank_green11,
		lfuel_tank_green12,
		lfuel_tank_green13,
		lfuel_tank_green14,
		lfuel_tank_green15,
		lfuel_tank_green16,
		lfuel_tank_green17,
		lfuel_tank_green18,
		lfuel_tank_green19,
		lfuel_tank_green20,
		lfuel_tank_green21,
		lfuel_tank_green22,
		lfuel_tank_green23,
		lfuel_tank_green24,
		lfuel_tank_green25,
		lfuel_tank_green26,

		// Right Fuel Tank
		// Yellow LEDs
		rfuel_tank_yellow1,
		rfuel_tank_yellow2,
		rfuel_tank_yellow3,
		rfuel_tank_yellow4,
		// Green LEDs
		rfuel_tank_green1,
		rfuel_tank_green2,
		rfuel_tank_green3,
		rfuel_tank_green4,
		rfuel_tank_green5,
		rfuel_tank_green6,
		rfuel_tank_green7,
		rfuel_tank_green8,
		rfuel_tank_green9,
		rfuel_tank_green10,
		rfuel_tank_green11,
		rfuel_tank_green12,
		rfuel_tank_green13,
		rfuel_tank_green14,
		rfuel_tank_green15,
		rfuel_tank_green16,
		rfuel_tank_green17,
		rfuel_tank_green18,
		rfuel_tank_green19,
		rfuel_tank_green20,
		rfuel_tank_green21,
		rfuel_tank_green22,
		rfuel_tank_green23,
		rfuel_tank_green24,
		rfuel_tank_green25,
		rfuel_tank_green26,

		// NG Speed
		// Left Engine
		// Green LEDs
		lng_spd_green1,
		lng_spd_green2,
		lng_spd_green3,
		lng_spd_green4,
		lng_spd_green5,
		lng_spd_green6,
		lng_spd_green7,
		lng_spd_green8,
		lng_spd_green9,
		lng_spd_green10,
		lng_spd_green11,
		lng_spd_green12,
		lng_spd_green13,
		lng_spd_green14,
		lng_spd_green15,
		lng_spd_green16,
		lng_spd_green17,
		lng_spd_green18,
		lng_spd_green19,
		lng_spd_green20,
		lng_spd_green21,
		lng_spd_green22,
		lng_spd_green23,
		lng_spd_green24,
		// Yellow LEDs
		lng_spd_yellow1,
		lng_spd_yellow2,
		// Red LEDs
		lng_spd_red1,
		lng_spd_red2,
		lng_spd_red3,
		lng_spd_red4,

		// Right Engine
		// Green LEDs
		rng_spd_green1,
		rng_spd_green2,
		rng_spd_green3,
		rng_spd_green4,
		rng_spd_green5,
		rng_spd_green6,
		rng_spd_green7,
		rng_spd_green8,
		rng_spd_green9,
		rng_spd_green10,
		rng_spd_green11,
		rng_spd_green12,
		rng_spd_green13,
		rng_spd_green14,
		rng_spd_green15,
		rng_spd_green16,
		rng_spd_green17,
		rng_spd_green18,
		rng_spd_green19,
		rng_spd_green20,
		rng_spd_green21,
		rng_spd_green22,
		rng_spd_green23,
		rng_spd_green24,
		// Yellow LEDs
		rng_spd_yellow1,
		rng_spd_yellow2,
		// Red LEDs
		rng_spd_red1,
		rng_spd_red2,
		rng_spd_red3,
		rng_spd_red4,

		// TGT Temp
		// Left Engine
		// Green LEDs
		ltgt_tmp_green1,
		ltgt_tmp_green2,
		ltgt_tmp_green3,
		ltgt_tmp_green4,
		ltgt_tmp_green5,
		ltgt_tmp_green6,
		ltgt_tmp_green7,
		ltgt_tmp_green8,
		ltgt_tmp_green9,
		ltgt_tmp_green10,
		ltgt_tmp_green11,
		ltgt_tmp_green12,
		ltgt_tmp_green13,
		ltgt_tmp_green14,
		ltgt_tmp_green15,
		ltgt_tmp_green16,
		ltgt_tmp_green17,
		ltgt_tmp_green18,
		ltgt_tmp_green19,
		ltgt_tmp_green20,
		ltgt_tmp_green21,
		ltgt_tmp_green22,
		ltgt_tmp_green23,
		// Yellow LEDs
		ltgt_tmp_yellow1,
		ltgt_tmp_yellow2,
		ltgt_tmp_yellow3,
		// Red LEDs
		ltgt_tmp_red1,
		ltgt_tmp_red2,
		ltgt_tmp_red3,
		ltgt_tmp_red4,

		// Right Engine
		// Green LEDs
		rtgt_tmp_green1,
		rtgt_tmp_green2,
		rtgt_tmp_green3,
		rtgt_tmp_green4,
		rtgt_tmp_green5,
		rtgt_tmp_green6,
		rtgt_tmp_green7,
		rtgt_tmp_green8,
		rtgt_tmp_green9,
		rtgt_tmp_green10,
		rtgt_tmp_green11,
		rtgt_tmp_green12,
		rtgt_tmp_green13,
		rtgt_tmp_green14,
		rtgt_tmp_green15,
		rtgt_tmp_green16,
		rtgt_tmp_green17,
		rtgt_tmp_green18,
		rtgt_tmp_green19,
		rtgt_tmp_green20,
		rtgt_tmp_green21,
		rtgt_tmp_green22,
		rtgt_tmp_green23,
		// Yellow LEDs
		rtgt_tmp_yellow1,
		rtgt_tmp_yellow2,
		rtgt_tmp_yellow3,
		// Red LEDs
		rtgt_tmp_red1,
		rtgt_tmp_red2,
		rtgt_tmp_red3,
		rtgt_tmp_red4;
};

typedef struct BLACKHAWK_LAMP_FLAGS blackhawk_lamp_flags;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern blackhawk_lamp_flags
	blackhawk_lamps;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void initialise_blackhawk_lamps (void);

extern void deinitialise_blackhawk_lamps (void);

extern void draw_blackhawk_virtual_cockpit_lamps (void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
