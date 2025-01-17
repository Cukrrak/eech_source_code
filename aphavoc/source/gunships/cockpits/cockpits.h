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

enum COCKPIT_PANELS
{
	COCKPIT_PANEL_UP40_LEFT90,
	COCKPIT_PANEL_UP40_LEFT60,
	COCKPIT_PANEL_UP40_LEFT30,
	COCKPIT_PANEL_UP40_AHEAD,
	COCKPIT_PANEL_UP40_RIGHT30,
	COCKPIT_PANEL_UP40_RIGHT60,
	COCKPIT_PANEL_UP40_RIGHT90,
	COCKPIT_PANEL_UP20_LEFT90,
	COCKPIT_PANEL_UP20_LEFT60,
	COCKPIT_PANEL_UP20_LEFT30,
	COCKPIT_PANEL_UP20_AHEAD,
	COCKPIT_PANEL_UP20_RIGHT30,
	COCKPIT_PANEL_UP20_RIGHT60,
	COCKPIT_PANEL_UP20_RIGHT90,
	COCKPIT_PANEL_LEVEL_LEFT90,
	COCKPIT_PANEL_LEVEL_LEFT60,
	COCKPIT_PANEL_LEVEL_LEFT30,
	COCKPIT_PANEL_LEVEL_AHEAD,
	COCKPIT_PANEL_LEVEL_RIGHT30,
	COCKPIT_PANEL_LEVEL_RIGHT60,
	COCKPIT_PANEL_LEVEL_RIGHT90,
	COCKPIT_PANEL_DOWN20_LEFT90,
	COCKPIT_PANEL_DOWN20_LEFT60,
	COCKPIT_PANEL_DOWN20_LEFT30,
	COCKPIT_PANEL_DOWN20_AHEAD,
	COCKPIT_PANEL_DOWN20_RIGHT30,
	COCKPIT_PANEL_DOWN20_RIGHT60,
	COCKPIT_PANEL_DOWN20_RIGHT90,
	COCKPIT_PANEL_SPECIAL_APACHE_LHS_MFD,
	COCKPIT_PANEL_SPECIAL_APACHE_RHS_MFD,
	COCKPIT_PANEL_SPECIAL_HAVOC_TV,
	COCKPIT_PANEL_SPECIAL_HAVOC_HUD,
	NUM_COCKPIT_PANEL_MODES
};

typedef enum COCKPIT_PANELS cockpit_panels;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void initialise_cockpits (void);

extern void deinitialise_cockpits (void);

extern void update_cockpits (void);

extern void draw_cockpit (cockpit_panels panel);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
// INCLUDE ORDER IS CRITICAL
//

#include "common/co_ckpt.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "apache/ap_ckpt.h"

#include "comanche/cm_ckpt.h"

#include "havoc/ha_ckpt.h"

#include "hokum/hk_ckpt.h"

////Moje 030518 Start

#include "blackhawk/bh_ckpt.h"

////Moje 030518 End
////Moje 030612 Start

#include "hind/hi_ckpt.h"

////Moje 030612 End
////Moje 030816 Start

#include "ah64a/ah_ckpt.h"

#include "ka50/hm_ckpt.h"

#include "viper/vi_ckpt.h"

#include "kiowa/ki_ckpt.h"

// GCsDriver  08-12-2007
#include "default/df_ckpt.h"

////Moje 030816 End
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
