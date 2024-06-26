/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:20:48 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:53 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
t_stacks	*sa(t_stacks *stacks)
{
	swap(stacks->st_a);
	write(1, "sa\n", 3);
	return (stacks);
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
t_stacks	*sb(t_stacks *stacks)
{
	swap(stacks->st_b);
	write(1, "sb\n", 3);
	return (stacks);
}

// sa and sb at the same time.
t_stacks	*ss(t_stacks *stacks)
{
	swap(stacks->st_a);
	swap(stacks->st_b);
	write(1, "ss\n", 3);
	return (stacks);
}

t_stacks	*ss_silent(t_stacks *stacks)
{
	swap(stacks->st_a);
	swap(stacks->st_b);
	return (stacks);
}
