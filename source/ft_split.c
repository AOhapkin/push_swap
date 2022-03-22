#include "push_swap.h"

size_t	ft_count_strs(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			n++;
			while (*s && *s != c)
				s++;
		}
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	char const	*ptr;
	size_t		i;
	size_t		ptr_len;

	result = (char **)malloc(sizeof(char *) * (ft_count_strs(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		ptr = s;
		ptr_len = 0;
		while ((*s != c) && *s)
		{
			ptr_len++;
			s++;
		}
		if (*(s - 1) != c)
			result[i++] = ft_substr(ptr, 0, ptr_len);
	}
	result[i] = NULL;
	return (result);
}
