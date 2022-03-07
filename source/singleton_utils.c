# include "push_swap.h"

void print_operation(char index)
{
    char *operations_names[NUM_OF_OPERATIONS] = {
            "SA",
            "SB",
            "SS",
            "PA",
            "PB",
            "RA",
            "RB",
            "RR",
            "RRA",
            "RRB",
            "RRR"
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

void print_operations(t_stack *head) {
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
    printf("FIRST element: %li\n", singleton->first ? singleton->first->value : 0);
    printf("LAST  element: %li\n", singleton->last ? singleton->last->value : 0);
    printf("-----------------------------------------------\n");
    printf("stack A: ");
    print_stack(singleton->stack_a);
    printf("stack B: ");
    print_stack(singleton->stack_b);
    printf("-----------------------------------------------\n");
    printf("operations: ");
    print_operations(singleton->operations);
    printf("===============================================\n");
    printf("                        ||                     \n");
    printf("                        \\/                     \n");

}
