/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:02:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 00:52:43 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		render_pipe(t_data *d)
{
	SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_wall);
	SDL_RenderClear(d->sdl.ren);
	SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_sprite);
	SDL_RenderClear(d->sdl.ren);
	SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_gui);
	SDL_RenderClear(d->sdl.ren);
	PR_START(4);
	ray_viewport(d);
	PR_END(4);
	PR_START(1);
	render_walls(d);
	PR_END(1);
	PR_START(2);
	render_sprites(d);
	PR_END(2);
	PR_START(3);
	render_gui(d);
	PR_END(3);
	SDL_SetRenderTarget(d->sdl.ren, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_bg, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_wall, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_sprite, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_gui_bg, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_gui, NULL, NULL);
	SDL_RenderPresent(d->sdl.ren);
}