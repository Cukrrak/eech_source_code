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

extern void get_hind_virtual_cockpit_hsi_needle_values (float *direction_finder, float *flight_path, float *drift);

extern float get_mi24_airspeed_needle_value(void);
extern float get_mi24_vertical_velocity_needle_value(void);
extern float get_mi24_pitch_ladder_dispacement(void);
extern void get_mi24_hover_indicator_speed(float* longitudinal, float* sideways);
extern float get_mi24_hover_indicator_vvi_needle_value(void);
extern float get_mi24_radar_altimeter_needle_value(void);
extern void get_mi24_barometric_altimeter_needle_values(float* shrt, float* lng);
extern float get_mi24_rpm_needle_value(float rpm);
extern void get_mi24_epr_needle_values(float* limits, float* left, float* right);
extern void get_mi24_temperature_needle_values(float temp, float* big_needle, float* small_needle);
extern float get_mi24_compass_waypoint_needle_value(void);
extern float get_mi24_compass_waypoint_needle_heading_value(void);
extern void get_mi24_clock_hand_values(float* hour_hand, float* minute_hand, float* second_hand);
extern void get_mi24_hydraulic_pressure_values(float* gear, float* primary, float* secondary);
extern void update_mi24_waypoint_indicator(float* indicator);
extern void update_mi24_weapon_status_lights(object_3d_sub_instance* ready, object_3d_sub_instance* not_ready, object_3d_sub_instance* min_range);

extern float get_mi24_apu_rpm_needle_value(void);
extern void get_mi24_engine_select_switch_value(float* current_val);
extern float get_mi24_rocket_salvo_switch_value(void);
extern float get_mi24_sidewind_needle_value(void);
extern float get_mi24_fuel_quantity_needle_value(void);
extern void update_mi24_engine_gauges(float* left_temp, float* right_temp, float* left_pressure, float* right_pressure);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
