/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:02:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 04:14:50 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

float		raycast_basic(t_data *d, t_vector3 pos, float angle)
{
	float		qt;
	float		si;
	float		co;
	t_vector3	cur;

	qt = RAYCAST_RESOLUTION;
	si = sin(angle);
	co = cos(angle);
	cur = pos;
	while (qt < RAYCAST_MAX_DISTANCE)
	{
		cur.x += RAYCAST_RESOLUTION * si;
		cur.y += RAYCAST_RESOLUTION * co;
		if (arr_get(d->scene.map_loaded, (int)cur.x + (int)cur.y * DEBUG_MAP_SIZE) != 0)
			return (qt);
		qt += RAYCAST_RESOLUTION;
	}
	return (9001.0);
}

void		render_frame(t_data *d)
{
	int		x;
	float	angle;
	float	angleDelta;
	float	height;

	SDL_SetRenderDrawColor(d->sdl.ren, 0xff, 0xa0, 0xa0, 0x00);
	x = 0;
	angle = d->scene.player0.lookAngle - FIELD_OF_VIEW / 2;
	angleDelta = (float)FIELD_OF_VIEW / (float)TEX_WIDTH;
	while (x < TEX_WIDTH)
	{
		height = raycast_basic(d, d->scene.player0.pos, angle)
			* cos(angle - d->scene.player0.lookAngle);
		height = (float)TEX_HEIGHT / height;		
		draw_wall(d, x, height);
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