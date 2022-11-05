/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/11/05 22:54:26 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stacka)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if ((*stacka)->index == 3)
			rotate(stacka, 'a');
		if ((*stacka)->index == 2 && (*stacka)->next->index == 3)
			reverse_rotate(stacka, 'a');
		if ((*stacka)->index == 2)
			swap(stacka, 'a');
		if ((*stacka)->index == 1 && (*stacka)->next->index == 3)
			rotate(stacka, 'a');
		i++;
	}
}

void	sort_stacks(t_list **stacka, t_list **stackb, int size)
{
	if (size == 3)
		if ((*stacka)->index != 1)
			swap(stacka, 'a');
	if (size == 4)
		sort_three(stacka);
	(void)stackb;
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	int		size;

	stackb = NULL;
	if (ac == 1)
		return (0);
	stacka = fill_stack(ac, av);
	check_dup(stacka);
	size = stacka->size;
	assign_index(stacka, size);
	sort_stacks(&stacka, &stackb, size);

	printf("\nStack A:\n");
	if (stacka == NULL)
		printf("NULL\n");
	while (stacka)
	{
		printf("Value: %d, Index: %d, Pos: %d\n",
			stacka->value, stacka->index, stacka->pos);
		stacka = stacka->next;
	}
	printf("\nStack B:\n");
	if (stackb == NULL)
		printf("NULL\n");
	while (stackb)
	{
		printf("Value: %d, Index: %d, Pos: %d\n",
			stackb->value, stackb->index, stackb->pos);
		stackb = stackb->next;
	}
	// system("leaks push_swap");
}
