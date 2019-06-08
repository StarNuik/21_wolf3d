/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:45:34 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/08 14:33:52 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_textures(t_data *d)
{
	int		qt;

	qt = -1;
	while (++qt < TEXTURE_POOL_SIZE)
	{
		// d->tex_pool[qt].data = NULL;
		// d->tex_pool[qt].width = 0;
		// d->tex_pool[qt].height = 0;
		// d->tex_pool[qt].channels = 0;
		d->tex_pool[qt].type = STBI_rgb;
	}
}

void	init(t_data *d)
{
	init_textures(d);
	read_textures(d);
	d->map_origin = read_map("abc");
	//! FIXME Dirty parsing ?
	d->scene.map_loaded = d->map_origin;
	// d->scene.player0.lookAngle = 0;
	d->scene.player0.pos = (t_vector3){5, 5, 0};
	// d->ctrl.forward = 0;
	// d->ctrl.backward = 0;
	// d->ctrl.left = 0;
	// d->ctrl.right = 0;
	init_sdl(d);
}