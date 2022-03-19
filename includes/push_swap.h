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
# define IS_VALID_OPERATION(x) (x >= 0 && x <  NUM_OF_OPERATIONS)
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

# define SORTED     1
# define PRESORTED  2
# define NOT_SORTED 0
# define EMPTY      -1


typedef struct       s_op
{
    char            operation_index;
    struct s_op	    *next;
}                   t_op;

typedef struct       s_stack
{
	long             value;
	struct s_stack	*next;
}		            t_stack;

typedef struct	s_base
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_op	*operations;
}				t_base;

void	validate_args(int argc, const char **argv);
void	print_stack(t_stack *head);
void	push_stack(t_stack **src, t_stack **dst);



void	init_singleton(t_base *singleton, int argc, char **argv);
long	ft_atol(const char *str);
int		is_valid_values(t_stack *head);
void    print_singleton(t_base *singleton);


void    call_operation_function(t_base *singleton, char operation_index);
void    sorting(t_base *singleton);

t_stack	*new_stack_element(long value);
void	push_elements_back(t_stack **stack, t_stack *element);
void	push_element_front(t_stack **stack, t_stack *element);
t_stack *pull_first_element(t_stack **stack);
t_stack *pull_last_element(t_stack **stack);
int     get_stack_status(t_stack *head);
int     get_stack_size(t_stack *head);
void    free_stack(t_stack *head);

void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

t_op	*new_operation(char operation_index);
void    push_operations_back(t_op **dst, t_op *operations);
void    free_operations(t_op *head);

#endif