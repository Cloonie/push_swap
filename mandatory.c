/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:57:45 by mliew             #+#    #+#             */
/*   Updated: 2022/12/27 00:47:49 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	t_info	*info;

	stackb = NULL;
	info = NULL;
	if (ac == 1)
		exit (0);
	stacka = fill_stack(ac, av);
	check_dup(stacka);
	assign_index(stacka);
	info = init_info(info, stacka);
	sort_stacks(&stacka, &stackb, info);

	// if (is_sorted(&stacka) && stackb == NULL)
	// 	printf("OK\n");
	// else
	// 	printf("KO\n");
	// while (get_next_line(1));
	// printing(stacka, stackb, info, 0);
	// system("leaks push_swap");
}
