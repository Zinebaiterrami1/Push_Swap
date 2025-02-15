/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:14:55 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/14 16:27:21 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_count(char **sp)
{
	int	count;

	count = 0;
	while (sp[count])
	{
		count++;
	}
	return (count);
}

void	check_empty(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i] || av[i][0] == '\0' || check_espace(av[i]) == 1)
			print_error();
		i++;
	}
}

int	check_espace(char *av)
{
	int	size;
	int	i;
	int	count_esp;

	i = 0;
	count_esp = 0;
	size = ft_strlen(av);
	while (av[i])
	{
		if (av[i] == ' ')
			count_esp++;
		i++;
	}
	if (count_esp == size)
		return (1);
	else
		return (0);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*current;

	current = *lst;
	while (current != NULL)
	{
		ptr = current->next;
		free(current);
		current = ptr;
	}
	*lst = NULL;
}
