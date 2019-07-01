/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:59:06 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/01 19:21:48 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_sprite(t_data *d, const int in_x, const int size, const t_object obj)
{
	const t_exture	tex = d->tex_pool[obj.tex_id];
	int				x;
	int				y;
	const float		dist = ft_v3dot2(ft_v3subtract(d->scene.player.pos, obj.pos));

	SDL_SetRenderDrawColor(d->sdl.ren, 200, 200, size, 0xff);
	x = ft_clamp(in_x - size / 2 - 1, 0, TEX_WIDTH);
	while (++x < ft_clamp(in_x + size / 2, 0, TEX_WIDTH))
	{
		y = TEX_HEIGHT / 2 - size / 2 - 1;
		if (x > 0 && x < TEX_WIDTH && dist < powf(d->rend.rays[x].dist, 2.0))
			while (++y < TEX_HEIGHT / 2 + size / 2)
			{
				SDL_RenderDrawPoint(d->sdl.ren, x, y);
			}
	}
	(void)tex;
}