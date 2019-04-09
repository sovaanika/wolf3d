/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:14:22 by bbear             #+#    #+#             */
/*   Updated: 2018/12/01 11:43:20 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*loc;
	const char	*needlecopy;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		loc = haystack;
		needlecopy = needle;
		while (*needlecopy == *haystack && *haystack)
		{
			++haystack;
			++needlecopy;
		}
		if (*needlecopy == '\0')
			return ((char *)loc);
		haystack = loc + 1;
	}
	return ((char*)0);
}
