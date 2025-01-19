/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:23:05 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/16 18:55:25 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    size = ft_lstsize(*stack_a);
    if (size <= 5)
        ft_small_sort(stack_a, stack_b);
    else
        radix_sort(stack_a , stack_b);
}


int main(int argc, char **argv)
{
    t_stack  **stack_a;
    t_stack  **stack_b;
    
    if (argc >= 2)
    {
        stack_a =(t_stack**)malloc(sizeof(t_stack));
        stack_b =(t_stack**)malloc(sizeof(t_stack));
        *stack_a = NULL;
        *stack_b = NULL;
        ft_check_arg(argc, argv);
        fill_stack(argc, argv, stack_a);
        if(is_sorted(stack_a))
        {
            ft_free_stack(stack_a);
            ft_free_stack(stack_b);
             return 0;
        }
        ft_sort(stack_a, stack_b);
        ft_free_stack(stack_a);
        ft_free_stack(stack_b);
        return 0;
    }
    return 1;
}
