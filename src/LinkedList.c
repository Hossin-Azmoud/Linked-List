#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void pop_head(Node *Head)
{
	*Head = *Head->Next;
}

size_t Filter(Node *Head, bool (*func)(Node*))
{
	size_t removed = 0;
	Node *Prev = NULL;
	Node *curr = Head;
	
	while(curr != NULL)
    {
		if(!func(curr))
		{
			// Remove it
			if(curr == Head)
			{
				*Head = *(Head->Next);
				removed++;
				Prev = curr;
				curr = curr->Next;
				continue;

			}

			*(Prev->Next) = *(curr->Next);
			removed++;
		}
		

		Prev = curr;
		curr = curr->Next;
    }

	return removed;
}

void map(Node *Head, void (*func)(Node*))
{
	Node *curr = Head;
	
	while(curr != NULL)
    {
		func(curr);
		curr = curr->Next;
    }
}

void print(Node *Head)
{
   	void f(Node *Some)
	{
		if(Some->Next == NULL)
		{
	   		printf("%d -> (NULL)\n", Some->data);
			return;
		}			
	
		printf("%d -> ", Some->data);
	}
    
    map(Head, f);
}
