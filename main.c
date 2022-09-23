/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/09/23 17:35:34 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->index = 0;
	new->pos = 0;
	new->target_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

t_stack	*fill_stack(int ac, char **av)
{
	int		i;
	t_stack	*head;
	t_stack	*tmp;

	i = 0;
	head = NULL;
	// if (ac == 2)
	// 	return (av[1]);
	while (++i < ac)
	{
		tmp = new_node(ft_atoi(av[1]));
		ft_lstadd_back(head, &tmp);
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = fill_stack(ac, av);
	stackb = NULL;
}
