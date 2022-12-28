/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:16:29 by mliew             #+#    #+#             */
/*   Updated: 2022/12/23 03:16:29 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printing(t_list *stacka, t_list *stackb, t_info *info, int size)
{
	ft_printf("~~~~~\nstack: %c\n", info->stack);
	ft_printf("size: %d\n", size);
	ft_printf("median: %d\n", info->median);
	ft_printf("btm_half_len: %d\n", info->btm_half_len);
	ft_printf("top_half_len: %d\n", info->top_half_len);
	ft_printf("\nStack A:\n");
	if (stacka == NULL)
		ft_printf("NULL\n");
	while (stacka)
	{
		ft_printf("Value: %3d, Index: %3d\n",
			stacka->value, stacka->index);
		stacka = stacka->next;
	}
	ft_printf("\nStack B:\n");
	if (stackb == NULL)
		ft_printf("NULL\n");
	while (stackb)
	{
		ft_printf("Value: %3d, Index: %3d\n",
			stackb->value, stackb->index);
		stackb = stackb->next;
	}
}

void	printingstack(t_list *stacka, t_list *stackb)
{
	ft_printf("\nStack A:\n");
	if (stacka == NULL)
		ft_printf("NULL\n");
	while (stacka)
	{
		ft_printf("Value: %3d, Index: %3d\n",
			stacka->value, stacka->index);
		stacka = stacka->next;
	}
	ft_printf("\nStack B:\n");
	if (stackb == NULL)
		ft_printf("NULL\n");
	while (stackb)
	{
		ft_printf("Value: %3d, Index: %3d\n",
			stackb->value, stackb->index);
		stackb = stackb->next;
	}
}
