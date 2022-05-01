/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:15:09 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/01 00:05:10 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*delete_static(char	*left, int idx)
{
	int		i;
	int		len;
	char	*new;

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

	idx = 0;
	while (left[idx])
	{
		if (left[idx] == '\n')
			break ;
		idx++;
	}
	idx += 1;
	tmp = ft_strndup(left, idx);
	printf("get return\n");
	printf("before delete and free %s\n", left);
	printf("before delete and free %p\n", left);
	left = delete_static(left, idx);
	printf("after delete and free %s\n", left);
	printf("after delete and free %p\n", left);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*left[OPEN_MAX];
	char		*buff;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!(ft_newline(left[fd])))
	{
		printf("%p %p\n", left[fd], buff);
		printf("before read static %s\n", left[fd]);
		read_size = read(fd, buff, BUFFER_SIZE); // ??
		printf("after read static %s\n", left[fd]);
		if (read_size == -1 || read_size == 0)
		{
			free(buff);
			if (!read_size)
				return (left[fd]);
			return (0);
		}
		buff[BUFFER_SIZE] = '\0';
		left[fd] = ft_strjoin(left[fd], buff);
	}
	if (ft_newline(left[fd]))
		return (get_return(left[fd]));
	return (0);
}
