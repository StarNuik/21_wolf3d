/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_fps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:03:10 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/29 21:41:19 by sbosmer          ###   ########.fr       */
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
		printf("\e[1;1H\e[2J");
		// printf("\n\n");
		printf("Last frame took:		%d ms\n", diff);
		PR_FLUSH(0, "Physics:			");
		PR_FLUSH(1, "Rendering walls:		");
		PR_FLUSH(2, "Rendering sprites:		");
		PR_FLUSH(3, "Rendering GUI:			");
		d->pr.last_message = time;
	}
	diff = TARGET_MS - diff;
	if (diff > 0)
		SDL_Delay(diff);
}
