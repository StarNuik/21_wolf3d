/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:15:47 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/08 09:28:19 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		choose_enemy(t_enemy *cache, char *idk)
{
	(ft_atoi(idk) == 1 ? *cache = ENEMY_TEST : ENEMY_NULL);
	(cache->rend.tex_id == -1 ? map_exit(-1) : 0);
}

char		parse_enemy(t_data *d, char *idk, const int x, const int y)
{
	t_enemy		*cache;

	cache = ft_memalloc(sizeof(t_enemy));
	choose_enemy(cache, ++idk);
	cache->rend.pos = (t_vector3){x + .5f, y + .5f, 0.f};
	if (!arr_push(d->scene.enemy_arr, (long long)cache))
		return (0);
	if (!spritequeue_add(d, &cache->rend))
		return (0);
	return (1);
}