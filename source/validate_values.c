#include "push_swap.h"

int isInteger(long value)
{
	if (value >= INT_MIN && value <= INT_MAX)
		return (1);
	return (0);
}

int	inspect_numbers(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (!isInteger(tmp->value))
			return (0);
		tmp = tmp->next;
	}
    return (1);
}

int count_dublicates(t_stack *head)
{
    int i;
    t_stack *tmp;
    long    value;

    i = 0;
    tmp = head;
    value = tmp->value;
    while (tmp)
    {
        if (value == tmp->value)
            i++;
        tmp = tmp->next;
    }
    return (i);
}

int check_for_dublicates(t_stack *head)
{
    t_stack *tmp;

    tmp = head;
    while (tmp)
    {
        if (count_dublicates(head) > 1)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int	is_valid_values(t_stack *head)
{
	if (!inspect_numbers(head))
		return (0);
	if (!check_for_dublicates(head))
		return (0);
	return (1);
}
