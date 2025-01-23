/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:55:31 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/23 16:08:09 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"  //

//helper fct
//check number
int check_number(t_stack *a)
{
    t_stack *tmp;
    
    tmp = a;
    while (tmp->next != NULL)
    {
        if(tmp->data >= INT_MAX && tmp->data <= INT_MIN)
            return (1); 
        tmp = tmp->next;
    }
    return(0);
}

int is_digit(const char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
            return (0);
        i++;
    }
    return (1);
}
//degits or dup ==== error
//main. split . check---parsing. init stack. atoi . hto f node.

//check duplicates
int check_dup(t_stack *a)
{
    t_stack *check;
    t_stack *current;

    current = a;
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

//handle empty input

int check_if_stack_empty(t_stack *a)
{
    t_stack *tmp;

    tmp = a;
    if(!tmp)
        return (1);
    return (0);
}
//no parameters , 
void check_error(int ac, char **av)
{
    int j;
    
    j = 1;
    if(ac == 1)
        exit(1);
    while (av[j])
        {
            if(!is_digit(av[j]) || !check_number(av[j]) || !check_dup(av[j]) || !check_if_stack_empty(av[j]))
                print_error();
            j++;
        }
}

//stack init
t_stack *init_stack(int ac, char **av)
{
    int data;
    t_stack *new;
    t_stack *stack;
    int j;

    j = 1;
    stack = NULL;

    while (j < ac)
    {
            data = ft_atoi(av[j]);
            new = ft_lstlast(data);
            if(!new)
                exit(1);
            ft_lstadd_back(&stack, new);
            j++;
    }
    if(check_dup(stack))
        print_error();
    return (stack);
}