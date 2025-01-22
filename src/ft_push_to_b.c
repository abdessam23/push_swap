/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:21 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 11:42:44 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_or_push(t_stack *a, t_stack *b, int num, int rotate_rb_flag)
{
	int	pos;

	pos = find_pos(num, a);
	if (pos <= (a->size / 2 + a->top))
	{
		while (num != a->stk[a->top])
			ra(a);
	}
	else
	{
		while (num != a->stk[a->top])
			rra(a);
	}
	pb(a, b);
	if (rotate_rb_flag)
		rb(b);
}

static void	rot_rb(t_stack *a, t_stack *b, int num)
{
	rotate_or_push(a, b, num, 1);
}

static void	push_only(t_stack *a, t_stack *b, int num)
{
	rotate_or_push(a, b, num, 0);
}

static void	ft_set(int *i, int *min, int *max, int top)
{
	(*min)++;
	(*max)++;
	*i = top;
}

void	ft_push_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	i;
	int	level;

	min = 1;
	max = ft_sqrt(a->c) + a->c / 500 + 5;
	i = a->top;
	while (i < a->c)
	{
		level = find_level(a->stk[i], a->sort, a->c);
		if (level < min)
		{
			rot_rb(a, b, a->stk[i]);
			ft_set(&i, &min, &max, a->top);
			continue ;
		}
		else if (level >= min && level <= max)
		{
			push_only(a, b, a->stk[i]);
			ft_set(&i, &min, &max, a->top);
			continue ;
		}
		i++;
	}
}
