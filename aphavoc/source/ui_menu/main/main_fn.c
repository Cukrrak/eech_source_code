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

void notify_main_screen (ui_object *obj, void *arg)
{

	obj;
	arg;

	if ( get_ui_object_drawable ( obj ) )
	{

		if ( main_screen_texture )
		{
	
			destroy_texture_graphic ( main_screen_texture );

			main_screen_texture = NULL;
		}
	
		main_screen_texture = create_texture_graphic ( "graphics\\ui\\cohokum\\main.psd" );
	
		set_ui_object_texture_graphic ( main_screen, main_screen_texture );
	
		blit_front_buffer_to_render_buffer ();
	
		leave_mission ();
	
		ui_set_user_function (NULL);
	
		reset_time_values ( main_screen );
	}
	else
	{

		if ( main_screen_texture )
		{
	
			destroy_texture_graphic ( main_screen_texture );

			main_screen_texture = NULL;
		}
	}

	#if DEMO_VERSION
	
		set_ui_object_highlightable (pilots_button, FALSE);

		set_ui_object_font_colour_end (pilots_button, ui_option_text_default_colour.r, ui_option_text_default_colour.g, ui_option_text_default_colour.b, 127);

		set_ui_object_notify_on (pilots_button, NOTIFY_TYPE_NONE);
	
		set_ui_object_drawable (ghost_pilots_button, TRUE);

		set_ui_object_highlightable (credits_button, FALSE);

		set_ui_object_font_colour_end (credits_button, ui_option_text_default_colour.r, ui_option_text_default_colour.g, ui_option_text_default_colour.b, 127);

		set_ui_object_drawable (ghost_credits_button, TRUE);

		set_ui_object_notify_on (credits_button, NOTIFY_TYPE_NONE);
	
	#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void notify_main_select_player_button (ui_object *obj, void *arg)
{

	obj;
	arg;

	push_ui_screen (select_player_screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void notify_main_combat_missions_button (ui_object *obj, void *arg)
{

	obj;
	arg;

	set_game_flow (GAME_FLOW_COMBAT_MISSIONS);

	push_ui_screen (game_type_screen);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void notify_main_credits_button (ui_object *obj, void *arg)
{

	obj;
	arg;

	push_ui_screen (credits_screen);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


