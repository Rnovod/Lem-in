/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:30:15 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/06 13:30:15 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline void	ftlmnv_sdl_error(int error)
{
	if (error == -1)
		ft_printf("SDL Error: %s\n", SDL_GetError());
	else if (error == -2)
		ft_printf("SDL_image Error: %s\n", IMG_GetError());
	else if (error == -3)
		ft_printf("SDL_ttf Error: %s\n", TTF_GetError());
}

void				ftlmnv_error(t_vdata *d, int error)
{
	if (error < 0)
		ftlmnv_sdl_error(error);
	else if (error == 1)
		ft_printf("Error: %s\n", strerror(errno));
	else if (error == 2)
		ft_printf("Error: lem-in error.\n");
	else if (error == 3)
		ft_printf("Error: invalid ant number or no rooms.\n");
	else if (error == 4)
		ft_printf("Error: invalid room format or no links.\n");
	else if (error == 5)
		ft_printf("Error: invalid links.\n");
	else if (error == 6)
		ft_printf("Error: problem in pars moves.\n");
	else if (error == 7)
		ft_printf("Error: No data.\n");
	else if (error == 8)
		ft_printf("Error: to much rooms(>30).\n");
	else if (error == 9)
		ft_printf("Error: invalid coordinate.\n");
	else if (error == 10)
		ft_printf("Error: name is too long.\n");
	ftlmnv_exit(d, error);
}
