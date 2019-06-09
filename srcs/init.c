/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:45:34 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/09 11:40:44 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init(t_data *d)
{
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
	read_audio(d);
}