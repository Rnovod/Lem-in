/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_put_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 19:52:06 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/24 19:52:07 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int	ftlmn_motion_ant(t_data *d)
{
	t_ways	*way;
	t_links	*link;
	int		ant;
	int		move;

	move = 0;
	way = d->ways;
	while (way)
	{
		link = way->end->prev;
		while (link)
		{
			ant = link->room->ant;
			if (ant != 0)
			{
				link->next->room->ant = ant;
				ft_printf("L%d-%s ", ant, link->next->room->name);
				link->room->ant = 0;
				move = 1;
			}
			link = link->prev;
		}
		way = way->next;
	}
	return (move);
}

static inline void	ftlmn_start_ant(t_data *d)
{
	int			count_way;
	t_ways		*way;
	static int	ant = 1;
	int			len;

	way = d->ways;
	len = 0;
	count_way = 0;
	while (way && d->ants - ant + 1 > 0)
	{
		if (len && (way->len - len / count_way) * count_way >=
			d->ants - ant + 1 + count_way)
			break ;
		way->start->next->room->ant = ant;
		ft_printf("L%d-%s ", ant++, way->start->next->room->name);
		len += way->len;
		way = way->next;
		count_way++;
	}
}

void				ftlmn_put_ants(t_data *d)
{
	int	breaker;

	breaker = 0;
	while (42)
	{
		if (ftlmn_motion_ant(d) == 0)
		{
			if (++breaker != 1)
				break ;
		}
		ftlmn_start_ant(d);
		ft_putchar('\n');
	}
}
