/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 04:57:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/08 14:43:23 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	read_texture_single(t_data *d, char *path, int num)
{
	d->tex_pool[num].data = stbi_load(
		path,
		&d->tex_pool[num].width,
		&d->tex_pool[num].height,
		&d->tex_pool[num].channels,
		d->tex_pool[num].type);
	if (!d->tex_pool[num].data)
		try_exit(d);
}

void	read_textures(t_data *d)
{
	read_texture_single(d, "./textures/Wall_0.bmp", 0);
	read_texture_single(d, "./textures/Wall_1.bmp", 1);
	read_texture_single(d, "./textures/Wall_2.bmp", 2);
	read_texture_single(d, "./textures/Wall_3.bmp", 3);
	read_texture_single(d, "./textures/Wall_4.bmp", 4);
	read_texture_single(d, "./textures/rem1.png", 5);
	read_texture_single(d, "./textures/fire.jpg", 6);
}
