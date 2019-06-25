/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:50:29 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/25 17:20:56 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_vector3	rotate_vector(t_vector3 in, float angle)
{
	float si;
	float co;

	angle = -angle;
	si = sin(angle);
	co = cos(angle);
	in = (t_vector3){co * in.x - si * in.y, si * in.x + co * in.y, 0.0};
	return (in);
}

void		move_player(t_data *d, char dir)
{
	t_vector3	dirv;
	t_raycast	hit[3];
	float		angle;
	int			qt;
	float		dist;

	dirv = (t_vector3){0, 1, 0};
	dirv = rotate_vector(dirv, d->scene.player.lookAngle);
	dirv = ft_v3multnum(dirv, CONTROL_MOVEMENT_DELTA * (double)dir);
	angle = (dir > 0 ? d->scene.player.lookAngle : d->scene.player.lookAngle - 180) - 1;
	qt = -1;
	while (++qt < 3)
		hit[qt] = raycast(d, d->scene.player.pos, angle++);
	dist = fmin(hit[0].dist, fmin(hit[1].dist, hit[2].dist));
	if (d->ctrl.noclip || dist > CONTROL_COLLISION_DIST)
		d->scene.player.pos = ft_v3add(d->scene.player.pos, dirv);
}

void		physics_pipe(t_data *d)
{
	if (d->ctrl.left)
		d->scene.player.lookAngle += CONTROL_ROTATION_DELTA;
	if (d->ctrl.right)
		d->scene.player.lookAngle -= CONTROL_ROTATION_DELTA;
	if (d->ctrl.forward)
		move_player(d, 1);
	if (d->ctrl.backward)
		move_player(d, -1);
}