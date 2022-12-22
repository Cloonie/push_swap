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
	printf("~~~~~\nstack: %c\n", info->stack);
	printf("size: %d\n", size);
	printf("median: %d\n", info->median);
	printf("btm_half_len: %d\n", info->btm_half_len);
	printf("top_half_len: %d\n", info->top_half_len);
	printf("\nStack A:\n");
	if (stacka == NULL)
		printf("NULL\n");
	while (stacka)
	{
		printf("Value: %3d, Index: %3d\n",
			stacka->value, stacka->index);
		stacka = stacka->next;
	}
	printf("\nStack B:\n");
	if (stackb == NULL)
		printf("NULL\n");
	while (stackb)
	{
		printf("Value: %3d, Index: %3d\n",
			stackb->value, stackb->index);
		stackb = stackb->next;
	}
}