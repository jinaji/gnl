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
	len = ft_strlen(left) - i - 1;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	i += 1;
	j = 0;
	while (left[i])
		new[j++] = left[i++];
	new[j] = '\0';
	free (left);
	return (new);
}

char	*get_return(char *left)
{
	int		i;
	int		idx;
	char	*tmp;

	i = 0;
	idx = get_index(left);
	while (left[i])
	{
		if (idx)
		{
			tmp = ft_strndup(left, idx);
			left = delete_static(left);
			return (tmp);
		}
		i++;
	}
	return (left);
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
	read_size = read(fd, buff, BUFFER_SIZE);
	if (read_size == -1 || read_size == 0)
	{
		free(buff);
		return (0);
	}
	left[fd] = ft_strjoin(left[fd], buff);
	if (get_index(left[fd]))
		return (get_return(left[fd]));
	else
		return (buff);
}
