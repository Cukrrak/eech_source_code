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

#include	"3d.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAX_VERTEX_BUFFER_SIZE 16384

#define USE_D3D_SOFTWARE_TNL 0

#define USE_ROUND_ROBIN_VBS 1

#define REPORT_RERENDER 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum
{

	PLAIN_VERTEX_BUFFER,
	TEXTURED_VERTEX_BUFFER,
	TEXTURED_TWICE_VERTEX_BUFFER,
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct _D3DPLAINVERTEX
{

	float
		x,
		y,
		z,
		nx,
		ny,
		nz;
} D3DPLAINVERTEX, *LPD3DPLAINVERTEX;

typedef struct _D3DTEXTURE2VERTEX
{

	float
		x,
		y,
		z,
		nx,
		ny,
		nz,
		tu,
		tv,
		tu2,
		tv2;
} D3DTEXTURE2VERTEX, *LPD3DTEXTURE2VERTEX;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct D3D_VB_INFO
{

	int
		number_of_vertices,
		number_of_buffers;
};

typedef struct D3D_VB_INFO d3d_vb_info;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

object_3d_extra_object_info
	*objects_3d_extra_data = NULL;


object_3d_surface_info
	*objects_3d_extra_data_surfaces = NULL;

WORD
	*objects_3d_extra_data_indices = NULL;

LPDIRECT3DVERTEXBUFFERX
	*objects_3d_vertex_buffers = NULL;

int
	*objects_3d_vertex_buffer_sizes = NULL;

int
	total_number_of_d3d_object_surfaces = 0;

int
	current_vb_object = 0,
	total_vb_created = 0,
	total_vb_vertices = 0,
	total_number_of_objects_3d_vertex_buffers = 0;

WORD
	d3d_hardware_vertex_indices[1024];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define NUMBER_OF_PLAIN_D3D_VBS 16
#define NUMBER_OF_TEXTURED_D3D_VBS 16
#define NUMBER_OF_LIGHTMAP_D3D_VBS 2
#define NUMBER_OF_VERTICES_IN_D3D_VBS 2048
#define NUMBER_OF_INDICES_PER_SLOT_FACTOR 10
#define NUMBER_OF_D3D_VB_SLOT_SIZES 4
#define MAX_NUMBER_OF_VERTICES_IN_D3D_VB_SLOT 256
#define MIN_NUMBER_OF_VERTICES_IN_D3D_VB_SLOT 32

LPDIRECT3DVERTEXBUFFERX
	*object_3d_d3d_vbs[D3D_VB_NUMBER_OF_TYPES][NUMBER_OF_D3D_VB_SLOT_SIZES];

d3d_vb_object_3d_info
	*d3d_vb_slots[D3D_VB_NUMBER_OF_TYPES][NUMBER_OF_D3D_VB_SLOT_SIZES],
	*d3d_vb_slots_head[D3D_VB_NUMBER_OF_TYPES][NUMBER_OF_D3D_VB_SLOT_SIZES],
	*d3d_vb_slots_tail[D3D_VB_NUMBER_OF_TYPES][NUMBER_OF_D3D_VB_SLOT_SIZES],
	**object_3d_vb_slot_references;

int
	number_of_d3d_vb_slots[D3D_VB_NUMBER_OF_TYPES][NUMBER_OF_D3D_VB_SLOT_SIZES],
	number_of_d3d_vbs[D3D_VB_NUMBER_OF_TYPES][NUMBER_OF_D3D_VB_SLOT_SIZES];

WORD
	*object_3d_d3d_vb_indices[D3D_VB_NUMBER_OF_TYPES][NUMBER_OF_D3D_VB_SLOT_SIZES];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void restore_3d_vb_routine ( void );

void deinitialise_3d_objects_in_d3d_new ( void );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_3d_objects_in_d3d_old ( void )
{

	static int
		object_vbs_restore_registered = FALSE;

	int
		total_surfaces,
		total_indices,
		count,
		face_count,
		surface_count,
		next_vertex_buffer_index,
		current_plain_vertex_buffer_index,
		current_plain_vertex_buffer_index_vertex_offset,
		current_plain_vertex_buffer_size,
		current_textured_vertex_buffer_index,
		current_textured_vertex_buffer_index_vertex_offset,
		current_textured_vertex_buffer_size,
		current_lightmap_vertex_buffer_index,
		current_lightmap_vertex_buffer_index_vertex_offset,
		current_lightmap_vertex_buffer_size,
		total_vb_memory_allocated,
		*objects_3d_vertex_buffer_types;

	object_3d_surface_info
		*surfaces;

	WORD
		*indices;

	D3DVERTEX
		*textured_vertices;

	D3DPLAINVERTEX
		*plain_vertices;

	D3DTEXTURE2VERTEX
		*lightmap_vertices;

	object_3d
		*object;

	object_3d_face
		*faces;

	HRESULT
		ret;

	debug_log ( "Number of objects to vb: %d", total_number_of_raw_3d_objects );

	debug_watch ( "Current vb object: %d", MT_INT, &current_vb_object );
	debug_watch ( "Total vbs: %d", MT_INT, &total_vb_created );
	debug_watch ( "Total vbs vertices: %d", MT_INT, &total_vb_vertices );

	objects_3d_extra_data = safe_malloc ( ( total_number_of_raw_3d_objects + 1 ) * sizeof ( object_3d_extra_object_info ) );

	memset ( objects_3d_extra_data, 0, ( ( total_number_of_raw_3d_objects + 1 ) * sizeof ( object_3d_extra_object_info ) ) );

	//
	// Allocate an array to store the size of each vertex buffer ( maximum possible buffers is number of 3d objects )
	//

	objects_3d_vertex_buffer_sizes = safe_malloc ( ( total_number_of_raw_3d_objects + 3 ) * sizeof ( int ) );

	objects_3d_vertex_buffer_types = safe_malloc ( ( total_number_of_raw_3d_objects + 3 ) * sizeof ( int ) );

	memset ( objects_3d_vertex_buffer_sizes, 0, ( ( total_number_of_raw_3d_objects + 3 ) * sizeof ( int ) ) );

	memset ( objects_3d_vertex_buffer_types, 0, ( ( total_number_of_raw_3d_objects + 3 ) * sizeof ( int ) ) );

	current_plain_vertex_buffer_index = 0;
	objects_3d_vertex_buffer_types[current_plain_vertex_buffer_index] = PLAIN_VERTEX_BUFFER;

	current_textured_vertex_buffer_index = 1;
	objects_3d_vertex_buffer_types[current_textured_vertex_buffer_index] = TEXTURED_VERTEX_BUFFER;

	current_lightmap_vertex_buffer_index = 2;
	objects_3d_vertex_buffer_types[current_lightmap_vertex_buffer_index] = TEXTURED_TWICE_VERTEX_BUFFER;

	next_vertex_buffer_index = 3;

	//
	// Calculate the number of surfaces and indices in the database
	//

	total_surfaces = 0;

	total_indices = 0;

	for ( count = 1; count <= total_number_of_raw_3d_objects; count++ )
	{

		object = &objects_3d_data[count];

		total_surfaces += objects_3d_data[count].number_of_surfaces;

		faces = objects_3d_data[count].faces;

		for ( surface_count = 0; surface_count < object->number_of_surfaces; surface_count++ )
		{

			int
				number_of_surface_points;

			number_of_surface_points = object->surfaces[surface_count].number_of_points;

			if ( number_of_surface_points == 0 )
			{

				number_of_surface_points = 256;
			}

			if ( number_of_surface_points )
			{

				if ( object->surfaces[surface_count].polygons )
				{

					if ( object->surfaces[surface_count].textured )
					{
	
						if ( object->surfaces[surface_count].has_luminosity_texture )
						{
	
							if ( ( objects_3d_vertex_buffer_sizes[current_lightmap_vertex_buffer_index] + number_of_surface_points ) >= MAX_VERTEX_BUFFER_SIZE )
							{
				
								current_lightmap_vertex_buffer_index = next_vertex_buffer_index;
	
								objects_3d_vertex_buffer_types[current_lightmap_vertex_buffer_index] = TEXTURED_TWICE_VERTEX_BUFFER;
	
								next_vertex_buffer_index++;
							}
				
							objects_3d_vertex_buffer_sizes[current_lightmap_vertex_buffer_index] += number_of_surface_points;
						}
						else
						{
	
							if ( ( objects_3d_vertex_buffer_sizes[current_textured_vertex_buffer_index] + number_of_surface_points ) >= MAX_VERTEX_BUFFER_SIZE )
							{
				
								current_textured_vertex_buffer_index = next_vertex_buffer_index;
	
								objects_3d_vertex_buffer_types[current_textured_vertex_buffer_index] = TEXTURED_VERTEX_BUFFER;
	
								next_vertex_buffer_index++;
							}
				
							objects_3d_vertex_buffer_sizes[current_textured_vertex_buffer_index] += number_of_surface_points;
						}
					}
					else
					{
	
						if ( ( objects_3d_vertex_buffer_sizes[current_plain_vertex_buffer_index] + number_of_surface_points ) >= MAX_VERTEX_BUFFER_SIZE )
						{
			
							current_plain_vertex_buffer_index = next_vertex_buffer_index;

							objects_3d_vertex_buffer_types[current_plain_vertex_buffer_index] = PLAIN_VERTEX_BUFFER;

							next_vertex_buffer_index++;
						}
			
						objects_3d_vertex_buffer_sizes[current_plain_vertex_buffer_index] += number_of_surface_points;
					}
	
					for ( face_count = 0; face_count < object->surfaces[surface_count].number_of_faces; face_count++ )
					{
	
						total_indices += ( ( faces->number_of_points - 2 ) * 3 );
	
						faces++;
					}
				}
			}
		}
	}

	objects_3d_extra_data_surfaces = safe_malloc ( total_surfaces * sizeof ( object_3d_surface_info ) );
	objects_3d_extra_data_indices = safe_malloc ( total_indices * sizeof ( WORD ) );

	total_number_of_d3d_object_surfaces = total_surfaces;
	total_number_of_objects_3d_vertex_buffers = next_vertex_buffer_index;

	objects_3d_vertex_buffers = safe_malloc ( ( sizeof ( LPDIRECT3DVERTEXBUFFERX ) ) * total_number_of_objects_3d_vertex_buffers );

	total_vb_memory_allocated = 0;

	for ( count = 0; count < total_number_of_objects_3d_vertex_buffers; count++ )
	{

		D3DVERTEXBUFFERDESC
			desc;
	
		memset ( &desc, 0, sizeof ( D3DVERTEXBUFFERDESC ) );
		desc.dwSize = sizeof ( D3DVERTEXBUFFERDESC );

#if USE_D3D_SOFTWARE_TNL
		desc.dwCaps = ( d3d_using_hardware_tnl ) ? ( D3DVBCAPS_WRITEONLY ) : ( D3DVBCAPS_WRITEONLY | D3DVBCAPS_SYSTEMMEMORY );
		desc.dwCaps |= D3DVBCAPS_SYSTEMMEMORY;
#else
		desc.dwCaps = D3DVBCAPS_DONOTCLIP;
		desc.dwCaps |= D3DVBCAPS_WRITEONLY;
#endif

		desc.dwNumVertices = objects_3d_vertex_buffer_sizes[count];

		switch ( objects_3d_vertex_buffer_types[count] )
		{

			case PLAIN_VERTEX_BUFFER:				desc.dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX0; total_vb_memory_allocated += ( objects_3d_vertex_buffer_sizes[count] * 24 ); break;
			case TEXTURED_VERTEX_BUFFER:			desc.dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1; total_vb_memory_allocated += ( objects_3d_vertex_buffer_sizes[count] * 32 ); break;
			case TEXTURED_TWICE_VERTEX_BUFFER:	desc.dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX2; total_vb_memory_allocated += ( objects_3d_vertex_buffer_sizes[count] * 40 ); break;
		}

		total_vb_memory_allocated += 2048;
		total_vb_created++;
		total_vb_vertices += objects_3d_vertex_buffer_sizes[count];

		ret = IDirect3D7_CreateVertexBuffer ( d3d.d3d, &desc, &objects_3d_vertex_buffers[count], 0 );

		if ( FAILED ( ret ) )
		{
	
			debug_fatal ( "Unable to create vertex buffer: %s", get_d3d_error_message ( ret ) );
		}
	}

	debug_log ( "Allocated %d bytes for object VBs", total_vb_memory_allocated );

	//
	// Go through converting all the objects
	//

	surfaces = objects_3d_extra_data_surfaces;

	indices = objects_3d_extra_data_indices;

	current_plain_vertex_buffer_index = 0;
	current_plain_vertex_buffer_index_vertex_offset = 0;
	current_plain_vertex_buffer_size = objects_3d_vertex_buffer_sizes[current_plain_vertex_buffer_index ];

	current_textured_vertex_buffer_index = 1;
	current_textured_vertex_buffer_index_vertex_offset = 0;
	current_textured_vertex_buffer_size = objects_3d_vertex_buffer_sizes[current_textured_vertex_buffer_index ];

	current_lightmap_vertex_buffer_index = 2;
	current_lightmap_vertex_buffer_index_vertex_offset = 0;
	current_lightmap_vertex_buffer_size = objects_3d_vertex_buffer_sizes[current_lightmap_vertex_buffer_index ];

	next_vertex_buffer_index = 3;

	ret = IDirect3DVertexBuffer7_Lock ( objects_3d_vertex_buffers[current_plain_vertex_buffer_index], DDLOCK_NOSYSLOCK | DDLOCK_WRITEONLY | DDLOCK_SURFACEMEMORYPTR, &plain_vertices, NULL );

	if ( FAILED ( ret ) )
	{

		debug_fatal ( "Unable to lock vertex buffer: %s", get_ddraw_error_message ( ret ) );
	}

	ret = IDirect3DVertexBuffer7_Lock ( objects_3d_vertex_buffers[current_textured_vertex_buffer_index], DDLOCK_NOSYSLOCK | DDLOCK_WRITEONLY | DDLOCK_SURFACEMEMORYPTR, &textured_vertices, NULL );

	if ( FAILED ( ret ) )
	{

		debug_fatal ( "Unable to lock vertex buffer: %s", get_ddraw_error_message ( ret ) );
	}

	ret = IDirect3DVertexBuffer7_Lock ( objects_3d_vertex_buffers[current_lightmap_vertex_buffer_index], DDLOCK_NOSYSLOCK | DDLOCK_WRITEONLY | DDLOCK_SURFACEMEMORYPTR, &lightmap_vertices, NULL );

	if ( FAILED ( ret ) )
	{

		debug_fatal ( "Unable to lock vertex buffer: %s", get_ddraw_error_message ( ret ) );
	}

	for ( count = 1; count <= total_number_of_raw_3d_objects; count++ )
	{

		float
			xmax,
			ymax,
			zmax;

		int
			surface_vertex_offset;

		object_3d_extra_object_info
			*object_extra;

		current_vb_object = count;
		object = &objects_3d_data[count];
		object_extra = &objects_3d_extra_data[count];

		xmax = max ( fabs ( object->bounding_box.xmin ), fabs ( object->bounding_box.xmax ) );
		ymax = max ( fabs ( object->bounding_box.ymin ), fabs ( object->bounding_box.ymax ) );
		zmax = max ( fabs ( object->bounding_box.zmin ), fabs ( object->bounding_box.zmax ) );

		object_extra->surfaces = NULL;

		object_extra->surfaces = surfaces;

		faces = object->faces;
		current_object_3d_surface = object->surfaces;
		current_object_3d_point_list = object->object_faces_point_plain_list;
		current_object_3d_face_normal_list = object->object_face_normal_references;
	
		current_object_3d_surface_point_list = object->surface_points;
		current_object_3d_surface_point_texture_list = object->surface_texture_points;
		current_object_3d_surface_point_normal_list = object->surface_point_normals;

		for ( surface_count = 0; surface_count < object->number_of_surfaces; surface_count++ )
		{

			int
				face_count,
				vertex_count,
				number_of_surface_points,
				current_face_index_offset;

			current_face_index_offset = 0;
		
			number_of_surface_points = object->surfaces[surface_count].number_of_points;

			if ( number_of_surface_points == 0 )
			{

				number_of_surface_points = 256;
			}

			if ( number_of_surface_points )
			{

				if ( object->surfaces[surface_count].polygons )
				{
	
					if ( object->surfaces[surface_count].textured )
					{

						if ( object->surfaces[surface_count].has_luminosity_texture )
						{

							if ( ( current_lightmap_vertex_buffer_size - number_of_surface_points ) < 0 )
							{
							
								//
								// Move onto the next vertex buffer
								//
		
								ASSERT ( current_lightmap_vertex_buffer_size == 0 );
							
								ret = IDirect3DVertexBuffer7_Unlock ( objects_3d_vertex_buffers[current_lightmap_vertex_buffer_index] );
							
								if ( FAILED ( ret ) )
								{
							
									debug_fatal ( "Unable to unlock vertex buffer: %s", get_d3d_error_message ( ret ) );
								}
							
								ret = IDirect3DVertexBuffer_Optimize ( objects_3d_vertex_buffers[current_lightmap_vertex_buffer_index], d3d.device, 0 );
							
								if ( ret != DD_OK )
								{
							
									debug_fatal ( "Unable to optimize vertex buffer: %s", get_d3d_error_message ( ret ) );
								}
							
								current_lightmap_vertex_buffer_index = next_vertex_buffer_index;
	
								next_vertex_buffer_index++;
							
								current_lightmap_vertex_buffer_index_vertex_offset = 0;
							
								current_lightmap_vertex_buffer_size = objects_3d_vertex_buffer_sizes[current_lightmap_vertex_buffer_index];
		
								if ( current_lightmap_vertex_buffer_index < total_number_of_objects_3d_vertex_buffers )
								{
								
									ret = IDirect3DVertexBuffer7_Lock ( objects_3d_vertex_buffers[current_lightmap_vertex_buffer_index], DDLOCK_NOSYSLOCK | DDLOCK_WRITEONLY | DDLOCK_SURFACEMEMORYPTR, &lightmap_vertices, NULL );
								
									if ( FAILED ( ret ) )
									{
								
										debug_fatal ( "Unable to lock vertex buffer: %s", get_ddraw_error_message ( ret ) );
									}
								}
								else
								{
		
									lightmap_vertices = NULL;
								}
							}
	
							surface_vertex_offset = current_lightmap_vertex_buffer_index_vertex_offset;
			
							for ( vertex_count = 0; vertex_count < number_of_surface_points; vertex_count++ )
							{
				
								object_short_3d_point
									*point;
				
								point = &object->points[ current_object_3d_surface_point_list[vertex_count].point ];
				
								lightmap_vertices[vertex_count+surface_vertex_offset].x = ( ( ( float ) point->x ) * xmax / 32767.0 );
								lightmap_vertices[vertex_count+surface_vertex_offset].y = ( ( ( float ) point->y ) * ymax / 32767.0 );
								lightmap_vertices[vertex_count+surface_vertex_offset].z = ( ( ( float ) point->z ) * zmax / 32767.0 );
				
								if ( current_object_3d_surface->smoothed )
								{
				
									object_3d_heading_pitch_normal
										*point_normal;

									vec3d
										normal;
					
									point_normal = &object->point_normals[ current_object_3d_surface_point_normal_list[vertex_count].point ];
									generate_object_3d_point_normal ( point_normal, &normal );

									lightmap_vertices[vertex_count+surface_vertex_offset].nx = normal.x;
									lightmap_vertices[vertex_count+surface_vertex_offset].ny = normal.y;
									lightmap_vertices[vertex_count+surface_vertex_offset].nz = normal.z;
								}
		
								lightmap_vertices[vertex_count+surface_vertex_offset].tu = current_object_3d_surface_point_texture_list[vertex_count*2].u;
								lightmap_vertices[vertex_count+surface_vertex_offset].tv = current_object_3d_surface_point_texture_list[vertex_count*2].v;
								lightmap_vertices[vertex_count+surface_vertex_offset].tu2 = current_object_3d_surface_point_texture_list[vertex_count*2+1].u;
								lightmap_vertices[vertex_count+surface_vertex_offset].tv2 = current_object_3d_surface_point_texture_list[vertex_count*2+1].v;
							}
				
							//
							// Generate the index list for vertex buffer ( and any face point normals )
							//
				
							for ( face_count = 0; face_count < current_object_3d_surface->number_of_faces; face_count++ )
							{
				
								int
									index_count;
							
								WORD
									base_index,
									next_index;
							
								base_index = current_object_3d_point_list[0].point;
								next_index = current_object_3d_point_list[1].point;
							
								for ( index_count = 0; index_count < ( faces->number_of_points - 2 ); index_count++ )
								{
							
									indices[current_face_index_offset++] = base_index;
									indices[current_face_index_offset++] = next_index;
							
									next_index = current_object_3d_point_list[index_count+2].point;
									indices[current_face_index_offset++] = next_index;
								}
			
								if ( !current_object_3d_surface->smoothed )
								{
				
									int
										point_index;
				
									for ( point_index = 0; point_index < faces->number_of_points; point_index++ )
									{
				
										int
											index;
						
										object_3d_heading_pitch_normal
											*point_normal;
	
										vec3d
											normal;
						
										point_normal = &object->point_normals[ current_object_3d_face_normal_list->point ];
										generate_object_3d_point_normal ( point_normal, &normal );
			
										index = current_object_3d_point_list[point_index].point + surface_vertex_offset;
				
										lightmap_vertices[index].nx = normal.x;
										lightmap_vertices[index].ny = normal.y;
										lightmap_vertices[index].nz = normal.z;
									}

									current_object_3d_face_normal_list++;
								}
			
								current_object_3d_point_list += faces->number_of_points;
								faces++;
							}
						}
						else
						{
	
							if ( ( current_textured_vertex_buffer_size - number_of_surface_points ) < 0 )
							{
							
								//
								// Move onto the next vertex buffer
								//
		
								ASSERT ( current_textured_vertex_buffer_size == 0 );
							
								ret = IDirect3DVertexBuffer7_Unlock ( objects_3d_vertex_buffers[current_textured_vertex_buffer_index] );
							
								if ( FAILED ( ret ) )
								{
							
									debug_fatal ( "Unable to unlock vertex buffer: %s", get_d3d_error_message ( ret ) );
								}
							
								ret = IDirect3DVertexBuffer_Optimize ( objects_3d_vertex_buffers[current_textured_vertex_buffer_index], d3d.device, 0 );
							
								if ( ret != DD_OK )
								{
							
									debug_fatal ( "Unable to optimize vertex buffer: %s", get_d3d_error_message ( ret ) );
								}
							
								current_textured_vertex_buffer_index = next_vertex_buffer_index;
	
								next_vertex_buffer_index++;
							
								current_textured_vertex_buffer_index_vertex_offset = 0;
							
								current_textured_vertex_buffer_size = objects_3d_vertex_buffer_sizes[current_textured_vertex_buffer_index];
		
								if ( current_textured_vertex_buffer_index < total_number_of_objects_3d_vertex_buffers )
								{
								
									ret = IDirect3DVertexBuffer7_Lock ( objects_3d_vertex_buffers[current_textured_vertex_buffer_index], DDLOCK_NOSYSLOCK | DDLOCK_WRITEONLY | DDLOCK_SURFACEMEMORYPTR, &textured_vertices, NULL );
								
									if ( FAILED ( ret ) )
									{
								
										debug_fatal ( "Unable to lock vertex buffer: %s", get_ddraw_error_message ( ret ) );
									}
								}
								else
								{
		
									textured_vertices = NULL;
								}
							}
	
							surface_vertex_offset = current_textured_vertex_buffer_index_vertex_offset;
			
							for ( vertex_count = 0; vertex_count < number_of_surface_points; vertex_count++ )
							{
				
								object_short_3d_point
									*point;
				
								point = &object->points[ current_object_3d_surface_point_list[vertex_count].point ];
				
								textured_vertices[vertex_count+surface_vertex_offset].x = ( ( ( float ) point->x ) * xmax / 32767.0 );
								textured_vertices[vertex_count+surface_vertex_offset].y = ( ( ( float ) point->y ) * ymax / 32767.0 );
								textured_vertices[vertex_count+surface_vertex_offset].z = ( ( ( float ) point->z ) * zmax / 32767.0 );
				
								if ( current_object_3d_surface->smoothed )
								{
				
									object_3d_heading_pitch_normal
										*point_normal;

									vec3d
										normal;
					
									point_normal = &object->point_normals[ current_object_3d_surface_point_normal_list[vertex_count].point ];
									generate_object_3d_point_normal ( point_normal, &normal );
				
									textured_vertices[vertex_count+surface_vertex_offset].nx = normal.x;
									textured_vertices[vertex_count+surface_vertex_offset].ny = normal.y;
									textured_vertices[vertex_count+surface_vertex_offset].nz = normal.z;
								}
		
								textured_vertices[vertex_count+surface_vertex_offset].tu = current_object_3d_surface_point_texture_list[vertex_count].u;
								textured_vertices[vertex_count+surface_vertex_offset].tv = current_object_3d_surface_point_texture_list[vertex_count].v;
							}
				
							//
							// Generate the index list for vertex buffer ( and any face point normals )
							//
				
							for ( face_count = 0; face_count < current_object_3d_surface->number_of_faces; face_count++ )
							{
				
								int
									index_count;
							
								WORD
									base_index,
									next_index;
							
								base_index = current_object_3d_point_list[0].point;
								next_index = current_object_3d_point_list[1].point;
							
								for ( index_count = 0; index_count < ( faces->number_of_points - 2 ); index_count++ )
								{
							
									indices[current_face_index_offset++] = base_index;
									indices[current_face_index_offset++] = next_index;
							
									next_index = current_object_3d_point_list[index_count+2].point;
									indices[current_face_index_offset++] = next_index;
								}
			
								if ( !current_object_3d_surface->smoothed )
								{
				
									int
										point_index;
				
									for ( point_index = 0; point_index < faces->number_of_points; point_index++ )
									{
				
										object_3d_heading_pitch_normal
											*point_normal;
	
										vec3d
											normal;
						
										int
											index;
						
										point_normal = &object->point_normals[ current_object_3d_face_normal_list->point ];
										generate_object_3d_point_normal ( point_normal, &normal );
			
										index = current_object_3d_point_list[point_index].point + surface_vertex_offset;
				
										textured_vertices[index].nx = normal.x;
										textured_vertices[index].ny = normal.y;
										textured_vertices[index].nz = normal.z;
									}

									current_object_3d_face_normal_list++;
								}
			
								current_object_3d_point_list += faces->number_of_points;
								faces++;
							}
						}
					}
					else
					{
					
						if ( ( current_plain_vertex_buffer_size - number_of_surface_points ) < 0 )
						{
							
							//
							// Move onto the next vertex buffer
							//
	
							ASSERT ( current_plain_vertex_buffer_size == 0 );
						
							ret = IDirect3DVertexBuffer7_Unlock ( objects_3d_vertex_buffers[current_plain_vertex_buffer_index] );
						
							if ( FAILED ( ret ) )
							{
						
								debug_fatal ( "Unable to unlock vertex buffer: %s", get_d3d_error_message ( ret ) );
							}
						
							ret = IDirect3DVertexBuffer_Optimize ( objects_3d_vertex_buffers[current_plain_vertex_buffer_index], d3d.device, 0 );
						
							if ( ret != DD_OK )
							{
						
								debug_fatal ( "Unable to optimize vertex buffer: %s", get_d3d_error_message ( ret ) );
							}
						
							current_plain_vertex_buffer_index = next_vertex_buffer_index;
	
							next_vertex_buffer_index++;
						
							current_plain_vertex_buffer_index_vertex_offset = 0;
						
							current_plain_vertex_buffer_size = objects_3d_vertex_buffer_sizes[current_plain_vertex_buffer_index];
	
							if ( current_plain_vertex_buffer_index < total_number_of_objects_3d_vertex_buffers )
							{
							
								ret = IDirect3DVertexBuffer7_Lock ( objects_3d_vertex_buffers[current_plain_vertex_buffer_index], DDLOCK_NOSYSLOCK | DDLOCK_WRITEONLY | DDLOCK_SURFACEMEMORYPTR, &plain_vertices, NULL );
							
								if ( FAILED ( ret ) )
								{
							
									debug_fatal ( "Unable to lock vertex buffer: %s", get_ddraw_error_message ( ret ) );
								}
							}
							else
							{
	
								plain_vertices = NULL;
							}
						}

						surface_vertex_offset = current_plain_vertex_buffer_index_vertex_offset;
		
						for ( vertex_count = 0; vertex_count < number_of_surface_points; vertex_count++ )
						{
			
							object_short_3d_point
								*point;
			
							point = &object->points[ current_object_3d_surface_point_list[vertex_count].point ];
			
							plain_vertices[vertex_count+surface_vertex_offset].x = ( ( ( float ) point->x ) * xmax / 32767.0 );
							plain_vertices[vertex_count+surface_vertex_offset].y = ( ( ( float ) point->y ) * ymax / 32767.0 );
							plain_vertices[vertex_count+surface_vertex_offset].z = ( ( ( float ) point->z ) * zmax / 32767.0 );
			
							if ( current_object_3d_surface->smoothed )
							{
			
								object_3d_heading_pitch_normal
									*point_normal;

								vec3d
									normal;
				
								point_normal = &object->point_normals[ current_object_3d_surface_point_normal_list[vertex_count].point ];
								generate_object_3d_point_normal ( point_normal, &normal );
			
								plain_vertices[vertex_count+surface_vertex_offset].nx = normal.x;
								plain_vertices[vertex_count+surface_vertex_offset].ny = normal.y;
								plain_vertices[vertex_count+surface_vertex_offset].nz = normal.z;
							}
						}
			
						//
						// Generate the index list for vertex buffer ( and any face point normals )
						//
			
						for ( face_count = 0; face_count < current_object_3d_surface->number_of_faces; face_count++ )
						{
			
							int
								index_count;
						
							WORD
								base_index,
								next_index;
						
							base_index = current_object_3d_point_list[0].point;
							next_index = current_object_3d_point_list[1].point;
						
							for ( index_count = 0; index_count < ( faces->number_of_points - 2 ); index_count++ )
							{
						
								indices[current_face_index_offset++] = base_index;
								indices[current_face_index_offset++] = next_index;
						
								next_index = current_object_3d_point_list[index_count+2].point;
								indices[current_face_index_offset++] = next_index;
							}
		
							if ( !current_object_3d_surface->smoothed )
							{
			
								int
									point_index;
			
								for ( point_index = 0; point_index < faces->number_of_points; point_index++ )
								{
			
									object_3d_heading_pitch_normal
										*point_normal;

									vec3d
										normal;
					
									int
										index;
					
									point_normal = &object->point_normals[ current_object_3d_face_normal_list->point ];
									generate_object_3d_point_normal ( point_normal, &normal );
		
									index = current_object_3d_point_list[point_index].point + surface_vertex_offset;
			
									plain_vertices[index].nx = normal.x;
									plain_vertices[index].ny = normal.y;
									plain_vertices[index].nz = normal.z;
								}

								current_object_3d_face_normal_list++;
							}
		
							current_object_3d_point_list += faces->number_of_points;
							faces++;
						}
					}

					object_extra->surfaces[surface_count].indices = indices;
					object_extra->surfaces[surface_count].number_of_indices = current_face_index_offset;
					object_extra->surfaces[surface_count].start_vertex = surface_vertex_offset;
					object_extra->surfaces[surface_count].number_of_vertices = number_of_surface_points;
				}
				else
				{

					object_extra->surfaces[surface_count].line_points = current_object_3d_point_list;

					object_extra->surfaces[surface_count].surface_points = current_object_3d_surface_point_list;

					for ( face_count = 0; face_count < current_object_3d_surface->number_of_faces; face_count++ )
					{
		
						current_object_3d_point_list += 2;
					}
				}
			}

			//
			// Set up the surface information
			//

			if ( object->surfaces[surface_count].polygons )
			{
	
				if ( object->surfaces[surface_count].textured )
				{
	
					if ( object->surfaces[surface_count].has_luminosity_texture )
					{
		
						object_extra->surfaces[surface_count].vertex_buffer = objects_3d_vertex_buffers[current_lightmap_vertex_buffer_index];
					}
					else
					{
		
						object_extra->surfaces[surface_count].vertex_buffer = objects_3d_vertex_buffers[current_textured_vertex_buffer_index];
					}
				}
				else
				{
	
					object_extra->surfaces[surface_count].vertex_buffer = objects_3d_vertex_buffers[current_plain_vertex_buffer_index];
				}
			}

			indices += current_face_index_offset;

			//
			// Move onto the next surface
			//

			if ( current_object_3d_surface->polygons )
			{

				surface_vertex_offset += number_of_surface_points;

				if ( current_object_3d_surface->textured )
				{

					if ( object->surfaces[surface_count].has_luminosity_texture )
					{
	
						current_lightmap_vertex_buffer_size -= number_of_surface_points;
						current_lightmap_vertex_buffer_index_vertex_offset += number_of_surface_points;
					}
					else
					{
	
						current_textured_vertex_buffer_size -= number_of_surface_points;
						current_textured_vertex_buffer_index_vertex_offset += number_of_surface_points;
					}
				}
				else
				{

					current_plain_vertex_buffer_size -= number_of_surface_points;
					current_plain_vertex_buffer_index_vertex_offset += number_of_surface_points;
				}
			}

			if ( current_object_3d_surface->smoothed )					current_object_3d_surface_point_normal_list += number_of_surface_points;
			if ( current_object_3d_surface->textured )					current_object_3d_surface_point_texture_list += number_of_surface_points;
			if ( current_object_3d_surface->has_luminosity_texture )	current_object_3d_surface_point_texture_list += number_of_surface_points;
	
			current_object_3d_surface_point_list += number_of_surface_points;
			current_object_3d_surface++;
		}

		surfaces += object->number_of_surfaces;
	}

	//
	// Finish up the last vertex buffer
	//

	if ( lightmap_vertices )
	{
	
		ret = IDirect3DVertexBuffer7_Unlock ( objects_3d_vertex_buffers[current_lightmap_vertex_buffer_index] );
	
		if ( FAILED ( ret ) )
		{
	
			debug_fatal ( "Unable to unlock vertex buffer: %s", get_d3d_error_message ( ret ) );
		}
	
		ret = IDirect3DVertexBuffer_Optimize ( objects_3d_vertex_buffers[current_lightmap_vertex_buffer_index], d3d.device, 0 );
	
		if ( ret != DD_OK )
		{
	
			debug_fatal ( "Unable to optimize vertex buffer: %s", get_d3d_error_message ( ret ) );
		}
	}

	if ( textured_vertices )
	{
	
		ret = IDirect3DVertexBuffer7_Unlock ( objects_3d_vertex_buffers[current_textured_vertex_buffer_index] );
	
		if ( FAILED ( ret ) )
		{
	
			debug_fatal ( "Unable to unlock vertex buffer: %s", get_d3d_error_message ( ret ) );
		}
	
		ret = IDirect3DVertexBuffer_Optimize ( objects_3d_vertex_buffers[current_textured_vertex_buffer_index], d3d.device, 0 );
	
		if ( ret != DD_OK )
		{
	
			debug_fatal ( "Unable to optimize vertex buffer: %s", get_d3d_error_message ( ret ) );
		}
	}

	if ( plain_vertices )
	{
	
		ret = IDirect3DVertexBuffer7_Unlock ( objects_3d_vertex_buffers[current_plain_vertex_buffer_index] );
	
		if ( FAILED ( ret ) )
		{
	
			debug_fatal ( "Unable to unlock vertex buffer: %s", get_d3d_error_message ( ret ) );
		}
	
		ret = IDirect3DVertexBuffer_Optimize ( objects_3d_vertex_buffers[current_plain_vertex_buffer_index], d3d.device, 0 );
	
		if ( ret != DD_OK )
		{
	
			debug_fatal ( "Unable to optimize vertex buffer: %s", get_d3d_error_message ( ret ) );
		}
	}


	if ( !object_vbs_restore_registered )
	{

		register_restore_vb_routine ( restore_3d_vb_routine );

		object_vbs_restore_registered = TRUE;
	}

	for ( count = 0; count < 1024; count += 2 )
	{

		d3d_hardware_vertex_indices[count] = count;
		d3d_hardware_vertex_indices[count+1] = count+1;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_3d_objects_in_d3d_old ( void )
{

	if ( objects_3d_vertex_buffers )
	{

		int
			count;
	
		HRESULT
			ret;
	
		for ( count = 0; count < total_number_of_objects_3d_vertex_buffers; count++ )
		{
	
			if ( objects_3d_vertex_buffers[count] )
			{
		
				ret = IDirect3DVertexBuffer_Release ( objects_3d_vertex_buffers[count] );
		
				if ( FAILED ( ret ) )
				{
		
					debug_log ( "Unable to release primary vertex buffer: %s", get_d3d_error_message ( ret ) );
				}
		
				objects_3d_vertex_buffers[count] = NULL;
	
				total_vb_created--;
			}
		}

		safe_free ( objects_3d_vertex_buffers );

		objects_3d_vertex_buffers = NULL;
	}

	if ( objects_3d_vertex_buffer_sizes )
	{
	
		safe_free ( objects_3d_vertex_buffer_sizes );

		objects_3d_vertex_buffer_sizes = NULL;
	}

	if ( objects_3d_extra_data )
	{

		safe_free ( objects_3d_extra_data );

		objects_3d_extra_data = NULL;
	}

	if ( objects_3d_extra_data_surfaces )
	{
		safe_free ( objects_3d_extra_data_surfaces );

		objects_3d_extra_data_surfaces = NULL;
	}

	if ( objects_3d_extra_data_indices )
	{

		safe_free ( objects_3d_extra_data_indices );

		objects_3d_extra_data_indices = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void restore_3d_vb_routine ( void )
{

	debug_log ( "RESTORING 3D VBS" );

	deinitialise_3d_objects_in_d3d ();

	initialise_3d_objects_in_d3d ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_3d_objects_in_d3d ( void )
{

	static int
		object_vbs_restore_registered = FALSE;

	int
		total_surfaces,
		count,
		number_of_vertices_in_slot,
		size_slot,
		type;

	deinitialise_3d_objects_in_d3d ();

	//
	// Allocate vertex buffers & slots
	//

	for ( size_slot = 0; size_slot < NUMBER_OF_D3D_VB_SLOT_SIZES; size_slot++ )
	{
	
		number_of_d3d_vbs[D3D_VB_PLAIN_TYPE][size_slot] = NUMBER_OF_PLAIN_D3D_VBS;
		number_of_d3d_vbs[D3D_VB_TEXTURED_TYPE][size_slot] = NUMBER_OF_TEXTURED_D3D_VBS;
		number_of_d3d_vbs[D3D_VB_LIGHTMAP_TYPE][size_slot] = NUMBER_OF_LIGHTMAP_D3D_VBS;
	}

	number_of_vertices_in_slot = MAX_NUMBER_OF_VERTICES_IN_D3D_VB_SLOT;

	for ( size_slot = 0; size_slot < NUMBER_OF_D3D_VB_SLOT_SIZES; size_slot++ )
	{

		number_of_d3d_vb_slots[D3D_VB_PLAIN_TYPE][size_slot] = ( NUMBER_OF_VERTICES_IN_D3D_VBS * NUMBER_OF_PLAIN_D3D_VBS ) / number_of_vertices_in_slot;
		number_of_d3d_vb_slots[D3D_VB_TEXTURED_TYPE][size_slot] = ( NUMBER_OF_VERTICES_IN_D3D_VBS * NUMBER_OF_TEXTURED_D3D_VBS ) / number_of_vertices_in_slot;
		number_of_d3d_vb_slots[D3D_VB_LIGHTMAP_TYPE][size_slot] = ( NUMBER_OF_VERTICES_IN_D3D_VBS * NUMBER_OF_LIGHTMAP_D3D_VBS ) / number_of_vertices_in_slot;

		number_of_vertices_in_slot >>= 1;
	}

	number_of_vertices_in_slot = MAX_NUMBER_OF_VERTICES_IN_D3D_VB_SLOT;

	for ( size_slot = 0; size_slot < NUMBER_OF_D3D_VB_SLOT_SIZES; size_slot++ )
	{
	
		for ( type = D3D_VB_PLAIN_TYPE; type < D3D_VB_NUMBER_OF_TYPES; type++ )
		{
	
			int
				slot_index;
	
			d3d_vb_slots[type][size_slot] = safe_malloc ( sizeof ( d3d_vb_object_3d_info ) * number_of_d3d_vb_slots[type][size_slot] );
		
			object_3d_d3d_vbs[type][size_slot] = safe_malloc ( sizeof ( LPDIRECT3DVERTEXBUFFERX ) * number_of_d3d_vbs[type][size_slot] );
	
			object_3d_d3d_vb_indices[type][size_slot] = safe_malloc ( sizeof ( WORD ) * ( number_of_vertices_in_slot * NUMBER_OF_INDICES_PER_SLOT_FACTOR * number_of_d3d_vb_slots[type][size_slot] ) );
	
			slot_index = 0;
	
			for ( count = 0; count < number_of_d3d_vbs[type][size_slot]; count++ )
			{
		
				D3DVERTEXBUFFERDESC
					desc;
	
				HRESULT
					ret;
	
				int
					temp;
			
				memset ( &desc, 0, sizeof ( D3DVERTEXBUFFERDESC ) );
				desc.dwSize = sizeof ( D3DVERTEXBUFFERDESC );
		
	#if USE_D3D_SOFTWARE_TNL
				desc.dwCaps = ( d3d_using_hardware_tnl ) ? ( D3DVBCAPS_WRITEONLY ) : ( D3DVBCAPS_WRITEONLY | D3DVBCAPS_SYSTEMMEMORY );
				desc.dwCaps |= D3DVBCAPS_SYSTEMMEMORY;
	#else
	//			desc.dwCaps = D3DVBCAPS_DONOTCLIP;
				desc.dwCaps |= D3DVBCAPS_WRITEONLY;
	#endif
		
				desc.dwNumVertices = NUMBER_OF_VERTICES_IN_D3D_VBS;
		
				switch ( type )
				{
	
					case D3D_VB_PLAIN_TYPE:		desc.dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX0; break;
					case D3D_VB_TEXTURED_TYPE:	desc.dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1; break;
					case D3D_VB_LIGHTMAP_TYPE:	desc.dwFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX2; break;
				}
	
				ret = IDirect3D7_CreateVertexBuffer ( d3d.d3d, &desc, &object_3d_d3d_vbs[type][size_slot][count], 0 );
		
				if ( FAILED ( ret ) )
				{
			
					debug_fatal ( "Unable to create vertex buffer: %s", get_d3d_error_message ( ret ) );
				}
	
				//
				// Now create the slots for this vertex buffer
				//
	
				for ( temp = 0; temp < ( NUMBER_OF_VERTICES_IN_D3D_VBS / number_of_vertices_in_slot ); temp++ )
				{
	
					if ( slot_index )
					{
			
						d3d_vb_slots[type][size_slot][slot_index].pred = &d3d_vb_slots[type][size_slot][slot_index-1];
					}
					else
					{
	
						d3d_vb_slots[type][size_slot][slot_index].pred = NULL;
	
						d3d_vb_slots_head[type][size_slot] = &d3d_vb_slots[type][size_slot][slot_index];
					}
			
					if ( ( slot_index + 1 ) < number_of_d3d_vb_slots[type][size_slot] )
					{
			
						d3d_vb_slots[type][size_slot][slot_index].succ = &d3d_vb_slots[type][size_slot][slot_index+1];
					}
					else
					{
	
						d3d_vb_slots[type][size_slot][slot_index].succ = NULL;
	
						d3d_vb_slots_tail[type][size_slot] = &d3d_vb_slots[type][size_slot][slot_index];
					}
			
					d3d_vb_slots[type][size_slot][slot_index].buffer = object_3d_d3d_vbs[type][size_slot][count];
					d3d_vb_slots[type][size_slot][slot_index].indices = &object_3d_d3d_vb_indices[type][size_slot][slot_index * number_of_vertices_in_slot * NUMBER_OF_INDICES_PER_SLOT_FACTOR];
					d3d_vb_slots[type][size_slot][slot_index].vertex_offset = temp * number_of_vertices_in_slot;
					d3d_vb_slots[type][size_slot][slot_index].number_of_vertices = 0;
					d3d_vb_slots[type][size_slot][slot_index].number_of_indices = 0;
					d3d_vb_slots[type][size_slot][slot_index].surface_reference = NULL;
	
					slot_index++;
				}
			}
		}

		number_of_vertices_in_slot >>= 1;
	}

	//
	// Allocate surface reference pointers
	//

	total_surfaces = 0;

	for ( count = 1; count <= total_number_of_raw_3d_objects; count++ )
	{

		total_surfaces += objects_3d_data[count].number_of_surfaces;
	}

	object_3d_vb_slot_references = safe_malloc ( sizeof ( d3d_vb_object_3d_info * ) * total_surfaces );

	memset ( object_3d_vb_slot_references, 0, ( sizeof ( d3d_vb_object_3d_info * ) * total_surfaces ) );

	//
	// Set line vertex indices
	//

	for ( count = 0; count < 1024; count += 2 )
	{

		d3d_hardware_vertex_indices[count] = count;
		d3d_hardware_vertex_indices[count+1] = count+1;
	}

	//
	// Register the restore routine for Alt-tab situations
	//

	if ( !object_vbs_restore_registered )
	{

		register_restore_vb_routine ( restore_3d_vb_routine );

		object_vbs_restore_registered = TRUE;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_3d_objects_in_d3d ( void )
{

	int
		size_slot,
		type;


	debug_log ( "DEINITIALISING 3d OBJECTS" );

	if ( object_3d_vb_slot_references )
	{

		safe_free ( object_3d_vb_slot_references );

		object_3d_vb_slot_references = NULL;
	}

	for ( size_slot = 0; size_slot < NUMBER_OF_D3D_VB_SLOT_SIZES; size_slot++ )
	{
	
		for ( type = D3D_VB_PLAIN_TYPE; type < D3D_VB_NUMBER_OF_TYPES; type++ )
		{
	
			int
				count;
	
			d3d_vb_slots_tail[type][size_slot] = NULL;
	
			d3d_vb_slots_head[type][size_slot] = NULL;
	
			if ( d3d_vb_slots[type][size_slot] )
			{
	
				safe_free ( d3d_vb_slots[type][size_slot] );
	
				d3d_vb_slots[type][size_slot] = NULL;
			}
	
			if ( object_3d_d3d_vb_indices[type][size_slot] )
			{
	
				safe_free ( object_3d_d3d_vb_indices[type][size_slot] );
	
				object_3d_d3d_vb_indices[type][size_slot] = NULL;
			}
	
			if ( object_3d_d3d_vbs[type][size_slot] )
			{
	
				for ( count = 0; count < number_of_d3d_vbs[type][size_slot]; count++ )
				{
	
					if ( object_3d_d3d_vbs[type][size_slot][count] )
					{
		
						HRESULT
							ret;
		
						ret = IDirect3DVertexBuffer_Release ( object_3d_d3d_vbs[type][size_slot][count] );
				
						if ( FAILED ( ret ) )
						{
				
							debug_log ( "Unable to release primary vertex buffer: %s", get_d3d_error_message ( ret ) );
						}
		
						object_3d_d3d_vbs[type][size_slot][count] = NULL;
					}
				}
	
				safe_free ( object_3d_d3d_vbs[type][size_slot] );
	
				object_3d_d3d_vbs[type][size_slot] = NULL;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void object_3d_render_hardware_surface ( object_3d *object )
{

	int
		prevent_rendering,
		type,
		global_surface_index,
		size_slot,
		number_of_vertices_in_slot,
		half_number_of_vertices_in_slot,
		number_of_surface_points;

	HRESULT
		ret;

	d3d_vb_object_3d_info
		*surface;

	D3DVERTEX
		*textured_vertices;

	D3DPLAINVERTEX
		*plain_vertices;

	D3DTEXTURE2VERTEX
		*lightmap_vertices;

	//
	// Check current surface
	//

	ASSERT ( current_object_3d_surface->polygons );

	global_surface_index = ( current_object_3d_surface - object_database_surfaces );

	surface = object_3d_vb_slot_references[global_surface_index];

	//
	// Get the type of vertex buffer we need
	//

	if ( current_object_3d_surface->textured )
	{

		if ( current_object_3d_surface->has_luminosity_texture )
		{

			type = D3D_VB_LIGHTMAP_TYPE;
		}
		else
		{

			type = D3D_VB_TEXTURED_TYPE;
		}
	}
	else
	{

		type = D3D_VB_PLAIN_TYPE;
	}

	//
	// Now, figure out what size slot we're dealing with
	//

	number_of_surface_points = current_object_3d_surface->number_of_points;

	if ( number_of_surface_points == 0 )
	{

		number_of_surface_points = 256;
	}

	ASSERT ( number_of_surface_points );

	size_slot = 0;
	number_of_vertices_in_slot = MAX_NUMBER_OF_VERTICES_IN_D3D_VB_SLOT;
	half_number_of_vertices_in_slot = MAX_NUMBER_OF_VERTICES_IN_D3D_VB_SLOT / 2;

	while ( ( number_of_surface_points < half_number_of_vertices_in_slot ) && ( half_number_of_vertices_in_slot >= MIN_NUMBER_OF_VERTICES_IN_D3D_VB_SLOT ) )
	{

		size_slot++;
		number_of_vertices_in_slot >>= 1;
		half_number_of_vertices_in_slot >>= 1;
	}

	prevent_rendering = FALSE;

	if ( !surface )
	{

		int
			face_count,
			vertex_count,
			current_face_index_offset,
			surface_vertex_offset,
			lock_flags;

		float
			xmax,
			ymax,
			zmax;

		WORD
			*indices;

		object_3d_face
			*faces;

		point_3d_short_reference
			*saved_object_3d_point_list;

		point_3d_plain_reference
			*saved_object_3d_face_normal_list;

		//
		// Remove first vb slot of this type
		//

		surface = d3d_vb_slots_head[type][size_slot];

		if ( surface->surface_reference )
		{

			*( surface->surface_reference ) = NULL;
		}

		//
		// Try to lock the vertex buffer
		//

		textured_vertices = NULL;
		plain_vertices = NULL;
		lightmap_vertices = NULL;

		lock_flags = DDLOCK_NOSYSLOCK | DDLOCK_WRITEONLY | DDLOCK_SURFACEMEMORYPTR;

		switch ( type )
		{

			case D3D_VB_PLAIN_TYPE:		ret = IDirect3DVertexBuffer7_Lock ( surface->buffer, lock_flags, &plain_vertices, NULL ); break;
			case D3D_VB_TEXTURED_TYPE: ret = IDirect3DVertexBuffer7_Lock ( surface->buffer, lock_flags, &textured_vertices, NULL ); break;
			case D3D_VB_LIGHTMAP_TYPE: ret = IDirect3DVertexBuffer7_Lock ( surface->buffer, lock_flags, &lightmap_vertices, NULL ); break;
		}

#if REPORT_RERENDER
		switch ( type )
		{

			case D3D_VB_PLAIN_TYPE:		debug_log ( "Constructing plain" ); break;
			case D3D_VB_TEXTURED_TYPE: debug_log ( "Constructing textured" ); break;
			case D3D_VB_LIGHTMAP_TYPE: debug_log ( "Constructing lightmap" ); break;
		}
#endif

		if ( FAILED ( ret ) )
		{

			//
			// Don't try to draw this vertex buffer!!!!
			//

			prevent_rendering = TRUE;
		}
		else
		{
	
			object_3d_vb_slot_references[global_surface_index] = surface;
			surface->surface_reference = &object_3d_vb_slot_references[global_surface_index];
			indices = surface->indices;
	
			saved_object_3d_point_list = current_object_3d_point_list;
			saved_object_3d_face_normal_list = current_object_3d_face_normal_list;
	
			xmax = max ( fabs ( object->bounding_box.xmin ), fabs ( object->bounding_box.xmax ) );
			ymax = max ( fabs ( object->bounding_box.ymin ), fabs ( object->bounding_box.ymax ) );
			zmax = max ( fabs ( object->bounding_box.zmin ), fabs ( object->bounding_box.zmax ) );
	
			current_face_index_offset = 0;
		
			surface_vertex_offset = surface->vertex_offset;
	
			if ( current_object_3d_surface->textured )
			{
	
				if ( current_object_3d_surface->has_luminosity_texture )
				{
	
					for ( vertex_count = 0; vertex_count < number_of_surface_points; vertex_count++ )
					{
		
						object_short_3d_point
							*point;
		
						point = &object->points[ current_object_3d_surface_point_list[vertex_count].point ];
		
						lightmap_vertices[vertex_count+surface_vertex_offset].x = ( ( ( float ) point->x ) * xmax / 32767.0 );
						lightmap_vertices[vertex_count+surface_vertex_offset].y = ( ( ( float ) point->y ) * ymax / 32767.0 );
						lightmap_vertices[vertex_count+surface_vertex_offset].z = ( ( ( float ) point->z ) * zmax / 32767.0 );
		
						if ( current_object_3d_surface->smoothed )
						{
		
							object_3d_heading_pitch_normal
								*point_normal;
	
							vec3d
								normal;
			
							point_normal = &object->point_normals[ current_object_3d_surface_point_normal_list[vertex_count].point ];
							generate_object_3d_point_normal ( point_normal, &normal );
	
							lightmap_vertices[vertex_count+surface_vertex_offset].nx = normal.x;
							lightmap_vertices[vertex_count+surface_vertex_offset].ny = normal.y;
							lightmap_vertices[vertex_count+surface_vertex_offset].nz = normal.z;
						}
	
						lightmap_vertices[vertex_count+surface_vertex_offset].tu = current_object_3d_surface_point_texture_list[vertex_count*2].u;
						lightmap_vertices[vertex_count+surface_vertex_offset].tv = current_object_3d_surface_point_texture_list[vertex_count*2].v;
						lightmap_vertices[vertex_count+surface_vertex_offset].tu2 = current_object_3d_surface_point_texture_list[vertex_count*2+1].u;
						lightmap_vertices[vertex_count+surface_vertex_offset].tv2 = current_object_3d_surface_point_texture_list[vertex_count*2+1].v;
					}
		
					//
					// Generate any face point normals
					//
	
					if ( !current_object_3d_surface->smoothed )
					{
	
						faces = current_object_3d_faces;
	
						for ( face_count = 0; face_count < current_object_3d_surface->number_of_faces; face_count++ )
						{
			
							int
								point_index;
		
							for ( point_index = 0; point_index < faces->number_of_points; point_index++ )
							{
		
								int
									index;
				
								object_3d_heading_pitch_normal
									*point_normal;
	
								vec3d
									normal;
				
								point_normal = &object->point_normals[ current_object_3d_face_normal_list->point ];
								generate_object_3d_point_normal ( point_normal, &normal );
	
								index = current_object_3d_point_list[point_index].point + surface_vertex_offset;
		
								lightmap_vertices[index].nx = normal.x;
								lightmap_vertices[index].ny = normal.y;
								lightmap_vertices[index].nz = normal.z;
							}
	
							current_object_3d_face_normal_list++;
							current_object_3d_point_list += faces->number_of_points;
							faces++;
						}
					}
				}
				else
				{
	
					for ( vertex_count = 0; vertex_count < number_of_surface_points; vertex_count++ )
					{
		
						object_short_3d_point
							*point;
		
						point = &object->points[ current_object_3d_surface_point_list[vertex_count].point ];
		
						textured_vertices[vertex_count+surface_vertex_offset].x = ( ( ( float ) point->x ) * xmax / 32767.0 );
						textured_vertices[vertex_count+surface_vertex_offset].y = ( ( ( float ) point->y ) * ymax / 32767.0 );
						textured_vertices[vertex_count+surface_vertex_offset].z = ( ( ( float ) point->z ) * zmax / 32767.0 );
		
						if ( current_object_3d_surface->smoothed )
						{
		
							object_3d_heading_pitch_normal
								*point_normal;
	
							vec3d
								normal;
			
							point_normal = &object->point_normals[ current_object_3d_surface_point_normal_list[vertex_count].point ];
							generate_object_3d_point_normal ( point_normal, &normal );
		
							textured_vertices[vertex_count+surface_vertex_offset].nx = normal.x;
							textured_vertices[vertex_count+surface_vertex_offset].ny = normal.y;
							textured_vertices[vertex_count+surface_vertex_offset].nz = normal.z;
						}
	
						textured_vertices[vertex_count+surface_vertex_offset].tu = current_object_3d_surface_point_texture_list[vertex_count].u;
						textured_vertices[vertex_count+surface_vertex_offset].tv = current_object_3d_surface_point_texture_list[vertex_count].v;
					}
		
					//
					// Generate the index list for vertex buffer ( and any face point normals )
					//
	
					if ( !current_object_3d_surface->smoothed )
					{
	
						faces = current_object_3d_faces;
	
						for ( face_count = 0; face_count < current_object_3d_surface->number_of_faces; face_count++ )
						{
			
							int
								point_index;
		
							for ( point_index = 0; point_index < faces->number_of_points; point_index++ )
							{
		
								object_3d_heading_pitch_normal
									*point_normal;
	
								vec3d
									normal;
				
								int
									index;
				
								point_normal = &object->point_normals[ current_object_3d_face_normal_list->point ];
								generate_object_3d_point_normal ( point_normal, &normal );
	
								index = current_object_3d_point_list[point_index].point + surface_vertex_offset;
		
								textured_vertices[index].nx = normal.x;
								textured_vertices[index].ny = normal.y;
								textured_vertices[index].nz = normal.z;
							}
	
							current_object_3d_face_normal_list++;
							current_object_3d_point_list += faces->number_of_points;
							faces++;
						}
					}
				}
			}
			else
			{
			
				for ( vertex_count = 0; vertex_count < number_of_surface_points; vertex_count++ )
				{
	
					object_short_3d_point
						*point;
	
					point = &object->points[ current_object_3d_surface_point_list[vertex_count].point ];
	
					plain_vertices[vertex_count+surface_vertex_offset].x = ( ( ( float ) point->x ) * xmax / 32767.0 );
					plain_vertices[vertex_count+surface_vertex_offset].y = ( ( ( float ) point->y ) * ymax / 32767.0 );
					plain_vertices[vertex_count+surface_vertex_offset].z = ( ( ( float ) point->z ) * zmax / 32767.0 );
	
					if ( current_object_3d_surface->smoothed )
					{
	
						object_3d_heading_pitch_normal
							*point_normal;
	
						vec3d
							normal;
		
						point_normal = &object->point_normals[ current_object_3d_surface_point_normal_list[vertex_count].point ];
						generate_object_3d_point_normal ( point_normal, &normal );
	
						plain_vertices[vertex_count+surface_vertex_offset].nx = normal.x;
						plain_vertices[vertex_count+surface_vertex_offset].ny = normal.y;
						plain_vertices[vertex_count+surface_vertex_offset].nz = normal.z;
					}
				}
	
				//
				// Generate the index list for vertex buffer ( and any face point normals )
				//
	
				if ( !current_object_3d_surface->smoothed )
				{
	
					faces = current_object_3d_faces;
	
					for ( face_count = 0; face_count < current_object_3d_surface->number_of_faces; face_count++ )
					{
		
						int
							point_index;
	
						for ( point_index = 0; point_index < faces->number_of_points; point_index++ )
						{
	
							object_3d_heading_pitch_normal
								*point_normal;
	
							vec3d
								normal;
			
							int
								index;
			
							point_normal = &object->point_normals[ current_object_3d_face_normal_list->point ];
							generate_object_3d_point_normal ( point_normal, &normal );
	
							index = current_object_3d_point_list[point_index].point + surface_vertex_offset;
	
							plain_vertices[index].nx = normal.x;
							plain_vertices[index].ny = normal.y;
							plain_vertices[index].nz = normal.z;
						}
	
						current_object_3d_face_normal_list++;
						current_object_3d_point_list += faces->number_of_points;
						faces++;
					}
				}
			}
	
			//
			// Generate the index list for vertex buffer
			//
	
			faces = current_object_3d_faces;
			current_object_3d_point_list = saved_object_3d_point_list;
			current_object_3d_face_normal_list = saved_object_3d_face_normal_list;
	
			{
	
				current_face_index_offset = 0;
	
				for ( face_count = 0; face_count < current_object_3d_surface->number_of_faces; face_count++ )
				{
		
					int
						index_count;
				
					WORD
						base_index,
						next_index;
				
					base_index = current_object_3d_point_list[0].point;
					next_index = current_object_3d_point_list[1].point;
				
					for ( index_count = 0; index_count < ( faces->number_of_points - 2 ); index_count++ )
					{
				
						indices[current_face_index_offset++] = base_index;
						indices[current_face_index_offset++] = next_index;
				
						next_index = current_object_3d_point_list[index_count+2].point;
						indices[current_face_index_offset++] = next_index;
					}
	
					current_object_3d_point_list += faces->number_of_points;
					faces++;
				}
	
				ASSERT ( current_face_index_offset < ( number_of_surface_points * NUMBER_OF_INDICES_PER_SLOT_FACTOR ) );
			}
	
			//
			// Unlock the vertex buffer
			//
	
			ret = IDirect3DVertexBuffer7_Unlock ( surface->buffer );
	
			if ( FAILED ( ret ) )
			{
	
				debug_fatal ( "Unable to unlock vertex buffer: %s", get_ddraw_error_message ( ret ) );
			}
	
			//
			// Fill in the surface attributes
			//
	
			surface->number_of_vertices = number_of_surface_points;
			surface->number_of_indices = current_face_index_offset;
	
			//
			// Unwind back the object pointers
			//
	
			current_object_3d_point_list = saved_object_3d_point_list;
			current_object_3d_face_normal_list = saved_object_3d_face_normal_list;
		}
	}

	if ( !prevent_rendering )
	{
	
#if ( USE_ROUND_ROBIN_VBS )
	
		if ( surface != d3d_vb_slots_tail[type][size_slot] )
		{
		
			//
			// Remove the surface from the list
			//
		
			if ( surface->pred )
			{
		
				surface->pred->succ = surface->succ;
			}
		
			if ( surface->succ )
			{
		
				surface->succ->pred = surface->pred;
			}
		
			if ( surface == d3d_vb_slots_head[type][size_slot] )
			{
		
				d3d_vb_slots_head[type][size_slot] = surface->succ;
			}
		
			if ( surface == d3d_vb_slots_tail[type][size_slot] )
			{
		
				d3d_vb_slots_tail[type][size_slot] = surface->pred;
			}
		
			//
			// Add it back in to the tail end of the list
			//
		
			surface->pred = d3d_vb_slots_tail[type][size_slot];
		
			surface->succ = NULL;
	
			d3d_vb_slots_tail[type][size_slot]->succ = surface;
		
			d3d_vb_slots_tail[type][size_slot] = surface;
		}
	
#endif
	
		ret = IDirect3DDevice7_DrawIndexedPrimitiveVB ( d3d.device, D3DPT_TRIANGLELIST, surface->buffer,
																			surface->vertex_offset, surface->number_of_vertices,
																			surface->indices, surface->number_of_indices, 0 );
		if ( FAILED ( ret ) )
		{
	
			debug_log ( "Unable to draw indexed primitive: %s", get_d3d_error_message ( ret ) );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

