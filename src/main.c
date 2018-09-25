/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:32:23 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/13 17:32:24 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	ftlmn_print_info(const t_data *d)
{
	const t_room	*ptr = d->begin->next;
	const t_links	*ptr1;

	ptr = d->begin->next;
	ft_printf("ants=%d\n\n", d->ants);
	while (ptr)
	{
		ft_printf("room name: %s\n", ptr->name);
		ft_printf("dis: %d\n", ptr->dis);
		ft_printf("visit: %d\n", ptr->visit);
		ft_printf("size: %d\n", ptr->size);
		ft_printf("links:\n");
		if (ptr->links)
		{
			ptr1 = ptr->links;
			while (ptr1)
			{
				ft_printf("%s-%s\n", ptr->name, ptr1->room->name);
				ptr1 = ptr1->next;
			}
		}
		ft_printf("\n");
		ptr = ptr->next;
	}
}

static inline void	ftlmn_print_ways(const t_data *d)
{
	const t_ways	*w = d->ways;
	t_links			*ptr1;

	while (w)
	{
		ptr1 = w->start;
		ft_printf("lenght of way: %d\n", w->len);
		while (ptr1)
		{
			ft_printf("%s", ptr1->room->name);
			ptr1 = ptr1->next;
			if (ptr1)
				ft_printf("->");
		}
		ft_printf("\n");
		if (w->next)
			ft_printf("\n");
		w = w->next;
	}
	ft_printf("\n");
}

static inline void	ftlmn_print_ants(t_data *d)
{
	if (d->arg_fl & LMN_INFO_FARM)
		ftlmn_print_info(d);
	if (d->end->dis == 2)
		ftlmn_print_all(d);
	else
	{
		if (d->arg_fl & LMN_INFO_TRACE)
			ft_dprintf(d->fd, "Start to find ways.\n");
		ftlmn_find_ways(d);
		if (d->arg_fl & LMN_INFO_WAYS)
			ftlmn_print_ways(d);
		if (d->arg_fl & LMN_INFO_TRACE)
			ft_dprintf(d->fd, "Putting ants on ways.\n");
		ftlmn_put_ants(d);
	}
	if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "All ants in the end.\n");
}

static inline void	ftlmn_start_algorithm(t_data *d, char **output)
{
	if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Starting BFS algorithm.\n");
	ftlmn_bfs(d);
	if (!d->end->dis)
	{
		ft_arrfree(&output);
		ftlmn_error(d, NULL, 5);
	}
	ft_printf("%m\n", output);
	ft_arrfree(&output);
	ftlmn_print_ants(d);
}

int					main(int ac, char **av)
{
	t_data	d;
	char	**output;

	ft_bzero(&d, sizeof(t_data));
	if (ac != 1 && ftlmn_mng_argv(&d, &av[1]) < 0)
		ftlmn_error(&d, NULL, -1);
	output = ftlmn_read_farm(&d);
	ftlmn_start_algorithm(&d, output);
	ftlmn_exit(&d, EXIT_SUCCESS);
}
