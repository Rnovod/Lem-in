/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_command_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:54:14 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/24 11:54:15 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void		ftlmn_trace_command(t_data *d, t_pars *p, t_room *room)
{
	if (p->flags & START)
	{
		ft_dprintf(d->fd, "Start room is: |%s|\n", room->name);
		if (d->start && d->start != room)
			ft_dprintf(d->fd, "Warning: start changed. Start was: |%s|\n",
			d->start->name);
	}
	else if (p->flags & END)
	{
		ft_dprintf(d->fd, "End room is: |%s|\n", room->name);
		if (d->end && d->end != room)
			ft_dprintf(d->fd, "Warning: end changed. End was: |%s|\n",
			d->end->name);
	}
	else if (p->flags & ANTEATER)
		ft_dprintf(d->fd, "Anteater room is: |%s|\n", room->name);
}

void					ftlmn_command_room(t_data *d, t_pars *p, t_room *room)
{
	if (d->arg_fl & LMN_INFO_TRACE)
		ftlmn_trace_command(d, p, room);
	if (p->flags & START)
		d->start = room;
	else if (p->flags & END)
		d->end = room;
	else if (p->flags & ANTEATER)
	{
		room->dis = -1;
		room->visit = 1;
	}
	p->flags &= 0;
}
