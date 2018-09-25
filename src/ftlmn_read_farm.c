/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_read_farm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:29:25 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/14 16:29:26 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int		ftlmn_init_value(t_pars *p)
{
	ft_bzero(p, sizeof(t_pars));
	p->output_size = OUTPUT_SIZE;
	if (!(p->output = ft_arr_realloc(NULL, p->output_size)))
		return (-1);
	return (0);
}

static inline void		ftlmn_read_room_links(t_data *d, t_pars *p)
{
	if (ftlmn_rooms(d, p) < 0)
		ftlmn_error(d, p, 7);
	if (!d->start || !d->end || d->start == d->end)
	{
		if (!d->start)
			ftlmn_error(d, p, 3);
		else if (!d->end)
			ftlmn_error(d, p, 4);
		else
			ftlmn_error(d, p, 8);
	}
	if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Reading rooms complete.\nStart reading links.\n");
	if (p->flags)
		ftlmn_error(d, p, 11);
	if (ftlmn_links(d, p) < 0 && d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Start/end/anteater command can't be in links\n");
}

char					**ftlmn_read_farm(t_data *d)
{
	t_pars		p;

	if (ftlmn_init_value(&p) < 0)
		ftlmn_error(d, NULL, 0);
	if ((d->ants = ftlmn_ants(d, &p)) < 0)
		ftlmn_error(d, &p, 9);
	if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Reading ant complete.\nNumber of ants: %d"
			"\nStart reading rooms.\n", d->ants);
	if (!(d->begin = (t_room*)ft_memalloc(sizeof(t_room))))
		ftlmn_error(d, &p, 0);
	p.ptr = d->begin;
	ftlmn_read_room_links(d, &p);
	if (d->arg_fl & LMN_INFO_TRACE)
	{
		if (!p.line)
			ft_dprintf(d->fd, "End of reading.\n");
		else
			ft_dprintf(d->fd, "End of reading on invalid line:\n%s\n", p.line);
		ft_dprintf(d->fd, "Reading links complete.\n");
	}
	if (p.line)
		ft_strdel(&p.line);
	return (p.output);
}
