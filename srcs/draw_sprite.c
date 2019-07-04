/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:59:06 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/05 02:50:31 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		spritequeue_remove(t_data *d, t_rendobj *obj)
{
	size_t			qt;
	const size_t	len = arr_length(d->rend.sprite_queue);

	qt = arr_find(d->rend.sprite_queue, (long long)obj);
	arr_drop(d->rend.sprite_queue, qt);
	arr_pop(d->rend.object_order);
	qt = -1;
	while (++qt < len)
		arr_set(d->rend.object_order, qt, qt);
}

char		spritequeue_add(t_data *d, t_rendobj *obj)
{
	if (!arr_push(d->rend.sprite_queue, (long long)obj))
		return (0);
	if (!arr_push(d->rend.object_order, arr_length(d->rend.object_order)))
		return (0);
	return (1);
}

int			get_tex_id(const int in_x, const int x, const int y, const int size, const int tex_height, const int tex_width)
{
	int		tex_x;
	int		tex_y;

	tex_x = ((float)(x - (in_x - size / 2)) / (float)(size)) * (float)tex_width;
	tex_y = ((float)(y - (TEX_HEIGHT / 2 - size / 2)) / (float)(size)) * (float)tex_height;
	tex_y *= tex_width;
	return (tex_x + tex_y);
}

void		draw_sprite(t_data *d, const int in_x, const int size, const t_rendobj obj)
{
	const t_exture	tex = d->tex_pool[obj.tex_id];
	int				x;
	int				y;
	int				tex_id;
	const float		dist = ft_v3dot2(ft_v3subtract(d->scene.player.pos, obj.pos));

	x = ft_clamp(in_x - size / 2 - 1, 0, TEX_WIDTH);
	while (++x < ft_clamp(in_x + size / 2, 0, TEX_WIDTH))
	{
		y = TEX_HEIGHT / 2 - size / 2 - 1;
		if (x > 0 && x < TEX_WIDTH && dist < powf(d->rend.rays[x].dist, 2.0))
			while (++y < TEX_HEIGHT / 2 + size / 2)
			{
				tex_id = get_tex_id(in_x, x, y, size, tex.height, tex.width);
				if ((tex.data[tex_id * 3] << 16) + (tex.data[tex_id * 3 + 1] << 8) + tex.data[tex_id * 3 + 2] == 0x980088)
					continue ;
				SDL_SetRenderDrawColor(d->sdl.ren, tex.data[tex_id * 3], tex.data[tex_id * 3 + 1], tex.data[tex_id * 3 + 2], 0xff);
				SDL_RenderDrawPoint(d->sdl.ren, x, y);
			}
	}
	(void)tex;
}

void		sort_sprites(t_data *d)
{
	int			qt;
	int			ct;
	int			key;
	const int	len = arr_length(d->rend.sprite_queue);
	t_rendobj	*obj;

	qt = -1;
	while (++qt < len)
	{
		obj = ((t_rendobj*)arr_get(d->rend.sprite_queue, qt));
		obj->dist_to_player = ft_v3magnitude(ft_v3subtract(d->scene.player.pos, obj->pos));
	}
	qt = 0;
	while (++qt < len)
	{
		key = arr_get(d->rend.object_order, qt);
		obj = (t_rendobj*)arr_get(d->rend.sprite_queue, key);
		ct = qt - 1;
		while (ct >= 0 && ((t_rendobj*)arr_get(d->rend.sprite_queue, arr_get(d->rend.object_order, ct)))->dist_to_player > obj->dist_to_player)
		{
			arr_set(d->rend.object_order, ct + 1, arr_get(d->rend.object_order, ct));
			ct--;
		}
		arr_set(d->rend.object_order, ct + 1, key);
	}
}

void		render_sprites(t_data *d)
{
	size_t		qt;
	float		size;
	float		angle;
	t_rendobj	*object;
	t_vector3	sub;

	SDL_SetRenderTarget(d->sdl.ren, d->sdl.tex_sprite);
	sort_sprites(d);
	qt = arr_length(d->rend.sprite_queue);
	while (--qt != (size_t)-1)
	{
		object = (t_rendobj*)arr_get(d->rend.sprite_queue, arr_get(d->rend.object_order, qt));
		if (object->hidden)
			continue ;
		sub = ft_v3subtract(object->pos, d->scene.player.pos);
		// (object->pickup && ft_v3dot2(sub) <= 1.f ? pickup(d, object) : 0);
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
		draw_sprite(d, ((angle + FT_PI / 4.0) / (FT_PI / 2.0)) * (float)TEX_WIDTH, size, *object);
	}
	SDL_SetRenderTarget(d->sdl.ren, NULL);
}