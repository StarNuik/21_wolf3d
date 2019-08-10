/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_fps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:03:10 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 15:42:00 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		wait_for_next_frame(t_data *d)
{
	const unsigned int	time = SDL_GetTicks();
	int					diff;

	diff = time - d->pr.frame_start;
	if (time >= d->pr.last_message + 500)
	{
		d->pr.last_message = time;
	}
	diff = TARGET_MS - diff;
	if (diff > 0)
		SDL_Delay(diff);
}
