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

#include "userint2.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void draw_screen_ui_object (ui_object *obj)
{

	float
		x1,
		y1,
		x2,
		y2;

	area_ui_object
		*area;

	struct SCREEN
		*old_active_screen;

	if (get_ui_object_redraw (obj))
	{

		//if (!get_ui_object_draw_function (obj))
		{
	
			if (get_ui_object_redraw (obj) == MAX_UI_REDRAW_NUMBER)
			{
	
				set_ui_object_redraw_all (get_ui_screen_stack_head (), TRUE);
			}
	
			area = (area_ui_object *) obj->data;
	
			//debug_log ("SC_DRAW: drawing screen %f, %f  %f, %f", area->x, area->y, area->x_size, area->y_size);
		
			x1 = get_ui_object_x (obj);
			
			y1 = get_ui_object_y (obj);
	
			switch (get_ui_object_graphic_type (obj))
			{

				case UI_OBJECT_GRAPHIC:
				{
		
					unsigned short int
						*graphic;
				
					int
						x_size,
						y_size;

					graphic = get_ui_object_graphic (obj);
			
					old_active_screen = get_active_screen ();
			
					if (get_ui_object_active_screen (obj))
					{
				
						set_active_screen (get_ui_object_active_screen (obj));
					}
					else
					{
			
						set_active_screen (video_screen);
					}
			
					// debug for userint2
					set_active_screen (video_screen);
					// debug
			
					clear_screen ();

					x_size = get_ui_object_x_size (obj) - 1;
			
					y_size = get_ui_object_y_size (obj) - 1;
				
					x2 = x1 + x_size;
				
					y2 = y1 + y_size;

			/*
					if (lock_screen (active_screen))
					{
					
						set_viewport (x1, y1, x2, y2);
					
						ui_set_origin (x1, y1);
				
						if (!get_ui_object_clear (obj))
						{
						
							if (graphic)
							{
					
								ui_draw_graphic (x1, y1, x2, y2, graphic);
							}
							else
							{
					
								ui_draw_area (0, 0, x2 - x1, y2 - y1, obj);
							}
						}
				
						set_viewport (x1 + 1, y1 + 1, x2 - 1, y2 - 1);
					
						ui_set_origin (x1 + 1, y1 + 1);
					
						unlock_screen (active_screen);
					}
			*/
					set_active_screen (old_active_screen);
			
					set_ui_repaint_area (x1, y1, x2, y2);
			
					area->redraw --;

					break;
				}

				case UI_OBJECT_TEXTURE_GRAPHIC:
				{
		
					texture_graphic
						*graphic;
				
					float
						x_size,
						y_size;

					graphic = get_ui_object_texture_graphic (obj);
			
					x_size = get_ui_object_x_size (obj);
			
					y_size = get_ui_object_y_size (obj);

					x_size -= 0.001;

					y_size -= 0.001;
				
					x2 = x1 + x_size;
				
					y2 = y1 + y_size;

					set_viewport (x1, y1, x2, y2);

					ui_set_origin (x1, y1);
			
					if (!get_ui_object_clear (obj))
					{
					
						if (graphic)
						{

							rgb_colour
								colour;

							real_colour
								text_colour;

							colour = get_ui_object_colour ( obj );

							text_colour.red = colour.r;
							text_colour.green = colour.g;
							text_colour.blue = colour.b;
							text_colour.alpha = colour.a;

							ui_draw_texture_graphic (x1, y1, x2, y2, graphic, text_colour);
						}
						else
						{
				
							ui_draw_area (0, 0, x2 - x1, y2 - y1, obj);
						}
					}
			
					set_viewport (x1 + 1, y1 + 1, x2 - 1, y2 - 1);
				
					ui_set_origin (x1 + 1, y1 + 1);
				
					set_ui_repaint_area (x1, y1, x2, y2);
			
					area->redraw --;

					break;
				}

				default:
				{

					clear_screen ();

					break;
				}
			}
		}
		//else
		{

			call_ui_object_draw_function (obj, NULL);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_screen_ui_object_draw_functions (ui_object_types type)
{

	fn_draw_ui_object [type] = draw_screen_ui_object;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
