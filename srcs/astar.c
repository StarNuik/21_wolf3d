/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 23:55:22 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 17:16:43 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		check_walkable(
	const size_t id, const long long val, void *test_val, void *walkable)
{
	if (val == *(long long*)test_val)
		*(char*)(walkable) = 1;
	(void)id;
}

int			get_dist(const t_anode a, const t_anode b)
{
	const int	delta_x = ft_abs(a.x - b.x);
	const int	delta_y = ft_abs(a.y - b.y);

	if (delta_x > delta_y)
		return (delta_y * 14 + (delta_x - delta_y) * 10);
	return (delta_x * 14 + (delta_y - delta_x) * 10);
}

t_anode		*get_cheapest_node(t_astar *astar)
{
	t_anode			*node;
	t_anode			*temp;
	const size_t	len = arr_length(astar->open);
	size_t			qt;

	node = (t_anode*)arr_top(astar->open);
	qt = -1;
	while (++qt < len)
	{
		temp = (t_anode*)arr_get(astar->open, qt);
		if (temp->f < node->f || (temp->f == node->f && temp->h < node->h))
			node = temp;
	}
	return (node);
}

void		work_neighbour(
	const size_t id, const long long val, void *astar_v, void *node_v)
{
	t_astar		*astar;
	t_anode		*parent;
	t_anode		*neighbour;
	int			new_cost;
	char		contains;

	astar = (t_astar*)astar_v;
	parent = (t_anode*)node_v;
	neighbour = (t_anode*)val;
	if (!neighbour->walkable ||
		arr_contains(astar->closed, (long long)neighbour))
		return ;
	new_cost = parent->g + get_dist(*parent, *neighbour);
	contains = arr_contains(astar->open, (long long)neighbour);
	if (new_cost < neighbour->g || !contains)
	{
		neighbour->g = new_cost;
		neighbour->h = get_dist(*neighbour, *astar->target);
		neighbour->f = neighbour->g + neighbour->h;
		neighbour->parent = parent;
		if (!contains)
			arr_push(astar->open, (long long)neighbour);
	}
	(void)id;
}

void		clean_node(const size_t id, const long long val)
{
	t_anode		*node;

	node = (t_anode*)val;
	node->f = 0;
	node->g = 0;
	node->h = 0;
	node->parent = NULL;
	(void)id;
}
