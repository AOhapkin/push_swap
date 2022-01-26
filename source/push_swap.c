#include "push_swap.h"

//int main(int argc, const char **argv)
//{
//	t_element	*stackA;
//
//	stackA = NULL;
//	validate_args(argc, argv);
//	save_stack(stackA, argc, argv);
//	return (0);
//}

int main()
{
	t_element *head;
	t_element *head2;

	head = NULL;
	push_back(&head, 1);
	push_back(&head, 2);
	push_back(&head, 3);
	push_back(&head, 4);
	push_back(&head, 5);
	print_t_element_list(head);

	head2 = NULL;
	push_back(&head2, 6);
	push_back(&head2, 7);
	push_back(&head2, 8);
	push_back(&head2, 9);
	push_back(&head2, 10);
	print_t_element_list(head2);

	swap_t_element(&head);
	print_t_element_list(head);
	swap_t_element(&head2);
	print_t_element_list(head2);
	return (0);
}