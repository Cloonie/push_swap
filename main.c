/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/11/11 16:26:20 by mliew            ###   ########.fr       */
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

void	sort_array(int *arr, int s)
{
	int	i;
	int	x;
	int	temp_x;
	int	temp;

	x = 0;
	i = s - 1;
	while (x < s)
	{
		temp_x = x;
		while (i >= 0)
		{
			if (arr[x] > arr[i])
			{
				temp = arr[x];
				arr[x] = arr[i];
				arr[i] = temp;
				x++;
			}
			i++;
		}
		x = temp_x + 1;
		i = x;
	}
}

void	quick_sort(t_list **stacka, t_list **stackb, int size)
{
	int	half;
	int	median;

	half = (size / 2) + (size % 2);
	while (ft_lstsize(*stackb) != half)
	{
		if (*stackb)
			median = size + half;
		if ((*stacka)->index <= half)
			push(stacka, stackb, 'b');
		else
			rotate(stacka, 'a');
	}
	// if (half == 3 || half == 2)
	// 	return ;
	// quick_sort(stacka, stackb, half);
}

void	sort_stacks(t_list **stacka, t_list **stackb, int size)
{
	if (size == 2)
		if ((*stacka)->index != 1)
			swap(stacka, 'a');
	if (size == 3)
		sort_three(stacka);
	if (size >= 4)
		quick_sort(stacka, stackb, size);
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
