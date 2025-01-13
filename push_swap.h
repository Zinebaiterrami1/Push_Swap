/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:15:46 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/13 00:02:07 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int data;
    int index;
    int size;
    int pos;
    int start;
    int end;
    struct s_list *next;
}   t_stack;

t_stack      *ft_lstnew(int data);
int					ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void 	ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void sa(t_stack **a);
void ra(t_stack **a);
void rra(t_stack **a);
void pa(t_stack **a, t_stack **b);
void sb(t_stack **b);
void rb(t_stack **b);
void rrb(t_stack **b);
void ft_swap(int *a, int *b);
void pb(t_stack **a, t_stack **b);
void ss(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b);
void rrr(t_stack **a, t_stack **b);
char	**ft_split(const char *s, char c);
int ft_atoi(char *str);
void algo_for2_elements(t_stack **a);
void algo_for3_elements(t_stack **a);
void algo_for4_elements(t_stack **a);
int find_the_smallest(t_stack **stack);
int find_the_largest(t_stack **stack);

#endif