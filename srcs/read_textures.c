/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 04:57:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/29 19:59:32 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	read_texture_single(t_data *d, char *path, int num, char load_alpha)
{
	d->tex_pool[num].type = (load_alpha ? STBI_rgb_alpha : STBI_rgb);
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
	read_texture_single(d, "./textures/Wall_1.bmp", 0, 0);
	read_texture_single(d, "./textures/Wall_2.bmp", 1, 0);
	read_texture_single(d, "./textures/Wall_3.bmp", 2, 0);
	read_texture_single(d, "./textures/Wall_4.bmp", 3, 0);
	read_texture_single(d, "./textures/Wall_5.bmp", 4, 0);
	read_texture_single(d, "./textures/Wall_6.bmp", 5, 0);
	read_texture_single(d, "./textures/waifu.png", 6, 0);
	read_texture_single(d, "./textures/cat.bmp", 7, 0);
	read_texture_single(d, "./textures/zharko.jpg", 8, 0);
	read_texture_single(d, "./textures/subj_0.bmp", 9, 0);
	read_texture_single(d, "./textures/subj_1.bmp", 10, 0);
	read_texture_single(d, "./textures/subj_2.bmp", 11, 0);
	read_texture_single(d, "./textures/subj_3.bmp", 12, 0);
}
