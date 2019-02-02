/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:31:07 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/11/05 11:31:09 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
