/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 01:32:05 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 09:22:47 by sbosmer          ###   ########.fr       */
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

	ray.hit.x = ray.hit.x - floorf(ray.hit.x + 0.5);
	ray.hit.y = ray.hit.y - floorf(ray.hit.y + 0.5);
	tex_x = (fabs(ray.hit.x) > fabs(ray.hit.y) ? ray.hit.x : ray.hit.y) * (float)tex.width;
	if (tex_x < 0)
		tex_x += tex.width;
	y = (TEX_HEIGHT - height) / 2;
	if (height > WIN_HEIGHT)
	{
		y = 0;
		height = WIN_HEIGHT;
	}
	qt = -1;
	while (++qt < height)
	{
		id = tex_x + (int)(((float)qt / (float)height) * (float)tex.height) * tex.width;
		SDL_SetRenderDrawColor(d->sdl.ren, tex.data[id * 3], tex.data[id * 3 + 1], tex.data[id * 3 + 2], 0x00);
		SDL_RenderDrawPoint(d->sdl.ren, x, y);
		y++;
	}
}
