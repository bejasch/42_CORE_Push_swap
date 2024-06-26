/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:47:49 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:50 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// sorts a 2-elements-stack-b to a
void	sort_two_b(t_stacks *st)
{
	if (st->st_b->list->position < st->st_b->list->next->position)
		pa(sb(st));
	else
		pa(st);
	pa(st);
}

// sorts a 3-elements-stack-b to a
void	sort_three_b(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_el(st->st_b, 3);
	if (biggest == 1)
		sort_two_b(pa(st));
	else if (biggest == 2)
		sort_two_b(pa(sb(st)));
	else
	{
		if (st->st_b->size == 3)
			sort_two_b(pa(rrb(st)));
		else
			sort_two_b(rrb(pa(sb(rb(st)))));
	}
}

// sorts a 4-elements-stack-b to a
void	sort_four_b(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_el(st->st_b, 4);
	if (biggest == 1)
		sort_three_b(pa(st));
	else if (biggest == 2)
		sort_three_b(pa(sb(st)));
	else if (st->st_b->size == 5)
	{
		if (biggest == 3)
			sort_three_b(pa(sb(rb(st))));
		else
			sort_three_b(pa(rrb(st)));
	}
	else if (biggest == 3)
		sort_three_b(rrb(pa(sb(rb(st)))));
	else
		sort_three_b(rrb(rrb(pa(sb(rb(rb(st)))))));
}

// sorts a 5-elements-stack-b to a
void	sort_five_b(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_el(st->st_b, 5);
	if (biggest == 1)
		sort_four_b(pa(st));
	else if (biggest == 2)
		sort_four_b(pa(sb(st)));
	else if (st->st_b->size == 5)
	{
		if (biggest == 3)
			sort_four_b(pa(rb(rb(st))));
		else if (biggest == 4)
			sort_four_b(pa(rrb(rrb(st))));
		else
			sort_four_b(pa(rrb(st)));
	}
	else if (biggest == 3)
		sort_four_b(rrb(pa(sb(rb(st)))));
	else if (biggest == 4)
		sort_four_b(rrb(rrb(pa(sb(rb(rb(st)))))));
	else
		sort_four_b(rrb(rrb(rrb(pa(sb(rb(rb(rb(st)))))))));
}
