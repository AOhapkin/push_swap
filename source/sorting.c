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

t_stack *get_last_element(t_stack *stack)
{
    t_stack *biggest;

    biggest = NULL;
    if (stack) {
        biggest = stack;
        stack = stack->next;
        while (stack)
        {
            if (biggest->value < stack->value)
                biggest = stack;
            stack = stack->next;
        }
    }
    return biggest;
}


void operation_handling(t_base *singleton, char op)
{
    call_function(singleton, op);
//    push_front(&(singleton->operations), op);
    push_back(&(singleton->operations), op);
//    print_singleton(singleton);
}

void sorting(t_base* singleton)
{
    print_singleton(singleton);
    print_singleton(singleton);
}
