/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:30:40 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/14 16:30:41 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	ftlmn_free_links(t_links *ptr)
{
	t_links	*tmp;

	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

static inline void	ftlmn_free_rooms(t_data *d)
{
	t_room	*ptr;
	t_room	*tmp;

	ptr = d->begin;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp->name);
		if (tmp->links)
			ftlmn_free_links(tmp->links);
		free(tmp);
	}
}

static inline void	ftlmn_free_ways(t_data *d)
{
	t_ways	*ptr;
	t_ways	*tmp;

	ptr = d->ways;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		ftlmn_free_links(tmp->start);
		free(tmp);
	}
}

void				ftlmn_exit(t_data *d, int status)
{
	ftlmn_free_rooms(d);
	ftlmn_free_ways(d);
	if (d->arg_fl & LMN_INFO_LEAKS)
	{
		if (d->arg_fl & LMN_INFO_TRACE)
			ft_dprintf(d->fd, "Checked leaks. "
				"Result put to the file lmn.leaks.\n");
		remove("lmn.leaks");
		system("leaks lem-in > lmn.leaks");
	}
	if (d->arg_fl & LMN_INFO_TRACE)
	{
		if (!status)
			ft_dprintf(d->fd, "Exitting status: success.\n");
		else
			ft_dprintf(d->fd, "Exitting status: failure.\n");
	}
	exit(status);
}
