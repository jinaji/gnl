/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:08:43 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/24 20:11:31 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*delete_static(char *left)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = get_index(left);
	len = ft_strlen(left) - i;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	j = 0;
	while (left[i])
		new[j++] = left[i++];
	new[j] = '\0';
	free (left);
	left = NULL;
	return (new);
}

char	*get_return(char *left)
{
	int		idx;
	char	*tmp;

	idx = get_index(left);
	tmp = ft_strndup(left, idx);
	left = delete_static(left);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*buff;
	int			read_size;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	read_size = 1;
	while (read_size && (get_index(left[fd]) == -1))
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buff);
			return (0);
		}
		if (read_size == 0)
		{
			free (buff);
			tmp = ft_strndup(left[fd], ft_strlen(left[fd]));
			left[fd] = NULL;
			return (tmp);
		}
		buff[read_size] = '\0';
		left[fd] = ft_strjoin(left[fd], buff);
		if (get_index(left[fd]) != -1)
			return (get_return(left[fd]));
	}
	if (get_index(left[fd]) != -1)
		return (get_return(left[fd]));
	return (left[fd]);
}
