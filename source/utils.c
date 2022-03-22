/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:15:16 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:15:17 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int first, int second)
{
	if (first > second)
		return (second);
	else
		return (first);
}

int	max(int first, int second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

int	get_index_smallest_value(int *arr, int size)
{
	int	index_of_smallest;
	int	i;

	index_of_smallest = 0;
	i = 1;
	while (i < size)
	{
		if (arr[index_of_smallest] > arr[i])
			index_of_smallest = i;
		i++;
	}
	return (index_of_smallest);
}
