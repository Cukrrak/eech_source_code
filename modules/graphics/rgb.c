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

#include "misc.h"

#include "3d.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void blit_rgb_graphic (unsigned char *rgb_graphic, const int x, const int y)
{
	int
		screen_pitch,
		width,
		height;

	unsigned char
		*screen_data,
		*rd,
		*wt;

	ASSERT (rgb_graphic);

	screen_pitch = get_screen_pitch (active_screen);

	screen_data = get_screen_data (active_screen);

	rd = rgb_graphic;

	width = get_list_item (rd, unsigned short int) * sizeof (rgb_packed);

	height = get_list_item (rd, unsigned short int);

	wt = screen_data + (x * sizeof (rgb_packed)) + (y * screen_pitch);

	while (height--)
	{
		memcpy (wt, rd, width);

		rd += width;
		wt += screen_pitch;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void blit_rgb_clipped_graphic (unsigned char *rgb_graphic, int x, int y)
{
	int
		screen_pitch,
		graphic_pitch,
		width,
		height;

	unsigned char
		*screen_data,
		*rd,
		*wt;

	ASSERT (rgb_graphic);

	screen_pitch = get_screen_pitch (active_screen);

	screen_data = get_screen_data (active_screen);

	rd = rgb_graphic;

	graphic_pitch = get_list_item (rd, unsigned short int);

	height = get_list_item (rd, unsigned short int);

	//
	// Clip to max screen extents
	//

	width = min (graphic_pitch, get_screen_width (active_screen) - x);

	height = min (height, get_screen_height (active_screen) - y);

	//
	// Clip to min screen extents
	//

	if (y < 0)
	{

		rd += (0 - y) * graphic_pitch * sizeof (rgb_packed);

		height -= (0 - y);

		y = 0;
	}

	if (x < 0)
	{

		rd += (0 - x) * sizeof (rgb_packed);

		width -= (0 - x);

		x = 0;
	}

	//
	// Early out
	//

	if (height <= 0)
	{

		return;
	}

	if (width <= 0)
	{

		return;
	}

	//
	// Scale into rgb_packed
	//

	graphic_pitch *= sizeof (rgb_packed);

	width *= sizeof (rgb_packed);

	//
	// Blit
	//

	wt = screen_data + (x * sizeof (rgb_packed)) + (y * screen_pitch);

	while (height--)
	{
		memcpy (wt, rd, width);

		rd += graphic_pitch;
		wt += screen_pitch;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void blit_rgb_centralised_clipped_graphic (unsigned char *rgb_graphic, int x, int y)
{
	int
		screen_pitch,
		graphic_pitch,
		width,
		height;

	unsigned char
		*screen_data,
		*rd,
		*wt;

	ASSERT (rgb_graphic);

	screen_pitch = get_screen_pitch (active_screen);

	screen_data = get_screen_data (active_screen);

	rd = rgb_graphic;

	graphic_pitch = get_list_item (rd, unsigned short int);

	height = get_list_item (rd, unsigned short int);

	//
	// Centralise
	//

	x -= graphic_pitch >> 1;

	y -= height >> 1;

	//
	// Clip to max screen extents
	//

	width = min (graphic_pitch, get_screen_width (active_screen) - x);

	height = min (height, get_screen_height (active_screen) - y);

	//
	// Clip to min screen extents
	//

	if (y < 0)
	{

		rd += (0 - y) * graphic_pitch * sizeof (rgb_packed);

		height -= (0 - y);

		y = 0;
	}

	if (x < 0)
	{

		rd += (0 - x) * sizeof (rgb_packed);

		width -= (0 - x);

		x = 0;
	}

	//
	// Early out
	//

	if (height <= 0)
	{

		return;
	}

	if (width <= 0)
	{

		return;
	}

	//
	// Scale into rgb_packed
	//

	graphic_pitch *= sizeof (rgb_packed);

	width *= sizeof (rgb_packed);

	//
	// Blit
	//

	wt = screen_data + (x * sizeof (rgb_packed)) + (y * screen_pitch);

	while (height--)
	{
		memcpy (wt, rd, width);

		rd += graphic_pitch;
		wt += screen_pitch;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void blit_rgb_alpha_centralised_clipped_graphic (unsigned char *rgb_graphic, unsigned char *alpha, int alpha_value, int x, int y)
{
	int
		screen_pitch,
		graphic_pitch,
		alpha_pitch,
		width,
		height;

	unsigned char
		*screen_data,
		*rd,
		*rda,
		*wt;

	ASSERT (rgb_graphic);

	screen_pitch = get_screen_pitch (active_screen);

	screen_data = get_screen_data (active_screen);

	rd = rgb_graphic;

	rda = alpha;

	graphic_pitch = get_list_item (rd, unsigned short int);

	alpha_pitch = graphic_pitch;

	height = get_list_item (rd, unsigned short int);

	//
	// Centralise
	//

	x -= graphic_pitch >> 1;
	y -= height >> 1;

	//
	// Clip to max screen extents
	//

	width = min (graphic_pitch, get_screen_width (active_screen) - x);
	height = min (height, get_screen_height (active_screen) - y);

	//
	// Clip to min screen extents
	//

	if (y < 0)
	{

		rd += (0 - y) * graphic_pitch * sizeof (rgb_packed);
		rda += (0 - y) * alpha_pitch * sizeof (unsigned char);
		height -= (0 - y);
		y = 0;
	}

	if (x < 0)
	{
		rd += (0 - x) * sizeof (rgb_packed);
		rda += (0 - x) * sizeof (unsigned char);
		width -= (0 - x);
		x = 0;
	}

	//
	// Early out
	//

	if (height <= 0)
		return;

	if (width <= 0)
		return;

	//
	// Scale into rgb_packed
	//

	graphic_pitch *= sizeof (rgb_packed);

	//
	// Blit
	//

	wt = screen_data + (x * sizeof (rgb_packed)) + (y * screen_pitch);

	while ( height-- )
	{

		int
			loop;

		unsigned short int
			*read,
			*write;

		read = ( unsigned short int * ) rd;
		write = ( unsigned short int * ) wt;

		for ( loop = 0; loop < width; loop++ )
		{

			if ( rda[loop] != alpha_value )
			{

				write[loop] = read[loop];
			}
		}

		rda += alpha_pitch;
		rd += graphic_pitch;
		wt += screen_pitch;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void blit_rgb_alpha_masked_sprite (unsigned char *rgb_data, unsigned char *mask_data, rgb_alpha_masked_sprite_data *sprite_data)
{
	int
		screen_pitch,
		rgb_width,
		rgb_height,
		rgb_add_on,
		mask_width,
		mask_height,
		mask_add_on,
		screen_add_on,
		u_loop,
		v_loop;

	unsigned char
		*screen_data,
		mask_value;

	ASSERT (rgb_data);

	ASSERT (mask_data);

	ASSERT (sprite_data);

	screen_pitch = get_screen_pitch (active_screen);

	screen_data = get_screen_data (active_screen);

	//
	// rgb data
	//

	rgb_width = get_list_item (rgb_data, unsigned short int) * sizeof (rgb_packed);

	rgb_height = get_list_item (rgb_data, unsigned short int);

	rgb_add_on = rgb_width - (sprite_data->width * sizeof (rgb_packed));

	rgb_data += (sprite_data->u * sizeof (rgb_packed)) + (sprite_data->v * rgb_width);

	//
	// mask data
	//

	mask_width = get_list_item (mask_data, unsigned short int);

	mask_height = get_list_item (mask_data, unsigned short int);

	mask_add_on = mask_width - sprite_data->width;

	mask_data += sprite_data->u + (sprite_data->v * mask_width);

	mask_value = sprite_data->mask_value;

	//
	// screen
	//

	screen_add_on = screen_pitch - (sprite_data->width * sizeof (rgb_packed));

	screen_data += (sprite_data->x * sizeof (rgb_packed)) + (sprite_data->y * screen_pitch);

	//
	// blit sprite
	//

	for (v_loop = sprite_data->height; v_loop > 0; v_loop--)
	{
		for (u_loop = sprite_data->width; u_loop > 0; u_loop--)
		{
			if (*mask_data == mask_value)
			{
				*(rgb_packed *)screen_data = *(rgb_packed *)rgb_data;
			}

			rgb_data += sizeof (rgb_packed);

			mask_data++;

			screen_data += sizeof (rgb_packed);
		}

		rgb_data += rgb_add_on;

		mask_data += mask_add_on;

		screen_data += screen_add_on;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void blit_rgb_alpha_masked_sprite_zero_mask_value (unsigned char *rgb_data, unsigned char *mask_data, rgb_alpha_masked_sprite_data *sprite_data)
{
	int
		screen_pitch,
		rgb_width,
		rgb_height,
		rgb_add_on,
		mask_width,
		mask_height,
		mask_add_on,
		screen_add_on,
		u_loop,
		v_loop;

	unsigned char
		*screen_data,
		mask_value;

	ASSERT (rgb_data);

	ASSERT (mask_data);

	ASSERT (sprite_data);

	screen_pitch = get_screen_pitch (active_screen);

	screen_data = get_screen_data (active_screen);

	//
	// rgb data
	//

	rgb_width = get_list_item (rgb_data, unsigned short int) * sizeof (rgb_packed);

	rgb_height = get_list_item (rgb_data, unsigned short int);

	rgb_add_on = rgb_width - (sprite_data->width * sizeof (rgb_packed));

	rgb_data += (sprite_data->u * sizeof (rgb_packed)) + (sprite_data->v * rgb_width);

	//
	// mask data
	//

	mask_width = get_list_item (mask_data, unsigned short int);

	mask_height = get_list_item (mask_data, unsigned short int);

	mask_add_on = mask_width - sprite_data->width;

	mask_data += sprite_data->u + (sprite_data->v * mask_width);

	mask_value = sprite_data->mask_value;

	//
	// screen
	//

	screen_add_on = screen_pitch - (sprite_data->width * sizeof (rgb_packed));

	screen_data += (sprite_data->x * sizeof (rgb_packed)) + (sprite_data->y * screen_pitch);

	//
	// blit sprite
	//

	for (v_loop = sprite_data->height; v_loop > 0; v_loop--)
	{
		for (u_loop = sprite_data->width; u_loop > 0; u_loop--)
		{
			if (*mask_data)
			{
				*(rgb_packed *)screen_data = *(rgb_packed *)rgb_data;
			}

			rgb_data += sizeof (rgb_packed);

			mask_data++;

			screen_data += sizeof (rgb_packed);
		}

		rgb_data += rgb_add_on;

		mask_data += mask_add_on;

		screen_data += screen_add_on;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void blit_rgb_alpha_masked_sprite_zero_mask_value_onto_texture (unsigned char *rgb_data, unsigned char *mask_data, rgb_alpha_masked_sprite_data *sprite_data, screen *user_screen)
{
	int
		screen_pitch,
		rgb_width,
		rgb_height,
		rgb_add_on,
		mask_width,
		mask_height,
		mask_add_on,
		screen_add_on,
		u_loop,
		v_loop;

	unsigned char
		*screen_data,
		mask_value;

	rgb_colour
		col;

	ASSERT (rgb_data);

	ASSERT (mask_data);

	ASSERT (sprite_data);

	ASSERT (user_screen);

	set_user_screen_pixel_format (user_screen);

	screen_pitch = get_screen_pitch (active_screen);

	screen_data = get_screen_data (active_screen);

	//
	// rgb data
	//

	rgb_width = get_list_item (rgb_data, unsigned short int) * sizeof (rgb_packed);

	rgb_height = get_list_item (rgb_data, unsigned short int);

	rgb_add_on = rgb_width - (sprite_data->width * sizeof (rgb_packed));

	rgb_data += (sprite_data->u * sizeof (rgb_packed)) + (sprite_data->v * rgb_width);

	//
	// mask data
	//

	mask_width = get_list_item (mask_data, unsigned short int);

	mask_height = get_list_item (mask_data, unsigned short int);

	mask_add_on = mask_width - sprite_data->width;

	mask_data += sprite_data->u + (sprite_data->v * mask_width);

	mask_value = sprite_data->mask_value;

	//
	// screen
	//

	screen_add_on = screen_pitch - (sprite_data->width * sizeof (rgb_packed));

	screen_data += (sprite_data->x * sizeof (rgb_packed)) + (sprite_data->y * screen_pitch);

	//
	// blit sprite
	//

	for (v_loop = sprite_data->height; v_loop > 0; v_loop--)
	{
		for (u_loop = sprite_data->width; u_loop > 0; u_loop--)
		{
			if (*mask_data)
			{
				col = get_user_rgb_colour_value (*(rgb_packed *)rgb_data);

				col.a = 255;

				*(rgb_packed *)screen_data = get_rgb_packed_value (col);
			}

			rgb_data += sizeof (rgb_packed);

			mask_data++;

			screen_data += sizeof (rgb_packed);
		}

		rgb_data += rgb_add_on;

		mask_data += mask_add_on;

		screen_data += screen_add_on;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void convert_tga_to_rgb (char *tga_filename, char *rgb_filename)
{

	FILE
		*rgb_file_ptr;

	rgb_colour
		colour;

	unsigned char
		*image;

	short int
		width,
		height;

	int
		x_loop,
		y_loop,
		bits_per_pixel;

	unsigned char
		*destination_image;

	rgb_packed
		*destination_ptr;

	if ((rgb_file_ptr = fopen (rgb_filename, "wb")) == NULL)
	{

		debug_fatal ( "Unable to open file %s during convert_tga_to_rgb", rgb_filename );
	}

	//
	// load tga file
	//

	image = load_tga_file (tga_filename, &width, &height, &bits_per_pixel);

	//
	// Allocate space for the destination image
	//

	destination_image = safe_malloc ( width * height * sizeof ( rgb_packed ) );

	ASSERT ( destination_image );

	destination_ptr = ( rgb_packed * ) destination_image;

	//
	// Convert the rgb to packed_rgb format
	//

	colour.a = 255;

	if (bits_per_pixel == 24)
	{

		tga_rgb
			*this_pixel,
			*image_data;

		image_data = (tga_rgb *) image;

		for (y_loop = (height - 1); y_loop >= 0; y_loop --)
		{

			this_pixel = image_data + (width * y_loop);

			for (x_loop = 0; x_loop < width; x_loop ++)
			{

				colour.b = this_pixel->b;

				colour.g = this_pixel->g;

				colour.r = this_pixel->r;

				*destination_ptr++ = get_rgb_packed_value (colour);

				this_pixel ++;
			}
		}
	}
	else if (bits_per_pixel == 32)
	{

		tga_rgba
			*this_pixel,
			*image_data;

		image_data = (tga_rgba *) image;

		for (y_loop = (height - 1); y_loop >= 0; y_loop --)
		{

			this_pixel = image_data + (width * y_loop);

			for (x_loop = 0; x_loop < width; x_loop ++)
			{

				colour.b = this_pixel->b;

				colour.g = this_pixel->g;

				colour.r = this_pixel->r;

				*destination_ptr++ = get_rgb_packed_value (colour);

				this_pixel ++;
			}
		}
	}
	else
	{
		debug_fatal ( "%s must have either 24 or 32 bits/pixel for convert_tga_to_rgb", tga_filename);
	}

	//
	// manually write out header (x, y sizes)
	//

	fwrite (&width, sizeof (width), 1, rgb_file_ptr);

	fwrite (&height, sizeof (height), 1, rgb_file_ptr);

	//
	// write out image
	//

	fwrite ( destination_image, width * sizeof ( rgb_packed ), height, rgb_file_ptr );

	fclose (rgb_file_ptr);

	safe_free ( destination_image );

	safe_free (image);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void convert_tga_to_rgb_alpha (char *tga_filename, char *rgb_alpha_filename)
{

	FILE
		*rgb_alpha_file_ptr;

	rgb_colour
		colour;

	unsigned char
		*alpha;

	tga_rgba
		*this_pixel,
		*image_data;

	short int
		width,
		height;

	rgb_packed
		value;

	int
		x_loop,
		y_loop,
		bits_per_pixel;

	if ((rgb_alpha_file_ptr = fopen (rgb_alpha_filename, "wb")) == NULL)
	{

		debug_fatal ( "Unable to open file %s during convert_tga_to_rgb_alpha", rgb_alpha_filename );
	}

	//
	// load tga file
	//

	image_data = load_tga_file (tga_filename, &width, &height, &bits_per_pixel);

	if (bits_per_pixel != 32)
	{

		debug_fatal ( "%s must have 32 bits/pixel for convert_tga_to_rgb_alpha", tga_filename);
	}

	//
	// malloc memory for alpha data
	//

	alpha = (char *) safe_malloc (sizeof (char) * width * height);

	//
	// write image out as rgb file format
	//

	// manually write out header (x, y sizes)

	fwrite (&width, sizeof (width), 1, rgb_alpha_file_ptr);

	fwrite (&height, sizeof (height), 1, rgb_alpha_file_ptr);

	// write out image

	for (y_loop = 0; y_loop < height; y_loop ++)
	{

		this_pixel = image_data + (width * (height - 1 - y_loop));

		for (x_loop = 0; x_loop < width; x_loop ++)
		{

			colour.b = this_pixel->b;

			colour.g = this_pixel->g;

			colour.r = this_pixel->r;

			colour.a = this_pixel->a;

			value = get_rgb_packed_value (colour);

			alpha [(y_loop * width) + x_loop] = colour.a;

			fwrite (&value, sizeof (value), 1, rgb_alpha_file_ptr);

			this_pixel ++;
		}
	}

	fwrite (alpha, sizeof (char) * width * height, 1, rgb_alpha_file_ptr);

	fclose (rgb_alpha_file_ptr);

	safe_free (alpha);

	safe_free (image_data);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void convert_tga_to_alpha_mask (char *tga_filename, char *alpha_mask_filename)
{
	FILE
		*fp;

	tga_rgba
		*image_data,
		*this_pixel;

	short int
		width,
		height;

	int
		x_loop,
		y_loop,
		bits_per_pixel;

	if ((fp = fopen (alpha_mask_filename, "wb")) == NULL)
	{
		debug_fatal ("Unable to open file %s during convert_tga_to_alpha_mask", alpha_mask_filename);
	}

	image_data = load_tga_file (tga_filename, &width, &height, &bits_per_pixel);

	if (bits_per_pixel != 32)
	{
		debug_fatal ( "%s must have 32 bits/pixel for convert_tga_to_alpha_mask", tga_filename);
	}

	fwrite (&width, sizeof (width), 1, fp);

	fwrite (&height, sizeof (height), 1, fp);

	for (y_loop = (height - 1); y_loop >= 0; y_loop--)
	{
		this_pixel = image_data + (width * y_loop);

		for (x_loop = 0; x_loop < width; x_loop++)
		{
			fwrite (&this_pixel->a, sizeof (unsigned char), 1, fp);

			this_pixel++;
		}
	}

	fclose (fp);

	safe_free (image_data);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void convert_psd_to_rgb (char *psd_filename, char *rgb_filename)
{

	FILE
		*rgb_file_ptr;

	rgb_colour
		colour;

	unsigned char
		*image;

	unsigned short int
		short_width,
		short_height;

	int
		width,
		height,
		x_loop,
		y_loop,
		number_of_channels;

	unsigned char
		*destination_image;

	rgb_packed
		*destination_ptr;

	//
	// load psd file
	//

	image = load_psd_file (psd_filename, &width, &height, &number_of_channels);

	//
	// Open the destination file
	//

	if ((rgb_file_ptr = fopen (rgb_filename, "wb")) == NULL)
	{

		debug_fatal ( "Unable to open file %s during convert_psd_to_rgb", rgb_filename );
	}

	//
	// Allocate space for the destination image
	//

	destination_image = safe_malloc ( width * height * sizeof ( rgb_packed ) );

	ASSERT ( destination_image );

	destination_ptr = ( rgb_packed * ) destination_image;

	//
	// Convert the rgb to packed_rgb format
	//

	colour.a = 0;

	if (number_of_channels == 3)
	{

		psd_rgb
			*this_pixel,
			*image_data;

		image_data = (psd_rgb *) image;

		for (y_loop = 0; y_loop < height; y_loop++)
		{

			this_pixel = image_data + (width * y_loop);

			for (x_loop = 0; x_loop < width; x_loop ++)
			{

				colour.b = this_pixel->b;

				colour.g = this_pixel->g;

				colour.r = this_pixel->r;

				*destination_ptr++ = get_rgb_packed_value (colour);

				this_pixel ++;
			}
		}
	}
	else if (number_of_channels == 4)
	{

		psd_rgba
			*this_pixel,
			*image_data;

		image_data = (psd_rgba *) image;

		for (y_loop = 0; y_loop < height; y_loop++)
		{

			this_pixel = image_data + (width * y_loop);

			for (x_loop = 0; x_loop < width; x_loop ++)
			{

				colour.b = this_pixel->b;

				colour.g = this_pixel->g;

				colour.r = this_pixel->r;

				*destination_ptr++ = get_rgb_packed_value (colour);

				this_pixel ++;
			}
		}
	}
	else
	{
		debug_fatal ( "%s must have either 3 or 4 channels/pixel for convert_psd_to_rgb", psd_filename);
	}

	//
	// manually write out header (x, y sizes)
	//

	short_width = width;

	short_height = height;

	fwrite (&short_width, sizeof (short_width), 1, rgb_file_ptr);

	fwrite (&short_height, sizeof (short_height), 1, rgb_file_ptr);

	//
	// write out image
	//

	fwrite ( destination_image, width * sizeof ( rgb_packed ), height, rgb_file_ptr );

	fclose (rgb_file_ptr);

	safe_free (destination_image);

	safe_free (image);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void convert_psd_to_rgb_alpha (char *psd_filename, char *rgb_alpha_filename)
{

	FILE
		*rgb_alpha_file_ptr;

	rgb_colour
		colour;

	unsigned char
		*alpha;

	psd_rgba
		*this_pixel,
		*image_data;

	unsigned short int
		short_width,
		short_height;

	rgb_packed
		value;

	int
		width,
		height,
		x_loop,
		y_loop,
		number_of_channels;

	//
	// load tga file
	//

	image_data = load_psd_file (psd_filename, &width, &height, &number_of_channels);

	if (number_of_channels != 4)
	{

		debug_fatal ( "%s must have 4 channels/pixel for convert_psd_to_rgb_alpha", psd_filename);
	}

	//
	// Open the destination file
	//

	if ((rgb_alpha_file_ptr = fopen (rgb_alpha_filename, "wb")) == NULL)
	{

		debug_fatal ( "Unable to open file %s during convert_psd_to_rgb_alpha", rgb_alpha_filename );
	}

	//
	// malloc memory for alpha data
	//

	alpha = (char *) safe_malloc (sizeof (char) * width * height);

	//
	// write image out as rgb file format
	//

	// manually write out header (x, y sizes)

	short_width = width;

	short_height = height;

	fwrite (&short_width, sizeof (short_width), 1, rgb_alpha_file_ptr);

	fwrite (&short_height, sizeof (short_height), 1, rgb_alpha_file_ptr);

	// write out image

	for (y_loop = 0; y_loop < height; y_loop ++)
	{

		this_pixel = image_data + (width * y_loop);

		for (x_loop = 0; x_loop < width; x_loop ++)
		{

			colour.b = this_pixel->b;

			colour.g = this_pixel->g;

			colour.r = this_pixel->r;

			colour.a = this_pixel->a;

			value = get_rgb_packed_value (colour);

			alpha [(y_loop * width) + x_loop] = colour.a;

			fwrite (&value, sizeof (value), 1, rgb_alpha_file_ptr);

			this_pixel ++;
		}
	}

	fwrite (alpha, sizeof (char) * width * height, 1, rgb_alpha_file_ptr);

	fclose (rgb_alpha_file_ptr);

	safe_free (alpha);

	safe_free (image_data);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void convert_psd_to_alpha_mask (char *psd_filename, char *alpha_mask_filename)
{
	FILE
		*fp;

	psd_rgba
		*image_data,
		*this_pixel;

	unsigned short int
		short_width,
		short_height;

	int
		width,
		height,
		x_loop,
		y_loop,
		number_of_channels;

	image_data = load_psd_file (psd_filename, &width, &height, &number_of_channels);

	if (number_of_channels != 4)
	{
		debug_fatal ( "%s must have 4 channels/pixel for convert_psd_to_alpha_mask", psd_filename);
	}

	//
	// Open the destination file
	//

	if ((fp = fopen (alpha_mask_filename, "wb")) == NULL)
	{
		debug_fatal ("Unable to open file %s during convert_psd_to_alpha_mask", alpha_mask_filename);
	}

	short_width = width;

	short_height = height;

	fwrite (&short_width, sizeof (short_width), 1, fp);

	fwrite (&short_height, sizeof (short_height), 1, fp);

	for (y_loop = 0; y_loop < height; y_loop++)
	{
		this_pixel = image_data + (width * y_loop);

		for (x_loop = 0; x_loop < width; x_loop++)
		{
			fwrite (&this_pixel->a, sizeof (unsigned char), 1, fp);

			this_pixel++;
		}
	}

	fclose (fp);

	safe_free (image_data);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void convert_and_dither_psd_to_rgb ( char *psd_filename, char *rgb_filename )
{

	FILE
		*rgb_file_ptr;

	unsigned char
		*image;

	unsigned short int
		short_width,
		short_height;

	int
		width,
		height,
		number_of_channels;

	unsigned char
		*destination_image;

	//
	// load psd file
	//

	image = load_psd_file ( psd_filename, &width, &height, &number_of_channels );

	//
	// Open the destination file
	//

	if ( ( rgb_file_ptr = fopen ( rgb_filename, "wb" ) ) == NULL )
	{

		debug_fatal ( "Unable to open file %s during convert_and_dither_psd_to_rgb", rgb_filename );
	}

	//
	// Allocate space for the destination image
	//

	debug_log ( "READ WIDTH %d, HEIGHT %d", width, height );

	destination_image = safe_malloc ( width * height * sizeof ( rgb_packed ) );

	//
	// Convert the rgb to dithered information format
	//

	if ( number_of_channels == 3 )
	{
	
		compute_dithered_rgb_image ( width, height, ( psd_rgb * ) image, ( rgb_packed * ) destination_image );
	}
	else if ( number_of_channels == 4 )
	{

		compute_dithered_rgba_image ( width, height, ( psd_rgba * ) image, ( rgb_packed * ) destination_image );
	}
	else
	{

		debug_fatal ( "%s must have either 3 or 4 channels/pixel for convert_psd_to_rgb", psd_filename);
	}

	//
	// manually write out header (x, y sizes)
	//

	short_width = width;

	short_height = height;

	fwrite ( &short_width, sizeof ( short_width ), 1, rgb_file_ptr );

	fwrite ( &short_height, sizeof ( short_height ), 1, rgb_file_ptr );

	//
	// write out image
	//

	fwrite ( destination_image, width * sizeof ( rgb_packed ), height, rgb_file_ptr );

	fclose ( rgb_file_ptr );

	safe_free ( destination_image );

	safe_free ( image );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void convert_and_dither_psd_to_rgb_alpha ( char *psd_filename, char *rgb_alpha_filename )
{

	FILE
		*rgb_alpha_file_ptr;

	unsigned char
		*destination_alpha,
		*alpha;

	psd_rgba
		*image_data,
		*image_ptr;

	unsigned short int
		short_width,
		short_height;

	rgb_packed
		*destination_image;

	int
		width,
		height,
		x_loop,
		y_loop,
		number_of_channels;

	//
	// Load psd file
	//

	image_data = load_psd_file ( psd_filename, &width, &height, &number_of_channels );

	if ( number_of_channels != 4 )
	{

		debug_fatal ( "%s must have 4 channels/pixel for convert_psd_to_rgb_alpha", psd_filename );
	}

	//
	// Open the destination file
	//

	if ( ( rgb_alpha_file_ptr = fopen ( rgb_alpha_filename, "wb" ) ) == NULL )
	{

		debug_fatal ( "Unable to open file %s during convert_psd_to_rgb_alpha", rgb_alpha_filename );
	}

	//
	// Malloc memory for alpha data
	//

	alpha = safe_malloc ( sizeof ( char ) * width * height );

	//
	// Allocate space for the destination image
	//

	destination_image = safe_malloc ( width * height * sizeof ( unsigned short int ) );

	//
	// Now perform the dithering
	//

	compute_dithered_rgba_image ( width, height, ( psd_rgba * ) image_data, ( rgb_packed * ) destination_image );

	//
	// Now copy the alpha data area
	//

	destination_alpha = alpha;

	image_ptr = image_data;

	for ( y_loop = 0; y_loop < height; y_loop++ )
	{

		for ( x_loop = 0; x_loop < width; x_loop++ )
		{

			*destination_alpha++ = image_ptr->a;

			image_ptr++;
		}
	}

	//
	// Manually write out header (x, y sizes)
	//

	short_width = width;

	short_height = height;

	fwrite ( &short_width, sizeof ( short_width ), 1, rgb_alpha_file_ptr );

	fwrite ( &short_height, sizeof ( short_height ), 1, rgb_alpha_file_ptr );

	//
	// Now write out the rgb data
	//

	fwrite ( destination_image, sizeof ( rgb_packed ), width * height, rgb_alpha_file_ptr );

	//
	// Write out the alpha data.
	//

	fwrite ( alpha, 1, width * height, rgb_alpha_file_ptr );

	fclose ( rgb_alpha_file_ptr );

	safe_free ( alpha );

	safe_free ( image_data );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

