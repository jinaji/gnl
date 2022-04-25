/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:03:47 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/25 19:39:26 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (0);
}

int	get_index(char *left)
{
	int	i;

	i = 0;
	while (left[i])
	{
		if (left[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		len;
	int		i;
	int		j;

	if (!s1)
		return (s2);
	if (!s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	return (arr);
}

char	*ft_strndup(char *s1, int len)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
