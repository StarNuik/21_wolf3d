/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:46:32 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/08 21:02:06 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		general_pipe(t_data *d)
{
	while (1)
	{
		event_router(d);
		physics_pipe(d);
		render_pipe(d);
		// SDL_Delay(10);

		// try_exit(d);
	}
	try_exit(d);
}