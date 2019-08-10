/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:16:09 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 16:18:14 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		mouse_press_hook(t_data *d)
{
	if (d->sdl.event.button.button == SDL_BUTTON_LEFT)
		d->ctrl.lmb = 1;
}

void		mouse_release_hook(t_data *d)
{
	if (d->sdl.event.button.button == SDL_BUTTON_LEFT)
	{
		d->ctrl.lmb = 0;
		d->scene.player.pistol_shot = 0;
	}
}

void		mouse_move_hook(t_data *d)
{
	d->sdl.mouse_move_processed = 1;
	d->ctrl.mouse_rel_x = d->sdl.event.motion.xrel;
	d->ctrl.mouse_rel_y = d->sdl.event.motion.yrel;
}
