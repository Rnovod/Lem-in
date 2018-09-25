/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:15:04 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/17 13:15:04 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int	ftlmn_create_link(t_data *d, t_pars *p,
					t_room *from, t_room *to)
{
	t_links	*links;

	if (!from->links)
	{
		if (!(from->links = (t_links*)ft_memalloc(sizeof(t_links))))
			ftlmn_error(d, p, 0);
		links = from->links;
	}
	else
	{
		links = from->links;
		while (links->next)
			links = links->next;
		if (!(links->next = (t_links*)ft_memalloc(sizeof(t_links))))
			ftlmn_error(d, p, 0);
		links = links->next;
	}
	links->room = to;
	return (0);
}

static inline int	ftlmn_check_links(t_data *d, t_pars *p,
					t_room *from, t_room *to)
{
	t_links	*ptr;

	ptr = from->links;
	if (p->output_size <= p->i)
		ftlmn_output(d, p);
	p->output[p->i++] = p->line;
	while (ptr)
	{
		if (ptr->room == to)
		{
			if (d->arg_fl & LMN_INFO_TRACE)
				ft_dprintf(d->fd, "Warning: the link repeats. Ignored."
				"\n|%s|\n", p->line);
			return (1);
		}
		ptr = ptr->next;
	}
	ftlmn_create_link(d, p, from, to);
	ftlmn_create_link(d, p, to, from);
	if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Get link: |%s|-|%s|\n", from->name, to->name);
	return (0);
}

static inline int	ftlmn_get_link(t_data *d, t_pars *p)
{
	t_room	*from;
	t_room	*to;
	char	*cp;
	ssize_t	len;

	from = d->begin;
	while ((from = from->next))
	{
		cp = p->line;
		len = ft_strlen(from->name);
		if (!ft_strncmp(from->name, cp, len))
		{
			cp += len;
			if (*cp++ == '-')
			{
				to = d->begin->next;
				while (to && ft_strcmp(to->name, cp))
					to = to->next;
				if (to && ft_strcmp(to->name, from->name))
					return (ftlmn_check_links(d, p, from, to));
			}
		}
	}
	return (-1);
}

int					ftlmn_links(t_data *d, t_pars *p)
{
	int		ret;

	if (ftlmn_get_link(d, p) < 0)
		ftlmn_error(d, p, 6);
	p->line = NULL;
	while ((ret = get_next_line(0, &p->line)) > 0 && *p->line)
	{
		if (*p->line == '#' && *(p->line + 1) != '#')
			ftlmn_get_comment(d, p);
		else if (*p->line == '#' && *(p->line + 1) == '#')
		{
			if (!ft_strcmp(p->line, "##start") || !ft_strcmp(p->line, "##end"))
				return (-1);
			ftlmn_get_command(d, p);
		}
		else
		{
			if (ftlmn_get_link(d, p) < 0)
				return (1);
		}
		p->line = NULL;
	}
	if (ret < 0)
		ftlmn_error(d, p, 0);
	return (0);
}
