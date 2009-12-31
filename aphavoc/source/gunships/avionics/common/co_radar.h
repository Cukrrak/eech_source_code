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

enum RADAR_SWEEP_MODES
{
	RADAR_SWEEP_MODE_CONTINUOUS,
//	RADAR_SWEEP_MODE_SINGLE_INACTIVE,
//	RADAR_SWEEP_MODE_SINGLE_ACTIVE,
	RADAR_SWEEP_MODE_SINGLE,
	NUM_RADAR_SWEEP_MODES
};

typedef enum RADAR_SWEEP_MODES radar_sweep_modes;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct RADAR_PARAMS
{
	float
		scan_range,
		scan_min_range,
		scan_datum,
		scan_arc_size,
		sweep_offset,
		sweep_rate,
		sweep_direction,
		elevation,
		max_target_track_range;

	int
		bar,
		bar_scan,   // how many bars to do in a scan
		show_allied_targets,
		target_locked,
		auto_target;

	radar_sweep_modes
		sweep_mode;

	target_priority_types
		target_priority_type;
};

typedef struct RADAR_PARAMS radar_params;

typedef struct
{
	entity*
		en;

	vec3d
		last_position,
		previous_position,
		velocity;

	vec2d
		display_position;

	float
		priority,
		last_contact;

	unsigned
		age;
} radar_contact;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define RADAR_SCAN_ARC_SIZE_360	((float) rad (360.0))

#define RADAR_SWEEP_CW				((float) 1.0)
#define RADAR_SWEEP_CCW				((float) -1.0)

#define NUM_TPM_PROFILE_LINES 5

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define AIR_RADAR_CONTACT_TIMEOUT	(10.0)

#define MIN_RADAR_ELEVATION_ANGLE rad(-20.0)
#define MAX_RADAR_ELEVATION_ANGLE rad(20.0)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern int
	draw_radar_sweep,
	draw_radar_terrain_los_markers;

extern radar_params
	zoomed_radar,
	tpm_radar,
	ground_radar,
	air_radar;

extern unsigned int
	radar_clutter_hatch_pattern[32];

typedef enum {
	RADAR_MODE_NONE,
	RADAR_MODE_GTM,   // ground targeting mode
	RADAR_MODE_ATM,   // air targeting mode
	RADAR_MODE_RMAP,  // radar map
	RADAR_MODE_TPM,   // terrain profile mode
	NUM_RADAR_MODES
} radar_modes;

typedef enum {
	RADAR_TPM_PROFILE_GEOM,
	RADAR_TPM_PROFILE_ARITH,
	RADAR_TPM_PROFILE_TEST,
} radar_tpm_profile_modes;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void initialise_common_radar (void);

extern void deinitialise_common_radar (void);

extern void limit_radar_sweep (radar_params *radar);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern int get_gunship_target_valid_for_ground_radar (entity *target);

extern int get_target_matches_ground_radar_declutter_criteria (entity *target);

extern void get_next_ground_radar_target (void);

extern void get_previous_ground_radar_target (void);

extern void select_next_designated_ground_radar_target (void); // Jabberwock 031108 Designated targets

extern void select_previous_designated_ground_radar_target (void);

extern void update_common_radar (int inactive_check);

extern void activate_common_ground_radar (void);

extern void deactivate_common_ground_radar (void);

extern void activate_common_radar (void);
extern void deactivate_common_radar (void);

extern radar_modes get_radar_mode(void);
extern void set_radar_mode(radar_modes mode);
extern radar_params* get_current_radar_params(void);

extern unsigned get_radar_active(void);
extern void set_radar_active(unsigned active);
extern void toggle_common_radar_active(void);

void toggle_continuous_radar_active(void);
void toggle_single_scan_active(void);

extern void toggle_ground_radar_active(void);
extern unsigned ground_radar_is_active(void);

radar_tpm_profile_modes get_tpm_profile_mode(void);
const char* get_tpm_profile_mode_name(void);
void set_tpm_profile_mode(radar_tpm_profile_modes mode);
float get_tpm_profile_range(unsigned index);

typedef void (*profile_line_iterator_handler)(vec2d* prev_vector, vec2d* vector, vec3d* prev_abs_position, vec3d* abs_position, unsigned line);
void for_all_profile_lines(profile_line_iterator_handler handler);

unsigned get_tpm_profile_lines(void);
void set_tpm_profile_lines(unsigned lines);

float get_tpm_clearance_height(void);
void set_tpm_clearance_height(float height);

void toggle_radar_tpm_far_near_mode(void);
unsigned get_radar_tpm_near_mode(void);

unsigned get_radar_zoomed(void);
void set_radar_zoomed(unsigned zoomed);

void rotate_radar_scan_datum(float amount);

unsigned get_radar_terrain_sensivity();
void set_radar_terrain_sensivity(unsigned sensivity);

void toggle_radar_auto_pan_scan_datum(void);
unsigned get_radar_auto_pan_scan_datum(void);

unsigned get_fcr_powered(void);
void toggle_fcr_power(void);

unsigned fcr_being_powered_up(void);
unsigned get_rfi_powered(void);
void toggle_rfi_power(void);

unsigned get_radar_mma_pinned(void);
void toggle_radar_mma_pinned(void);

unsigned get_rfi_show_hostile_only(void);
void toggle_rfi_show_hostile_only(void);

void draw_terrain_radar_returns(vec3d* origin, float centre_y, float scale);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern int get_gunship_target_valid_for_air_radar (entity *target);

extern int get_target_matches_air_radar_declutter_criteria (entity *target, entity_sides source_side);

extern void get_next_air_radar_target (void);

extern void get_previous_air_radar_target (void);

extern void select_next_designated_air_radar_target (void); // Jabberwock 031108 Designated targets

extern void select_previous_designated_air_radar_target (void);

extern void activate_common_air_radar (void);

extern void deactivate_common_air_radar (void);

extern void toggle_air_radar_active(void);
extern int air_radar_is_active(void);

extern int get_los_clear (entity *target, vec3d *source_position, vec3d *target_position);
extern int check_bearing_within_cw_sweep_segment (float bearing, float cw_sweep_start_direction, float cw_sweep_end_direction);

// TODO remove:
void set_air_radar_is_active(int active);
void set_ground_radar_is_active(int active);

// returns NULL if there are none, otherwise array with ncontacts number of entries
radar_contact* get_radar_contacts(unsigned* ncontacts);

// returns NULL if entity is not among radar's targets
radar_contact* get_radar_contact_from_entity(entity* en);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
