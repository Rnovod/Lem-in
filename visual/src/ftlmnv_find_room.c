/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_find_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:47:29 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/23 11:47:30 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

const t_vroom		*ftlmnv_find_room(t_vdata *d, const char *line, int *len)
{
	const t_vroom	*tmp = d->b->next;
	char			*name;
	ssize_t			len_space;

	if ((len_space = ft_strclen(line, ' ')) < 0)
		len_space = ft_strlen(line);
	if (len)
		*len = len_space;
	if (!(name = ft_strsub(line, 0, len_space)))
		ftlmnv_error(d, 1);
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
		{
			free(name);
			return (tmp);
		}
		tmp = tmp->next;
	}
	free(name);
	return (NULL);
}
