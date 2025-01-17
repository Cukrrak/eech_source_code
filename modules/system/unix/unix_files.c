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

#include "system.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define DEBUG_MODULE 0

#define MAX_NUMBER_FILES 1024

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct FILEMAP
{

	int
		used;

#if DEBUG_MODULE

	char
		filename[256];

#endif

	int
		fd;

	long
		length;

	void
		*data;
};

typedef struct FILEMAP filemap;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static filemap
	*file_maps;

static int
	safe_memory_mapped_file_counter = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void deinitialise_file_system ( void );

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL initialise_file_system ( void )
{

	int
		count;

	file_maps = safe_malloc ( sizeof ( filemap ) * MAX_NUMBER_FILES );

	for ( count = 0; count < MAX_NUMBER_FILES; count++ )
	{

		file_maps[count].used = FALSE;
		file_maps[count].fd = 0;
		file_maps[count].length = 0;
		file_maps[count].data = NULL;
	}

	register_exit_function ( deinitialise_file_system );

	return ( TRUE );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_file_system ( void )
{

	int
		count;

	for ( count = 0; count < MAX_NUMBER_FILES; count++ )
	{

		if ( file_maps[count].used )
		{

#if DEBUG_MODULE

			debug_log ( "Memory mapped file %s not closed", file_maps[count].filename );

#endif
			mclose ( file_maps[count].data );
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void * mopen ( char *filename )
{
	int
		fd;

	long
		length;

	struct stat filestat;
	
	void
		*data;

	int
		count;

	char
		mapping_name[256];


	for ( count=0; ( ( count<MAX_NUMBER_FILES ) && ( file_maps[count].used ) ); count++ )
	{
	}

	if ( count == MAX_NUMBER_FILES )
	{

		debug_log ( "Unable to create a file mapping - maximum files already mapped" );

		return ( NULL );
	}
	else
	{

		fd = open ( filename, O_RDONLY );

		if ( !fd )
		{
			debug_log ( "Unable to open file %s prior to mmap: %s", filename, strerror(errno) );

			return ( NULL );
		}

		sprintf ( mapping_name, "%08x%04dFileMapping", SDL_GetTicks (), count );

		// set length to size of file
		fstat( fd, &filestat );
		length = filestat.st_size;

		data = mmap(0, length, PROT_READ, MAP_SHARED, fd, 0);
		if ( ! data )
		{

			close(fd);

			debug_log ( "Unable to create file mapping for memory mapped file %s: %s", filename, strerror(errno) );

			return ( NULL );
		}

		file_maps[count].fd = fd;
		file_maps[count].length = length;
		file_maps[count].data = data;

#if DEBUG_MODULE

		strcpy ( file_maps[count].filename, filename );

#endif

		file_maps[count].used = TRUE;

		return ( data );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL mclose ( void *data )
{

	int
		count;

	for ( count=0; ( ( count<MAX_NUMBER_FILES ) && ( file_maps[count].data != data ) ); count++ )
	{
	}

	if ( count == MAX_NUMBER_FILES )
	{

		debug_log ( "Unable to locate memory mapped file to unmap file." );

		return ( FALSE );
	}

	munmap( file_maps[count].data, file_maps[count].length );

	close( file_maps[count].fd );


	file_maps[count].used = FALSE;
	file_maps[count].fd = 0;
	file_maps[count].length = 0;
	file_maps[count].data = NULL;

	return ( TRUE );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// JB 030311 Enable running out of separate directories
//FIXME: Not implemented yet. Defined in aphavoc/source/project.c!!!
//extern char comanche_hokum_installation_path[];
char comanche_hokum_installation_path[1024];

int file_exist (char *filename)
{
	char fn[1024];

	FILE
		*file_ptr;

	if (file_ptr = fopen (filename, "r"))
	{

		fclose (file_ptr);

		return TRUE;
	}

	// JB 030311 Enable running out of separate directories
	fn[0] = 0;
	strcpy(fn, comanche_hokum_installation_path);
	strcat(fn, "\\cohokum\\");
	strcat(fn, filename);

	if (file_ptr = fopen (fn, "r"))
	{
		fclose (file_ptr);

		return TRUE;
	}

	fn[0] = 0;
	strcpy(fn, comanche_hokum_installation_path);
	strcat(fn, "\\common\\");
	strcat(fn, filename);

	if (file_ptr = fopen (fn, "r"))
	{
		fclose (file_ptr);

		return TRUE;
	}

	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int file_size ( char *filename )
{
	char fn[1024];

	FILE
		*fp;

	int
		size;

	size = 0;

	if ( fp = fopen ( filename, "r" ) )
	{

		fseek ( fp, 0, SEEK_END );

		size = ftell ( fp );

		fclose ( fp );
		return ( size );
	}

	// JB 030311 Enable running out of separate directories
	fn[0] = 0;
	strcpy(fn, comanche_hokum_installation_path);
	strcat(fn, "\\cohokum\\");
	strcat(fn, filename);

	if ( fp = fopen ( fn, "r" ) )
	{

		fseek ( fp, 0, SEEK_END );

		size = ftell ( fp );

		fclose ( fp );
		return ( size );
	}

	fn[0] = 0;
	strcpy(fn, comanche_hokum_installation_path);
	strcat(fn, "\\common\\");
	strcat(fn, filename);

	if ( fp = fopen ( fn, "r" ) )
	{

		fseek ( fp, 0, SEEK_END );

		size = ftell ( fp );

		fclose ( fp );
		return ( size );
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void reset_safe_memory_mapped_file_counter (void)
{
//	debug_log ("NOTE! Safe memory mapped file counter reset");

	safe_memory_mapped_file_counter = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void check_safe_memory_mapped_file_counter (void)
{
	if (safe_memory_mapped_file_counter == 0)
	{
		debug_log ("NOTE! Safe memory mapped file counter == 0");
	}
	else
	{
		debug_log ("WARNING! Safe memory mapped file counter != 0 (counter = %d)", safe_memory_mapped_file_counter);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// JB 030311 Enable running out of separate directories
extern char comanche_hokum_installation_path[];

void *safe_mopen (char *filename)
{
	void
		*ptr;

	ASSERT (filename);

	ptr = mopen (filename);

	// JB 030311 Enable running out of separate directories
	if (!ptr)
	{
		char fn[1024];
		fn[0] = 0;
		strcpy(fn, comanche_hokum_installation_path);
		strcat(fn, "\\cohokum\\");
		strcat(fn, filename);

		ptr = mopen (fn);

		if ( !ptr )
		{
			fn[0] = 0;
			strcpy(fn, comanche_hokum_installation_path);
			strcat(fn, "\\common\\");
			strcat(fn, filename);

			ptr = mopen (fn);

			if ( !ptr )
			{

				if ( file_exist ( fn ) )
				{
			
					debug_fatal ( "Unable to map file %s\n\nThis may be due to lack of virtual memory", fn );
				}
				else
				{

					debug_fatal ( "Unable to load file %s", fn );
				}
			}
		}
	}

	safe_memory_mapped_file_counter++;

	return (ptr);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL safe_mclose (void *data)
{
	BOOL
		result;

	ASSERT (data);

	result = mclose (data);

	ASSERT (result);

	safe_memory_mapped_file_counter--;

	return (result);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

FILE *safe_fopen( char *filename, char *mode )
{
	FILE
		*fp;

	ASSERT (filename);

	ASSERT (mode);

	fp = fopen( filename, mode );

	// JB 030311 Enable running out of separate directories
	if (!fp)
	{
		char fn[1024];
		fn[0] = 0;
		strcpy(fn, comanche_hokum_installation_path);
		strcat(fn, "\\cohokum\\");
		strcat(fn, filename);

		fp = fopen( fn, mode );

		if ( !fp )
		{
			fn[0] = 0;
			strcpy(fn, comanche_hokum_installation_path);
			strcat(fn, "\\common\\");
			strcat(fn, filename);

			fp = fopen( fn, mode );

			if ( !fp )
			{

				if ( ( *mode == 'r' ) || ( *mode == 'R' ) )
				{
			
					debug_fatal("Error opening file for reading: %s", fn );
				}
				else if ( ( *mode == 'w' ) || ( *mode == 'W' ) )
				{
			
					debug_fatal("Error opening file for writing: %s", fn );
				}
				else
				{
			
					debug_fatal("Error opening file %s", fn );
				}
			}
		}
	}

	return fp;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int safe_fclose (FILE *fp)
{
	int
		error;

	ASSERT (fp);

	error = fclose (fp);

	if (error)
	{
		debug_fatal ("Error closing file (error = %d)", error);
	}

	return (error);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void safe_fread ( void *data, int element_size, int number_of_elements, FILE *fp )
{

	size_t
		size_read;

	size_read = fread ( data, element_size, number_of_elements, fp );

	if ( feof ( fp ) )
	{

		debug_fatal ( "Read past end of file" );
	}

	if ( ferror ( fp ) )
	{

		debug_fatal ( "Error reading file" );
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

