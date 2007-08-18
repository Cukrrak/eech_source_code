//
//   Enemy Engaged RAH-66 Comanche Versus KA-52 Hokum
//   Copyright (C) 2000 Empire Interactive (Europe) Ltd,
//   677 High Road, North Finchley, London N12 0DA
//
//   Please see the document LICENSE.TXT for the full licence agreement
//
// 2. LICENCE
//  2.1
//      Subject to the provisions of this Agreement we now grant to you the
//      following rights in respect of the Source Code:
//   2.1.1
//      the non-exclusive right to Exploit  the Source Code and Executable
//      Code on any medium; and
//   2.1.2
//      the non-exclusive right to create and distribute Derivative Works.
//  2.2
//      Subject to the provisions of this Agreement we now grant you the
//  following rights in respect of the Object Code:
//   2.2.1
//  the non-exclusive right to Exploit the Object Code on the same
//  terms and conditions set out in clause 3, provided that any
//  distribution is done so on the terms of this Agreement and is
//  accompanied by the Source Code and Executable Code (as
//  applicable).
//
// 3. GENERAL OBLIGATIONS
//  3.1
//      In consideration of the licence granted in clause 2.1 you now agree:
//   3.1.1
//  that when you distribute the Source Code or Executable Code or
//  any Derivative Works to Recipients you will also include the
//  terms of this Agreement;
//   3.1.2
//  that when you make the Source Code, Executable Code or any
//  Derivative Works ("Materials") available to download, you will
//  ensure that Recipients must accept the terms of this Agreement
//  before being allowed to download such Materials;
//   3.1.3
//  that by Exploiting the Source Code or Executable Code you may
//  not impose any further restrictions on a Recipient's subsequent
//  Exploitation of the Source Code or Executable Code other than
//  those contained in the terms and conditions of this Agreement;
//   3.1.4
//  not (and not to allow any third party) to profit or make any
//  charge for the Source Code, or Executable Code, any
//  Exploitation of the Source Code or Executable Code, or for any
//  Derivative Works;
//   3.1.5
//  not to place any restrictions on the operability of the Source
//  Code;
//   3.1.6
//  to attach prominent notices to any Derivative Works stating
//  that you have changed the Source Code or Executable Code and to
//  include the details anddate of such change; and
//   3.1.7
//      not to Exploit the Source Code or Executable Code otherwise than
//  as expressly permitted by  this Agreement.
//

//
//   VJ eech.ini mod, date: 030403
//
//   Description: reads TEXT file "eech.ini" with commandline options
//

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "project.h"

//VJ 060211 save hud info to eech.ini
int hud_code[8][3];

