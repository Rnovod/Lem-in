/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlmnv_room_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:16:26 by rnovodra          #+#    #+#             */
/*   Updated: 2018/09/16 14:16:27 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int					ftlmnv_room_format(t_vdata *d, const char *line)
{
	int			nbr;
	const char	*cp = line;

	if (!*cp || (*cp > 8 && *cp < 14) || *cp == 32 ||
		*cp == 'L')
		ftlmnv_error(d, 9);
	while (*cp && !(*cp > 8 && *cp < 14) && *cp != 32)
		++cp;
	if (cp - line > 15)
		ftlmnv_error(d, 10);
	if (!ft_isdigit(*++cp))
		ftlmnv_error(d, 9);
	nbr = 0;
	while (*cp >= '0' && *cp <= '9' && nbr < WIDTH)
		nbr = nbr * 10 + (*cp++ - '0');
	if (*cp++ != ' ' || nbr > WIDTH)
		ftlmnv_error(d, 9);
	nbr = 0;
	if (!ft_isdigit(*cp))
		ftlmnv_error(d, 9);
	while (*cp >= '0' && *cp <= '9' && nbr < HEIGHT)
		nbr = nbr * 10 + (*cp++ - '0');
	if (*cp != '\0' || nbr > HEIGHT)
		ftlmnv_error(d, 9);
	return ((ftlmnv_find_room(d, line, NULL)) ? 0 : 1);
}
