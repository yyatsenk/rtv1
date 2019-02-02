/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:01:23 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/28 12:01:25 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t	*p;
	size_t	i;

	i = 0;
	p = (wchar_t*)malloc(size + 1);
	if (p != NULL)
		while (i != size + 1)
		{
			p[i] = '\0';
			i++;
		}
	if (p == NULL)
		return (NULL);
	return (p);
}
