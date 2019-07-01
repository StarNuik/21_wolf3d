/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:02:36 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/01 22:12:14 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		render_walls(t_data *d)
{
	int				x;
	float			height;
	t_raycast		ray;
	const float		angleDelta = (float)FIELD_OF_VIEW / (float)TEX_WIDTH;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_wall);
	x = TEX_WIDTH;
	while (--x >= 0)
	{
		ray = d->rend.rays[x];
		height = ray.dist * cos(angleDelta * x - FIELD_OF_VIEW / 2);
		height = (float)TEX_HEIGHT / height;
		draw_wall(d, x, height, ray);
		// x++;
	}
	SDL_SetRenderTarget(d->sdl.ren, NULL);
	// ft_putmem
}

void		sort_sprites(t_data *d)
{
	int			qt;
	int			ct;
	int			key;
	const int	len = arr_length(d->scene.object_arr);
	t_object	*obj;

	qt = -1;
	while (++qt < len)
	{
		obj = ((t_object*)arr_get(d->scene.object_arr, qt));
		obj->dist_to_player = ft_v3magnitude(ft_v3subtract(d->scene.player.pos, obj->pos));
	}
	qt = 0;
	while (++qt < len)
	{
		key = arr_get(d->rend.object_order, qt);
		obj = (t_object*)arr_get(d->scene.object_arr, key);
		ct = qt - 1;
		while (ct >= 0 && ((t_object*)arr_get(d->scene.object_arr, ct))->dist_to_player > obj->dist_to_player)
		{
			d->scene.object_arr->field[ct + 1] = arr_get(d->scene.object_arr, ct);
			ct--;
		}
		d->scene.object_arr->field[ct + 1] = key;
	}
}

void		render_sprites(t_data *d)
{
	size_t		qt;
	float		size;
	float		angle;
	t_object	object;
	t_vector3	sub;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_sprite);
	// sort_sprites(d);
	// qt = arr_length(d->scene.object_arr);
	qt = -1;
	while (++qt < arr_length(d->scene.object_arr))
	{
		// object = *(t_object*)arr_get(d->scene.object_arr, arr_get(d->rend.object_order, qt));
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
		// size = size * cos((float)FIELD_OF_VIEW / (float)TEX_WIDTH * ((angle + FT_PI / 4.0) / (FT_PI / 2.0)) * (float)TEX_WIDTH - FIELD_OF_VIEW / 2);
		size = (float)TEX_HEIGHT / fmax(ft_v3magnitude(sub), 1);
		draw_sprite(d, ((angle + FT_PI / 4.0) / (FT_PI / 2.0)) * (float)TEX_WIDTH, size, object);
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