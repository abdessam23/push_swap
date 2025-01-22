/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:21:19 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 18:49:49 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(char **str, int n, int i)
{
	i++;
	while (str[i])
	{
		if (ft_atoi(str[i]) == n)
			return (1);
		i++;
	}
	return (0);
}

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_freetab(int argc, char **tab)
{
	if (argc == 2)
		ft_free(tab);
}

int	ft_check_arg(int argc, char **argv)
{
	int			i;
	char		**tab;
	long long	n;

	i = 0;
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		tab = argv;
	}
	while (tab[i])
	{
		n = ft_atol(tab[i]);
		if (n < -2147483648 || n > 2147483647)
			return (ft_check_error(argc, tab, "Error\n"));
		if (!is_number(tab[i]))
			return (ft_check_error(argc, tab, "Error\n"));
		if (check_duplicate(tab, n, i))
			return (ft_check_error(argc, tab, "Error\n"));
		i++;
	}
	ft_freetab(tab);
	return (1);
}
