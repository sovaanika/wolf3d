/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:53:15 by bbear             #+#    #+#             */
/*   Updated: 2018/11/30 18:59:00 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*sur;

	sur = s1;
	while (*s1)
	{
		s1++;
	}
	while (*s2 && n)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';
	return (sur);
}
