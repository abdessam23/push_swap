/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:23:05 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/01 16:59:20 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->c <= 5)
		ft_small_sort(stack_a, stack_b);
	else
	{
		ft_push_to_b(stack_a, stack_b);
		ft_push_to_a(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		**str;

	str = args_check(argc, argv);
	stack_a = fill_stack_a(str);
	if (check_duplicate(stack_a.stk, stack_a.size) == 1)
	{
		free(stack_a.stk);
		free(stack_a.sort);
		ft_error("Error\n");
	}
	stack_b = fill_stack_b(stack_a);
	if (!is_sorted(stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a, &stack_b);
	return (0);
}
