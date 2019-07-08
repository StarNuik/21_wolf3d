/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:53:56 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/08 09:16:52 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		choose_object(t_object *cache, char *idk)
{
	(ft_atoi(idk) == 1 ? *cache = OBJ_CHAND : OBJ_NULL);
	(ft_atoi(idk) == 2 ? *cache = OBJ_LAMP : OBJ_NULL);
	(ft_atoi(idk) == 3 ? *cache = OBJ_TABLE : OBJ_NULL);
	(ft_atoi(idk) == 4 ? *cache = OBJ_TREASU : OBJ_NULL);
	(ft_atoi(idk) == 5 ? *cache = OBJ_BUSH : OBJ_NULL);
	(ft_atoi(idk) == 6 ? *cache = OBJ_TREE : OBJ_NULL);
	(ft_atoi(idk) == 7 ? *cache = OBJ_HEALTH : OBJ_NULL);
	(ft_atoi(idk) == 8 ? *cache = OBJ_AMMO : OBJ_NULL);
	(cache->rend.tex_id == -1 ? map_exit(-1) : 0);
}

char		parse_object(t_data *d, char *idk, const int x, const int y)
{
	t_object	*cache;

	cache = ft_memalloc(sizeof(t_object));
	choose_object(cache, ++idk);
	cache->rend.pos = (t_vector3){x + 0.5, y + 0.5, 0.0};
	if (cache->health > 0)
	{
		if (!arr_push(d->scene.destr_object_arr, (long long)cache))
			return (0);
	}
	else if (cache->pickup > 0)
	{
		if (!arr_push(d->scene.pickup_arr, (long long)cache))
			return (0);
	}
	else
		if (!arr_push(d->scene.object_arr, (long long)cache))
			return (0);
	if (!spritequeue_add(d, &cache->rend))
		return (0);
	return (1);
}