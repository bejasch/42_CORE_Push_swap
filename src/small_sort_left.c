/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:47:42 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:44 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// sorts a 2-elements-stack-a
void	sort_two_a(t_stacks *st)
{
	if (st->st_a->list->position > st->st_a->list->next->position)
		sa(st);
}

// sorts a 3-elements-stack-a
void	sort_three_a(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_el(st->st_a, 3);
	if (st->st_a->size == 3 && biggest == 1)
		sort_two_a(ra(st));
	else if (biggest == 1)
		sort_two_a(rra(sa(ra(sa(st)))));
	else if (st->st_a->size == 3 && biggest == 2)
		sort_two_a(rra(st));
	else if (biggest == 2)
		sort_two_a(rra(sa(ra(st))));
	else
		sort_two_a(st);
}

// sorts a 4-elements-stack-a
void	sort_four_a(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_el(st->st_a, 4);
	if (biggest == 4)
		sort_three_a(st);
	else if (st->st_a->size == 4)
	{
		if (biggest == 1)
			sort_three_a(ra(st));
		else if (biggest == 2)
			sort_three_a(ra(ra(st)));
		else
			sort_three_a(rra(st));
	}
	else if (biggest == 3)
		sort_three_b(pb(sa(pb(pb(st)))));
	else if (biggest == 2)
		sort_three_b(pb(sa(pb(sa(pb(st))))));
	else
		sort_three_b(rra(pb(pb(pb(ra(st))))));
}

// sorts a 5-elements-stack-a
void	sort_five_a(t_stacks *st)
{
	size_t	biggest;

	biggest = biggest_el(st->st_a, 5);
	if (biggest == 5)
		sort_four_a(st);
	else if (st->st_a->size == 5)
	{
		if (biggest == 4)
			sort_four_a(rra(st));
		else if (biggest == 3)
			sort_four_a(rra(rra(st)));
		else if (biggest == 2)
			sort_four_a(ra(ra(st)));
		else
			sort_four_a(ra(st));
	}
	else if (biggest == 4)
		sort_four_b(pb(sa(pb(pb(pb(st))))));
	else if (biggest == 3)
		sort_four_b(pb(sa(pb(sa(pb(pb(st)))))));
	else if (biggest == 2)
		sort_four_b(rra(pb(pb(pb(ra(pb(st)))))));
	else
		sort_four_b(rra(pb(pb(pb(pb(ra(st)))))));
}
