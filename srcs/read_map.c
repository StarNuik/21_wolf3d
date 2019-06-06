/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:46:55 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 03:40:43 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_array		*read_map(char *path)
{
	t_array		*res;
	long long	a[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	long long	b[15] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
	long long	c[15] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
	long long	z[15] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
	long long	e[15] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1};
	long long	f[15] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1};
	long long	g[15] = {1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1};
	long long	h[15] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1};
	long long	i[15] = {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
	long long	j[15] = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1};
	long long	k[15] = {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1};
	long long	l[15] = {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1};
	long long	m[15] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
	long long	n[15] = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
	long long	o[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	(void)path;
	res = arr_init();
	arr_absorb(res, a, 15);
	arr_absorb(res, b, 15);
	arr_absorb(res, c, 15);
	arr_absorb(res, z, 15);
	arr_absorb(res, e, 15);
	arr_absorb(res, f, 15);
	arr_absorb(res, g, 15);
	arr_absorb(res, h, 15);
	arr_absorb(res, i, 15);
	arr_absorb(res, j, 15);
	arr_absorb(res, k, 15);
	arr_absorb(res, l, 15);
	arr_absorb(res, m, 15);
	arr_absorb(res, n, 15);
	arr_absorb(res, o, 15);
	return (res);
}
