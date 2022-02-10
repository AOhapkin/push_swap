#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"

# define SPACE						' '
# define VALID_CHARS_AFTER_SPACE	" -+1234567890"
# define VALID_CHARS_AFTER_DIGIT	" 1234567890"
# define ARITHMETICAL_CHARS			"-+"

typedef struct          s_stack
{
	long             value;
	struct s_stack	*next;
}		        t_stack;

typedef struct	s_base
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_base;

void	validate_args(int argc, const char **argv);
void	save_stack(t_stack *stack, int argc, const char **argv);
void	push_back(t_stack **head, long value);
void	push_front(t_stack **head, long value);
void	free_list(t_stack *head);
void	print_t_stack(t_stack *head);
void	push_t_element(t_stack **src, t_stack **dst);
void	rotate_t_element(t_stack **head);
void	rotate_reverse_t_element(t_stack **head);
void	swap_t_element(t_stack **head);
void	init_singleton(t_base *singleton, int argc, char **argv);
long	ft_atol(const char *str);
void	validate_values(t_stack *head);

#endif