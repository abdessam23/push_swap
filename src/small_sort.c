/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:13 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 11:43:51 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->c == 2)
		if (a->stk[a->top] > a->stk[a->c - 1])
			sa(a);
	if (a->stk[a->top] > a->stk[a->top + 1] && a->stk[a->c - 1] > a->stk[a->top])
		sa(a);
	else if (a->stk[a->top] > a->stk[a->top + 1] && a->stk[a->top + 1] > a->stk[a->c - 1])
	{
		sa(a);
		rra(a);
	}
	else if (a->stk[a->top] > a->stk[a->c - 1] && a->stk[a->top + 1] < a->stk[a->c - 1])
		ra(a);
	else if (a->stk[a->top] < a->stk[a->c - 1] && a->stk[a->c - 1] < a->stk[a->top + 1])
	{
		sa(a);
		ra(a);
	}
	else if (a->stk[a->top + 1] > a->stk[a->top]
		&& a->stk[a->top + 1] > a->stk[a->c - 1])
		rra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->stk[a->top] == a->sort[0]
			|| a->stk[a->top] == a->sort[1])
			pb(a, b);
		else
			ra(a);
	}
	sort_3(a);
	if (b->stk[b->top] < b->stk[b->c - 1])
		sb(b);
	pa(a, b);
	pa(a, b);
	if (a->stk[a->top] > a->stk[a->top + 1])
		sa(a);
}

void    ft_small_sort(t_stack *a, t_stack *b)
{
    if (a->c == 2)
        sa(a);
    if (a->c == 3)
        sort_3(a);
    else if (a->c > 3 && a->c <= 5)
        sort_5(a, b);
}