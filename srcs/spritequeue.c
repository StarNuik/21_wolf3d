/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritequeue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:03:23 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 16:03:34 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		spritequeue_remove(t_data *d, t_rendobj *obj)
{
	size_t			qt;
	const size_t	len = arr_length(d->rend.sprite_queue);

	qt = arr_find(d->rend.sprite_queue, (long long)obj);
	arr_drop(d->rend.sprite_queue, qt);
	arr_pop(d->rend.object_order);
	qt = -1;
	while (++qt < len)
		arr_set(d->rend.object_order, qt, qt);
}

char		spritequeue_add(t_data *d, t_rendobj *obj)
{
	if (!arr_push(d->rend.sprite_queue, (long long)obj))
		return (0);
	if (!arr_push(d->rend.object_order, arr_length(d->rend.object_order)))
		return (0);
	return (1);
}
