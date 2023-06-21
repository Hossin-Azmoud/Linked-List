#ifndef LINKED_LH
#define LINKED_LH
#include "node.h"
/**
 * node.h is a dependency for llist_t, so we can implement function for llist_t
 */

typedef struct llist_t {
    Node *tail;
    Node *head;
	size_t count;
} llist_t;

llist_t *new_llist_t();

void llist_t_add(llist_t *l, int data);
void llist_t_remove(llist_t *l);
void llist_t_log(llist_t *l);

#endif // LINKED_LH
