/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:03:47 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/24 20:51:14 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	char	*str;
	int		i;

	str = (char *)s;
	chr = (char)c;
	i = 0;
	if (chr == '\0')
		return (&str[ft_strlen(s)]);
	while (str[i])
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		len1;
	int		len2;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!arr)
		return (0);
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

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)malloc((sizeof(char) * len) + 1);
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
