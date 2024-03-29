/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:46:32 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 15:51:48 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		general_pipe(t_data *d)
{
	while (1)
	{
		d->pr.frame_start = SDL_GetTicks();
		event_router(d);
		ray_viewport(d);
		sort_sprites(d);
		player_pipe(d);
		enemy_pipe(d);
		render_pipe(d);
		wait_for_next_frame(d);
		d->ticks++;
	}
	try_exit(d);
}
