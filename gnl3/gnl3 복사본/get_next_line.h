/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:15:07 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/01 19:24:46 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

size_t	ft_strlen(char	*str);
int		is_newline(char *str);
char	*ft_strjoin(char *left, char *buff);
char	*ft_strndup(char *left, int idx);

int		get_index(char *left);
char	*delete_static(char *left);
char	*get_return(char *left);
char	*get_next_line(int fd);

#endif