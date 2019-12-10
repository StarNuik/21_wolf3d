/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:04:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/12/10 20:15:00 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft.h"
# include <SDL.h>
# include "stb_image.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TEX_WIDTH 711
# define TEX_HEIGHT 400
# define TARGET_FPS 24
# define TARGET_MS (1000 / (int)TARGET_FPS)

# define RAYCAST_MAX_DISTANCE 45
# define RAYCAST_RESOLUTION 0.01f
# define FIELD_OF_VIEW (M_PI / 2)

# define CONTROL_ROTATION_DELTA 0.001f
# define CONTROL_MOVEMENT_DELTA 0.18f
# define CONTROL_COLLISION_DIST 0.3f
# define CONTROL_SPEEDHACK 5

# define WEAP_ANIM_DURATION 10
# define HIT_CIRCLE_RADIUS_SQUARED 0.25
# define WEAP_PISTOL_DAMAGE 7
# define WEAP_SMG_DAMAGE 14
# define WEAP_BFG_DAMAGE 20

# define TEXTURE_POOL_SIZE 32
# define SOUND_POOL_SIZE 8

# define GUI_ZOOM_FACTOR ((float)TEX_HEIGHT / 320.f)
# define GUI_BG_HEIGHT 90
# define GUI_NUM_WIDTH 18
# define GUI_NUM_HEIGHT 36
# define GUI_NUM_Y 345
# define GUI_SCORE_OFFSET 102
# define GUI_HEALTH_OFFSET 370
# define GUI_AMMO_OFFSET 465
# define GUI_WICON_X 570
# define GUI_WICON_Y 329
# define GUI_WICON_W 107
# define GUI_WICON_H 53
# define GUI_GUN_SIZE 300
# define GUI_GUN_X 205
# define GUI_GUN_Y 10

typedef struct			s_rend_obj
{
	t_vector3			pos;
	int					tex_id;
	float				dist_to_player;
}						t_rendobj;

# define OBJ_CHAND	(t_object){{V3_ZERO, 13, 0.f}, 0, -1, 0, 1, 0}
# define OBJ_LAMP	(t_object){{V3_ZERO, 14, 0.f}, 0, -1, 0, 1, 0}
# define OBJ_TABLE	(t_object){{V3_ZERO, 15, 0.f}, 20, 28, 0, 0, 0}
# define OBJ_TREASU	(t_object){{V3_ZERO, 16, 0.f}, 0, -1, 1, 1, 500}
# define OBJ_BUSH	(t_object){{V3_ZERO, 17, 0.f}, 0, -1, 0, 0, 0}
# define OBJ_TREE	(t_object){{V3_ZERO, 18, 0.f}, 20, 19, 0, 0, 0}
# define OBJ_HEALTH	(t_object){{V3_ZERO, 26, 0.f}, 0, -1, 2, 1, 25}
# define OBJ_AMMO	(t_object){{V3_ZERO, 27, 0.f}, 0, -1, 3, 1, 5}
# define OBJ_NULL	(t_object){{V3_ZERO, -1, 0.f}, 0, -1, -1, -1, -1}

typedef struct			s_object
{
	t_rendobj			rend;
	int					health;
	int					broke_tex_id;
	char				pickup;
	char				walkthrough;
	int					value;
}						t_object;

struct s_data;
struct s_enemy;

# define ENEMY_TEST (t_enemy){{V3_ZERO, 29, 0.f}, 500, .1f, &ai_test, NULL}
# define ENEMY_NULL (t_enemy){{V3_ZERO, -1, 0.f}, -1, -1.f, NULL, NULL}

typedef struct			s_enemy
{
	t_rendobj			rend;
	int					health;
	float				speed;
	void				(*logic)(struct s_data*, struct s_enemy*);
	t_array				*path;
}						t_enemy;

typedef struct			s_astarnode
{
	struct s_astarnode	*parent;
	int					g;
	int					h;
	int					f;
	int					x;
	int					y;
	char				walkable;
}						t_anode;

typedef struct			s_astar
{
	t_array				*map;
	int					size_x;
	int					size_y;
	t_array				*open;
	t_array				*closed;
	t_anode				*target;
}						t_astar;

typedef struct			s_castret
{
	float				dist;
	char				type;
	t_vector3			hit;
}						t_raycast;

typedef struct			s_shothit
{
	t_rendobj			*closest;
	t_vector3			ray_dir;
	t_vector3			ray_start;
}						t_shotdata;

typedef struct			s_controls
{
	int					mouse_rel_x;
	int					mouse_rel_y;
	char				lmb;
	char				forward;
	char				backward;
	char				left;
	char				right;
	char				zharko;
	char				noclip;
	char				speedhack;
}						t_rols;

