/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:42:54 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/05 13:42:55 by zait-err         ###   ########.fr       */
/*                           void ft_swap(int *a,
	int *b)                                                 */
/* ************************************************************************** */

#include "../push_swap.h"
#include "push_swap_bonus.h"

void	sb(t_stack **b)
{
	if (*b != NULL && (*b)->next != NULL)
	{
		ft_swap(&(*b)->data, &(*b)->next->data);
	}
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*b != NULL && (*b)->next != NULL)
	{
		first = (*b)->next;
		last = ft_lstlast(*b);
		last->next = *b;
		(*b)->next = NULL;
		*b = first;
	}
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*b != NULL && (*b)->next != NULL)
	{
		last = *b;
		tmp = *b;
		while (last->next != NULL)
		{
			tmp = last;
			last = last->next;
		}
		last->next = *b;
		*b = last;
		tmp->next = NULL;
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, ft_lstnew((*a)->data));
	free(*a);
	*a = tmp;
}
