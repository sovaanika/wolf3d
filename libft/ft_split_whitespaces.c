/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:32:23 by bbear             #+#    #+#             */
/*   Updated: 2018/12/10 13:17:38 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_fill_str(int len, char *str)
{
	char	*new;
	int		j;

	new = (char *)malloc(len + 1);
	j = -1;
	while (++j < len)
		new[j] = str[j];
	new[j] = '\0';
	return (new);
}

static char		**ft_alloc_memory(int word_count, char *str)
{
	char	**arr;
	int		i;
	int		len;

	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	i = -1;
	while (++i < word_count)
	{
		while (*str == '\n' || *str == '\t' || *str == ' ')
			str++;
		len = 0;
		while (str[len] != '\n' && str[len] != '\t'
				&& str[len] != ' ' && str[len])
			len++;
		if (len != 0)
			arr[i] = ft_fill_str(len, str);
		str += len;
	}
	arr[i] = 0;
	return (arr);
}

static int		ft_words_count(char *str)
{
	char	*ptr;
	int		word_count;

	ptr = str;
	word_count = 0;
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '\n' && *ptr != '\t')
		{
			word_count++;
			while (*ptr != ' ' && *ptr != '\n' && *ptr != '\t' && *ptr)
				ptr++;
		}
		if (*ptr)
			ptr++;
	}
	return (word_count);
}

char			**ft_split_whitespaces(char *str)
{
	return (ft_alloc_memory(ft_words_count(str), str));
}
