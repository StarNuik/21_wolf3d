/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:00:48 by sbosmer           #+#    #+#             */
/*   Updated: 2019/06/08 14:27:51 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_audio(t_data *d)
{
	read_audio(d, "./sounds/song1.wav", 0);
	read_audio(d, "./sounds/walk_g.wav", 1);
	read_audio(d, "./sounds/hit.wav", 2);
	// SDL_PauseAudio(0);
	play_audio(d, 0);
}

void	init_sdl(t_data *d)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	d->sdl.win = SDL_CreateWindow("Abc, don't bite me!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);
	d->sdl.ren = SDL_CreateRenderer(d->sdl.win, -1, SDL_RENDERER_ACCELERATED);
	d->sdl.tex_out = SDL_CreateTexture(d->sdl.ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, TEX_WIDTH, TEX_HEIGHT);
	init_audio(d);
}