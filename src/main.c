/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:40:12 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/26 13:05:46 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// SORTING LOGIC: THIRDS-SORTING (my ivention by given conditions)
// 
// Given operations in two stacks:
// 1. 'push' an element from stack A to B or vice versa (pb, pa)
// 2. 'swap' the top two elements of stack A or B or BOTH (sa, sb, ss)
// 3. 'rotate' the stack by moving the top element to the bottom:
//	 	either in stack A or B or BOTH (ra, rb, rr)
// 4. 'reverse rotate' the stack by moving the bottom element to the top:
//	 	either in stack A or B or BOTH (rra, rrb, rrr)
// 
// My algorithm works by dividing the stack into three parts to sort:
// When executing the algorithm from the left (stack A to B):
// 1. the first third (smallest elements) is sorted to the bottom of stack B
// 2. the second third (middle elements) is sorted to the top of stack B
// 3. the last third (largest elements) is sorted to the bottom of stack A
// 4. thirds are sorted recursively the same way and pushed back to stack A
//
// The algorithm is optimized for the given operations because rr and rrr
// sometimes allows to sort two elements at once - in stack A and B.
// For stacks with less than 5 elements, there are optimized functions.
//
// Note: The algorithm is not the fastest and could be optimized further
// 			at some points. Eg. the thirds sorting could stop when two
// 			thirds would have been moved. There was no time to implement this.
//		Anyway, the algorithm performs quite good in O(n * log(n)) range.

// main control inputs and sorting
// stacks can also be printed using "print(&stacks)"
int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (1);
	if (!stacks_init(&stacks))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!fill_stack(&stacks, argc, argv))
		return (free_stacks(&stacks), ft_putstr_fd("Error\n", 2), 1);
	if (stacks.total)
		sort_from_left(&stacks, 1, stacks.total);
	free_stacks(&stacks);
	return (0);
}
