/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:12 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:13 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memalloc(size_t size)
{
	void	*dest;

	dest = malloc(size);
	if (!dest)
		return (NULL);
	return (ft_memset(dest, 0, size));
}
