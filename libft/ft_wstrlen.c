/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 10:04:57 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/27 10:13:09 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstrlen(wchar_t *wstr)
{
	int	size;
	int	res;
	int	i;

	i = -1;
	size = 0;
	res = 0;
	while (wstr && wstr[++i] != 0)
	{
		size = ft_size_bin(wstr[i]);
		if (size <= 7)
			res += 1;
		else if (size <= 11)
			res += 2;
		else if (size <= 16)
			res += 3;
		else
			res += 4;
	}
	return (res);
}
