/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:44:33 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/11/05 11:44:34 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen_until_char(const char *str, char c)
{
	const char	*s;

	s = str;
	while (*s != c && *s)
		++s;
	return (s - str);
}
