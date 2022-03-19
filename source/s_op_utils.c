#include "push_swap.h"

t_op	*new_operation(char operation_index)
{
    t_op *new;

    new = ft_memalloc(sizeof(t_op));
    new->operation_index = operation_index;
    return (new);
}

t_stack	*get_last_operation(t_stack *head)
{
    while (head->next)
        head = head->next;
    return (head);
}

void    push_operations_back(t_op **dst, t_op *operations)
{
    t_op	*last_operation;

    if (*dst)
    {
        last_operation = get_last_operation(*dst);
        last_operation->next = operations;
    }
    else
        *dst = operations;
}

void    free_operations(t_op *head)
{
    t_op	*temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}