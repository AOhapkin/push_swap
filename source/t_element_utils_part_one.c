/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_element_utils_part_one.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:15:07 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:15:09 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	len;

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

int	get_stack_status(t_element *head)
{
	t_element	*first;
	t_element	*last;

	last = head;
	first = head;
	if (!head)
		return (EMPTY);
	while (last
		&& last->next
		&& (last->value < last->next->value))
		last = last->next;
	if (last->next == NULL)
		return (SORTED);
	else
		first = last->next;
	while (first
		&& first->next
		&& (first->value < first->next->value))
		first = first->next;
	if (first->value < head->value && !first->next)
		return (PRESORTED);
	else
		return (NOT_SORTED);
}
