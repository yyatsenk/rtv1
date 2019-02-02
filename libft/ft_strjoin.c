/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:18:46 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/28 13:18:47 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		sum;
	int		j;
	char	*p;

	i = 0;
	j = -1;
	sum = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0')
		i++;
	sum = i - 1;
	i = -1;
	while (s2[++i] != '\0')
		sum++;
	if (!(p = (char *)malloc(sizeof(char*) * sum)))
		return (NULL);
	while (s1[++j] != '\0')
		p[j] = s1[j];
	i = -1;
	while (s2[++i] != '\0')
		p[j++] = s2[i];
	p[j] = '\0';
	return (p);
}
