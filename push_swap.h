/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:58:03 by mliew             #+#    #+#             */
/*   Updated: 2022/11/03 01:28:13 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib42/includes/libft.h"
# include "lib42/includes/ft_printf.h"
# include "lib42/includes/get_next_line_bonus.h"

void	swap(t_list **stacka, int c);
void	rotate(t_list **stack, int c);
void	reverse_rotate(t_list **stack, int c);
void	push(t_list **from, t_list **pushto, int c);

#endif