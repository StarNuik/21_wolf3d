/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:16:51 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 16:20:01 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_bg(t_data *d)
{
	int		x;
	int		y;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_bg);
	SDL_SetRenderDrawColor(d->sdl.ren, 30, 30, 30, 0xff);
	SDL_RenderClear(d->sdl.ren);
	x = -1;
	while (++x < TEX_WIDTH)
	{
		y = -1;
		while (++y < TEX_HEIGHT)
		{
			SDL_SetRenderDrawColor(d->sdl.ren, 30, 30, 30, 0xff);
			if (y < TEX_HEIGHT / 2)
				SDL_SetRenderDrawColor(d->sdl.ren, 50, 50, 50, 0xff);
			SDL_RenderDrawPoint(d->sdl.ren, x, y);
		}
	}
	SDL_SetRenderTarget(d->sdl.ren, NULL);
}
