/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:34 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 11:38:44 by abhimi           ###   ########.fr       */
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

// Check args ....
int  ft_check_arg(int argc, char **argv);
long    ft_atol(char *str);

// Utils ....
void    ft_free(char **str);
void    ft_error(char *str);
void    ft_free_stack(t_stack *stack_a, t_stack *stack_b);
int     ft_sqrt(int n);
int     find_pos(int n, t_stack *a);
int     find_level(int n,int *sorted, int len);
void    ft_sorted(t_stack *a);
int ft_check_error(int ac, char **av, char *str);

// fill stack ....

int   *ft_cpystk(t_stack *a);
t_stack fill_stack_b(t_stack a);
t_stack fill_stack_a(int argc,char  **argv);

// Sorting ....

void    ft_push_to_a(t_stack *a, t_stack *b);
void    ft_push_to_b(t_stack *a, t_stack *b);
void    ft_small_sort(t_stack *a, t_stack *b);
int     is_sorted(t_stack stack_a);

// Instrections ....

void    ft_swap(t_stack *stack);
void	sa(t_stack *a);
void    sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void    ft_rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void    ft_push(t_stack *to, t_stack *from);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ft_rev_rotate(t_stack *stack);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif