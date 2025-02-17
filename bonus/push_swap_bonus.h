/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-err <zait-err@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:07:14 by zait-err          #+#    #+#             */
/*   Updated: 2025/02/16 10:53:38 by zait-err         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../bonus/get_next_line/get_next_line.h"
# include "../push_swap.h"

void	get_moves(char *r, t_stack **ss, t_stack **b);
void	check_move(char *instruction, t_stack **a, t_stack **b);
int		is_sorted(t_stack **a);
void	push(t_stack **a, t_stack **b);
#endif