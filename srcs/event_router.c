/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_router.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:35:53 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/08 14:44:32 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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

void		key_press_hook(t_data *d)
{
	SDL_Keycode		key;

	key = d->sdl.event.key.keysym.sym;
	if (key == SDLK_ESCAPE)
		try_exit(d);
	if (key == SDLK_w)
		d->ctrl.forward = 1;
	if (key == SDLK_s)
		d->ctrl.backward = 1;
	if (key == SDLK_a)
		d->ctrl.left = 1;
	if (key == SDLK_d)
		d->ctrl.right = 1;
	if (key == SDLK_r)
	{
		d->ctrl.zharko = 1;
		play_audio(d, 2);
	}
	if (key == SDLK_q)
		stop_audio(d, 0);
	if (key == SDLK_e)
		play_audio(d, 0);
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
	while (SDL_PollEvent(&d->sdl.event))
	{
		if (d->sdl.event.type == SDL_QUIT)
			try_exit(d);
		if (d->sdl.event.type == SDL_KEYDOWN)
			key_press_hook(d);
		if (d->sdl.event.type == SDL_KEYUP)
			key_release_hook(d);
	}
	walk_sound_hack(d);
}