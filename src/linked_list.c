#include "linked_list.h"

void llist_t_add(llist_t *l, int data)
{

	if (l->count == 0)
	{
		add(&(l->head), data);
		l->tail = l->head;
		l->count++;
		return;
	}

	add(&(l->head), data);
	l->count++;
	return;
}

void llist_t_remove(llist_t *l)
{
	(void) l;
	assert(0 && "NOT IMPLEMENTED!");
}

void llist_t_log(llist_t *l)
{
	print(l->head);
}

void llist_t_map(llist_t *l)
{
	(void) l;
	assert(0 && "NOT IMPLEMENTED!");

}

void llist_t_filter(llist_t *l)
{
	(void) l;
	assert(0 && "NOT IMPLEMENTED!");

}

llist_t *new_llist_t()
{
	llist_t *l = malloc(sizeof(llist_t));

	l->head  = NULL;
	l->tail  = NULL;
	l->count = 0;
	
	return l;
}
