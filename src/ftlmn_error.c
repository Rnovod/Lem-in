/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:30:34 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/14 16:30:35 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	ftlmn_trace_2(t_data *d, int error)
{
	if (error == 6)
		ft_dprintf(d->fd, "invalid link.\n");
	else if (error == 5)
		ft_dprintf(d->fd, "there is no way.\n");
	else if (error == 8)
		ft_dprintf(d->fd, "start and end are same room\n");
	else if (error == 9)
		ft_dprintf(d->fd, "Command start/end/anteater"
			" must be after atns number.\n");
	else if (error == 10)
		ft_dprintf(d->fd, "ant number must be greater than 0.\n");
	else if (error == 11)
		ft_dprintf(d->fd, "Command start/end/anteater"
			"must be using to room.\n");
	else if (error == 12)
		ft_dprintf(d->fd, "No data.\n");
}

static inline void	ftlmn_trace(t_data *d, t_pars *p, int error)
{
	if (p)
		ft_dprintf(d->fd, "Error in line %d: ", p->i + 1);
	else
		ft_dprintf(d->fd, "Error: ");
	if (error == 1)
		ft_dprintf(d->fd, "incorrect ant format:\n|%s|\n", p->line);
	else if (error == 2)
		ft_dprintf(d->fd, "number of ant's is too big:\n|%s|\n", p->line);
	else if (error == 3)
		ft_dprintf(d->fd, "no start room.\n");
	else if (error == 4)
		ft_dprintf(d->fd, "no end room.\n");
	else if (error == 7)
	{
		if (!p->line)
			ft_dprintf(d->fd, "No room.\n");
		else
			ft_dprintf(d->fd, "incorrect room format:\n|%s|\n", p->line);
	}
	else
		ftlmn_trace_2(d, error);
}

void				ftlmn_error(t_data *d, t_pars *p, int error)
{
	if (error == -1)
		ft_printf("Error: Invalid argument.\nusage: lem-in [-ltwfn]\n"
			"l - for leaks(lmn.leaks)\n"
			"t - create the trace file lmn.trace\n"
			"w - show all possible ways on output\n"
			"f - information about rooms on output\n"
			"n - a room can have a name with \'-\'\n");
	else if (error == 0)
	{
		error = -1;
		ft_printf("{red}Error: %s\n{eoc}", strerror(errno));
	}
	else
	{
		if (d->arg_fl & LMN_INFO_TRACE)
			ft_putendl("ERROR"
				"(for error reason check the file lmn.trace)");
		else
			ft_putendl("ERROR");
	}
	if (d->arg_fl & LMN_INFO_TRACE)
		ftlmn_trace(d, p, error);
	if (p && p->output)
		ft_arrfree(&p->output);
	ftlmn_exit(d, error);
}
