/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 01:32:05 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/09 11:32:16 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_wall_simple(t_data *d, int x, int height)
{
	int		y;

	y = (TEX_HEIGHT - height) / 2;
	if (height > WIN_HEIGHT)
	{
		y = 0;
		height = WIN_HEIGHT;
	}
	while (height--)
	{
		SDL_RenderDrawPoint(d->sdl.ren, x, y);
		y++;
	}
}

void		draw_wall(t_data *d, int x, int height, t_raycast ray)
{
	int				y;
	t_exture		tex;
	int				tex_x;
	int				id;
	int				qt;

	tex = d->tex_pool[ray.type - 1];
	if (d->ctrl.zharko)
		tex = d->tex_pool[6];
	ray.hit.x = ray.hit.x - floorf(ray.hit.x + 0.5);
	ray.hit.y = ray.hit.y - floorf(ray.hit.y + 0.5);
	tex_x = (fabs(ray.hit.x) > fabs(ray.hit.y) ? ray.hit.x : ray.hit.y) * (float)tex.width;
	if (tex_x < 0)
		tex_x += tex.width;
	y = (TEX_HEIGHT - height) / 2;
	qt = -1;
	while (++qt < height)
	{
		id = tex_x + (int)(((float)qt / (float)height) * (float)tex.height) * tex.width;
		SDL_SetRenderDrawColor(d->sdl.ren, tex.data[id * 3], tex.data[id * 3 + 1], tex.data[id * 3 + 2], 0x00);
		SDL_RenderDrawPoint(d->sdl.ren, x, y);
		y++;
	}
}

void		draw_wall_sky(t_data *d, int x, int height, t_raycast ray)
{
	int				y;
	t_exture		tex;
	int				tex_x;
	int				id;
	int				qt;

	tex = d->tex_pool[ray.type - 1];
	if (d->ctrl.zharko)
		tex = d->tex_pool[6];
	ray.hit.x = ray.hit.x - floorf(ray.hit.x + 0.5);
	ray.hit.y = ray.hit.y - floorf(ray.hit.y + 0.5);
	tex_x = (fabs(ray.hit.x) > fabs(ray.hit.y) ? ray.hit.x : ray.hit.y) * (float)tex.width;
	if (tex_x < 0)
		tex_x += tex.width;
	y = (TEX_HEIGHT - height) / 2;
	qt = -1;
	while (++qt < TEX_HEIGHT)
	{
		if (qt < y)
			SDL_SetRenderDrawColor(d->sdl.ren, 0, 0, 80, 0x00);
		else if (qt > y + height)
			SDL_SetRenderDrawColor(d->sdl.ren, 30, 30, 30, 0x00);
		else
		{
			id = tex_x + (int)(((float)(qt - y - 1) / (float)height) * (float)tex.height) * tex.width;
			SDL_SetRenderDrawColor(d->sdl.ren, tex.data[id * 3], tex.data[id * 3 + 1], tex.data[id * 3 + 2], 0x00);
		}
		SDL_RenderDrawPoint(d->sdl.ren, x, qt);
	}
}

int			get_tex_num(t_vector3 hit)
{
	// t_vector3	center;
	int			res;

	// center.x = floorf(hit.x + 0.5) + 0.5;
	// center.y = floorf(hit.y + 0.5) + 0.5;
	// center.x = ;
	// center.y = ;
	hit.x = -hit.x + floorf(hit.x) + 0.5;
	hit.y = -hit.y + floorf(hit.y) + 0.5;
	// SDL_Log("%.3f %.3f", hit.x, hit.y);
	//? Can be un bugged if one adds simple y(x) = x solve algorithm
	hit = (t_vector3){hit.x * COS45 - hit.y * SIN45, hit.x * SIN45 + hit.y * COS45, 0.0};
	res = 0;
	if (hit.y >= 0.0)
		res -= 1;
	if (hit.y < 0.0)
		res += 1;
	if (hit.x >= 0.0)
		res -= 2;
	if (hit.x < 0.0)
		res += 2;
	return (res + 3);
}

void		draw_wall_subj(t_data *d, int x, int height, t_raycast ray)
{
	int				y;
	t_exture		tex;
	int				tex_x;
	int				id;
	int				qt;

	tex = d->tex_pool[get_tex_num(ray.hit)];

	ray.hit.x = ray.hit.x - floorf(ray.hit.x + 0.5);
	ray.hit.y = ray.hit.y - floorf(ray.hit.y + 0.5);
	tex_x = (fabs(ray.hit.x) > fabs(ray.hit.y) ? ray.hit.x : ray.hit.y) * (float)tex.width;
	if (tex_x < 0)
		tex_x += tex.width;
	y = (TEX_HEIGHT - height) / 2;
	qt = -1;
	while (++qt < TEX_HEIGHT)
	{
		if (qt < y)
			SDL_SetRenderDrawColor(d->sdl.ren, 0, 0, 80, 0);
		else if (qt > y + height)
			SDL_SetRenderDrawColor(d->sdl.ren, 30, 30, 30, 0);
		else
		{
			id = tex_x + (int)(((float)(qt - y - 1) / (float)height) * (float)tex.height) * tex.width;
			SDL_SetRenderDrawColor(d->sdl.ren, tex.data[id * 3], tex.data[id * 3 + 1], tex.data[id * 3 + 2], 0);
		}
		SDL_RenderDrawPoint(d->sdl.ren, x, qt);
	}
}
