/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_router.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:35:53 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/01 14:15:08 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		key_press_hook(t_data *d)
{
	SDL_Keycode		key;

	key = d->sdl.event.key.keysym.sym;
	(key == SDLK_ESCAPE ? try_exit(d) : 0);
	(key == SDLK_w ? d->ctrl.forward = 1 : 0);
	(key == SDLK_s ? d->ctrl.backward = 1 : 0);
	(key == SDLK_a ? d->ctrl.left = 1 : 0);
	(key == SDLK_d ? d->ctrl.right = 1 : 0);
	(key == SDLK_q ? stop_audio(d, 0) : 0);
	(key == SDLK_e ? play_audio(d, 0) : 0);
	(key == SDLK_1 ? d->ctrl.noclip = !d->ctrl.noclip : 0);
	(key == SDLK_2 ? d->ctrl.speedhack = !d->ctrl.speedhack : 0);
	(key == SDLK_3 ? d->ctrl.zharko = 1 : 0);
	(key == SDLK_3 ? play_audio(d, 2) : 0);
}

void		key_release_hook(t_data *d)
{
	SDL_Keycode		key;

	key = d->sdl.event.key.keysym.sym;
	if (key == SDLK_w)
		d->ctrl.forward = 0;
	if (key == SDLK_s)
		d->ctrl.backward = 0;
	if (key == SDLK_a)
		d->ctrl.left = 0;
	if (key == SDLK_d)
		d->ctrl.right = 0;
}

void		mouse_move_hook(t_data *d)
{
	d->sdl.mouse_move_processed = 1;
	d->ctrl.mouse_rel_x = d->sdl.event.motion.xrel;
	d->ctrl.mouse_rel_y = d->sdl.event.motion.yrel;
}

void		walk_sound_hack(t_data *d)
{
	if ((d->ctrl.forward || d->ctrl.backward) && !(d->ctrl.forward && d->ctrl.backward))
		play_audio(d, 1);
	if ((!d->ctrl.forward && !d->ctrl.backward) || (d->ctrl.forward && d->ctrl.backward))
		stop_audio(d, 1);
}

void		event_router(t_data *d)
{
	d->sdl.mouse_move_processed = 0;
	while (SDL_PollEvent(&d->sdl.event))
	{
		if (d->sdl.event.type == SDL_QUIT)
			try_exit(d);
		if (d->sdl.event.type == SDL_KEYDOWN)
			key_press_hook(d);
		if (d->sdl.event.type == SDL_KEYUP)
			key_release_hook(d);
		if (d->sdl.event.type == SDL_MOUSEMOTION)
			mouse_move_hook(d);
	}
	if (!d->sdl.mouse_move_processed)
	{
		d->ctrl.mouse_rel_x = 0;
		d->ctrl.mouse_rel_y = 0;
	}
	walk_sound_hack(d);
}