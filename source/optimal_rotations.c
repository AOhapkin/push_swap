/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:38 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:39 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_operations_to_rotations(t_rotations *rotations, int variation_index)
{
	void	(*optimisation_functions[NUM_OF_OPERATIONS])
		(t_rotations *not_optimized);

	optimisation_functions[RA_RB] = ra_rb_optimization;
	optimisation_functions[RRA_RRB] = rra_rrb_optimization;
	optimisation_functions[RA_RRB] = ra_rrb_optimization;
	optimisation_functions[RRA_RB] = rra_rb_optimization;
	optimisation_functions[variation_index](rotations);
}

void	optimize_rotations(t_rotations *rotations)
{
	int		r[NUM_VARIATIONS];

	r[RA_RB] = max(rotations->ra, rotations->rb);
	r[RRA_RRB] = max(rotations->rra, rotations->rrb);
	r[RA_RRB] = rotations->ra + rotations->rrb;
	r[RRA_RB] = rotations->rra + rotations->rb;
	set_operations_to_rotations(rotations,
		get_index_smallest_value(r, NUM_VARIATIONS));
}
