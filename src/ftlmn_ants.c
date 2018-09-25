/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:14:45 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/17 13:14:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int	ftlmn_get_ants(t_data *d, t_pars *p)
{
	char			*cp;
	long int		num;

	cp = p->line;
	num = 0;
	if (p->output_size <= p->i)
		ftlmn_output(d, p);
	p->output[p->i++] = p->line;
	if (!*cp)
		ftlmn_error(d, p, 1);
	while (*cp >= '0' && *cp <= '9' && cp - p->line < 10)
		num = num * 10 + *cp++ - '0';
	if (cp - p->line > 10 || num > 2147483647)
		ftlmn_error(d, p, 2);
	if (*cp)
		ftlmn_error(d, p, 1);
	if (!num)
		ftlmn_error(d, p, 10);
	return ((int)num);
}

int					ftlmn_ants(t_data *d, t_pars *p)
{
	int		ret;

	p->line = NULL;
	while (!p->flags && (ret = get_next_line(0, &p->line)) > 0)
	{
		if (*p->line == '#' && *(p->line + 1) != '#')
			ftlmn_get_comment(d, p);
		else if (*p->line == '#' && *(p->line + 1) == '#')
			ftlmn_get_command(d, p);
		else
			return (ftlmn_get_ants(d, p));
		p->line = NULL;
	}
	if (ret < 0)
		ftlmn_error(d, p, 0);
	if (!p->line && !p->flags)
		ftlmn_error(d, p, 12);
	return (-1);
}
