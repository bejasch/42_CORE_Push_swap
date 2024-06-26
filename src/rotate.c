/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:15:25 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:33 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
t_stacks	*ra(t_stacks *stacks)
{
	rotate(stacks->st_a);
	write(1, "ra\n", 3);
	return (stacks);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
t_stacks	*rb(t_stacks *stacks)
{
	rotate(stacks->st_b);
	write(1, "rb\n", 3);
	return (stacks);
}

// ra and rb at the same time.
t_stacks	*rr(t_stacks *stacks)
{
	rotate(stacks->st_a);
	rotate(stacks->st_b);
	write(1, "rr\n", 3);
	return (stacks);
}

t_stacks	*rr_silent(t_stacks *stacks)
{
	rotate(stacks->st_a);
	rotate(stacks->st_b);
	return (stacks);
}
