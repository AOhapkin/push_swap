/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:41 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:42 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_base *singleton)
{
	swap(&(singleton->stack_a));
}

void	pb(t_base *singleton)
{
	push_element_front(
		&(singleton->stack_b),
		pull_first_element(&(singleton->stack_a)));
}

void	pa(t_base *singleton)
{
	push_element_front(
		&(singleton->stack_a),
		pull_first_element(&(singleton->stack_b)));
}
