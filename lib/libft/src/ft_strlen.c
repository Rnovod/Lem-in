/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:37:57 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/05 14:57:43 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	inline	size_t	ft_calc_len(char *cp, const char *str)
{
	if (cp[0] == 0)
		return (cp - str);
	if (cp[1] == 0)
		return (cp - str + 1);
	if (cp[2] == 0)
		return (cp - str + 2);
	if (cp[3] == 0)
		return (cp - str + 3);
	if (cp[4] == 0)
		return (cp - str + 4);
	if (cp[5] == 0)
		return (cp - str + 5);
	if (cp[6] == 0)
		return (cp - str + 6);
	else
		return (cp - str + 7);
}

size_t					ft_strlen(const char *str)
{
	char		*cp;
	uintmax_t	*longword_ptr;
	uintmax_t	longword;

	longword_ptr = (uintmax_t *)str;
	if (!str)
		return (0);
	while (42)
	{
		longword = *longword_ptr++;
		if (((longword - 0x101010101010101L)
			& ~longword & 0x8080808080808080L) != 0)
		{
			cp = (char *)(longword_ptr - 1);
			return (ft_calc_len(cp, str));
		}
	}
}
