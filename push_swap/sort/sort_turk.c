
#include "push_swap.h"

static void evacuate_to_b(t_stack **stack_a, t_stack **stack_b)
{
int size;
int pushed;

size = stack_size(*stack_a);
pushed = 0;
while (size > 3 && pushed < size / 2)
{
// Optional: Add logic here to push cheaper nodes first based on index
pb(stack_a, stack_b, 1);
pushed++;
}
while (size - pushed > 3)
{
pb(stack_a, stack_b, 1);
pushed++;
}
}

void turk_sort(t_stack **stack_a, t_stack **stack_b)
{
t_stack *cheapest_node;

evacuate_to_b(stack_a, stack_b);
sort_three(stack_a);
while (*stack_b)
{
update_position(*stack_a);
update_position(*stack_b);
update_target_position(*stack_a, *stack_b);
update_cost(*stack_a, *stack_b);
cheapest_node = get_cheapest_node(*stack_b);
execute_move(stack_a, stack_b, cheapest_node);
pa(stack_a, stack_b, 1);
}
update_position(*stack_a);
// Final rotation logic goes here to put min_value at the top
//Para integrar a nova lógica de ordenação, criei a pasta sort/ com quatro arquivos: sort_stacks.c (um roteador automático chamado na main que mede a pilha e escolhe a estratégia), sort_tiny.c (resolve 2 ou 3 números com lógica hardcoded de até 2 movimentos), sort_five.c (manda os dois menores para a Pilha B, ordena a A e os devolve) e sort_turk.c (o motor pesado que esvazia a Pilha A e roda o loop devolvendo sempre o cheapest_node). Para plugar isso tudo no nosso pipeline, basta adicionar os cinco protótipos no push_swap.h, criar uma variável SORT no Makefile apontando para esses arquivos (e incluí-la no SRC), e por fim, disparar sort_stacks(&stack_a, &stack_b); direto na nossa main.c logo após a validação verificar que a lista não está ordenada.
}
