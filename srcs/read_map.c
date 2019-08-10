/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:46:55 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/10 15:18:36 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		parse_entity(t_data *d, char *idk)
{
	int			x;
	int			y;

	x = (d->scene.map_x ? arr_length(d->map_origin) % d->scene.map_x
						: arr_length(d->map_origin));
	y = (d->scene.map_x ? arr_length(d->map_origin) / d->scene.map_x : 0);
	if (*idk == 'e')
	{
		if (!parse_enemy(d, idk, x, y))
			return (0);
	}
	else if (*idk == 'o')
	{
		if (!parse_object(d, idk, x, y))
			return (0);
	}
	return (arr_push(d->map_origin, 0));
}

void		work_single(t_data *d, char *idk, int max_x)
{
	char	test;

	test = -1;
	if (*idk == 'p')
	{
		if (max_x)
			d->scene.player.pos = (t_vector3){
				arr_length(d->map_origin) % max_x + 0.5,
				arr_length(d->map_origin) / max_x + 0.5, 0.0};
		test = arr_push(d->map_origin, 0);
	}
	(*idk == 'a' ? test = arr_push(d->map_origin, 7) : 0);
	(*idk == 'c' ? test = arr_push(d->map_origin, 8) : 0);
	(*idk == 's' ? test = arr_push(d->map_origin, -1) : 0);
	(*idk == 'e' || *idk == 'o' ? test = parse_entity(d, idk) : 0);
	(*idk == '.' ? test = arr_push(d->map_origin, 0) : 0);
	(*idk >= '1' && *idk <= '6' ?
		test = arr_push(d->map_origin, *idk - '0') : 0);
	(test == -1 ? map_exit(1) : 0);
	(test == 0 ? exit(5) : 0);
}

void		work_line(t_data *d, char **split)
{
	char	**ref;
	int		qt;

	qt = 0;
	ref = split;
	while (*split)
	{
		work_single(d, *split, d->scene.map_x ? d->scene.map_x : 0);
		free(*split);
		split++;
		qt++;
	}
	free(ref);
	if (!d->scene.map_x)
		d->scene.map_x = qt;
	else if (d->scene.map_x != qt)
		map_exit(2);
	d->scene.map_y++;
}

void		work(t_data *d, int fd)
{
	char	**split;
	char	*line;
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			exit(6);
		if (ret == 0)
			break ;
		if (*line == '#' || !ft_strncmp(line, "//", 2))
		{
			free(line);
			continue ;
		}
		split = ft_strsplit(line, ' ');
		if (split == NULL)
			exit(7);
		work_line(d, split);
		free(line);
	}
}

void		read_map(t_data *d, char *path)
{
	int			fd;

	d->map_origin = arr_init();
	d->scene.object_arr = arr_init();
	d->scene.destr_object_arr = arr_init();
	d->scene.pickup_arr = arr_init();
	d->scene.enemy_arr = arr_init();
	d->rend.object_order = arr_init();
	d->rend.sprite_queue = arr_init();
	if (!d->map_origin)
		exit(8);
	fd = open(path, O_RDONLY);
	if (fd <= 2)
		map_exit(3);
	work(d, fd);
	if (d->scene.map_x < 3 || d->scene.map_y < 3)
		map_exit(4);
	close(fd);
}
