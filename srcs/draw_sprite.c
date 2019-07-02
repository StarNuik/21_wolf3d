/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:59:06 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/02 21:18:33 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			get_tex_id(const int in_x, const int x, const int y, const int size, const int tex_height, const int tex_width)
{
	int		tex_x;
	int		tex_y;

	tex_x = ((float)(x - (in_x - size / 2)) / (float)(size)) * (float)tex_width;
	tex_y = ((float)(y - (TEX_HEIGHT / 2 - size / 2)) / (float)(size)) * (float)tex_height;
	tex_y *= tex_width;
	return (tex_x + tex_y);
}

void		draw_sprite(t_data *d, const int in_x, const int size, const t_object obj)
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