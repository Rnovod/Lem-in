/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:30:19 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/06 13:30:20 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline void	ftlmnv_free_moves(t_moves *m)
{
	t_ant	*ant;
	t_ant	*ant_tmp;
	t_moves	*m_tmp;

	while (m)
	{
		ant = m->ants;
		while (ant)
		{
			ant_tmp = ant;
			ant = ant->next;
			free(ant_tmp);
		}
		m_tmp = m;
		m = m->next;
		free(m_tmp);
	}
}

static inline void	ftlmnv_free_rooms(t_vroom *r)
{
	t_vlink	*l;
	t_vlink	*l_tmp;
	t_vroom	*r_tmp;

	while (r)
	{
		l = r->links;
		while (l)
		{
			l_tmp = l;
			l = l->next;
			free(l_tmp);
		}
		free(r->name);
		r_tmp = r;
		r = r->next;
		free(r_tmp);
	}
}

void				ftlmnv_exit(t_vdata *d, int status)
{
	if (d->file)
		ft_arrfree(&d->file);
	if (d->sdl)
	{
		TTF_CloseFont(d->sdl->font);
		SDL_DestroyTexture(d->sdl->anteater);
		SDL_DestroyTexture(d->sdl->ant_mov[0]);
		SDL_DestroyTexture(d->sdl->ant_mov[1]);
		SDL_DestroyTexture(d->sdl->ant_mov[2]);
		SDL_DestroyTexture(d->sdl->ant_mov[3]);
		SDL_DestroyTexture(d->sdl->ant[0]);
		SDL_DestroyTexture(d->sdl->ant[1]);
		SDL_DestroyTexture(d->sdl->background);
		SDL_DestroyRenderer(d->sdl->rend);
		SDL_DestroyWindow(d->sdl->win);
		IMG_Quit();
		TTF_Quit();
		SDL_Quit();
	}
	if (d->b)
		ftlmnv_free_rooms(d->b);
	if (d->begin_moves)
		ftlmnv_free_moves(d->begin_moves);
	exit(status);
}
