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

enum UI_OBJECT_TYPES
{
	UI_TYPE_UNKNOWN,
	UI_TYPE_AREA,
	UI_TYPE_BUTTON,
	UI_TYPE_RADIO,
	UI_TYPE_TOGGLE,
	UI_TYPE_TEXT,
	UI_TYPE_SCREEN,
	UI_TYPE_CLOSE_BOX,
	UI_TYPE_VSLIDER,
	UI_TYPE_HSLIDER,
	UI_TYPE_HVSLIDER,
	UI_TYPE_MSLIDER,
	UI_TYPE_RESIZE,
	UI_TYPE_LIST_BOX,
	UI_TYPE_LIST_ITEM,
	UI_TYPE_MENU_STACK,
	UI_TYPE_INPUT,
	UI_TYPE_NUMBER,
	NUM_UI_TYPES
};

typedef enum UI_OBJECT_TYPES ui_object_types;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct UI_OBJECT
{
	ui_object_types
		type;

	union
	{

		void
			*data;

		struct AREA_UI_OBJECT
			*area;

		struct BUTTON_UI_OBJECT
			*button;

		struct INPUT_UI_OBJECT
			*input;

		struct LIST_BOX
			*list;

		struct RADIO_UI_OBJECT
			*radio;
	};

	struct UI_OBJECT
		*succ,
		*pred,
		*stack_head,
		*stack_next,
		*stack_prev;

	short int
		stack_id;
};

typedef struct UI_OBJECT ui_object;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum UI_OBJECT_STATES
{

	UI_OBJECT_STATE_OFF,
	UI_OBJECT_STATE_ON,
	UI_OBJECT_STATE_UNKNOWN,
	UI_OBJECT_STATE_INVALID
};

typedef enum UI_OBJECT_STATES ui_object_states;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum UI_OBJECT_GRAPHIC_TYPES
{

	UI_OBJECT_NO_GRAPHIC,
	UI_OBJECT_GRAPHIC,
	UI_OBJECT_MEMORY_GRAPHIC,
	UI_OBJECT_ALPHA_GRAPHIC,
	UI_OBJECT_ZOOMABLE_PALETTE_GRAPHIC,
};

typedef enum UI_OBJECT_GRAPHIC_TYPES ui_object_graphic_types;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum TEXT_JUSTIFY_TYPES
{

	TEXT_JUSTIFY_CENTRE,
	TEXT_JUSTIFY_LEFT_CENTRE,
	TEXT_JUSTIFY_RIGHT_CENTRE,
	TEXT_JUSTIFY_CENTRE_TOP,
	TEXT_JUSTIFY_LEFT_TOP,
	TEXT_JUSTIFY_RIGHT_TOP,
	TEXT_JUSTIFY_CENTRE_BOTTOM,
	TEXT_JUSTIFY_LEFT_BOTTOM,
	TEXT_JUSTIFY_RIGHT_BOTTOM
};

typedef enum TEXT_JUSTIFY_TYPES text_justify_types;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum NOTIFY_TYPES
{

	NOTIFY_TYPE_NONE,
	NOTIFY_TYPE_BUTTON_UP,
	NOTIFY_TYPE_BUTTON_DOWN,
	NOTIFY_TYPE_BUTTON_EITHER,
	NOTIFY_TYPE_DISPLAYED,			// when an object is first displayed
	NOTIFY_TYPE_REMOVED, 			// when an object is removed from screen
	NOTIFY_TYPE_END
};

typedef enum NOTIFY_TYPES notify_types;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
