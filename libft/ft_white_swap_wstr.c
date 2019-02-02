/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_white_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:03:55 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/12/22 13:03:56 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		firstr_part(wchar_t *str, int *i)
{
	while (str[*i] == ' ' && str[*i])
		(*i)++;
}

static wchar_t	*second_part(wchar_t *str, int i, wchar_t **res, int w)
{
	int		j;

	j = i;
	if (j == 0 || !(*res = (wchar_t*)malloc(sizeof(wchar_t) * (w + 1))))
		return (str);
	*res = ft_wstrncpy(*res, &str[i], w);
	return (NULL);
}

static void		free_part(wchar_t **tmp_1, wchar_t **tmp_2, wchar_t **str)
{
	free(*tmp_1);
	free(*tmp_2);
	free(*str);
}

wchar_t			*ft_white_swap_wstr(wchar_t *str, int wstrlen)
{
	wchar_t		*white;
	wchar_t		*tmp_1;
	wchar_t		*tmp_2;
	wchar_t		*res;
	int			i;

	i = 0;
	res = NULL;
	if (str != NULL)
	{
		firstr_part(str, &i);
		if (i == 0 || !(white = (wchar_t*)malloc(sizeof(wchar_t) * (i + 1))))
			return (str);
		white = ft_wstrncpy(white, str, i);
		tmp_1 = white;
		if (second_part(str, i, &res, wstrlen))
			return (str);
		tmp_2 = res;
		res = ft_wstrjoin(res, white);
		free_part(&tmp_1, &tmp_2, &str);
	}
	return (res);
}
