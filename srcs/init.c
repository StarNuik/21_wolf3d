/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:45:34 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 15:52:14 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_astar(t_data *d)
{
	t_array		*walk_mask;

	walk_mask = arr_init();
	arr_push(walk_mask, 0);
	d->scene.astar = astar_init(
		d->scene.map_loaded, walk_mask, d->scene.map_x, d->scene.map_y);
	arr_destroy(walk_mask);
}

void	init(t_data *d)
{
	d->scene.player.pos = (t_vector3){1.5, 1.5, 0};
	d->scene.player.health = 69;
	d->scene.player.ammo = 999;
	read_map(d, "maps/test.wolf");
	read_textures(d);
	d->scene.map_loaded = d->map_origin;
	init_astar(d);
	init_sdl(d);
	draw_bg(d);
	draw_gui_bg(d);
	read_audio(d);
}
