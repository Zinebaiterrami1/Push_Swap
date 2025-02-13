/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:51:25 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/09 16:04:39 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 1);
}
