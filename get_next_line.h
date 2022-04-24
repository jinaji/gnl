/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:05:04 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/24 19:53:27 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

char	*save_static(char *left, char *buff);
char	*delete_static(char *left);
char	*get_return(char *left);
char	*get_next_line(int fd);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10496
# endif

#endif