#include "push_swap.h"

int	checkNextChar(char *str)
{
	if (*str == ' ')
	{
		if ((*str + 1) == ' ' || (*str + 1) == '-' || (*str + 1) == '+' || ft_isdigit(*str + 1))
			return (1);
	}
	else if (*str == '-' || *str == '+')
	{
		if (ft_isdigit(*str + 1))
			return (1);
	}
	else if (ft_isdigit(*str))
	{
		if ((*str + 1) == ' ' || ft_isdigit(*str + 1))
			return (1);
	}
	return (0);
}

void	validate_args(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) != 0)
	{
		while (*argv[1])
		{
			if (!checkNextChar(*argv[1]))
				exit(EXIT_FAILURE);
			argv[1]++;
		}
	}
}