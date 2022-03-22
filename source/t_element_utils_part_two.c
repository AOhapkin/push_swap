#include "push_swap.h"

t_element	*pull_last_element(t_element **stack)
{
	t_element	*tmp;
	t_element	*last;

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
	t_element	*first;

	first = NULL;
	if (stack && *stack)
	{
		first = *stack;
		*stack = first->next;
		first->next = NULL;
	}
	return (first);
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
	t_element	*new_head;
	t_element	*old_head;

	if (stack && *stack && (*stack)->next)
	{
		old_head = *stack;
		new_head = (*stack)->next;
		old_head->next = new_head->next;
		new_head->next = old_head;
		*stack = new_head;
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
