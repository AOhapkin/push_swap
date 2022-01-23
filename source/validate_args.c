#include "push_swap.h"

int checkNextChar(const char *str)
{
	char currentChar;
	char nextChar;

	currentChar = *str;
	nextChar = *(str + 1);
	if (currentChar == SPACE
		&& ft_strchr(VALID_CHARS_AFTER_SPACE, nextChar))
		return (1);
	else if (ft_strchr(ARITHMETICAL_CHARS, currentChar)
			 && ft_isdigit(nextChar))
		return (1);
	else if (ft_isdigit(currentChar)
			 && ft_strchr(VALID_CHARS_AFTER_DIGIT, nextChar))
		return (1);
	return (0);
}

void validate_args(int argc, char **argv)
{
	char	*arg;

	arg = argv[1];
	if (argc == 2 && ft_strlen(arg) != 0)
	{
		while (*arg)
		{
			if (!checkNextChar(arg))
				exit(EXIT_FAILURE);
			arg++;
		}
	}
}