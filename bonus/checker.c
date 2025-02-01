/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:36:31 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/01 16:48:34 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_del(t_stack *a, t_stack *b, char *str)
{
	free(str);
	ft_free_stack(a, b);
	ft_error("Error\n");
}

static void	ft_command(char *str, t_stack *a, t_stack *b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_swap(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_swap(b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ft_rotate(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		ft_rotate(b);
	else if (ft_strncmp(str, "rra\n", 3) == 0)
		ft_rev_rotate(a);
	else if (ft_strncmp(str, "rrb\n", 3) == 0)
		ft_rev_rotate(b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_push(a, b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_push(b, a);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr_1(b, a);
	else if (ft_strncmp(str, "rrr\n", 3) == 0)
		rrr_1(b, a);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss_1(b, a);
	else
		ft_del(a, b, str);
}

static void	ft_read_move(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_command(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**str;

	str = args_check(argc, argv);
	stack_a = fill_stack_a(str);
	if (check_duplicate(stack_a.stk, stack_a.size) == 1)
	{
		free(stack_a.stk);
		free(stack_a.sort);
		ft_error("Error\n");
	}
	stack_b = fill_stack_b(stack_a);
	ft_read_move(&stack_a, &stack_b);
	if (stack_b.size == 0 && is_sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(&stack_a, &stack_b);
	return (0);
}
