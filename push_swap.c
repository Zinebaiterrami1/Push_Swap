/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:13:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/25 04:25:31 by zait-err         ###   ########.fr       */
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
    char **s;
    char *join;
    t_stack *ss;

    i = 1;
    if(argv[i][0] == '\0')
        return (0);
    check_error(argc, argv); 
    join = 
    ss = init_stack(argc, s);
    if(argc == 4)
        algo_for3_elements(&ss);
    while(ss != NULL)
    {
        printf("%d-> ", ss->data);
        ss = ss-> next;
   
    }     printf("NULL");
    printf("\n------end of program--------");
}