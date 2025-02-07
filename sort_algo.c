/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:57:26 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/07 16:06:34 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//algo for 2, 

void algo_for2_elements(t_stack **a)
{
    if(!*a || !(*a)->next)
        return ;
    if(                   (*a)->next == NULL)
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
void    push_to_b(t_stack **a, int *arr_sorted, t_stack **b)
{
    if(!*a)
        return;
    int size;
    int start;
    int end;
    
    start = 0;
    size = ft_lstsize(*a);
    if(size <= 100)
        end = size / 6;
    else
        end = size / 14;
    // printf("\n size of stack  == %d ,end ==%d \n",size,end);
    while (end < size && *a)
    {   
        if((*a)->data <= arr_sorted[start])
        {   
            pb(a, b);
            rb(b);
            start++;
            end++;
        }
        else if((*a)->data <= arr_sorted[end])
        {   
            pb(a, b);
            if (*b && (*b)->next && (*b)->data < (*b)->next->data)
                sb(b);
            start++;
            end++;

        }
        else if((*a)->data > arr_sorted[end])
        {   
            ra(a);
        }
    }
    while(*a)
    {
        pb(a, b);
    }

    // t_stack *tmp_b = *b;
    // printf("\nnew stack sorted (b):\n");
    // while (tmp_b)
    // {
    //     printf("%d\n", tmp_b->data);
    //     tmp_b = tmp_b->next;
    // }
    // printf("NULL");

    // printf("\ncheck if any nodes left in stack a:\n");
    // t_stack *tmp_z = *a;
    // printf("\njust check:\n");
    // while (tmp_z)
    // {
    //     printf("%d---->", tmp_z->data);
    //     tmp_z = tmp_z->next;
    // }printf("NULL\n");
    
    phase_2(a, b);               
    // t_stack *tmp_c = *a;
    // printf("\nnew stack sorted:\n");
    // while (tmp_c)
    // {
    //     printf("%d---->", tmp_c->data);
    //     tmp_c = tmp_c->next;
    // }printf("NULL\n");
    // tmp_c = *a;
    // while (tmp_c)
    // {
    //     printf("%d\n", tmp_c->data);
    //     tmp_c = tmp_c->next;
    // }printf("NULL\n");
}

void	phase_2(t_stack **a, t_stack **b)
{
	int	biggest;
    
	while (*b)
	{
		biggest = find_the_largest(b);
		while (biggest != 0  && biggest != ft_lstsize(*b))
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

int is_sorted(t_stack **a)
{
    t_stack *tmp;

    tmp = *a;
    while (tmp && tmp->next && tmp->data < tmp->next->data)
    {
        tmp = tmp->next;
    }
    if(tmp->next == NULL)
        return (0);
    return (1);
}