/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:19:09 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/25 04:21:27 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fct to have index of the all elements in, stack 

int find_the_smallest(t_stack **stack)
{
    t_stack *tmp;
    int min_val;
    int idx;
    int i;
    
    i = 0;
    tmp = *stack;
    min_val = tmp->data;
    idx = 0;
    while (tmp)
    {
        if(tmp->data < min_val)
        {
            min_val = tmp->data;
            idx = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (idx);
}

int find_the_largest(t_stack **stack)
{
     t_stack *tmp;
    int max_val;
    int max_idx;
    int i;

    i = 0;
    tmp = *stack;
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
    return (max_idx);
}

char *join_args(int ac, char **av)
{
    int i;
    char *join;
    char *tmp;
    
    join = malloc(1);
    i = 1;
    join = "";
    while (i < ac)
    {
        tmp = join;
        join = ft_strjoin(join, av[i]);
        free(tmp);
        while (i < ac - 1)
        {
            tmp = join;
            join = ft_strjoin(join, " ");
            free(tmp);
        }
        i++;
    }
    return (join);
}