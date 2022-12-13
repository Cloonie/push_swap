/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/12/13 23:12:20 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spliting(t_list **src, t_list **dst, int size, int c)
{
	int	median;
	int	total_stacks;
	int	adjust;
	static int recursive;

	recursive++;
	total_stacks = ft_lstsize(*src) + ft_lstsize(*dst);
	median = total_stacks - (size / 2);
	adjust = 0;

	printf("\n|Size: %d| ", size);
	printf("|Median: %d| ", median);
	printf("|Recursion No: %d| \n", recursive);
	// printing(*src, *dst);

	while (size--)
	{
		if ((*src)->index <= median
			&& ((*src)->size == median || (*src)->size == total_stacks))
		{
			(*src)->size = median;
			if (c == 'a')
				push(src, dst, 'b');
			else if (c == 'b')
				push(src, dst, 'a');
		}
		else
		{
			rotate(src, c);
			adjust++;
		}
	}
	while (adjust--)
		reverse_rotate(src, c);
}

// void	re_adjust(t_list **src, int c)
// {
// 	while ((*src)->size == ft_lstlast(*src)->size)
// 		reverse_rotate(src, c);
// }

void	sort_a(t_list **stacka, t_list **stackb, int size)
{
	if (size == 2)
		sort_two(stacka);
	else if (size == 3)
		sort_three(stacka);
	else if (size > 3)
	{
		spliting(stacka, stackb, size, 'a');
		// re_adjust(stacka, 'a');
		printing(*stacka, *stackb);
		sort_a(stacka, stackb, (size / 2));
		sort_b(stackb, stacka, (size / 2));
	}
}

void	sort_b(t_list **stackb, t_list **stacka, int size)
{
	if (size == 2)
		sort_two(stackb);
	else if (size == 3)
		sort_three(stackb);
	else if (size > 3)
	{
		spliting(stackb, stacka, size, 'b');
		// re_adjust(stackb, 'b');
		printing(*stacka, *stackb);
		// sort_b(stackb, stacka, (size / 2));
		// sort_a(stacka, stackb, (size / 2));
	}
}

void	sort_stacks(t_list **stacka, t_list **stackb)
{
	int	size;

	size = ft_lstsize(*stacka);
	if (is_sorted(stacka))
		return ;
	else if (size == 2)
		sort_two(stacka);
	else if (size == 3)
		sort_three(stacka);
	else if (size == 5)
		sort_five(stacka, stackb);
	else
	{
		sort_a(stacka, stackb, size);
		// sort_b(stackb, stacka, size);
	}
}

void	printing(t_list *stacka, t_list *stackb)
{
	printf("\nStack A:\n");
	if (stacka == NULL)
		printf("NULL\n");
	while (stacka)
	{
		printf("Value: %d, Index: %d, Size: %d\n",
			stacka->value, stacka->index, stacka->size);
		stacka = stacka->next;
	}
	printf("\nStack B:\n");
	if (stackb == NULL)
		printf("NULL\n");
	while (stackb)
	{
		printf("Value: %d, Index: %d, Size: %d\n",
			stackb->value, stackb->index, stackb->size);
		stackb = stackb->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;

	stackb = NULL;
	if (ac == 1)
		exit (0);
	stacka = fill_stack(ac, av);
	check_dup(stacka);
	assign_index(stacka);
	set_size(stacka, ft_lstsize(stacka));
	sort_stacks(&stacka, &stackb);

	// printing(stacka, stackb);
	// system("leaks push_swap");
}
