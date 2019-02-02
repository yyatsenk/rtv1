/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:04:02 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/29 09:40:07 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = dst;
	i = 0;
	if (src <= dst)
		while (len--)
			temp[len] = ((unsigned char *)src)[len];
	else
		while (i < len)
		{
			temp[i] = ((unsigned char *)src)[i];
			i++;
		}
	return ((void *)dst);
}
