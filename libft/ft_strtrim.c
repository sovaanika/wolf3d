/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:57:52 by bbear             #+#    #+#             */
/*   Updated: 2018/12/07 15:39:13 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countlen(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len == 0)
		return (0);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	s = &s[0];
	while ((*s == ' ' || *s == '\n' || *s == '\t') && len)
	{
		len--;
		s++;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	char	*new;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_countlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	while (j < len && len)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (&new[0]);
}
