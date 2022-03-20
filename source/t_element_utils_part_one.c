#include "push_swap.h"


t_element	*new_element(long value)
{
	t_element	*new;

	new = malloc(sizeof(new));
	if (new)
	{
		new->value = value;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int	get_size(t_element *head)
{
	int		len;

	len = 0;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	return (len);
}

void	free_list_of_elements(t_element *head)
{
	t_element	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int get_stack_status(t_element *head)
{
    t_element *first;
    t_element *last;

    last = head;
    first = head;
    if (!head)
        return (EMPTY);
    // finding last element in stack
    while (last
           && last->next
           && (last->value < last->next->value))
        last = last->next;
    // check for sort
    if (last->next == NULL)
        return (SORTED);
    else
        first = last->next;
    // check second part
    while (first
           && first->next
           && (first->value < first->next->value))
        first = first->next;
    // check that stack head bigger than last
    if (first->value < head->value && !first->next)
        return (PRESORTED);
    else
        return (NOT_SORTED);

}