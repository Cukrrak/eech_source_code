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

#define VIEWPORT_WIDTH		(84.0)
#define VIEWPORT_HEIGHT		(40.0)

#define LINE_LENGTH  36

#define MAX_STRING_LENGTH	(12)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static rgb_colour
	text_colour,
	clear_colour;

static screen
	*ng_screen,
	*tgt_screen,
	*trq_screen,
	*fuel_quantity_screen,
	*chaff_flare_screen;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//static void display_messages (float x_org, float y_org)
//{
//	float y = 1.0;
//	int i=0;
//	char buffer[64];
//
//	set_mono_font_type(MONO_FONT_TYPE_6X10);
//	set_mono_font_colour(text_colour);
//
//	for (i=0; i<5; i++)
//	{
//		snprintf(buffer, LINE_LENGTH+1, "%-11s|%-11s|%-12s",
//			warnings[(last_warning + i) % 5], cautions[(last_caution + i) % 5], advisories[(last_advisory + i) % 5]);
//
//		set_mono_font_position(0.0, y);
//		set_mono_font_rel_position(0.0, 0.0);
//
//		print_mono_font_string(buffer);
//		y += 10;
//	}
//
//	for (i=0; i<4; i++)
//	{
//		set_mono_font_position(0.0, y);
//		set_mono_font_rel_position(0.0, 0.0);
//
//		print_mono_font_string(radio_freqs[i]);
//		y += 10;
//	}
//
//	{
//		float hours, minutes, seconds;
//		float time_of_day = get_local_entity_float_value (get_session_entity (), FLOAT_TYPE_TIME_OF_DAY);
//		get_digital_clock_values (time_of_day, &hours, &minutes, &seconds);
//
//		snprintf(buffer, LINE_LENGTH+1, "%s %02d:%02d:%02d L", radio_freqs[4], (int) hours, (int) minutes, (int) seconds);
//
//		set_mono_font_position(0.0, y);
//		set_mono_font_rel_position(0.0, 0.0);
//
//		print_mono_font_string(buffer);
//	}
//#if 0
//	float
//		x_min,
//		y_min,
//		x_max,
//		y_max,
//		y_line1,
//		y_line2,
//		y_line3,
//		y_line4;
//
//	if (!electrical_system_active())
//		return;
//
//	x_min = x_org;
//	y_min = y_org;
//	x_max = x_org + VIEWPORT_WIDTH;
//	y_max = y_org + VIEWPORT_HEIGHT;
//
//	set_viewport (x_min, y_min, x_max, y_max);
//
//	y_line1 = y_org;
//	y_line2 = y_org + 10.0;
//	y_line3 = y_org + 20.0;
//	y_line4 = y_org + 30.0;
//
//	set_mono_font_type (MONO_FONT_TYPE_5X9);
//
//	set_mono_font_colour (text_colour);
//
//	set_mono_font_position (x_min, y_line1);
//
//	print_mono_font_string (line1);
//
//	set_mono_font_position (x_min, y_line2);
//
//	print_mono_font_string (line2);
//
//	set_mono_font_position (x_min, y_line3);
//
//	print_mono_font_string (line3);
//
//	set_mono_font_position (x_min, y_line4);
//
//	print_mono_font_string (line4);
//#endif
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void display_ng (void)
{
	float y = 1.0;
	char buffer[64];

	set_mono_font_type(MONO_FONT_TYPE_17X26_DIGITAL);
	set_mono_font_colour(text_colour);

	sprintf (buffer, "%d %d", (int) (bound(current_flight_dynamics->left_engine_n1_rpm.value, 0.0, 120.0)*10),
			(int) (bound(current_flight_dynamics->right_engine_n1_rpm.value, 0.0, 120.0)*10));

	set_mono_font_position(0.0, y);
	set_mono_font_rel_position(0.0, 0.0);

	print_mono_font_string(buffer);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void display_tgt (void)
{
	float y = 1.0;
	char buffer[64];

	set_mono_font_type(MONO_FONT_TYPE_17X26_DIGITAL);
	set_mono_font_colour(text_colour);

	sprintf (buffer, "%d %d", (int) (bound(current_flight_dynamics->left_engine_temp.value, 0.0, 1000.0)),
			(int) (bound(current_flight_dynamics->right_engine_temp.value, 0.0, 1000.0)));

	set_mono_font_position(0.0, y);
	set_mono_font_rel_position(0.0, 0.0);

	print_mono_font_string(buffer);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void display_trq (void)
{
	float y = 1.0;
	char buffer[64];

	set_mono_font_type(MONO_FONT_TYPE_17X26_DIGITAL);
	set_mono_font_colour(text_colour);

	sprintf (buffer, "%02d %02d", (int) (bound(current_flight_dynamics->left_engine_torque.value, 0.0, 120.0)),
							(int) (bound(current_flight_dynamics->right_engine_torque.value, 0.0, 120.0)));

	set_mono_font_position(0.0, y);
	set_mono_font_rel_position(0.0, 0.0);

	print_mono_font_string(buffer);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void display_fuel (void)
{
	float y = 1.0;
	char buffer[64];

	set_mono_font_type(MONO_FONT_TYPE_17X26_DIGITAL);
	set_mono_font_colour(text_colour);

	sprintf (buffer, "%d", (int) (bound (kilograms_to_pounds (current_flight_dynamics->fuel_weight.value), 0.0, 2500.0)));

	set_mono_font_position(0.0, y);
	set_mono_font_rel_position(-1.0, 0.0);

	print_mono_font_string(buffer);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void display_chaff_flare (void)
{
	float y = 1.0;
	char buffer[64];

//	int
//		lh_chaff,
//		rh_chaff,
//		lh_chaff_number,
//		rh_chaff_number,
//		total_chaff,
//		lh_flare,
//		rh_flare,
//		lh_flare_number,
//		rh_flare_number,
//		total_flare,
//		damaged;

	entity
		*en;

//	entity_sub_types
//		weapon_sub_type;

	en = get_gunship_entity ();

	set_mono_font_type(MONO_FONT_TYPE_17X26_DIGITAL);
	set_mono_font_colour(text_colour);

	sprintf (buffer, "%d          %d", get_local_entity_weapon_count (en, ENTITY_SUB_TYPE_WEAPON_CHAFF), get_local_entity_weapon_count (en, ENTITY_SUB_TYPE_WEAPON_FLARE));

//	lh_chaff = get_local_entity_weapon_hardpoint_info (en, BLACKHAWK_LHS_CHAFF_DISPENSER, ENTITY_SUB_TYPE_WEAPON_CHAFF, &weapon_sub_type, &lh_chaff_number, &damaged);
//	rh_chaff = get_local_entity_weapon_hardpoint_info (en, BLACKHAWK_RHS_CHAFF_DISPENSER, ENTITY_SUB_TYPE_WEAPON_CHAFF, &weapon_sub_type, &rh_chaff_number, &damaged);
//	lh_flare = get_local_entity_weapon_hardpoint_info (en, BLACKHAWK_LHS_FLARE_DISPENSER, ENTITY_SUB_TYPE_WEAPON_CHAFF, &weapon_sub_type, &lh_flare_number, &damaged);
//	rh_flare = get_local_entity_weapon_hardpoint_info (en, BLACKHAWK_RHS_FLARE_DISPENSER, ENTITY_SUB_TYPE_WEAPON_CHAFF, &weapon_sub_type, &rh_flare_number, &damaged);
//
//	if (lh_chaff || rh_chaff || lh_flare || rh_flare)
//	{
//		if (!damaged)
//		{
////			total_chaff = lh_chaff_number + rh_chaff_number;
////			total_flare = lh_flare_number + rh_flare_number;
//
//			sprintf (buffer, "%d %d", get_local_entity_weapon_count (en, ENTITY_SUB_TYPE_WEAPON_CHAFF), get_local_entity_weapon_count (en, ENTITY_SUB_TYPE_WEAPON_FLARE));
//		}
////		else if (damaged)
////			{
////				if (blackhawk_damage.lh_chaff_dispenser)
////				{
////					total_chaff = rh_chaff_number;
////					total_flare = lh_flare_number + rh_flare_number;
////
////					sprintf (buffer, "%d %d", total_chaff, total_flare);
////				}
////
////				if (blackhawk_damage.rh_chaff_dispenser)
////				{
////					total_chaff = lh_chaff_number;
////					total_flare = lh_flare_number + rh_flare_number;
////
////					sprintf (buffer, "%d %d", total_chaff, total_flare);
////				}
////
////				if (blackhawk_damage.lh_flare_dispenser)
////				{
////					total_chaff = lh_chaff_number + rh_chaff_number;
////					total_flare = rh_flare_number;
////
////					sprintf (buffer, "%d %d", total_chaff, total_flare);
////				}
////
////				if (blackhawk_damage.rh_flare_dispenser)
////				{
////					total_chaff = lh_chaff_number + rh_chaff_number;
////					total_flare = lh_flare_number;
////
////					sprintf (buffer, "%d %d", total_chaff, total_flare);
////				}
////
////				if (blackhawk_damage.lh_chaff_dispenser && blackhawk_damage.rh_chaff_dispenser)
////				{
////					sprintf (buffer, "XX %d", total_flare);
////				}
////				else if (blackhawk_damage.lh_flare_dispenser && blackhawk_damage.rh_flare_dispenser)
////					{
////						sprintf (buffer, "%d XX", total_chaff);
////					}
////			}
//	}

	set_mono_font_position(0.0, y);
	set_mono_font_rel_position(15.0, 0.0);

	print_mono_font_string(buffer);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_blackhawk_upfront_display (void)
{
	ng_screen = create_system_texture_screen (125, 26, TEXTURE_INDEX_HOKUM_COCKPIT_MFD_RHS_1, TEXTURE_TYPE_SINGLEALPHA);

	tgt_screen = create_system_texture_screen (125, 26, TEXTURE_INDEX_HOKUM_COCKPIT_MFD_LHS_1, TEXTURE_TYPE_SINGLEALPHA);

	trq_screen = create_system_texture_screen (125, 26, TEXTURE_INDEX_AVCKPT_DISPLAY_LHS_MFD, TEXTURE_TYPE_SINGLEALPHA);

	fuel_quantity_screen = create_system_texture_screen (69, 26, TEXTURE_INDEX_AVCKPT_DISPLAY_UPFRONT, TEXTURE_TYPE_SINGLEALPHA);

	chaff_flare_screen = create_system_texture_screen (140, 26, TEXTURE_INDEX_COMANCHE_MFD1, TEXTURE_TYPE_SINGLEALPHA);

	set_rgb_colour (text_colour, 65, 211, 42, 255);

	set_rgb_colour (clear_colour, 180, 240, 0, 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_blackhawk_upfront_display (void)
{
	destroy_screen (ng_screen);
	destroy_screen (tgt_screen);
	destroy_screen (trq_screen);
	destroy_screen (fuel_quantity_screen);
	destroy_screen (chaff_flare_screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_blackhawk_upfront_display (void)
{

//	if (!electrical_system_active())
//		return;
#if 0
	time_of_day = get_local_entity_float_value (get_session_entity (), FLOAT_TYPE_TIME_OF_DAY);

	get_digital_clock_values (time_of_day, &hours, &minutes, &seconds);

	sprintf (s1, "%02d:%02d:%02d", (int) hours, (int) minutes, (int) seconds);

	sprintf (s2, "FUEL %04d LBS", (int) (bound (kilograms_to_pounds (current_flight_dynamics->fuel_weight.value), 0.0, 2500.0)));

	set_blackhawk_upfront_display_text (NULL, NULL, s1, s2);
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void draw_blackhawk_upfront_display_on_cockpit (float x_org, float y_org)
//{
//	if (lock_screen (active_screen))
//	{
//		display_messages (x_org, y_org);
//
//		unlock_screen (active_screen);
//	}
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_blackhawk_upfront_display_on_texture (void)
{
	draw_ng_display_on_texture();
	draw_tgt_display_on_texture();
	draw_trq_display_on_texture();
	draw_fuel_display_on_texture();
	draw_chaff_flare_display_on_texture();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_ng_display_on_texture (void)
{
	set_active_screen (ng_screen);

	if (lock_screen (ng_screen))
	{
		set_block (0, 0, (ng_screen->width-1), (ng_screen->height-1), clear_colour);

		display_ng ();

		unlock_screen (ng_screen);
	}

	set_active_screen (video_screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//void draw_right_ng_display_on_texture (void)
//{
//	set_active_screen (right_ng_screen);
//
//	if (lock_screen (right_ng_screen))
//	{
//		set_block (0, 0, (right_ng_screen->width-1), (right_ng_screen->height-1), clear_colour);
//
//		display_right_ng ();
//
//		unlock_screen (right_ng_screen);
//	}
//
//	set_active_screen (video_screen);
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_tgt_display_on_texture (void)
{
	set_active_screen (tgt_screen);

	if (lock_screen (tgt_screen))
	{
		set_block (0, 0, (tgt_screen->width-1), (tgt_screen->height-1), clear_colour);

		display_tgt ();

		unlock_screen (tgt_screen);
	}

	set_active_screen (video_screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_trq_display_on_texture (void)
{
	set_active_screen (trq_screen);

	if (lock_screen (trq_screen))
	{
		set_block (0, 0, (trq_screen->width-1), (trq_screen->height-1), clear_colour);

		display_trq ();

		unlock_screen (trq_screen);
	}

	set_active_screen (video_screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_fuel_display_on_texture (void)
{
	set_active_screen (fuel_quantity_screen);

	if (lock_screen (fuel_quantity_screen))
	{
		set_block (0, 0, (fuel_quantity_screen->width-1), (fuel_quantity_screen->height-1), clear_colour);

		display_fuel ();

		unlock_screen (fuel_quantity_screen);
	}

	set_active_screen (video_screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_chaff_flare_display_on_texture (void)
{
	set_active_screen (chaff_flare_screen);

	if (lock_screen (chaff_flare_screen))
	{
		set_block (0, 0, (chaff_flare_screen->width-1), (chaff_flare_screen->height-1), clear_colour);

		display_chaff_flare ();

		unlock_screen (chaff_flare_screen);
	}

	set_active_screen (video_screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// note: NULL == do not overwrite, "" == overwrite with blank message
//

void set_blackhawk_upfront_display_text (char *s1, char *s2, char *s3, char *s4)
{
#if 0
	if (s1)
	{
		strncpy (line1, s1, MAX_STRING_LENGTH);

		line1[MAX_STRING_LENGTH] = '\0';
	}

	if (s2)
	{
		strncpy (line2, s2, MAX_STRING_LENGTH);

		line2[MAX_STRING_LENGTH] = '\0';
	}

	if (s3)
	{
		strncpy (line3, s3, MAX_STRING_LENGTH);

		line3[MAX_STRING_LENGTH] = '\0';
	}

	if (s4)
	{
		strncpy (line4, s4, MAX_STRING_LENGTH);

		line4[MAX_STRING_LENGTH] = '\0';
	}

	if (command_line_shared_mem_export != 0)

		update_upfront_display_shared_mem(s1, s2, s3, s4);	//  Javelin  7/19
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void clear_blackhawk_upfront_display(void)
{

}
