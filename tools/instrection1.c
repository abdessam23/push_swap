/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrection1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:26:27 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/21 13:57:47 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  ft_swap(t_stack *stack)
{
    int tmp;
    if(stack->size >= 2)
    {
        tmp = stack->stk[stack->top];
        stack->stk[stack->top] = stack->stk[stack->top + 1];
        stack->stk[stack->top + 1] = tmp;
    }
}

void	sa(t_stack *a, int msg)
{
    ft_swap(a);
    if (msg)
         ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b, int msg)
{
    ft_swap(b);
    if (msg)
         ft_putstr_fd("sb\n", 1);
}
void	ss(t_stack *a, t_stack *b, int msg)
{
    ft_swap(a);
    ft_swap(b);
    if (!msg)
         ft_putstr_fd("ss\n", 1);
}

void    ft_rotate(t_stack *stack)
{
    int tmp;
    int i;

    if (stack->size < 2)
		return ;
    i = 0;
    while (i < stack->size - 1)
    {
        tmp = stack->stk[i + stack->top];
        stack->stk[i + stack->top] =  stack->stk[i + stack->top + 1];
        stack->stk[i + stack->top + 1] = tmp;
        i++;
    }
}

void	ra(t_stack *a, int msg)
{
    ft_rotate(a);
    if (msg)
         ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b, int msg)
{
    ft_rotate(b);
    if (msg)
        ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b, int msg)
{
    ft_rotate(a);
    ft_rotate(b);
    if (msg)
         ft_putstr_fd("rr\n", 1);
}