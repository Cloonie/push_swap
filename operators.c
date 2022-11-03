/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:38:01 by mliew             #+#    #+#             */
/*   Updated: 2022/11/03 20:51:46 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head, int c)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *head;
	*head = (*head)->next;
	next = (*head)->next;
	(*head)->next = tmp;
	tmp->next = next;
	set_position (*head);
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

void	rotate(t_list **head, int c)
{
	t_list	*tmp;
	t_list	*tail;

	if (!(*head))
		return ;
	tmp = *head;
	*head = (*head)->next;
	tail = ft_lstlast(*head);
	tail->next = tmp;
	tmp->next = NULL;
	set_position (*head);
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_list **head, int c)
{
	t_list	*tmp;
	t_list	*tail;

	tail = ft_lstlast(*head);
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = *head;
	*head = tail;
	set_position (*head);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	push(t_list **from, t_list **pushto, int c)
{
	t_list	*tmp;

	tmp = *from;
	*from = (*from)->next;
	tmp->next = *pushto;
	*pushto = tmp;
	set_position (*pushto);
	set_position (*from);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}