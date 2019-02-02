/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 10:29:31 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/27 10:29:32 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrncpy(wchar_t *dst, wchar_t *src, size_t len)
{
	size_t i;
	size_t counter;
	size_t res;

	counter = 0;
	res = 0;
	i = -1;
	while (counter < len && src[++i])
	{
		counter += ft_wcharlen(src[i]);
		if (counter <= len)
			res++;
	}
	i = -1;
	while (src[++i] != '\0' && i < res)
		dst[i] = src[i];
	dst[i] = L'\0';
	return (dst);
}
