/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:21:06 by bbear             #+#    #+#             */
/*   Updated: 2018/12/02 13:08:20 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*loc;

	while (*s != '\0')
	{
		loc = s;
		if (*loc == (char)c)
			return ((char *)loc);
		s = loc + 1;
	}
	if ((char)c == '\0' && *s == (char)c)
		return ((char *)s);
	return ((char *)0);
}
