/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 07:31:09 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/27 09:05:38 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

float		raycast_basic(t_data *d, t_vector3 pos, float angle)
{
	float		qt;
	float		si;
	float		co;
	t_vector3	cur;

	qt = RAYCAST_RESOLUTION;
	si = RAYCAST_RESOLUTION * sin(angle);
	co = RAYCAST_RESOLUTION * cos(angle);
	cur = pos;
	while (qt < RAYCAST_MAX_DISTANCE)
	{
		cur.x += si;
		cur.y += co;
		if (arr_get(d->scene.map_loaded, (int)cur.x + (int)cur.y * d->scene.map_x) != 0)
			return (qt);
		qt += RAYCAST_RESOLUTION;
	}
	return (-9000.1);
}

t_raycast	raycast(t_data *d, t_vector3 pos, float angle)
{
	t_raycast	res;
	float		si;
	float		co;

	res.type = 0;
	res.hit.x = -1.0;
	res.hit.y = -1.0;
	res.dist = RAYCAST_RESOLUTION;
	si = RAYCAST_RESOLUTION * sin(angle);
	co = RAYCAST_RESOLUTION * cos(angle);
	res.hit = pos;
	while (res.dist < RAYCAST_MAX_DISTANCE)
	{
		res.hit.x += si;
		res.hit.y += co;
		if (arr_get(d->scene.map_loaded, (int)res.hit.x + (int)res.hit.y * d->scene.map_x) != 0)
		{
			res.type = arr_get(d->scene.map_loaded, (int)res.hit.x + (int)res.hit.y * d->scene.map_x);
			return (res);
		}
		res.dist += RAYCAST_RESOLUTION;
	}
	res.dist = -1.0;
	return (res);
}
