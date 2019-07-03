/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 01:32:05 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 00:52:07 by sbosmer          ###   ########.fr       */
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

void		draw_wall(t_data *d, const int x, const int height, t_raycast ray)
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
	qt = ft_clamp(y - 1, 0, TEX_HEIGHT);
	while (++qt < ft_clamp(y + height, 0, TEX_HEIGHT))
	{
		id = tex_x + (int)((qt - y) / (float)height * tex.height) * tex.width;
		id = ft_clamp(id, 0, tex.width * tex.height - 1);
		SDL_SetRenderDrawColor(d->sdl.ren, tex.data[id * 3], tex.data[id * 3 + 1], tex.data[id * 3 + 2], 0xff);
		SDL_RenderDrawPoint(d->sdl.ren, x, qt);
	}
}

void		render_walls(t_data *d)
{
	int				x;
	float			height;
	t_raycast		ray;
	const float		angleDelta = (float)FIELD_OF_VIEW / (float)TEX_WIDTH;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_wall);
	x = TEX_WIDTH;
	while (--x >= 0)
	{
		ray = d->rend.rays[x];
		height = ray.dist * cos(angleDelta * x - FIELD_OF_VIEW / 2);
		height = (float)TEX_HEIGHT / height;
		draw_wall(d, x, height, ray);
		// x++;
	}
	SDL_SetRenderTarget(d->sdl.ren, NULL);
	// ft_putmem
}