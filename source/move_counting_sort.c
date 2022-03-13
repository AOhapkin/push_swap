# include "push_swap.h"

void find_larges_presort_in_a(t_base *singleton, t_presort_sequence *presort) {
    t_stack *head;
    t_stack *prev;
    t_stack *tail;
    int     current_size;


    head = singleton->stack_a;
    while (head)
    {
        if (head->next)
            tail = head->next;
        else
            tail = singleton->stack_a;
        current_size = 1;
        prev = head;
        while (prev->value < tail->value)
        {
            current_size++;
            prev = tail;
            if (tail->next)
                tail = tail->next;
            else
                tail = singleton->stack_a;
        }
        if (presort->size < current_size)
        {
            presort->head_value = head->value;
            presort->tail_value = prev->value;
            presort->size = current_size;
        }
        head = head->next;
    }
}

void leave_largest_presorted_sequence_in_a(t_base *singleton)
{
    t_presort_sequence presort;

    ft_bzero(&presort, sizeof(presort));
    find_larges_presort_in_a(singleton, &presort);
    printf(" ");
}

void move_counting_sort(t_base *singleton)
{
    leave_largest_presorted_sequence_in_a(singleton);
}