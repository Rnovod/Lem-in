/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:26:19 by rnovodra          #+#    #+#             */
/*   Updated: 2017/11/17 19:22:53 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dest;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char*)dst;
	while (n--)
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	return (dest);
}
