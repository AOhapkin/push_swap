#include "push_swap.h"

t_element	*find_last_t_element(t_element *head)
{
	if (head)
	{
		while (head->next != 0)
			head = head->next;
		return (head);
	}
	return (0);
}

t_element	*create_new_t_element(int value)
{
	t_element	*new;

	new = malloc(sizeof(new));
	if (new)
	{
		new->value = value;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int	size_t_element(t_element *head)
{
	int		len;

	len = 0;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	return (len);
}

void	push_back(t_element **head, int value)
{
	t_element	*last_elem;

	if (*head)
	{
		last_elem = find_last_t_element(*head);
		last_elem->next = create_new_t_element(value);
	}
	else
	{
		*head = create_new_t_element(value);
	}
}

void	push_front(t_element **head, int value)
{
	t_element	*new_elem;

	new_elem = create_new_t_element(value);
	if (head && new_elem)
	{
		new_elem->next = *head;
		*head = new_elem;
	}
}

void	free_list(t_element *head)
{
	t_element	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	print_t_element_list(t_element *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void	push_t_element(t_element **src, t_element **dst)
{
	t_element	*temp;

	if (src)
	{
		temp = *src;
		*src = (*src)->next;
		temp->next = *dst;
		*dst = temp;
	}
}

void	rotate_t_element(t_element **head)
{
	t_element	*temp;

	if (size_t_element(*head) >= 2)
	{
		temp = *head;
		*head = (*head)->next;
		temp->next = NULL;
		push_back(head, temp->value);
		free(temp);
	}
}

void	rotate_reverse_t_element(t_element **head)
{
	t_element	*last;
	t_element	*prelast;

	if (size_t_element(*head) >= 2)
	{
		last = *head;
		prelast = *head;
		while (last->next)
		{
			prelast = last;
			last = last->next;
		}
		prelast->next = NULL;
		push_front(head, last->value);
	}
}

void	swap_t_element(t_element **head)
{
	int	head_value;
	int temp_value;

	if (size_t_element(*head) >= 2)
	{
		head_value = (*head)->value;
		temp_value = (*head)->next->value;
		(*head)->value = temp_value;
		(*head)->next->value = head_value;
	}
}

