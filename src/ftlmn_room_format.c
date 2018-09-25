/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_room_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:16:26 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/16 14:16:27 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int	ftlmnv_isname_repeat(t_data *d, t_pars *p, const char *line)
{
	const t_room	*tmp = d->begin->next;
	char			*name;
	size_t			len;

	len = ft_strclen(line, ' ');
	if (!(name = ft_strsub(line, 0, len)))
		ftlmn_error(d, p, 0);
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
		{
			if (d->arg_fl & LMN_INFO_TRACE)
				ft_dprintf(d->fd, "Warning: the room name repeats. "
				"Ignored.\n|%s|\n", tmp->name);
			free(name);
			return (0);
		}
		tmp = tmp->next;
	}
	free(name);
	return (1);
}

static inline int	ftlmn_check_name(t_data *d, const char **pos)
{
	const char	*cp = *pos;

	if (!*cp || (*cp > 8 && *cp < 14) || *cp == 32 ||
		*cp == 'L')
	{
		if (d->arg_fl & LMN_INFO_TRACE && *cp)
			ft_dprintf(d->fd, "Incorrect room name.\n");
		else if (d->arg_fl & LMN_INFO_TRACE)
			ft_dprintf(d->fd, "No room name.\n");
		return (-1);
	}
	while (*cp && !(*cp > 8 && *cp < 14) && *cp != 32)
	{
		if (!(d->arg_fl & LMN_NAME) && *cp == '-')
		{
			if (d->arg_fl & LMN_INFO_TRACE)
				ft_dprintf(d->fd, "Incorrect room name.\n");
			return (-1);
		}
		++cp;
	}
	*pos = cp;
	return (1);
}

static inline int	ftlmn_check_coord(const char **pos)
{
	const char	*cp = *pos;
	int			nbr;

	if (*cp++ != ' ')
		return (-1);
	if (*cp == '-')
		++cp;
	if (!ft_isdigit(*cp))
		return (-1);
	nbr = 0;
	while (*cp >= '0' && *cp <= '9')
		nbr = nbr * 10 + (*cp++ - '0');
	*pos = cp;
	return (0);
}

int					ftlmn_room_format(t_data *d, t_pars *p, const char *line)
{
	const char	*cp = line;

	if (ftlmn_check_name(d, &cp) < 0)
		return (-1);
	if (ftlmn_check_coord(&cp) < 0 || *cp != ' ')
	{
		if (d->arg_fl & LMN_INFO_TRACE)
			ft_dprintf(d->fd, "incorrect x coordinate.\n");
		return (-1);
	}
	if (ftlmn_check_coord(&cp) < 0 || *cp)
	{
		if (d->arg_fl & LMN_INFO_TRACE)
			ft_dprintf(d->fd, "incorrect y coordinate.\n");
		return (-1);
	}
	return (ftlmnv_isname_repeat(d, p, line));
}
