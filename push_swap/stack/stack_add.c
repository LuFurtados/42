
#include "push_swap.h"

void stack_add_back(t_stack **stack, t_stack *new_node)
{
    t_stack *last;

    if (!stack || !new_node)
        return ;
    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    last = stack_last(*stack);
    last->next = new_node;
}
