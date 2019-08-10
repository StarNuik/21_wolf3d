/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_router.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:35:53 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 16:19:12 by sbosmer          ###   ########.fr       */
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
	(key == SDLK_1 && !d->scene.player.anim_frame
		? d->scene.player.selected_gun = 0 : 0);
	(key == SDLK_2 && !d->scene.player.anim_frame
		? d->scene.player.selected_gun = 1 : 0);
	(key == SDLK_3 && !d->scene.player.anim_frame
		? d->scene.player.selected_gun = 2 : 0);
	(key == SDLK_KP_1 ? d->ctrl.noclip = !d->ctrl.noclip : 0);
	(key == SDLK_KP_2 ? d->ctrl.speedhack = !d->ctrl.speedhack : 0);
	(key == SDLK_KP_3 ? d->ctrl.zharko = 1 : 0);
	(key == SDLK_KP_3 ? play_audio(d, 2) : 0);
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

void		walk_sound_hack(t_data *d)
{
	if (((d->ctrl.forward || d->ctrl.backward) &&
		!(d->ctrl.forward && d->ctrl.backward)) ||
		((d->ctrl.left || d->ctrl.right) &&
		!(d->ctrl.left && d->ctrl.right)))
		play_audio(d, 1);
	if ((!(d->ctrl.forward || d->ctrl.backward) ||
		(d->ctrl.forward && d->ctrl.backward)) &&
		(!(d->ctrl.left || d->ctrl.right) ||
		(d->ctrl.left && d->ctrl.right)))
		stop_audio(d, 1);
	(void)d;
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
		if (d->sdl.event.type == SDL_MOUSEBUTTONDOWN)
			mouse_press_hook(d);
		if (d->sdl.event.type == SDL_MOUSEBUTTONUP)
			mouse_release_hook(d);
	}
	if (!d->sdl.mouse_move_processed)
	{
		d->ctrl.mouse_rel_x = 0;
		d->ctrl.mouse_rel_y = 0;
	}
	walk_sound_hack(d);
}
