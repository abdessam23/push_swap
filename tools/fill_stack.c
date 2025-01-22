/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:47:39 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 18:58:08 by abhimi           ###   ########.fr       */
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

static void	fill_array(t_stack *a, char **tab, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	a->stk = malloc(sizeof(int) * (count_args(tab)));
	if (!a->stk)
	{
		free(a->stk);
		ft_error("Error\n");
	}
	i = 0;
	if (argc > 2)
		i = 1;
	while (tab[i])
	{
		a->stk[j++] = ft_atoi(tab[i]);
		i++;
	}
	a->top = 0;
	a->size = j;
	a->c = j;
	ft_sorted(a);
}

t_stack	fill_stack_a(int argc, char **argv)
{
	char	**tab;
	t_stack	a;

	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
		tab = argv;
	fill_array(&a, tab, argc);
	if (argc == 2)
		ft_free(tab);
	return (a);
}
