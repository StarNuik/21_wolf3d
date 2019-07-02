/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:55:38 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/02 23:45:44 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		static_itoa(int num, int a[], int ct)
{
	while (--ct >= 0)
	{
		a[ct] = num % 10;
		num = num / 10;
	}
}