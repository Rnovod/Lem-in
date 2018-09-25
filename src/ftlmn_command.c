/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:15:34 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/17 13:15:35 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ftlmn_get_command(t_data *d, t_pars *p)
{
	if (p->output_size <= p->i)
		ftlmn_output(d, p);
	p->output[p->i++] = p->line;
	if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Reading the command line:\n%s\n", p->line);
	if (p->flags)
		ftlmn_error(d, p, 11);
	if (!ft_strcmp(p->line, "##start"))
		p->flags = p->flags | START;
	else if (!ft_strcmp(p->line, "##end"))
		p->flags = p->flags | END;
	else if (!ft_strcmp(p->line, "##anteater"))
		p->flags = p->flags | ANTEATER;
	else if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Unknown command ignored: %s\n", p->line);
}
