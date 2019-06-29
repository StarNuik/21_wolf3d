/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:02:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/29 18:01:16 by sbosmer          ###   ########.fr       */
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

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_wall);
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
	SDL_SetRenderTarget(d->sdl.ren, NULL);
}

void		render_sprites(t_data *d)
{
	size_t		qt;
	float		size;
	float		angle;
	t_object	object;
	t_vector3	sub;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_sprite);
	qt = -1;
	while (++qt < arr_length(d->scene.object_arr))
	{
		object = *(t_object*)arr_get(d->scene.object_arr, qt);
		sub = ft_v3subtract(object.pos, d->scene.player.pos);
		angle = atan2(sub.y, sub.x) + FT_PI / 2.0 - FT_PI;
		angle = angle + d->scene.player.lookAngle;
		if (angle > FT_PI)
			angle -= 2 * FT_PI;
		if (angle < -FT_PI)
			angle += 2 * FT_PI;
		if (angle > FT_PI / 3.0 || angle < -FT_PI / 3.0)
			continue;
		size = (float)TEX_HEIGHT / fmax(ft_v3magnitude(sub), 1);
		draw_sprite(d, ((angle + FT_PI / 4.0) / (FT_PI / 2.0)) * (float)TEX_WIDTH, size, object.tex_id);
	}
	SDL_SetRenderTarget(d->sdl.ren, NULL);
}

void		render_gui(t_data *d)
{
	(void)d;
}

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
	render_walls(d);
	render_sprites(d);
	render_gui(d);
	SDL_SetRenderTarget(d->sdl.ren, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_bg, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_wall, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_sprite, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_gui_bg, NULL, NULL);
	SDL_RenderCopy(d->sdl.ren, d->sdl.tex_gui, NULL, NULL);
	SDL_RenderPresent(d->sdl.ren);
}