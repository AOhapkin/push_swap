#include "push_swap.h"

t_element	*get_last_element(t_element *head)
{
    while (head->next)
        head = head->next;
    return (head);
}

t_element	*pull_last_element(t_element **stack)
{
    t_element *tmp;
    t_element *last;

    last = NULL;
    if (stack && *stack)
    {
        tmp = *stack;
        while (tmp && tmp->next && tmp->next->next)
            tmp = tmp->next;
        last = tmp->next;
        tmp->next = NULL;
    }
    return (last);
}

t_element	*pull_first_element(t_element **stack)
{
    t_element *first;

    first = NULL;
    if (stack && *stack)
    {
        first = *stack;
        *stack = first->next;
        first->next = NULL;
    }
    return (first);
}

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

void	push_elements_back(t_element **stack, t_element *element)
{
    t_element	*last_elem;

    if (*stack)
    {
        last_elem = get_last_element(*stack);
        last_elem->next = element;
    }
    else
        *stack = element;
}

void	push_element_front(t_element **stack, t_element *element)
{
	if (stack && element)
	{
		element->next = *stack;
		*stack = element;
	}
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


void	rotate(t_element **stack)
{
    t_element	*old_head;

	if (stack && *stack && (*stack)->next)
	{
        old_head = pull_first_element(stack);
        push_elements_back(stack, old_head);
	}
}

void	reverse_rotate(t_element **stack)
{
    t_element	*old_back;

    if (stack && *stack && (*stack)->next)
    {
        old_back = pull_last_element(stack);
        push_element_front(stack, old_back);
    }
}

void	swap(t_element **stack)
{
	t_element *new_head;
	t_element *old_head;

	if (stack && *stack && (*stack)->next)
	{
		old_head = *stack;
		new_head = (*stack)->next;
        old_head->next = new_head->next;
        new_head->next = old_head;
        *stack = new_head;
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

int get_position_in_the_stack(t_element *stack, t_element *element)
{
    int position;

    position = 0;
    while (stack && element && stack != element)
    {
        position++;
        stack = stack->next;
    }
    return position;
}

int get_position_to_insert(t_element *stack, t_element *element)
{
    int position;

    position = 1;
    while (stack && stack->next)
    {
        if ((stack->value < stack->next->value
                && stack->value < element->value
                && stack->next->value > element->value)
            || (stack->value > stack->next->value
                && ((stack->value < element->value
                        && stack->next->value < element->value)
                    || (stack->value > element->value
                       && stack->next->value > element->value))))
            return (position);
        position++;
        stack = stack->next;
    }
    return (0);
}