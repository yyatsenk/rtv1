/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:08:28 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/12/19 18:08:30 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned long nb, int base)
{
	int		size;

	size = 1;
	while (nb >= (unsigned long)base)
	{
		nb /= base;
		++size;
	}
	return (size);
}

char		*ft_itoa_base_l_u(unsigned long value, int base, int whatcase)
{
	int		i;
	char	*res;
	char	*hex;

	hex = "0123456789ABCDEF";
	if (whatcase == 0)
		hex = "0123456789abcdef";
	i = ft_size(value, base);
	res = (char*)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	while (i)
	{
		res[i - 1] = hex[value % base];
		value /= base;
		--i;
	}
	return (res);
}
