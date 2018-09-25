/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 20:44:30 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/23 20:44:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_bits(void *a, size_t size)
{
	size_t	i;
	char	tmp;
	char	*bits;

	if (!a)
		return ;
	i = 0;
	bits = (char*)a;
	while (i < size - i)
	{
		tmp = bits[i];
		bits[i] = bits[size - 1 - i];
		bits[size - 1 - i] = tmp;
		i++;
	}
}
