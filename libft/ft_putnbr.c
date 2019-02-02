/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 10:38:34 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/29 10:38:35 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	m;

	if (n < 0)
	{
		ft_putchar('-');
		n = n * (-1);
		ft_putnbr((unsigned int)n / 10);
		m = ((unsigned int)n % 10);
		ft_putchar(m + '0');
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar(n + '0');
	}
}
