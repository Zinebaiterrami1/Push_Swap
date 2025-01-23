/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:13:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/23 15:54:42 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int main(int argc, char **argv)
{
    int i;
    int data;
    char **s;
    char *ss;

    
    i = 1;
    
    while (argv[i])
    {
        check_error(argc, argv);
        ss = ft_split(argv[i], ' ');
        s = init_stack(argc, ss);
        if(argc == 4)
        {
            algo_for3_elements(&s);
        }
        i++;
    }
    printf("------end of program--------");
}