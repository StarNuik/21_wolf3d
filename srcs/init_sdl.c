/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:00:48 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/03 13:03:46 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_sdl(t_data *d)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	d->sdl.win = SDL_CreateWindow("Wolf4dEAD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);
	d->sdl.ren = SDL_CreateRenderer(d->sdl.win, -1, SDL_RENDERER_ACCELERATED);
	d->sdl.tex_bg = SDL_CreateTexture(d->sdl.ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, TEX_WIDTH, TEX_HEIGHT);
	d->sdl.tex_wall = SDL_CreateTexture(d->sdl.ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, TEX_WIDTH, TEX_HEIGHT);
	d->sdl.tex_sprite = SDL_CreateTexture(d->sdl.ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, TEX_WIDTH, TEX_HEIGHT);
	d->sdl.tex_gui_bg = SDL_CreateTexture(d->sdl.ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, TEX_WIDTH, TEX_HEIGHT);
	d->sdl.tex_gui = SDL_CreateTexture(d->sdl.ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, TEX_WIDTH, TEX_HEIGHT);
	SDL_SetTextureBlendMode(d->sdl.tex_bg, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(d->sdl.tex_wall, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(d->sdl.tex_sprite, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(d->sdl.tex_gui_bg, SDL_BLENDMODE_BLEND);
	SDL_SetTextureBlendMode(d->sdl.tex_gui, SDL_BLENDMODE_BLEND);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}