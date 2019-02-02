/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 11:55:19 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/11/01 14:16:39 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)ft_memalloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	if (content)
	{
		if ((list->content = ft_memalloc(content_size)))
			ft_memcpy(list->content, content, content_size);
		else
			return (NULL);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
