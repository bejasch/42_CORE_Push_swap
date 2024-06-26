/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:21:06 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:05 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

char	stacks_init(t_stacks *stacks)
{
	stacks->st_b = NULL;
	stacks->st_a = (t_head *)malloc(sizeof(t_head));
	if (!stacks->st_a)
		return (0);
	stacks->st_b = (t_head *)malloc(sizeof(t_head));
	if (!stacks->st_b)
	{
		free(stacks->st_a);
		return (0);
	}
	stacks->st_a->size = 0;
	stacks->st_a->list = NULL;
	stacks->st_b->size = 0;
	stacks->st_b->list = NULL;
	return (1);
}

// checks if the given value is already in the stack and calcs all positions
static size_t	check_position(t_rlist *tmp, int value)
{
	size_t	position;

	position = 1;
	while (tmp)
	{
		if (tmp->data == value)
			return (0);
		else if (tmp->data < value)
			position++;
		else
			tmp->position++;
		tmp = tmp->next;
	}
	return (position);
}

static t_rlist	*create_ring_el(t_head *stack, char *str)
{
	t_rlist	*new;
	int		value;
	size_t	position;

	if (*str == '\0' || !ft_isai(str))
		return (0);
	value = ft_atoi(str);
	if (*str == '-' && !value)
		return (NULL);
	if (*str != '-' && value == -1)
		return (NULL);
	position = check_position(stack->list, value);
	if (!position)
		return (NULL);
	new = (t_rlist *)malloc(sizeof(t_rlist));
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	new->last = NULL;
	new->position = position;
	return (new);
}

static char	add_elements(t_head *stack, char *argv[], int i)
{
	t_rlist	**endpointer_to_next;
	t_rlist	*new_el;
	t_rlist	*old_el;

	endpointer_to_next = &(stack->list);
	old_el = stack->list;
	while (argv[++i])
	{
		new_el = create_ring_el(stack, argv[i]);
		if (!new_el)
			return (0);
		new_el->last = old_el;
		*endpointer_to_next = new_el;
		endpointer_to_next = &(new_el->next);
		old_el = new_el;
		stack->size++;
	}
	*endpointer_to_next = stack->list;
	if (stack->list)
		stack->list->last = old_el;
	return (1);
}

// fills the stack with th given elements. Returns 0 on wrong input
char	fill_stack(t_stacks *stacks, int argc, char *argv[])
{
	int		i;
	char	out;

	if (argc == 2)
	{
		if (!*argv[1] || *argv[1] == ' ')
			return (0);
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (0);
		argc = 0;
		i = -1;
	}
	else
		i = 0;
	out = add_elements(stacks->st_a, argv, i);
	if (!argc)
		ft_split_free(argv);
	stacks->total = stacks->st_a->size;
	return (out);
}
