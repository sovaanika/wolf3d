/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:55:38 by bbear             #+#    #+#             */
/*   Updated: 2018/11/30 16:59:01 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss2 = (const unsigned char *)s2;
	ss1 = (const unsigned char *)s1;
	while (n--)
	{
		if (*ss1 != *ss2)
		{
			return (*ss1 - *ss2);
		}
		++ss1;
		++ss2;
	}
	return (0);
}
