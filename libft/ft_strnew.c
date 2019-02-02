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

char		*ft_strnew(size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char*)malloc(size + 1);
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
