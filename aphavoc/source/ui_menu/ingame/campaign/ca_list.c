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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "project.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define DEBUG_MODULE	0

#define COMMON_LIST_ITEM_ENTITY -2

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static common_list_modes
	current_list_mode;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ui_object
	*common_list [NUM_COMMON_LIST_MODES];

static ui_object
	*common_list_area [NUM_COMMON_LIST_MODES],
	*common_list_mode_area,
	*common_list_filter_area,
	*mission_list_mode_button,
	*group_list_mode_button,
	*base_list_mode_button,
	*available_button,
	*all_button;

static int
	common_available_only_flag;

entity
	*list_filter [NUM_COMMON_LIST_MODES];

static texture_graphic
	*mission_group_graphic,
	*mission_group_base_graphic;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void show_common_list (common_list_modes mode);

static void notify_scroll_common_list (ui_object *obj, void *arg);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_campaign_screen_list_objects (void)
{
	int
		loop;
		
	for (loop = 0; loop < NUM_COMMON_LIST_MODES; loop ++)
	{
		set_ui_object_drawable (common_list_area [loop], FALSE);

		list_filter [loop] = NULL;

		set_ui_object_item_number (common_list [loop], ENTITY_INDEX_DONT_CARE);
	}

	set_common_list_available_only_state (TRUE);

	//
	// Filter buttons
	//

	set_mission_filter (ENTITY_INDEX_DONT_CARE);

	set_group_filter (ENTITY_INDEX_DONT_CARE);

	set_ui_object_drawable (base_list_mode_button, FALSE);

	//
	// Set-up list
	//

	current_list_mode = NUM_COMMON_LIST_MODES;

	set_ui_object_state (mission_list_mode_button, UI_OBJECT_STATE_ON);

	show_common_list (COMMON_LIST_MODE_MISSION);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void add_mission_to_common_list (entity *en, int text_type)
{
	entity
		*previous;

	ui_object
		*new_item;

	unsigned char
		buffer [128];

	ASSERT (en);

	previous = get_local_entity_safe_ptr (get_ui_object_item_number (common_list [COMMON_LIST_MODE_MISSION]));

	new_item = NULL;

	sprintf (buffer, "  %s #%d", get_trans (get_local_entity_string (en, STRING_TYPE_SHORT_DISPLAY_NAME)), get_local_entity_int_value (en, INT_TYPE_TASK_ID));

	switch (text_type)
	{
		case COMMON_LIST_TEXT_AVAILABLE:
		case COMMON_LIST_TEXT_BUSY:
		case COMMON_LIST_TEXT_COMPLETE:
		{
			//
			// Suitable Task - White
			//

			new_item = add_to_pop_up_list (buffer, common_list [COMMON_LIST_MODE_MISSION], NULL, get_local_entity_index (en), CAMPAIGN_LIST_ITEM_FONT, ui_ingame_live_text_colour);

			set_ui_mouse_over_entity_function (new_item);

			break;
		}

		default:
		{
			//
			// Unsuitable Task - Grey
			//

			new_item = add_to_pop_up_list (buffer, common_list [COMMON_LIST_MODE_MISSION], NULL, get_local_entity_index (en), CAMPAIGN_LIST_ITEM_FONT, ui_colour_grey);

			set_ui_mouse_over_entity_function (new_item);

			break;
		}
	}

	ASSERT (new_item);

	set_ui_object_item_number2 (new_item, COMMON_LIST_ITEM_ENTITY);

	if (en == previous)
	{
		set_ui_object_state (new_item, UI_OBJECT_STATE_ON);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void build_mission_list (void)
{
	entity
		*en,
		*force,
		*group_filter,
		*base_filter;

	ui_object_destroy_list_items (common_list [COMMON_LIST_MODE_MISSION]);

	force = get_local_force_entity (get_global_gunship_side ());

	if (!force)
	{
		return;
	}

	#if DEBUG_MODULE

	debug_log ("CA_LIST: Building Mission List");

	#endif

	//
	// set-up filter buttons
	//

	group_filter = NULL;

	base_filter = NULL;

	if (get_common_list_available_only_state ())
	{
		en = list_filter [COMMON_LIST_MODE_MISSION];
	
		if (en)
		{
			if (get_local_entity_type (en) == ENTITY_TYPE_GROUP)
			{
				group_filter = en;
	
				base_filter = get_local_entity_parent (en, LIST_TYPE_KEYSITE_GROUP);

				ASSERT (base_filter);

				if (get_local_entity_type (base_filter) != ENTITY_TYPE_KEYSITE)
				{
					base_filter = NULL;
				}
			}
			else if (get_local_entity_type (en) == ENTITY_TYPE_KEYSITE)
			{
				base_filter = en;
			}
			else
			{
				debug_fatal ("COMMON: Invalid Entity Type %d", get_local_entity_type (en));
			}
		}
	}

	//
	//
	//

	display_sorted_collapsed_mission_list (force, base_filter, group_filter);

	resize_pop_up_list (common_list [COMMON_LIST_MODE_MISSION]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void add_group_to_common_list (entity *en, int text_type)
{
	entity
		*previous,
		*company,
		*keysite;

	entity_sub_types
		sub_type;

	ui_object
		*new_item;

	unsigned char
		ext1 [5],
		ext2 [5],
		buffer [128];

	int
		val1,
		val2;

	ASSERT (en);

	previous = get_local_entity_safe_ptr (get_ui_object_item_number (common_list [COMMON_LIST_MODE_GROUP]));

	new_item = NULL;

	sub_type = get_local_entity_int_value (en, INT_TYPE_ENTITY_SUB_TYPE);

	switch (group_database [sub_type].platoon_short_name_type)
	{
		case PLATOON_SHORT_NAME_CALLSIGN:
		{
			sprintf (buffer, "  %s", get_local_entity_string (en, STRING_TYPE_DIVISION_NAME));

			break;
		}
		case PLATOON_SHORT_NAME_ARMOUR:
		{
			company = get_local_entity_parent (en, LIST_TYPE_DIVISION);

			ASSERT (company);

			val1 = get_local_entity_int_value (en, INT_TYPE_DIVISION_ID),
			val2 = get_local_entity_int_value (company, INT_TYPE_DIVISION_ID),

			get_number_extension (val1, ext1);
			get_number_extension (val2, ext2);

			sprintf (buffer, "  %d%s / %d%s", val1, ext1, val2, ext2);

			break;
		}
		case PLATOON_SHORT_NAME_SHIPS:
		{
			company = get_local_entity_parent (en, LIST_TYPE_DIVISION);

			ASSERT (company);

			val1 = get_local_entity_int_value (company, INT_TYPE_DIVISION_ID),

			sprintf (buffer, "  %s #%d", get_trans (get_local_entity_string (en, STRING_TYPE_GROUP_SHORT_NAME)), val1);

			break;
		}
		case PLATOON_SHORT_NAME_KEYSITE:
		{
			company = get_local_entity_parent (en, LIST_TYPE_DIVISION);

			ASSERT (company);

			keysite = get_local_entity_parent (company, LIST_TYPE_DIVISION_HEADQUARTERS);

			ASSERT (keysite);
				
			sprintf (buffer, "  %s", get_local_entity_string (keysite, STRING_TYPE_KEYSITE_NAME)); 

			break;
		}
		default:
		{
			debug_fatal ("CA_LIST: Invalid Platoon Short Name (%d)", group_database [sub_type].platoon_short_name_type);
		}
	}

	switch (text_type)
	{
		case COMMON_LIST_TEXT_AVAILABLE:
		case COMMON_LIST_TEXT_BUSY:
		{
			//
			// Suitable group - White
			//
			
			new_item = add_to_pop_up_list (buffer, common_list [COMMON_LIST_MODE_GROUP], NULL, get_local_entity_index (en), CAMPAIGN_LIST_ITEM_FONT, ui_ingame_live_text_colour);

			set_ui_mouse_over_entity_function (new_item);

			break;
		}

		default:
		{
			//
			// Unsuitable group - Grey
			//
			
			new_item = add_to_pop_up_list (buffer, common_list [COMMON_LIST_MODE_GROUP], NULL, get_local_entity_index (en), CAMPAIGN_LIST_ITEM_FONT, ui_colour_grey);

			set_ui_mouse_over_entity_function (new_item);

			break;
		}
	}

	ASSERT (new_item);

	set_ui_object_item_number2 (new_item, COMMON_LIST_ITEM_ENTITY);

	if (en == previous)
	{
		set_ui_object_state (new_item, UI_OBJECT_STATE_ON);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void build_group_list ()
{
	entity
		*en,
		*force,
		*base_filter,
		*mission_filter;

	ui_object_destroy_list_items (common_list [COMMON_LIST_MODE_GROUP]);

	force = get_local_force_entity (get_global_gunship_side ());

	if (!force)
	{
		return;
	}
	
	#if DEBUG_MODULE

	debug_log ("CA_LIST: Building Group List");

	#endif

	//
	// set-up filter buttons
	//

	mission_filter = NULL;

	base_filter = NULL;

	if (get_common_list_available_only_state ())
	{
		en = list_filter [COMMON_LIST_MODE_GROUP];
	
		if (en)
		{
			if (get_local_entity_type (en) == ENTITY_TYPE_TASK)
			{
				mission_filter = en;
	
				base_filter = get_local_entity_parent (en, LIST_TYPE_UNASSIGNED_TASK);
			}
			else if (get_local_entity_type (en) == ENTITY_TYPE_KEYSITE)
			{
				base_filter = en;
			}
			else
			{
				debug_fatal ("COMMON: Invalid Entity Type %d", get_local_entity_type (en));
			}
		}
	}
	
	//
	//
	//

	display_sorted_collapsed_group_list (force, base_filter, mission_filter);

	resize_pop_up_list (common_list [COMMON_LIST_MODE_GROUP]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void add_base_to_common_list (entity *en, int text_type)
{
	entity
		*previous;

	ui_object
		*new_item;

	unsigned char
		buffer [128];

	ASSERT (en);

	previous = get_local_entity_safe_ptr (get_ui_object_item_number (common_list [COMMON_LIST_MODE_BASE]));

	new_item = NULL;

	sprintf (buffer, "  %s %d", get_trans (get_local_entity_string (en, STRING_TYPE_SHORT_DISPLAY_NAME)), get_local_entity_int_value (en, INT_TYPE_KEYSITE_ID));

	switch (text_type)
	{
		case COMMON_LIST_TEXT_AVAILABLE:
		{
			new_item = add_to_pop_up_list (buffer, common_list [COMMON_LIST_MODE_BASE], NULL, get_local_entity_index (en), CAMPAIGN_LIST_ITEM_FONT, ui_ingame_live_text_colour);

			set_ui_mouse_over_entity_function (new_item);

			break;
		}

		default:
		{
			new_item = add_to_pop_up_list (buffer, common_list [COMMON_LIST_MODE_BASE], NULL, get_local_entity_index (en), CAMPAIGN_LIST_ITEM_FONT, ui_colour_grey);

			set_ui_mouse_over_entity_function (new_item);

			break;
		}
	}

	ASSERT (new_item);

	set_ui_object_item_number2 (new_item, COMMON_LIST_ITEM_ENTITY);

	if (en == previous)
	{
		set_ui_object_state (new_item, UI_OBJECT_STATE_ON);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void build_base_list ()
{
	entity
		*force;

	ui_object_destroy_list_items (common_list [COMMON_LIST_MODE_BASE]);

	force = get_local_force_entity (get_global_gunship_side ());

	if (!force)
	{
		return;
	}
	
	#if DEBUG_MODULE

	debug_log ("CA_LIST: Building Base List");

	#endif

	display_sorted_collapsed_base_list (force);

	resize_pop_up_list (common_list [COMMON_LIST_MODE_BASE]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void show_common_list (common_list_modes mode)
{
	ASSERT ((mode >= 0) && (mode < NUM_COMMON_LIST_MODES));

	if (mode != current_list_mode)
	{
		if ((current_list_mode >= 0) && (current_list_mode < NUM_COMMON_LIST_MODES))
		{
			set_ui_object_drawable (common_list_area [current_list_mode], FALSE);
		}

		current_list_mode = mode;

		set_ui_object_drawable (common_list_area [current_list_mode], TRUE);

		update_campaign_screen_list_objects ();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void update_current_common_list (void)
{
	switch (current_list_mode)
	{
		case COMMON_LIST_MODE_MISSION:
		{
			build_mission_list ();

			break;
		}
		case COMMON_LIST_MODE_GROUP:
		{
			build_group_list ();

			break;
		}
		case COMMON_LIST_MODE_BASE:
		{
			build_base_list ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_campaign_screen_list_objects (void)
{
	update_current_common_list ();

	// bound the list extremes
	notify_scroll_common_list (NULL, NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_mission_filter (int index)
{
	list_filter [COMMON_LIST_MODE_MISSION] = get_local_entity_safe_ptr (index);

	update_current_common_list ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_group_filter (int index)
{
	list_filter [COMMON_LIST_MODE_GROUP] = get_local_entity_safe_ptr (index);

	update_current_common_list ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void common_list_mission_selected (ui_object *obj)
{
	int
		index,
		state;

	index = get_ui_object_item_number (obj);

	state = get_ui_object_item_number2 (obj);

	if ((state == -1) || (index == -1))
	{
		return;
	}

	switch (state)
	{
		case COMMON_LIST_ITEM_ENTITY:
		{
			entity
				*task;

			task = get_local_entity_safe_ptr (index);

			if (get_local_entity_int_value (task, INT_TYPE_TASK_STATE) == TASK_STATE_COMPLETED)
			{
				show_debriefing_page (task, FALSE, FALSE);
			}
			else
			{
				show_briefing_page (task, FALSE);
			}

			set_ui_object_item_number (common_list [COMMON_LIST_MODE_MISSION], index);

			break;
		}

		default:	
		{
			ASSERT ((state >= 0) && (state < NUM_TASK_STATE_TYPES));

			toggle_mission_type_collapse_state (index, state);

			update_current_common_list ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void common_list_group_selected (ui_object *obj)
{
	int
		state,
		index,
		member_index;
		
	index = get_ui_object_item_number (obj);

	state = get_ui_object_item_number2 (obj);

	if ((state == -1) || (index == -1))
	{
		return;
	}

	switch (state)
	{
		case COMMON_LIST_ITEM_ENTITY:
		{
			member_index = show_group_page (get_local_entity_safe_ptr (index), FALSE);

			set_ui_object_item_number (common_list [COMMON_LIST_MODE_GROUP], index);

			break;
		}
	
		default:
		{
			ASSERT ((state >= 0) && (state < NUM_GROUP_MODE_TYPES));

			toggle_group_type_collapse_state (index, state);

			update_current_common_list ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void common_list_base_selected (ui_object *obj)
{
	int
		state,
		index;

	index = get_ui_object_item_number (obj);

	state = get_ui_object_item_number2 (obj);

	if ((state == -1) || (index == -1))
	{
		return;
	}

	switch (state)
	{
		case COMMON_LIST_ITEM_ENTITY:
		{
			show_base_page (get_local_entity_safe_ptr (index), FALSE);

			set_ui_object_item_number (common_list [COMMON_LIST_MODE_BASE], index);

			break;
		}
	
		default:
		{
			ASSERT (state >= 0);

			toggle_base_type_collapse_state (index);

			update_current_common_list ();

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void notify_scroll_common_list (ui_object *obj, void *arg)
{
	float
		y_max,
		y_origin;

	// N.B. Origin always -ve

	y_max = get_next_list_position (common_list [current_list_mode]) - get_ui_object_y_size (common_list [current_list_mode]);

	y_max = -max (y_max, 0.0);

	y_origin = get_ui_object_y_origin (common_list [current_list_mode]);

	if (obj)
	{
		y_origin += get_ui_object_item_number (obj);
	}

	y_origin = bound (y_origin, y_max, 0.0);

	set_ui_object_y_origin (common_list [current_list_mode], y_origin);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_common_list_available_only_state (int flag)
{
	if (flag)
	{
		set_ui_object_state (available_button, UI_OBJECT_STATE_ON);
		set_ui_object_state (all_button, UI_OBJECT_STATE_OFF);

		set_ui_object_drawable (base_list_mode_button, FALSE);

		set_ui_object_texture_graphic (common_list_mode_area, mission_group_graphic);

		if (current_list_mode == COMMON_LIST_MODE_BASE)
		{
			show_common_list (COMMON_LIST_MODE_MISSION);

			set_ui_object_state (mission_list_mode_button, UI_OBJECT_STATE_ON);
		}
	}
	else
	{
		set_ui_object_state (available_button, UI_OBJECT_STATE_OFF);
		set_ui_object_state (all_button, UI_OBJECT_STATE_ON);

		set_ui_object_drawable (base_list_mode_button, TRUE);

		set_ui_object_texture_graphic (common_list_mode_area, mission_group_base_graphic);
	}

	common_available_only_flag = flag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_common_list_available_only_state (void)
{
	return common_available_only_flag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void notify_available_items_button (ui_object *obj, void *arg)
{
	set_common_list_available_only_state (TRUE);

	update_campaign_screen_list_objects ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void notify_all_items_button (ui_object *obj, void *arg)
{
	set_common_list_available_only_state (FALSE);

	update_campaign_screen_list_objects ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void notify_common_list (ui_object *obj, void *arg)
{
	switch (current_list_mode)
	{
		case COMMON_LIST_MODE_MISSION:
		{
			common_list_mission_selected (obj);

			break;
		}
		case COMMON_LIST_MODE_GROUP:
		{
			common_list_group_selected (obj);

			break;
		}
		case COMMON_LIST_MODE_BASE:
		{
			common_list_base_selected (obj);

			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void show_base_list (ui_object *obj, void *arg)
{
	build_base_list ();

	set_ui_object_state (base_list_mode_button, UI_OBJECT_STATE_ON);

	show_common_list (COMMON_LIST_MODE_BASE);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void show_mission_list (ui_object *obj, void *arg)
{
	build_mission_list ();

	set_ui_object_state (mission_list_mode_button, UI_OBJECT_STATE_ON);

	show_common_list (COMMON_LIST_MODE_MISSION);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void show_group_list (ui_object *obj, void *arg)
{
	build_group_list ();

	set_ui_object_state (group_list_mode_button, UI_OBJECT_STATE_ON);

	show_common_list (COMMON_LIST_MODE_GROUP);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_current_list_mode (void)
{
	return current_list_mode;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_mission_sort_mode (void)
{
	return MISSION_SORT_MODE_TYPE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_group_sort_mode (void)
{
	return GROUP_SORT_MODE_TYPE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_base_sort_mode (void)
{
	return BASE_SORT_MODE_TYPE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void define_campaign_screen_list_objects (void)
{
	float
		x1,
		y1,
		x2,
		y2;

	int
		loop;

	mission_group_graphic = create_texture_graphic ("graphics\\ui\\cohokum\\map\\mgbtn.psd");
	mission_group_base_graphic = create_texture_graphic ("graphics\\ui\\cohokum\\map\\mgbbtn.psd");

	/////////////////////////////////////////////////////////////////
	// Missions / Groups / Bases List 
	/////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////
	// List Options 

	x1 = 0.0;
	y1 = 0.0;
	x2 = CAMPAIGN_INSET_PAGE_X1;
	y2 = CAMPAIGN_INSET_PAGE_Y1;

	common_list_filter_area = create_ui_object
	(
		UI_TYPE_AREA,
		UI_ATTR_PARENT (campaign_screen),
		UI_ATTR_VIRTUAL_POSITION (x1, y1),
		UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
		UI_ATTR_TEXTURE_GRAPHIC (create_texture_graphic ("graphics\\ui\\cohokum\\map\\avail.psd")),
		UI_ATTR_END
	);

	/////////////////////////////////////////////////////////////////
	// Player Selection Button

	x1 = 0.0;
	y1 = 0.0;
	x2 = 0.5;
	y2 = 1.0;

	available_button = create_ui_object
			(
				UI_TYPE_RADIO,
				UI_ATTR_PARENT (common_list_filter_area),
				UI_ATTR_VIRTUAL_POSITION (x1, y1),
				UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
				UI_ATTR_TEXT (get_trans ("AVAILABLE")),
				UI_ATTR_NOTIFY_ON (NOTIFY_TYPE_BUTTON_DOWN),
				UI_ATTR_FUNCTION (notify_available_items_button),
				UI_ATTR_CLEAR (TRUE),
				UI_ATTR_HIGHLIGHTABLE (TRUE),
				UI_ATTR_FONT_TYPE (UI_FONT_ARIAL_16),
				UI_ATTR_FONT_COLOUR (ui_ingame_live_text_colour.r, ui_ingame_live_text_colour.g, ui_ingame_live_text_colour.b, ui_ingame_live_text_colour.a),
				UI_ATTR_HIGHLIGHTED_FONT_COLOUR (ui_ingame_highlight_text_colour.r, ui_ingame_highlight_text_colour.g, ui_ingame_highlight_text_colour.b, ui_ingame_highlight_text_colour.a),
				UI_ATTR_SELECTED_FONT_COLOUR (ui_ingame_selected_text_colour.r, ui_ingame_selected_text_colour.g, ui_ingame_selected_text_colour.b, ui_ingame_selected_text_colour.a),
				UI_ATTR_END
			);

	/////////////////////////////////////////////////////////////////
	// All items list (O.O.B.)

	x1 = 0.5;
	y1 = 0.0;
	x2 = 1.0;
	y2 = 1.0;

	all_button = create_ui_object
			(
				UI_TYPE_RADIO,
				UI_ATTR_PARENT (common_list_filter_area),
				UI_ATTR_VIRTUAL_POSITION (x1, y1),
				UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
				UI_ATTR_TEXT (get_trans ("O.O.B")),
				UI_ATTR_NOTIFY_ON (NOTIFY_TYPE_BUTTON_DOWN),
				UI_ATTR_FUNCTION (notify_all_items_button),
				UI_ATTR_CLEAR (TRUE),
				UI_ATTR_HIGHLIGHTABLE (TRUE),
				UI_ATTR_FONT_TYPE (UI_FONT_ARIAL_16),
				UI_ATTR_FONT_COLOUR (ui_ingame_live_text_colour.r, ui_ingame_live_text_colour.g, ui_ingame_live_text_colour.b, ui_ingame_live_text_colour.a),
				UI_ATTR_HIGHLIGHTED_FONT_COLOUR (ui_ingame_highlight_text_colour.r, ui_ingame_highlight_text_colour.g, ui_ingame_highlight_text_colour.b, ui_ingame_highlight_text_colour.a),
				UI_ATTR_SELECTED_FONT_COLOUR (ui_ingame_selected_text_colour.r, ui_ingame_selected_text_colour.g, ui_ingame_selected_text_colour.b, ui_ingame_selected_text_colour.a),
				UI_ATTR_END
			);

	/////////////////////////////////////////////////////////////////
	// List Mode Toggles/Buttons

	x1 = 0.0;
	y1 = 0.06;

	x2 = 0.219;
	y2 = 0.242;

	common_list_mode_area = create_ui_object
	(
		UI_TYPE_AREA,
		UI_ATTR_PARENT (campaign_screen),
		UI_ATTR_VIRTUAL_POSITION (x1, y1),
		UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
		UI_ATTR_END
	);

	/////////////////////////////////////////////////////////////////
	// List modes

	x1 = 0.064;
	y1 = 0.0;

	x2 = 0.645;
	y2 = 0.387;

	mission_list_mode_button = create_ui_object
	(
		UI_TYPE_RADIO,
		UI_ATTR_PARENT (common_list_mode_area),
		UI_ATTR_VIRTUAL_POSITION (x1, y1),
		UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
		UI_ATTR_FONT_TYPE (UI_FONT_ARIAL_16),
		UI_ATTR_FONT_COLOUR (ui_ingame_live_text_colour.r, ui_ingame_live_text_colour.g, ui_ingame_live_text_colour.b, ui_ingame_live_text_colour.a),
		UI_ATTR_HIGHLIGHTED_FONT_COLOUR (ui_ingame_highlight_text_colour.r, ui_ingame_highlight_text_colour.g, ui_ingame_highlight_text_colour.b, ui_ingame_highlight_text_colour.a),
		UI_ATTR_TEXT (get_trans ("Missions")),
		UI_ATTR_FUNCTION (show_mission_list),
		UI_ATTR_HIGHLIGHTABLE (TRUE),
		UI_ATTR_CLEAR (TRUE),
		UI_ATTR_END
	);

	//

	x1 = 0.354;
	y1 = 0.304;

	x2 = 0.935;
	y2 = 0.694;

	group_list_mode_button = create_ui_object
	(
		UI_TYPE_RADIO,
		UI_ATTR_PARENT (common_list_mode_area),
		UI_ATTR_VIRTUAL_POSITION (x1, y1),
		UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
		UI_ATTR_FONT_TYPE (UI_FONT_ARIAL_16),
		UI_ATTR_FONT_COLOUR (ui_ingame_live_text_colour.r, ui_ingame_live_text_colour.g, ui_ingame_live_text_colour.b, ui_ingame_live_text_colour.a),
		UI_ATTR_HIGHLIGHTED_FONT_COLOUR (ui_ingame_highlight_text_colour.r, ui_ingame_highlight_text_colour.g, ui_ingame_highlight_text_colour.b, ui_ingame_highlight_text_colour.a),
		UI_ATTR_TEXT (get_trans ("Groups")),
		UI_ATTR_FUNCTION (show_group_list),
		UI_ATTR_HIGHLIGHTABLE (TRUE),
		UI_ATTR_CLEAR (TRUE),
		UI_ATTR_END
	);

	//

	x1 = 0.064;
	y1 = 0.604;

	x2 = 0.645;
	y2 = 1.0;

	base_list_mode_button = create_ui_object
	(
		UI_TYPE_RADIO,
		UI_ATTR_PARENT (common_list_mode_area),
		UI_ATTR_VIRTUAL_POSITION (x1, y1),
		UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
		UI_ATTR_FONT_TYPE (UI_FONT_ARIAL_16),
		UI_ATTR_FONT_COLOUR (ui_ingame_live_text_colour.r, ui_ingame_live_text_colour.g, ui_ingame_live_text_colour.b, ui_ingame_live_text_colour.a),
		UI_ATTR_HIGHLIGHTED_FONT_COLOUR (ui_ingame_highlight_text_colour.r, ui_ingame_highlight_text_colour.g, ui_ingame_highlight_text_colour.b, ui_ingame_highlight_text_colour.a),
		UI_ATTR_TEXT (get_trans ("Bases")),
		UI_ATTR_FUNCTION (show_base_list),
		UI_ATTR_HIGHLIGHTABLE (TRUE),
		UI_ATTR_CLEAR (TRUE),
		UI_ATTR_END
	);

	/////////////////////////////////////////////////////////////////
	// List Box
	/////////////////////////////////////////////////////////////////

	for (loop = 0; loop < NUM_COMMON_LIST_MODES; loop ++)
	{
		x1 = 0.0;
		y1 = 0.266;
		x2 = CAMPAIGN_INSET_PAGE_X1;
		y2 = 0.856;

		common_list_area [loop] = create_ui_object
			(
				UI_TYPE_AREA,
				UI_ATTR_PARENT (campaign_screen),
				UI_ATTR_VIRTUAL_POSITION (x1, y1),
				UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
				UI_ATTR_VSLIDER (0, 300, 12),
				UI_ATTR_CLEAR (TRUE),
				UI_ATTR_END
			);

		set_common_slider_graphics (common_list_area [loop]);

		x1 = 0.0;
		y1 = 0.00;
		x2 = 0.915;
		y2 = 1.0;

		common_list [loop] = create_ui_object
				(
					UI_TYPE_LIST_BOX,
					UI_ATTR_PARENT (common_list_area [loop]),
					UI_ATTR_VIRTUAL_POSITION (x1, y1),
					UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
					UI_ATTR_CLEAR (TRUE),
					UI_ATTR_FUNCTION (notify_common_list),
					UI_ATTR_FONT_TYPE (CAMPAIGN_LIST_ITEM_FONT),
					UI_ATTR_ITEM_NUMBER (ENTITY_INDEX_DONT_CARE),
					UI_ATTR_END
				);
	}

	/////////////////////////////////////////////////////////////////
	// "Divider" graphics

	x1 = 0.021;
	y1 = 0.248;
	x2 = 0.20;
	y2 = 0.265;

	create_ui_object
			(
				UI_TYPE_AREA,
				UI_ATTR_PARENT (campaign_screen),
				UI_ATTR_VIRTUAL_POSITION (x1, y1),
				UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
				UI_ATTR_TEXTURE_GRAPHIC (common_divider_graphic),
				UI_ATTR_END
			);

	////////////////////////////////////

	x1 = 0.021;
	y1 = 0.858;
	x2 = 0.20;
	y2 = 0.874;

	create_ui_object
			(
				UI_TYPE_AREA,
				UI_ATTR_PARENT (campaign_screen),
				UI_ATTR_VIRTUAL_POSITION (x1, y1),
				UI_ATTR_VIRTUAL_SIZE (x2 - x1, y2 - y1),
				UI_ATTR_TEXTURE_GRAPHIC (common_divider_graphic),
				UI_ATTR_END
			);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_mission_created (campaign_screen_messages message, entity *sender)
{
	update_current_common_list ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_mission_assigned (campaign_screen_messages message, entity *sender)
{
	update_current_common_list ();

	activate_accept_selections_button ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_mission_completed (campaign_screen_messages message, entity *sender)
{
	update_current_common_list ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_mission_destroyed (campaign_screen_messages message, entity *sender)
{
	//
	// Check if entity was currently selected list item
	// 
	
	if (sender == get_local_entity_safe_ptr (get_ui_object_item_number (common_list [COMMON_LIST_MODE_MISSION])))
	{
		set_ui_object_item_number (common_list [COMMON_LIST_MODE_MISSION], ENTITY_INDEX_DONT_CARE);
	}

	//
	// Check if entity was filter list item
	// 
	
	if (sender == list_filter [COMMON_LIST_MODE_GROUP])
	{
		list_filter [COMMON_LIST_MODE_GROUP] = NULL;
	}

	update_current_common_list ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_group_created (campaign_screen_messages message, entity *sender)
{
	update_current_common_list ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_group_destroyed (campaign_screen_messages message, entity *sender)
{
	//
	// sender is a group
	//
		
	//
	// Check if entity was currently selected list item
	// 
	
	if (sender == get_local_entity_safe_ptr (get_ui_object_item_number (common_list [COMMON_LIST_MODE_GROUP])))
	{
		set_ui_object_item_number (common_list [COMMON_LIST_MODE_GROUP], ENTITY_INDEX_DONT_CARE);
	}

	//
	// Check if entity was filter list item
	// 
	
	if (sender == list_filter [COMMON_LIST_MODE_MISSION])
	{
		list_filter [COMMON_LIST_MODE_MISSION] = NULL;
	}

	update_current_common_list ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_group_change_base (campaign_screen_messages message, entity *sender)
{
	update_current_common_list ();

	activate_accept_selections_button ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_group_remove_member (campaign_screen_messages message, entity *sender)
{
	entity
		*member;

	//
	// sender is a mobile
	//
		
	update_current_common_list ();

	member = get_currently_selected_member ();

	if ((member) && (member == sender))
	{
		set_currently_selected_member (ENTITY_INDEX_DONT_CARE);
	}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_base_created (campaign_screen_messages message, entity *sender)
{
	update_current_common_list ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int response_to_base_destroyed (campaign_screen_messages message, entity *sender)
{
	//
	// Check if entity was currently selected list item
	// 
	
	if (sender == get_local_entity_safe_ptr (get_ui_object_item_number (common_list [COMMON_LIST_MODE_BASE])))
	{
		set_ui_object_item_number (common_list [COMMON_LIST_MODE_BASE], ENTITY_INDEX_DONT_CARE);
	}

	update_current_common_list ();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_mission_list_message_responses (void)
{
	campaign_screen_message_targets
		target;

	target = CAMPAIGN_SCREEN_TARGET_MISSION_LIST;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_MISSION_CREATED]	=	response_to_mission_created;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_MISSION_ASSIGNED]	=	response_to_mission_assigned;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_MISSION_COMPLETED]	=	response_to_mission_completed;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_MISSION_DESTROYED]	=	response_to_mission_destroyed;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_group_list_message_responses (void)
{
	campaign_screen_message_targets
		target;

	target = CAMPAIGN_SCREEN_TARGET_GROUP_LIST;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_GROUP_CREATED]		=	response_to_group_created;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_GROUP_DESTROYED]	=	response_to_group_destroyed;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_GROUP_CHANGE_BASE]	=	response_to_group_change_base;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_GROUP_REMOVE_MEMBER]	=	response_to_group_remove_member;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void overload_base_list_message_responses (void)
{
	campaign_screen_message_targets
		target;

	target = CAMPAIGN_SCREEN_TARGET_BASE_LIST;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_BASE_CREATED]		=	response_to_base_created;

	campaign_screen_message_responses [target][CAMPAIGN_SCREEN_BASE_DESTROYED]		=	response_to_base_destroyed;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


