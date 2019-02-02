/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:51:17 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/25 16:51:19 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (n != 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dst + 1);
		return (ft_memccpy(dst + 1, src + 1, c, --n));
	}
	return (NULL);
}
