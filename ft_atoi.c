/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:42:34 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/12 18:21:38 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *str)
{
    int i;
    int resultat;
    int sign;

    i = 0;
    resultat = 0;
    sign = 1;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
    {
        i++;
    }
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] != '\0')
    {
        resultat = resultat * 10 + (str[i] - 48);
        i++;
    }
    return (sign * resultat);
}
