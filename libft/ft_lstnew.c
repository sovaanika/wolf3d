/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:28:37 by bbear             #+#    #+#             */
/*   Updated: 2018/12/09 17:19:06 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;
	void	*contentc;

	head = (t_list *)malloc(sizeof(*head));
	if (head == NULL)
		return (NULL);
	contentc = (void *)malloc((content_size) * sizeof(void *));
	if (contentc == NULL)
	{
		free(head);
		return (NULL);
	}
	if (!content)
	{
		head->content = (void *)NULL;
		head->content_size = 0;
		head->next = NULL;
		return (head);
	}
	contentc = ft_memcpy(contentc, content, content_size);
	head->content = (void *)contentc;
	head->content_size = content_size;
	head->next = NULL;
	return (head);
}
