#include "push_swap.h"

int	check_next_char(const char *str)
{
	char	current_char;
	char	next_char;

	current_char = *str;
	next_char = *(str + 1);
	if (current_char == SPACE
		&& ft_strchr(VALID_CHARS_AFTER_SPACE, next_char))
		return (1);
	else if (ft_strchr(ARITHMETICAL_CHARS, current_char)
		&& ft_isdigit(next_char))
		return (1);
	else if (ft_isdigit(current_char)
		&& ft_strchr(VALID_CHARS_AFTER_DIGIT, next_char))
		return (1);
	return (0);
}

void	check_argument_chars(const char *string)
{
	char	*arg;

	arg = (char *)string;
	while (*arg)
	{
		if (!check_next_char(arg))
			exit(EXIT_SUCCESS);
		arg++;
	}
}

void	validate_args(int argc, const char **argv)
{
	int	i;

	if (argc >= 2)
	{
		i = 1;
		while (argv[i])
		{
			if (ft_strlen(argv[i]) == 0)
				exit(EXIT_SUCCESS);
			check_argument_chars(argv[i]);
			i++;
		}
	}
	else
		exit(EXIT_SUCCESS);
}
