/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 04:57:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 07:40:00 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	read_textures(t_data *d)
{
	d->tex_pool[0].data = stbi_load(
		"./textures/Wall_0.bmp",
		&d->tex_pool[0].width,
		&d->tex_pool[0].height,
		&d->tex_pool[0].channels,
		d->tex_pool[0].type);
	d->tex_pool[1].data = stbi_load(
		"./textures/Wall_1.bmp",
		&d->tex_pool[1].width,
		&d->tex_pool[1].height,
		&d->tex_pool[1].channels,
		d->tex_pool[1].type);
	d->tex_pool[2].data = stbi_load(
		"./textures/Wall_2.bmp",
		&d->tex_pool[2].width,
		&d->tex_pool[2].height,
		&d->tex_pool[2].channels,
		d->tex_pool[2].type);
	d->tex_pool[3].data = stbi_load(
		"./textures/Wall_3.bmp",
		&d->tex_pool[3].width,
		&d->tex_pool[3].height,
		&d->tex_pool[3].channels,
		d->tex_pool[3].type);
	d->tex_pool[4].data = stbi_load(
		"./textures/Wall_4.bmp",
		&d->tex_pool[4].width,
		&d->tex_pool[4].height,
		&d->tex_pool[4].channels,
		d->tex_pool[4].type);
	d->tex_pool[5].data = stbi_load(
		"./textures/Wall_5.bmp",
		&d->tex_pool[5].width,
		&d->tex_pool[5].height,
		&d->tex_pool[5].channels,
		d->tex_pool[5].type);
	if (!d->tex_pool[0].data || !d->tex_pool[1].data
	|| !d->tex_pool[2].data || !d->tex_pool[3].data
	|| !d->tex_pool[4].data || !d->tex_pool[5].data)
		try_exit(d);
}
