/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_optimizators.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:50 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:51 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_optimization(t_rotations *rotations)
{
	if (rotations->ra < rotations->rb)
	{
		rotations->rb = rotations->rb - rotations->ra;
		rotations->ra = 0;
	}
	else
	{
		rotations->ra = rotations->ra - rotations->rb;
		rotations->rb = 0;
	}
	rotations->rra = 0;
	rotations->rrb = 0;
	rotations->rrr = 0;
}

void	rra_rrb_optimization(t_rotations *rotations)
{
	if (rotations->rrb > rotations->rra)
	{
		rotations->rrb = rotations->rrb - rotations->rra;
		rotations->rra = 0;
	}
	else
	{
		rotations->rra = rotations->rra - rotations->rrb;
		rotations->rrb = 0;
	}
	rotations->ra = 0;
	rotations->rb = 0;
	rotations->rr = 0;
}

void	ra_rrb_optimization(t_rotations *rotations)
{
	rotations->rb = 0;
	rotations->rra = 0;
	rotations->rrr = 0;
	rotations->rr = 0;
}

void	rra_rb_optimization(t_rotations *rotations)
{
	rotations->ra = 0;
	rotations->rrb = 0;
	rotations->rrr = 0;
	rotations->rr = 0;
}
