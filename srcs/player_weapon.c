/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 02:05:52 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 15:22:58 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		shoot_pistol(t_data *d)
{
	if (d->scene.player.anim_frame ||
		d->scene.player.pistol_shot ||
		d->scene.player.ammo <= 0)
		return ;
	cast_shot(d, WEAP_PISTOL_DAMAGE);
	stop_audio(d, 3);
	play_audio(d, 3);
	d->scene.player.anim_frame = 2;
	d->scene.player.pistol_shot = 1;
	d->scene.player.ammo--;
}

void		shoot_smg(t_data *d)
{
	if ((d->scene.player.anim_frame <= 5 &&
		d->scene.player.anim_frame) ||
		d->scene.player.ammo <= 0)
		return ;
	cast_shot(d, WEAP_SMG_DAMAGE);
	stop_audio(d, 3);
	play_audio(d, 3);
	d->scene.player.anim_frame = 2;
	d->scene.player.ammo--;
}

void		shoot_bfg(t_data *d)
{
	if ((d->scene.player.anim_frame <= 4 &&
		d->scene.player.anim_frame) ||
		d->scene.player.ammo <= 0)
		return ;
	cast_shot(d, WEAP_BFG_DAMAGE);
	stop_audio(d, 4);
	play_audio(d, 4);
	d->scene.player.anim_frame = 2;
	d->scene.player.ammo--;
}

void		player_shoot(t_data *d)
{
	(d->scene.player.selected_gun == 0 ? shoot_pistol(d) : 0);
	(d->scene.player.selected_gun == 1 ? shoot_smg(d) : 0);
	(d->scene.player.selected_gun == 2 ? shoot_bfg(d) : 0);
}
