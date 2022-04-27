/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:05:04 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/26 00:52:32 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

size_t	ft_strlen(char *s);
int		get_index(char *left);
char	*ft_strndup(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

char	*delete_static(char *left);
char	*get_return(char *left);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10496
# endif

#endif