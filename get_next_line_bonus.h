/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:04:51 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/07 19:16:14 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

size_t	ft_strlen(char	*str);
size_t	get_index(char *left);
int		is_newline(char *str);
char	*ft_strjoin(char *left, char *buff);
char	*ft_strndup(char *left, int idx);

char	*delete_static(char *left);
char	*get_return(char *left);
int		make_line(char **left, int fd, char *buff, char **tmp);
char	*get_next_line(int fd);

#endif