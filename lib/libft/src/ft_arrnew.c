/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:56:00 by rnovodra          #+#    #+#             */
/*   Updated: 2017/12/29 16:56:01 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(size_t size)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i <= size)
		arr[i++] = NULL;
	return (arr);
}
