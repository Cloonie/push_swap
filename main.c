/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/11/22 02:58:36 by mliew            ###   ########.fr       */
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

void	quick_sort_a(t_list **stacka, t_list **stackb)
{
	int	median;
	int	midval;
	int	ori_size;

	ori_size = ft_lstsize(*stacka);
	median = (ori_size / 2) + (ori_size % 2);
	midval = median + ft_lstsize(*stackb);
	if (ft_lstsize(*stacka) <= 2)
		return ;
	while (ft_lstsize(*stacka) != median)
	{
		if ((*stacka)->index <= midval && (ori_size % 2) == 0)
			push(stacka, stackb, 'b');
		else if ((*stacka)->index < midval && (ori_size % 2) == 1)
			push(stacka, stackb, 'b');
		else
			rotate(stacka, 'a');
	}
	quick_sort_a(stacka, stackb);
	if ((*stacka)->index > (*stacka)->next->index)
		swap(stacka, 'a');
}

void	quick_sort_b(t_list **stackb, t_list **stacka)
{
	if (ft_lstsize(*stacka) >= ft_lstsize(*stackb))
	{
		while (stackb)
		{
			if ((*stackb)->index == (*stacka)->index - 1)
				push(stackb, stacka, 'a');
			else if ((*stackb)->next->index == (*stacka)->index - 1)
				swap(stackb, 'b');
			else
				rotate(stackb, 'b');
		}
		return ;
	}
	// if ((*stackb)->index == (*stacka)->index - 1)
	// 	push(stackb, stacka, 'a');
	// else if ((*stackb)->next->index == (*stacka)->index - 1)
	// 	swap(stackb, 'b');
	// quick_sort_b(stackb, stacka);
}

void	sort_stacks(t_list **stacka, t_list **stackb, int size)
{
	if (size == 2)
		if ((*stacka)->index != 1)
			swap(stacka, 'a');
	if (size == 3)
		sort_three(stacka);
	if (size >= 4)
	{
		quick_sort_a(stacka, stackb);
		quick_sort_b(stackb, stacka);
	}
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
