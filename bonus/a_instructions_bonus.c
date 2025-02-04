/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_instructions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:48:25 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/03 16:20:38 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../push_swap.h"

void ft_swap(int *a, int *b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//swap a , swap the first two nodes, lwla katwli taniya wl3aks
void sa(t_stack **a)
{
    
    if(*a != NULL && (*a)->next != NULL)
    {
        ft_swap(&(*a)->data, &(*a)->next->data);
        write(1, "sa\n", 3);
    }
}

void ra(t_stack **a)
{
    t_stack *first;
    t_stack *last;
    
    if(*a != NULL && (*a)->next != NULL)
    {
        first = (*a)->next;
        last = ft_lstlast(*a);
        last->next = *a; //hna last iwli ippointi 3l adakchi li kan f lwal dstack
        (*a)->next = NULL;
        *a = first;
        write(1, "ra\n", 3);
    }
}

//void *rra()
void rra(t_stack **a)
{
    t_stack *tmp;
    t_stack *last;
    
    if(*a != NULL && (*a)->next != NULL)
    {
        last = *a;
        tmp = *a;
        while (last->next != NULL)
        {
            tmp = last;
            last = last->next;
        }
        last->next = *a;
        *a = last;
        tmp->next = NULL;
        write(1, "rra\n", 4);
    }
}

void pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if(!*b)
        return;
    tmp =  (*b)->next;
    ft_lstadd_front(a, ft_lstnew((*b)->data));
    free(*b);
    *b = tmp;
    write(1, "pa\n", 3);
}


