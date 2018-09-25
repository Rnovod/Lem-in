/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_pars_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:42:22 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/11 17:42:23 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			ftlmnv_pars_ants(const char **file, int *index)
{
	int	i;
	int	ants;

	ants = 0;
	i = 0;
	while (file[i])
	{
		if (ft_isdigit(*file[i]))
		{
			ants = ft_atoi(file[i++]);
			break ;
		}
		else if (*file[i] != '#')
			return (0);
		++i;
	}
	if (!file[i] || !*file[i])
		return (-1);
	*index = i;
	return (ants);
}
