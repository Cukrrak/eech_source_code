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

extern int
	total_number_of_d3d_triangles,
	number_of_d3d_degenerate_triangles,
	number_of_d3d_triangles_drawn,
	number_of_d3d_lines_drawn,
	number_of_d3d_state_int_changes,
	number_of_d3d_state_float_changes;

extern int
	d3d_transparency_enabled;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void initialise_d3d_state ( void );

extern void set_d3d_alpha_fog_zbuffer ( int alpha, int fog, int ztest, int zwrite );

extern void set_d3d_transparency_on ( void );

extern void set_d3d_transparency_off ( void );
/*
extern void set_d3d_alpha_blending ( int flag );
*/
extern void set_d3d_in_order_rendering ( int flag );

extern void set_d3d_zbuffer_comparison ( int flag );

//extern void set_d3d_zbuffer_writing ( int flag );

extern void set_d3d_culling ( int flag );

extern void set_d3d_texture_wrapping ( int stage, int flag );

extern void set_d3d_texture_filtering ( int flag );

extern void set_d3d_texture_mag_filtering ( int flag );

extern void set_d3d_texture_min_filtering ( int flag );

extern void set_d3d_texture_mip_filtering ( int flag );

extern void set_d3d_plain_renderstate ( void );

extern void set_d3d_gouraud_shaded_renderstate ( void );

extern void set_d3d_flat_shaded_textured_renderstate ( struct SCREEN *texture );

extern void set_d3d_gouraud_shaded_textured_renderstate ( struct SCREEN *texture );


extern void reset_deferred_state_changes ( void );

extern void commit_deferred_state_changes ( void );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

