/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:15:22 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:15:24 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(long value)
{
	if (value >= INT_MIN && value <= INT_MAX)
		return (1);
	return (0);
}

int	inspect_numbers(t_element *head)
{
	t_element	*tmp;

	tmp = head;
	while (tmp)
	{
		if (!is_integer(tmp->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	count_dublicates(t_element *head)
{
	int			i;
	t_element	*tmp;
	long		value;

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

int	check_for_dublicates(t_element *head)
{
	t_element	*tmp;

	tmp = head;
	while (tmp)
	{
		if (count_dublicates(head) > 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_valid_values(t_element *head)
{
	if (!inspect_numbers(head))
		return (0);
	if (!check_for_dublicates(head))
		return (0);
	return (1);
}
