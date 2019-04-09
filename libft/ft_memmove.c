/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:20:35 by bbear             #+#    #+#             */
/*   Updated: 2018/12/02 19:29:24 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*surc;

	dest = (unsigned char *)dst;
	surc = (unsigned char *)src;
	if (dest < surc)
		while (len--)
			*dest++ = *surc++;
	else
		while (len--)
			*(dest + len) = *(surc + len);
	return (dst);
}
