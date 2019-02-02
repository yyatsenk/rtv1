/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:52:22 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/28 12:52:23 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	length;
	char			*string;
	char			*tmp;
	int				index;

	index = 0;
	if (!s || !(*f))
		return (0);
	length = ft_strlen(s);
	tmp = NULL;
	if ((string = (char *)malloc(length + 1)))
	{
		tmp = string;
		while (*s)
		{
			*tmp = (*f)(index, *s);
			s++;
			tmp++;
			index++;
		}
	}
	else
		return (0);
	*tmp = '\0';
	return (string);
}
