/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:42:34 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/15 21:19:36 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_atoi(const char *str)
// {
// 	int			i;
// 	long long	resultat;
// 	int			sign;

// 	i = 0;
// 	resultat = 0;
// 	sign = 1;
// 	if (!str)
// 		return (0);
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -sign;
// 		i++;
// 	}
// 	while (str[i] != '\0')
// 	{
// 		resultat = resultat * 10 + (str[i] - 48);
// 		i++;
// 	}
// 	resultat = sign * resultat;
// 	if (resultat < INT_MIN || resultat > INT_MAX)
// 		print_error();
// 	return (resultat);
// }

// int mystrlen(char *str)
// {
// 	int i;

// 	i = 0;
// 	while(str[i] == '0' || str[i] == '+' || str[i] == '-')
// 		i++;
// 	while(str[i])
// 		i++;
// 	int j;
// 	j = i;
// 	while (str[j])
// 	{
// 		j++;
// 	}
// 	return (j - i);
// }

// void invalid_input(int *data, int i)
// {
// 	if(mystrlen(data[i]) > 11 && (mystrlen(data[i]) == -1 || mystrlen(data[i] == 0) || mystrlen(data[i]) > 2147483647) || mystrlen(data[i]) < -2147483648)
// 	else if(mystrlen(data[i]) == 11 && mystrlen(data[i]) == -2147483648)
// 	else if(mystrlen(data[i]) == 10 && mystrlen(data[i]) == 2147483647)
// }

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;

	// Skip leading spaces
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	// Handle sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Check if next char is a digit after sign
	if (!is_digit(str[i]))
		print_error();

	// Convert digits to integer
	while (str[i] && is_digit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			print_error();
	}

	// Check if trailing characters are invalid
	if (str[i] != '\0')
		print_error();

	return ((int)(result * sign));
}
