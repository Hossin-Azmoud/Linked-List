/*


malloc() is a system function which allocates a block of memory in the "heap" and
returns a pointer to the new block. The prototype of malloc() and other heap functions 
are in stdlib.h. malloc() returns NULL if it cannot fulfill the request. It is defined by:
    void *malloc (number_of_bytes)
Since a void * is returned the C standard states that this pointer can be converted to 
any type. For example,
    char *cp;
    cp = (char *) malloc (100);

Attempts to get 100 bytes and assigns the starting address to cp. We can also use the 
sizeof() function to specify the number of bytes. For example,

int *ip;
ip = (int *) malloc (100*sizeof(int));

Linked lists are dynamic data structures. i.e., they can grow or shrink during 
the execution of a program.

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct Node {
    int  data;
    Node *Next;
} Node;

Node *add(Node *Head, int data)
{
    Node *New = malloc(sizeof(Node));
    
    New->data  =  data;
    New->Next  =  Head;
    
    return New;
}

Node *Find(Node *Head, int d)
{
    Node *curr = Head;

    while(curr != NULL)
    {
	if(curr->data == d)
	{
	    return curr;
	}

	curr = curr->Next;
    }

    return NULL;
}

int DeleteBydata(Node *Head, int data)
{
    Node *Prev = NULL;
    Node *curr = Head;

    while(curr != NULL)
    {
	if(curr->data == data)
	{
	    if(Prev != NULL)
	    {
		*Prev->Next = *curr->Next;
		return 0;
	    }
	    
	    *Head = *curr->Next;

	    return 0;
	}

	Prev = curr;
	curr = curr->Next;
    }

    return 1;
}

int DeleteByIndex(Node *Head, int i)
{
    Node *Prev = NULL;
    Node *curr = Head; 
    size_t index = 0;
 

    if(Head == NULL)
    {
	return 1;
    }

    if(i == 0)
    {
	*Head = *curr->Next;
	return 0;
    }

        
    while(curr != NULL)
    {
	
	if(i - index == 0)
	{
	    if(Prev != NULL)
	    {
		Prev->Next = curr->Next;
	    }

	    break;
	}

	Prev = curr;
	curr = curr->Next;
	index++;
    }
    
    if(i - index > 0)
    {
	return 1;
    }

    return 0;
}
Node *Insert(Node *Head, int data, int i)
{
    Node *new = malloc(sizeof(Node));
    
    if(new == NULL) return NULL; 
    
    Node *Prev = NULL;
    Node *curr = Head;
     
    if(i == 0)
    {
	new = add(Head, data);
	return new;
    }

    while(curr != NULL && i > 0)
    {
	i--;
	Prev = curr;
	curr = curr->Next;
    }
    
    if(i == 0)
    {
	new->data  =  data;
	new->Next  =  curr;
	Prev->Next =  new;
	return new;
    }
    
    return NULL;
    
}

Node *At(Node *Head, size_t i)
{
    if(Head == NULL)
    {
	return NULL;
    }

    Node *curr = Head; 
    size_t index = 0;
    
    while(curr != NULL)
    {
	
	if(i - index == 0)
	{
	    break;
	}

	curr = curr->Next;
	index++;
    }
    
    if(i - index > 0)
    {
	return NULL;
    }

    return curr;
}

void print(Node *Head)
{
    Node *curr = Head;    
    
    while(curr != NULL)
    {
	if(curr->Next == NULL)
	{
	   printf("%d -> (NULL)\n", curr->data);
	} else {
	    printf("%d -> ", curr->data);
	}

	curr = curr->Next;
    }
}

int main(void) 
{
    Node *Head = malloc(sizeof(Node));
    
    Head->data = 10;
    Head->Next = NULL;
     
    Head = add(Head, 20);    
    Head = add(Head, 30);
    Head = add(Head, 40);
    Head = add(Head, 30);
    
    // printing.
    print(Head);
    Node *n = At(Head, 10);
    if(n != NULL) 
    {
	printf("%d\n", n->data);
    } else {
	printf("Not found!\n");
    }
    DeleteByIndex(Head, 0);
    // Freeing the list.
    
    print(Head);
    
    DeleteByIndex(Head, 3);
    print(Head);

    DeleteByIndex(Head, 1);
    Insert(Head, 777, 1);
    
    print(Head);
    
    Insert(Head, 911, 2);
    
    print(Head);
    free(Head);

    return 0;
}
