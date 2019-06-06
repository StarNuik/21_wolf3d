/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:04:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 09:28:33 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libft.h"
# include <stdio.h>
# include <SDL.h>
//? Be careful with this boi
# include "stb_image.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TEX_WIDTH 640
# define TEX_HEIGHT 480

# define RAYCAST_MAX_DISTANCE 20
# define RAYCAST_RESOLUTION 0.05
# define FIELD_OF_VIEW (M_PI / 2)
# define WALL_HEIGHT_MULT 0.9

# define CONTROL_ROTATION_DELTA 0.1
# define CONTROL_MOVEMENT_DELTA 0.12

# define TEXTURE_POOL_SIZE 16
# define DEBUG_MAP_SIZE 15

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_castret
{
	float			dist;
	char			type;
	t_vector3		hit;
}					t_raycast;

typedef struct		s_controls
{
	char			forward;
	char			backward;
	char			left;
	char			right;
}					t_rols;

typedef struct		s_player
{
	t_vector3		pos;
	float			lookAngle;
}					t_player;

typedef struct		s_texture
{
	unsigned char	*data;
	int				width;
	int				height;
	int				channels;
	int				type;
}					t_exture;

typedef struct		s_scene
{
	t_player		player0;
	t_array			*map_loaded;
}					t_scene;

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex_out;
	SDL_Event		event;
}					t_sdl;

typedef struct		s_data
{
	t_sdl			sdl;
	t_array			*map_origin;
	t_scene			scene;
	t_rols			ctrl;
	t_exture		tex_pool[TEXTURE_POOL_SIZE];
}					t_data;

void				init_sdl(t_data *d);
void				init(t_data *d);
void				try_exit(t_data *d);
t_array				*read_map(char *path);
void				general_pipe(t_data *d);
void				physics_pipe(t_data *d);
void				render_pipe(t_data *d);
void				draw_wall_simple(t_data *d, int x, int height);
void				draw_wall(t_data *d, int x, int height, t_raycast ray);
void				event_router(t_data *d);
void				read_textures(t_data *d);
t_raycast			raycast(t_data *d, t_vector3 pos, float angle);
float				raycast_basic(t_data *d, t_vector3 pos, float angle);

#endif