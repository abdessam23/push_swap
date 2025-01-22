/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrection1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:26:27 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 19:23:24 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ra(t_stack *a)
{
	ft_rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	ft_rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_putstr_fd("rr\n", 1);
}
