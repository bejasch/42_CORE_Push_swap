/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:48:48 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:48:08 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	pr_data(t_stacks *stacks, t_rlist *el_a, t_rlist *el_b, size_t i)
{
	while (i--)
	{
		if (i < stacks->st_a->size)
		{
			ft_printf("  |%12d |%3d", el_a->data, el_a->position);
			el_a = el_a->next;
		}
		else
			ft_printf("  |             |   ");
		if (i < stacks->st_b->size)
		{
			ft_printf("   |%12d |%3d\n", el_b->data, el_b->position);
			el_b = el_b->next;
		}
		else
			ft_printf("   |             |\n");
	}
}

void	print(t_stacks *stacks)
{
	size_t	a;
	size_t	b;

	a = stacks->st_a->size;
	b = stacks->st_b->size;
	ft_printf("------------  TOTAL:%3d elements -----------\n", stacks->total);
	ft_printf("   /  STACK A  \\   #    /  STACK B  \\   #\n");
	if (a > b)
		pr_data(stacks, stacks->st_a->list, stacks->st_b->list, a);
	else
		pr_data(stacks, stacks->st_a->list, stacks->st_b->list, b);
	if (a == 1 && b != 1)
		ft_printf(" / %3d element   \\    / %3d elements  \\\n", a, b);
	else if (b == 1 && a != 1)
		ft_printf(" / %3d elements  \\    / %3d element   \\\n", a, b);
	else if (a == 1 && b == 1)
		ft_printf(" / %3d element   \\    / %3d element   \\\n", a, b);
	else
		ft_printf(" / %3d elements  \\    / %3d elements  \\\n", a, b);
	ft_printf("--------------------------------------------\n");
}

// frees the stacks (both a and b head / linked ring lists)
void	free_stacks(t_stacks *stacks)
{
	t_rlist	*tmp;

	if (stacks->st_a)
	{
		while (stacks->st_a->size--)
		{
			tmp = stacks->st_a->list->next;
			free(stacks->st_a->list);
			stacks->st_a->list = tmp;
		}
		free(stacks->st_a);
	}
	if (stacks->st_b)
	{
		while (stacks->st_b->size--)
		{
			tmp = stacks->st_b->list->next;
			free(stacks->st_b->list);
			stacks->st_b->list = tmp;
		}
		free(stacks->st_b);
	}
}
