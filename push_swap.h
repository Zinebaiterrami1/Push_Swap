/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:15:46 by zait-err          #+#    #+#             */
/*   Updated: 2025/01/31 18:20:57 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
// #include "../MyLibft/libft.h"

typedef struct s_list
{
    int data;
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
int ft_atoi(const char *str);
void algo_for2_elements(t_stack **a);
void algo_for3_elements(t_stack **a);
void algo_for4_elements(t_stack **a);
int find_the_smallest(t_stack **stack);
int find_the_largest(t_stack **stack);
void algo_for5_elements(t_stack **a);
t_stack** push_to_b(t_stack **a, int *arr_sorted);
void push_to_a(int size, t_stack **b, t_stack **a);
void print_error(void);
//parsing function
//int check_number(const char *str);
int is_not_digit(const char *str);
int check_dup(t_stack *a);
// int check_if_stack_empty(const char *a);
void check_error(int ac, char **av);
char	*ft_strjoin(char const *s1, char const *s2);
t_stack *init_stack(char **av);
char *join_args(int ac, char **av);
char	*ft_strdup(const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
int *ft_bubble_sort(int arr[], int n);
#endif