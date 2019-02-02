/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:07:02 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/27 13:07:03 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' && s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
