/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:58 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/01 16:43:55 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_sorted(t_stack a)
{
	int	i;

	i = 0;
	while (i < a.c - 1)
	{
		if (a.stk[i] > a.stk[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stk);
	free(stack_b->stk);
	free(stack_a->sort);
}

void	wrong_number(char **args, t_stack *a)
{
	ft_free(args);
	free(a->stk);
	ft_error("Error\n");
}

int	ft_atol(char *str, char **args, t_stack *a)
{
	int		i;
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
		if (str[i] < '0' || str[i] > '9')
			wrong_number(args, a);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (sign * num < INT_MIN || sign * num > INT_MAX)
			wrong_number(args, a);
	}
	if (str[i] != '\0')
		wrong_number(args, a);
	return (num * sign);
}
