/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:15:11 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/30 17:09:55 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_newline(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left, char *buff)
{
	char		*str;
	size_t		len;
	size_t		i;
	size_t		j;

	if (!left)
		left = ft_strndup("", 1);
	if (!buff)
		return (ft_strndup(buff, ft_strlen(buff)));
	len = ft_strlen(left) + ft_strlen(buff);
	printf("join len = %zu\nbefore join left : %s\n before join buff %s\n", len, left, buff);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	i = 0;
	while (left[i])
	{
		str[i] = left[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		str[i] = buff[j];
		i++;
		j++;
	}
	printf("after join : %s\n", str);
	str[i] = '\0';
	return (str);
}

char	*ft_strndup(char *left, int idx)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * idx + 1);
	if (!str)
		return (0);
	while (left[i] && idx > i)
	{
		str[i] = left[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
