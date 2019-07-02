/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:04:22 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/02 23:52:39 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_number(t_data *d, const int in_x, const int num)
{
	const t_exture	tex = d->tex_pool[21];
	int				tex_id;
	int				x;
	int				y;

	x = in_x - 1;
	// printf("%d\n", num);
	while (++x < in_x + GUI_NUM_WIDTH)
	{
		y = GUI_NUM_Y - 1;
		while (++y < GUI_NUM_Y + GUI_NUM_HEIGHT)
		{
			tex_id = (int)((float)(x - in_x) / (float)GUI_NUM_WIDTH * 8.f) + num * 8;
			tex_id += (int)((float)(y - GUI_NUM_Y) / (float)GUI_NUM_HEIGHT * 16.f) * tex.width;
			SDL_SetRenderDrawColor(d->sdl.ren, tex.data[tex_id * 3], tex.data[tex_id * 3 + 1], tex.data[tex_id * 3 + 2], 0xff);
			// SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(d->sdl.ren, x, y);
		}
	}
	(void)d;
	(void)in_x;
	(void)num;
}