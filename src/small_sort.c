/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:13 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/16 18:55:21 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->c == 2)
		if (a->stack[a->top] > a->stack[a->c - 1])
			sa(a, 1);
	if (a->stack[a->top] > a->stack[a->top + 1] && a->stack[a->c - 1] > a->stack[a->top])
		sa(a, 1);
	else if (a->stack[a->top] > a->stack[a->top + 1] && a->stack[a->top + 1] > a->stack[a->c - 1])
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (a->stack[a->top] > a->stack[a->c - 1] && a->stack[a->top + 1] < a->stack[a->c - 1])
		ra(a, 1);
	else if (a->stack[a->top] < a->stack[a->c - 1] && a->stack[a->c - 1] < a->stack[a->top + 1])
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (a->stack[a->top + 1] > a->stack[a->top]
		&& a->stack[a->top + 1] > a->stack[a->c - 1])
		rra(a, 1);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->stack[a->top] == a->sorted[0]
			|| a->stack[a->top] == a->sorted[1])
			pb(b, a, 1);
		else
			ra(a, 1);
	}
	sort_3(a);
	if (b->stack[b->top] < b->stack[b->c - 1])
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	if (a->stack[a->top] > a->stack[a->top + 1])
		sa(a, 1);
}

void    ft_small_sort(t_stack *a, t_stack *b)
{
    if (a->c == 2)
        sa(a, 1);
    if (a->c == 3)
        sort_3(a);
    else if (a->c > 3 && a->c <= 5)
        sort_5(a, b);
}