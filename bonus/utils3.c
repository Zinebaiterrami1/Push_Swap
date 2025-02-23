/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:05:34 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/23 15:57:29 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_moves(char *r, t_stack **ss, t_stack **b)
{
	int	returnval;

	returnval = 0;
	while (r != NULL)
	{
		returnval = check_move(r, ss, b);
		if (returnval == 1)
			return (returnval);
		free(r);
		r = get_next_line(0, 0);
	}
	return (0);
}

int	is_sorted(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a)
		return (0);
	tmp = *a;
	while (tmp && tmp->next && tmp->data < tmp->next->data)
	{
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (0);
	return (1);
}

int	helper_fct3(t_stack **a, t_stack **b)
{
	get_next_line(0, -1);
	if (a)
		ft_lstclear(a);
	if (b)
		ft_lstclear(b);
	return (1);
}
