/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_pars_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:16:55 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/20 17:16:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

inline static int		ftlmnv_check_line_moves(t_vdata *d, const char *line)
{
	int				len;
	const t_vroom	*r;

	while (*line)
	{
		if (*line++ != 'L')
			return (-1);
		while (*line != '-')
			if (!ft_isdigit(*line++))
				return (-1);
		++line;
		r = ftlmnv_find_room(d, line, &len);
		line += len;
		if (!r || (*line != ' ' && *line))
			return (-1);
		if (*line)
			++line;
	}
	return (0);
}

inline static int		ftlmnv_init_ant(t_vdata *d, t_ant *ant,
						const t_moves *prev, const t_vroom *r)
{
	t_ant	*find;

	ant->to_x = r->x;
	ant->to_y = r->y;
	if (prev)
	{
		find = prev->ants;
		while (find && find->id != ant->id)
			find = find->next;
	}
	if (!prev || !find)
	{
		ant->from_x = d->st->x;
		ant->from_y = d->st->y;
	}
	else
	{
		ant->from_x = find->to_x;
		ant->from_y = find->to_y;
	}
	ant->now_x = ant->from_x;
	ant->now_y = ant->from_y;
	return (0);
}

inline static t_ant		*ftlmnv_create_ant(t_vdata *d, t_moves *m,
						const char **line)
{
	const char		*cp = *line;
	const t_vroom	*r;
	t_ant			*ant;
	int				len;

	if (!(ant = (t_ant*)ft_memalloc(sizeof(t_ant))))
		ftlmnv_error(d, 1);
	ft_getnbr(&cp, &ant->id);
	++cp;
	r = ftlmnv_find_room(d, cp, &len);
	ftlmnv_init_ant(d, ant, m, r);
	*line = cp + len;
	return (ant);
}

inline static t_moves	*ftlmnv_create_moves(t_vdata *d, const char *line,
						t_moves *prev)
{
	t_ant		*ant;
	t_moves		*moves;

	if (!(moves = (t_moves*)ft_memalloc(sizeof(t_moves))))
		ftlmnv_error(d, 1);
	if (ftlmnv_check_line_moves(d, line) < 0 ||
		!(ant = ftlmnv_create_ant(d, prev, &line)))
	{
		free(moves);
		return (NULL);
	}
	moves->ants = ant;
	while (*++line)
	{
		ant->next = ftlmnv_create_ant(d, prev, &line);
		ant = ant->next;
		if (!*line)
			break ;
	}
	moves->prev = prev;
	return (moves);
}

int						ftlmnv_pars_moves(t_vdata *d, int i)
{
	const char	**file = d->file;
	t_moves		*moves;

	while (file[i] && file[i][0] != 'L')
		++i;
	if (!(moves = (t_moves*)ft_memalloc(sizeof(t_moves))))
		ftlmnv_error(d, 1);
	d->begin_moves = moves;
	while (file[i])
	{
		if (!(moves->next = ftlmnv_create_moves(d, file[i++], moves)))
			break ;
		moves = moves->next;
	}
	if (!moves->ants)
		return (-1);
	return (0);
}
