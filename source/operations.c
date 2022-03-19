# include "push_swap.h"

void sa(t_base *singleton)
{
    swap(&(singleton->stack_a));
}

void pb(t_base *singleton)
{
    push_element_front(
            &(singleton->stack_b),
            pull_first_element(&(singleton->stack_a))
    );
}

void ra(t_base *singleton)
{
    rotate(&(singleton->stack_a));
}

void rra(t_base *singleton)
{
    reverse_rotate(&(singleton->stack_a));
}

void pa(t_base *singleton) {
    push_element_front(
            &(singleton->stack_a),
            pull_first_element(&(singleton->stack_b))
    );
}

void rb(t_base *singleton)
{
    rotate(&(singleton->stack_b));
}

void rrb(t_base *singleton)
{
    reverse_rotate(&(singleton->stack_b));
}

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

void call_operation_function(t_base *singleton, char operation_index)
{
    void (*implementations[NUM_OF_OPERATIONS])(t_base *singleton);
    implementations[SA] = sa;
    implementations[PB] = pb;
    implementations[RA] = ra;
    implementations[RRA] = rra;
    implementations[PA] = pa;
    implementations[RB] = rb;
    implementations[RRB] = rrb;
    implementations[RR] = rr;
    implementations[RRR] = rrr;
    if (IS_VALID_OPERATION(operation_index) || operation_index < 0)
        implementations[operation_index](singleton);
}

void perform_operations(t_base *singleton, t_element *head)
{
    t_element *tmp;

    tmp = head;
    push_elements_back(&(singleton->operations), head);
    while (tmp)
    {
        call_operation_function(singleton, tmp->value);
        tmp = tmp->next;
    }
}