/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:04:09 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/06 04:54:33 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STB_IMAGE_IMPLEMENTATION
#include "wolf.h"

int		main(void)
{
	t_data	d;

	init(&d);
	general_pipe(&d);
	try_exit(&d);
	return (0);
}
