/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirds_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:47:58 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:59 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	sort_back_left(t_stacks *st, size_t min, size_t max, size_t trd)
{
	if (st->st_a->size > max - min + 1 - 2 * trd)
		rr_times(st, max - min + 1 - 2 * trd, 0);
	sort_from_left(st, min + 2 * trd, max);
	sort_from_right(st, min + trd, min + 2 * trd - 1);
	if (st->st_b->size > trd)
		rr_times(st, trd, 1);
	sort_from_right(st, min, min + trd - 1);
}

// sorts from left two thirds to right up/bottom
static void	thirds_right(t_stacks *st, size_t min, size_t max, size_t size)
{
	size_t	trd;
	size_t	i;

	trd = size / 3;
	if (size % 3 == 2)
		trd++;
	i = 0;
	while (i++ < size)
	{
		if (st->st_a->list->position < min + trd)
		{
			if (st->st_a->list->next->position >= min + 2 * trd && i < size)
			{
				rr(pb(st));
				i++;
			}
			else
				rb(pb(st));
		}
		else if (st->st_a->list->position < min + 2 * trd)
			pb(st);
		else
			ra(st);
	}
	sort_back_left(st, min, max, trd);
}

// checks how to sort from left
void	sort_from_left(t_stacks *stacks, size_t min_el, size_t max_el)
{
	size_t	size;

	size = max_el - min_el + 1;
	if (n_ascending(stacks->st_a, size))
		return ;
	if (size > 5)
		thirds_right(stacks, min_el, max_el, size);
	else if (size == 5)
		sort_five_a(stacks);
	else if (size == 4)
		sort_four_a(stacks);
	else if (size == 3)
		sort_three_a(stacks);
	else if (size == 2)
		sort_two_a(stacks);
}
