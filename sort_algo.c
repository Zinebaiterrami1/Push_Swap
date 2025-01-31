/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:57:26 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/31 18:49:07 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//algo for 2, 

void algo_for2_elements(t_stack **a)
{
    if(!*a || !(*a)->next)
        return ;
    if((*a)->next == NULL)
        return;
    if((*a)->data > (*a)->next->data)
        sa(a);
}
//algo for 3,
void algo_for3_elements(t_stack **a)
{
    int idx;
    if(!*a || !(*a)->next)
        return ;
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
    
    if(!*a || !(*a)->next)
        return ;
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

void algo_for5_elements(t_stack **a)
{
    
    t_stack *b;
    
    if(!*a || !(*a)->next)
        return ;
    b = NULL;
    int smallest_idx = find_the_smallest(a);
    if (smallest_idx <= 2)
    {
        while (smallest_idx-- > 0) //smallest_idx--
        {
            ra(a);
        }   
    }
    else
    {
        while (smallest_idx++ < 5) // smallest_idx++ < 5
        {
            rra(a);
        }
    }
    pb(a, &b);
    algo_for4_elements(a);
    pa(a, &b);
}

//algo for 6 elements and more
t_stack** push_to_b(t_stack **a, int *arr_sorted)
{
    t_stack *b;
    t_stack *tmp;
    int size;
    int start;
    int end;
    
    tmp = *a;
    start = 0;
    size = ft_lstsize(*a);
    b = NULL;
    if(size <= 100)
        end = size / 6;
    else
        end = size / 14;
    while (start < end - 1)
    {
        while (tmp != NULL)
        {
            if(tmp->data <= arr_sorted[start])
            {
                pb(a, &b);
                rb(&b);
                start++;
                end++;
            }
            else if(tmp->data <= arr_sorted[end])
            {
                pb(a, &b);
                if (b && b->next && b->data < b->next->data)
                    sb(&b);
                start++;
                end++;
            }
            else if(tmp->data > arr_sorted[end])
            {
                ra(a);
            }
            tmp = tmp->next;
        }
    }
    push_to_a(size, &b, a);
    return(a);
}

void push_to_a(int size, t_stack **b, t_stack **a)
{
    int index;
    
    index = find_the_largest(b);
    if(index < size/2)
    {
        while (index > 0)
        {
            rb(b);
            index --;
        }
    }
    else
    {
        while (index >= size/2)
        {
            rra(b);
            index++;
        }
    }
    pa(a, b);
}
