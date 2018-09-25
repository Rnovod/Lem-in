/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_init_sdl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:30:33 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/06 13:30:34 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline SDL_Texture	*ftlmnv_load_texture(t_vdata *d, const char *file)
{
	SDL_Surface	*sur;
	SDL_Texture	*ant;

	if (!(sur = IMG_Load(file)))
		ftlmnv_error(d, -2);
	if (!(ant = SDL_CreateTextureFromSurface(d->sdl->rend, sur)))
	{
		SDL_FreeSurface(sur);
		ftlmnv_error(d, -1);
	}
	SDL_FreeSurface(sur);
	return (ant);
}

static inline void			ftlmnv_load_all_texture(t_vdata *d, t_sdl_data *s)
{
	s->anteater = ftlmnv_load_texture(d, "./visual/img/anteater.png");
	s->ant[0] = ftlmnv_load_texture(d, "./visual/img/ant.png");
	s->ant[1] = ftlmnv_load_texture(d, "./visual/img/ant_back.png");
	s->ant_mov[0] = ftlmnv_load_texture(d, "./visual/img/ant_mov1.png");
	s->ant_mov[1] = ftlmnv_load_texture(d, "./visual/img/ant_mov2.png");
	s->ant_mov[2] = ftlmnv_load_texture(d, "./visual/img/ant_back_mov1.png");
	s->ant_mov[3] = ftlmnv_load_texture(d, "./visual/img/ant_back_mov2.png");
}

void						ftlmnv_init_sdl(t_vdata *d, t_sdl_data *s)
{
	SDL_Surface	*sur;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ftlmnv_error(d, -1);
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != (IMG_INIT_JPG | IMG_INIT_PNG))
		ftlmnv_error(d, -2);
	if (TTF_Init() == -1)
		ftlmnv_error(d, -3);
	if (!(s->win = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0)))
		ftlmnv_error(d, -1);
	if (!(s->rend = SDL_CreateRenderer(s->win, -1, SDL_RENDERER_TARGETTEXTURE)))
		ftlmnv_error(d, -1);
	if (!(s->font = TTF_OpenFont("./visual/font/Roboto-black.ttf", 32)))
		ftlmnv_error(d, -3);
	if (!(sur = IMG_Load("./visual/img/ant_icon.png")))
		ftlmnv_error(d, -2);
	SDL_SetWindowIcon(s->win, sur);
	SDL_FreeSurface(sur);
	ftlmnv_load_all_texture(d, s);
}
