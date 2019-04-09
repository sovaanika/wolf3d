/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:56:05 by bbear             #+#    #+#             */
/*   Updated: 2018/12/05 14:56:52 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	while (size && i < size - 1 && *src)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	if (size < dlen)
		return (slen + size);
	return (slen + dlen);
}
