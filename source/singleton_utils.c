# include "push_swap.h"

void print_operation(char index)
{
    char *operations_names[NUM_OF_OPERATIONS] = {
            "sa",
            "sb",
            "ss",
            "pa",
            "pb",
            "ra",
            "rb",
            "rr",
            "rra",
            "rrb",
            "rrr"
    };

    if (IS_VALID_OPERATION(index))
    {
        printf("%s ", operations_names[index]);
    }
    else
    {
        printf("?? ");
    }
};

void print_operations_in_line(t_stack *head) {
    while (head)
    {
        print_operation(head->value);
        head = head->next;
    }
    printf("\n");
}

void print_singleton(t_base *singleton)
{
    printf("================== SINGLETON ==================\n");
    printf("stack A: ");
    print_stack(singleton->stack_a);
    int status = get_stack_status(singleton->stack_a);
    printf("status: %s\n", status == SORTED ? "SORTED" : status == PRESORTED ? "PRESORTED" : status == NOT_SORTED ? "NOT_SORTED" : "EMPTY");
    printf("size: %i\n", get_stack_size(singleton->stack_a));
    printf("- - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("stack B: ");
    print_stack(singleton->stack_b);
    status = get_stack_status(singleton->stack_b);
    printf("status: %s\n", status == SORTED ? "SORTED" : status == PRESORTED ? "PRESORTED" : status == NOT_SORTED ? "NOT_SORTED" : "EMPTY");
    printf("size: %i\n", get_stack_size(singleton->stack_b));
    printf("-----------------------------------------------\n");
    printf("operations: ");
    print_operations_in_line(singleton->operations);
    printf("===============================================\n");
    printf("                        ||                     \n");
    printf("                        \\/                     \n");

}

void print_one_operation(int index)
{
    char *operations_names[NUM_OF_OPERATIONS] = {
            "sa",
            "sb",
            "ss",
            "pa",
            "pb",
            "ra",
            "rb",
            "rr",
            "rra",
            "rrb",
            "rrr"
    };

    if (IS_VALID_OPERATION(index))
        write(1, operations_names[index], ft_strlen(operations_names[index]));
    else
        write(1, "??", 2);
    write(1, "\n",1);
}

void print_operations_in_a_column(t_stack *head)
{
    t_stack *curr;

    curr = head;
    while (curr)
    {
        print_one_operation(curr->value);
        curr = curr->next;
    }
}