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

#include "graphics.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define DEBUG_MODULE 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int
	compress_system_textures = FALSE,
	d3d_use_evict_textures = TRUE,
	d3d_allow_32bit_textures = TRUE,
	d3d_allow_paletted_textures = TRUE,
	d3d_paletted_textures_supported = FALSE;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

texture_format
	texture_formats[NUMBER_OF_TEXTURE_TYPES],
	available_texture_formats[256];

int
	number_available_texture_formats;

LPDIRECTDRAWPALETTE
	hardware_texture_palette;

PALETTEENTRY
	hardware_texture_colour_table[256];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int setup_texture_formats ( void );

static int create_multiple_hardware_textures ( int width, int height, texture_map_types type, int number, int successful );

static int create_internal_hardware_texture ( int width, int height, texture_map_types type, int mipmap_level );

static HRESULT CALLBACK enumerate_texture_formats ( LPDDPIXELFORMAT format, LPVOID lpContext );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL initialise_system_texture_formats ( void )
{

	int
		count;

	HRESULT
		d3drval;

	DDSURFACEDESC2
		ddsd;

	//
	// Get the surface description of the render buffer.
	//

	ASSERT ( ddraw.lpRenderBuffer );

	ddsd.dwSize = sizeof ( ddsd );

	IDirectDrawSurface7_GetSurfaceDesc ( ddraw.lpRenderBuffer, &ddsd );

	//
	// Enumerate the texture formats
	//

	number_available_texture_formats = 0;

	d3drval = IDirect3DDevice7_EnumTextureFormats ( d3d.device, ( LPVOID ) enumerate_texture_formats, NULL );

	if ( d3drval != DD_OK )
	{

		debug_log ( "Error during texture format enumeration: %s", get_d3d_error_message ( d3drval ) );

		return ( FALSE );
	}

	//
	// Assume we don't have a suitable texture format for now
	//

	for ( count = TEXTURE_TYPE_INVALID; count < NUMBER_OF_TEXTURE_TYPES; count++ )
	{

		texture_formats[count].valid = FALSE;
	}

	for ( count = 0; count < number_available_texture_formats; count++ )
	{

		if ( ( !available_texture_formats[count].palette ) && ( !texture_formats[TEXTURE_TYPE_SCREEN].valid ) )
		{

			//
			// Check this format for the same format as the screen.
			//

//			if ( memcmp ( &available_texture_formats[count].format, &ddsd.ddpfPixelFormat, sizeof ( DDPIXELFORMAT ) ) == 0 )
			if (	( available_texture_formats[count].format.dwRBitMask == ddsd.ddpfPixelFormat.dwRBitMask ) &&
					( available_texture_formats[count].format.dwGBitMask == ddsd.ddpfPixelFormat.dwGBitMask ) &&
					( available_texture_formats[count].format.dwBBitMask == ddsd.ddpfPixelFormat.dwBBitMask ) &&
					( available_texture_formats[count].format.dwRGBAlphaBitMask == ddsd.ddpfPixelFormat.dwRGBAlphaBitMask ) )
			{

				//
				// We have the screen format as a texture format as well ( that is good ! )
				//

				memcpy ( &texture_formats[TEXTURE_TYPE_SCREEN], &available_texture_formats[count], sizeof ( texture_format ) );

				texture_formats[TEXTURE_TYPE_SCREEN].valid = TRUE;
			}
		}

		if ( ( available_texture_formats[count].palette ) && ( available_texture_formats[count].bpp_palette == 8 ) )
		{

			//
			// This is THE best just colour texture we can get. If its enabled, use it.
			//

			memcpy ( &texture_formats[TEXTURE_TYPE_NOALPHA], &available_texture_formats[count], sizeof ( texture_format ) );

			if ( ( !texture_formats[TEXTURE_TYPE_SINGLEALPHA].valid ) || ( texture_formats[TEXTURE_TYPE_SINGLEALPHA].bpp_alpha < 1 ) )
			{

				memcpy ( &texture_formats[TEXTURE_TYPE_SINGLEALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
			}

			if ( ( !texture_formats[TEXTURE_TYPE_MULTIPLEALPHA].valid ) || ( texture_formats[TEXTURE_TYPE_MULTIPLEALPHA].bpp_alpha < 1 ) )
			{

				memcpy ( &texture_formats[TEXTURE_TYPE_MULTIPLEALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
			}

			if ( ( !texture_formats[TEXTURE_TYPE_MULTIPLEALPHA_16BIT].valid ) || ( texture_formats[TEXTURE_TYPE_MULTIPLEALPHA_16BIT].bpp_alpha < 1 ) )
			{

				memcpy ( &texture_formats[TEXTURE_TYPE_MULTIPLEALPHA_16BIT], &available_texture_formats[count], sizeof ( texture_format ) );
			}
		}
		else if ( ( available_texture_formats[count].bpp_red > 3 ) && ( available_texture_formats[count].bpp_green > 3 ) && ( available_texture_formats[count].bpp_blue > 3 ) )
		{

			if ( !texture_formats[TEXTURE_TYPE_NOALPHA].valid )
			{

				memcpy ( &texture_formats[TEXTURE_TYPE_NOALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
			}
			else if ( !texture_formats[TEXTURE_TYPE_NOALPHA].palette )
			{

				//
				// Compare the quality of the colour ( number of bits rgb )
				//

				if ( available_texture_formats[count].bpp_colour > texture_formats[TEXTURE_TYPE_NOALPHA].bpp_colour )
				{

					if ( available_texture_formats[count].bpp_colour <= 16 )
					{

						memcpy ( &texture_formats[TEXTURE_TYPE_NOALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
					}
				}
			}

			//
			// Check against the pure colour nopalette texture format
			//

			if ( !texture_formats[TEXTURE_TYPE_NOALPHA_NOPALETTE].valid )
			{

				memcpy ( &texture_formats[TEXTURE_TYPE_NOALPHA_NOPALETTE], &available_texture_formats[count], sizeof ( texture_format ) );
			}
			else
			{

				//
				// Compare the quality of the colour ( number of bits rgb )
				//

				if ( available_texture_formats[count].bpp_colour > texture_formats[TEXTURE_TYPE_NOALPHA_NOPALETTE].bpp_colour )
				{

					if ( available_texture_formats[count].bpp_colour <= 16 )
					{

						memcpy ( &texture_formats[TEXTURE_TYPE_NOALPHA_NOPALETTE], &available_texture_formats[count], sizeof ( texture_format ) );
					}
				}
			}

			//
			// Check against the single alpha texture format
			//

			if ( !texture_formats[TEXTURE_TYPE_SINGLEALPHA].valid )
			{

				memcpy ( &texture_formats[TEXTURE_TYPE_SINGLEALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
			}
			else if ( available_texture_formats[count].bpp_alpha )
			{

				if ( texture_formats[TEXTURE_TYPE_SINGLEALPHA].bpp_alpha )
				{

					//
					// Compare the quality of the colour ( number of bits rgb )
					//

					if ( available_texture_formats[count].bpp_colour > texture_formats[TEXTURE_TYPE_SINGLEALPHA].bpp_colour )
					{

						if ( available_texture_formats[count].bpp_colour <= 16 )
						{

							memcpy ( &texture_formats[TEXTURE_TYPE_SINGLEALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
						}
					}
				}
				else
				{

					memcpy ( &texture_formats[TEXTURE_TYPE_SINGLEALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
				}
			}

			//
			// Check against the multiple alpha texture format.
			//

			if ( !texture_formats[TEXTURE_TYPE_MULTIPLEALPHA].valid )
			{

				memcpy ( &texture_formats[TEXTURE_TYPE_MULTIPLEALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
			}
			else
			{

				if ( available_texture_formats[count].bpp_alpha >= 1 )
				{

					//
					// Compare the quality of the ALPHA
					//

					if ( available_texture_formats[count].bpp_alpha > texture_formats[TEXTURE_TYPE_MULTIPLEALPHA].bpp_alpha )
					{

						memcpy ( &texture_formats[TEXTURE_TYPE_MULTIPLEALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
					}
				}
				else
				{

					if ( ( !texture_formats[TEXTURE_TYPE_MULTIPLEALPHA].palette ) && ( texture_formats[TEXTURE_TYPE_MULTIPLEALPHA].bpp_alpha <= 1 ) )
					{

						//
						// Compare the quality of the COLOUR
						//

						if ( available_texture_formats[count].bpp_colour > texture_formats[TEXTURE_TYPE_MULTIPLEALPHA].bpp_colour )
						{
	
							memcpy ( &texture_formats[TEXTURE_TYPE_MULTIPLEALPHA], &available_texture_formats[count], sizeof ( texture_format ) );
						}
					}
				}
			}

			//
			// Check against the multiple alpha 16bit texture format.
			//

			if ( !texture_formats[TEXTURE_TYPE_MULTIPLEALPHA_16BIT].valid )
			{

				memcpy ( &texture_formats[TEXTURE_TYPE_MULTIPLEALPHA_16BIT], &available_texture_formats[count], sizeof ( texture_format ) );
			}
			else
			{

				if ( available_texture_formats[count].bpp_alpha >= 1 )
				{

					//
					// Compare the quality of the ALPHA
					//

					if ( available_texture_formats[count].bpp_alpha > texture_formats[TEXTURE_TYPE_MULTIPLEALPHA_16BIT].bpp_alpha )
					{

						if ( available_texture_formats[count].bpp_colour <= 16 )
						{
		
							memcpy ( &texture_formats[TEXTURE_TYPE_MULTIPLEALPHA_16BIT], &available_texture_formats[count], sizeof ( texture_format ) );
						}
					}
				}
			}
		}
	}

	if ( !texture_formats[TEXTURE_TYPE_NOALPHA].valid )
	{

		debug_log ( "Unable to find a suitable texture format for the 3d card" );

		return ( FALSE );
	}

	set_texture_pixel_formats ();

	return ( TRUE );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL initialise_texture_system ( void )
{

	register_exit_function ( release_all_textures );

	if ( initialise_system_texture_formats () )
	{

		int
			count;

		for ( count = TEXTURE_TYPE_INVALID + 1; count < NUMBER_OF_TEXTURE_TYPES; count++ )
		{

			debug_log ( "Texture %d: Valid %d Palette %d, R:%d, G:%d, B:%d",
								count, texture_formats[count].valid, texture_formats[count].palette,
								texture_formats[count].bpp_red, texture_formats[count].bpp_green, texture_formats[count].bpp_blue );
		}

		return ( TRUE );
	}
	else
	{

		debug_fatal ( "Unable to find a suitable texture format on this card!" );

		return ( FALSE );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static HRESULT CALLBACK enumerate_texture_formats ( LPDDPIXELFORMAT format, LPVOID lpContext )
{

	unsigned long
		m;

	int
		r,
		g,
		b,
		a;

	//
	// Set the surface description
	//

	memset ( &available_texture_formats[number_available_texture_formats], 0, sizeof ( texture_format ) );
	
	memcpy ( &available_texture_formats[number_available_texture_formats].format, format, sizeof ( DDPIXELFORMAT ) );

	//
	// Assess the texture format
	//

	if ( format->dwFlags & DDPF_PALETTEINDEXED8 )
	{

		if ( d3d_allow_paletted_textures )
		{
	
			available_texture_formats[number_available_texture_formats].valid = TRUE;
			available_texture_formats[number_available_texture_formats].palette = TRUE;
			available_texture_formats[number_available_texture_formats].bpp_palette = 8;
			available_texture_formats[number_available_texture_formats].bpp_colour = 0;
			available_texture_formats[number_available_texture_formats].bpp_red = 0;
			available_texture_formats[number_available_texture_formats].bpp_green = 0;
			available_texture_formats[number_available_texture_formats].bpp_blue = 0;

			d3d_paletted_textures_supported = TRUE;
	
			number_available_texture_formats ++;
		}

		return ( DDENUMRET_OK );
	}
	else if ( format->dwFlags & DDPF_PALETTEINDEXED4 )
	{

		//
		// DEBUG DEBUG - ignore 4bpp palette texture format.....
		//						perhaps put it back in later. ( yeah right )
		//
//		available_texture_formats[number_available_texture_formats].palette = TRUE;

//		available_texture_formats[number_available_texture_formats].bpp_palette = 4;

//		number_available_texture_formats ++;

//		debug_log ( "Got palette 4bit entry texture format" );

		return ( DDENUMRET_OK );
	}
	else if ( format->dwFlags & DDPF_RGB )
	{

		available_texture_formats[number_available_texture_formats].valid = TRUE;
		available_texture_formats[number_available_texture_formats].palette = FALSE;
		available_texture_formats[number_available_texture_formats].bpp_palette = 0;

		for ( r=0, m=format->dwRBitMask; !(m & 1); r++, m >>= 1)
				;
		
		for ( r=0; m & 1; r++, m >>= 1)
				;
		
		for ( g=0, m=format->dwGBitMask; !(m & 1); g++, m >>= 1)
				;
		
		for ( g=0; m & 1; g++, m >>= 1)
				;
		
		for ( b=0, m=format->dwBBitMask; !(m & 1); b++, m >>= 1)
				;
		
		for ( b=0; m & 1; b++, m >>= 1)
				;

		a = 0;

		if ( format->dwRGBAlphaBitMask )
		{

			for ( a=0, m=format->dwRGBAlphaBitMask; !(m & 1); a++, m >>= 1)
					;
	
			for ( a=0; m & 1; a++, m >>= 1)
					;
		}
		
		available_texture_formats[number_available_texture_formats].bpp_red = r;
		available_texture_formats[number_available_texture_formats].bpp_green = g;
		available_texture_formats[number_available_texture_formats].bpp_blue = b;
		available_texture_formats[number_available_texture_formats].bpp_alpha = a;
		available_texture_formats[number_available_texture_formats].bpp_colour = r + g + b;

		if ( ( r + g + b + a ) <= 16 )
		{

			number_available_texture_formats ++;
		}
		else
		{

			if ( d3d_allow_32bit_textures )
			{
	
				number_available_texture_formats ++;
			}
		}

		return ( DDENUMRET_OK );
	}
	else
	{

		debug_log ( "Got a wierd texture format that Im not quite sure about! - debug me!" );

		return ( DDENUMRET_OK );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void release_all_textures ( void )
{

	HRESULT
		ddrval;

	//
	// First, the hardware textures
	//

	free_all_hardware_textures ();

	//
	// Now release the hardware colour palette
	//

	if ( hardware_texture_palette )
	{

		ddrval = IDirectDrawPalette_Release ( hardware_texture_palette );

		if ( ddrval < DD_OK )
		{

			debug_log ( "Unable to release the hardware palette: %s", get_ddraw_error_message ( ddrval ) );
		}
		else if ( ddrval > DD_OK )
		{

			debug_log ( "Unable to release hardware palette: references: %d", ddrval );
		}
		else
		{

			debug_log ( "Released hardware texture palette" );
		}

		hardware_texture_palette = NULL;
	}

	//
	// Finally, get rid of any system textures
	//

	release_system_textures ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void free_all_hardware_textures ( void )
{

	HRESULT
		ret;

	//
	// Free the hardware textures
	//

	if ( d3d.d3d )
	{

		if ( d3d_use_evict_textures )
		{

			//
			// Evict any video / agp memory textures
			//

			ret = IDirect3D7_EvictManagedTextures ( d3d.d3d );
	
			if ( FAILED ( ret ) )
			{
	
				debug_log ( "Unable to evict managed textures: %s", get_ddraw_error_message ( ret ) );
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL lock_texture ( screen *texture, int mipmap_level )
{

	int
		count;

	LPDIRECTDRAWSURFACEX
		texture_surface,
		next_level;

	HRESULT
		ddrval;

	DDSURFACEDESC2
		ddsd;

	ASSERT ( ddraw.ddraw );
	ASSERT ( texture );
	ASSERT ( texture->surface );
	ASSERT ( !texture->locked );

	texture_surface = texture->surface;

	for ( count = 0; count < mipmap_level; count++ )
	{

		DDSCAPS2
			ddscaps;

		memset ( &ddscaps, 0, sizeof ( ddscaps ) );

		ddscaps.dwCaps = DDSCAPS_TEXTURE | DDSCAPS_MIPMAP;

		ddrval = IDirectDrawSurface7_GetAttachedSurface ( texture_surface, &ddscaps, &next_level );

		if ( ddrval != DD_OK )
		{

			debug_log ( "Failed to get attached surface: %s", get_ddraw_error_message ( ddrval ) );

			memset ( &ddsd, 0, sizeof ( ddsd ) );

			ddsd.dwSize = sizeof ( ddsd );

			ddrval = IDirectDrawSurface7_GetSurfaceDesc ( texture_surface, &ddsd );

			if ( ddrval != DD_OK )
			{

				debug_log ( "Failed to get surface description: %s", get_ddraw_error_message ( ddrval ) );
			}
		
			debug_log ( "Failed to find mipmap %d, from %d levels: %s", count, ddsd.dwMipMapCount, get_ddraw_error_message ( ddrval ) );

			return ( FALSE );
		}

		if ( texture_surface != texture->surface )
		{

			IDirectDrawSurface7_Release ( texture_surface );
		}

		texture_surface = next_level;
	}


	ddsd.dwSize = sizeof ( ddsd );

	ddrval = IDirectDrawSurface7_GetSurfaceDesc ( texture_surface, &ddsd );

	if ( ddrval != DD_OK )
	{

		debug_log ( "Failed to get surface description of texture: %s", get_ddraw_error_message ( ddrval ) );

		return ( FALSE );
	}

	ddrval = IDirectDrawSurface7_Lock ( texture_surface, NULL, &ddsd, DDLOCK_WAIT | DDLOCK_SURFACEMEMORYPTR, NULL );
		
	if ( ddrval != DD_OK )
	{

		debug_log ( "failed to lock texture: %s", get_ddraw_error_message ( ddrval ) );

		return ( FALSE );
	}

	texture->surface_locked = texture_surface;

	texture->locked = TRUE;

	texture->data = ddsd.lpSurface;

	texture->pitch = ddsd.lPitch;

	return ( TRUE );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL unlock_texture ( screen *texture )
{

	HRESULT
		ddrval;

	ASSERT ( ddraw.ddraw );
	ASSERT ( texture );
	ASSERT ( texture->surface );
	ASSERT ( texture->surface_locked );
	ASSERT ( texture->locked );
	ASSERT ( texture->data );

	ddrval = IDirectDrawSurface7_Unlock ( texture->surface_locked, texture->data );
		
	if ( ddrval != DD_OK )
	{

		debug_log ( "Unable to unlock texture: %s", get_ddraw_error_message ( ddrval ) );

		return ( FALSE );
	}

	if ( texture->surface_locked != texture->surface )
	{

		IDirectDrawSurface7_Release ( texture->surface_locked );
	}

	texture->locked = FALSE;

	texture->surface_locked = NULL;

	texture->data = NULL;

	return ( TRUE );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LPDIRECTDRAWSURFACEX load_hardware_texture_map ( screen *texture )
{

	if ( texture )
	{

		return ( texture->surface );
	}
	else
	{

		return ( NULL );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void report_free_texture_memory ( void )
{

	DWORD
		total,
		free;

	DDSCAPS2
		caps;

	memset ( &caps, 0, sizeof ( caps ) );

	caps.dwCaps = DDSCAPS_TEXTURE | DDSCAPS_VIDEOMEMORY | DDSCAPS_LOCALVIDMEM;

	IDirectDraw7_GetAvailableVidMem ( ddraw.ddraw, &caps, &total, &free );

	debug_log ( "Texture memory: %d, Free: %d", total, free );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

