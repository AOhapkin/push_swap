#include "push_swap.h"

t_element	*get_last_element(t_element *head)
{
	while (head->next)
		head = head->next;
	return (head);
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

int	get_position_in_the_stack(t_element *stack, t_element *element)
{
	int	position;

	position = 0;
	while (stack && element && stack != element)
	{
		position++;
		stack = stack->next;
	}
	return (position);
}

int	get_position_to_insert(t_element *stack, t_element *element)
{
	int	position;

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
