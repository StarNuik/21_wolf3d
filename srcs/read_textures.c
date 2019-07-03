/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 04:57:30 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 01:17:29 by sbosmer          ###   ########.fr       */
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
	read_texture_single(d, "./textures/walls/Wall_1.bmp", 0, 0);
	read_texture_single(d, "./textures/walls/Wall_2.bmp", 1, 0);
	read_texture_single(d, "./textures/walls/Wall_3.bmp", 2, 0);
	read_texture_single(d, "./textures/walls/Wall_4.bmp", 3, 0);
	read_texture_single(d, "./textures/walls/Wall_5.bmp", 4, 0);
	read_texture_single(d, "./textures/walls/Wall_6.bmp", 5, 0);
	read_texture_single(d, "./textures/walls/waifu.png", 6, 0);
	read_texture_single(d, "./textures/walls/cat.bmp", 7, 0);
	read_texture_single(d, "./textures/walls/zharko.jpg", 8, 0);
	read_texture_single(d, "./textures/walls/subj_0.bmp", 9, 0);
	read_texture_single(d, "./textures/walls/subj_1.bmp", 10, 0);
	read_texture_single(d, "./textures/walls/subj_2.bmp", 11, 0);
	read_texture_single(d, "./textures/walls/subj_3.bmp", 12, 0);
	read_texture_single(d, "./textures/sprites/chandelier.png", 13, 0);
	read_texture_single(d, "./textures/sprites/lamp.png", 14, 0);
	read_texture_single(d, "./textures/sprites/table.png", 15, 0);
	read_texture_single(d, "./textures/sprites/treasure.png", 16, 0);
	read_texture_single(d, "./textures/sprites/tree.png", 17, 0);
	read_texture_single(d, "./textures/sprites/tree2.png", 18, 0);
	read_texture_single(d, "./textures/sprites/tree2.png", 19, 0);
	read_texture_single(d, "./textures/gui/gui_bg.png", 20, 0);
	read_texture_single(d, "./textures/gui/font.png", 21, 0);
	read_texture_single(d, "./textures/gui/pistol_anim.png", 22, 0);
}
