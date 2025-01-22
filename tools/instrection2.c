/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:15:09 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 19:18:00 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_putstr_fd("pb\n", 1);
}

void	rra(t_stack *a)
{
	ft_rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	ft_rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
