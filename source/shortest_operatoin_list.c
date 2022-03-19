#include "push_swap.h"

int min(int first, int second)
{
    if (first > second)
        return (second);
    else
        return (first);
}

int max(int first, int second)
{
    if (first > second)
        return (first);
    else
        return (second);
}

int get_index_smallest_value(int *arr, int size)
{
    int index_of_smallest;
    int i;

    index_of_smallest = 0;
    i = 1;
    while (i < size)
    {
        if (arr[index_of_smallest] > arr[i])
            index_of_smallest = i;
        i++;
    }
    return (index_of_smallest);
}

void init_info(t_stacks *info, t_base *singleton) {
    ft_bzero(info, sizeof(t_stacks));
    info->a_size = get_size(singleton->stack_a);
    info->b_size = get_size(singleton->stack_b);
}

int get_num_of_operations(t_rotations rotations)
{
    return (rotations.ra
            + rotations.rra
            + rotations.rb
            + rotations.rrb
            + rotations.rrr
            + rotations.rr);
}

void init_t_rotations(t_rotations *rotations, t_element *element, t_base *singleton, t_stacks info)
{
    ft_bzero(rotations, sizeof(t_rotations));
    if (!element)
        rotations->ra = INT_MAX;
    else
    {
        rotations->element = element;
        rotations->rb = get_position_in_the_stack(singleton->stack_b, element);
        rotations->rrb = info.b_size - rotations->rb;
        rotations->ra = get_position_to_insert(singleton->stack_b, element);
        rotations->rra = info.a_size - rotations->ra;
        rotations->rr = min(rotations->ra, rotations->rb);
        rotations->rrr = min(rotations->rra, rotations->rrb);
    }
}

void count_rotations_for_the_element(t_base *singleton, t_rotations rotations, t_stacks info)
{

}


t_element *get_shortest_operation_list(t_base *singleton)
{
    t_stacks info;
    t_rotations optimal;
    t_rotations current;
    t_element *current_element;

    init_info(&info, singleton);
    init_t_rotations(&optimal, NULL, singleton, info);
    current_element = singleton->stack_b;
    while (current_element)
    {
        init_t_rotations(&current, current_element, singleton, info);
        optimize_rotations(&current);
        if (get_num_of_operations(current) < get_num_of_operations(optimal))
            optimal = current;
        current_element = current_element->next;
    }
    return NULL;
}
