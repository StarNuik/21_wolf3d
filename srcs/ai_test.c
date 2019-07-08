/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:48:13 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/08 13:27:35 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ai_test(t_data *d, t_enemy *self)
{
	t_vector3	dir;
	t_anode		*node;

	if (self->rend.dist_to_player < 1.f)
		return ;
	// If you've hit the end
	if (self->path && arr_length(self->path) == 0)
	{
		arr_destroy(self->path);
		self->path = NULL;
		return ;
	}
	// If no path, generate new path
	if (!self->path)
		self->path = astar_get_path(d->scene.astar, self->rend.pos, d->scene.player.pos);
	// If didn't generate, don't segfault
	if (!self->path)
		return ;
	node = (t_anode*)arr_top(self->path);
	if (node->x != (int)d->scene.player.pos.x || node->y != (int)d->scene.player.pos.y)
	{
		arr_destroy(self->path);
		self->path = NULL;
		return ;
	}
	node = (t_anode*)arr_last(self->path);
	if (!node)
		return ;
	if (ft_v3dot2(ft_v3subtract(self->rend.pos, (t_vector3){node->x + .5f, node->y + .5f, 0.f})) < 1.f)
	{
		arr_pop(self->path);
		return ;
	}
	dir = ft_v3subtract((t_vector3){node->x + .5f, node->y + .5f, 0.f}, self->rend.pos);
	dir = ft_v3normalize(dir);
	dir = ft_v3multnum(dir, self->speed);
	self->rend.pos = ft_v3add(self->rend.pos, dir);
	(void)d;
}