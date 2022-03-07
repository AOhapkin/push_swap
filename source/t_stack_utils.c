#include "push_swap.h"

int is_stack_operable(t_stack **stack) {
    return (stack && *stack && (*stack)->next);
}

t_stack	*get_last_stack_element(t_stack *head)
{
	if (head)
	{
		while (head->next != 0)
			head = head->next;
		return (head);
	}
	return (0);
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

int	stack_length(t_stack *head)
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

void	push_back(t_stack **stack, long value)
{
	t_stack	*last_elem;

	if (*stack)
	{
		last_elem = get_last_stack_element(*stack);
		last_elem->next = new_stack_element(value);
	}
	else
	{
		*stack = new_stack_element(value);
	}
}

void	push_front(t_stack **stack, long value)
{
	t_stack	*new_elem;

	new_elem = new_stack_element(value);
	if (stack && new_elem)
	{
		new_elem->next = *stack;
		*stack = new_elem;
	}
}

void	free_list(t_stack *head)
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

void	push_stack(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	if (src)
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dst;
		*dst = temp;
	}
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*temp;

	if (is_stack_operable(stack))
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		push_back(stack, temp->value);
		free(temp);
	}
}

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prelast;

	if (stack && stack_length(*stack) >= 2)
	{
		last = *stack;
		prelast = *stack;
		while (last->next)
		{
			prelast = last;
			last = last->next;
		}
		prelast->next = NULL;
		push_front(stack, last->value);
	}
}

void	swap_stack(t_stack **stack)
{
	t_stack *new_head;
	t_stack *old_head;

	if (is_stack_operable(stack))
	{
		old_head = *stack;
		new_head = (*stack)->next;
        old_head->next = new_head->next;
        new_head->next = old_head;
        *stack = new_head;
	}
}

int is_sorted_stack(t_stack *head)
{
    t_stack *tmp;

    if (head)
    {
        tmp = head;
        while (tmp->next)
        {
            if (tmp->value > tmp->next->value)
                return (0);
            tmp = tmp->next;
        }
    }
    return (1);
}
