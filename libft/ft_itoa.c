/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:58:39 by bbear             #+#    #+#             */
/*   Updated: 2018/12/05 15:22:14 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	retlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0 || n == -0)
		len = 1;
	else
	{
		if (n < 0)
			len++;
		while (n)
		{
			len++;
			n = n / 10;
		}
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*arr;

	len = retlen(n);
	arr = (char *)ft_strnew(len);
	if (arr)
	{
		arr[len--] = '\0';
		if (n == 0 || n == -0)
			arr[len--] = '0';
		while (n)
		{
			if (n < 0)
				arr[len] = (n % 10) * (-1) + '0';
			else
				arr[len] = n % 10 + '0';
			n = n / 10;
			len--;
		}
		if (len == 0)
			arr[len] = '-';
		return (arr);
	}
	return (NULL);
}
