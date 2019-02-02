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

wchar_t		*ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
	int		i;
	int		sum;
	int		j;
	wchar_t	*p;

	i = 0;
	j = -1;
	sum = 0;
	if (!s1 || !s2)
		return (0);
	if (!*s1)
		return (s2);
	if (!*s2)
		return (s1);
	sum = ft_wstrlen(s1);
	sum += ft_wstrlen(s2);
	if (!(p = (wchar_t *)malloc(sizeof(wchar_t) * (sum + 1))))
		return (NULL);
	while (s1[++j] != '\0')
		p[j] = s1[j];
	i = -1;
	while (s2[++i] != '\0')
		p[j++] = s2[i];
	p[j] = '\0';
	return (p);
}
