/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:57:26 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/13 00:29:44 by zait-err         ###   ########.fr       */
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
    int idx;

    idx = find_the_largest(a);
    if(idx == 0)
        ra(a);
    else if(idx == 1)
        rra(a);
    if ((*a)->data > (*a)->next->data)
        sa(a);      
}

//algo for 4,
void algo_for4_elements(t_stack **a)
{
    int idx;

    idx = find_the_smallest(a);
    if(idx == 0)
        algo_for3_elements(a);
    else if(idx == 1)
        {
            sa(a);
            algo_for3_elements(&(*a)->next);
        }
    else if(idx == 2)
        {
            ra(a);
            ra(a);
            algo_for3_elements(&(*a)->next);
        }
    else if(idx == 3)
        {
            rra(a);
            algo_for3_elements(&(*a)->next);
        }
}

//algo for 5 fama faw9,

void algo_for5_elemts(t_stack **a)
{
    
}