/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:59:06 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/27 14:34:56 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_sprite(t_data *d, int in_x, int size, int tex_id)
{
	t_exture	tex;
	int			x;
	int			y;

	tex = d->tex_pool[tex_id];

	SDL_SetRenderDrawColor(d->sdl.ren, 200, 200, size, 0xff);
	x = in_x - size / 2 - 1;
	while (++x < in_x + size / 2)
	{
		y = TEX_HEIGHT / 2 - size / 2 - 1;
		while (++y < TEX_HEIGHT / 2 + size / 2)
		{
			SDL_RenderDrawPoint(d->sdl.ren, x, y);
		}
	}
	(void)tex_id;
}