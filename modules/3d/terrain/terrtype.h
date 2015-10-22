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

//
// Terrain types are ordered according to their relative heights in a sector
//

enum //TERRAIN_TYPES
{

	TERRAIN_TYPE_INVALID,						//0

	// Sunken features tops
   TERRAIN_TYPE_RIVER,							//1
   TERRAIN_TYPE_RESERVOIR,                //2
   TERRAIN_TYPE_TRENCH,                   //3

	// Sunken features banks
   TERRAIN_TYPE_RIVER_BANK,					//4
   TERRAIN_TYPE_TRENCH_SIDE_X,				//5
   TERRAIN_TYPE_TRENCH_SIDE_Z,            //6
                                          //
	// Regular terrain types               //
   TERRAIN_TYPE_SEA,                      //7
                                          //
   TERRAIN_TYPE_BEACH,                    //8
                                          //
   TERRAIN_TYPE_LAND,                     //9
                                          //
	TERRAIN_TYPE_FIELD1,                   //10
	TERRAIN_TYPE_FIELD2,                   //11
	TERRAIN_TYPE_FIELD3,                   //12
	TERRAIN_TYPE_FIELD4,                   //13
	TERRAIN_TYPE_FIELD5,                   //14
	TERRAIN_TYPE_FIELD6,                   //15
	TERRAIN_TYPE_FIELD7,                   //16
	TERRAIN_TYPE_FIELD8,                   //17
	TERRAIN_TYPE_FIELD9,                   //18
	TERRAIN_TYPE_FIELD10,                  //19
	TERRAIN_TYPE_FIELD11,                  //20
                                          //
	TERRAIN_TYPE_ALTERED_LAND1,            //21
	TERRAIN_TYPE_ALTERED_LAND2,            //22
	TERRAIN_TYPE_ALTERED_LAND3,            //23
                                          //
	TERRAIN_TYPE_FOREST_FLOOR,             //24
                                          //
	// Raised features banks               //
   TERRAIN_TYPE_ROAD_BANK,                //25
   TERRAIN_TYPE_RAIL_BANK,                //26
                                          //
	// Raised features sides               //
	TERRAIN_TYPE_HEDGE_SIDE_X,             //27
	TERRAIN_TYPE_HEDGE_SIDE_Z,             //28
	TERRAIN_TYPE_WALL_SIDE_X,              //29
	TERRAIN_TYPE_WALL_SIDE_Z,              //30
   TERRAIN_TYPE_FOREST_SIDE_BOTTOM_X,     //31
   TERRAIN_TYPE_FOREST_SIDE_BOTTOM_Z,     //32
   TERRAIN_TYPE_FOREST_SIDE_MID_X,        //33
   TERRAIN_TYPE_FOREST_SIDE_MID_Z,        //34
   TERRAIN_TYPE_FOREST_SIDE_TOP_X,        //35
   TERRAIN_TYPE_FOREST_SIDE_TOP_Z,        //36
                                          //
	// Raised features tops                //
   TERRAIN_TYPE_BUILT_UP_AREA1,           //37
   TERRAIN_TYPE_BUILT_UP_AREA2,           //38
   TERRAIN_TYPE_BUILT_UP_AREA3,           //39
   TERRAIN_TYPE_BUILT_UP_AREA4,           //40
                                          //
   TERRAIN_TYPE_ROAD,                     //41
   TERRAIN_TYPE_TRACK,                    //42
   TERRAIN_TYPE_RAIL,                     //43
	TERRAIN_TYPE_WALL_TOP,                 //44
	TERRAIN_TYPE_HEDGE_TOP,                //45
                                          //
   TERRAIN_TYPE_FOREST_TOP,               //46
                                          //
	// Temporary types used in the terrain //generation, but not in the visual
	TEMP_TERRAIN_TYPE_FRINGE,              //
	TEMP_TERRAIN_TYPE_POWER_LINE,          //
	TEMP_TERRAIN_TYPE_TELEPHONE_LINE,      //
	TEMP_TERRAIN_TYPE_SEA_BANK,            //
	TEMP_TERRAIN_TYPE_COASTAL_RIVER,       //
                                          //
	TEMP_TERRAIN_TYPE_BEACH_MID,           //
                                          //
   TEMP_TERRAIN_TYPE_STEPPED_RIVER_BANK3, //
   TEMP_TERRAIN_TYPE_STEPPED_RIVER_BANK5, //
   TEMP_TERRAIN_TYPE_STEPPED_RIVER_BANK7, //
                                          //
   TEMP_TERRAIN_TYPE_LAKE,                //
                                          //
   TEMP_TERRAIN_TYPE_FOREST_SIDE_X,       //
   TEMP_TERRAIN_TYPE_FOREST_SIDE_Z,       //
                                          //
	TEMP_TERRAIN_TYPE_OFFROAD,             //
	TEMP_TERRAIN_TYPE_POLITICAL_BOUNDARY,  //
	TEMP_TERRAIN_TYPE_BUILT_UP_AREA_BANK,  //
                                          //
	TERRAIN_TYPE_LAST,                     // 62
};

