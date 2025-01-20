/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:55:31 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/20 21:14:05 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//helper fcts
//check number
int check_number(t_stack **a)
{
    t_stack *tmp;
    
    tmp = *a;
    while (tmp->next != NULL)
    {
        if(tmp->data >= INT_MAX && tmp->data <= INT_MIN)
            return (1); 
        tmp = tmp->next;
    }
    return(0);
}

//check duplicates
int check_dup(t_stack **a)
{
    t_stack *check;
    t_stack *current;

    current = *a;
    while (current->next != NULL)
    {
        check = current->next;
        while (check->next != NULL)
        {
            if(check->data == current->data)
                return (1);
            check = check->next;
        }
        current = current->next;
    }
    return(0);
}