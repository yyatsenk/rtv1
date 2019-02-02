/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:00:50 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/27 13:00:51 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!*little && !*big)
	{
		return ((char *)big);
	}
	while (big[a] && (a < len))
	{
		b = 0;
		while (little[b] == big[a + b] && little[b] &&
				big[a + b] && ((a + b) < len))
			b++;
		if (!little[b])
			return ((char *)&big[a]);
		a++;
	}
	return (0);
}
