/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:21:52 by bbear             #+#    #+#             */
/*   Updated: 2018/12/10 14:00:35 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*begin;
	t_list	*tmp;

	if (lst && f)
	{
		tmp = f(lst);
		res = ft_lstnew(tmp->content, tmp->content_size);
		if (res == NULL)
			return (NULL);
		begin = res;
		while ((lst = lst->next))
		{
			tmp = f(lst);
			res->next = ft_lstnew(tmp->content, tmp->content_size);
			if (res == NULL)
			{
				free(res);
			}
			res = res->next;
		}
		return (begin);
	}
	return (NULL);
}
