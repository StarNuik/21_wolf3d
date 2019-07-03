/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:04:22 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 01:16:34 by sbosmer          ###   ########.fr       */
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

void		render_gui(t_data *d)
{
	int		score[6];
	int		health[3];
	int		ammo[2];
	int		qt;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_gui);
	static_itoa(d->scene.player.score, score, 6);
	static_itoa(d->scene.player.health, health, 3);
	static_itoa(d->scene.player.ammo, ammo, 2);
	qt = -1;
	while (++qt < 6)
		draw_number(d, GUI_SCORE_OFFSET + qt * GUI_NUM_WIDTH, score[qt]);
	qt = -1;
	while (++qt < 3)
		draw_number(d, GUI_HEALTH_OFFSET + qt * GUI_NUM_WIDTH, health[qt]);
	qt = -1;
	while (++qt < 2)
		draw_number(d, GUI_AMMO_OFFSET + qt * GUI_NUM_WIDTH, ammo[qt]);
	draw_pistol(d);
	SDL_SetRenderTarget(d->sdl.ren, NULL);
}