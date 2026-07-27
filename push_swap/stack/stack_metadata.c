
#include "push_swap.h"

void	update_position(t_stack *stack)
{
    int position;

    position = 0;

    while (stack)
    {
        stack->position = position;
        position++;
        stack = stack->next;
    }
}
void	update_index(t_stack *stack)
{
    t_stack *current;
    t_stack *runner;
    int index;

    current = stack;
    while (current)
    {
        index = 0;
        runner = stack;
        while (runner)
        {
            if (runner->value < current->value)
                index++;
            runner = runner->next;
        }
        current->index = index;
        current = current->next;
    }
}
