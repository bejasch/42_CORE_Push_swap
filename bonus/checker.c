/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:46:13 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/26 12:46:05 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// checks if the line is an operation and executes it
static char	is_operation(t_stacks *stacks, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(stacks->st_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(stacks->st_b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss_silent(stacks);
	else if (!ft_strncmp(line, "pa\n", 3))
		push(stacks->st_b, stacks->st_a);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(stacks->st_a, stacks->st_b);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(stacks->st_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(stacks->st_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr_silent(stacks);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(stacks->st_a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(stacks->st_b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr_silent(stacks);
	else
		return (0);
	return (1);
}

char	get_inputs(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (is_operation(stacks, line))
			free(line);
		else if (!ft_strncmp(line, "\n", 1))
			return (free(line), 1);
		else
			return (free(line), 0);
		line = get_next_line(0);
	}
	write(1, "\n", 1);
	return (1);
}

// checker program that reads from stdin and 
// checks if the operations sort the stack a ascending while b is empty
// Check will be triggered by EOF (pressing ctrl+d) or pressing enter twice
int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc == 1)
		return (1);
	if (!stacks_init(&stacks))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!fill_stack(&stacks, argc, argv))
		return (free_stacks(&stacks), ft_putstr_fd("Error\n", 2), 1);
	if (!get_inputs(&stacks))
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_printf("\033[A\033[K");
	if (n_ascending(stacks.st_a, stacks.st_a->size) && !stacks.st_b->size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
