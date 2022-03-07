# include "push_swap.h"

void operation_sa(t_base *singleton, char operation)
{
    swap_stack(&(singleton->stack_a));
}

void operation_ra(t_base *singleton, char operation)
{
    rotate_stack(&(singleton->stack_a));
}

void operation_rra(t_base *singleton, char operation)
{
    reverse_rotate_stack(&(singleton->stack_a));
}

void call_function(t_base *singleton, char index)
{
    void (*implementations[NUM_OF_OPERATIONS])(t_base *singleton, int operation);
    implementations[SA] = *operation_sa;
    implementations[RA] = *operation_ra;
    implementations[RRA] = *operation_rra;
    if (IS_VALID_OPERATION(index) || index < 0)
    {
        implementations[index](singleton, index);
    }
}