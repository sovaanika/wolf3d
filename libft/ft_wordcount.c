/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:02:27 by wqarro-v          #+#    #+#             */
/*   Updated: 2018/12/10 18:46:24 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s, char c)
{
	size_t		size;

	size = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size++;
			while (*s != c && *s)
				s++;
		}
	}
	return (size);
}
