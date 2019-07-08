/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_fps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:03:10 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/08 07:57:43 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		debug_output(t_data *d)
{
	// printf("Sizeof t_object: %lu\n", sizeof(t_object));
	printf("astar: %p\n", d->scene.astar);
	// printf("\n");
	// printf("\n");
	// printf("\n");
	// printf("\n");
	// printf("\n");
	(void)d;
}

void		todo_list()
{
	printf("\e[30m\n\n\n");
	printf("\e[47m. Todo list:						.\n");
	printf("\e[47m. Type	Desc						.\n");
	printf("\e[100m. \e[32mADD\e[30m	Enemy pathfinding (use A*)			.\n");
	printf("\e[100m. \e[32mADD\e[30m	Enemy animation					.\n");
	printf("\e[100m. \e[32mADD\e[30m	Enemy attacks					.\n");
	printf("\e[100m. \e[32mADD\e[30m	Enemy object					.\n");
	printf("\e[100m. \e[32mADD\e[30m	Object destruction sprites			.\n");
	printf("\e[100m. \e[33mFIX\e[30m	Switch to sprite sheets				.\n");
	printf("\e[100m. \e[32mADD\e[30m	Doors						.\n");
	printf("\e[100m. \e[32mADD\e[30m	Gates						.\n");
	printf("\e[100m. \e[32mADD\e[30m	Gate switches					.\n");
	printf("\e[100m. \e[33mFIX\e[30m	Sprite size on close-ups			.\n");
	printf("\e[100m. \e[33mFIX\e[30m	Change to camera plane				.\n");
	printf("\e[39m\e[49m\n");
	// printf("\e[100m. \e[33mFIX\e[30m	Sprite size			.\n");
	// printf("\e[100m. \e[32mADD\e[30m	Enemy pathfinding (use random)	.\n");
	// printf("\e[100m. \e[31mBUG\e[30m	Lag spike on object interaction	.\n");
}

void		profiler_output(t_data *d, int diff)
{
	const int green_frame_time = 16;
	const int yellow_frame_time = 33;
	const int red_frame_time = 44;
	const int green_render_time = 16;
	const int yellow_render_time = 33;


	printf("\e[1;1H\e[2J");
	if (diff <= green_frame_time)
		printf("Last frame took:		\e[32m%d\e[39m ms\n", diff);
	else if (diff <= yellow_frame_time)
		printf("Last frame took:		\e[33m%d\e[39m ms\n", diff);
	else if (diff <= red_frame_time)
		printf("Last frame took:		\e[91m%d\e[39m ms\n", diff);
	else
		printf("Last frame took:		\e[103m\e[91m%d\e[39m\e[49m ms\n", diff);
	printf("Frames per second:		%.2f\n", 1000.0 / (float)diff);
	printf("\n");

	if (PR_ELAPSED(4) <= green_render_time)
		printf("Raycast:			\e[32m%d\e[39m ms\n", PR_ELAPSED(4));
	else if (PR_ELAPSED(4) <= yellow_render_time)
		printf("Raycast:			\e[33m%d\e[39m ms\n", PR_ELAPSED(4));
	else
		printf("Raycast:			\e[91m%d\e[39m ms\n", PR_ELAPSED(4));

	if (PR_ELAPSED(5) <= green_render_time)
		printf("Sprite sorting:			\e[32m%d\e[39m ms\n", PR_ELAPSED(5));
	else if (PR_ELAPSED(5) <= yellow_render_time)
		printf("Sprite sorting:			\e[33m%d\e[39m ms\n", PR_ELAPSED(5));
	else
		printf("Sprite sorting:			\e[91m%d\e[39m ms\n", PR_ELAPSED(5));

	if (PR_ELAPSED(0) <= green_render_time)
		printf("Player:				\e[32m%d\e[39m ms\n", PR_ELAPSED(0));
	else if (PR_ELAPSED(0) <= yellow_render_time)
		printf("Player:				\e[33m%d\e[39m ms\n", PR_ELAPSED(0));
	else
		printf("Player:				\e[91m%d\e[39m ms\n", PR_ELAPSED(0));

	if (PR_ELAPSED(6) <= green_render_time)
		printf("Enemy:				\e[32m%d\e[39m ms\n", PR_ELAPSED(6));
	else if (PR_ELAPSED(6) <= yellow_render_time)
		printf("Enemy:				\e[33m%d\e[39m ms\n", PR_ELAPSED(6));
	else
		printf("Enemy:				\e[91m%d\e[39m ms\n", PR_ELAPSED(6));

	if (PR_ELAPSED(1) <= green_render_time)
		printf("Rendering walls:		\e[32m%d\e[39m ms\n", PR_ELAPSED(1));
	else if (PR_ELAPSED(1) <= yellow_render_time)
		printf("Rendering walls:		\e[33m%d\e[39m ms\n", PR_ELAPSED(1));
	else
		printf("Rendering walls:		\e[91m%d\e[39m ms\n", PR_ELAPSED(1));

	if (PR_ELAPSED(2) <= green_render_time)
		printf("Rendering sprites:		\e[32m%d\e[39m ms\n", PR_ELAPSED(2));
	else if (PR_ELAPSED(2) <= yellow_render_time)
		printf("Rendering sprites:		\e[33m%d\e[39m ms\n", PR_ELAPSED(2));
	else
		printf("Rendering sprites:		\e[91m%d\e[39m ms\n", PR_ELAPSED(2));

	if (PR_ELAPSED(3) <= green_render_time)
		printf("Rendering GUI:			\e[32m%d\e[39m ms\n", PR_ELAPSED(3));
	else if (PR_ELAPSED(3) <= yellow_render_time)
		printf("Rendering GUI:			\e[33m%d\e[39m ms\n", PR_ELAPSED(3));
	else
		printf("Rendering GUI:			\e[91m%d\e[39m ms\n", PR_ELAPSED(3));
	// todo
	todo_list();
	debug_output(d);
	(void)d;
}

void		wait_for_next_frame(t_data *d)
{
	const unsigned int	time = SDL_GetTicks();
	int					diff;

	diff = time - d->pr.frame_start;
	if (time >= d->pr.last_message + 500)
	{
		profiler_output(d, diff);
		d->pr.last_message = time;
	}
	diff = TARGET_MS - diff;
	if (diff > 0)
		SDL_Delay(diff);
}
