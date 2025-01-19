
#include "push_swap.h"

int	*ft_cpystk(t_stack a)
{
	int	*sorted_ar;

	sorted_ar = malloc*(sizeof(int) *(a->size));
	if (!sorted_ar)
	{
		free(sorted_ar);
		ft_error("Error\n");
	}
	ft_memcpy(sorted_ar,a->stk, sizeof(int)* a->stk);
	return (sorted_ar);
}
int	*ft_sorted(t_stack a)
{
	int	*sorted_ar;
	int	i;
	int	tmp;

	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if(sorted_ar[j] > sorted_ar[j + 1])
			{
			tmp = sorted_ar[j];
			sorted_ar[j] = sorted_ar[j + 1];
			sorted_ar[j + 1] = tmp;
			}
			j++;
		}
		
		i++;
	}
	return (sorted_ar);
}

static int	count_args(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	fill_array(t_stack a, char **args)
{
	int	i;
    
    i = 0;
	a->stk = malloc(sizeof(int) * (count_args(args)));
	if (!a->stk)
	{
		
		while (args[i])
			free(args[i++]);
		free(args);
		error("Error\n");
	}
	i = 0;
	while (args[i])
	{
		a->stk[i] = ft_atoi(args[i]);
		free(args[i]);
		i++;
	}
	a->top = 0;
	a->size = i;
	a->c = i;
	free(args);
	ft_sorted(a);
}
t_stack  fill_stack_a(int argc,char  **argv)
{
    int i;
    char **tab;
    t_stack a;

    i = 0;
    if (argc == 2)
        tab = ft_split(argv[1], ' ');
    else
    {
        i = 1;
        tab = argv;
    }
    
    fill_array(a);
    if (argc == 2)
        ft_free(tab);
	return (a)
}