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
        print_singleton(singleton);
    }
}

void sorting(t_base* singleton)
{

    pb_while_stack_a_size_greater_three(singleton);

//    print_singleton(singleton);
    if (get_stack_status(singleton->stack_a) == NOT_SORTED)
        perform_operations(singleton, new_element(SA));

    print_singleton(singleton);
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    insert_sort(singleton);
//    get_shortest_operation_list(singleton);
//    print_singleton(singleton);
}
