/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:26:39 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:02 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// returns 1 if and only if first n elements are in ascending order 
char	n_ascending(t_head *stack, size_t n)
{
	t_rlist	*current;

	if (!stack->list)
		return (0);
	current = stack->list;
	while (--n)
	{
		if (current->position > current->next->position)
			return (0);
		current = current->next;
	}
	return (1);
}

// returns 1 if and only if first n elements are in descending order
char	n_descending(t_head *stack, size_t n)
{
	t_rlist	*current;

	if (!stack->list)
		return (0);
	current = stack->list;
	while (--n)
	{
		if (current->position < current->next->position)
			return (0);
		current = current->next;
	}
	return (1);
}

// finds the position of the biggest of first n elements in stack
size_t	biggest_el(t_head *head, size_t n)
{
	size_t	curr_pos;
	size_t	max_value;
	size_t	max_pos;
	t_rlist	*tmp;

	if (!head->size)
		return (0);
	tmp = head->list;
	max_pos = 1;
	max_value = tmp->position;
	curr_pos = 1;
	while (curr_pos++ < n)
	{
		if (tmp->next->position > max_value)
		{
			max_value = tmp->next->position;
			max_pos = curr_pos;
		}
		tmp = tmp->next;
	}
	return (max_pos);
}
