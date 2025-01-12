/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:57:26 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/12 16:59:39 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//algo for 2, 

void algo_for2_elements(t_stack **a)
{
    if(!*a || !(*a)->next)
        return ;
    if((*a)->data > (*a)->next->data)
        sa(a);
}
//algo for 3,
void algo_for3_elements(t_stack **a)
{
    t_stack *tmp;
    int max_val;
    int max_idx;
    int i;

    i = 0;
    tmp = *a;
    max_idx = 0;
    max_val = tmp->data;
    while (tmp)
    {
        if(tmp->data > max_val)
        {
            max_val = tmp->data;
            max_idx = i;
        }
        tmp = tmp->next;
        i++;
    }
    
    if(max_idx == 0)
        ra(a);
    else if(max_idx == 1)
        rra(a);
    if ((*a)->data > (*a)->next->data)
        sa(a);       // Swap the first two elements
}

//algo for 4,

//algo for 5 fama faw9,