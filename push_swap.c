/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:13:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/24 18:08:42 by zait-err         ###   ########.fr       */
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
		array[j] = ft_atoi(s[j], s, NULL);
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

	join = NULL;
	b = NULL;
	sp = NULL;
	array = 0;
	if (argc < 2)
		return (0);
	check_empty(argv);
	join = join_args(argc, argv);
	sp = ft_split(join, ' ');
	check_error(argc, sp, join);
	free(join);
	a = init_stack(sp);
	if (!is_sorted(&a))
		helper_fct2(&a, sp);
	call_algo_functions(calc_count(sp), &a, sort_array(array, calc_count(sp),
			sp), &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	ft_free(sp);
}

void	helper_fct2(t_stack **a, char **sp)
{
	ft_lstclear(a);
	free_split(sp);
	exit(0);
}
