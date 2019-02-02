/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:02:49 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/12/05 12:02:51 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				file_reader(int fd, char **res)
{
	char				*buffer;
	char				*temp;
	int					ret;

	if (!(buffer = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	ret = read(fd, buffer, BUFF_SIZE);
	temp = *res;
	if (ret > 0)
	{
		buffer[ret] = '\0';
		*res = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	free(buffer);
	if (ret == 0)
	{
		if (ft_strlen(*res) == 0)
			return (-2);
		(*res) = ft_strjoin((*res), "\n");
	}
	return (ret);
}

static t_deskriptor		*creat_elem(const int fd)
{
	t_deskriptor			*obj;

	if (!(obj = (t_deskriptor *)malloc(sizeof(*obj))))
		return (NULL);
	if (!(obj->res = (char *)malloc(sizeof(char*))))
	{
		free(obj);
		return (NULL);
	}
	obj->next = NULL;
	obj->fdc = fd;
	obj->begin = obj;
	return (obj);
}

static t_deskriptor		*add_back(t_deskriptor **result, t_deskriptor *to_add)
{
	t_deskriptor			*temp;
	t_deskriptor			*begin_copy;

	temp = *result;
	begin_copy = *result;
	while (temp->next)
		temp = temp->next;
	temp->next = to_add;
	to_add->next = NULL;
	to_add->begin = begin_copy;
	return (begin_copy);
}

static t_deskriptor		*fd_finder(const int fd, t_deskriptor **result)
{
	if ((*result) == NULL)
		(*result) = creat_elem(fd);
	else
	{
		(*result) = (*result)->begin;
		while ((*result)->fdc != fd && (*result)->next)
			(*result) = (*result)->next;
		if ((*result)->fdc != fd && (*result)->next == NULL)
		{
			(*result) = (*result)->begin;
			(*result) = add_back(&(*result), creat_elem(fd));
		}
		while ((*result)->fdc != fd && (*result)->next)
			(*result) = (*result)->next;
	}
	return ((*result));
}

int						get_next_line(const int fd, char **line)
{
	static t_deskriptor	*result;
	char				*tmp;
	char				*tmp_2;
	int					ret;

	result = fd_finder(fd, &result);
	if ((!result->res) || fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	tmp = ft_strchr(result->res, '\n');
	while (!tmp)
	{
		ret = file_reader(fd, &result->res);
		if (ret == -2)
			return (0);
		if (ret < 0)
			return (-1);
		else
			tmp = ft_strchr(result->res, '\n');
	}
	tmp_2 = result->res;
	*line = ft_strsub(result->res, 0, ft_strlen(result->res) - ft_strlen(tmp));
	result->res = ft_strdup(tmp + 1);
	free(tmp_2);
	return (1);
}
