/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pickup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 07:11:01 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/07 09:42:42 by sbosmer          ###   ########.fr       */
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
	(obj->pickup == 1 ? score_pickup(d, obj) : 0);
	(obj->pickup == 2 ? health_pickup(d, obj) : 0);
	(obj->pickup == 3 ? ammo_pickup(d, obj) : 0);
	spritequeue_remove(d, &obj->rend);
	arr_drop(d->scene.pickup_arr, arr_find(d->scene.pickup_arr, (long long)obj));
	(void)d;
}

void		test_pickups(t_data *d)
{
	t_object		*obj;
	t_object		*closest;
	const size_t	len = arr_length(d->scene.pickup_arr);
	size_t			qt;

	if (len == 0)
		return ;
	closest = (t_object*)arr_top(d->scene.pickup_arr);
	qt = -1;
	while (++qt < len)
	{
		obj = (t_object*)arr_get(d->scene.pickup_arr, qt);
		if (closest->rend.dist_to_player > obj->rend.dist_to_player)
			closest = obj;
	}
	if (closest->rend.dist_to_player <= .5f)
		pickup(d, closest);
}