/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:46 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:48 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_base *singleton)
{
	rotate(&(singleton->stack_a));
}

void	rra(t_base *singleton)
{
	reverse_rotate(&(singleton->stack_a));
}

void	rb(t_base *singleton)
{
	rotate(&(singleton->stack_b));
}

void	rrb(t_base *singleton)
{
	reverse_rotate(&(singleton->stack_b));
}
