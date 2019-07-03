/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 01:15:28 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 02:55:55 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_pistol(t_data *d)
{
	const t_exture	tex = d->tex_pool[22];
	const int		animFrame = d->scene.player.pistol_frame / 2 % 5;
	int				x;
	int				y;
	int				tex_id;

	x = GUI_GUN_X - 1;
	while (++x < GUI_GUN_SIZE + GUI_GUN_X)
	{
		y = GUI_GUN_Y - 1;
		while (++y < GUI_GUN_SIZE + GUI_GUN_Y)
		{
			tex_id = (int)((float)(x - GUI_GUN_X) / (float)GUI_GUN_SIZE * 64.f) + animFrame * 64;
			tex_id += (int)((float)(y - GUI_GUN_Y) / (float)GUI_GUN_SIZE * 64.f) * tex.width;
			if ((tex.data[tex_id * 3] << 16) + (tex.data[tex_id * 3 + 1] << 8) + tex.data[tex_id * 3 + 2] == 0x980088)
				continue ;
			SDL_SetRenderDrawColor(d->sdl.ren, tex.data[tex_id * 3], tex.data[tex_id * 3 + 1], tex.data[tex_id * 3 + 2], 0xff);
			SDL_RenderDrawPoint(d->sdl.ren, x, y);
		}
	}
	if (d->scene.player.pistol_frame)
		d->scene.player.pistol_frame++;
	if (d->scene.player.pistol_frame >= PISTOL_ANIM_DURATION)
	{
		d->scene.player.pistol_frame = 0;
		stop_audio(d, 3);
	}
	(void)d;
}