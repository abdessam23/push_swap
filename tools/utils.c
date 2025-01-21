/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:58 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/21 18:35:46 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error(char   *str)
{
    ft_putstr_fd(str, 1);
    exit (1);
}
void    ft_free(char **str)
{
    int i;
    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str); 
}

int is_sorted(t_stack stack_a)
{
    int i;
    
    i = stack_a.top;
    while(i < stack_a.c - 1)
    {
        if(stack_a.stk[i] > stack_a.stk[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void ft_free_stack(t_stack   *stack_a, t_stack *stack_b)
{
    free(stack_a->stk);
    free(stack_b->stk);
    free(stack_a->sort);
}
long	ft_atol(char *str)
{
	int	sign;
	long long	r;

	r = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r *= 10;
		r += *str - '0';
		str++;
	}
	r *= sign;
	return ((long)r);
}