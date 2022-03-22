/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:43 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:45 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_base	singleton;

	validate_args(argc, argv);
	init_singleton(&singleton, argc, (char **) argv);
	if (is_valid_values(singleton.stack_a)
		&& get_stack_status(singleton.stack_a) != SORTED)
	{
		sorting(&singleton);
	}
	free_singleton(&singleton);
	return (0);
}
