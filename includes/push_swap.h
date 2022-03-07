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

# define NUM_OF_OPERATIONS         11
# define IS_VALID_OPERATION(X) (X < NUM_OF_OPERATIONS)
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



typedef struct       s_stack
{
	long             value;
	struct s_stack	*next;
}		            t_stack;

typedef struct	s_base
{
	t_stack	*stack_a;
	t_stack	*stack_b;
    t_stack *first;
    t_stack *last;
	t_stack	*operations;
}				t_base;

void	validate_args(int argc, const char **argv);
void	save_stack(t_stack *stack, int argc, const char **argv);
void	push_back(t_stack **stack, long value);
void	push_front(t_stack **stack, long value);
void	free_list(t_stack *head);
void	print_stack(t_stack *head);
void	push_stack(t_stack **src, t_stack **dst);

void	swap_stack(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);

void	init_singleton(t_base *singleton, int argc, char **argv);
long	ft_atol(const char *str);
int		is_valid_values(t_stack *head);
int     is_sorted_stack(t_stack *head);
void    print_singleton(t_base *singleton);
void sort_stack_a_without_b(t_base* singleton);
void call_function(t_base *singleton, char index);

#endif