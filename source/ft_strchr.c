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
