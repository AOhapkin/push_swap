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
    push_front(&(singleton->operations), op);
    print_singleton(singleton);
}


int is_presorted_stack(t_base *singleton) {
    return (singleton
            && singleton->stack_a
            && !(singleton->stack_b)
            && is_sorted_stack(singleton->first, NULL)
            && is_sorted_stack(singleton->stack_a, singleton->last));
}

void bubbleish_sort(t_base *singleton) {
    while (is_presorted_stack(singleton))
    {

    }

}

void sort_stack_a_without_b(t_base* singleton)
{
    singleton->first = get_first_element(singleton->stack_a);
    singleton->last = get_last_element(singleton->stack_a);

    print_singleton(singleton);
    print_singleton(singleton);
    operation_handling(singleton, RA);
    operation_handling(singleton, SA);
//    operation_handling(singleton, RA);
    operation_handling(singleton, RA);
    if (is_presorted_stack(singleton))
        printf("PRESORTED !!!\n");
//    operation_handling(singleton, RRA);
    bubbleish_sort(singleton);
}