#include "push_swap.h"
static void mid_top_to_a(t_stack *a, t_stack *b, int  num,int level)
{
    level--;
    while (b->stk[top] != num)
        rb(b, 1);
    pa(a, b);
}

static void mid_bot_to_a(t_stack *a, t_stack *b, int  num,int level)
{
    level--;
    while (b->stk[top] != num)
        rrb(b, 1);
    pa(a, b);
}

void    ft_push_to_a(t_stack *a, t_stack *b)
{
    int top;
    int len;
    int level;

    level = b->c;
    while (b->top > 0)
    {
        top = b->top;
        len = b->top + b->size - 1;
        while (top <= len)
        {
           if(find_level(b->stk[top], a->sort, a->c) == level)
            {
                mid_top_to_a(a, b, b->stack[top], &level);
                break;
            }
            if(find_level(b->stk[len], a->sort, a->c) == level)
            {
                mid_bot_to_a(a, b, b->stack[len], &level);
                break;
            }
            top++;
            len--;
        }
    }
}