/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:07:16 by mliew             #+#    #+#             */
/*   Updated: 2022/12/26 20:07:16 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extra_op(t_list **stacka, t_list **stackb, char *op)
{
	if (ft_strncmp(op, "ss\n", 3) == 0)
	{
		swap(stacka, 0);
		swap(stackb, 0);
	}
	else if (ft_strncmp(op, "rr\n", 3) == 0)
	{
		rotate(stacka, 0);
		rotate(stackb, 0);
	}
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
	{
		reverse_rotate(stacka, 0);
		reverse_rotate(stackb, 0);
	}
	else
		errormsg();
}

void	do_op(t_list **stacka, t_list **stackb, char *op)
{
	if (ft_strncmp(op, "\n", 2) == 0)
		errormsg();
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		push(stackb, stacka, 0);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		push(stacka, stackb, 0);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		swap(stacka, 0);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		rotate(stacka, 0);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		reverse_rotate(stacka, 0);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		swap(stackb, 0);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rotate(stackb, 0);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		reverse_rotate(stackb, 0);
	else
		extra_op(stacka, stackb, op);
}

void	take_op(t_list **stacka, t_list **stackb)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		do_op(stacka, stackb, op);
		op = get_next_line(0);
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
	assign_index(stacka, ft_lstsize(stacka) + 1);
	take_op(&stacka, &stackb);
	if (is_sorted(&stacka) && stackb == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	// system("leaks checker");
}
