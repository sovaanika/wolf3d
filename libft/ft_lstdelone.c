/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:34:20 by bbear             #+#    #+#             */
/*   Updated: 2018/12/09 18:55:50 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	void	*content;
	size_t	content_size;

	if (alst && *alst && del)
	{
		content = (*alst)->content;
		content_size = (*alst)->content_size;
		del(content, content_size);
		free(*alst);
		*alst = NULL;
	}
}
