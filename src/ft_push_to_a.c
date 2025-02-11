/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:21 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/25 18:23:54 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mid_top_to_a(t_stack *a, t_stack *b, int num, int *level)
{
	(*level)--;
	while (b->stk[b->top] != num)
		rb(b);
	pa(a, b);
}

static void	mid_bot_to_a(t_stack *a, t_stack *b, int num, int *level)
{
	(*level)--;
	while (b->stk[b->top] != num)
		rrb(b);
	pa(a, b);
}

void	ft_push_to_a(t_stack *a, t_stack *b)
{
	int	up;
	int	len;
	int	level;

	level = a->c - 1;
	while (b->size > 0)
	{
		up = b->top;
		len = b->top + b->size - 1;
		while (up <= len)
		{
			if (find_level(b->stk[up], a->sort, a->c) == level)
			{
				mid_top_to_a(a, b, b->stk[up], &level);
				break ;
			}
			if (find_level(b->stk[len], a->sort, a->c) == level)
			{
				mid_bot_to_a(a, b, b->stk[len], &level);
				break ;
			}
			up++;
			len--;
		}
	}
}
