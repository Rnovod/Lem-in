/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_mng_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:24:57 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/04 17:24:58 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int	ftlmn_check_the_argv(t_data *d, char *av)
{
	while (*++av)
	{
		if (*av == 'w')
			d->arg_fl |= LMN_INFO_WAYS;
		else if (*av == 'f')
			d->arg_fl |= LMN_INFO_FARM;
		else if (*av == 't')
			d->arg_fl |= LMN_INFO_TRACE;
		else if (*av == 'l')
			d->arg_fl |= LMN_INFO_LEAKS;
		else if (*av == 'n')
			d->arg_fl |= LMN_NAME;
		else
		{
			d->arg_fl = 0;
			return (-1);
		}
	}
	return (0);
}

int					ftlmn_mng_argv(t_data *d, char **av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (!*(av[i]) || *(av[i]) != '-')
			return (-1);
		if (ftlmn_check_the_argv(d, av[i]) < 0)
			return (-1);
		++i;
	}
	if (d->arg_fl & LMN_INFO_TRACE)
	{
		remove("lmn.trace");
		if ((d->fd = open("lmn.trace", O_RDWR | O_CREAT, 0666)) < 0)
			d->arg_fl ^= LMN_INFO_TRACE;
		else
			ft_dprintf(d->fd, "Start reading the ant farm.\n"
			"Start reading ant.\n");
	}
	return (0);
}
