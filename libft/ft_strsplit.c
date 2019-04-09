/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:58:06 by wqarro-v          #+#    #+#             */
/*   Updated: 2018/12/12 19:53:56 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		words;
	int		len;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	if (!(split = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*s)
		if (*s == c)
			s++;
		else
		{
			len = ft_wordsize(s, c);
			if (!(*split = ft_strnew(len)))
				return (NULL);
			while (*s != c && *s)
				*(*split)++ = *s++;
			*split = *split - len;
			split++;
		}
	*split = NULL;
	return (split - words);
}
