#include "push_swap.h"

void	init_singleton(t_base *singleton, int argc, char **argv)
{
	char	**strs;
	int		i;

	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i], SPACE);
		while (*strs)
		{
			long element = ft_atol(*strs);
			push_back(&(singleton->stack_a), element);
			strs++;
		}
		i++;
	}

}