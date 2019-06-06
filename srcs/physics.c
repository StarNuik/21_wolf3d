/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:50:29 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 04:11:44 by sbosmer          ###   ########.fr       */
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

	dirv = (t_vector3){0, 1, 0};
	dirv = rotate_vector(dirv, d->scene.player0.lookAngle);
	dirv = ft_v3multnum(&dirv, CONTROL_MOVEMENT_DELTA * (double)dir);
	d->scene.player0.pos = ft_v3add(&d->scene.player0.pos, &dirv);
}

void		physics_pipe(t_data *d)
{
	if (d->ctrl.left)
		d->scene.player0.lookAngle -= CONTROL_ROTATION_DELTA;
	if (d->ctrl.right)
		d->scene.player0.lookAngle += CONTROL_ROTATION_DELTA;
	if (d->ctrl.forward)
		move_player(d, 1);
	if (d->ctrl.backward)
		move_player(d, -1);
}