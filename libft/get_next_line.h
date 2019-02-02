/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:03:12 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/12/05 12:03:13 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# define BUFF_SIZE 32

typedef struct			s_deskriptor
{
	char				*res;
	int					fdc;
	struct s_deskriptor	*next;
	struct s_deskriptor	*begin;
}						t_deskriptor;
int						get_next_line(const int fd, char **line);

#endif
