/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:13 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/20 15:39:43 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->c == 2)
		if (a->stk[a->top] > a->stk[a->c - 1])
			sa(a, 1);
	if (a->stk[a->top] > a->stk[a->top + 1] && a->stk[a->c - 1] > a->stk[a->top])
		sa(a, 1);
	else if (a->stk[a->top] > a->stk[a->top + 1] && a->stk[a->top + 1] > a->stk[a->c - 1])
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (a->stk[a->top] > a->stk[a->c - 1] && a->stk[a->top + 1] < a->stk[a->c - 1])
		ra(a, 1);
	else if (a->stk[a->top] < a->stk[a->c - 1] && a->stk[a->c - 1] < a->stk[a->top + 1])
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (a->stk[a->top + 1] > a->stk[a->top]
		&& a->stk[a->top + 1] > a->stk[a->c - 1])
		rra(a, 1);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->stk[a->top] == a->sort[0]
			|| a->stk[a->top] == a->sort[1])
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	sort_3(a);
	if (b->stk[b->top] < b->stk[b->c - 1])
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	if (a->stk[a->top] > a->stk[a->top + 1])
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