/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:55:16 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 16:37:11 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	play_audio(t_data *d, int num)
{
	if (d->sound_pool[num].len_left <= 0)
	{
		d->sound_pool[num].pos = d->sound_pool[num].buffer;
		d->sound_pool[num].len_left = d->sound_pool[num].length;
	}
}

void	stop_audio(t_data *d, int num)
{
	d->sound_pool[num].pos = NULL;
	d->sound_pool[num].len_left = 0;
}

void	audio_call(void *userdata, Uint8 *stream, int len)
{
	t_sound			*s;

	s = (t_sound*)userdata;
	if (s->len_left <= 0)
	{
		ft_bzero(stream, len);
		return ;
	}
	len = (len > s->len_left ? s->len_left : len);
	ft_memcpy(stream, s->pos, len);
	s->pos += len;
	s->len_left -= len;
}
