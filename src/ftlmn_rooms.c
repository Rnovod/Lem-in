/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmn_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:14:18 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/17 13:14:19 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int	ftlmn_get_coord(const char **cp)
{
	const char	*tmp = *cp + 1;
	int			coord;

	coord = ft_atoi(tmp);
	if (*tmp == '-')
		++tmp;
	while (*tmp >= '0' && *tmp <= '9')
		++tmp;
	*cp = tmp;
	return (coord);
}

static inline char	*ftlmn_get_nameroom(t_data *d, t_pars *p, const char **cp)
{
	const char	*tmp = *cp;
	char		*name;

	while (*tmp && !(*tmp > 8 && *tmp < 14) && *tmp != 32)
		++tmp;
	if (!(name = ft_strnew(tmp - *cp)))
		ftlmn_error(d, p, 0);
	ft_strncpy(name, *cp, tmp - *cp);
	*cp = tmp;
	return (name);
}

static inline int	ftlmn_get_room(t_data *d, t_pars *p)
{
	const char	*cp;
	int			ret;

	cp = (const char*)p->line;
	if ((ret = ftlmn_room_format(d, p, cp)) < 0)
		ftlmn_error(d, p, 7);
	if (ret == 0)
		return (0);
	if (!(p->ptr->next = (t_room*)ft_memalloc(sizeof(t_room))))
		ftlmn_error(d, p, 0);
	p->ptr = p->ptr->next;
	p->ptr->name = ftlmn_get_nameroom(d, p, &cp);
	p->ptr->x = ftlmn_get_coord(&cp);
	p->ptr->y = ftlmn_get_coord(&cp);
	if (d->arg_fl & LMN_INFO_TRACE)
		ft_dprintf(d->fd, "Get room: |%s|\n", p->ptr->name);
	if (p->flags)
		ftlmn_command_room(d, p, p->ptr);
	return (1);
}

int					ftlmn_rooms(t_data *d, t_pars *p)
{
	int		ret;

	p->line = NULL;
	while ((ret = get_next_line(0, &p->line)) > 0)
	{
		if (*p->line == '#' && *(p->line + 1) != '#')
			ftlmn_get_comment(d, p);
		else if (*p->line == '#' && *(p->line + 1) == '#')
			ftlmn_get_command(d, p);
		else
		{
			if (*p->line && ft_count_words(p->line, ' ') == 1 &&
				ft_strchr(p->line, '-'))
				return (0);
			else if (ftlmn_get_room(d, p) < 0)
				break ;
			if (p->output_size <= p->i)
				ftlmn_output(d, p);
			p->output[p->i++] = p->line;
		}
		p->line = NULL;
	}
	if (ret < 0)
		ftlmn_error(d, p, 0);
	return (-1);
}
