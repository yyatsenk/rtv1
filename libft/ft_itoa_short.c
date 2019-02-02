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

static size_t		string_length(short int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa_short(short int n)
{
	size_t			str_len;
	short int		tmp_n;
	char			*str;

	str_len = string_length(n);
	tmp_n = n;
	if (n < 0)
	{
		tmp_n = -n;
		str_len++;
	}
	if (!(str = ft_strnew(str_len)))
		return (0);
	str[--str_len] = tmp_n % 10 + '0';
	while (tmp_n /= 10)
		str[--str_len] = tmp_n % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
