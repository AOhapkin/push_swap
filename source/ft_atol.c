#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	long	negative;
	size_t	i;

	result = 0;
	negative = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * negative);
}