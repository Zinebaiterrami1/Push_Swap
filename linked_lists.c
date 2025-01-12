/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:47:14 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/05 21:35:41 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *ft_lstnew(int data)
{
    t_stack *new_element;
    new_element = malloc(sizeof(t_stack));
    if(!new_element)
        return (NULL);
    new_element->data = data;
    new_element->next = NULL;
    return (new_element);
}
int ft_lstsize(t_stack *lst)
{
    int count;
    t_stack *tmp;
    
    count = 0;
    if(!lst)
        return (0);
    tmp = lst;
    while (tmp->next != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return(count);    
}
void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
    if(!new || !stack)
        return;
    new->next= *stack;
    *stack = new;
}

void 	ft_lstadd_back(t_stack **stack, t_stack *new)
{
    if(!new || !stack)
        return;
    new->next=*stack;
    *stack = new;    
}

t_stack	*ft_lstlast(t_stack *lst)
{
    t_stack *tmp;
    
    if(!lst)
        return (NULL);
    tmp = lst;
    while (tmp->next != NULL)
    {
        tmp= tmp->next;
    }
    return(tmp);
}