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

static scale_data
	clock_large_hand_scale_down_20_ahead[] =
	{
		// dial centred at x = 45, y = 388

		#define TICK_VALUE		(0.0)
		#define TICK_INCREMENT	(5.0)
		{ 45, 369, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{ 46, 369, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{ 47, 369, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{ 48, 370, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{ 49, 370, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{ 50, 370, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{ 51, 370, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{ 52, 371, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{ 53, 371, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(5.0)
		#define TICK_INCREMENT	(5.0)
		{ 54, 372, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{ 55, 372, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{ 56, 373, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{ 57, 374, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{ 58, 375, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{ 59, 376, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{ 60, 377, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(10.0)
		#define TICK_INCREMENT	(5.0)
		{ 60, 378, TICK_VALUE + (TICK_INCREMENT * ( 0.0 / 10.0))},
		{ 61, 379, TICK_VALUE + (TICK_INCREMENT * ( 1.0 / 10.0))},
		{ 61, 380, TICK_VALUE + (TICK_INCREMENT * ( 2.0 / 10.0))},
		{ 62, 381, TICK_VALUE + (TICK_INCREMENT * ( 3.0 / 10.0))},
		{ 62, 382, TICK_VALUE + (TICK_INCREMENT * ( 4.0 / 10.0))},
		{ 62, 383, TICK_VALUE + (TICK_INCREMENT * ( 5.0 / 10.0))},
		{ 63, 384, TICK_VALUE + (TICK_INCREMENT * ( 6.0 / 10.0))},
		{ 63, 385, TICK_VALUE + (TICK_INCREMENT * ( 7.0 / 10.0))},
		{ 63, 386, TICK_VALUE + (TICK_INCREMENT * ( 8.0 / 10.0))},
		{ 63, 387, TICK_VALUE + (TICK_INCREMENT * ( 9.0 / 10.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(15.0)
		#define TICK_INCREMENT	(5.0)
		{ 63, 388, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{ 63, 389, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{ 63, 390, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{ 63, 391, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{ 62, 392, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{ 62, 393, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{ 62, 394, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{ 61, 395, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{ 61, 396, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(20.0)
		#define TICK_INCREMENT	(5.0)
		{ 61, 397, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{ 60, 398, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{ 59, 399, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{ 58, 400, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{ 57, 401, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{ 56, 402, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{ 55, 403, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(25.0)
		#define TICK_INCREMENT	(5.0)
		{ 54, 404, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{ 53, 404, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{ 52, 405, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{ 51, 405, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{ 50, 405, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{ 49, 406, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{ 48, 406, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{ 47, 406, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{ 46, 406, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(30.0)
		#define TICK_INCREMENT	(5.0)
		{ 45, 406, TICK_VALUE + (TICK_INCREMENT * ( 0.0 / 10.0))},
		{ 44, 406, TICK_VALUE + (TICK_INCREMENT * ( 1.0 / 10.0))},
		{ 43, 406, TICK_VALUE + (TICK_INCREMENT * ( 2.0 / 10.0))},
		{ 42, 406, TICK_VALUE + (TICK_INCREMENT * ( 3.0 / 10.0))},
		{ 41, 406, TICK_VALUE + (TICK_INCREMENT * ( 4.0 / 10.0))},
		{ 40, 406, TICK_VALUE + (TICK_INCREMENT * ( 5.0 / 10.0))},
		{ 39, 405, TICK_VALUE + (TICK_INCREMENT * ( 6.0 / 10.0))},
		{ 38, 405, TICK_VALUE + (TICK_INCREMENT * ( 7.0 / 10.0))},
		{ 37, 405, TICK_VALUE + (TICK_INCREMENT * ( 8.0 / 10.0))},
		{ 36, 404, TICK_VALUE + (TICK_INCREMENT * ( 9.0 / 10.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(35.0)
		#define TICK_INCREMENT	(5.0)
		{ 35, 404, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{ 34, 403, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{ 33, 402, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{ 32, 401, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{ 31, 400, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{ 30, 399, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{ 29, 398, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(40.0)
		#define TICK_INCREMENT	(5.0)
		{ 28, 397, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{ 28, 396, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{ 27, 395, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{ 27, 394, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{ 27, 393, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{ 27, 392, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{ 26, 391, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{ 26, 390, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{ 26, 389, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(45.0)
		#define TICK_INCREMENT	(5.0)
		{ 26, 388, TICK_VALUE + (TICK_INCREMENT * ( 0.0 / 10.0))},
		{ 26, 387, TICK_VALUE + (TICK_INCREMENT * ( 1.0 / 10.0))},
		{ 26, 386, TICK_VALUE + (TICK_INCREMENT * ( 2.0 / 10.0))},
		{ 26, 385, TICK_VALUE + (TICK_INCREMENT * ( 3.0 / 10.0))},
		{ 26, 384, TICK_VALUE + (TICK_INCREMENT * ( 4.0 / 10.0))},
		{ 27, 383, TICK_VALUE + (TICK_INCREMENT * ( 5.0 / 10.0))},
		{ 27, 382, TICK_VALUE + (TICK_INCREMENT * ( 6.0 / 10.0))},
		{ 27, 381, TICK_VALUE + (TICK_INCREMENT * ( 7.0 / 10.0))},
		{ 28, 380, TICK_VALUE + (TICK_INCREMENT * ( 8.0 / 10.0))},
		{ 28, 379, TICK_VALUE + (TICK_INCREMENT * ( 9.0 / 10.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(50.0)
		#define TICK_INCREMENT	(5.0)
		{ 29, 378, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{ 29, 377, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{ 30, 376, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{ 31, 375, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{ 32, 374, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{ 33, 373, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{ 34, 372, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(55.0)
		#define TICK_INCREMENT	(5.0)
		{ 35, 372, TICK_VALUE + (TICK_INCREMENT * ( 0.0 / 10.0))},
		{ 36, 371, TICK_VALUE + (TICK_INCREMENT * ( 1.0 / 10.0))},
		{ 37, 371, TICK_VALUE + (TICK_INCREMENT * ( 2.0 / 10.0))},
		{ 38, 370, TICK_VALUE + (TICK_INCREMENT * ( 3.0 / 10.0))},
		{ 39, 370, TICK_VALUE + (TICK_INCREMENT * ( 4.0 / 10.0))},
		{ 40, 370, TICK_VALUE + (TICK_INCREMENT * ( 5.0 / 10.0))},
		{ 41, 370, TICK_VALUE + (TICK_INCREMENT * ( 6.0 / 10.0))},
		{ 42, 369, TICK_VALUE + (TICK_INCREMENT * ( 7.0 / 10.0))},
		{ 43, 369, TICK_VALUE + (TICK_INCREMENT * ( 8.0 / 10.0))},
		{ 44, 369, TICK_VALUE + (TICK_INCREMENT * ( 9.0 / 10.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		{0, 0, FLT_MAX},
	};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static scale_data
	clock_small_hand_scale_down_20_ahead[] =
	{
		// dial centred at x = 45, y = 388

		#define TICK_VALUE		(0.0)
		#define TICK_INCREMENT	(1.0)
		{ 45, 378, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{ 46, 378, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{ 47, 378, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{ 48, 379, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{ 49, 379, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(1.0)
		#define TICK_INCREMENT	(1.0)
		{ 50, 379, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{ 51, 380, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{ 52, 381, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{ 53, 382, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(2.0)
		#define TICK_INCREMENT	(1.0)
		{ 53, 383, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{ 53, 384, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{ 54, 385, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{ 54, 386, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{ 54, 387, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(3.0)
		#define TICK_INCREMENT	(1.0)
		{ 54, 388, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{ 54, 389, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{ 54, 390, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{ 54, 391, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{ 53, 392, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(4.0)
		#define TICK_INCREMENT	(1.0)
		{ 53, 393, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  3.0))},
		{ 52, 394, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  3.0))},
		{ 51, 395, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  3.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(5.0)
		#define TICK_INCREMENT	(1.0)
		{ 50, 396, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{ 49, 396, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{ 48, 397, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{ 47, 397, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{ 46, 397, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(6.0)
		#define TICK_INCREMENT	(1.0)
		{ 45, 397, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{ 44, 397, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{ 43, 397, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{ 42, 397, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{ 41, 397, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(7.0)
		#define TICK_INCREMENT	(1.0)
		{ 40, 396, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{ 39, 396, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{ 38, 395, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{ 37, 394, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(8.0)
		#define TICK_INCREMENT	(1.0)
		{ 36, 393, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{ 36, 392, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{ 35, 391, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{ 35, 390, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{ 35, 389, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(9.0)
		#define TICK_INCREMENT	(1.0)
		{ 35, 388, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{ 35, 387, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{ 35, 386, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{ 35, 385, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{ 36, 384, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(10.0)
		#define TICK_INCREMENT	(1.0)
		{ 36, 383, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{ 37, 382, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{ 38, 381, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{ 39, 380, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(11.0)
		#define TICK_INCREMENT	(1.0)
		{ 40, 379, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{ 41, 379, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{ 42, 378, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{ 43, 378, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{ 44, 378, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		{0, 0, FLT_MAX},
	};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static scale_data
	clock_large_hand_scale_down_20_left_30[] =
	{
		// dial centred at x = 317, y = 349

		#define TICK_VALUE		(0.0)
		#define TICK_INCREMENT	(5.0)
		{320, 333, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{321, 333, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{322, 333, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{323, 334, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{324, 334, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{325, 335, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{326, 336, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(5.0)
		#define TICK_INCREMENT	(5.0)
		{327, 337, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{328, 338, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{329, 339, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{329, 340, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{330, 341, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{330, 342, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{331, 343, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(10.0)
		#define TICK_INCREMENT	(5.0)
		{331, 344, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{331, 345, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{331, 346, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{332, 347, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{332, 348, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{332, 349, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{332, 350, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{332, 351, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{332, 352, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(15.0)
		#define TICK_INCREMENT	(5.0)
		{331, 353, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  8.0))},
		{331, 354, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  8.0))},
		{331, 355, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  8.0))},
		{331, 356, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  8.0))},
		{330, 357, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  8.0))},
		{330, 358, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  8.0))},
		{329, 359, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  8.0))},
		{329, 360, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  8.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(20.0)
		#define TICK_INCREMENT	(5.0)
		{328, 361, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  6.0))},
		{327, 362, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  6.0))},
		{326, 363, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  6.0))},
		{325, 363, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  6.0))},
		{324, 364, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  6.0))},
		{323, 364, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  6.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(25.0)
		#define TICK_INCREMENT	(5.0)
		{322, 365, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  8.0))},
		{321, 365, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  8.0))},
		{320, 365, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  8.0))},
		{319, 365, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  8.0))},
		{318, 365, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  8.0))},
		{317, 365, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  8.0))},
		{316, 365, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  8.0))},
		{315, 365, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  8.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(30.0)
		#define TICK_INCREMENT	(5.0)
		{314, 364, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  6.0))},
		{313, 364, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  6.0))},
		{312, 363, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  6.0))},
		{311, 363, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  6.0))},
		{310, 362, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  6.0))},
		{309, 361, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  6.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(35.0)
		#define TICK_INCREMENT	(5.0)
		{308, 360, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{307, 359, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{306, 358, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{306, 357, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{305, 356, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{305, 355, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{304, 354, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(40.0)
		#define TICK_INCREMENT	(5.0)
		{304, 353, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{304, 352, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{303, 351, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{303, 350, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{303, 349, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{303, 348, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{303, 347, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{303, 346, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{303, 345, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(45.0)
		#define TICK_INCREMENT	(5.0)
		{303, 344, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{304, 343, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{304, 342, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{304, 341, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{305, 340, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{305, 339, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{306, 338, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(50.0)
		#define TICK_INCREMENT	(5.0)
		{306, 337, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{307, 336, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{308, 335, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{309, 334, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{310, 334, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{311, 333, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{312, 333, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(55.0)
		#define TICK_INCREMENT	(5.0)
		{313, 333, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{314, 332, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{315, 332, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{316, 332, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{317, 332, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{318, 332, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{319, 332, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		{0, 0, FLT_MAX},
	};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static scale_data
	clock_small_hand_scale_down_20_left_30[] =
	{
		// dial centred at x = 317, y = 349

		#define TICK_VALUE		(0.0)
		#define TICK_INCREMENT	(1.0)
		{319, 340, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{320, 341, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{321, 341, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{322, 342, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(1.0)
		#define TICK_INCREMENT	(1.0)
		{323, 342, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{324, 343, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{324, 344, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{325, 345, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(2.0)
		#define TICK_INCREMENT	(1.0)
		{325, 346, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{325, 347, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{325, 348, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{325, 349, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{325, 350, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(3.0)
		#define TICK_INCREMENT	(1.0)
		{325, 351, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{325, 352, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{325, 353, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{324, 354, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(4.0)
		#define TICK_INCREMENT	(1.0)
		{323, 355, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{322, 356, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{321, 356, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{320, 357, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(5.0)
		#define TICK_INCREMENT	(1.0)
		{319, 357, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{318, 357, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{317, 357, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{316, 357, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(6.0)
		#define TICK_INCREMENT	(1.0)
		{315, 357, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  3.0))},
		{314, 357, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  3.0))},
		{313, 356, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  3.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(7.0)
		#define TICK_INCREMENT	(1.0)
		{312, 355, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{311, 354, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{310, 353, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{310, 352, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(8.0)
		#define TICK_INCREMENT	(1.0)
		{309, 351, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{309, 350, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{309, 349, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{309, 348, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{309, 347, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(9.0)
		#define TICK_INCREMENT	(1.0)
		{309, 346, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{309, 345, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{310, 344, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{310, 343, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(10.0)
		#define TICK_INCREMENT	(1.0)
		{311, 342, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{312, 342, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{313, 341, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{314, 341, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(11.0)
		#define TICK_INCREMENT	(1.0)
		{315, 340, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{316, 340, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{317, 340, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{318, 340, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		{0, 0, FLT_MAX},
	};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static scale_data
	clock_large_hand_scale_down_20_left_60[] =
	{
		// dial centred at x = 589, y = 386

		#define TICK_VALUE		(0.0)
		#define TICK_INCREMENT	(5.0)
		{596, 370, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{597, 370, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{598, 371, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{599, 372, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{600, 373, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{601, 374, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{602, 375, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(5.0)
		#define TICK_INCREMENT	(5.0)
		{603, 376, TICK_VALUE + (TICK_INCREMENT * ( 0.0 / 10.0))},
		{604, 377, TICK_VALUE + (TICK_INCREMENT * ( 1.0 / 10.0))},
		{604, 378, TICK_VALUE + (TICK_INCREMENT * ( 2.0 / 10.0))},
		{605, 379, TICK_VALUE + (TICK_INCREMENT * ( 3.0 / 10.0))},
		{605, 380, TICK_VALUE + (TICK_INCREMENT * ( 4.0 / 10.0))},
		{606, 381, TICK_VALUE + (TICK_INCREMENT * ( 5.0 / 10.0))},
		{606, 382, TICK_VALUE + (TICK_INCREMENT * ( 6.0 / 10.0))},
		{606, 383, TICK_VALUE + (TICK_INCREMENT * ( 7.0 / 10.0))},
		{607, 384, TICK_VALUE + (TICK_INCREMENT * ( 8.0 / 10.0))},
		{607, 385, TICK_VALUE + (TICK_INCREMENT * ( 9.0 / 10.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(10.0)
		#define TICK_INCREMENT	(5.0)
		{607, 386, TICK_VALUE + (TICK_INCREMENT * ( 0.0 / 10.0))},
		{607, 387, TICK_VALUE + (TICK_INCREMENT * ( 1.0 / 10.0))},
		{607, 388, TICK_VALUE + (TICK_INCREMENT * ( 2.0 / 10.0))},
		{607, 389, TICK_VALUE + (TICK_INCREMENT * ( 3.0 / 10.0))},
		{607, 390, TICK_VALUE + (TICK_INCREMENT * ( 4.0 / 10.0))},
		{607, 391, TICK_VALUE + (TICK_INCREMENT * ( 5.0 / 10.0))},
		{607, 392, TICK_VALUE + (TICK_INCREMENT * ( 6.0 / 10.0))},
		{607, 393, TICK_VALUE + (TICK_INCREMENT * ( 7.0 / 10.0))},
		{606, 394, TICK_VALUE + (TICK_INCREMENT * ( 8.0 / 10.0))},
		{606, 395, TICK_VALUE + (TICK_INCREMENT * ( 9.0 / 10.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(15.0)
		#define TICK_INCREMENT	(5.0)
		{606, 396, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{605, 397, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{605, 398, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{604, 399, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{603, 400, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{602, 401, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{601, 402, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(20.0)
		#define TICK_INCREMENT	(5.0)
		{600, 403, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{599, 404, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{598, 404, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{597, 404, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{596, 405, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{595, 405, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{594, 405, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{593, 405, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{592, 405, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(25.0)
		#define TICK_INCREMENT	(5.0)
		{591, 405, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{590, 405, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{589, 405, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{588, 405, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{587, 405, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{586, 405, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{585, 404, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{584, 404, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{583, 403, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(30.0)
		#define TICK_INCREMENT	(5.0)
		{582, 403, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  8.0))},
		{581, 402, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  8.0))},
		{580, 401, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  8.0))},
		{579, 401, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  8.0))},
		{578, 400, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  8.0))},
		{577, 399, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  8.0))},
		{577, 398, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  8.0))},
		{576, 397, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  8.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(35.0)
		#define TICK_INCREMENT	(5.0)
		{575, 396, TICK_VALUE + (TICK_INCREMENT * ( 0.0 / 10.0))},
		{574, 395, TICK_VALUE + (TICK_INCREMENT * ( 1.0 / 10.0))},
		{574, 394, TICK_VALUE + (TICK_INCREMENT * ( 2.0 / 10.0))},
		{573, 393, TICK_VALUE + (TICK_INCREMENT * ( 3.0 / 10.0))},
		{573, 392, TICK_VALUE + (TICK_INCREMENT * ( 4.0 / 10.0))},
		{573, 391, TICK_VALUE + (TICK_INCREMENT * ( 5.0 / 10.0))},
		{572, 390, TICK_VALUE + (TICK_INCREMENT * ( 6.0 / 10.0))},
		{572, 389, TICK_VALUE + (TICK_INCREMENT * ( 7.0 / 10.0))},
		{572, 388, TICK_VALUE + (TICK_INCREMENT * ( 8.0 / 10.0))},
		{572, 387, TICK_VALUE + (TICK_INCREMENT * ( 9.0 / 10.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(40.0)
		#define TICK_INCREMENT	(5.0)
		{572, 386, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{572, 385, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{571, 384, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{572, 383, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{572, 382, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{572, 381, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{572, 380, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{572, 379, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{572, 378, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(45.0)
		#define TICK_INCREMENT	(5.0)
		{573, 377, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  7.0))},
		{573, 376, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  7.0))},
		{574, 375, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  7.0))},
		{574, 374, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  7.0))},
		{575, 373, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  7.0))},
		{576, 372, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  7.0))},
		{577, 371, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  7.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(50.0)
		#define TICK_INCREMENT	(5.0)
		{578, 370, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{579, 370, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{580, 369, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{581, 369, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{582, 368, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{583, 368, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{584, 368, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{585, 367, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{586, 367, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(55.0)
		#define TICK_INCREMENT	(5.0)
		{587, 367, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  9.0))},
		{588, 367, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  9.0))},
		{589, 367, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  9.0))},
		{590, 368, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  9.0))},
		{591, 368, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  9.0))},
		{592, 368, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  9.0))},
		{593, 368, TICK_VALUE + (TICK_INCREMENT * ( 6.0 /  9.0))},
		{594, 369, TICK_VALUE + (TICK_INCREMENT * ( 7.0 /  9.0))},
		{595, 369, TICK_VALUE + (TICK_INCREMENT * ( 8.0 /  9.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		{0, 0, FLT_MAX},
	};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static scale_data
	clock_small_hand_scale_down_20_left_60[] =
	{
		// dial centred at x = 589, y = 386

		#define TICK_VALUE		(0.0)
		#define TICK_INCREMENT	(1.0)
		{593, 377, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{594, 378, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{595, 378, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{596, 379, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{596, 380, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(1.0)
		#define TICK_INCREMENT	(1.0)
		{597, 381, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{597, 382, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{597, 383, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{598, 384, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{598, 385, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(2.0)
		#define TICK_INCREMENT	(1.0)
		{598, 386, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  6.0))},
		{598, 387, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  6.0))},
		{598, 388, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  6.0))},
		{598, 389, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  6.0))},
		{598, 390, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  6.0))},
		{598, 391, TICK_VALUE + (TICK_INCREMENT * ( 5.0 /  6.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(3.0)
		#define TICK_INCREMENT	(1.0)
		{598, 392, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  3.0))},
		{597, 393, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  3.0))},
		{596, 394, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  3.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(4.0)
		#define TICK_INCREMENT	(1.0)
		{595, 395, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{594, 395, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{593, 396, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{592, 396, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{591, 396, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(5.0)
		#define TICK_INCREMENT	(1.0)
		{590, 396, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{589, 396, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{588, 396, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{587, 396, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{586, 395, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(6.0)
		#define TICK_INCREMENT	(1.0)
		{585, 395, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{584, 394, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{583, 393, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{582, 392, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(7.0)
		#define TICK_INCREMENT	(1.0)
		{581, 391, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{581, 390, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{580, 389, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{580, 388, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{580, 387, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(8.0)
		#define TICK_INCREMENT	(1.0)
		{580, 386, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{580, 385, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{580, 384, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{580, 383, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{580, 382, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(9.0)
		#define TICK_INCREMENT	(1.0)
		{580, 381, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  4.0))},
		{581, 380, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  4.0))},
		{581, 379, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  4.0))},
		{582, 378, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  4.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(10.0)
		#define TICK_INCREMENT	(1.0)
		{583, 377, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{584, 377, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{585, 377, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{586, 377, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{587, 376, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		#define TICK_VALUE		(11.0)
		#define TICK_INCREMENT	(1.0)
		{588, 376, TICK_VALUE + (TICK_INCREMENT * ( 0.0 /  5.0))},
		{589, 376, TICK_VALUE + (TICK_INCREMENT * ( 1.0 /  5.0))},
		{590, 377, TICK_VALUE + (TICK_INCREMENT * ( 2.0 /  5.0))},
		{591, 377, TICK_VALUE + (TICK_INCREMENT * ( 3.0 /  5.0))},
		{592, 377, TICK_VALUE + (TICK_INCREMENT * ( 4.0 /  5.0))},
		#undef TICK_VALUE
		#undef TICK_INCREMENT
		{0, 0, FLT_MAX},
	};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
