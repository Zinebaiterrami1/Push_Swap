/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:07:25 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/14 18:31:16 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*lines;
	static char	*stash;

	lines = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = _fill_line_buffer(fd, stash);
	if (!stash)
		return (NULL);
	lines = _set_line(stash);
	stash = _helper_function(stash);
	if (!stash)
	{
		free(stash);
		stash = NULL;
	}
	return (lines);
}

char	*_fill_line_buffer(int fd, char *str)
{
	ssize_t	r;
	char	*buffer;

	r = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	if (fd == -1)
		return (NULL);
	while (!ft_strchr(str, '\n') && r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		str = ft_strjoin1(str, buffer);
		if (!str)
			return (NULL);
	}
	free(buffer);
	return (str);
}

char	*_helper_function(char *line)
{
	ssize_t	i;
	char	*left_c;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	if (line[i] == '\n')
		i++;
	left_c = ft_substr(line, i, ft_strlen1(line) - i);
	if (!left_c)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (left_c);
}

char	*_set_line(char *line_buffer)
{
	ssize_t	i;
	char	*line;
	ssize_t	j;

	j = 0;
	i = 0;
	if (!ft_strlen1(line_buffer))
		return (NULL);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j <= i && line_buffer[j])
	{
		line[j] = line_buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
