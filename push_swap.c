/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:13:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/13 21:27:12 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*current;

	current = *lst;
	while (current != NULL)
	{
		ptr = current->next;
		free(current);
		current = ptr;
	}
	*lst = NULL;
}

void	free_split(char **str_str)
{
	int	i;

	if (!str_str)
		return ;
	i = 0;
	while (str_str[i])
	{
		free(str_str[i]);
		i++;
	}
	free(str_str);
}

void print_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int	*sort_array(int *array, int ac, char **s)
{
	int	size;
	int	j;
	int	*r;
	int	count;

	size = ac - 1;
	j = 0;
	count = 0;
	while (s[count])
		count++;
	array = malloc(count * sizeof(int));
	if (!array)
		return (0);
	while (s[j])
	{
		array[j] = ft_atoi(s[j]);
		j++;
	}
	r = ft_bubble_sort(array, size);
	return (r);
}

int check_espace(char *av)
{
	int size;
	int i;
	int count_esp;

	i = 0;
	count_esp = 0;
	size = ft_strlen(av);
	while(av[i])
	{
		if(av[i] == ' ')
			count_esp++;
		i++;
	}
	if(count_esp == size)
		return (1);
	else 
	return (0);
	
}

void check_empty(char **av)
{
	int i = 1;
	while(av[i])
	{
		if( !av[i] || av[i][0] == '\0' || check_espace(av[i]) == 1)
			print_error();
		
		i++;
	}
	
}

int main(int argc, char **argv)
{
    char **sp;
    char *join;
    t_stack *a;
    t_stack *b;
    int *r;
    int *array;
    int count;
    
    b = NULL;
    array = 0;
    if(argc < 2)
		return (0);
	check_empty(argv);
    join = join_args(argc, argv);
    sp = ft_split(join, ' ');
    check_error(argc, sp);
    r = sort_array(array, argc, sp);
    a = init_stack(sp);
	is_sorted(&a);
    count = 0;
    while (sp[count])
        count++;
    call_algo_functions(count, &a, r, &b);
    ft_lstclear(&a);
	free(r);
	free(join);
	ft_free(sp);
}
 