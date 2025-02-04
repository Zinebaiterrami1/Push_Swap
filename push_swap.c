/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:13:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/04 15:05:28 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

// int main(int argc, char **argv)
// {
//     int i;
//     char **s;
//     char *join;
//     t_stack *ss;
//     //t_stack *tmp;
//     t_stack *b;
//     int *array;
//     int size;
//     int j;
//     int *r;
    
//     i = 1;
//     b = NULL;
//     if(argc < 2 || argv[i][0] == '\0')
//         return (0);
//     check_error(argc, argv); 
//     join = join_args(argc, argv);
//     size = argc - 1;
//     array = malloc(size * sizeof(int));
//     if(!array)
//         return (0);
//     j = 0;
//     s = ft_split(join, ' '); 
//     while (s[j])
//     {   
//         array[j] = ft_atoi(s[j]);
//         j++;
//     }
//     r = ft_bubble_sort(array, size);
//     ss = init_stack(s);
//     //push_to_b(&ss, r, &b);
//     algo_for3_elements(&ss);
//     printf("\n------end of program--------");
// }
