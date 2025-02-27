/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:07:14 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/23 16:06:39 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../bonus/get_next_line/get_next_line.h"
# include "../push_swap.h"

int	get_moves(char *r, t_stack **ss, t_stack **b);
int	check_move(char *instruction, t_stack **a, t_stack **b);
int	is_sorted(t_stack **a);
int	helper_fct3(t_stack **a, t_stack **b);

#endif