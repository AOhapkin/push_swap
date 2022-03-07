#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"

# define SPACE						' '
# define VALID_CHARS_AFTER_SPACE	" -+1234567890"
# define VALID_CHARS_AFTER_DIGIT	" 1234567890"
# define ARITHMETICAL_CHARS			"-+"

# define INT_MAX         2147483647
# define INT_MIN         (-2147483647-1) // Не похоже на нормальную запись. Этот макрос будет высчитываться при каждом использовании и портить производительность.

# define SA         0
# define SB         1
# define SS         2
# define PA         3
# define PB         4
# define RA         5
# define RB         6
# define RR         7
# define RRA        8
# define RRB        9
# define RRR        10


typedef struct       s_ops
{
    char            operation;
    struct s_ops	*next;
}		            t_ops;

typedef struct       s_stack
{
	long             value;
	struct s_stack	*next;
}		            t_stack;

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
void	print_stack(t_stack *head);
void	push_stack(t_stack **src, t_stack **dst);

void	swap_stack(t_stack **stack);
void	rotate_stack(t_stack **head);
void	reverse_rotate_stack(t_stack **head);

void	init_singleton(t_base *singleton, int argc, char **argv);
long	ft_atol(const char *str);
int		is_valid_values(t_stack *head);
int     is_sorted_stack(t_stack *head);

#endif