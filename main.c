/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/09/27 18:03:02 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_stack(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	i = 0;
	head = NULL;
	while (++i < ac)
	{
		tmp = ft_lstnew(av[i]);
		ft_lstadd_back(&head, tmp);
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_list	*stacka;

	stacka = fill_stack(ac, av);
	printf("%d\n", stacka->value);
	printf("%d\n", stacka->next->value);
}
