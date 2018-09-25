/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:15:40 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/17 13:15:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ftlmn_get_comment(t_data *d, t_pars *p)
{
	if (p->output_size > p->i)
		ftlmn_output(d, p);
	p->output[p->i++] = p->line;
	if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Read the comment:\n%s\n", p->line);
}
