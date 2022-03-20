# include "push_swap.h"

void free_strs(char **strs)
{
    int	i;
    if (strs != NULL)
    {
        i = 0;
        while (strs[i])
        {
            free(strs[i]);
            i++;
        }
        free(strs);
    }
}

void	init_singleton(t_base *singleton, int argc, char **argv)
{
    char	**strs;
    int		i;
    int		j;
    long	value;

    i = 1;
    ft_bzero(singleton, sizeof(t_base));
    while (i < argc)
    {
        strs = ft_split(argv[i], SPACE);
        j = 0;
        while (strs[j])
        {
            value = ft_atol(strs[j]);
            push_elements_back(&(singleton->stack_a), new_element(value));
            j++;
        }
        i++;
    }
    free_strs(strs);
}

int		free_singleton(t_base *singleton)
{
    free_list_of_elements(singleton->stack_a);
    free_list_of_elements(singleton->stack_b);
    free_list_of_elements(singleton->operations);
}