/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/11/09 22:03:10 by mliew            ###   ########.fr       */
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
			swap(stacka, 'a');
		i++;
	}
}

// void	sort(t_list **stacka, t_list **stackb, int size)
// {
// 	int	i = 1;
// 	int	num = 0;

// 	while (size)
// 	{
// 		if ((*stacka)->index == i)
// 		{
// 			push(stacka, stackb, 'b');
// 			size--;
// 			i++;
// 		}
// 		else
// 			rotate(stacka, 'a');
// 		num++;
// 	}
// 	i -= 1;
// 	while (i--)
// 	{
// 		push(stackb, stacka, 'a');
// 		num++;
// 	}
// 	printf("Instructions: %d\n", num);
// }

void	sort2(t_list **stacka, t_list **stackb, int size)
{
	int	half;

	half = size / 2;
	while (ft_lstsize(*stackb) != half)
	{
		if ((*stacka)->index <= half)
			push(stacka, stackb, 'b');
		else
			rotate(stacka, 'a');
	}
	
}

void	sort_stacks(t_list **stacka, t_list **stackb, int size)
{
	if (size == 2)
		if ((*stacka)->index != 1)
			swap(stacka, 'a');
	if (size == 3)
		sort_three(stacka);
	if (size >= 4)
		sort2(stacka, stackb, size);
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
