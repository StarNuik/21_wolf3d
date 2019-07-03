/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 02:05:52 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 02:54:35 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		shoot_pistol(t_data *d)
{
	// Reverse timer
	// if (d->ticks <= d->scene.player.pistol_shot_tick + PISTOL_COOLDOWN_TICKS)
	// 	return ;
	// d->scene.player.pistol_shot_tick = d->ticks;
	if (d->scene.player.pistol_frame || d->scene.player.pistol_shot || d->scene.player.ammo <= 0)
		return ;
	play_audio(d, 3);
	d->scene.player.pistol_frame = 2;
	d->scene.player.pistol_shot = 1;
	d->scene.player.ammo--;
}