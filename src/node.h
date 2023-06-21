#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node Node;

typedef struct Node {
    int  data;
    Node *Next;
} Node;

void   add(Node **Head, int data);
Node   *find(Node *Head, int d);
int    delete_by_data(Node *Head, int data);
int    delete_by_index(Node *Head, int i);
void   pop_head(Node *Head);
size_t filter(Node **Head, bool (*func)(Node*));
void   map(Node *Head, void (*func)(Node*));
void   insert(Node **Head, int data, int i);
void   print(Node *Head);
Node   *at(Node *Head, size_t i);
void   free_list(Node **Head);
Node   *allocate_head();

#endif // NODE_H

