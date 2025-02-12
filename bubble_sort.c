/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:20:32 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/12 16:22:52 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_bubble_sort(int arr[], int n)
{
    int i;
    int j;
    int swapped;
    
    i = 0;
    swapped = 0;
    while (i < n -1)
    {
        j = 0;
        while (j < n - i - 1)
        {  
            if(arr[j] > arr[j + 1])
            {
                ft_swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
            j ++;
        }
        i++;    
        if(swapped == 0)
            break;
    }
    return (arr);
}
