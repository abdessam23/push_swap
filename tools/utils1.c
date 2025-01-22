/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:26:16 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/21 18:47:31 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sqrt(int n)
{
    if (n < 0) return -1;
    if (n == 0 || n == 1) return n;

    int low = 1, high = n, mid;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        
        if (mid * mid == n)
            return mid;
        else if (mid * mid < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

t_stack   fill_stack_b(t_stack a)
{
    t_stack b;
    
    b.stk = malloc(sizeof(int) * a.size);
    if(!b.stk)
    {
        free(a.stk);
        free(a.sort);
        ft_error("Error\n");
    }
    b.top = a.size;
    b.size = 0;
    b.c = a.size;
    return (b);
}

int find_pos(int n, t_stack *stack)
{
    int i;

    i = stack->top;
    while(i < stack->c)
    {
        if(stack->stk[i] == n)
            return (i);
        i++;
    }
    return (-1);
}

int find_level(int n,int *sorted, int len)
{
    int i;

    i = 0;
    while (i <= len)
    {
        if (n == sorted[i])
            return(i + 1);
        i++;
    }
    return (-1);
}

int ft_check_error(int ac, char **av, char *str)
{
    if (ac == 2)
        ft_free(av);
    ft_putstr_fd(str, 1);
    return (0);
}