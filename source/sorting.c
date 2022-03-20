# include "push_swap.h"

void pb_while_stack_a_size_greater_three(t_base *singleton) {
    int iterations;
    t_element *pb_operations;

    iterations = get_size(singleton->stack_a) - 3;
    pb_operations = NULL;
    if (iterations > 0)
    {
        while (iterations > 0)
        {
            push_elements_back(&pb_operations, new_element(PB));
            iterations--;
        }
        perform_operations(singleton, pb_operations);
    }
}

void insert_sort(t_base *singleton)
{
    t_element *operations;

    while (singleton->stack_b)
    {
        operations = get_shortest_operation_list(singleton);
        perform_operations(singleton, operations);
//        print_singleton(singleton);
    }
}

void rotate_or_reverse_rotate_while_presort(t_base *singleton) {
    t_element tmp;
    t_element *operations;
    int ra;
    int rra;

    ft_bzero(&tmp, sizeof(t_element));
    tmp.value = INT_MAX;
    ra = get_position_to_insert(singleton->stack_a, &tmp);
    rra = get_size(singleton->stack_a) - ra;
    operations = NULL;
    if (ra < rra)
        while (ra--)
            push_elements_back(&operations, new_element(RA));
    else
        while (rra--)
            push_elements_back(&operations, new_element(RRA));
    perform_operations(singleton, operations);
}

void sorting(t_base* singleton)
{

    pb_while_stack_a_size_greater_three(singleton);

    if (get_stack_status(singleton->stack_a) == NOT_SORTED)
        perform_operations(singleton, new_element(SA));

    insert_sort(singleton);
    rotate_or_reverse_rotate_while_presort(singleton);
    print_operations_on_column(singleton);
//    print_singleton(singleton);

}
