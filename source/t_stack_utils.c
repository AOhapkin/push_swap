#include "push_swap.h"

t_stack	*get_last_element(t_stack *head)
{
    while (head->next)
        head = head->next;
    return (head);
}

t_stack	*pull_last_element(t_stack **stack)
{
    t_stack *tmp;
    t_stack *last;

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

t_stack	*pull_first_element(t_stack **stack)
{
    t_stack *first;

    first = NULL;
    if (stack && *stack)
    {
        first = *stack;
        *stack = first->next;
        first->next = NULL;
    }
    return (first);
}

t_stack	*new_stack_element(long value)
{
	t_stack	*new;

	new = malloc(sizeof(new));
	if (new)
	{
		new->value = value;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int	get_stack_size(t_stack *head)
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

void	push_elements_back(t_stack **stack, t_stack *element)
{
    t_stack	*last_elem;

    if (*stack)
    {
        last_elem = get_last_element(*stack);
        last_elem->next = element;
    }
    else
        *stack = element;
}

void	push_element_front(t_stack **stack, t_stack *element)
{
	if (stack && element)
	{
		element->next = *stack;
		*stack = element;
	}
}

void	free_stack(t_stack *head)
{
	t_stack	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	print_stack(t_stack *head)
{
	while (head)
	{
		printf("%ld ", head->value);
		head = head->next;
	}
	printf("\n");
}

void	rotate(t_stack **stack)
{
    t_stack	*old_head;

	if (stack && *stack && (*stack)->next)
	{
        old_head = pull_first_element(stack);
        push_elements_back(stack, old_head);
	}
}

void	reverse_rotate(t_stack **stack)
{
    t_stack	*old_back;

    if (stack && *stack && (*stack)->next)
    {
        old_back = pull_last_element(stack);
        push_element_front(stack, old_back);
    }
}

void	swap(t_stack **stack)
{
	t_stack *new_head;
	t_stack *old_head;

	if (stack && *stack && (*stack)->next)
	{
		old_head = *stack;
		new_head = (*stack)->next;
        old_head->next = new_head->next;
        new_head->next = old_head;
        *stack = new_head;
	}
}

int get_stack_status(t_stack *head)
{
    t_stack *first;
    t_stack *last;

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
    if (first->value < head->value)
        return (PRESORTED);
    else
        return (NOT_SORTED);

}
