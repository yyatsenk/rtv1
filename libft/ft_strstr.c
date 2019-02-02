/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:15:33 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/31 16:07:06 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int icopy;

	i = -1;
	j = 0;
	icopy = -1;
	while (big[++i] != '\0' && little[j] != '\0')
	{
		if (big[i] == little[j] && icopy == -1)
			icopy = i;
		if (i != 0 && j != 0 &&
			big[i - 1] == little[j - 1] && big[i] != little[j])
		{
			i = icopy;
			icopy = -1;
			j = 0;
			continue;
		}
		if (big[i] == little[j])
			j++;
	}
	if (little[j] == '\0')
		return (((char *)big + (icopy == -1 ? 0 : icopy)));
	return (NULL);
}
