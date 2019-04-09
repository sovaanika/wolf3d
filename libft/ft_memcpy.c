/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:23:28 by bbear             #+#    #+#             */
/*   Updated: 2018/11/29 16:46:48 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new;
	unsigned char	*dest;

	new = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (n)
	{
		*dest++ = *new++;
		n--;
	}
	return (dst);
}
