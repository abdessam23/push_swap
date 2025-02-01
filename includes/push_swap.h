/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:34 by abhimi            #+#    #+#             */
/*   Updated: 2025/02/01 16:46:26 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct stack
{
	int				top;
	int				size;
	int				c;
	int				*stk;
	int				*sort;
}					t_stack;

// Check args ....
void				check_args(char **av);
char				**args_check(int ac, char **av);
void				arg_check_int(char **av);
char				**args_combinor(char **av);
void				arg_check_int(char **av);
int					check_duplicate(int *str, int size);

// Utils ....
void				ft_free(char **str);
void				ft_error(char *str);
void				ft_free_stack(t_stack *stack_a, t_stack *stack_b);
int					ft_sqrt(int n);
int					find_pos(int n, t_stack *a);
int					find_level(int n, int *sorted, int len);
void				ft_sorted(t_stack *a);
int					ft_check_error(int ac, char **av, char *str);

// fill stack ....

int					*ft_cpystk(t_stack *a);
t_stack				fill_stack_b(t_stack a);
t_stack				fill_stack_a(char **argv);
int					ft_atol(char *str, char **args, t_stack *a);
// Sorting ....

void				ft_push_to_a(t_stack *a, t_stack *b);
void				ft_push_to_b(t_stack *a, t_stack *b);
void				ft_small_sort(t_stack *a, t_stack *b);
int					is_sorted(t_stack stack_a);

// Instrections ....

void				ft_swap(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ft_rotate(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				ft_push(t_stack *to, t_stack *from);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ft_rev_rotate(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

#endif
