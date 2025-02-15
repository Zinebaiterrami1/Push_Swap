/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:13:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/15 17:25:44 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_error(void)
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

int	main(int argc, char **argv)
{
	char	**sp;
	t_stack	*a;
	t_stack	*b;
	int		*array;
	char	*join;

	b = NULL;
	array = 0;
	if (argc < 2)
		return (0);
	check_overflow(argv);
	join = join_args(argc, argv);
	check_empty(argv);
	sp = ft_split(join, ' ');
	check_error(argc, sp);
	a = init_stack(sp);
	t_stack *tmp;
	tmp = a;
	while (tmp != NULL)
	{
		printf("%d-->", tmp->data);
		tmp = tmp->next;	
	}
	printf("NULL\n");
	is_sorted(&a);
	call_algo_functions(calc_count(sp), &a, sort_array(array, argc, sp), &b);
	ft_lstclear(&a);
	ft_free(sp);
	free(join);
}

void	check_overflow(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11 && ft_atoi(argv[i]) == -1)
			print_error();
		i++;
	}
}
