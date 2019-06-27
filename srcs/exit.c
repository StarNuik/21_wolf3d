/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:52:54 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/27 10:30:34 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		clean_sdl(t_data *d)
{
	SDL_Log("Commiting isekai...");
	SDL_FreeWAV(d->sound_pool[0].buffer);
	SDL_FreeWAV(d->sound_pool[1].buffer);
	SDL_FreeWAV(d->sound_pool[2].buffer);
	stbi_image_free(d->tex_pool[0].data);
	stbi_image_free(d->tex_pool[1].data);
	stbi_image_free(d->tex_pool[2].data);
	stbi_image_free(d->tex_pool[3].data);
	stbi_image_free(d->tex_pool[4].data);
	stbi_image_free(d->tex_pool[5].data);
	stbi_image_free(d->tex_pool[6].data);
	stbi_image_free(d->tex_pool[7].data);
	stbi_image_free(d->tex_pool[8].data);
	stbi_image_free(d->tex_pool[9].data);
	stbi_image_free(d->tex_pool[10].data);
	stbi_image_free(d->tex_pool[11].data);
	stbi_image_free(d->tex_pool[12].data);
	SDL_DestroyTexture(d->sdl.tex_out);
	SDL_DestroyTexture(d->sdl.tex_gui);
	SDL_DestroyTexture(d->sdl.tex_sprite);
	SDL_DestroyRenderer(d->sdl.ren);
	SDL_DestroyWindow(d->sdl.win);
	SDL_Log("Isekai commitment successful!");
	SDL_Quit();
}

void		map_exit(int code)
{
	if (code == 1)
		ft_putendl("Map has forbidden symbols!");
	else if (code == 2)
		ft_putendl("Map has different length rows!");
	else if (code == 3)
		ft_putendl("Map doesn't exist!");
	else if (code == 4)
		ft_putendl("Map is too small.");
	else
		ft_putendl("All your map are belong to us!");
	exit(1);
}

void		try_exit(t_data *d)
{
	clean_sdl(d);
	exit(0);
}
