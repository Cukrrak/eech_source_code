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



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "project.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float
	mouse_sensitivity = 25.0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cyclic_left (event *ev)
{

	if (!current_flight_dynamics)
	{

		return;
	}

	if (ev->state == KEY_STATE_DOWN)
	{

		current_flight_dynamics->input_data.cyclic_input_pressure |= CYCLIC_PRESSURE_LEFT;
	}
	else
	{

		current_flight_dynamics->input_data.cyclic_input_pressure ^= CYCLIC_PRESSURE_LEFT;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cyclic_right (event *ev)
{

	if (!current_flight_dynamics)
	{

		return;
	}

	if (ev->state == KEY_STATE_DOWN)
	{

		current_flight_dynamics->input_data.cyclic_input_pressure |= CYCLIC_PRESSURE_RIGHT;
	}
	else
	{

		current_flight_dynamics->input_data.cyclic_input_pressure ^= CYCLIC_PRESSURE_RIGHT;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cyclic_forward (event *ev)
{

	if (!current_flight_dynamics)
	{

		return;
	}

	if (ev->state == KEY_STATE_DOWN)
	{

		current_flight_dynamics->input_data.cyclic_input_pressure |= CYCLIC_PRESSURE_FORWARD;
	}
	else
	{

		current_flight_dynamics->input_data.cyclic_input_pressure ^= CYCLIC_PRESSURE_FORWARD;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cyclic_backward (event *ev)
{

	if (!current_flight_dynamics)
	{

		return;
	}

	if (ev->state == KEY_STATE_DOWN)
	{

		current_flight_dynamics->input_data.cyclic_input_pressure |= CYCLIC_PRESSURE_BACKWARD;
	}
	else
	{

		current_flight_dynamics->input_data.cyclic_input_pressure ^= CYCLIC_PRESSURE_BACKWARD;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cyclic_mouse_input (event *ev)
{

#if 1

	// make mouse act on pressures

	if (ev->dx > 0.0)
	{

		current_flight_dynamics->input_data.cyclic_horizontal_pressure.value = max (0.0, current_flight_dynamics->input_data.cyclic_horizontal_pressure.value);
	}
	else if (ev->dx < 0.0)
	{

		current_flight_dynamics->input_data.cyclic_horizontal_pressure.value = min (0.0, current_flight_dynamics->input_data.cyclic_horizontal_pressure.value);
	}

	if (ev->dy > 0.0)
	{

		current_flight_dynamics->input_data.cyclic_vertical_pressure.value = max (0.0, current_flight_dynamics->input_data.cyclic_vertical_pressure.value);
	}
	else if (ev->dy < 0.0)
	{

		current_flight_dynamics->input_data.cyclic_vertical_pressure.value = min (0.0, current_flight_dynamics->input_data.cyclic_vertical_pressure.value);
	}

	current_flight_dynamics->input_data.cyclic_horizontal_pressure.value += (float) (ev->dx) * (mouse_sensitivity / 50.0);

	current_flight_dynamics->input_data.cyclic_vertical_pressure.value -= (float) (ev->dy) * (mouse_sensitivity / 50.0);

#else

	// make mouse act on cyclic values

	current_flight_dynamics->input_data.cyclic_x.value += (float) (ev->dx) * mouse_sensitivity / 50.0;

	current_flight_dynamics->input_data.cyclic_y.value -= (float) (ev->dy) * mouse_sensitivity / 50.0;

#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_cyclic_pressure_inputs (void)
{

	float
		trim_x,
		trim_y;

	if (!current_flight_dynamics)
	{

		return;
	}

	trim_x = current_flight_dynamics->input_data.cyclic_x_trim.value;
	trim_y = current_flight_dynamics->input_data.cyclic_y_trim.value;

	switch (get_global_cyclic_input ())
	{

		case KEYBOARD_INPUT:
		case MOUSE_INPUT:
		{
		
			if (current_flight_dynamics->input_data.cyclic_input_pressure & CYCLIC_PRESSURE_LEFT)
			{
		
				current_flight_dynamics->input_data.cyclic_horizontal_pressure.value = min (0.0, current_flight_dynamics->input_data.cyclic_horizontal_pressure.value);
		
				current_flight_dynamics->input_data.cyclic_x.value = min ((current_flight_dynamics->input_data.cyclic_x.value) / 2.0, current_flight_dynamics->input_data.cyclic_x.value);
		
				current_flight_dynamics->input_data.cyclic_horizontal_pressure.value -= MODEL_FRAME_RATE * get_model_delta_time ();

				if ((current_flight_dynamics->auto_hover == HOVER_HOLD_NORMAL) ||
					(current_flight_dynamics->auto_hover == HOVER_HOLD_STABLE))
				{

					set_current_flight_dynamics_auto_hover (HOVER_HOLD_NONE);
					set_current_flight_dynamics_auto_pilot (FALSE);
				}
			}
			else if (current_flight_dynamics->input_data.cyclic_input_pressure & CYCLIC_PRESSURE_RIGHT)
			{
		
				current_flight_dynamics->input_data.cyclic_horizontal_pressure.value = max (0.0, current_flight_dynamics->input_data.cyclic_horizontal_pressure.value);
		
				current_flight_dynamics->input_data.cyclic_x.value = max ((current_flight_dynamics->input_data.cyclic_x.value) / 2.0, current_flight_dynamics->input_data.cyclic_x.value);
		
				current_flight_dynamics->input_data.cyclic_horizontal_pressure.value += MODEL_FRAME_RATE * get_model_delta_time ();

				if ((current_flight_dynamics->auto_hover == HOVER_HOLD_NORMAL) ||
					(current_flight_dynamics->auto_hover == HOVER_HOLD_STABLE))
				{

					set_current_flight_dynamics_auto_hover (HOVER_HOLD_NONE);
					set_current_flight_dynamics_auto_pilot (FALSE);
				}
			}
			else
			{
		
				if (fabs (current_flight_dynamics->input_data.cyclic_horizontal_pressure.value) < 1.0)
				{
		
					current_flight_dynamics->input_data.cyclic_horizontal_pressure.value = 0.0;
				}
				else
				{
		
					current_flight_dynamics->input_data.cyclic_horizontal_pressure.value -= ((MODEL_FRAME_RATE * get_model_delta_time ()) / 2.0) * (current_flight_dynamics->input_data.cyclic_horizontal_pressure.value);
				}
			}
			
			if (current_flight_dynamics->input_data.cyclic_input_pressure & CYCLIC_PRESSURE_BACKWARD)
			{
		
				current_flight_dynamics->input_data.cyclic_vertical_pressure.value = min (0.0, current_flight_dynamics->input_data.cyclic_vertical_pressure.value);
		
				current_flight_dynamics->input_data.cyclic_y.value = min (current_flight_dynamics->input_data.cyclic_y.value / 2.0, current_flight_dynamics->input_data.cyclic_y.value);
		
				current_flight_dynamics->input_data.cyclic_vertical_pressure.value -= MODEL_FRAME_RATE * get_model_delta_time ();

				if ((current_flight_dynamics->auto_hover == HOVER_HOLD_NORMAL) ||
					(current_flight_dynamics->auto_hover == HOVER_HOLD_STABLE))
				{

					set_current_flight_dynamics_auto_hover (HOVER_HOLD_NONE);
					set_current_flight_dynamics_auto_pilot (FALSE);
				}
			}
			else if (current_flight_dynamics->input_data.cyclic_input_pressure & CYCLIC_PRESSURE_FORWARD)
			{
		
				current_flight_dynamics->input_data.cyclic_vertical_pressure.value = max (0.0, current_flight_dynamics->input_data.cyclic_vertical_pressure.value);
		
				current_flight_dynamics->input_data.cyclic_y.value = max (current_flight_dynamics->input_data.cyclic_y.value / 2.0, current_flight_dynamics->input_data.cyclic_y.value);
		
				current_flight_dynamics->input_data.cyclic_vertical_pressure.value += MODEL_FRAME_RATE * get_model_delta_time ();

				if ((current_flight_dynamics->auto_hover == HOVER_HOLD_NORMAL) ||
					(current_flight_dynamics->auto_hover == HOVER_HOLD_STABLE))
				{

					set_current_flight_dynamics_auto_hover (HOVER_HOLD_NONE);
					set_current_flight_dynamics_auto_pilot (FALSE);
				}
			}
			else
			{
		
				if (fabs (current_flight_dynamics->input_data.cyclic_vertical_pressure.value) < 1.0)
				{
		
					current_flight_dynamics->input_data.cyclic_vertical_pressure.value = 0.0;
				}
				else
				{
		
					current_flight_dynamics->input_data.cyclic_vertical_pressure.value -= ((MODEL_FRAME_RATE * get_model_delta_time ()) / 2.0) * (current_flight_dynamics->input_data.cyclic_vertical_pressure.value);
				}
			}
		
			// limit pressure inputs
		
			current_flight_dynamics->input_data.cyclic_horizontal_pressure.value = bound (
																				current_flight_dynamics->input_data.cyclic_horizontal_pressure.value,
																				current_flight_dynamics->input_data.cyclic_horizontal_pressure.min,
																				current_flight_dynamics->input_data.cyclic_horizontal_pressure.max
																				);
		
			current_flight_dynamics->input_data.cyclic_vertical_pressure.value = bound (current_flight_dynamics->input_data.cyclic_vertical_pressure.value,
																				current_flight_dynamics->input_data.cyclic_vertical_pressure.min,
																				current_flight_dynamics->input_data.cyclic_vertical_pressure.max
																				);
		
			// recalculate cyclic position
		
			if (current_flight_dynamics->input_data.cyclic_horizontal_pressure.value)
			{
			
				current_flight_dynamics->input_data.cyclic_x.value += (MODEL_FRAME_RATE * get_model_delta_time ()) * current_flight_dynamics->input_data.cyclic_horizontal_pressure.value;
				//current_flight_dynamics->input_data.cyclic_x.value += (MODEL_FRAME_RATE * get_model_delta_time ()) * (current_flight_dynamics->input_data.cyclic_horizontal_pressure.value);// + current_flight_dynamics->input_data.cyclic_x_trim.value);
			}
			else
			{

				static float
					a = 1.0,
					b = 1.0;
		
				// restore x
/*
				if (check_key (DIK_W))
				{

					a += 0.1;

					debug_log ("a = %f", a);
				}
				else if (check_key (DIK_S))
				{

					a -= 0.1;

					debug_log ("a = %f", a);
				}

				if (check_key (DIK_E))
				{

					b += 0.1;

					debug_log ("b = %f", b);
				}
				else if (check_key (DIK_D))
				{

					b -= 0.1;

					debug_log ("b = %f", b);
				}
		
	  */
				if (get_global_cyclic_input () == KEYBOARD_INPUT)
				{

					if (get_current_dynamics_options (DYNAMICS_OPTIONS_KEYBOARD_ASSISTANCE))
					{
	
						current_flight_dynamics->input_data.cyclic_x.value += ((a * 1.0 / 16.0) * MODEL_FRAME_RATE * get_model_delta_time ()) * (current_flight_dynamics->input_data.cyclic_x_trim.value - current_flight_dynamics->input_data.cyclic_x.value);
					}
					else
					{
	
						current_flight_dynamics->input_data.cyclic_x.value += ((b * 3.0 / 4.0) * MODEL_FRAME_RATE * get_model_delta_time ()) * (current_flight_dynamics->input_data.cyclic_x_trim.value - current_flight_dynamics->input_data.cyclic_x.value);
					}
				}
				else if (get_global_cyclic_input () == MOUSE_INPUT)
				{
		
					if (fabs (current_flight_dynamics->input_data.cyclic_x.value) < 5.0)
					{
		
						current_flight_dynamics->input_data.cyclic_x.value *= 0.8;
					}
				}
			}
		
			if (current_flight_dynamics->input_data.cyclic_vertical_pressure.value)
			{
			
				//current_flight_dynamics->input_data.cyclic_y.value += (MODEL_FRAME_RATE * get_model_delta_time ()) * (current_flight_dynamics->input_data.cyclic_vertical_pressure.value + current_flight_dynamics->input_data.cyclic_y_trim.value);
				current_flight_dynamics->input_data.cyclic_y.value += (MODEL_FRAME_RATE * get_model_delta_time ()) * (current_flight_dynamics->input_data.cyclic_vertical_pressure.value);// + current_flight_dynamics->input_data.cyclic_y_trim.value);
			}
			else
			{
		
				// restore y
		
				if (get_global_cyclic_input () == KEYBOARD_INPUT)
				{

					if (get_current_dynamics_options (DYNAMICS_OPTIONS_KEYBOARD_ASSISTANCE))
					{
						
						current_flight_dynamics->input_data.cyclic_y.value += ((1.0 / 16.0) * MODEL_FRAME_RATE * get_model_delta_time ()) * (current_flight_dynamics->input_data.cyclic_y_trim.value - current_flight_dynamics->input_data.cyclic_y.value);
					}
					else
					{
						
						current_flight_dynamics->input_data.cyclic_y.value += ((3.0 / 4.0) * MODEL_FRAME_RATE * get_model_delta_time ()) * (current_flight_dynamics->input_data.cyclic_y_trim.value - current_flight_dynamics->input_data.cyclic_y.value);
					}
				}
				else if (get_global_cyclic_input () == MOUSE_INPUT)
				{
		
					if (fabs (current_flight_dynamics->input_data.cyclic_y.value) < 5.0)
					{

						debug_fatal ("CYCLIC: code with delta time");
		
						current_flight_dynamics->input_data.cyclic_y.value *= 0.8;
					}
				}
			}

			break;
		}

		case JOYSTICK_INPUT:
		{

			int
				joyval;

			float
				input;

			// x

			joyval = joystick_devices [current_flight_dynamics->input_data.cyclic_joystick_device_index].joystick_state.lX;

			input = (float) (200.0 * (float) joyval ) / ((float) JOYSTICK_AXIS_MAXIMUM - (float) JOYSTICK_AXIS_MINIMUM);

			if (fabs (input) < command_line_dynamics_cyclic_dead_zone)
			{

				input = 0.0;
			}

			current_flight_dynamics->input_data.cyclic_x.value = input;

			current_flight_dynamics->input_data.cyclic_x.value += current_flight_dynamics->input_data.cyclic_x_trim.value;

			// y

			joyval = joystick_devices [current_flight_dynamics->input_data.cyclic_joystick_device_index].joystick_state.lY;

			input = -(float) (200.0 * joyval) / (JOYSTICK_AXIS_MAXIMUM - JOYSTICK_AXIS_MINIMUM);

			if (fabs (input) < command_line_dynamics_cyclic_dead_zone)
			{

				input = 0.0;
			}

			current_flight_dynamics->input_data.cyclic_y.value = input;

			current_flight_dynamics->input_data.cyclic_y.value += current_flight_dynamics->input_data.cyclic_y_trim.value;

			/*
			debug_log ("CYCLIC: x %f, y %f", ((float) fabs (200.0 * joystick_devices [current_flight_dynamics->input_data.cyclic_joystick_device_index].joystick_state.lX) / (JOYSTICK_AXIS_MAXIMUM - JOYSTICK_AXIS_MINIMUM)),
				((float) fabs (200.0 * joystick_devices [current_flight_dynamics->input_data.cyclic_joystick_device_index].joystick_state.lY) / (JOYSTICK_AXIS_MAXIMUM - JOYSTICK_AXIS_MINIMUM)));
			*/

			if (((float) fabs (200.0 * joystick_devices [current_flight_dynamics->input_data.cyclic_joystick_device_index].joystick_state.lX) / (JOYSTICK_AXIS_MAXIMUM - JOYSTICK_AXIS_MINIMUM) > 10.0) ||
				((float) fabs (200.0 * joystick_devices [current_flight_dynamics->input_data.cyclic_joystick_device_index].joystick_state.lY) / (JOYSTICK_AXIS_MAXIMUM - JOYSTICK_AXIS_MINIMUM) > 10.0))
			{
	
				if ((current_flight_dynamics->auto_hover == HOVER_HOLD_NORMAL) ||
					(current_flight_dynamics->auto_hover == HOVER_HOLD_STABLE))
				{
	
					set_current_flight_dynamics_auto_hover (HOVER_HOLD_NONE);
					set_current_flight_dynamics_auto_pilot (FALSE);
				}
			}

			break;
		}
	}

	//
	// DEBUG - to get the coolie hat working
	//
	#if 0
	{

		unsigned int
			coolie_position;

		coolie_position = joystick_devices [current_flight_dynamics->input_data.cyclic_joystick_device_index].joystick_state.rgdwPOV [0];

		if (LOWORD(coolie_position) == 0xFFFF)
		{

			debug_log ("CYCLIC: coolie centered");
		}
		else if (coolie_position == 0)
		{

			debug_log ("CYCLIC: coolie up");
		}
		else if (coolie_position == 9000)
		{

			debug_log ("CYCLIC: coolie left");
		}
		else if (coolie_position == 18000)
		{
			
			debug_log ("CYCLIC: coolie down");
		}
		else if (coolie_position == 27000)
		{
			
			debug_log ("CYCLIC: coolie right");
		}
	}
	#endif

	//
	// Damaged hydraulics
	//

	if (current_flight_dynamics->input_data.cyclic_x.damaged)
	{

		current_flight_dynamics->input_data.cyclic_x.value += (MODEL_FRAME_RATE * get_model_delta_time ()) * (0.5 * sfrand1 () * current_flight_dynamics->input_data.cyclic_x.value);
	}

	if (current_flight_dynamics->input_data.cyclic_y.damaged)
	{

		current_flight_dynamics->input_data.cyclic_y.value += (MODEL_FRAME_RATE * get_model_delta_time ()) * (0.5 * sfrand1 () * current_flight_dynamics->input_data.cyclic_y.value);
	}

	//
	// Damaged Stabaliser
	//

	if ((current_flight_dynamics->input_data.cyclic_x_trim.damaged) || (current_flight_dynamics->input_data.cyclic_y_trim.damaged))
	{

		current_flight_dynamics->input_data.cyclic_x_trim.value += (MODEL_FRAME_RATE * get_model_delta_time ()) * (0.5 * sfrand1 () * current_flight_dynamics->input_data.cyclic_x_trim.value);

		current_flight_dynamics->input_data.cyclic_y_trim.value += (MODEL_FRAME_RATE * get_model_delta_time ()) * (0.5 * sfrand1 () * current_flight_dynamics->input_data.cyclic_y_trim.value);
	}

	// limit cyclic position

	current_flight_dynamics->input_data.cyclic_x.value = bound (
												//current_flight_dynamics->input_data.cyclic_x.value + current_flight_dynamics->input_data.cyclic_x_trim.value,
												current_flight_dynamics->input_data.cyclic_x.value,
												current_flight_dynamics->input_data.cyclic_x.min,
												current_flight_dynamics->input_data.cyclic_x.max
												);

	current_flight_dynamics->input_data.cyclic_y.value = bound (
												//current_flight_dynamics->input_data.cyclic_y.value + current_flight_dynamics->input_data.cyclic_y_trim.value,
												current_flight_dynamics->input_data.cyclic_y.value,
												current_flight_dynamics->input_data.cyclic_y.min,
												current_flight_dynamics->input_data.cyclic_y.max
												);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
