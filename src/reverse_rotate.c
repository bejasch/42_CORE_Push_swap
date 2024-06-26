/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:16:02 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:30 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
t_stacks	*rra(t_stacks *stacks)
{
	reverse_rotate(stacks->st_a);
	write(1, "rra\n", 4);
	return (stacks);
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
t_stacks	*rrb(t_stacks *stacks)
{
	reverse_rotate(stacks->st_b);
	write(1, "rrb\n", 4);
	return (stacks);
}

// rra and rrb at the same time.
t_stacks	*rrr(t_stacks *stacks)
{
	reverse_rotate(stacks->st_a);
	reverse_rotate(stacks->st_b);
	write(1, "rrr\n", 4);
	return (stacks);
}

// rrr without printing the operation to stdout
t_stacks	*rrr_silent(t_stacks *stacks)
{
	reverse_rotate(stacks->st_a);
	reverse_rotate(stacks->st_b);
	return (stacks);
}

// rr n times stack a (0) or b (1)
t_stacks	*rr_times(t_stacks *stacks, size_t n, char st_b)
{
	if (st_b)
		while (n--)
			rrb(stacks);
	else
		while (n--)
			rra(stacks);
	return (stacks);
}
