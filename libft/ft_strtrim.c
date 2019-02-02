/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:16:19 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/28 14:16:20 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*res;
	char	*reslike;
	size_t	beg;
	size_t	end;

	if (!s)
		return (NULL);
	beg = 0;
	end = 0;
	end = ft_strlen(s);
	while ((s[beg] == ' ' || s[beg] == '\n'
	|| s[beg] == '\t') && s[beg] != '\0')
		beg++;
	while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
		end--;
	if (end < beg)
	{
		beg = 0;
		end = 0;
	}
	if (!(reslike = ft_strnew(end - beg)))
		return (NULL);
	if ((res = ft_strncpy(reslike, &s[beg], end - beg)))
		return (res);
	return (NULL);
}
