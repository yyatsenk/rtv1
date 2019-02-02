/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:17:34 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/11/15 16:24:38 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(const char *str, int *i, int *sign)
{
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v'
	|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		*i = *i + 1;
	}
	return (*sign);
}

int			ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	sign = checker(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[i] - '0') > 8)) && sign == -1)
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
