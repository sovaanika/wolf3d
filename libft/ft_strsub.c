/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:32:51 by bbear             #+#    #+#             */
/*   Updated: 2019/02/14 17:14:49 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	sub = (char *)malloc((len + 1) * sizeof(*sub));
	if (sub == NULL)
		return (NULL);
	s = &s[start];
	while (i < len)
	{
		sub[i] = *s++;
		i++;
	}
	sub[i] = '\0';
	sub = &sub[0];
	return (sub);
}
