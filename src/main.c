#include "linked_list.h"

int main(void)
{
    // allocate the head.
	llist_t *l = new_llist_t();
    
	llist_t_add(l, 0);
    llist_t_add(l, 1);
    llist_t_add(l, 2);
	llist_t_log(l);

	free_list(&(l->head));
	return 0;
}
