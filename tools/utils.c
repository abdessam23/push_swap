/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:25:58 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/15 16:06:36 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error(char   *str)
{
    ft_putstr_fd(str, 1);
    exit (1);
}
void    ft_free(char    **str)
{
    int i;
    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str); 
}

int is_sorted(t_stack **stack)
{
    t_stack  *head;
    head = *stack;
    while(head && head->next)
    {
        if(head->data > head->next->data)
            return (0);
        head = head->next;
    }
    return (1);
}

void ft_free_stack(t_stack   **stack)
{
    t_stack  *head;
    t_stack  *tmp;

    head = *stack;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(stack);
}