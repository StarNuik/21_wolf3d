/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_audio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:24:43 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/27 13:32:53 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		read_audio_file(t_data *d, char *path, int num)
{
	SDL_LoadWAV(path, &d->sound_pool[num].spec, &d->sound_pool[num].buffer, &d->sound_pool[num].length);
	d->sound_pool[num].spec.callback = &audio_call;
	d->sound_pool[num].spec.userdata = &d->sound_pool[num];
	stop_audio(d, num);
	d->sound_pool[num].dev = SDL_OpenAudioDevice(NULL, 0, &d->sound_pool[num].spec, NULL, SDL_AUDIO_ALLOW_ANY_CHANGE);
	SDL_PauseAudioDevice(d->sound_pool[num].dev, 0);
}

void	read_audio(t_data *d)
{
	read_audio_file(d, "./sounds/song2.wav", 0);
	read_audio_file(d, "./sounds/walk_g.wav", 1);
	read_audio_file(d, "./sounds/hit.wav", 2);
	play_audio(d, 0);
}