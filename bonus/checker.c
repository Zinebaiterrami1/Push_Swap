/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:07:17 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/14 18:28:23 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_move(char *instruction, t_stack **a, t_stack **b)
{
	if (ft_strcmp(instruction, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instruction, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(a, b);
	else
		print_error();
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*b;
	char	**s;
	t_stack	*ss;
	char	*join;
	char	*r;

	b = NULL;
	r = NULL;
	if (argc < 2)
		return (0);
	check_empty(argv);
	join = join_args(argc, argv);
	s = ft_split(join, ' ');
	check_error(argc, s);
	ss = init_stack(s);
	r = get_next_line(0);
	get_moves(r, ss, b);
	if (is_sorted(&ss) == 0 && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&ss);
	ft_lstclear(&b);
	free(join);
	ft_free(s);
}
