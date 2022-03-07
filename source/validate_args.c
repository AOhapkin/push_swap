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

void checkArgumentChars(const char *string)
{
	char *arg;

	arg = (char *)string;
	while (*arg)
	{
		if (!checkNextChar(arg))
			exit(EXIT_SUCCESS);
		arg++;
	}
}

void validate_args(int argc, const char **argv)
{
	int i;

	if (argc >= 2)
	{
		i = 1;
		while (argv[i])
		{
			if (ft_strlen(argv[i]) == 0)
				exit(EXIT_SUCCESS);
			checkArgumentChars(argv[i]);
			i++;
		}

	}
	else
		exit(EXIT_SUCCESS);
}