typedef int terrain_types;	//enum TERRAIN_TYPES terrain_types;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//VJ 050814 number of river textures
// declared in textuser.c but needed in terrtype.c
extern int
	start_of_river_textures,
	number_of_river_textures,
	delay_river,
	scale_river_top,scale_river_bottom,
	start_of_sea_textures,
	number_of_sea_textures,
	delay_sea,
	scale_sea_top,scale_sea_bottom;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//
// Xhit:	enum surface_types was added (030328) for downwash effect since terrain_types doesnt
//			tell what kind of surface the terrain_type is.
//			(for example: TERRAIN_TYPE_LAND can be desert or grass depending of campaign)
//
//	Xhit: added SURFACE_TYPE_DESERT for desert campaigns (030515)
//
//////////////////////////////////////////////////////////////////////////////////////////

enum SURFACE_TYPES
{
	SURFACE_TYPE_NONE,

	SURFACE_TYPE_DESERT,
	SURFACE_TYPE_SAND,
	SURFACE_TYPE_GRASS,
	SURFACE_TYPE_ASPHALT,
	SURFACE_TYPE_WATER,
	SURFACE_TYPE_SOIL,
	SURFACE_TYPE_FIELD_LIGHTBROWN,
	SURFACE_TYPE_FIELD_DARKBROWN,
	SURFACE_TYPE_FIELD_LIGHTGREEN,
	SURFACE_TYPE_FIELD_DARKGREEN,
	SURFACE_TYPE_ROCK,
	SURFACE_TYPE_SNOW,

	SURFACE_TYPE_LAST,
};

typedef enum SURFACE_TYPES surface_types;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum TERRAIN_CLASSES
{

	TERRAIN_CLASS_INVALID,

	TERRAIN_CLASS_WATER,
	TERRAIN_CLASS_FOREST,
	TERRAIN_CLASS_LAND,

	TERRAIN_CLASS_LAST,
};

typedef enum TERRAIN_CLASSES terrain_classes;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum DYNAMICS_COLLISION_SURFACE_TYPES
{

	DYNAMICS_COLLISION_SURFACE_GROUND,
	DYNAMICS_COLLISION_SURFACE_WATER,
	DYNAMICS_COLLISION_SURFACE_TREE,
	DYNAMICS_COLLISION_SURFACE_OBJECT,

	NUM_DYNAMICS_COLLISION_SURFACE_TYPES
};

typedef enum DYNAMICS_COLLISION_SURFACE_TYPES dynamics_collision_surface_types;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum TERRAIN_POLYGON_TYPE
{

	POLYGON_TYPE_FAN,
	POLYGON_TYPE_STRIP,
	POLYGON_TYPE_UNKNOWN,
};

typedef enum TERRAIN_POLYGON_TYPE terrain_polygon_type;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TERRAIN_TYPE_INFO
{

	int
		initialised;

	struct SCREEN
		*texture,
		*texture2;

#ifdef OGRE_EE
	int
		texture_index,
		texture2_index;
#endif

	unsigned char
		red,
		green,
		blue,
		transparent;

	float
		xz_texture_scale,
		y_texture_scale,
		xz_texture_scale2,
		y_texture_scale2;

	void ( *render_word_clipped ) ( int number_of_points );

	void ( *render_byte_clipped ) ( int number_of_points );

	void ( *render_word_unclipped ) ( int number_of_points );

	void ( *render_byte_unclipped ) ( int number_of_points );

	terrain_polygon_type
		polygon_type;

	// Xhit: added for the downwash effect (to get type of smokelist actually) (030328)
	surface_types
		surface_type;
};

typedef struct TERRAIN_TYPE_INFO terrain_type_info;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern terrain_type_info
	terrain_type_information[TERRAIN_TYPE_LAST];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void set_3d_terrain_dual_pass_rendering ( int enabled );

extern int get_3d_terrain_dual_pass_rendering ( void );

extern void initialise_3d_terrain_rendering_routines ( int dual_pass );

extern void initialise_3d_terrain_types ( void );

extern void initialise_3d_terrain_map_specific_texture_indices ( void );

extern const char *get_terrain_type_name ( terrain_types type );

// Xhit: added to get surface_type for downwash effect. (030328)
extern int get_terrain_surface_type ( terrain_types type );

extern float texture_gamma_correction(int texture_index);

extern void initialise_noisemaps(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

