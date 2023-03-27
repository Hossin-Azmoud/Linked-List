#include "LinkedList.c"

int main(void) 
{
    // allocate the head.
    Node *Head = malloc(sizeof(Node));
    
    // Set Fields
    Head->data = 10;
    Head->Next = NULL;
    
    // Adding Nodes.
    Head = add(Head, 20);    
    Head = add(Head, 30);
    Head = add(Head, 40);
    Head = add(Head, 30);
    
    // printing.
    print(Head); // (30) -> (40) -> (30) -> (20) -> (10) -> NULL
		 
    Node *n = At(Head, 10); // NULL because the size of Linked list is less than (10 + 1)
    
    if(n != NULL) 
    {
	printf("%d\n", n->data);
    } else {
	printf("Not found!\n");
    }
    
    // Deletes the first element.
    DeleteByIndex(Head, 0);

    print(Head); // (40) -> (30) -> (20) -> (10) -> NULL

    
    DeleteByIndex(Head, 3);
    print(Head); // (40) -> (30) -> (20) -> NULL


    DeleteByIndex(Head, 1); // Deletes the second element.

    Insert(Head, 777, 1); // adds (777) to index 1. 
    
    print(Head); // (40) -> (777) -> (20) -> NULL
    
    Insert(Head, 911, 2);
    
    print(Head); // (40) -> (777) -> (911) -> (20) -> NULL

    free(Head);

    return 0;
}
