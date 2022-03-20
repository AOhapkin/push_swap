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

# define RA_RB       0
# define RRA_RRB     1
# define RA_RRB      2
# define RRA_RB      3
# define NUM_VARIATIONS 4

typedef struct       s_element
{
    long             value;
    struct s_element	*next;
}		            t_element;


typedef struct       s_rotations
{
    struct s_element *element;
    int             ra;
    int             rb;
    int             rra;
    int             rrb;
    int             rrr;
    int             rr;
}                    t_rotations;

typedef struct       s_stacks
{
    int             a_size;
    int             b_size;
}                    t_stacks;

typedef struct	s_base
{
	t_element	*stack_a;
	t_element	*stack_b;
    t_element	*operations;
}				t_base;

void	validate_args(int argc, const char **argv);

int min(int first, int second);
int max(int first, int second);
int get_index_smallest_value(int *arr, int size);

void	init_singleton(t_base *singleton, int argc, char **argv);
long	ft_atol(const char *str);
int		is_valid_values(t_element *head);
void    free_singleton(t_base *singleton);

void    perform_operations(t_base *singleton, t_element *head);
void    sorting(t_base *singleton);

t_element *get_shortest_operation_list(t_base *singleton);
void    optimize_rotations(t_rotations *rotations);
void    ra_rb_optimization(t_rotations* rotations);
void    rra_rrb_optimization(t_rotations* rotations);
void    ra_rrb_optimization(t_rotations* rotations);
void    rra_rb_optimization(t_rotations* rotations);

void ra(t_base *singleton);
void rra(t_base *singleton);
void rb(t_base *singleton);
void rrb(t_base *singleton);

void sa(t_base *singleton);
void pb(t_base *singleton);
void pa(t_base *singleton);

void rr(t_base *singleton);
void rrr(t_base *singleton);

int min(int first, int second);
int max(int first, int second);
int get_index_smallest_value(int *arr, int size);

t_element	*new_element(long value);
void	push_elements_back(t_element **stack, t_element *element);
void	push_element_front(t_element **stack, t_element *element);
t_element *pull_first_element(t_element **stack);
t_element *pull_last_element(t_element **stack);
int     get_stack_status(t_element *head);
int     get_size(t_element *head);
int     get_position_in_the_stack(t_element *stack, t_element *element);
int     get_position_to_insert(t_element *stack, t_element *element);
void    free_list_of_elements(t_element *head);

void	swap(t_element **stack);
void	rotate(t_element **stack);
void	reverse_rotate(t_element **stack);

void print_operations_on_column(t_base *singleton);


#endif