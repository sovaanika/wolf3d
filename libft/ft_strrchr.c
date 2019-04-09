/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:57:22 by bbear             #+#    #+#             */
/*   Updated: 2018/11/26 18:07:56 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*res;

	len = (int)ft_strlen(s);
	while (len > -1)
	{
		if ((char)c == s[len])
		{
			res = (char *)&s[len];
			return ((char *)res);
		}
		len--;
	}
	return ((char *)0);
}
