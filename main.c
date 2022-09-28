/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/09/28 16:33:42 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_stack(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*tmp;

	char	**array;
	int		j = 0;

	i = 0;
	head = NULL;
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		while (array[j] != NULL)
		{
			tmp = ft_lstnew(array[j++]);
			ft_lstadd_back(&head, tmp);
		}
		return (head);
	}
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
	while (stacka)
	{
		printf("%d\n", stacka->value);
		stacka = stacka->next;
	}
}
