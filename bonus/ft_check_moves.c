/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:32:55 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/26 18:13:02 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_1(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	rrr_1(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
}

void	ss_1(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
}
