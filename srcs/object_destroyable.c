/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_destroyable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:37:45 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/07 09:45:41 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		damage_object(t_data *d, t_object *obj, const int damage)
{
	obj->health -= damage;
	if (obj->health <= 0)
	{
		arr_find_destroy(d->scene.destr_object_arr, (long long)obj);
		arr_push(d->scene.object_arr, (long long)obj);
		obj->rend.tex_id = obj->broke_tex_id;
	}
}