/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:26:16 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/15 15:54:10 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sqrt(int n)
{
    int i;

    i = 1;
    while (i <= n)
    {
        if (i * i == n)
            return (i);
        
        if (i * i > n)
            return (i - 1);
        i++;
    }
    return (0); 
}

t_stack   fill_stack_b(t_stack a)
{
    t_stack b;

    b.stk = malloc(sizeof(int) * a.c);
    if(!b.stk)
    {
        ft_free_stack(a.stk);
        ft_free_stack(a.sort);
        ft_error("Error\n");
    }
    b.top = 0;
    b.size = a.size;
    b.c = a.size;
    return (b);
}

int find_pos(int n, t_stack *a)
{
    int i;

    i = a->top;
    while(a->stk[i])
    {
        if(a->stk[i] = n)
        {
            return (i);
        }
        i++;
    }
    return (-1);
}
int find_level(int n,t_stack *sorted, int len)