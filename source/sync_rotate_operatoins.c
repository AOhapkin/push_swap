#include "push_swap.h"

void rr(t_base *singleton)
{
    rotate(&(singleton->stack_b));
    rotate(&(singleton->stack_a));
}

void rrr(t_base *singleton)
{
    reverse_rotate(&(singleton->stack_b));
    reverse_rotate(&(singleton->stack_a));
}