/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:19:09 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/17 14:52:25 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_smallest(t_stack **stack)
{
	t_stack	*tmp;
	int		min_val;
	int		idx;
	int		i;

	i = 0;
	tmp = *stack;
	min_val = tmp->data;
	idx = 0;
	while (tmp)
	{
		if (tmp->data < min_val)
		{
			min_val = tmp->data;
			idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (idx);
}

int	find_the_largest(t_stack **stack)
{
	t_stack	*tmp;
	int		max_val;
	int		max_idx;
	int		i;

	i = 0;
	tmp = *stack;
	max_idx = 0;
	max_val = tmp->data;
	while (tmp)
	{
		if (tmp->data > max_val)
		{
			max_val = tmp->data;
			max_idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_idx);
}

char	*ft_strdup(const char *src)
{
	size_t	len_src;
	char	*arr;

	len_src = ft_strlen(src);
	arr = (char *)malloc((len_src + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	ft_memcpy(arr, src, len_src + 1);
	return (arr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (!dest && !src)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}

char	*join_args(int ac, char **av)
{
	int		i;
	char	*join;

	i = 1;
	join = ft_strdup("");
	while (i < ac)
	{
		join = ft_strjoin(join, av[i]);
		join = ft_strjoin(join, " ");
		i++;
	}
	return (join);
}
