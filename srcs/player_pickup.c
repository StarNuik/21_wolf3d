/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pickup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 07:11:01 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 09:26:25 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		score_pickup(t_data *d, t_object *obj)
{
	stop_audio(d, 5);
	play_audio(d, 5);
	d->scene.player.score += obj->value;
}

void		health_pickup(t_data *d, t_object *obj)
{
	stop_audio(d, 6);
	play_audio(d, 6);
	d->scene.player.health += obj->value;
	d->scene.player.health = ft_clamp(d->scene.player.health, 0, 100);
}

void		ammo_pickup(t_data *d, t_object *obj)
{
	stop_audio(d, 7);
	play_audio(d, 7);
	d->scene.player.ammo += obj->value;
}

void		pickup(t_data *d, t_object *obj)
{
	obj->hidden = 1;
	(obj->pickup == 1 ? score_pickup(d, obj) : 0);
	(obj->pickup == 2 ? health_pickup(d, obj) : 0);
	(obj->pickup == 3 ? ammo_pickup(d, obj) : 0);
	(void)d;
}