/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:37:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/15 14:41:30 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for2_elements(t_stack **a)
{
	if (!*a || !(*a)->next)
		return ;
	if ((*a)->next == NULL)
		return ;
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	incr_segment(int *start, int *end, int size)
{
	if (*end < size - 1)
		(*end)++;
	if (*start < size - 2)
		(*start)++;
}

void	algo(t_stack **a, int *sorted_arr, t_stack **b)
{
	int	size;
	int	end;

	size = ft_lstsize(*a);
	if (size <= 100)
		end = size / 6;
	else
		end = size / 14;
	push_to_b(a, sorted_arr, b, end);
	while (*a)
		pb(a, b);
	phase_2(a, b);
}

int	is_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if(ft_lstsize(tmp) == 1)
		return (0);
	while (tmp && tmp->next && tmp->data < tmp->next->data)
	{
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (0);
	return (1);
}

void	call_algo_functions(int count, t_stack **ss, int *r, t_stack **b)
{
	if (count == 2)
		algo_for2_elements(ss);
	else if (count == 3)
		algo_for3_elements(ss);
	else if (count == 4)
		algo_for4_elements(ss, b);
	else if (count == 5)
		algo_for5_elements(ss, b);
	else
		algo(ss, r, b);
	free(r);
}
