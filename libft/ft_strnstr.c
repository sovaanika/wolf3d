/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:48:47 by bbear             #+#    #+#             */
/*   Updated: 2018/12/02 14:23:05 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*loc;
	const char	*needlecopy;
	int			i;
	int			j;

	i = -1;
	j = i;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && (i < ((int)len - 1)))
	{
		j = i;
		loc = haystack;
		needlecopy = needle;
		while (*needlecopy == *haystack && i++ < (int)len - 1 && *haystack)
		{
			++haystack;
			++needlecopy;
		}
		if (*needlecopy == '\0')
			return ((char *)loc);
		haystack = loc + 1;
		i = j + 1;
	}
	return ((char*)0);
}
