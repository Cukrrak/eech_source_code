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

// Workaround for memory fragmentation issue
#define MFA

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct FILEMAP
{

	int
		used;

#if DEBUG_MODULE

	char
		filename[260];

#endif

#ifdef WIN32
	HANDLE
		hFile,
		hMap;
#else
	int
		fd;

	long
		length;
#endif

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

#ifdef MFA
#ifdef WIN32
// MEMORY1 must be large enough for any TREE_POS.DAT
// MAP3 Georgia 40'998'136 bytes
#define MEMORY1 (40 << 20)

// MEMORY1 must be large enough for any TERRAIN.FFP
// MAP17 Afognak 141'422'414 bytes
#define MEMORY2 (140 << 20)

void
	*memory1,
	*memory2;
int
	memory1_used,
	memory2_used;
#endif
#endif

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

	file_maps = (filemap *) safe_malloc ( sizeof ( filemap ) * MAX_NUMBER_FILES );

	for ( count = 0; count < MAX_NUMBER_FILES; count++ )
	{

		file_maps[count].used = FALSE;
#ifdef WIN32
		file_maps[count].hFile = 0;
		file_maps[count].hMap = 0;
#else
		file_maps[count].fd = 0;
		file_maps[count].length = 0;
#endif
		file_maps[count].data = NULL;
	}

#ifdef MFA
#ifdef WIN32
	memory1 = VirtualAlloc ( NULL, MEMORY1, MEM_COMMIT | MEM_RESERVE | MEM_TOP_DOWN, PAGE_READWRITE );
	if ( !memory1 )
	{
		debug_fatal ( "Failed to allocate %u bytes: 0x%08X", MEMORY1, GetLastError () );
	}
	memory2 = VirtualAlloc ( NULL, MEMORY2, MEM_COMMIT | MEM_RESERVE | MEM_TOP_DOWN, PAGE_READWRITE );
	if ( !memory2 )
	{
		debug_fatal ( "Failed to allocate %u bytes: 0x%08X", MEMORY2, GetLastError () );
	}
#endif
#endif

#ifndef OGRE_EE
	register_exit_function ( deinitialise_file_system );
#endif

	return ( TRUE );
}

#ifndef OGRE_EE
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

#ifdef MFA
#ifdef WIN32
	VirtualFree(memory1, MEMORY1, MEM_RELEASE);
	VirtualFree(memory2, MEMORY2, MEM_RELEASE);
#endif
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif

void * mopen ( const char *filename )
{
#ifdef WIN32
	HANDLE
		hFile,
		hMap;
#else
	int
		fd;

	long
		length;

	struct stat filestat;
#endif

	void
		*data;

	int
		count;

	char
		mapping_name[260];


	for ( count = 0; count < MAX_NUMBER_FILES; count++ )
	{
		if ( !file_maps[count].used )
		{
			break;
		}
	}

	if ( count == MAX_NUMBER_FILES )
	{

		debug_log ( "Unable to create a file mapping - maximum files already mapped" );

		return ( NULL );
	}
	else
	{

#ifdef WIN32
		hFile = CreateFile ( filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

		if ( !hFile )
		{

			debug_log ( "Unable to memory map file %s", filename );

			return ( NULL );
		}
#else
		fd = open ( filename, O_RDONLY );

		if ( !fd )
		{
			debug_log ( "Unable to open file %s prior to mmap: %s", filename, strerror(errno) );

			return ( NULL );
		}
#endif

		sprintf ( mapping_name, "%08x%04dFileMapping", timeGetTime (), count );

#ifdef WIN32
		hMap = CreateFileMapping ( hFile, NULL, PAGE_READONLY, 0, 0, mapping_name );

		if ( ! hMap )
		{

			CloseHandle ( hFile );

			debug_log ( "Unable to create memory mapped file %s", filename );

			return ( NULL );
		}

		data = MapViewOfFile ( hMap, FILE_MAP_READ, 0, 0, 0 );
#else
		// set length to size of file
		fstat( fd, &filestat );
		length = filestat.st_size;

		data = mmap(0, length, PROT_READ, MAP_SHARED, fd, 0);
#endif

#ifdef MFA
#ifdef WIN32
		if ( !data )
		{
			unsigned long
				length;

			DWORD
				offset,
				read;

			length = GetFileSize ( hFile, NULL );
			if ( length <= MEMORY1 && !memory1_used )
			{
				data = memory1;
				memory1_used = TRUE;
			}
			else if ( length <= MEMORY2 && !memory2_used )
			{
				data = memory2;
				memory2_used = TRUE;
			}

			if ( data )
			{
				offset = 0;
				while ( length )
				{
					if ( !ReadFile ( hFile, ( char * ) data + offset, length, &read, NULL ) )
					{
						debug_fatal ( "Failed to read %u bytes from file %s: 0x%08X", length, filename, GetLastError () );
					}
					offset += read;
					length -= read;
				}
			}
		}
#endif
#endif

		if ( ! data )
		{

#ifdef WIN32
			CloseHandle ( hMap );

			CloseHandle ( hFile );

			debug_log ( "Unable to create file mapping for memory mapped file %s", filename );
#else
			close(fd);

			debug_log ( "Unable to create file mapping for memory mapped file %s: %s", filename, strerror(errno) );
#endif

			return ( NULL );
		}

#ifdef WIN32
		file_maps[count].hFile = hFile;
		file_maps[count].hMap = hMap;
#else
		file_maps[count].fd = fd;
		file_maps[count].length = length;
#endif
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

	for ( count = 0; count < MAX_NUMBER_FILES; count++ )
	{
		if ( file_maps[count].used && file_maps[count].data == data )
		{
			break;
		}
	}

	if ( count == MAX_NUMBER_FILES )
	{

		debug_log ( "Unable to locate memory mapped file to unmap file." );

		return ( FALSE );
	}

#ifdef WIN32
#ifdef MFA
	if ( file_maps[count].data == memory1 )
	{
		memory1_used = FALSE;
	}
	else if ( file_maps[count].data == memory1 )
	{
		memory2_used = FALSE;
	}
	else
#endif
	UnmapViewOfFile ( file_maps[count].data );

	CloseHandle ( file_maps[count].hMap );

	CloseHandle ( file_maps[count].hFile );
#else
	munmap( file_maps[count].data, file_maps[count].length );

	close( file_maps[count].fd );
#endif


	file_maps[count].used = FALSE;
#ifdef WIN32
	file_maps[count].hFile = 0;
	file_maps[count].hMap = 0;
#else
	file_maps[count].fd = 0;
	file_maps[count].length = 0;
#endif
	file_maps[count].data = NULL;

	return ( TRUE );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// JB 030311 Enable running out of separate directories
extern char comanche_hokum_installation_path[];

int file_exist (const char *filename)
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

int file_size ( const char *filename )
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

void *safe_mopen (const char *filename)
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

FILE *safe_fopen( const char *filename, const char *mode )
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

