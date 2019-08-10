/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui_bg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:40:41 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 16:27:38 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_gui_bg(t_data *d)
{
	int				x;
	int				y;
	int				tex_id;
	const t_exture	tex = d->tex_pool[20];

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_gui_bg);
	SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(d->sdl.ren);
	x = -1;
	while (++x < TEX_WIDTH)
	{
		y = TEX_HEIGHT - 90 - 1;
		while (++y < TEX_HEIGHT)
		{
			tex_id = ((float)x / (float)TEX_WIDTH) * (float)tex.width;
			tex_id += (int)(((float)(y - TEX_HEIGHT + 90) / 90.f)
				* (float)tex.height) * tex.width;
			SDL_SetRenderDrawColor(d->sdl.ren, tex.data[tex_id * 3],
				tex.data[tex_id * 3 + 1], tex.data[tex_id * 3 + 2], 0xff);
			SDL_RenderDrawPoint(d->sdl.ren, x, y);
		}
	}
	SDL_SetRenderTarget(d->sdl.ren, NULL);
}
