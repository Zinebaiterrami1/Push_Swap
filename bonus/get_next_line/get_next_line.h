/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:14:38 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/21 23:00:37 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../../push_swap.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd, int k);
char	*_fill_line_buffer(int fd, char *str);
char	*_set_line(char *line_buffer);
size_t	ft_strlen1(const char *s);
char	*ft_strdup1(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*_helper_function(char *line);
char	*ft_strjoin1(char *s1, char *s2);

#endif