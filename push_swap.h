/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:15:46 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/12 16:51:41 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

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
void algo_for4_elements(t_stack **a, t_stack **b);
int find_the_smallest(t_stack **stack);
int find_the_largest(t_stack **stack);
void algo_for5_elements(t_stack **a, t_stack **b);
void    push_to_b(t_stack **a, int *arr_sorted, t_stack **b, int end);
void	phase_2(t_stack **a, t_stack **b);
void print_error(void);
int is_not_digit(const char *str);
int check_dup(t_stack *a);
int check_if_args_empty(char *av);
void check_error(int ac, char **av);
char	*ft_strjoin(char *s1, char *s2);
t_stack *init_stack(char **av);
char *join_args(int ac, char **av);
char	*ft_strdup(const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
int *ft_bubble_sort(int arr[], int n);
void	phase_2(t_stack **a, t_stack **b);
int is_sorted(t_stack **a);
void	ft_lstclear(t_stack **lst);
char **ft_free(char **s);
void	incr_segment(int *start, int *end, int size);
void    algo(t_stack **a, int *sorted_arr, t_stack **b);
void call_algo_functions(int count, t_stack **ss, int *r, t_stack **b);
#endif