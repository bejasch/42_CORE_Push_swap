/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:37:57 by bschneid          #+#    #+#             */
/*   Updated: 2024/06/24 09:47:14 by bschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft_extended/include/libft.h"
# include <stdlib.h>

// struct for a (double linked) ringlist
typedef struct s_rlist
{
	int				data;
	struct s_rlist	*last;
	struct s_rlist	*next;
	size_t			position;
}	t_rlist;

// head of the ringlist (stack): size and pointer to first element
typedef struct s_head
{
	size_t	size;
	t_rlist	*list;
}	t_head;

// holds both stack pointers and gives total elements
typedef struct s_stacks
{
	size_t	total;
	t_head	*st_a;
	t_head	*st_b;
}	t_stacks;

// FILL INIT
char		stacks_init(t_stacks *stacks);
char		fill_stack(t_stacks *stacks, int argc, char *argv[]);
// OPERATIONS
void		push(t_head *stack_one, t_head *stack_two);
void		swap(t_head *stack);
void		rotate(t_head *stack);
void		reverse_rotate(t_head *stack);
// FUNCTIONS
t_stacks	*sa(t_stacks *stacks);
t_stacks	*sb(t_stacks *stacks);
t_stacks	*ss(t_stacks *stacks);
t_stacks	*ss_silent(t_stacks *stacks);
t_stacks	*pa(t_stacks *stacks);
t_stacks	*pb(t_stacks *stacks);
void		p_times(t_stacks *stacks, size_t n, char st_b);
t_stacks	*ra(t_stacks *stacks);
t_stacks	*rb(t_stacks *stacks);
t_stacks	*rr(t_stacks *stacks);
t_stacks	*rra(t_stacks *stacks);
t_stacks	*rrb(t_stacks *stacks);
t_stacks	*rrr(t_stacks *stacks);
t_stacks	*rr_silent(t_stacks *stacks);
t_stacks	*rrr_silent(t_stacks *stacks);
t_stacks	*rr_times(t_stacks *stacks, size_t n, char st_b);
// CONTROL
char		n_ascending(t_head *stack, size_t n);
char		n_descending(t_head *stack, size_t n);
size_t		biggest_el(t_head *head, size_t n);
// UTILS
void		print(t_stacks *stacks);
void		free_stacks(t_stacks *stacks);
// SMALL SORTING FROM LEFT
void		sort_two_a(t_stacks *st);
void		sort_three_a(t_stacks *st);
void		sort_four_a(t_stacks *st);
void		sort_five_a(t_stacks *st);
// SMALL SORTING FROM RIGHT
void		sort_two_b(t_stacks *st);
void		sort_three_b(t_stacks *st);
void		sort_four_b(t_stacks *st);
void		sort_five_b(t_stacks *st);
// SORTING INTO THIRDS
void		sort_from_left(t_stacks *stacks, size_t min_el, size_t max_el);
void		sort_from_right(t_stacks *stacks, size_t min_el, size_t max_el);

#endif
