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

void collective_forward (event *ev)
{

	if (ev->state == KEY_STATE_DOWN)
	{

		current_flight_dynamics->input_data.collective_input_pressure |= COLLECTIVE_PRESSURE_FORWARD;
	}
	else
	{

		current_flight_dynamics->input_data.collective_input_pressure ^= COLLECTIVE_PRESSURE_FORWARD;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void collective_backward (event *ev)
{

	if (ev->state == KEY_STATE_DOWN)
	{

		current_flight_dynamics->input_data.collective_input_pressure |= COLLECTIVE_PRESSURE_BACKWARD;
	}
	else
	{

		current_flight_dynamics->input_data.collective_input_pressure ^= COLLECTIVE_PRESSURE_BACKWARD;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void collective_mouse_input (event *ev)
{

#if 0

	current_flight_dynamics->input_data.collective_pressure.value -= (ev->dy);

#else

	current_flight_dynamics->input_data.collective.value -= (ev->dy);

#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_collective_pressure_inputs (void)
{

	current_flight_dynamics->input_data.collective.delta = current_flight_dynamics->input_data.collective.value;

	switch (get_global_collective_input ())
	{

		case KEYBOARD_INPUT:
		case MOUSE_INPUT:
		{
		
			if (current_flight_dynamics->input_data.collective_input_pressure & COLLECTIVE_PRESSURE_BACKWARD)
			{
		
				current_flight_dynamics->input_data.collective_pressure.value = min (0, current_flight_dynamics->input_data.collective_pressure.value);
		
				current_flight_dynamics->input_data.collective_pressure.value -= 5.0 * get_delta_time ();
			}
			else if (current_flight_dynamics->input_data.collective_input_pressure & COLLECTIVE_PRESSURE_FORWARD)
			{
		
				current_flight_dynamics->input_data.collective_pressure.value = max (0, current_flight_dynamics->input_data.collective_pressure.value);
		
				current_flight_dynamics->input_data.collective_pressure.value += 5.0 * get_delta_time ();
			}
			else
			{
		
				current_flight_dynamics->input_data.collective_pressure.value = 0.0;
			}
		
			current_flight_dynamics->input_data.collective_pressure.value = bound (current_flight_dynamics->input_data.collective_pressure.value,
																											current_flight_dynamics->input_data.collective_pressure.min,
																											current_flight_dynamics->input_data.collective_pressure.max);
	
			break;
		}
		case THROTTLE_INPUT:
		{

			int
				joyval;

			float
				input;

			joyval = joystick_devices [current_flight_dynamics->input_data.cyclic_joystick_device_index].joystick_state.lZ;

			input = (float) (120.0 * (float) joyval ) / ((float) JOYSTICK_AXIS_MAXIMUM - (float) JOYSTICK_AXIS_MINIMUM);

			if ((current_flight_dynamics->auto_hover != HOVER_HOLD_STABLE) && (current_flight_dynamics->auto_hover != HOVER_HOLD_ALTITUDE_LOCK))
			{
		
				if (get_current_dynamics_options (DYNAMICS_OPTIONS_REVERSE_THROTTLE_INPUT))
				{
	
					current_flight_dynamics->input_data.collective.value = (float) 60.0 - input;
				}
				else
				{
	
					current_flight_dynamics->input_data.collective.value = (float) 60.0 + input;
				}
			}

			break;
		}
	}

	// recalculate collective position

	if (current_flight_dynamics->input_data.collective_pressure.value)
	{
	
		current_flight_dynamics->input_data.collective.value += 10.0 * current_flight_dynamics->input_data.collective_pressure.value * get_delta_time ();
	}
	else
	{

		// restore
	}

	if (current_flight_dynamics->input_data.collective.damaged)
	{

		current_flight_dynamics->input_data.collective.value += (get_model_delta_time ()) * (7.5 * sfrand1 () * current_flight_dynamics->input_data.collective.delta);
	}

	current_flight_dynamics->input_data.collective.value = bound (current_flight_dynamics->input_data.collective.value,
																						current_flight_dynamics->input_data.collective.min,
																						current_flight_dynamics->input_data.collective.max);
		
	current_flight_dynamics->input_data.collective.delta -= current_flight_dynamics->input_data.collective.value;
	current_flight_dynamics->input_data.collective.delta *= -1.0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
