/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:44:02 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/25 15:44:07 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t counter;

	counter = 0;
	while (counter < len)
	{
		((unsigned char*)b)[counter] = (unsigned char)c;
		counter++;
	}
	return (b);
}
