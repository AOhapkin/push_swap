#include "push_swap.h"

void free_strs(char **strs)
{
	int	i;
	if (strs != NULL)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

void	init_singleton(t_base *singleton, int argc, char **argv)
{
	char	**strs;
	int		i;
	int		j;
	long	element;

	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i], SPACE);
		j = 0;
		while (strs[j])
		{
			element = ft_atol(strs[j]);
			push_back(&(singleton->stack_a), element);
			j++;
		}
		i++;
	}
	free_strs(strs);
}
