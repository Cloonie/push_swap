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

void	do_op(t_list **stacka, t_list **stackb, char *op)
{
	if (ft_strncmp(op, "\n", 2) == 0)
		errormsg();
	else if (ft_strncmp(op, "pa", 2) == 0 && *stackb)
		push(stackb, stacka, 0);
	else if (ft_strncmp(op, "pb", 2) == 0 && *stacka)
		push(stacka, stackb, 0);
	else if (ft_lstsize(*stacka) < 2)
		errormsg();
	else if (ft_strncmp(op, "sa", 2) == 0)
		swap(stacka, 0);
	else if (ft_strncmp(op, "ra", 2) == 0)
		rotate(stacka, 0);
	else if (ft_strncmp(op, "rra", 3) == 0)
		reverse_rotate(stacka, 0);
	else if (ft_lstsize(*stackb) < 2)
		errormsg();
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap(stackb, 0);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rotate(stackb, 0);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		reverse_rotate(stackb, 0);
	else if (ft_strncmp(op, "ss", 2) == 0)
	{
		swap(stacka, 0);
		swap(stackb, 0);
	}
	else if (ft_strncmp(op, "rr", 2) == 0)
	{
		rotate(stacka, 0);
		rotate(stackb, 0);
	}
	else if (ft_strncmp(op, "rrr", 3) == 0)
	{
		reverse_rotate(stacka, 0);
		reverse_rotate(stackb, 0);
	}
	else
		errormsg();
	// printingstack(*stacka, *stackb);
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
	assign_index(stacka);
	take_op(&stacka, &stackb);
	if (is_sorted(&stacka) && stackb == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	// system("leaks checker");
}
