#include "push_swap.h"

int main(int argc, const char **argv)
{
	t_base	singleton;

	validate_args(argc, argv);
	ft_bzero(&singleton, sizeof(t_base));
	init_singleton(&singleton, argc, (char **) argv);
//    print_stack(singleton.stack_a);
	if (is_valid_values(singleton.stack_a))
    {
        print_stack(singleton.stack_a);
//        swap_stack(&(singleton.stack_a));
//        rotate_stack(&(singleton.stack_a));
        reverse_rotate_stack(&(singleton.stack_a));
        print_stack(singleton.stack_a);
//        if (!is_sorted_stack(singleton.stack_a))
//        {
//        }

//        printf("sorted");
    }


//    free_list(singleton.stack_a);
	return (0);
}

//int main()
//{
//	t_element *head;
//	t_element *head2;
//
//	head = NULL;
//	push_back(&head, 1);
//	push_back(&head, 2);
//	push_back(&head, 3);
//	push_back(&head, 4);
//	push_back(&head, 5);
//	print_t_element_list(head);
//
//	head2 = NULL;
//	push_back(&head2, 6);
//	push_back(&head2, 7);
//	push_back(&head2, 8);
//	push_back(&head2, 9);
//	push_back(&head2, 10);
//	print_t_element_list(head2);
//
//	swap_stack(&head);
//	print_t_element_list(head);
//	swap_stack(&head2);
//	print_t_element_list(head2);
//	return (0);
//}