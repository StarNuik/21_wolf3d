/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:40:46 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/01 15:50:11 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_vector3	rotate_vector(t_vector3 in, const float angle)
{
	const float si = sin(-angle);
	const float co = cos(-angle);

	// angle = -angle;
	in = (t_vector3){co * in.x - si * in.y, si * in.x + co * in.y, 0.0};
	return (in);
}


void		move_player(t_data *d, t_vector3 dirv)
{
	t_raycast	hit[3];
	float		angle;
	int			qt;
	float		dist;

	// dirv = (t_vector3){0, 1, 0};
	angle = atan2(dirv.y, dirv.x) - FT_PI / 2.0 /* - FT_PI */;
	angle = -angle + d->scene.player.lookAngle;
	dirv = rotate_vector(dirv, d->scene.player.lookAngle);
	dirv = ft_v3multnum(dirv, CONTROL_MOVEMENT_DELTA);
	if (d->ctrl.speedhack)
		dirv = ft_v3multnum(dirv, CONTROL_SPEEDHACK);
	qt = -1;
	angle -= 5 * DEG2RAD;
	while (++qt < 3)
	{
		hit[qt] = raycast(d, d->scene.player.pos, angle);
		angle += 5 * DEG2RAD;
	}
	dist = fmin(hit[0].dist, fmin(hit[1].dist, hit[2].dist));
	if (d->ctrl.noclip || dist >= CONTROL_COLLISION_DIST)
		d->scene.player.pos = ft_v3add(d->scene.player.pos, dirv);
}
