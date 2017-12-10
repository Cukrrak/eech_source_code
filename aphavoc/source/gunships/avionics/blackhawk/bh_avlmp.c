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

#define DEBUG_MODULE	0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MASTER_CAUTION_FLASH_RATE	(0.5)

static int
	master_caution_alert,
	engine_damage_imminent_status,
	previous_engine_damage_imminent_status;

static float
	master_caution_flash_timer;

static float
	master_caution_sound_timer;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void initialise_master_caution (void)
{
	master_caution_alert = FALSE;

	master_caution_flash_timer = 0.0;

	master_caution_sound_timer = 0.0;

	engine_damage_imminent_status = FALSE;

	previous_engine_damage_imminent_status = FALSE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void deinitialise_master_caution (void)
{
	if (get_gunship_entity ())
	{
		pause_local_entity_sound_type (get_gunship_entity (), ENTITY_SUB_TYPE_EFFECT_SOUND_MCA, 0.5);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void activate_blackhawk_master_caution (void)
{
	blackhawk_lamps.master_caution = 1;

	master_caution_alert = TRUE;

	master_caution_flash_timer = MASTER_CAUTION_FLASH_RATE;

	master_caution_sound_timer = 3.0;

	resume_local_entity_sound_type (get_gunship_entity (), ENTITY_SUB_TYPE_EFFECT_SOUND_MCA);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deactivate_blackhawk_master_caution (void)
{
	blackhawk_lamps.master_caution = 0;

	master_caution_alert = FALSE;

	master_caution_flash_timer = 0.0;

	master_caution_sound_timer = 0.0;

	pause_local_entity_sound_type (get_gunship_entity (), ENTITY_SUB_TYPE_EFFECT_SOUND_MCA, 0.5);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void update_master_caution (void)
{
	//
	// monitor engine damage
	//

	engine_damage_imminent_status = get_current_flight_dynamics_engine_damage_imminent ();

	if ((!previous_engine_damage_imminent_status) && engine_damage_imminent_status)
	{
		play_client_server_warning_message (get_gunship_entity (), SPEECH_SYSTEM_ENGINE_OVERTORQUE);

		activate_blackhawk_master_caution ();
	}

	previous_engine_damage_imminent_status = engine_damage_imminent_status;

	//
	// update master caution lamp
	//

	if (master_caution_alert)
	{
		master_caution_flash_timer -= get_delta_time ();

		if (master_caution_flash_timer <= 0.0)
		{
			master_caution_flash_timer = MASTER_CAUTION_FLASH_RATE;

			blackhawk_lamps.master_caution ^= 1;
		}

	master_caution_sound_timer -= get_delta_time ();

	if (master_caution_sound_timer <= 0.0)
	{
		master_caution_sound_timer = 0.0;

		pause_local_entity_sound_type (get_gunship_entity (), ENTITY_SUB_TYPE_EFFECT_SOUND_MCA, 0.5);
	}
}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void clear_rtr_rpm_leds(void)
{
	blackhawk_lamps.rtr_rpm_red_led1  = 0;
	blackhawk_lamps.rtr_rpm_red_led2  = 0;
	blackhawk_lamps.rtr_rpm_red_led3  = 0;
	blackhawk_lamps.rtr_rpm_red_led4  = 0;
	blackhawk_lamps.rtr_rpm_red_led5  = 0;
	blackhawk_lamps.rtr_rpm_red_led6  = 0;
	blackhawk_lamps.rtr_rpm_red_led7  = 0;
	blackhawk_lamps.rtr_rpm_red_led8  = 0;
	blackhawk_lamps.rtr_rpm_red_led9  = 0;
	blackhawk_lamps.rtr_rpm_red_led10 = 0;
	blackhawk_lamps.rtr_rpm_red_led11 = 0;
	blackhawk_lamps.rtr_rpm_red_led12 = 0;
	blackhawk_lamps.rtr_rpm_red_led13 = 0;
	blackhawk_lamps.rtr_rpm_red_led14 = 0;
	blackhawk_lamps.rtr_rpm_red_led15 = 0;
	blackhawk_lamps.rtr_rpm_red_led16 = 0;
	blackhawk_lamps.rtr_rpm_red_led17 = 0;
	blackhawk_lamps.rtr_rpm_red_led18 = 0;
	blackhawk_lamps.rtr_rpm_red_led19 = 0;
	blackhawk_lamps.rtr_rpm_red_led20 = 0;
	blackhawk_lamps.rtr_rpm_red_led21 = 0;
	blackhawk_lamps.rtr_rpm_red_led22 = 0;
	blackhawk_lamps.rtr_rpm_red_led23 = 0;
	blackhawk_lamps.rtr_rpm_red_led24 = 0;
	blackhawk_lamps.rtr_rpm_red_led25 = 0;
	blackhawk_lamps.rtr_rpm_red_led26 = 0;
	blackhawk_lamps.rtr_rpm_red_led27 = 0;

//	blackhawk_lamps.rtr_rpm_cp_red_led1 = 0;

	blackhawk_lamps.rtr_rpm_yellow_led1 = 0;
	blackhawk_lamps.rtr_rpm_yellow_led2 = 0;
	blackhawk_lamps.rtr_rpm_yellow_led3 = 0;
	blackhawk_lamps.rtr_rpm_yellow_led4 = 0;
	blackhawk_lamps.rtr_rpm_yellow_led5 = 0;
	blackhawk_lamps.rtr_rpm_yellow_led6 = 0;
	blackhawk_lamps.rtr_rpm_yellow_led7 = 0;
	blackhawk_lamps.rtr_rpm_yellow_led8 = 0;
	blackhawk_lamps.rtr_rpm_yellow_led9 = 0;

	blackhawk_lamps.rtr_rpm_green_led1 = 0;
	blackhawk_lamps.rtr_rpm_green_led2 = 0;
	blackhawk_lamps.rtr_rpm_green_led3 = 0;
	blackhawk_lamps.rtr_rpm_green_led4 = 0;
	blackhawk_lamps.rtr_rpm_green_led5 = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void clear_leng_rpm_leds (void)
{
	// L Eng RPM
	// Red LEDs
	blackhawk_lamps.leng_rpm_red_led1    = 0;
	blackhawk_lamps.leng_rpm_red_led2    = 0;
	blackhawk_lamps.leng_rpm_red_led3    = 0;
	blackhawk_lamps.leng_rpm_red_led4    = 0;
	blackhawk_lamps.leng_rpm_red_led5    = 0;
	blackhawk_lamps.leng_rpm_red_led6    = 0;
	blackhawk_lamps.leng_rpm_red_led7    = 0;
	blackhawk_lamps.leng_rpm_red_led8    = 0;
	blackhawk_lamps.leng_rpm_red_led9    = 0;
	blackhawk_lamps.leng_rpm_red_led10   = 0;
	blackhawk_lamps.leng_rpm_red_led11   = 0;
	blackhawk_lamps.leng_rpm_red_led12   = 0;
	blackhawk_lamps.leng_rpm_red_led13   = 0;
	blackhawk_lamps.leng_rpm_red_led14   = 0;
	blackhawk_lamps.leng_rpm_red_led15   = 0;
	blackhawk_lamps.leng_rpm_red_led16   = 0;
	blackhawk_lamps.leng_rpm_red_led17   = 0;
	blackhawk_lamps.leng_rpm_red_led18   = 0;
	blackhawk_lamps.leng_rpm_red_led19   = 0;
	blackhawk_lamps.leng_rpm_red_led20   = 0;
	blackhawk_lamps.leng_rpm_red_led21   = 0;
	blackhawk_lamps.leng_rpm_red_led22   = 0;
	blackhawk_lamps.leng_rpm_red_led23   = 0;
	blackhawk_lamps.leng_rpm_red_led24   = 0;
	blackhawk_lamps.leng_rpm_red_led25   = 0;
	blackhawk_lamps.leng_rpm_red_led26   = 0;
	blackhawk_lamps.leng_rpm_red_led27   = 0;
	// Yellow LEDs
	blackhawk_lamps.leng_rpm_yellow_led1 = 0;
	blackhawk_lamps.leng_rpm_yellow_led2 = 0;
	blackhawk_lamps.leng_rpm_yellow_led3 = 0;
	blackhawk_lamps.leng_rpm_yellow_led4 = 0;
	blackhawk_lamps.leng_rpm_yellow_led5 = 0;
	blackhawk_lamps.leng_rpm_yellow_led6 = 0;
	blackhawk_lamps.leng_rpm_yellow_led7 = 0;
	blackhawk_lamps.leng_rpm_yellow_led8 = 0;
	blackhawk_lamps.leng_rpm_yellow_led9 = 0;
	// Green LEDs
	blackhawk_lamps.leng_rpm_green_led1  = 0;
	blackhawk_lamps.leng_rpm_green_led2  = 0;
	blackhawk_lamps.leng_rpm_green_led3  = 0;
	blackhawk_lamps.leng_rpm_green_led4  = 0;
	blackhawk_lamps.leng_rpm_green_led5  = 0;
}

void clear_reng_rpm_leds (void)
{
	// R Eng RPM
	// Red LEDs
	blackhawk_lamps.reng_rpm_red_led1    = 0;
	blackhawk_lamps.reng_rpm_red_led2    = 0;
	blackhawk_lamps.reng_rpm_red_led3    = 0;
	blackhawk_lamps.reng_rpm_red_led4    = 0;
	blackhawk_lamps.reng_rpm_red_led5    = 0;
	blackhawk_lamps.reng_rpm_red_led6    = 0;
	blackhawk_lamps.reng_rpm_red_led7    = 0;
	blackhawk_lamps.reng_rpm_red_led8    = 0;
	blackhawk_lamps.reng_rpm_red_led9    = 0;
	blackhawk_lamps.reng_rpm_red_led10   = 0;
	blackhawk_lamps.reng_rpm_red_led11   = 0;
	blackhawk_lamps.reng_rpm_red_led12   = 0;
	blackhawk_lamps.reng_rpm_red_led13   = 0;
	blackhawk_lamps.reng_rpm_red_led14   = 0;
	blackhawk_lamps.reng_rpm_red_led15   = 0;
	blackhawk_lamps.reng_rpm_red_led16   = 0;
	blackhawk_lamps.reng_rpm_red_led17   = 0;
	blackhawk_lamps.reng_rpm_red_led18   = 0;
	blackhawk_lamps.reng_rpm_red_led19   = 0;
	blackhawk_lamps.reng_rpm_red_led20   = 0;
	blackhawk_lamps.reng_rpm_red_led21   = 0;
	blackhawk_lamps.reng_rpm_red_led22   = 0;
	blackhawk_lamps.reng_rpm_red_led23   = 0;
	blackhawk_lamps.reng_rpm_red_led24   = 0;
	blackhawk_lamps.reng_rpm_red_led25   = 0;
	blackhawk_lamps.reng_rpm_red_led26   = 0;
	blackhawk_lamps.reng_rpm_red_led27   = 0;
	// Yellow LEDs
	blackhawk_lamps.reng_rpm_yellow_led1 = 0;
	blackhawk_lamps.reng_rpm_yellow_led2 = 0;
	blackhawk_lamps.reng_rpm_yellow_led3 = 0;
	blackhawk_lamps.reng_rpm_yellow_led4 = 0;
	blackhawk_lamps.reng_rpm_yellow_led5 = 0;
	blackhawk_lamps.reng_rpm_yellow_led6 = 0;
	blackhawk_lamps.reng_rpm_yellow_led7 = 0;
	blackhawk_lamps.reng_rpm_yellow_led8 = 0;
	blackhawk_lamps.reng_rpm_yellow_led9 = 0;
	// Green LEDs
	blackhawk_lamps.reng_rpm_green_led1  = 0;
	blackhawk_lamps.reng_rpm_green_led2  = 0;
	blackhawk_lamps.reng_rpm_green_led3  = 0;
	blackhawk_lamps.reng_rpm_green_led4  = 0;
	blackhawk_lamps.reng_rpm_green_led5  = 0;
}

void clear_leng_trq_leds (void)
{
	// Green LEDs
	blackhawk_lamps.leng_trq_green_led1  = 0;
	blackhawk_lamps.leng_trq_green_led2  = 0;
	blackhawk_lamps.leng_trq_green_led3  = 0;
	blackhawk_lamps.leng_trq_green_led4  = 0;
	blackhawk_lamps.leng_trq_green_led5  = 0;
	blackhawk_lamps.leng_trq_green_led6  = 0;
	blackhawk_lamps.leng_trq_green_led7  = 0;
	blackhawk_lamps.leng_trq_green_led8  = 0;
	blackhawk_lamps.leng_trq_green_led9  = 0;
	blackhawk_lamps.leng_trq_green_led10 = 0;
	blackhawk_lamps.leng_trq_green_led11 = 0;
	blackhawk_lamps.leng_trq_green_led12 = 0;
	blackhawk_lamps.leng_trq_green_led13 = 0;
	blackhawk_lamps.leng_trq_green_led14 = 0;
	blackhawk_lamps.leng_trq_green_led15 = 0;
	blackhawk_lamps.leng_trq_green_led16 = 0;
	blackhawk_lamps.leng_trq_green_led17 = 0;
	blackhawk_lamps.leng_trq_green_led18 = 0;
	blackhawk_lamps.leng_trq_green_led19 = 0;
	blackhawk_lamps.leng_trq_green_led20 = 0;

	// Yellow LEDs
	blackhawk_lamps.leng_trq_yellow_led1 = 0;
	blackhawk_lamps.leng_trq_yellow_led2 = 0;
	blackhawk_lamps.leng_trq_yellow_led3 = 0;
	blackhawk_lamps.leng_trq_yellow_led4 = 0;
	blackhawk_lamps.leng_trq_yellow_led5 = 0;
	blackhawk_lamps.leng_trq_yellow_led6 = 0;

	// Red LEDs
	blackhawk_lamps.leng_trq_red_led1 = 0;
	blackhawk_lamps.leng_trq_red_led2 = 0;
	blackhawk_lamps.leng_trq_red_led3 = 0;
	blackhawk_lamps.leng_trq_red_led4 = 0;
}
void clear_reng_trq_leds (void)
{
	// Green LEDs
	blackhawk_lamps.reng_trq_green_led1  = 0;
	blackhawk_lamps.reng_trq_green_led2  = 0;
	blackhawk_lamps.reng_trq_green_led3  = 0;
	blackhawk_lamps.reng_trq_green_led4  = 0;
	blackhawk_lamps.reng_trq_green_led5  = 0;
	blackhawk_lamps.reng_trq_green_led6  = 0;
	blackhawk_lamps.reng_trq_green_led7  = 0;
	blackhawk_lamps.reng_trq_green_led8  = 0;
	blackhawk_lamps.reng_trq_green_led9  = 0;
	blackhawk_lamps.reng_trq_green_led10 = 0;
	blackhawk_lamps.reng_trq_green_led11 = 0;
	blackhawk_lamps.reng_trq_green_led12 = 0;
	blackhawk_lamps.reng_trq_green_led13 = 0;
	blackhawk_lamps.reng_trq_green_led14 = 0;
	blackhawk_lamps.reng_trq_green_led15 = 0;
	blackhawk_lamps.reng_trq_green_led16 = 0;
	blackhawk_lamps.reng_trq_green_led17 = 0;
	blackhawk_lamps.reng_trq_green_led18 = 0;
	blackhawk_lamps.reng_trq_green_led19 = 0;
	blackhawk_lamps.reng_trq_green_led20 = 0;

	// Yellow LEDs
	blackhawk_lamps.reng_trq_yellow_led1 = 0;
	blackhawk_lamps.reng_trq_yellow_led2 = 0;
	blackhawk_lamps.reng_trq_yellow_led3 = 0;
	blackhawk_lamps.reng_trq_yellow_led4 = 0;
	blackhawk_lamps.reng_trq_yellow_led5 = 0;
	blackhawk_lamps.reng_trq_yellow_led6 = 0;

	// Red LEDs
	blackhawk_lamps.reng_trq_red_led1 = 0;
	blackhawk_lamps.reng_trq_red_led2 = 0;
	blackhawk_lamps.reng_trq_red_led3 = 0;
	blackhawk_lamps.reng_trq_red_led4 = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void update_rtr_rpm_leds(void)
{
	float
		rtr_rpm;

	clear_rtr_rpm_leds ();

	rtr_rpm = bound(current_flight_dynamics->main_rotor_rpm.value, 0.0, 110.0);

	if (rtr_rpm > 0 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led1 = 1;
//			blackhawk_lamps.rtr_rpm_cp_red_led1 = 1;
		}
	if (rtr_rpm >= 10 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led2 = 1;
		}
	if (rtr_rpm >= 20 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led3 = 1;
		}
	if (rtr_rpm >= 30 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led4 = 1;
		}
	if (rtr_rpm >= 40 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led5 = 1;
		}
	if (rtr_rpm >= 50 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led6 = 1;
		}
	if (rtr_rpm >= 60 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led7 = 1;
		}
	if (rtr_rpm >= 70 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led8 = 1;
		}
	if (rtr_rpm >= 75 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led9 = 1;
		}
	if (rtr_rpm >= 80 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led10 = 1;
		}
	if (rtr_rpm >= 85 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led11 = 1;
		}
	if (rtr_rpm >= 90 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_red_led12 = 1;
		}
	if (rtr_rpm >= 91 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_yellow_led1 = 1;
		}
	if (rtr_rpm >= 92 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_yellow_led2 = 1;
		}
	if (rtr_rpm >= 93 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_yellow_led3 = 1;
		}
	if (rtr_rpm >= 94 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_yellow_led4 = 1;
		}
	if (rtr_rpm >= 95 && rtr_rpm < 96)
		{
			blackhawk_lamps.rtr_rpm_yellow_led5 = 1;
		}
	if (rtr_rpm > 96)
		{
			blackhawk_lamps.rtr_rpm_green_led1 = 1;
		}
	if (rtr_rpm > 97)
		{
			blackhawk_lamps.rtr_rpm_green_led2 = 1;
		}
	if (rtr_rpm > 98)
		{
			blackhawk_lamps.rtr_rpm_green_led3 = 1;
		}
	if (rtr_rpm > 99)
		{
			blackhawk_lamps.rtr_rpm_green_led4 = 1;
		}
	if (rtr_rpm == 100)
		{
			blackhawk_lamps.rtr_rpm_green_led5 = 1;
		}
	if (rtr_rpm > 101)
		{
			blackhawk_lamps.rtr_rpm_yellow_led6 = 1;
		}
	if (rtr_rpm > 102)
		{
			blackhawk_lamps.rtr_rpm_yellow_led7 = 1;
		}
	if (rtr_rpm > 103)
		{
			blackhawk_lamps.rtr_rpm_yellow_led8 = 1;
		}
	if (rtr_rpm > 104)
		{
			blackhawk_lamps.rtr_rpm_yellow_led9 = 1;
		}
	if (rtr_rpm > 105)
		{
			blackhawk_lamps.rtr_rpm_red_led13 = 1;
		}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void update_leng_rpm_leds(void)
{
	float
		leng_rpm;

	clear_leng_rpm_leds ();

	leng_rpm = bound(current_flight_dynamics->left_engine_rpm.value, 0.0, 120.0);

	if (leng_rpm > 0 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led1 = 1;
		}
	if (leng_rpm >= 10 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led2 = 1;
		}
	if (leng_rpm >= 20 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led3 = 1;
		}
	if (leng_rpm >= 30 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led4 = 1;
		}
	if (leng_rpm >= 40 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led5 = 1;
		}
	if (leng_rpm >= 50 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led6 = 1;
		}
	if (leng_rpm >= 60 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led7 = 1;
		}
	if (leng_rpm >= 70 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led8 = 1;
		}
	if (leng_rpm >= 75 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led9 = 1;
		}
	if (leng_rpm >= 80 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led10 = 1;
		}
	if (leng_rpm >= 85 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led11 = 1;
		}
	if (leng_rpm >= 90 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_red_led12 = 1;
		}
	if (leng_rpm >= 91 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_yellow_led1 = 1;
		}
	if (leng_rpm >= 92 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_yellow_led2 = 1;
		}
	if (leng_rpm >= 93 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_yellow_led3 = 1;
		}
	if (leng_rpm >= 94 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_yellow_led4 = 1;
		}
	if (leng_rpm >= 95 && leng_rpm < 96)
		{
			blackhawk_lamps.leng_rpm_yellow_led5 = 1;
		}
	if (leng_rpm > 96)
		{
			blackhawk_lamps.leng_rpm_green_led1 = 1;
		}
	if (leng_rpm > 97)
		{
			blackhawk_lamps.leng_rpm_green_led2 = 1;
		}
	if (leng_rpm > 98)
		{
			blackhawk_lamps.leng_rpm_green_led3 = 1;
		}
	if (leng_rpm > 99)
		{
			blackhawk_lamps.leng_rpm_green_led4 = 1;
		}
	if (leng_rpm > 100)
		{
			blackhawk_lamps.leng_rpm_green_led5 = 1;
		}
	if (leng_rpm > 101)
		{
			blackhawk_lamps.leng_rpm_yellow_led6 = 1;
		}
	if (leng_rpm > 102)
		{
			blackhawk_lamps.leng_rpm_yellow_led7 = 1;
		}
	if (leng_rpm > 103)
		{
			blackhawk_lamps.leng_rpm_yellow_led8 = 1;
		}
	if (leng_rpm > 104)
		{
			blackhawk_lamps.leng_rpm_yellow_led9 = 1;
		}
	if (leng_rpm > 105)
		{
			blackhawk_lamps.leng_rpm_red_led13 = 1;
		}
	if (leng_rpm > 106)
		{
			blackhawk_lamps.leng_rpm_red_led14 = 1;
		}
	if (leng_rpm > 107)
		{
			blackhawk_lamps.leng_rpm_red_led15 = 1;
		}
	if (leng_rpm > 108)
		{
			blackhawk_lamps.leng_rpm_red_led16 = 1;
		}
	if (leng_rpm > 109)
		{
			blackhawk_lamps.leng_rpm_red_led17 = 1;
		}
	if (leng_rpm > 110)
		{
			blackhawk_lamps.leng_rpm_red_led18 = 1;
		}
	if (leng_rpm > 111)
		{
			blackhawk_lamps.leng_rpm_red_led19 = 1;
		}
	if (leng_rpm > 112)
		{
			blackhawk_lamps.leng_rpm_red_led20 = 1;
		}
	if (leng_rpm > 113)
		{
			blackhawk_lamps.leng_rpm_red_led21 = 1;
		}
	if (leng_rpm > 115)
		{
			blackhawk_lamps.leng_rpm_red_led22 = 1;
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void update_reng_rpm_leds(void)
{
	float
		reng_rpm;

	clear_reng_rpm_leds ();

	reng_rpm = bound(current_flight_dynamics->right_engine_rpm.value, 0.0, 120.0);

	if (reng_rpm > 0 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led1 = 1;
		}
	if (reng_rpm >= 10 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led2 = 1;
		}
	if (reng_rpm >= 20 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led3 = 1;
		}
	if (reng_rpm >= 30 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led4 = 1;
		}
	if (reng_rpm >= 40 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led5 = 1;
		}
	if (reng_rpm >= 50 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led6 = 1;
		}
	if (reng_rpm >= 60 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led7 = 1;
		}
	if (reng_rpm >= 70 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led8 = 1;
		}
	if (reng_rpm >= 75 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led9 = 1;
		}
	if (reng_rpm >= 80 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led10 = 1;
		}
	if (reng_rpm >= 85 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led11 = 1;
		}
	if (reng_rpm >= 90 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_red_led12 = 1;
		}
	if (reng_rpm >= 91 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_yellow_led1 = 1;
		}
	if (reng_rpm >= 92 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_yellow_led2 = 1;
		}
	if (reng_rpm >= 93 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_yellow_led3 = 1;
		}
	if (reng_rpm >= 94 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_yellow_led4 = 1;
		}
	if (reng_rpm >= 95 && reng_rpm < 96)
		{
			blackhawk_lamps.reng_rpm_yellow_led5 = 1;
		}
	if (reng_rpm > 96)
		{
			blackhawk_lamps.reng_rpm_green_led1 = 1;
		}
	if (reng_rpm > 97)
		{
			blackhawk_lamps.reng_rpm_green_led2 = 1;
		}
	if (reng_rpm > 98)
		{
			blackhawk_lamps.reng_rpm_green_led3 = 1;
		}
	if (reng_rpm > 99)
		{
			blackhawk_lamps.reng_rpm_green_led4 = 1;
		}
	if (reng_rpm > 100)
		{
			blackhawk_lamps.reng_rpm_green_led5 = 1;
		}
	if (reng_rpm > 101)
		{
			blackhawk_lamps.reng_rpm_yellow_led6 = 1;
		}
	if (reng_rpm > 102)
		{
			blackhawk_lamps.reng_rpm_yellow_led7 = 1;
		}
	if (reng_rpm > 103)
		{
			blackhawk_lamps.reng_rpm_yellow_led8 = 1;
		}
	if (reng_rpm > 104)
		{
			blackhawk_lamps.reng_rpm_yellow_led9 = 1;
		}
	if (reng_rpm > 105)
		{
			blackhawk_lamps.reng_rpm_red_led13 = 1;
		}
	if (reng_rpm > 106)
		{
			blackhawk_lamps.reng_rpm_red_led14 = 1;
		}
	if (reng_rpm > 107)
		{
			blackhawk_lamps.reng_rpm_red_led15 = 1;
		}
	if (reng_rpm > 108)
		{
			blackhawk_lamps.reng_rpm_red_led16 = 1;
		}
	if (reng_rpm > 109)
		{
			blackhawk_lamps.reng_rpm_red_led17 = 1;
		}
	if (reng_rpm > 110)
		{
			blackhawk_lamps.reng_rpm_red_led18 = 1;
		}
	if (reng_rpm > 111)
		{
			blackhawk_lamps.reng_rpm_red_led19 = 1;
		}
	if (reng_rpm > 112)
		{
			blackhawk_lamps.reng_rpm_red_led20 = 1;
		}
	if (reng_rpm > 113)
		{
			blackhawk_lamps.reng_rpm_red_led21 = 1;
		}
	if (reng_rpm > 115)
		{
			blackhawk_lamps.reng_rpm_red_led22 = 1;
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void update_leng_trq_leds(void)
{
	float
		leng_trq;

	clear_leng_trq_leds();

	leng_trq = bound(current_flight_dynamics->left_engine_torque.value, 0.0, 120.0);

	if (leng_trq > 5 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led1 = 1;
		}
	if (leng_trq > 10 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led2 = 1;
		}
	if (leng_trq > 15 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led3 = 1;
		}
	if (leng_trq > 20 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led4 = 1;
		}
	if (leng_trq > 25 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led5 = 1;
		}
	if (leng_trq > 30 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led6 = 1;
		}
	if (leng_trq > 35 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led7 = 1;
		}
	if (leng_trq > 40 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led8 = 1;
		}
	if (leng_trq > 45 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led9 = 1;
		}
	if (leng_trq > 50 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led10 = 1;
		}
	if (leng_trq > 55 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led11 = 1;
		}
	if (leng_trq > 60 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led12 = 1;
		}
	if (leng_trq > 65 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led13 = 1;
		}
	if (leng_trq > 70 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led14 = 1;
		}
	if (leng_trq > 75 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led15 = 1;
		}
	if (leng_trq > 80 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led16 = 1;
		}
	if (leng_trq > 85 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led17 = 1;
		}
	if (leng_trq > 90 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led18 = 1;
		}
	if (leng_trq > 95 && leng_trq < 100)
		{
			blackhawk_lamps.leng_trq_green_led19 = 1;
		}
	if (leng_trq > 100)
		{
			blackhawk_lamps.leng_trq_green_led20 = 1;
		}
	if (leng_trq > 105)
		{
			blackhawk_lamps.leng_trq_yellow_led1 = 1;
		}
	if (leng_trq > 110)
		{
			blackhawk_lamps.leng_trq_yellow_led2 = 1;
		}
	if (leng_trq > 115)
		{
			blackhawk_lamps.leng_trq_yellow_led3 = 1;
		}
	if (leng_trq > 120)
		{
			blackhawk_lamps.leng_trq_yellow_led4 = 1;
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void update_reng_trq_leds(void)
{
	float
		reng_trq;

	clear_reng_trq_leds();

	reng_trq = bound(current_flight_dynamics->right_engine_torque.value, 0.0, 120.0);

	if (reng_trq > 5 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led1 = 1;
		}
	if (reng_trq > 10 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led2 = 1;
		}
	if (reng_trq > 15 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led3 = 1;
		}
	if (reng_trq > 20 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led4 = 1;
		}
	if (reng_trq > 25 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led5 = 1;
		}
	if (reng_trq > 30 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led6 = 1;
		}
	if (reng_trq > 35 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led7 = 1;
		}
	if (reng_trq > 40 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led8 = 1;
		}
	if (reng_trq > 45 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led9 = 1;
		}
	if (reng_trq > 50 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led10 = 1;
		}
	if (reng_trq > 55 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led11 = 1;
		}
	if (reng_trq > 60 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led12 = 1;
		}
	if (reng_trq > 65 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led13 = 1;
		}
	if (reng_trq > 70 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led14 = 1;
		}
	if (reng_trq > 75 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led15 = 1;
		}
	if (reng_trq > 80 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led16 = 1;
		}
	if (reng_trq > 85 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led17 = 1;
		}
	if (reng_trq > 90 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led18 = 1;
		}
	if (reng_trq > 95 && reng_trq < 100)
		{
			blackhawk_lamps.reng_trq_green_led19 = 1;
		}
	if (reng_trq > 100)
		{
			blackhawk_lamps.reng_trq_green_led20 = 1;
		}
	if (reng_trq > 105)
		{
			blackhawk_lamps.reng_trq_yellow_led1 = 1;
		}
	if (reng_trq > 110)
		{
			blackhawk_lamps.reng_trq_yellow_led2 = 1;
		}
	if (reng_trq > 115)
		{
			blackhawk_lamps.reng_trq_yellow_led3 = 1;
		}
	if (reng_trq > 120)
		{
			blackhawk_lamps.reng_trq_yellow_led4 = 1;
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Note that all lamps are extinguished in initialise_blackhawk_lamps ().
//

void initialise_blackhawk_lamp_avionics (void)
{
	initialise_master_caution ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_blackhawk_lamp_avionics (void)
{
	deinitialise_master_caution ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_blackhawk_lamp_avionics (void)
{
	entity
		*en;

	en = get_gunship_entity ();

	update_master_caution ();

	update_rtr_rpm_leds ();

	update_leng_rpm_leds ();

	update_reng_rpm_leds ();

	update_leng_trq_leds ();

	update_reng_trq_leds ();

	////////////////////////////////////////

	blackhawk_lamps.engine_ignition = !get_dynamics_damage_type (DYNAMICS_DAMAGE_LEFT_ENGINE) && current_flight_dynamics->left_engine_rpm.value > 0.01;

	blackhawk_lamps.apu_ignition = current_flight_dynamics->apu_rpm.value > 0.01;

	blackhawk_lamps.engine_fire = get_dynamics_damage_type (DYNAMICS_DAMAGE_LEFT_ENGINE_FIRE);

	blackhawk_lamps.apu_fire = 0;

	blackhawk_lamps.engine_fire_extinguiser = fire_extinguisher_used;

	blackhawk_lamps.hydraulic_pressure = get_dynamics_damage_type (DYNAMICS_DAMAGE_LOW_HYDRAULICS);

	blackhawk_lamps.oil_pressure = get_dynamics_damage_type (DYNAMICS_DAMAGE_LOW_OIL_PRESSURE) || get_dynamics_damage_type (DYNAMICS_DAMAGE_HIGH_OIL_PRESSURE);

	blackhawk_lamps.oil_temperature = 0;

	blackhawk_lamps.overtorque = get_current_flight_dynamics_overtorque ();

	blackhawk_lamps.rotor_rpm = get_current_flight_dynamics_low_rotor_rpm ();

	blackhawk_lamps.fuel_low = current_flight_dynamics->fuel_weight.value < (current_flight_dynamics->fuel_weight.max * 0.25);

	blackhawk_lamps.rotor_brake = get_current_flight_dynamics_rotor_brake ();

	blackhawk_lamps.navigation_lights = get_local_entity_int_value (en, INT_TYPE_LIGHTS_ON);

	blackhawk_lamps.hover_hold = get_current_flight_dynamics_auto_hover ();

	blackhawk_lamps.altitude_hold = get_current_flight_dynamics_altitude_lock ();

	blackhawk_lamps.auto_pilot = get_current_flight_dynamics_auto_pilot ();

	blackhawk_lamps.laser = get_local_entity_int_value (en, INT_TYPE_LASER_ON);

	blackhawk_lamps.ir_jammer = get_local_entity_int_value (en, INT_TYPE_INFRA_RED_JAMMER_ON);

	blackhawk_lamps.auto_counter_measures = get_global_auto_counter_measures ();

	blackhawk_lamps.ase_auto_page = get_global_ase_auto_page ();

	blackhawk_lamps.pilot_main_mfd_focus = get_blackhawk_mfd_has_focus (BLACKHAWK_MFD_LOCATION_PILOT_MAIN);

	blackhawk_lamps.co_pilot_main_mfd_focus = get_blackhawk_mfd_has_focus (BLACKHAWK_MFD_LOCATION_CO_PILOT_MAIN);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
