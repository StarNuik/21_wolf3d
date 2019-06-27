/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:02:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/27 14:28:15 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		render_walls(t_data *d)
{
	int			x;
	float		angle;
	float		angleDelta;
	float		height;
	t_raycast	ray;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_out);
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

void		render_sprites(t_data *d)
{
	int		qt;
	float	dist;
	int		size;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_sprite);
	qt = -1;
	while (++qt < OBJECT_POOL_SIZE)
	{
		dist = ft_v3magnitude(ft_v3subtract(d->scene.player.pos, d->scene.object_pool[qt].pos));
		size = (float)TEX_HEIGHT / dist;
		draw_sprite(d, TEX_WIDTH / 2, size, d->scene.object_pool[qt].tex_id);
	}
}

void		render_gui(t_data *d)
{
	(void)d;
}

void		render_pipe(t_data *d)
{
	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_out);
	SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(d->sdl.ren);
	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_gui);
	SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(d->sdl.ren);
	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_sprite);
	SDL_SetRenderDrawColor(d->sdl.ren, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(d->sdl.ren);
	render_walls(d);
	render_sprites(d);
	render_gui(d);
	SDL_SetRenderTarget(d->sdl.ren, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_out, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_sprite, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_gui, NULL, NULL);
	SDL_RenderPresent(d->sdl.ren);
}