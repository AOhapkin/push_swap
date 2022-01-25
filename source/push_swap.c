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

	head = NULL;
	push_back(&head, 7);
	push_back(&head, 6);
	push_back(&head, 5);
	push_back(&head, 4);
	push_back(&head, 3);
	print_t_element_list(head);
	return (0);
}