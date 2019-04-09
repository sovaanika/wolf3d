/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:48:17 by bbear             #+#    #+#             */
/*   Updated: 2018/12/09 22:29:21 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int					count;
	const unsigned char	*sour;
	unsigned char		*dest;

	if (n != 0)
	{
		count = 0;
		sour = (const unsigned char *)src;
		dest = (unsigned char *)dst;
		while (*sour != (unsigned char)c && n)
		{
			*dest++ = *sour++;
			n--;
			count++;
		}
		if (*sour == (unsigned char)c && n)
		{
			*dest++ = (unsigned char)c;
			return (dest);
		}
	}
	return (NULL);
}
