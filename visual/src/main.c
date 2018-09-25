/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:17:35 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/05 17:17:36 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int					main(void)
{
	t_vdata		d;
	t_sdl_data	s;

	ft_bzero(&d, sizeof(t_vdata));
	ft_bzero(&s, sizeof(t_sdl_data));
	d.sdl = &s;
	d.speed = SPEED_ANT;
	ftlmnv_read_data(&d);
	ftlmnv_init_sdl(&d, &s);
	ftlmnv_create_backgrd(&d, &s);
	ftlmnv_draw_farm(&d, &s);
	ftlmnv_exit(&d, EXIT_SUCCESS);
}
