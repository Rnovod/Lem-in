/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 20:02:49 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/22 20:02:50 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** variables type of t_links are using as queue here
*/

static inline void		ftlmn_free_queue(t_links *q)
{
	t_links	*tmp;

	while (q)
	{
		tmp = q;
		q = q->next;
		free(tmp);
	}
}

static inline t_links	*ftlmn_create_queue(t_data *d, t_room *r, int dis)
{
	t_links	*q;

	if (!(q = (t_links*)ft_memalloc(sizeof(t_links))))
		ftlmn_error(d, NULL, 0);
	q->room = r;
	q->room->dis = dis;
	if (q->room != d->start && q->room != d->end)
		q->room->size++;
	return (q);
}

void					ftlmn_bfs(t_data *d)
{
	t_links	*begin;
	t_links	*l;
	t_links	*end;
	t_links	*q;

	begin = ftlmn_create_queue(d, d->start, 1);
	q = begin;
	end = q;
	while (q)
	{
		l = q->room->links;
		if (q->room != d->end)
			while (l)
			{
				if (l->room->dis > q->room->dis || l->room->dis == 0)
				{
					end->next = ftlmn_create_queue(d, l->room,
						q->room->dis + 1);
					end = end->next;
				}
				l = l->next;
			}
		q = q->next;
	}
	ftlmn_free_queue(begin);
}