typedef struct			s_player
{
	t_vector3			pos;
	float				look_angle;
	int					score;
	int					ammo;
	int					health;
	char				selected_gun;
	char				anim_frame;
	char				pistol_shot;
}						t_player;

typedef struct			s_texture
{
	unsigned char		*data;
	int					width;
	int					height;
	int					channels;
	int					type;
}						t_exture;

typedef struct			s_sound
{
	SDL_AudioDeviceID	dev;
	SDL_AudioSpec		spec;
	Uint8				*buffer;
	Uint32				length;
	Uint8				*pos;
	int					len_left;
}						t_sound;

typedef struct			s_scene
{
	t_astar				*astar;
	t_player			player;
	t_array				*map_loaded;
	int					map_x;
	int					map_y;
	int					track_playing;
	t_array				*object_arr;
	t_array				*destr_object_arr;
	t_array				*pickup_arr;
	t_array				*enemy_arr;
}						t_scene;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*ren;
	SDL_Texture			*tex_bg;
	SDL_Texture			*tex_wall;
	SDL_Texture			*tex_sprite;
	SDL_Texture			*tex_gui_bg;
	SDL_Texture			*tex_gui;
	SDL_Event			event;
	char				mouse_move_processed;
}						t_sdl;

typedef struct			s_frame_control
{
	unsigned int		last_message;
	unsigned int		frame_start;
}						t_frames;

typedef struct			s_renderer
{
	t_raycast			rays[TEX_WIDTH];
	t_array				*object_order;
	t_array				*sprite_queue;
}						t_rend;

typedef struct			s_data
{
	t_sdl				sdl;
	t_array				*map_origin;
	t_scene				scene;
	t_rols				ctrl;
	t_exture			tex_pool[TEXTURE_POOL_SIZE];
	t_sound				sound_pool[SOUND_POOL_SIZE];
	t_frames			pr;
	t_rend				rend;
	unsigned int		ticks;
}						t_data;

void					try_exit(t_data *d);
void					map_exit(int code);

void					init(t_data *d);
void					init_sdl(t_data *d);
void					read_map(t_data *d, char *path);
char					parse_object(t_data *d, char *idk, int x, int y);
char					parse_enemy(t_data *d, char *idk, int x, int y);
void					read_audio(t_data *d);
void					read_textures(t_data *d);

void					general_pipe(t_data *d);
void					ray_viewport(t_data *d);
void					player_pipe(t_data *d);
void					enemy_pipe(t_data *d);
void					render_pipe(t_data *d);
void					event_router(t_data *d);
void					wait_for_next_frame(t_data *d);

float					raycast_basic(t_data *d, t_vector3 pos, float angle);
t_raycast				raycast(t_data *d, t_vector3 pos, float angle);

void					move_player(t_data *d, t_vector3 dirv);
void					player_shoot(t_data *d);
void					test_pickups(t_data *d);
void					cast_shot(t_data *d, int damage);
void					damage_object(t_data *d, t_object *object, int damage);

void					ai_test(t_data *d, t_enemy *self);

void					render_walls(t_data *d);
void					render_sprites(t_data *d);
void					draw_bg(t_data *d);
void					draw_gui_bg(t_data *d);
void					render_gui(t_data *d);
void					draw_weapon(t_data *d);
char					spritequeue_add(t_data *d, t_rendobj *obj);
void					spritequeue_remove(t_data *d, t_rendobj *obj);
void					sort_sprites(t_data *d);

void					play_audio(t_data *d, int num);
void					stop_audio(t_data *d, int num);
void					audio_call(void *userdata,
	unsigned char *stream, int len);

void					mouse_press_hook(t_data *d);
void					mouse_release_hook(t_data *d);
void					mouse_move_hook(t_data *d);

void					check_walkable(const size_t id, const long long val,
	void *test_val, void *walkable);
int						get_dist(const t_anode a, const t_anode b);
t_anode					*get_cheapest_node(t_astar *astar);
void					work_neighbour(const size_t id, const long long val,
	void *astar_v, void *node_v);
void					clean_node(const size_t id, const long long val);
void					clear(t_astar *astar);
t_array					*retrace_path(t_astar *astar);
void					get_neighbours(t_astar *astar, t_array *neighbours,
	t_anode *node);
t_array					*calc_path(t_astar *astar);
t_array					*astar_get_path(t_astar *astar, const t_vector3 start,
	const t_vector3 target);
t_astar					*astar_init(t_array *map, t_array *walkable_mask,
	const int size_x, const int size_y);

void					static_itoa(int num, int a[], int ct);

t_astar					*astar_init(t_array *map, t_array *walkable_mask,
	int size_x, int size_y);
t_array					*astar_get_path(t_astar *astar, t_vector3 start,
	t_vector3 target);

#endif
