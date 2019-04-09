/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:14:38 by bbear             #+#    #+#             */
/*   Updated: 2018/12/02 16:52:46 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(len + 1 * sizeof(*new));
	if (new == NULL)
		return (NULL);
	while (*s1)
	{
		new[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		new[i] = *s2++;
		i++;
	}
	new[i] = '\0';
	return (&new[0]);
}
