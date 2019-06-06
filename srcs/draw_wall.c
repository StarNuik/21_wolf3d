/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 01:32:05 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 02:04:29 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_wall(t_data *d, int x, int height)
{
	int		y;

	// SDL_RenderDrawPoint(d->sdl.ren, rand() % 640, rand() % 480);
	y = (TEX_HEIGHT - height) / 2;
	// if (height > WIN_HEIGHT)
	// 	y = 0;
	while (height--)
	{
		SDL_RenderDrawPoint(d->sdl.ren, x, y);
		y++;
	}
}