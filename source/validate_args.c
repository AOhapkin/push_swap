#include "push_swap.h"

void	check_spaces(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
		{
			return ;
		}
		str++;
	}
	exit(EXIT_SUCCESS);
}

void	validate_args(int argc, char **argv)
{
	char	**splited;
	
	if (argc == 2 && ft_strlen(argv[1] != 0))
	{
		check_spaces(argv[1]);
		splited = ft_split(argv[1], ' ');
	}
	return (0);
}