/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_find_the_way.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:43:55 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/19 20:43:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_links	*ftlmn_create_step(t_room *r, t_links *next)
{
	t_links	*step;

	if (!(step = (t_links*)ft_memalloc(sizeof(t_links))))
		return (NULL);
	step->room = r;
	step->next = next;
	return (step);
}

static inline t_room	*ftlmn_choose_room(t_data *d, t_room *room)
{
	t_room	*r;
	t_links	*l;

	l = room->links;
	r = NULL;
	while (l)
	{
		if (l->room->visit == 0 && l->room != d->end &&
			(!r || (r->dis >= l->room->dis && r->size >= l->room->size)))
			r = l->room;
		l = l->next;
	}
	if (!r && room != d->end)
		ftlmn_go_back(d, room);
	return (r);
}

static inline int		ftlmn_way(t_data *d, t_ways *way)
{
	t_links	*step;
	t_room	*r;
	int		len;

	step = way->end;
	len = 0;
	r = NULL;
	while (r != d->start)
	{
		r = ftlmn_choose_room(d, step->room);
		if (!r && step->room == d->end)
			return (-1);
		else if (!r)
			return (0);
		if (r != d->start && r != d->end)
			r->visit = 1;
		if (!(step->prev = ftlmn_create_step(r, step)))
			ftlmn_error(d, NULL, 0);
		step = step->prev;
		len++;
	}
	way->start = step;
	way->len = len;
	return (1);
}

static inline int		ftlmn_find_the_way(t_data *d, t_ways *way)
{
	int		ret;
	t_links	*tmp;

	while (42)
	{
		if ((ret = ftlmn_way(d, way)) > 0)
			return (1);
		else if (ret < 0)
			return (0);
		tmp = way->end->prev;
		while (tmp && tmp->prev)
		{
			tmp = tmp->prev;
			free(tmp->next);
		}
		free(tmp);
		way->end->prev = NULL;
	}
}

void					ftlmn_find_ways(t_data *d)
{
	t_ways	*way;
	t_ways	*prev;

	if (!(way = (t_ways*)ft_memalloc(sizeof(t_ways))))
		ftlmn_error(d, NULL, 0);
	d->ways = way;
	while (42)
	{
		if (!(way->end = ftlmn_create_step(d->end, NULL)))
			ftlmn_error(d, NULL, 0);
		if (!ftlmn_find_the_way(d, way))
			break ;
		if (!(way->next = (t_ways*)ft_memalloc(sizeof(t_ways))))
			ftlmn_error(d, NULL, 0);
		prev = way;
		way = way->next;
	}
	free(prev->next->end);
	free(prev->next);
	prev->next = NULL;
}
