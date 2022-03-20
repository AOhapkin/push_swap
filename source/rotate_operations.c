#include "push_swap.h"

void ra(t_base *singleton)
{
    rotate(&(singleton->stack_a));
}

void rra(t_base *singleton)
{
    reverse_rotate(&(singleton->stack_a));
}

void rb(t_base *singleton)
{
    rotate(&(singleton->stack_b));
}

void rrb(t_base *singleton)
{
    reverse_rotate(&(singleton->stack_b));
}