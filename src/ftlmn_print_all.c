/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_print_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 19:53:13 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/23 19:53:14 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ftlmn_print_all(t_data *d)
{
	int		ants;

	ants = 1;
	if (d->arg_fl & LMN_INFO_TRACE)
	{
		ft_dprintf(d->fd, "There is the one shortest way between start"
			"and end.\nThis way is %s->%s\n", d->start->name, d->end->name);
		ft_dprintf(d->fd, "Putting ants on the way.\n");
	}
	while (ants <= d->ants)
	{
		ft_printf("L%d-%s", ants++, d->end->name);
		if (ants <= d->ants)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
