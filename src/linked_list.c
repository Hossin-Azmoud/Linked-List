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
	return print(l->head);
}

void llist_t_map(llist_t *l, void (*application)(Node *))
{
	return map(l->head, application);
}

void llist_t_filter(llist_t *l, bool (*predicate)(Node*))
{
	size_t r = filter(&(l->head), predicate);
	l->count = l->count - r;
}

llist_t *new_llist_t()
{
	llist_t *l = malloc(sizeof(llist_t));
	
	if (l == NULL)
	{
		fprintf(stderr, "Could not allocate the llist in func `new_llist_t()`\n")
		exit(1);
	}

	l->head  = NULL;
	l->tail  = NULL;
	l->count = 0;
	
	return l;
}
