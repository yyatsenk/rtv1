/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:23:50 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/12/15 17:23:51 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			string_length(unsigned short int n)
{
	size_t				i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char					*ft_itoa_short_u(unsigned short int n)
{
	size_t				str_len;
	unsigned short int	tmp_n;
	char				*str;

	str_len = string_length(n);
	tmp_n = n;
	if (!(str = ft_strnew(str_len)))
		return (0);
	str[--str_len] = tmp_n % 10 + '0';
	while (tmp_n /= 10)
		str[--str_len] = tmp_n % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
