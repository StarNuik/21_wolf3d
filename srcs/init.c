/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:45:34 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/29 17:43:07 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init(t_data *d)
{
	d->scene.player.pos = (t_vector3){1.5, 1.5, 0};
	read_map(d, "maps/test.wolf");
	read_textures(d);
	d->scene.map_loaded = d->map_origin;
	init_sdl(d);
	draw_bg(d);
	draw_gui_bg(d);
	read_audio(d);
}