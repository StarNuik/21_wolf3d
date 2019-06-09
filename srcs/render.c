/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:02:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/09 11:41:41 by sbosmer          ###   ########.fr       */
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
	x = 0;
	angle = d->scene.player0.lookAngle - FIELD_OF_VIEW / 2;
	angleDelta = (float)FIELD_OF_VIEW / (float)TEX_WIDTH;
	while (x < TEX_WIDTH)
	{
		ray = raycast(d, d->scene.player0.pos, angle);
		height = ray.dist * cos(angle - d->scene.player0.lookAngle);
		height = (float)TEX_HEIGHT / height;
		// draw_wall_simple(d, x, height);
		// draw_wall(d, x, height, ray);
		draw_wall_sky(d, x, height, ray);
		// draw_wall_subj(d, x, height, ray);
		angle += angleDelta;
		x++;
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