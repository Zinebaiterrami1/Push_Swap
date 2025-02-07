/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:55:31 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/07 19:38:26 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_not_digit(const char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    // if(str[i] == '\0')
    //     return (0);
    while (str[i])
    {
        if(str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int check_dup(t_stack *a)
{
    t_stack *check;
    t_stack *current;

    current = a;
    while (current)
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

int check_if_args_empty(char *av)
{
    // if(av[1] == '\0')
    //     return (1);
    int i;

    i = 1;
    while (av[i])
    {
        if(av[i] == '\0' || !av[i])
            return (1);
        i++;
    }
    return (0);
}

void  check_error(int ac, char **av)
{
    int j;
    
    j = 1;
    if(ac == 1)
        exit(1);
    printf("av : %s\n", av[0]);
    // if(av[0] == NULL)
    //     print_error();
    while (av[j])
    {    printf("fdgdfgfdg");
        if(!is_not_digit(av[j]) || !check_if_args_empty(av[j]))
        {
           printf("\n test av = %s \n\n",av[j]);
                    printf("2\n");
            print_error();}
        j++;
    }
}

t_stack *init_stack(char **av)
{
    int data;
    t_stack *new;
    t_stack *stack;
    int j;
    
    j = 0; 
    stack = NULL;
    while (av[j])
    {
        data = ft_atoi(av[j]);
        new = ft_lstnew(data);
        if(!new)
            exit(1);
        ft_lstadd_back(&stack, new);
        j++; 
    }
    if(check_dup(stack) == 0){
                printf("3\n");
        print_error();}
    return (stack);
}
