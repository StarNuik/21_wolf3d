/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:02:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/25 17:17:21 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		render_frame(t_data *d)
{
	int			x;
	float		angle;
	float		angleDelta;
	float		height;
	t_raycast	ray;

	SDL_SetRenderDrawColor(d->sdl.ren, 0xff, 0xa0, 0xa0, 0x00);
	x = TEX_WIDTH;
	angle = d->scene.player.lookAngle - FIELD_OF_VIEW / 2;
	angleDelta = (float)FIELD_OF_VIEW / (float)TEX_WIDTH;
	while (--x >= 0)
	{
		ray = raycast(d, d->scene.player.pos, angle);
		height = ray.dist * cos(angle - d->scene.player.lookAngle);
		height = (float)TEX_HEIGHT / height;
		draw_wall(d, x, height, ray);
		angle += angleDelta;
		// x++;
	}
	
}

void		render_pipe(t_data *d)
{
	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_out);
	SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(d->sdl.ren);
	render_frame(d);
	SDL_SetRenderTarget(d->sdl.ren, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_out, NULL, NULL);
	SDL_RenderPresent(d->sdl.ren);
}