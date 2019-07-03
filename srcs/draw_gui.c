/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:04:22 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 05:03:23 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_weapon_icon(t_data *d)
{
	const t_exture	tex = d->tex_pool[22];
	int				tex_id;
	int				x;
	int				y;

	x = GUI_WICON_X - 1;
	// printf("%d\n", num);
	while (++x < GUI_WICON_X + GUI_WICON_W)
	{
		y = GUI_WICON_Y - 1;
		while (++y < GUI_WICON_Y + GUI_WICON_H)
		{
			tex_id = (int)((float)(x - GUI_WICON_X) / (float)GUI_WICON_W * 48.f) + d->scene.player.selected_gun * 48;
			tex_id += (int)((float)(y - GUI_WICON_Y) / (float)GUI_WICON_H * 24.f) * tex.width;
			SDL_SetRenderDrawColor(d->sdl.ren, tex.data[tex_id * 3], tex.data[tex_id * 3 + 1], tex.data[tex_id * 3 + 2], 0xff);
			SDL_RenderDrawPoint(d->sdl.ren, x, y);
		}
	}
}

void		draw_number(t_data *d, const int in_x, const int num)
{
	const t_exture	tex = d->tex_pool[21];
	int				tex_id;
	int				x;
	int				y;

	x = in_x - 1;
	while (++x < in_x + GUI_NUM_WIDTH)
	{
		y = GUI_NUM_Y - 1;
		while (++y < GUI_NUM_Y + GUI_NUM_HEIGHT)
		{
			tex_id = (int)((float)(x - in_x) / (float)GUI_NUM_WIDTH * 8.f) + num * 8;
			tex_id += (int)((float)(y - GUI_NUM_Y) / (float)GUI_NUM_HEIGHT * 16.f) * tex.width;
			SDL_SetRenderDrawColor(d->sdl.ren, tex.data[tex_id * 3], tex.data[tex_id * 3 + 1], tex.data[tex_id * 3 + 2], 0xff);
			SDL_RenderDrawPoint(d->sdl.ren, x, y);
		}
	}
}

void		render_gui(t_data *d)
{
	int		score[6];
	int		health[3];
	int		ammo[3];
	int		qt;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_gui);
	static_itoa(d->scene.player.score, score, 6);
	static_itoa(d->scene.player.health, health, 3);
	static_itoa(d->scene.player.ammo, ammo, 3);
	qt = -1;
	while (++qt < 6)
		draw_number(d, GUI_SCORE_OFFSET + qt * GUI_NUM_WIDTH, score[qt]);
	qt = -1;
	while (++qt < 3)
		draw_number(d, GUI_HEALTH_OFFSET + qt * GUI_NUM_WIDTH, health[qt]);
	qt = -1;
	while (++qt < 3)
		draw_number(d, GUI_AMMO_OFFSET + qt * GUI_NUM_WIDTH, ammo[qt]);
	draw_weapon_icon(d);
	draw_weapon(d);
	SDL_SetRenderTarget(d->sdl.ren, NULL);
}