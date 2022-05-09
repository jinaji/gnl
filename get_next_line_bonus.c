/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:06:06 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/07 19:06:19 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*delete_static(char	*left)
{
	int		i;
	int		idx;
	int		len;
	char	*new;

	if (!left)
		return (0);
	idx = get_index(left);
	len = ft_strlen(left) - idx;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (0);
	i = 0;
	while (left[idx])
		new[i++] = left[idx++];
	new[i] = '\0';
	free (left);
	left = 0;
	return (new);
}

char	*get_return(char *left)
{
	size_t		idx;
	char		*tmp;

	if (!left)
		return (0);
	idx = get_index(left);
	tmp = ft_strndup(left, idx);
	if (*tmp == 0)
	{
		free (tmp);
		return (0);
	}
	return (tmp);
}

int	make_line(char **left, int fd, char *buff, char **tmp)
{
	int	read_size;

	while (!is_newline(left[fd]))
	{	
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1 || read_size == 0)
		{
			free (buff);
			if (read_size == 0)
			{
				*tmp = get_return(left[fd]);
				free (left[fd]);
				left[fd] = 0;
				return (1);
			}
			return (0);
		}
		buff[read_size] = '\0';
		left[fd] = ft_strjoin(left[fd], buff);
	}
	return (2);
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*buff;
	char		*tmp;
	int			flag;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	flag = make_line(left, fd, buff, &tmp);
	if (flag == 1)
		return (tmp);
	else if (flag == 0)
		return (0);
	if (is_newline(left[fd]))
	{
		tmp = (get_return(left[fd]));
		left[fd] = delete_static(left[fd]);
		free (buff);
		return (tmp);
	}
	return (0);
}
