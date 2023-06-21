#include "linked_list.h"

int main(void)
{
    // allocate the head.
	llist_t *l = new_llist_t();
	int data = 0;

	while(data <= 100)
	{
		llist_t_add(l, data);
		data++;
	}

	// llist_t_log(l);
	void log_node(Node *some_node)
	{
		if (some_node != NULL)
		{
			some_node->data	*= (1 + 3);
		}
	}

	bool is_even(Node *some_node)
	{
		return (bool)((some_node->data % 2) == 0);
	}

	llist_t_map(l, log_node); // 2 1 0
	printf("\n");
	llist_t_filter(l, is_even);	
	llist_t_log(l); // 1 0  
	
	free_list(&(l->head));
	return 0;
}
