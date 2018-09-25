/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_go_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 18:45:50 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/23 18:45:53 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ftlmn_go_back(t_data *d, t_room *room)
{
	t_links		*l;

	room->visit = 1;
	l = room->links;
	while (l && l->room != d->end)
	{
		if (l->room->visit == 1 && l->room->dis >= room->dis)
		{
			l->room->visit = 0;
			room = l->room;
			l = l->room->links;
		}
		else
			l = l->next;
	}
}
