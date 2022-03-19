# include "push_swap.h"

t_stack *get_first_element(t_stack *stack)
{
    t_stack *smallest;

    smallest = NULL;
    if (stack) {
        smallest = stack;
        stack = stack->next;
        while (stack)
        {
            if (smallest->value > stack->value)
                smallest = stack;
            stack = stack->next;
        }
    }
    return smallest;
}

void operation_handling(t_base *singleton, char op)
{
    call_function(singleton, op);
//    push_front(&(singleton->operations), op);
//    push_elements_back(&(singleton->operations), op);
//    print_singleton(singleton);
}

void pb_while_stack_a_size_greater_three(t_base *singleton) {
    int iterations;

    iterations = get_stack_size(singleton->stack_a) - 3;
//    while (iterations > 0)
//        operation_handling(singleton, );
}

void sorting(t_base* singleton)
{

    print_singleton(singleton);
    operation_handling(singleton, SA);
    print_singleton(singleton);
    operation_handling(singleton, RA);
    print_singleton(singleton);
    operation_handling(singleton, RRA);
    print_singleton(singleton);
    operation_handling(singleton, PB);
    operation_handling(singleton, PB);
    operation_handling(singleton, PB);
    operation_handling(singleton, PB);
    print_singleton(singleton);
    operation_handling(singleton, RB);
    print_singleton(singleton);
    operation_handling(singleton, RRB);
    print_singleton(singleton);
    operation_handling(singleton, RR);
    print_singleton(singleton);
    operation_handling(singleton, RRR);
    print_singleton(singleton);
    operation_handling(singleton, PA);
    print_singleton(singleton);
}
