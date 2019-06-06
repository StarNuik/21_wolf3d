/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:52:54 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 03:04:52 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		clean_sdl(t_data *d)
{
	SDL_DestroyTexture(d->sdl.tex_out);
	SDL_DestroyRenderer(d->sdl.ren);
	SDL_DestroyWindow(d->sdl.win);
	SDL_Quit();
}

void		try_exit(t_data *d)
{
	clean_sdl(d);
	exit(0);
}
