/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_pars_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:10:00 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/12 15:10:01 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline void	ftlmnv_create_link(t_vdata *d, t_vroom *from, t_vroom *to)
{
	t_vlink	*links;

	if (!from->links)
	{
		if (!(from->links = (t_vlink*)ft_memalloc(sizeof(t_vlink))))
			ftlmnv_error(d, 1);
		links = from->links;
	}
	else
	{
		links = from->links;
		while (links->next)
			links = links->next;
		if (!(links->next = (t_vlink*)ft_memalloc(sizeof(t_vlink))))
			ftlmnv_error(d, 1);
		links = links->next;
	}
	links->room = to;
}

static inline int	ftlmnv_get_link(t_vdata *d, t_vroom *from, t_vroom *to)
{
	t_vlink	*l;

	l = from->links;
	while (l)
	{
		if (l->room == to)
			return (1);
		l = l->next;
	}
	ftlmnv_create_link(d, from, to);
	ftlmnv_create_link(d, to, from);
	return (0);
}

static inline int	ftlmnv_check_link(t_vdata *d, const char *line)
{
	const char	*cp;
	t_vroom		*from;
	t_vroom		*to;
	ssize_t		len;

	from = d->b->next;
	while (from)
	{
		cp = line;
		len = ft_strlen(from->name);
		if (!ft_strncmp(from->name, cp, len))
		{
			cp += len;
			if (*cp++ == '-')
			{
				to = d->b->next;
				while (to && ft_strcmp(cp, to->name))
					to = to->next;
				if (to && ft_strcmp(from->name, to->name))
					return (ftlmnv_get_link(d, from, to));
			}
		}
		from = from->next;
	}
	return (-1);
}

int					ftlmnv_pars_links(t_vdata *d, const char **file, int *ind)
{
	int	i;

	i = *ind;
	while (file[i] && *file[i] != 'L')
	{
		if (*file[i] && *file[i] != '#')
		{
			if (ftlmnv_check_link(d, file[i]) < 0)
				break ;
		}
		else if (!*file[i])
			return (-1);
		++i;
	}
	*ind = i;
	return (0);
}
