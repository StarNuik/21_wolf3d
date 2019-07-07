/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 07:32:13 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/07 09:48:26 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		intersection_test(const t_vector3 pos, const t_vector3 dir, const t_vector3 target)
{
	const t_vector3		m = ft_v3subtract(pos, target);
	const float			c = ft_v3dot2(m) - HIT_CIRCLE_RADIUS_SQUARED;
	float				b;
	float				d;

	if (c <= 0.f)
		return (1);
	b = ft_v3dot(m, dir);
	if (b > 0.f)
		return (0);
	d = b * b - c;
	if (d < 0.f)
		return (0);
	return (1);
}

void		get_closest_intersect(const size_t id, const long long val, void *data)
{
	const t_rendobj		test = *(t_rendobj*)val;
	const t_shotdata	shot = *(t_shotdata*)data;

	if (intersection_test(shot.ray_start, shot.ray_dir, test.pos))
	{
		if (!shot.closest || test.dist_to_player < shot.closest->dist_to_player)
			((t_shotdata*)data)->closest = (t_rendobj*)val;
	}
	(void)id;
}

void		cast_shot(t_data *d, const int damage)
{
	t_shotdata		shot;

	shot.closest = NULL;
	shot.ray_start = d->scene.player.pos;
	shot.ray_dir = ft_v3euleur(V3_UP, 0, 0, -d->scene.player.lookAngle * RAD2DEG);
	arr_iterv(d->scene.destr_object_arr, &shot, &get_closest_intersect);
	if (shot.closest)
	{
		damage_object(d, (t_object*)shot.closest, damage);
	}
}