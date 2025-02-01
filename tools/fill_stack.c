/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:47:39 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/01 16:44:40 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_cpystk(t_stack *a)
{
	int	*sorted_ar;

	sorted_ar = malloc(sizeof(int) *(a->size));
	if (!sorted_ar)
	{
		free(a->stk);
		ft_error("Error\n");
	}
	ft_memcpy(sorted_ar, a->stk, sizeof(int) * a->c);
	return (sorted_ar);
}

void	ft_sorted(t_stack *a)
{
	int	*sorted_ar;
	int	i;
	int	j;
	int	tmp;

	i = 0;
	sorted_ar = ft_cpystk(a);
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if (sorted_ar[j] > sorted_ar[j + 1])
			{
				tmp = sorted_ar[j];
				sorted_ar[j] = sorted_ar[j + 1];
				sorted_ar[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	a->sort = sorted_ar;
}

static int	count_args(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_duplicate(int *str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (str[i] == str[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	fill_stack_a(char **argv)
{
	t_stack	a;
	int		i;

	i = 0;
	a.stk = malloc(sizeof(int) * (count_args(argv)));
	if (!a.stk)
	{
		free(a.stk);
		ft_free(argv);
		ft_error("Error\n");
	}
	while (argv[i])
	{
		a.stk[i] = ft_atol(argv[i], argv, &a);
		i++;
	}
	a.top = 0;
	a.size = i;
	a.c = i;
	ft_sorted(&a);
	ft_free(argv);
	return (a);
}
