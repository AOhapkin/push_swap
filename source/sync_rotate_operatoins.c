/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_rotate_operatoins.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:58 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:15:00 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_base *singleton)
{
	rotate(&(singleton->stack_b));
	rotate(&(singleton->stack_a));
}

void	rrr(t_base *singleton)
{
	reverse_rotate(&(singleton->stack_b));
	reverse_rotate(&(singleton->stack_a));
}
