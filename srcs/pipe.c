/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:46:32 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/07 06:53:11 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		general_pipe(t_data *d)
{
	while (1)
	{
		d->pr.frame_start = SDL_GetTicks();
		event_router(d);
		PR_START(4);
		ray_viewport(d);
		PR_END(4);
		PR_START(5)
		sort_sprites(d);
		PR_END(5)
		PR_START(0);
		player_pipe(d);
		PR_END(0);
		render_pipe(d);
		wait_for_next_frame(d);
		PR_CLEAR
		d->ticks++;
	}
	try_exit(d);
}