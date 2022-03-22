/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:02 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:04 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = 0;
		i++;
	}
}