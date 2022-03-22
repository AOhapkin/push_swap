#include "push_swap.h"

void	init_info(t_stacks *info, t_base *singleton)
{
	ft_bzero(info, sizeof(t_stacks));
	info->a_size = get_size(singleton->stack_a);
	info->b_size = get_size(singleton->stack_b);
}

int	get_num_of_operations(t_rotations rotations)
{
	return (rotations.ra
		+ rotations.rra
		+ rotations.rb
		+ rotations.rrb
		+ rotations.rrr
		+ rotations.rr);
}

void	init_t_rotations(t_rotations *rotations, t_element *element,
	t_base *singleton, t_stacks info)
{
	ft_bzero(rotations, sizeof(t_rotations));
	if (!element)
		rotations->ra = INT_MAX;
	else
	{
		rotations->element = element;
		rotations->rb = get_position_in_the_stack(singleton->stack_b, element);
		rotations->rrb = info.b_size - rotations->rb;
		rotations->ra = get_position_to_insert(singleton->stack_a, element);
		rotations->rra = info.a_size - rotations->ra;
		rotations->rr = min(rotations->ra, rotations->rb);
		rotations->rrr = min(rotations->rra, rotations->rrb);
	}
}

t_element	*generate_operations_list(t_rotations rotations)
{
	t_element	*result;

	result = NULL;
	while (0 < rotations.rr--)
		push_elements_back(&result, new_element(RR));
	while (0 < rotations.rrr--)
		push_elements_back(&result, new_element(RRR));
	while (0 < rotations.rb--)
		push_elements_back(&result, new_element(RB));
	while (0 < rotations.ra--)
		push_elements_back(&result, new_element(RA));
	while (0 < rotations.rrb--)
		push_elements_back(&result, new_element(RRB));
	while (0 < rotations.rra--)
		push_elements_back(&result, new_element(RRA));
	push_elements_back(&result, new_element(PA));
	return (result);
}

t_element	*get_shortest_operation_list(t_base *singleton)
{
	t_stacks	info;
	t_rotations	optimal;
	t_rotations	current;
	t_element	*current_element;

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
	return (generate_operations_list(optimal));
}
