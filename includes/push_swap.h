#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"

# define SPACE						' '
# define VALID_CHARS_AFTER_SPACE	" -+1234567890"
# define VALID_CHARS_AFTER_DIGIT	" 1234567890"
# define ARITHMETICAL_CHARS			"-+"

typedef struct          s_element
{
	int             value;
	struct s_element	*next;
}		        t_element;

typedef struct	s_args
{
	char			*value;
	struct s_args	*next;
}				t_args;

typedef struct	s_base
{
	struct s_element	*value;
	struct s_args	*next;
}				t_base;

void	validate_args(int argc, const char **argv);
void	save_stack(t_element *stack, int argc, const char **argv);
void	push_back(t_element **head, int value);
void	push_front(t_element **head, int value);
void	free_list(t_element *head);
void	print_t_element_list(t_element *head);

#endif