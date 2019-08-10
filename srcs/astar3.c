/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:14:23 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 17:22:45 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		kill_me(t_astar *astar, const int size_x, const int size_y)
{
	astar->size_x = size_x;
	astar->size_y = size_y;
}

t_astar		*astar_init(
	t_array *map, t_array *walkable_mask, const int size_x, const int size_y)
{
	t_astar			*astar;
	t_anode			*node;
	int				qt;
	char			walkable;
	long long		val;

	if (!(astar = ft_memalloc(sizeof(t_astar)))
		|| !(astar->open = arr_init())
		|| !(astar->closed = arr_init())
		|| !(astar->map = arr_init()))
		return (NULL);
	kill_me(astar, size_x, size_y);
	qt = -1;
	while (++qt < size_x * size_y && (walkable = 0) == 0)
	{
		node = ft_memalloc(sizeof(t_anode));
		if (!node || !arr_push(astar->map, (long long)node))
			return (NULL);
		node->x = qt % size_x;
		node->y = qt / size_x;
		val = arr_get(map, qt);
		arr_itervv(walkable_mask, &val, &walkable, &check_walkable);
		node->walkable = walkable;
	}
	return (astar);
}
