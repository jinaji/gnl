/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:15:09 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/01 21:32:44 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*delete_static(char	*left)
{
	int		i;
	int		idx;
	int		len;
	char	*new;

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
	int		idx;
	char	*tmp;

	if (!left)
		return (0);
	idx = get_index(left);
	tmp = ft_strndup(left, idx);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*buff;
	char		*tmp;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!(is_newline(left[fd])))
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1 || read_size == 0)
		{
			free (buff);
			if (read_size == 0)
				return (get_return(left[fd]));
			return (0);
		}
		buff[read_size] = '\0';
		left[fd] = ft_strjoin(left[fd], buff);
	}
	if (is_newline(left[fd]))
	{
		tmp = (get_return(left[fd]));
		left[fd] = delete_static(left[fd]);
		free (buff);
		return (tmp);
	}
	return (0);
}
