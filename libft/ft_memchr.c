/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:01:06 by bbear             #+#    #+#             */
/*   Updated: 2018/11/29 20:54:35 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*new;

	new = (const unsigned char *)s;
	while (n)
	{
		if (*new == (unsigned char)c)
		{
			return ((void *)new);
		}
		new++;
		n--;
	}
	return (NULL);
}
