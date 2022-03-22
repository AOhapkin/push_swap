/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:14:24 by gmyriah           #+#    #+#             */
/*   Updated: 2022/03/22 17:14:25 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
	{
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
