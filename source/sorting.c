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

void perform_operations(t_base *singleton, t_op *head)
{
    t_op *tmp;

    tmp = head;
    push_operations_back(&(singleton->operations), head);
    while (tmp)
    {
        call_operation_function(singleton, tmp->operation_index);
        tmp = tmp->next;
    }
}

void pb_while_stack_a_size_greater_three(t_base *singleton) {
    int iterations;
    t_op *pb_operations;

    iterations = get_stack_size(singleton->stack_a) - 3;
    pb_operations = NULL;
    if (iterations > 0)
    {
        while (iterations > 0)
        {
            push_operations_back(&pb_operations, new_operation(PB));
            iterations--;
        }
        perform_operations(singleton, pb_operations);
    }
}

void sorting(t_base* singleton)
{
    print_singleton(singleton);
    pb_while_stack_a_size_greater_three(singleton);
    print_singleton(singleton);
}
