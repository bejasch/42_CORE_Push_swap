/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:14:33 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:26 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
t_stacks	*pa(t_stacks *stacks)
{
	push(stacks->st_b, stacks->st_a);
	write(1, "pa\n", 3);
	return (stacks);
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
t_stacks	*pb(t_stacks *stacks)
{
	push(stacks->st_a, stacks->st_b);
	write(1, "pb\n", 3);
	return (stacks);
}

// pa (0) / pb (1) n times
void	p_times(t_stacks *stacks, size_t n, char st_b)
{
	if (st_b)
		while (n--)
			pb(stacks);
	else
		while (n--)
			pa(stacks);
}
