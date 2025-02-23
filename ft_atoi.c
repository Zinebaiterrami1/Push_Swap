/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:42:34 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/23 16:21:07 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, char **av, t_stack **stack)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != '\0')
	{
		result = result * 10 + (str[i++] - 48);
		if ((sign == 1 && result > INT_MAX) || (sign == -1
				&& (-result) < INT_MIN))
		{
			helper_fct1(av, stack);
		}
	}
	return (sign * result);
}

void helper_fct1(char **av, t_stack **stack)
{
	ft_free(av);
	if (stack)
		ft_lstclear(stack);
	print_error();
}