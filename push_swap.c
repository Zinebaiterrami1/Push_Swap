/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:13:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/31 18:14:48 by zait-err         ###   ########.fr       */
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
    t_stack *tmp;
    int *array;
    int size;
    int j;
    int *r;
    
    i = 1;
    if(argc < 2 || argv[i][0] == '\0')
        return (0);
    check_error(argc, argv);
    join = join_args(argc, argv);
    size = argc - 1;
    array = malloc(size * sizeof(int));
    if(!array)
        return (0);
    j = 0;
    printf("joining args : %s\n", join); 
    s = ft_split(join, ' '); 
    for(int k = 0; k <= 10; k++)
    {
        printf("split [%d]:%s\t ", k,s[k]);
    }
    while (s[j])
    {   
        array[j] = ft_atoi(s[j]);
        j++;
    }
    r = ft_bubble_sort(array, size);
    j = 0;
    while (j < size)
    {   
        printf("sorted table :[%d]\t", r[j]);
        j++;
    }
    ss = init_stack(s);
    tmp = ss;
    printf("\nbefore processing-----\n");
    while(tmp != NULL)
    {
        printf("%d-> ", tmp->data);
        tmp = tmp-> next;
    }printf("NULL");
    printf("\nafter processing-----\n");
        // printf("test\n");
    //algo_for3_elements(&ss);
    push_to_b(&ss, r);
    tmp = ss;
    while(tmp != NULL)
    {
        printf("%d-> ", tmp->data);
        tmp = tmp-> next;
    }printf("NULL");
    printf("\n------end of program--------");
}
