/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:44:27 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/17 12:02:55 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// changes first and second elemtent of the stack
void	swap(t_head *stack)
{
	t_rlist	*first;
	t_rlist	*second;

	if (stack->size < 2)
		return ;
	else if (stack->size == 2)
		return (rotate(stack));
	first = stack->list;
	second = stack->list->next;
	first->last->next = second;
	second->next->last = first;
	first->next = second->next;
	second->last = first->last;
	first->last = second;
	second->next = first;
	stack->list = second;
}

static void	add_el_on_stack(t_rlist *element, t_head *stack)
{
	if (!stack->list)
	{
		stack->list = element;
		element->next = element;
		element->last = element;
	}
	else
	{
		element->next = stack->list;
		element->last = stack->list->last;
		stack->list->last->next = element;
		stack->list->last = element;
		stack->list = element;
	}
	stack->size++;
}

// pushes the first element of stack_one to stack_two, if there is one
void	push(t_head *stack_one, t_head *stack_two)
{
	t_rlist	*tmp;

	if (!stack_one->list)
		return ;
	tmp = stack_one->list;
	stack_one->size--;
	if (!stack_one->size)
		stack_one->list = NULL;
	else
	{
		stack_one->list = stack_one->list->next;
		stack_one->list->last = tmp->last;
		tmp->last->next = stack_one->list;
	}
	add_el_on_stack(tmp, stack_two);
}

// rotates the first element of the stack to the end
void	rotate(t_head *stack)
{
	if (stack->list)
		stack->list = stack->list->next;
}

// rotates the last element of the stack to the top
void	reverse_rotate(t_head *stack)
{
	if (stack->list)
		stack->list = stack->list->last;
}
