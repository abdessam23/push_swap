/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:34 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/16 16:47:00 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct stack
{
    int top;
    int size;
    int c;
    int *stk;
    int *sort;
    struct stack *next;
}t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int     ft_lstsize(t_stack *lst);
t_stack  *ft_lstnew(int value);

void    ft_check_arg(int argc, char **argv);
void    ft_index(t_stack **stack);
void    ft_free(char **str);
void    ft_error(char *str);
void    ft_free_stack(t_stack **stack);

void    radix_sort(t_stack **stack_a, t_stack **stack_b);
void    ft_small_sort(t_stack *stack_a, t_stack *stack_b);


int    ft_rev_rotate(t_stack **stack);
int    ft_push(t_stack **stack_to, t_stack **stack_from);
int    ft_rotate(t_stack **stack);
int    ft_swap(t_stack **stack);

int    pa(t_stack **stack_a, t_stack **stack_b);
int    pb(t_stack **stack_a, t_stack **stack_b);
int    sa(t_stack **stack_a);
int    sb(t_stack **stack_a);
int    ra(t_stack **stack_a);
int    rb(t_stack **stack_a);
int    rra(t_stack  **stack_a);
int    rrb(t_stack  **stack_a);
int     is_sorted(t_stack **stack);


#endif