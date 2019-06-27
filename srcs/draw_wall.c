/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 01:32:05 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/27 13:15:43 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			get_tex_num(t_vector3 hit)
{
	int			res;

	hit.x = -hit.x + floorf(hit.x) + 0.5;
	hit.y = -hit.y + floorf(hit.y) + 0.5;
	if (hit.y >= hit.x && hit.y >= -hit.x)
		res = 0;
	else if (hit.y < hit.x && hit.y >= -hit.x)
		res = 1;
	else if (hit.y >= hit.x && hit.y < -hit.x)
		res = 2;
	else
		res = 3;
	return (res + 9);
}

void		draw_wall(t_data *d, int x, int height, t_raycast ray)
{
	int				y;
	t_exture		tex;
	int				tex_x;
	int				id;
	int				qt;

	if (ray.type == -1)
		tex = d->tex_pool[get_tex_num(ray.hit)];
	else if (d->ctrl.zharko)
		tex = d->tex_pool[8];
	else
		tex = d->tex_pool[ray.type - 1];
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
			SDL_SetRenderDrawColor(d->sdl.ren, 0, 0, 80, 0xff);
		else if (qt > y + height)
			SDL_SetRenderDrawColor(d->sdl.ren, 30, 30, 30, 0xff);
		else
		{
			id = tex_x + (int)((qt - y) / (float)height * tex.height) * tex.width;
			id = ft_clamp(id, 0, tex.width * tex.height - 1);
			SDL_SetRenderDrawColor(d->sdl.ren, tex.data[id * 3], tex.data[id * 3 + 1], tex.data[id * 3 + 2], 0xff);
		}
		SDL_RenderDrawPoint(d->sdl.ren, x, qt);
	}
}
