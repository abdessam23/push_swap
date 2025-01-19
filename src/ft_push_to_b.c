/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:21 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/15 16:33:59 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void rotate_or_push(t_stack *a, t_stack *b, int num, int rotate_rb_flag)
{
    if (find_pos(num, a) <= (a->size / 2 + a->top))
    {
        while (num != a->stack[a->top])
            ra(a, 1);
    }
    else
    {
        while (num != a->stack[a->top])
            rra(a, 1);
    }

    pb(b, a, 1);
    
    if (rotate_rb_flag)
        rb(b, 1);
}

static void rotate_rb(t_stack *a, t_stack *b, int num)
{
    rotate_or_push(a, b, num, 1);
}

static void just_push(t_stack *a, t_stack *b, int num)
{
    rotate_or_push(a, b, num, 0);
}

static  ft_set(int i, int min, int max, int top)
{
    min++;
    max++;
    i = top;
}

void    ft_push_to_b(t_stack *a, t_stack *b)
{
    int min;
    int max;
    int i;
    int level;

    min = 1;
    max = ft_sqrt(a->c) + a->c / 500 + 5;
    i = a->top;
    while (i < a->size - 1)
    {
        level = find_level(a->stk[i],a->sort, a->c)
        if (level < min)
        {
            rot_rb(a, b, a->stk[i]);
            ft_set(i, min, max, top);
        }
        else if (level >= min && level <= max)
        {
            push_only(a->stk[i],a->sort, a->c);
            ft_set(i, min, max, top);
        }
        i++;
    }  
}