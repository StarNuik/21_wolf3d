/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 02:50:29 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 17:33:59 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		rotate_player(t_data *d)
{
	float	angle;

	angle = d->scene.player.look_angle;
	angle += CONTROL_ROTATION_DELTA * -d->ctrl.mouse_rel_x;
	if (angle > FT_PI)
		angle -= 2 * FT_PI;
	if (angle < -FT_PI)
		angle += 2 * FT_PI;
	d->scene.player.look_angle = angle;
}

void		player_pipe(t_data *d)
{
	t_vector3	move_dir;

	test_pickups(d);
	if (d->ctrl.mouse_rel_x)
		rotate_player(d);
	move_dir = V3_ZERO;
	if (d->ctrl.forward)
		move_dir.y += 1.0;
	if (d->ctrl.backward)
		move_dir.y += -1.0;
	if (d->ctrl.right)
		move_dir.x += -1.0;
	if (d->ctrl.left)
		move_dir.x += 1.0;
	if (((d->ctrl.forward || d->ctrl.backward) &&
		!(d->ctrl.forward && d->ctrl.backward)) ||
		((d->ctrl.left || d->ctrl.right) &&
		!(d->ctrl.left && d->ctrl.right)))
		move_player(d, ft_v3normalize(move_dir));
	if (d->ctrl.lmb)
		player_shoot(d);
}
