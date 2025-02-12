/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:57:26 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/12 16:57:30 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for3_elements(t_stack **a)
{
	int	idx;

	if (!*a || !(*a)->next)
		return ;
	idx = find_the_largest(a);
	if (idx == 0)
		ra(a);
	else if (idx == 1)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

// void	algo_for4_elements(t_stack **a)
// {
// 	int	idx;

// 	if (!*a || !(*a)->next)
// 		return ;
// 	idx = find_the_smallest(a);
// 	if (idx == 0)
// 		algo_for3_elements(&(*a)->next);
// 	else if (idx == 1)
// 	{
// 		sa(a);
// 		algo_for3_elements(&(*a)->next);
// 	}
// 	else if (idx == 2)
// 	{
// 		ra(a);
// 		ra(a);
// 		algo_for3_elements(&(*a)->next);
// 	}
// 	else if (idx == 3)
// 	{
// 		rra(a);
// 		algo_for3_elements(&(*a)->next);
// 	}
// }


void algo_for4_elements(t_stack **a, t_stack **b)
{
    int idx;

    if (!*a || !(*a)->next)
        return ;

    idx = find_the_smallest(a);
    if (idx == 0)
        pb(a, b);
    else if (idx == 1)
    {
        sa(a);
        pb(a, b);
    }
    else if (idx == 2)
    {
        ra(a);
        ra(a);
        pb(a, b);
    }
    else if (idx == 3)
    {
        rra(a);
        pb(a, b);
    }
    algo_for3_elements(a);
    pa(a, b);
}



// void	algo_for5_elements(t_stack **a, t_stack **b)
// {
// 	int		smallest_idx;

// 	if (!*a || !(*a)->next)
// 		return ;
// 	b = NULL;
// 	smallest_idx = find_the_smallest(a);
// 	if (smallest_idx <= 2)
// 	{
// 		while (smallest_idx-- > 0)
// 		{
// 			ra(a);
// 		}
// 	}
// 	else
// 	{
// 		while (smallest_idx++ < 5)
// 		{
// 			rra(a);
// 		}
// 	}
// 	pb(a, b);
// 	algo_for4_elements(a, b);
// }

void algo_for5_elements(t_stack **a, t_stack **b)
{
    int smallest_idx;

    if (!*a || !(*a)->next)
        return ;

    smallest_idx = find_the_smallest(a);

    // Move the smallest number to stack B
    if (smallest_idx <= 2)
    {
        while (smallest_idx-- > 0)
            ra(a);
    }
    else
    {
        while (smallest_idx++ < 4) // Fix: should be 4, not 5
            rra(a);
    }
    pb(a, b); // Push the smallest to B

    // Sort the remaining 4 elements
    algo_for4_elements(a, b);

    // Push the smallest element back to A
    pa(a, b);
}


void	push_to_b(t_stack **a, int *arr_sorted, t_stack **b, int end)
{
	int	start;
	int size;
	
	if (!*a)
		return ;
	start = 0;
	size = ft_lstsize(*a);
	while (end < size && *a)
	{
		if ((*a)->data <= arr_sorted[start])
		{
			pb(a, b);
			rb(b);
			incr_segment(&start, &end, size);
		}
		else if ((*a)->data <= arr_sorted[end])
		{
			pb(a, b);
			if (*b && (*b)->next && (*b)->data < (*b)->next->data)
				sb(b);
			incr_segment(&start, &end, size);
		}
		else if ((*a)->data > arr_sorted[end])
			ra(a);
	}
}

void	phase_2(t_stack **a, t_stack **b)
{
	int	biggest;

	while (*b)
	{
		biggest = find_the_largest(b);
		while (biggest != 0 && biggest != ft_lstsize(*b))
		{
			if (biggest < ft_lstsize(*b) / 2)
			{
				rb(b);
				biggest--;
			}
			else
			{
				rrb(b);
				biggest++;
			}
		}
		pa(a, b);
	}
}
