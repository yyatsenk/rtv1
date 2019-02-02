/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:05:21 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/28 13:05:22 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*string;

	if (!s || !(string = ft_strnew(len)))
		return (0);
	ft_strncpy(string, &s[start], len);
	return (string);
}
