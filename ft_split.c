/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:23:24 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/21 19:15:46 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lenword(const char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] && s[i] == c)
	{
		i++;
	}
	while (s[i] && s[i] != c)
	{
		j++;
		i++;
	}
	return (j);
}

int	count_word(const char *s, char c)
{
	int	i;
	int	check;
	int	wc;

	wc = 0;
	i = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] == c)
			check = 0;
		else if (check == 0)
		{
			check = 1;
			wc++;
		}
		i++;
	}
	return (wc);
}

char	*mystrdup(const char *s, char c)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	array = malloc(sizeof(char) * ft_lenword(s, c) + 1);
	if (!array)
		return (NULL);
	while (s[i] && s[i] == c)
	{
		i++;
	}
	while (s[i] && s[i] != c)
	{
		array[j] = s[i];
		i++;
		j++;
	}
	array[j] = '\0';
	return (array);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			str[j] = mystrdup(s + i, c);
			if (str[j++] == NULL)
				ft_free(str);
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (str[j] = NULL, str);
}
