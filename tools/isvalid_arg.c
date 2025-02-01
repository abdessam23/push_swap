/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:21:19 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/01 17:35:27 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (1);
}

void	check_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			ft_error("Error\n");
		i++;
	}
}

char	**args_check(int ac, char **av)
{
	char	**args;

	if (ac == 1)
		exit(1);
	check_args(av);
	arg_check_int(av);
	args = args_combinor(av);
	if (!args)
		exit(1);
	if (!args[0])
	{
		ft_free(args);
		exit(1);
	}
	return (args);
}

void	arg_check_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9')
					&& (av[i][j] != ' ' && av[i][j] != '-' && av[i][j] != '+'))
			{
				ft_error("Error\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

char	**args_combinor(char **av)
{
	char	*tmp1;
	char	*tmp2;
	int		i;
	char	**args;

	i = 2;
	tmp1 = ft_strjoin(av[1], " ");
	if (!tmp1)
		return (NULL);
	while (av[i])
	{
		tmp2 = ft_strjoin(tmp1, av[i]);
		free(tmp1);
		if (!tmp2)
			return (NULL);
		tmp1 = ft_strjoin(tmp2, " ");
		free(tmp2);
		if (!tmp1)
			return (NULL);
		i++;
	}
	args = ft_split(tmp1, ' ');
	free(tmp1);
	return (args);
}
