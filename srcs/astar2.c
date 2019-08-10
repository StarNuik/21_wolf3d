/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:13:28 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 17:24:08 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		clear(t_astar *astar)
{
	arr_iter(astar->open, &clean_node);
	arr_iter(astar->closed, &clean_node);
	arr_clear(astar->open);
	arr_clear(astar->closed);
	astar->target = NULL;
}

t_array		*retrace_path(t_astar *astar)
{
	t_array		*path;
	t_anode		*node;

	path = arr_init();
	node = (t_anode*)arr_last(astar->closed);
	while (node)
	{
		arr_push(path, (long long)node);
		node = node->parent;
	}
	clear(astar);
	return (path);
}

void		get_neighbours(t_astar *astar, t_array *neighbours, t_anode *node)
{
	t_anode		*try;
	int			x;
	int			y;

	arr_clear(neighbours);
	x = -2;
	while (++x <= 1)
	{
		y = -2;
		while (++y <= 1)
			if ((node->x + x >= 0)
			&& (node->x + x < astar->size_x)
			&& (node->y + y >= 0)
			&& (node->y + y < astar->size_y)
			&& !(x == 0 && y == 0)
			&& ft_abs(x) != ft_abs(y))
			{
				try = (t_anode*)arr_get(
					astar->map, node->x + x + (node->y + y) * astar->size_x);
				arr_push(neighbours, (long long)try);
			}
	}
}

t_array		*calc_path(t_astar *astar)
{
	t_anode		*node;
	t_array		*neighbours;

	neighbours = arr_init();
	while (1)
	{
		if (arr_length(astar->open) == 0)
		{
			clear(astar);
			return (NULL);
		}
		node = get_cheapest_node(astar);
		arr_find_destroy(astar->open, (long long)node);
		arr_push(astar->closed, (long long)node);
		if (node == astar->target)
			return (retrace_path(astar));
		get_neighbours(astar, neighbours, node);
		arr_itervv(neighbours, astar, node, &work_neighbour);
	}
}

t_array		*astar_get_path(
	t_astar *astar, const t_vector3 start, const t_vector3 target)
{
	t_anode		*node;

	node = (t_anode*)arr_get(
		astar->map, (int)target.x + (int)target.y * astar->size_x);
	astar->target = node;
	node = (t_anode*)arr_get(
		astar->map, (int)start.x + (int)start.y * astar->size_x);
	if (!node || !astar->target)
		return (NULL);
	node->h = get_dist(*node, *astar->target);
	node->f = node->h;
	arr_push(astar->open, (long long)node);
	return (calc_path(astar));
}
