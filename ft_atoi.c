/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:42:34 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/13 12:51:41 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	resultat;
	int			sign;

	i = 0;
	resultat = 0;
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
		resultat = resultat * 10 + (str[i] - 48);
		i++;
	}
	resultat = sign * resultat;
	if (resultat < INT_MIN || resultat > INT_MAX)
		print_error();
	return (resultat);
}
