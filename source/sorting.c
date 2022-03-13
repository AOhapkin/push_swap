# include "push_swap.h"

void operation_handling(t_base *singleton, char op)
{
    call_function(singleton, op);
//    push_front(&(singleton->operations), op);
    push_back(&(singleton->operations), op);
//    print_singleton(singleton);
}


int is_presorted_stack(t_base *singleton) {
    return (singleton
            && singleton->stack_a
            && !(singleton->stack_b)
            && is_sorted_stack(singleton->first, NULL)
            && is_sorted_stack(singleton->stack_a, singleton->last)
            && (singleton->last == NULL || singleton->last->next == singleton->first));
}

void bubbleish_sort(t_base *singleton) {
    t_stack **stack;

    stack = &(singleton->stack_a);
    while (!is_presorted_stack(singleton))
    {
        while(((*stack)->value < (*stack)->next->value || (*stack) == singleton->last)
            && !is_presorted_stack(singleton))
            operation_handling(singleton, RA);
        while((*stack)->value > (*stack)->next->value
            && (*stack) != singleton->last
            && !is_presorted_stack(singleton))
            operation_handling(singleton, SA);
    }
    while (!is_sorted_stack(singleton->stack_a, NULL))
        operation_handling(singleton, RA);
}

void sort_stack_a_without_b(t_base* singleton)
{
    bubbleish_sort(singleton);
    print_operations_in_a_column(singleton->operations);
}
