/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/09/22 21:05:24 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = ft_split(av[1]);
	stackb = NULL;
	i = 1;
	while (ac > 1 && av[i])
	{
		if (atoi(av[i]) == atoi(av[i - 1]))
			exit (0);
		ft_printf("%d\n", atoi(av[i]));
		i++;
	}
	// write (1, "\n", 1);
}
