#include "push_swap.h"

void    ft_push(t_stack *to, t_stack *from)
{
    if(from->size == 0)
        return ;
    to->top--;
    to->size++;
    to->stk[to->top] = from->stk[from->top];
    from->top++;
    from->size--;
}

void    pa(t_stack *a, t_stack *b)
{
    ft_push(a,b);
    ft_putstr_fd("pa\n", 1);
}
void    pb(t_stack *a, t_stack *b)
{
    ft_push(b,a);
    ft_putstr_fd("pb\n", 1);
}

void    ft_rev_rotate(t_stack *stack)
{
    int tmp;
    int i;
    if(stack->size < 2)
        return ;
    i = stack->top + stack->size - 1;
    while (i > stack->top)
    {
        tmp = stack->stk[i];
        stack->stk[i] =  stack->stk[i - 1];
        stack->stk[i - 1] = tmp;
        i--;
    }
}

void    rra(t_stack *a)
{
    ft_rev_rotate(a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack *b)
{
    ft_rev_rotate(b);
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack *a, t_stack *b)
{
    ft_rev_rotate(a);
    ft_rev_rotate(b);
    ft_putstr_fd("rrr\n", 1);
}