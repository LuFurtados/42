
#include "push_swap.h"

void	stack_print(t_stack *stack)
{
    if(!stack)
        return ;
    while (stack)
    {
        ft_putnbr_fd(stack->value, 1);
        ft_putchar_fd('\n', 1);
        stack = stack->next;
    }
}
