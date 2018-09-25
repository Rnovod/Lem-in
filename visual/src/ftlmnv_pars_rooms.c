/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_pars_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:43:27 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/11 17:43:28 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static inline char	*ftlmnv_get_name(t_vdata *d, const char **line)
{
	char		*name;
	const char	*cp = *line;

	while (*cp && !(*cp > 8 && *cp < 14) && *cp != 32)
		++cp;
	if (!(name = ft_strnew(cp - *line)))
		ftlmnv_error(d, 1);
	ft_strncpy(name, *line, cp - *line);
	*line = cp;
	return (name);
}

static inline int	ftlmnv_get_coord(const char **line)
{
	const char	*cp = *line + 1;
	int			coord;

	coord = ft_atoi(cp);
	while (*cp >= '0' && *cp <= '9')
		++cp;
	*line = cp;
	return (coord);
}

static inline int	ftlmnv_room(t_vdata *d, const char *line, t_vroom *r)
{
	int	ret;

	if ((ret = ftlmnv_room_format(d, line)) < 0)
		ftlmnv_error(d, 8);
	if (ret == 0)
		return (0);
	if (!(r->next = (t_vroom*)ft_memalloc(sizeof(t_vroom))))
		ftlmnv_error(d, 1);
	r = r->next;
	r->name = ftlmnv_get_name(d, &line);
	r->x = ftlmnv_get_coord(&line);
	r->y = ftlmnv_get_coord(&line);
	if (d->fl & START)
		d->st = r;
	else if (d->fl & END)
		d->e = r;
	else if (d->fl & ANTEATER)
		r->anteater = 1;
	d->fl = 0;
	++d->num_rooms;
	return (1);
}

static inline void	ftlmnv_command(t_vdata *d, const char *line)
{
	if (!ft_strcmp(line, "##end"))
		d->fl = END;
	else if (!ft_strcmp(line, "##start"))
		d->fl = START;
	else if (!ft_strcmp(line, "##anteater"))
		d->fl = ANTEATER;
}

int					ftlmnv_pars_rooms(t_vdata *d, const char **file,
					int *index)
{
	int		i;
	t_vroom	*r;

	i = *index;
	r = d->b;
	while (file[i] && *file[i] && d->num_rooms <= 30)
	{
		if (*file[i] == '#' && *(file[i] + 1) == '#')
			ftlmnv_command(d, file[i]);
		else if (*file[i] != '#' && *file[i])
		{
			if (ft_count_words(file[i], ' ') == 1 && ft_strchr(file[i], '-'))
				break ;
			else if (ftlmnv_room(d, file[i], r) > 0)
				r = r->next;
		}
		++i;
	}
	if (!file[i] || !*file[i])
		return (-1);
	*index = i;
	return (0);
}
