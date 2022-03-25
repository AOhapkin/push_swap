/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:34 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:36 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_operation_function(t_base *singleton, int operation_index)
{
	void	(*implementations[NUM_OF_OPERATIONS])(t_base *singleton);

	implementations[SA] = sa;
	implementations[PB] = pb;
	implementations[RA] = ra;
	implementations[RRA] = rra;
	implementations[PA] = pa;
	implementations[RB] = rb;
	implementations[RRB] = rrb;
	implementations[RR] = rr;
	implementations[RRR] = rrr;
	if (is_valid_operation(operation_index))
		implementations[operation_index](singleton);
}

void	perform_operations(t_base *singleton, t_element *operations_head)
{
	t_element	*tmp_operation;

	tmp_operation = operations_head;
	push_elements_back(&(singleton->operations), operations_head);
	while (tmp_operation)
	{
		call_operation_function(singleton, tmp_operation->value);
		tmp_operation = tmp_operation->next;
	}
}

void	write_operation(long operation_index)
{
	char	*operations_names[NUM_OF_OPERATIONS];

	operations_names[SA] = "sa";
	operations_names[PB] = "pb";
	operations_names[RA] = "ra";
	operations_names[RRA] = "rra";
	operations_names[PA] = "pa";
	operations_names[RB] = "rb";
	operations_names[RRB] = "rrb";
	operations_names[RR] = "rr";
	operations_names[RRR] = "rrr";
	if (is_valid_operation(operation_index))
		write(1, operations_names[operation_index],
			ft_strlen(operations_names[operation_index]));
	else
		write(1, "??", 2);
}

void	print_operations_on_column(t_base *singleton)
{
	t_element	*tmp;

	tmp = singleton->operations;
	while (tmp)
	{
		write_operation(tmp->value);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}