#define DEFAULT_GWUT_FILE "gwut190.csv"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//VJ 050207 use enum definitions from wm_data.h
static void wide_cockpit_initialize(void)
{
	//VJ 050205 new wideview init settings
		wide_cockpit_position[WIDEVIEW_COMANCHE_PILOT].x = 0;
		wide_cockpit_position[WIDEVIEW_COMANCHE_PILOT].y = 0.105; 
		wide_cockpit_position[WIDEVIEW_COMANCHE_PILOT].z = 0.180;
		wide_cockpit_position[WIDEVIEW_COMANCHE_PILOT].p = 0;

		wide_cockpit_position[WIDEVIEW_COMANCHE_COPILOT].x = 0;
		wide_cockpit_position[WIDEVIEW_COMANCHE_COPILOT].y = 0.105; 
		wide_cockpit_position[WIDEVIEW_COMANCHE_COPILOT].z = 0.180;
		wide_cockpit_position[WIDEVIEW_COMANCHE_COPILOT].p = 0;

		wide_cockpit_position[WIDEVIEW_HOKUM_PILOT].x = 0.0;
		wide_cockpit_position[WIDEVIEW_HOKUM_PILOT].y = 0.0;
		wide_cockpit_position[WIDEVIEW_HOKUM_PILOT].z = 0.200;
		wide_cockpit_position[WIDEVIEW_HOKUM_PILOT].p = 0.0;

		wide_cockpit_position[WIDEVIEW_HOKUM_COPILOT].x = 0.0;
		wide_cockpit_position[WIDEVIEW_HOKUM_COPILOT].y = 0.0;
		wide_cockpit_position[WIDEVIEW_HOKUM_COPILOT].z = 0.200;
		wide_cockpit_position[WIDEVIEW_HOKUM_COPILOT].p = 0.0;
//VJ 050210 defined in vm_data.h
		wide_cockpit_position[WIDEVIEW_APACHE_PILOT].x = BASE_X_APACHE;
		wide_cockpit_position[WIDEVIEW_APACHE_PILOT].y = BASE_Y_APACHE;
		wide_cockpit_position[WIDEVIEW_APACHE_PILOT].z = BASE_Z_APACHE;
		wide_cockpit_position[WIDEVIEW_APACHE_PILOT].p = BASE_P_APACHE;

		wide_cockpit_position[WIDEVIEW_HAVOC_PILOT].x = BASE_X_HAVOC;
		wide_cockpit_position[WIDEVIEW_HAVOC_PILOT].y = BASE_Y_HAVOC;
		wide_cockpit_position[WIDEVIEW_HAVOC_PILOT].z = BASE_Z_HAVOC;
		wide_cockpit_position[WIDEVIEW_HAVOC_PILOT].p = BASE_P_HAVOC;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//VJ 050207 cleaning up the wideview code
void read_wideview_parameters (char *q, int i)
{
	char *p = strtok(q,",");         
	if (p) 
		wide_cockpit_position[i].x = atof(p);
	p = strtok(NULL,",");	     
	if (p) 
		wide_cockpit_position[i].y = atof(p);
	p = strtok(NULL,",");	     
	if (p) 
		wide_cockpit_position[i].z = atof(p);
	p = strtok(NULL,",");	     
	if (p) 
		wide_cockpit_position[i].p = atof(p);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//VJ 060212 hud info mod
void read_hud_parameters (char *q)
{
	int i;
	char *p = strtok(q,",");
	
	for (i = 0; i < 4; i++)
	{
		if (p) 
			hud_code[i][0] = atoi(p);				
		p = strtok(NULL,",");	    
		if (p) 
			hud_code[i][1] = atoi(p);				
		p = strtok(NULL,",");	    
		if (p) 
			hud_code[i][2] = atoi(p);				
		p = strtok(NULL,",");	    
				 
	}	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void read_export_mfd_pos(char *q, int *pos)
{
	char *p = strtok(q,",");         
	if (p) 
		pos[0]= atoi(p);
	p = strtok(NULL,",");	     
	if (p) 
		pos[1]= atoi(p);
	p = strtok(NULL,",");	     
	if (p) 
		pos[2]= atoi(p);
	p = strtok(NULL,",");	     
	if (p) 
		pos[3]= atoi(p);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//VJ 030807 adjustable radar ranges
//LEAVE THESE:  even if they are not in eech.ini they need to be initialized before a wut file is read
static void initialize_radar_ranges(void)
{
		radar_range_apache[0] = 500;
		radar_range_apache[1] = 1000;
		radar_range_apache[2] = 2000;
		radar_range_apache[3] = 4000;
		radar_range_apache[4] = 8000;

		radar_range_comanche[0] = 500;
		radar_range_comanche[1] = 1000;
		radar_range_comanche[2] = 2000;
		radar_range_comanche[3] = 4000;
		radar_range_comanche[4] = 8000;

		radar_range_blackhawk[0] = 500;
		radar_range_blackhawk[1] = 1000;
		radar_range_blackhawk[2] = 2000;
		radar_range_blackhawk[3] = 4000;
		radar_range_blackhawk[4] = 8000;

		radar_range_havoc[0] = 1000;
		radar_range_havoc[1] = 2000;
		radar_range_havoc[2] = 4000;
		radar_range_havoc[3] = 6000;

		radar_range_hokum[0] = 1000;
		radar_range_hokum[1] = 2000;
		radar_range_hokum[2] = 4000;
		radar_range_hokum[3] = 6000;
		radar_range_hokum[4] = 10000;

		radar_range_hind[0] = 1000;
		radar_range_hind[1] = 2000;
		radar_range_hind[2] = 4000;
		radar_range_hind[3] = 6000;
		
		
		//VJ 060212 hud info mod
		memset(	hud_code, 0, 8*3*sizeof(int));		
		hud_code[0][2] = 10;
		hud_code[1][2] = 10;
		hud_code[2][2] = 10;
		hud_code[3][2] = 10;
		hud_code[4][2] = 10;
		hud_code[5][2] = 10;
		hud_code[6][2] = 10;
		hud_code[7][2] = 10;		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void process_ini_file(int argc, char *argv[])
{
	 FILE *f;

//VJ 040816 (and 041002) bug fix: make a copy of the text buf to buf1 and strip the spaces before the '#' char
	 char *buf, *buf1;
	 char *p, *q, *r;
	 char fname[12] = "eech.ini";
	 float v1;
	 int d1, k;

//VJ 030511, get wideview cockpit mod defaults in aphavoc\source\gunships\views\vm_event.c
	 wide_cockpit_initialize();

//VJ 030807 initialize radar ranges, do it here because they need initializing even if eech.ini doesn't work 
//VJ 050125 changed back: this should always be done
    initialize_radar_ranges();

	 buf = ( char * ) malloc (255);
	 if (buf == NULL)
	 {
		  debug_fatal ("Could not allocate buffer");
		  return;
	 }

//VJ 030414, commandline /ini:0 starts up without ini file
	 while(argc--)
	 {
		 p = *argv++;
		 debug_log("eech.ini %s",p);
		 if( strstr(p, "ini:0"))
		 {
			free(buf);
			return;
		 }
	 }
	 
//VJ 030409, changed to generate eech.ini when it doesn't exist
	 if (command_line_dump_ini && !file_exist(fname))
	 {
		 dump_ini_file();
	 }

	 f = fopen(fname, "r");
	 if (!f)
	 {
		 free(buf);
		 debug_fatal("Error opening eech.ini");
		 return;
	 }

//VJ 040816 bug fix: make a copy of the text buf to buf1 and strip the spaces before the '#' char
    buf1 = ( char * ) malloc(255);
    
	 // main loop to parse eech.ini file
	 while (!strstr(buf,"end of file"))
	 {
		int i = 0, j = 0;
		fscanf(f,"%[^\n]\n",buf);
      
		if (!strchr(buf,'='))
		  continue;

//VJ 040816 bug fix: make a copy of the text buf to buf1 and strip the spaces before the '#' char
		j=0;
      for (i = 0; i < strlen(buf); i++){
      	if (buf[i] != ' '){
      		buf1[j] = buf[i];
	   		j++;
      	}  
      }
      buf1[j] = '\0';
      
//VJ 041002 bug fix: if variable is empty so # follows = the # is overwritten by NULL 
//after the first call to strtok, this causes an error because q then contains the comment 
//without spaces. fix: empty q when that is the case.
		r = strchr(buf1, '=');
		r++;
		if (r[0] == '#'){       
  			p = strtok(buf1,"=");
			q[0] = '\0';
		}else{
  			p = strtok(buf1,"=");
			q = strtok(NULL,"#");
		}   

		while(q[i] && q[i]!=' ')
		 i++;
		q[i] = '\0';

		sscanf(q,"%f",&v1);
		sscanf(q,"%d",&d1);
//GAME
		if (strcmp(p, "chaff")==0)  command_line_chaff_effectiveness = v1;
		if (strcmp(p, "flare")==0)  command_line_flare_effectiveness = v1;
		if (strcmp(p, "smoke")==0)  command_line_smoke_effectiveness = v1;
		if (strcmp(p, "fog"  )==0)  command_line_fog_of_war_maximum_value = v1;
		if (strcmp(p, "cpac")==0) 	command_line_capture_aircraft = d1;
		if (strcmp(p, "uit")==0) 	command_line_user_invulnerable_time = v1;
//GRAPH
		if (strcmp(p, "cbar")==0)  	command_line_city_block_approximation_range = v1;
		if (strcmp(p, "mfr")==0)  	command_line_max_frame_rate = d1;
		if (strcmp(p, "fs")==0) 		command_line_full_screen = d1;
		if (strcmp(p, "32bit")==0)
		{
			command_line_display_bpp=16;
		 if (d1 == 1)
			command_line_display_bpp=32;
		}
		if (strcmp(p, "persistent_smoke")==0)  command_line_persistent_smoke = d1;
		if (strcmp(p, "wobbly-camera")==0)  command_line_wobbly_camera = d1;

		if (strcmp(p, "nrt")==0)  	command_line_no_render_to_texture = d1;
		if (strcmp(p, "notnl")==0) 	command_line_no_hardware_tnl = d1;
		if (strcmp(p, "3dreset")==0)
		{
			if (d1 == 1)
			{
				 set_global_3d_visual_screen_width(640.0);
				 set_global_3d_visual_screen_height(480.0);
			}
		}
		if (strcmp(p, "dxtm")==0) 	command_line_d3d_use_texture_management = d1;
		if (strcmp(p, "cg")==0) 		command_line_clean_graphics = d1;
		if (strcmp(p, "palette")==0) 	d3d_allow_paletted_textures = d1; //Casm 20JUN05 External switch of .pal/.bin for textures
//COMMS
		if (strcmp(p, "ipa")==0)
		  if(strlen(q)!=0)
				strcpy(command_line_ip_address, q);
		if (strcmp(p, "pss")==0)
		  if(strlen(q)!=0)
				strcpy(command_line_primary_server_setting, q);
		if (strcmp(p, "sss")==0)
		  if(strlen(q)!=0)
				strcpy(command_line_secondary_server_setting, q);

		if (strcmp(p, "usemaster")==0) 	command_line_report_to_masterserver = d1; //Werewolf 2 Jan 04

		if (strcmp(p, "ccrs")==0) 	command_line_comms_connection_receive_size = d1;
		if (strcmp(p, "cdrs")==0) 	command_line_comms_data_record_size = d1;
		if (strcmp(p, "cpbs")==0) 	command_line_comms_pack_buffer_size = d1;
		if (strcmp(p, "cpds")==0) 	command_line_comms_packet_data_size = d1;
		if (strcmp(p, "cgs")==0) 	command_line_comms_guaranteed_send = d1;
		if (strcmp(p, "crls")==0) 	command_line_comms_resend_list_size = d1;
		if (strcmp(p, "crl")==0) 	command_line_comms_packet_rerequest_limit = d1;
		if (strcmp(p, "cpt")==0) 	command_line_comms_packet_resend_timer = v1;
		if (strcmp(p, "crto")==0) 	command_line_comms_resend_timeout = v1;
		if (strcmp(p, "mur")==0) 	command_line_max_game_update_rate = d1;
		if (strcmp(p, "cig")==0) 	command_line_comms_interpolate_gunships = d1;
		if (strcmp(p, "cvc")==0) 	command_line_comms_validate_connections = d1;
		if (strcmp(p, "cptl")==0) 	command_line_comms_packet_throttle_limit = d1;
		if (strcmp(p, "cto")==0) 	command_line_comms_timeout = d1;
		if (strcmp(p, "eufr")==0) 	command_line_entity_update_frame_rate = d1;
		if (strcmp(p, "css")==0) 	command_line_comms_show_stats = d1;
		if (strcmp(p, "cist")==0) 	command_line_comms_initial_sleep_time = d1;
		if (strcmp(p, "servlog")==0) // Jabberwock 031119 Server log
		  if (strlen(q)!=0)
			  strcpy(command_line_server_log_filename, q); 
		if (strcmp(p, "pauseserv")==0) 	command_line_pause_server = d1; // Jabberwock 040220 Pause server
		if (strcmp(p, "dedicated")==0) 	command_line_comms_dedicated_server = d1;
		if (strcmp(p, "game_type")==0) 	command_line_game_initialisation_phase_game_type = d1;
		if (strcmp(p, "gunship_type")==0) command_line_game_initialisation_phase_gunship_type = d1;
		if (strcmp(p, "path")==0)
		  if (strlen(q)!=0)
			  strcpy(command_line_game_initialisation_phase_path, q);
//DYN
		if (strcmp(p, "advancedfm")==0) command_line_dynamics_advanced_flight_model = d1; //Werewolf 3 Jan 04
		if (strcmp(p, "enginerealism")==0) command_line_dynamics_advanced_engine_model = d1; //Werewolf 5 Feb 06
		if (strcmp(p, "enginestartup")==0) 	command_line_dynamics_engine_startup = d1; // arneh - july 2006
		if (strcmp(p, "drbs")==0) 	command_line_dynamics_retreating_blade_stall_effect = v1;
		if (strcmp(p, "drv")==0) 	command_line_dynamics_rudder_value = v1;
		if (strcmp(p, "dra")==0) 	command_line_dynamics_rudder_acceleration = v1;
		if (strcmp(p, "drd")==0) 	command_line_dynamics_main_rotor_drag = v1;
		if (strcmp(p, "dmrl")==0) 	command_line_dynamics_main_rotor_lift = v1;
		if (strcmp(p, "dtrd")==0) 	command_line_dynamics_tail_rotor_drag = v1;
		if (strcmp(p, "dcdz")==0) 	command_line_dynamics_cyclic_dead_zone = v1;
		if (strcmp(p, "dyal")==0) 	command_line_dynamics_yaw_altitude_loss = v1;
		if (strcmp(p, "debug_show_force_vectors")==0) 	set_global_dynamics_options_draw_flight_path(d1); // arneh - dec 2006
//MISC
		if (strcmp(p, "goto")==0) 	command_line_planner_goto_button = d1;
		if (strcmp(p, "vfm")==0) 	command_line_vector_flight_model = d1;
		if (strcmp(p, "psr")==0) 	command_line_player_start_rank = d1;
		if (strcmp(p, "ns")==0) 		command_line_no_sound=d1;
		if (strcmp(p, "hdwrbuf")==0) 	command_line_sound_hdwrbuf=d1;
		if (strcmp(p, "mta")==0) 	command_line_max_time_acceleration = d1;
		if (strcmp(p, "nomcm")==0) 	command_line_no_mission_complete_music = d1;
//WUT
//VJ 030511 WUT is a separate part of the eech.ini
		if (strcmp(p, "wut") == 0)
		{
			if (strlen(q)!=0)
				strcpy(WUT_filename, q);
			else
				strcpy(WUT_filename, DEFAULT_GWUT_FILE);

			debug_log("wutfile ini [%s]",WUT_filename);

			if (WUT_filename[0] != 0 && file_exist(WUT_filename))
				command_line_wut = TRUE;
			// wut filename checking is done elsewhere
		}

//WIDEVIEW
//VJ 030511 added the wideview params to eech.ini
//VJ 041225 fixed bug: no spaces in variable name allowed, comanche with 1 'm'!
//VJ 050207 cleaning up the wideview code
	 	if (strcmp(p, "comanche_pilot")==0)
			read_wideview_parameters(q, WIDEVIEW_COMANCHE_PILOT);
	 	if (strcmp(p, "comanche_co-pilot")==0)
			read_wideview_parameters(q, WIDEVIEW_COMANCHE_COPILOT);
	 	if (strcmp(p, "hokum_pilot")==0)
			read_wideview_parameters(q, WIDEVIEW_HOKUM_PILOT);
	 	if (strcmp(p, "hokum_co-pilot")==0)
			read_wideview_parameters(q, WIDEVIEW_HOKUM_COPILOT);
	 	if (strcmp(p, "apache_pilot")==0)
			read_wideview_parameters(q, WIDEVIEW_APACHE_PILOT);
	 	if (strcmp(p, "havoc_pilot")==0)
			read_wideview_parameters(q, WIDEVIEW_HAVOC_PILOT);
		//VJ 060211 save hud config info
	 	if (strcmp(p, "hud_code")==0)
	 		read_hud_parameters(q);
	 	if (strcmp(p, "g-force_head_movement")==0)
	 		command_line_g_force_head_movment_modifier = v1;
//MODS
		if (strcmp(p, "msl") == 0) 			command_line_mouse_look = d1;
		if (strcmp(p, "msls") == 0)			command_line_mouse_look_speed = d1;
		if (strcmp(p, "minfov") == 0) 		command_line_min_fov = d1;
		if (strcmp(p, "maxfov0") == 0) 		command_line_max_fov0 = d1;
		if (strcmp(p, "maxfov1") == 0) 		command_line_max_fov1 = d1;
		if (strcmp(p, "maxfov2") == 0) 		command_line_max_fov2 = d1;
		if (strcmp(p, "maxfov3") == 0) 		command_line_max_fov3 = d1;
		if (strcmp(p, "eopann") == 0) 		command_line_eo_pan_joystick_index = d1;
		if (strcmp(p, "eopanv") == 0) 		command_line_eo_pan_vertical_joystick_axis = d1 - 1;
		if (strcmp(p, "eopanh") == 0) 		command_line_eo_pan_horizontal_joystick_axis = d1 - 1;
		if (strcmp(p, "eozoomn") == 0)		command_line_eo_zoom_joystick_index = d1;
		if (strcmp(p, "eozoomax") == 0)		command_line_eo_zoom_joystick_axis = d1 - 1;
		if (strcmp(p, "joylookn") == 0)		command_line_joylook_joystick_index = d1; // Jabberwock 031104
		if (strcmp(p, "joylookh") == 0)		command_line_joylookh_joystick_axis = d1 - 1; // Jabberwock 031104
		if (strcmp(p, "joylookv") == 0)		command_line_joylookv_joystick_axis = d1 - 1; // Jabberwock 031104
		if (strcmp(p, "joylookst") == 0)	command_line_joylook_step = d1; // Jabberwock 031104
		if (strcmp(p, "radarinf") == 0)		command_line_ground_radar_ignores_infantry = d1;
		if (strcmp(p, "grstab") == 0) 		command_line_ground_stabilisation_available = d1;
		if (strcmp(p, "manual_laser/radar") == 0) 		command_line_manual_laser_radar = d1;
		if (strcmp(p, "targeting_system_auto_page") == 0) 		command_line_targeting_system_auto_page = d1;

		if (strcmp(p, "dfr") == 0) 			command_line_framerate = d1;
////Retro27NovDEAD		if (strcmp(p, "keymap") == 0) 		command_line_key_mapping = d1;
		if (strcmp(p, "dwash") == 0)			command_line_downwash = d1; 
		if (strcmp(p, "cyclicn") == 0)		command_line_cyclic_joystick_index = d1;
		if (strcmp(p, "cyclich") == 0)		command_line_cyclic_joystick_x_axis = d1 - 1;
		if (strcmp(p, "cyclicv") == 0)		command_line_cyclic_joystick_y_axis = d1 - 1;
		if (strcmp(p, "nonlinear-cyclic") == 0)		command_line_nonlinear_cyclic = d1;
		if (strcmp(p, "collectiven") == 0)	command_line_collective_joystick_index = d1;
		if (strcmp(p, "collectiveax") == 0) command_line_collective_joystick_axis = d1 - 1;
		if (strcmp(p, "nonlinear-collective-zone1") == 0)		command_line_collective_zone_1_limit = v1;
		if (strcmp(p, "nonlinear-collective-zone2") == 0)		command_line_collective_zone_2_limit = v1;
		if (strcmp(p, "ruddern") == 0)		command_line_rudder_joystick_index = d1;
		if (strcmp(p, "rudderax") == 0)		command_line_rudder_joystick_axis = d1 - 1;
		if (strcmp(p, "nonlinear-pedals") == 0)		command_line_nonlinear_pedals = d1;
		if (strcmp(p, "restricted_nvg_fov") == 0)	command_line_restricted_nvg_fov = d1; // loke 030420
//		if (strcmp(p, "highresmfd") == 0)	command_line_high_res_mfd = TRUE; // arneh 20061211 - always in hi-res mode for MFDs
		if (strcmp(p, "colourmfd") == 0)	command_line_colour_mfd = d1; // arneh 20061211 - always in hi-res mode for MFDs
		if (strcmp(p, "highreshud") == 0)	command_line_high_res_hud = d1; // loke 030420
		if (strcmp(p, "maxplayers") == 0)	command_line_maxplayers = d1; // Werewolf 030518
		if (strcmp(p, "camcom") == 0)		command_line_camcom = d1; // Jabberwock 031007 Campaign Commander
		if (strcmp(p, "campaign_map_mode") == 0)	command_line_campaign_map = d1;
		if (strcmp(p, "campaign_map_palette") == 0)	command_line_campaign_map_palette = d1;
		if (strcmp(p, "map_update_interval") == 0)	command_line_campaign_map_update_interval = d1;
		if (strcmp(p, "destgt") == 0)		command_line_designated_targets = d1; // Jabberwock 031107 Designated targets
		if (strcmp(p, "filter") == 0)		command_line_session_filter = d1; // Jabberwock 031210 Session filter
		if (strcmp(p, "tsdrender") == 0)		command_line_tsd_render_mode = d1; // VJ 030511
		if (strcmp(p, "tsdpalette") == 0)	command_line_tsd_palette = d1; // VJ 030511
		if (strcmp(p, "tsdenemy") == 0)		command_line_tsd_enemy_colours = d1; // VJ 030511
		if (strcmp(p, "tsddetail") == 0)		global_tsd_detail = d1; // VJ 061215 detailed TSD
		if (strcmp(p, "reverse_pedal") == 0)command_line_reverse_pedal = d1;	// Retro 17Jul2004
		if (strcmp(p, "external_trackir") == 0) command_line_external_trackir = d1;	// Retro 31Oct2004
		if (strcmp(p, "external_trackir_dir") == 0) command_line_external_trackir_direction = d1;	// Retro 31Jan2005
		if (strcmp(p, "high_lod_hack") == 0) command_line_high_lod_hack = d1;	// Retro 31Oct2004
		if (strcmp(p, "TIR_6DOF") == 0) command_line_TIR_6DOF = d1;	// Retro 6Feb2005
		if (strcmp(p, "MEMEXPORT") == 0) command_line_shared_mem_export = d1;	// Retro 14Aug2006
		if (strcmp(p, "3d_cockpit") == 0) command_line_3d_cockpit = d1;	// VJ 050101 3d cockpit mod
		if (strcmp(p, "texture_colour") == 0) command_line_texture_colour = d1;	// VJ 050303 texture colour mod
		if (strcmp(p, "texture_filtering") == 0)  global_anisotropic = d1;	//VJ 050530 AF filtering on/off
		if (strcmp(p, "mipmapping") == 0) global_mipmapping = d1;	//VJ 050530 mipmapping		
	  if (strcmp(p, "night_light") == 0) global_night_light_level = v1;	//VJ 060920 night light levels

		if (strcmp(p, "dynamic_water") == 0) global_dynamic_water = d1;	//VJ 050817 dynamic water textures
		if (strcmp(p, "autosave") == 0) command_line_autosave = d1 * 60; // Casm 17JUN05 Autosave option
		if (strcmp(p, "cannontrack") == 0) command_line_cannontrack = d1;	// Jabberwock 050120 Cannon tracking
		if (strcmp(p, "faa") == 0)
		{
			// VJ 030424 fly any aircraft optional, default on
			////Moje 030609 Changed k-value from 4 to 6 Blackhawk and Hind is always flyable now
			////Moje 030816 Changed the next expression to get the AH64A and KA50 always flyable
			////            number 21 and 22 in ac_dbase.c
			//// 030820 On a 2nd thought, I put back the orginal. Not everyone want's the new choppers

			command_line_fly_any_airplane = d1;
			if (command_line_fly_any_airplane == 0)
			{
				for (k=4; k < NUM_ENTITY_SUB_TYPE_AIRCRAFT; k++)
					aircraft_database[k].player_controllable = FALSE;
			}
		}
		if (strcmp(p, "export_mfd") == 0) command_line_export_mfd= d1;	// mue 070223 
		if (strcmp(p, "export_mfd_adapter") == 0) command_line_export_mfd_adapter= d1;	// mue 070223 
		if (strcmp(p, "export_mfd_screen_width") == 0) command_line_export_mfd_screen_width= d1;	// mue 070223 
		if (strcmp(p, "export_mfd_screen_height") == 0) command_line_export_mfd_screen_height= d1;	// mue 070223 
		if (strcmp(p, "export_mfd_left_pos") == 0) read_export_mfd_pos(q,command_line_export_mfd_left_pos);	// mue 070223 
		if (strcmp(p, "export_mfd_right_pos") == 0) read_export_mfd_pos(q,command_line_export_mfd_right_pos);		// mue 070223 
		if (strcmp(p, "export_mfd_single_pos") == 0) read_export_mfd_pos(q,command_line_export_mfd_single_pos);		// mue 070223 

	}// while (!strstr(buf,"end of file"))
	fclose(f);

//VJ 050818 water doesn't work without the colour texture mod
	if (command_line_texture_colour == 0)
		global_dynamic_water = 0;

//VJ 040816 forgot these
   if (buf1) free(buf1);  
   if (buf) free(buf);  
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//VJ 030511 rewrote dump_ini_file
void dump_ini_file(void)
{
	FILE *f = fopen("eech.ini","w");

	fprintf(f,"[Enemy Engaged - Comanche Hokum commandline options]\n");
	fprintf(f,"[Game]\n");
	fprintf(f,"chaff=%3.1f        # Effectivness of chaff where n = 0.0 (ineffective) to 1.0 (fully effective - default)\n",command_line_chaff_effectiveness);
	fprintf(f,"flare=%3.1f        # Effectivness of flares where n = 0.0 (ineffective) to 1.0 (fully effective - default)\n",command_line_flare_effectiveness);
	fprintf(f,"smoke=%3.1f        # Effectivness of smoke where n = 0.0 (ineffective) to 1.0 (fully effective - default)\n",command_line_smoke_effectiveness);
	fprintf(f,"fog=%.0f            # Sets the time (sec) taken for the \"fog of war\" to reshroud enemy sector info (def = 14400 (4 hours)).\n",command_line_fog_of_war_maximum_value);
	fprintf(f,"cpac=%d              # Capture aircraft landed at captured bases or FARPS become usable by your side.\n",command_line_capture_aircraft);
	fprintf(f,"uit=%3.1f            # User invulnerable time (in seconds), when starting mission (def = 5.0)\n",command_line_user_invulnerable_time);
	fprintf(f,"\n[Graphics]\n");
	fprintf(f,"cbar=%.0f            # distance (in meters) that city blocks resolve\n",command_line_city_block_approximation_range);
	fprintf(f,"fs=%d                # Switch for turning off the default FULL SCREEN video mode, (def = 1, full screen, 0 = windows mode)\n",command_line_full_screen);
	fprintf(f,"mfr=%d               # Max visual frame rate (default = 30)\n",command_line_max_frame_rate);
	fprintf(f,"32bit=%d             # Activates 32bit rendering if your video card supports it (default 1 (on))\n", command_line_display_bpp != 16);
	fprintf(f,"nrt=%d               # Turns off rendering to texture in case of visual problems with MFDs or TADS (default 0 (off))\n",command_line_no_render_to_texture);
	fprintf(f,"notnl=%d             # Turns off GeForce \"TnL\" support for troubleshooting\n",command_line_no_hardware_tnl);
	fprintf(f,"3dreset=0            # Reset screen resolution to 640x480 (def = 0)\n");
	fprintf(f,"dxtm=%d              # directx texture management, should fix \"unable to allocate hardware slot\" error (def = 0)\n",command_line_d3d_use_texture_management);
	fprintf(f,"cg=0                # clean graphics, re-installs graphics files (def = 0)\n");
	fprintf(f,"palette=%i           # allow to use textures.pal if videocard supports it. Default is 1. Recommended is 0.\n", d3d_allow_paletted_textures); //Casm 20JUN05 External switch of .pal/.bin for textures
	fprintf(f,"\n[Communications]\n");
	fprintf(f,"maxplayers=%d        # maximum number of players in a multiplayer game, def = 4\n",command_line_maxplayers);
	fprintf(f,"ipa=%s               # ip address = TCPIP address to connect to. A HOST can leave out the value.\n",command_line_ip_address);
	fprintf(f,"usemaster=%d         # Report game to internet masterserver (0 for private games)\n",command_line_report_to_masterserver);  //Werewolf 2 Jan 04
	fprintf(f,"pss=%s               # primary masterserver setting (server internet address)\n",command_line_primary_server_setting);  //Werewolf: Defaults changed 080403
	fprintf(f,"sss=%s               # secondary masterserver setting (server internet address)\n",command_line_secondary_server_setting);
	fprintf(f,"ccrs=%d              # connection receive size, initial guess of campaign data size (default = 210k)\n",command_line_comms_connection_receive_size);
	fprintf(f,"cdrs=%d              # data record size, similar to above\n",command_line_comms_data_record_size);
	fprintf(f,"cpbs=%d              # pack buffer size, similar to above\n",command_line_comms_pack_buffer_size);
	fprintf(f,"cpds=%d              # packet data size (def = 512)\n",command_line_comms_packet_data_size);
	fprintf(f,"cgs=%d               # force the comms to use DirectPlay guaranteed send instead of its own (def=0).\n",command_line_comms_guaranteed_send);
	fprintf(f,"crls=%d              # packet history list size, increase if client keeps getting kicked out by server (default = 1000)\n",command_line_comms_resend_list_size);
	fprintf(f,"crl=%d               # number of times a client can re-request the same packet, increase for poor connections (def=10)\n",command_line_comms_packet_rerequest_limit);
	fprintf(f,"cpt=%.0f             # time delay in seconds the comms will wait for a packet before re-requesting it. (default = 5s)\n",command_line_comms_packet_resend_timer);
	fprintf(f,"crto=%.0f            # time comms will wait before assuming re-requested packets was lost (default = 2s)\n",command_line_comms_resend_timeout);
	fprintf(f,"mur=%d               # max update framerate for a server, na for a client (default = 5fps for TCPIP, 15fps for IPX)\n",command_line_max_game_update_rate);
	fprintf(f,"cig=%d               # interpolate helicopter position for smoother visuals\n",command_line_comms_interpolate_gunships);
	fprintf(f,"cvc=%d               # validate connection, removes dead player husks when client crashes\n",command_line_comms_validate_connections);
	fprintf(f,"cptl=%d              # packet throttle limit, mainly for modems, governs the flow rate of packets\n",command_line_comms_packet_throttle_limit);
	fprintf(f,"cto=%d               # timeout, the amount of time to wait before removing dead player husks\n",command_line_comms_timeout);
	fprintf(f,"eufr=%d              # client server entity update framerate, no. of iterations\n",command_line_entity_update_frame_rate);
	fprintf(f,"css=%d               # show communication stats (def = 0)\n",command_line_comms_show_stats);
	fprintf(f,"cist=%d              # comms initial sleep time\n",command_line_comms_initial_sleep_time);
	fprintf(f,"servlog=%s           # filename for server log\n",command_line_server_log_filename);
	fprintf(f,"pauseserv=%d         # pause server if no clients connected\n",command_line_pause_server); // 040320 Jabberwock - Pause server
	fprintf(f,"dedicated=%d         # active server mode, off by default.\n",command_line_comms_dedicated_server);
	fprintf(f,"game_type=%d         # Valid game_types are: 1 = Freeflight, 2 = Campaign, 3 = Skirmish (def = 0)\n",command_line_game_initialisation_phase_game_type);
	fprintf(f,"gunship_type=%d      # Gunship_types are, 0 = Apache, 1 = Havoc, 2 = Comanche, 3 = Hokum\n",command_line_game_initialisation_phase_gunship_type);
	fprintf(f,"path=%s              # Path to map, campaign, skirmish\n",command_line_game_initialisation_phase_path);
	fprintf(f,"\n[Dynamics]\n");
	fprintf(f,"advancedfm=%d      # advanced flight model, off by default. Makes sideways flight easier, but not realistic\n",command_line_dynamics_advanced_flight_model);
	fprintf(f,"enginerealism=%d      # realistic engine workload simulation model, on by default.\n",command_line_dynamics_advanced_engine_model);
	fprintf(f,"enginestartup=%d      # manual engine start up, off by default.\n", command_line_dynamics_engine_startup);
	fprintf(f,"drbs=%3.1f         # retreating blade stall, floating point scaling factor for RBS effect (default = 1.0)\n",command_line_dynamics_retreating_blade_stall_effect);
	fprintf(f,"drv=%3.1f          # rudder value, scaling factor for drag on tail rotation (default = 1.0)\n",command_line_dynamics_rudder_value);
	fprintf(f,"dra=%3.1f          # rudder acceleration, scaling factor for tail rotation acceleration (default = 0.8)\n",command_line_dynamics_rudder_acceleration);
	fprintf(f,"drd=%3.1f          # main rotor drag, scaling factor for drag caused by main rotor (default = 1.0)\n",command_line_dynamics_main_rotor_drag);
	fprintf(f,"dmrl=%3.1f         # main rotor lift, scaling factor for lift of main rotor (default = 1.0)\n",command_line_dynamics_main_rotor_lift);
	fprintf(f,"dtrd=%3.1f         # tail rotor drag, scaling factor for drag caused by tail in forward flight (default = 1.0)\n",command_line_dynamics_tail_rotor_drag);
	fprintf(f,"dzd=%3.1f          # cyclic dead zone, percentage deadzone for the cyclic (default = 0.0)\n",command_line_dynamics_cyclic_dead_zone);
	fprintf(f,"dyal=%3.1f         # yaw altitude loss (default = 5.0)\n",command_line_dynamics_yaw_altitude_loss);
	fprintf(f,"debug_show_force_vectors=%d   # show force vectors on own helicopter for debuging purposes\n", get_global_dynamics_options_draw_flight_path());
	fprintf(f,"\n[Miscellaneous]\n");
	fprintf(f,"goto=%d              # Activates \"GOTO\" teleport button on the campaign map.\n",command_line_planner_goto_button);
	fprintf(f,"vfm=%d               # vector flight model, activates viewer or \"UFO\" flight mode.\n",command_line_vector_flight_model);
	fprintf(f,"psr=%d               # player start rank for new pilots\n",command_line_player_start_rank);
	fprintf(f,"ns=%d                # Bypass soundcard, useful for tracking hardware conflicts\n",command_line_no_sound);
	fprintf(f,"hdwrbuf=%d           # Number of hardware buffers to use for sound (0 to use software only)\n",command_line_sound_hdwrbuf); //VJ 050904 added "for sound"
	fprintf(f,"mta=%d               # The maximum multiplier allowed for time acceleration (default - 4)\n",command_line_max_time_acceleration);
	fprintf(f,"nomcm=%d             # no mission complete music\n",command_line_no_mission_complete_music);
//VJ 060209 re-organized in groups with more or less the same meaning
	fprintf(f,"\n[MODIFICATIONS]\n");
	fprintf(f,"[WUT]\n");
	fprintf(f,"wut=%s               # supply a filename of a wut text file here\n",WUT_filename);
	fprintf(f,"\n[Wideview]\n");
	fprintf(f, "g-force_head_movement=%.1f                # g-forces move head in wideview (default 0.0, off = 0.0, normal = 1.0, other values adjust amount of head movement)\n", command_line_g_force_head_movment_modifier);
	fprintf(f, "comanche_pilot=%.3f,%.3f,%.3f,%.3f        #wideview pilot position\n",wide_cockpit_position[WIDEVIEW_COMANCHE_PILOT  ].x,wide_cockpit_position[WIDEVIEW_COMANCHE_PILOT  ].y,wide_cockpit_position[WIDEVIEW_COMANCHE_PILOT  ].z,wide_cockpit_position[WIDEVIEW_COMANCHE_PILOT  ].p);
	fprintf(f, "comanche_co-pilot=%.3f,%.3f,%.3f,%.3f  #wideview co-pilot position\n",wide_cockpit_position[WIDEVIEW_COMANCHE_COPILOT].x,wide_cockpit_position[WIDEVIEW_COMANCHE_COPILOT].y,wide_cockpit_position[WIDEVIEW_COMANCHE_COPILOT].z,wide_cockpit_position[WIDEVIEW_COMANCHE_COPILOT].p);
	fprintf(f, "hokum_pilot=%.3f,%.3f,%.3f,%.3f           #wideview pilot position\n",wide_cockpit_position[WIDEVIEW_HOKUM_PILOT     ].x,wide_cockpit_position[WIDEVIEW_HOKUM_PILOT     ].y,wide_cockpit_position[WIDEVIEW_HOKUM_PILOT     ].z,wide_cockpit_position[WIDEVIEW_HOKUM_PILOT     ].p);
	fprintf(f, "hokum_co-pilot=%.3f,%.3f,%.3f,%.3f     #wideview co-pilot position\n",wide_cockpit_position[WIDEVIEW_HOKUM_COPILOT   ].x,wide_cockpit_position[WIDEVIEW_HOKUM_COPILOT   ].y,wide_cockpit_position[WIDEVIEW_HOKUM_COPILOT   ].z,wide_cockpit_position[WIDEVIEW_HOKUM_COPILOT   ].p);
	fprintf(f, "apache_pilot=%.3f,%.3f,%.3f,%.3f          #wideview pilot position\n",wide_cockpit_position[WIDEVIEW_APACHE_PILOT    ].x,wide_cockpit_position[WIDEVIEW_APACHE_PILOT    ].y,wide_cockpit_position[WIDEVIEW_APACHE_PILOT    ].z,wide_cockpit_position[WIDEVIEW_APACHE_PILOT    ].p);
	fprintf(f, "havoc_pilot=%.3f,%.3f,%.3f,%.3f           #wideview pilot position\n",wide_cockpit_position[WIDEVIEW_HAVOC_PILOT     ].x,wide_cockpit_position[WIDEVIEW_HAVOC_PILOT     ].y,wide_cockpit_position[WIDEVIEW_HAVOC_PILOT     ].z,wide_cockpit_position[WIDEVIEW_HAVOC_PILOT     ].p);	
	//VJ 060212 hud info mod
	fprintf(f, "hud_code=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d	#hud code for 4 gunships\n",
		hud_code[0][0],hud_code[0][1],hud_code[0][2],
		hud_code[1][0],hud_code[1][1],hud_code[1][2],
		hud_code[2][0],hud_code[2][1],hud_code[2][2],
		hud_code[3][0],hud_code[3][1],hud_code[3][2]);

	fprintf(f,"\n[Gameplay]\n");	
	fprintf(f,"faa=%d                  # fligh any aircraft, def = 1 (on)\n",command_line_fly_any_airplane);
	fprintf(f,"radarinf=%d             # infantry no longer visible on radar, def = 1 (on)\n",command_line_ground_radar_ignores_infantry);
	fprintf(f,"grstab=%d               # ground stabilisation of FLIR, def = 1 (on)\n",command_line_ground_stabilisation_available);
	fprintf(f,"manual_laser/radar=%d   # have to manually enable and disable radar and laser, def = 0 (off)\n",command_line_manual_laser_radar);
	fprintf(f,"targeting_system_auto_page = %d   # changing targeting system will also bring up the targeting systems MFD page. def = 1 (on)\n", command_line_targeting_system_auto_page);
	fprintf(f,"camcom=%d               # Activates the Campaign Commander\n",command_line_camcom); // Jabberwock 031007
	fprintf(f,"campaign_map_mode=%d    # 1 = default resolution and 2 is high resolution map (only for fast PCs\n",command_line_campaign_map);
	fprintf(f,"campaign_map_palette=%d # Which palette to use for the new campaign map.  1 is the default shades from green via red to white, 2 is more like a paper map\n",command_line_campaign_map_palette);
	fprintf(f,"map_update_interval=%d  # How often (in seconds) enemy units are updated on campaign map  120 seconds is the default\n",command_line_campaign_map_update_interval);
	fprintf(f,"destgt=%d               # Activates designated target list\n",command_line_designated_targets); // Jabberwock 031107
	fprintf(f,"cannontrack=%d          # Cannon tracking boresight (def=1, 0 = no tracking, 1 = track if no acq, 2 = track in IHADSS/HIDSS/HMS \n",command_line_cannontrack);	// Jabberwock 050120 Cannon tracking

	fprintf(f,"\n[Joysticks and TIR]\n");	
	fprintf(f,"eopann=%d            # joystick no. used for FLIR panning\n",command_line_eo_pan_joystick_index);
	fprintf(f,"eopanv=%d            # joystick DirectX axis used for vertical FLIR panning\n",command_line_eo_pan_vertical_joystick_axis+1);   //VJ 030531 added +1
	fprintf(f,"eopanh=%d            # joystick DirectX axis used for horizontal FLIR panning\n",command_line_eo_pan_horizontal_joystick_axis+1); //VJ 030531 added +1
	fprintf(f,"eozoomn=%d           # joystick no. used for FLIR zoom\n",command_line_eo_zoom_joystick_index);
	fprintf(f,"eozoomax=%d          # joystick DirextX axis used for FLIR zoom\n",command_line_eo_zoom_joystick_axis+1);  //VJ 030531 added +1
	fprintf(f,"cyclicn=%d           # Joystick no. for the cyclic\n",command_line_cyclic_joystick_index);
	fprintf(f,"cyclich=%d           # Joystick DirectX axis for cyclic horizontal\n",command_line_cyclic_joystick_x_axis+1);  //VJ 030531 added +1
	fprintf(f,"cyclicv=%d           # Joystick DirectX axis for cyclic vertical\n",command_line_cyclic_joystick_y_axis+1);   //VJ 030531 added +1
	fprintf(f,"nonlinear-cyclic=%d  # Use non-linear control for cyclic. Less sensitive around center. 1 = On (default), 0 = off\n", command_line_nonlinear_pedals);
	fprintf(f,"collectiven=%d       # Joystick no. for the collective\n",command_line_collective_joystick_index);
	fprintf(f,"collectiveax=%d      # Joystick DirectX acis for the collective\n",command_line_collective_joystick_axis+1);  //VJ 030531 added +1
	fprintf(f,"nonlinear-pedals=%d  # Use non-linear control for pedals. Gives finer around center. 1 = On (default), 0 = off\n", command_line_nonlinear_cyclic);
	fprintf(f,"nonlinear-collective-zone1=%.2f   # Putting the controller at this position will give 60%% collective. 0.0 to use linear collective. Valid values are in range 0.0 to 1.0, default is 0.3.\n", command_line_collective_zone_1_limit);
	fprintf(f,"nonlinear-collective-zone2=%.2f   # Putting the controller at this position will give 100%% collective (max is 120%%). 0.0 to use linear collective. Valid values are in range from nonlinear-collective-zone1 to 1.0, default is 0.7.\n", command_line_collective_zone_2_limit);
	fprintf(f,"ruddern=%d           # Joystick no. for the rudder\n",command_line_rudder_joystick_index);
	fprintf(f,"rudderax=%d          # Joystick DirectX axis for the rudder\n",command_line_rudder_joystick_axis+1);   //VJ 030531 added +1
	fprintf(f,"nonlinear-pedals=%d  # Use non-linear control for pedals. Gives finer around center. 1 = On (default), 0 = off\n", command_line_nonlinear_pedals);
	fprintf(f,"joylookn=%d          # joystick no. used for joystick look\n",command_line_joylook_joystick_index); //Jabberwock 031104
	fprintf(f,"joylookh=%d          # joystick DirectX axis used for horizontal joystick look\n",command_line_joylookh_joystick_axis+1);   //Jabberwock 031104
	fprintf(f,"joylookv=%d          # joystick DirectX axis used for vertical joystick look\n",command_line_joylookv_joystick_axis+1); //Jabberwock 031104
	fprintf(f,"joylookst=%d         # joystick look step (min=1,def=30,max=100)\n",command_line_joylook_step); //Jabberwock 031104
	fprintf(f,"reverse_pedal=%d		# reversed pedal input\n",command_line_reverse_pedal);	// Retro 17Jul2004
	fprintf(f,"external_trackir=%d  # if TrackIR is active, let it control external view too\n",command_line_external_trackir); // Retro 31Oct2004
	fprintf(f,"external_trackir_dir=%d  # Can be used to invert the view direction of the external TIR\n",command_line_external_trackir_direction); // Retro 31Jan2005
	fprintf(f,"msl=%d               # activates mouselook, and TrackIR when present. '0' is OFF, '1' is internal-only, '2' is external-only, '3' is both.\n",command_line_mouse_look);
	fprintf(f,"msls=%d              # mouselook speed when activated (def=15, must be > 0) otherwise POV speed (min=1,def=13,max=20)\n",command_line_mouse_look_speed);
	fprintf(f,"TIR_6DOF=%d          # Enables support for TrackIR vector in the hokum and comanche\n",command_line_TIR_6DOF); // Retro 6Feb2005

	fprintf(f,"\n[Graphics and textures]\n");
	fprintf(f,"minfov=%d            # general field of view minimum, linked to key '7', normal fov (60) = key '8'\n",command_line_min_fov);
	fprintf(f,"maxfov0=%d            # general field of view maximum for Apache pits, linked to key '9'\n",command_line_max_fov0);
	fprintf(f,"maxfov1=%d            # general field of view maximum for Havoc pits, linked to key '9'\n",command_line_max_fov1);
	fprintf(f,"maxfov2=%d            # general field of view maximum for Comanche pits, linked to key '9'\n",command_line_max_fov2);
	fprintf(f,"maxfov3=%d            # general field of view maximum for Hokum-B pits, linked to key '9'\n",command_line_max_fov3);	
	fprintf(f,"high_lod_hack=%d     # EXPERIMENTAL! Enables highest level-of-detail models at far distances. Nice for higher FOVs, bad for FPS (esp. near cities)\n",command_line_high_lod_hack);	// Retro 31Oct2004
	fprintf(f,"dwash=%d             # visible rotor downwash (dust), def = 1 (on)\n",command_line_downwash);
	fprintf(f,"restricted_nvg_fov=%d        # restrict night vision field of view by shading edge of screen, def = 1 (on)\n", command_line_restricted_nvg_fov);
	fprintf(f,"colourmfd=%d         # MFDs will use colour when available, def = 1 (on)\n",command_line_colour_mfd);
//	fprintf(f,"highresmfd=%d        # high resolution mfd's, def = 1 (on)\n",command_line_high_res_mfd);
	fprintf(f,"highreshud=%d        # high resolution HUD, def = 1 (on)\n",command_line_high_res_hud);
	fprintf(f,"tsdrender=%d         # TSD render options (0-4) def = 0 (contours only)\n",command_line_tsd_render_mode);
	fprintf(f,"tsdpalette=%d        # TSD palette options (0-2) def = 0 \n",command_line_tsd_palette);
	fprintf(f,"tsdenemy=%d          # TSD showing enemy colours (red, blue) def = 0 (off)\n",command_line_tsd_enemy_colours);
	fprintf(f,"tsddetail=%d          # TSD in high detail, def = 0 (off)\n",global_tsd_detail); // VJ 061215 detailed TSD
	fprintf(f,"3d_cockpit=%d        # EXPERIMENTAL! Draws a 3d apache cockpit (wide_view and MFD close-up (F3 and F4) disabled)\n",command_line_3d_cockpit);	// VJ 050101
	fprintf(f,"texture_colour=%d    # Use texture colours directly. WARNING: only use with correct texture packs (def=0) \n",command_line_texture_colour);	//VJ 050303 texture colour mod
	fprintf(f,"texture_filtering=%d  # Texture blending, reacts to Anisotropic filter setting. EXPERIMENTAL (def=0) \n",global_anisotropic);	//VJ 050530 AF filtering on/off
	fprintf(f,"mipmapping=%d        # Use mipmnapped textures (dds files). WARNING: only use with correct texture packs (def=0) \n",global_mipmapping);	//VJ 050530 mipmapping
	fprintf(f,"dynamic_water=%d     # Use dynamic water textures (def=0) \n",global_dynamic_water);	//VJ 050817 dynamic water textures
	fprintf(f,"night_light=%3.1f     # Make night light levels darker (fraction 0 (dark) to 1 default light) \n",global_night_light_level);	//VJ 060920 night light levels
	fprintf(f,"persistent_smoke=%d   # Make smoke from burning targets keep burning for a long time (CPU intensive)\n", command_line_persistent_smoke);
	fprintf(f,"wobbly-camera=%d     # If enabled (=1) will make movement of external cameras wobbly (and smoother)\n", command_line_wobbly_camera);
	
	fprintf(f,"\n[Misc]\n");
	fprintf(f,"filter=%d            # Turns on session filtering\n",command_line_session_filter); // Jabberwock 031210
	fprintf(f,"autosave=%d          # Autosave every n minutes or 0 not to autosave\n", command_line_autosave / 60); //Casm 17JUN05 Autosave option
	fprintf(f,"dfr=%d               # display framerate (0 = off (default), 1 = on, 2 = log to file \"framerate.txt\")\n",command_line_framerate);
	fprintf(f,"MEMEXPORT=%d         # enables export of cockpit information to a shared memory area\n", command_line_shared_mem_export);
	fprintf(f,"export_mfd=%d               # mfd export on multimon systems (0 = off (default), 1 = on\n",command_line_export_mfd);
	fprintf(f,"export_mfd_adapter=%d               # graphicadapter for mfd export(0=first, 1=second, ...)\n",command_line_export_mfd_adapter);
	fprintf(f,"export_mfd_screen_width=%d               # resolution of export screen (width)\n",command_line_export_mfd_screen_width);
	fprintf(f,"export_mfd_screen_height=%d               # resolution of export screen (height)\n",command_line_export_mfd_screen_height);

	fprintf(f,"export_mfd_left_pos=%d,%d,%d,%d               # left mfd position\n",command_line_export_mfd_left_pos[0],
			command_line_export_mfd_left_pos[1],command_line_export_mfd_left_pos[2],command_line_export_mfd_left_pos[3]);
	fprintf(f,"export_mfd_right_pos=%d,%d,%d,%d               #  right mfd position\n",command_line_export_mfd_right_pos[0],
			command_line_export_mfd_right_pos[1],command_line_export_mfd_right_pos[2],command_line_export_mfd_right_pos[3]);
	fprintf(f,"export_mfd_single_pos=%d,%d,%d,%d               #  single (havoc) mfd position\n",command_line_export_mfd_single_pos[0],
			command_line_export_mfd_single_pos[1],command_line_export_mfd_single_pos[2],command_line_export_mfd_single_pos[3]);
	fprintf(f,"[end of file]\n");

//Retro27NovDEAD	fprintf(f,"keymap=%d            # key mapping, def = 0 (off)\n",command_line_key_mapping);

	fclose(f);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
