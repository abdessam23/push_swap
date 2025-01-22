/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:15:01 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 19:24:34 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_push(t_stack *to, t_stack *from)
{
	if (from->size == 0)
		return ;
	to->top--;
	to->size++;
	to->stk[to->top] = from->stk[from->top];
	from->top++;
	from->size--;
}

void	ft_rev_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	i = stack->top + stack->size - 1;
	while (i > stack->top)
	{
		tmp = stack->stk[i];
		stack->stk[i] = stack->stk[i - 1];
		stack->stk[i - 1] = tmp;
		i--;
	}
}

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->stk[stack->top];
		stack->stk[stack->top] = stack->stk[stack->top + 1];
		stack->stk[stack->top + 1] = tmp;
	}
}

void	ft_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	i = 0;
	while (i < stack->size - 1)
	{
		tmp = stack->stk[i + stack->top];
		stack->stk[i + stack->top] = stack->stk[i + stack->top + 1];
		stack->stk[i + stack->top + 1] = tmp;
		i++;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1);
}
