/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:55:31 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/27 16:01:46 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//helper fct
int is_not_digit(const char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    if(str[i] == '\0')
        return (0);
    while (str[i])
    {
        if(str[i] < '0' || str[i] > '9')
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
    while (current) // current->next != NULL
    {
        check = current->next;
        while (check)
        {
            if (check->data == current->data)
                return (0);
            check = check->next;
        }
        current = current->next;
    }
    return(1);
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
        if(!is_not_digit(av[j]))
            print_error();
        j++;
    }
}

//stack init
t_stack *init_stack(char **av)
{
    int data;
    t_stack *new;
    t_stack *stack;
    int j;
    
    j = 0; 
    stack = NULL;
    //printf("\nValue before enteering the loop %s\n", av[j]);
    while (av[j])
    {
        printf("\nDebugging: %s\n", av[j]);
        data = ft_atoi(av[j]);
        //printf("\nValue after enteering the loop %d\n", data);
        new = ft_lstnew(data);
        if(!new)
            exit(1);
        printf("{%d}\n", new->data);
        ft_lstadd_back(&stack, new);
        j++;
    }
    if(check_dup(stack) == 0)
        print_error();
    return (stack);
}
