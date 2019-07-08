/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 23:55:22 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/08 07:31:57 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		check_walkable(const size_t id, const long long val, void *test_val, void *walkable)
{
	if (val == *(long long*)test_val)
		*(char*)(walkable) = 1;
	(void)id;
}

t_astar		*astar_init(t_array *map, t_array *walkable_mask, const int size_x, const int size_y)
{
	t_astar			*astar;
	t_anode			*node;
	int				qt;
	char			walkable;
	long long		val;

	if (!(astar = ft_memalloc(sizeof(t_astar))) || !(astar->open = arr_init()) || !(astar->closed = arr_init()) || !(astar->map = arr_init()))
		return (NULL);
	*(long long*)(&astar->size_x) = ((long long)size_x << 32) + size_y;
	qt = -1;
	while (++qt < size_x * size_y)
	{
		node = ft_memalloc(sizeof(t_anode));
		if (!node || !arr_push(astar->map, (long long)node))
			return (NULL);
		node->x = qt % size_x;
		node->y = qt / size_x;
		val = arr_get(map, qt);
		walkable = 0;
		arr_itervv(walkable_mask, &val, &walkable, &check_walkable);
		node->walkable = walkable;
	}
	return (astar);
}

int		get_dist(const t_anode a, const t_anode b)
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

void		work_neighbour(const size_t id, const long long val, void *astar_v, void *node_v)
{
	t_astar		*astar;
	t_anode		*parent;
	t_anode		*neighbour;
	int			new_cost;
	char		contains;

	astar = (t_astar*)astar_v;
	parent = (t_anode*)node_v;
	neighbour = (t_anode*)val;
	if (!neighbour->walkable || arr_contains(astar->closed, (long long)neighbour))
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

t_array		*retrace_path(t_astar *astar)
{
	t_array		*path;
	t_anode		*node;

	path = arr_init();
	node = (t_anode*)arr_last(astar->closed);
	while (node)
	{
		arr_unshift(path, (long long)node);
		node = node->parent;
	}
	arr_iter(astar->open, &clean_node);
	arr_iter(astar->closed, &clean_node);
	return (path);
}

void	get_neighbours(t_astar *astar, t_array *neighbours, t_anode *node)
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
			&& !(x == 0 && y == 0))
			{
				try = (t_anode*)arr_get(astar->map, node->x + x + (node->y + y) * astar->size_x);
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
			printf("Empty open set !!\n");
		if (arr_length(astar->open) == 0)
			return (NULL);
		node = get_cheapest_node(astar);
		arr_find_destroy(astar->open, (long long)node);
		arr_push(astar->closed, (long long)node);
		if (node == astar->target)
			return (retrace_path(astar));
		get_neighbours(astar, neighbours, node);
		arr_itervv(neighbours, astar, node, &work_neighbour);
	}
}

t_array		*astar_get_path(t_astar *astar, const t_vector3 start, const t_vector3 target)
{
	t_anode		*node;

	node = (t_anode*)arr_get(astar->map, (int)target.x + (int)target.y * astar->size_x);
	astar->target = node;
	node = (t_anode*)arr_get(astar->map, (int)start.x + (int)start.y * astar->size_x);
	node->h = get_dist(*node, *astar->target);
	node->f = node->h;
	arr_push(astar->open, (long long)node);
	return (calc_path(astar));
}
