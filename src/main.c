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
    // print The List
	print(Head); // (40) -> (30) -> (20) -> (10) -> NULL
    // Delete Node index 3.
	DeleteByIndex(Head, 3);
	// Print the list.
    print(Head); // (40) -> (30) -> (20) -> NULL
    // Delete index 1
	DeleteByIndex(Head, 1); // Deletes the second element.
    // Insert a node in index 1.
	Insert(Head, 777, 1); // adds (777) to index 1. 
    // print the list.
	print(Head); // (40) -> (777) -> (20) -> NULL
	// Insert in index 2
    Insert(Head, 911, 2);
    // Print list again.
	print(Head); // (40) -> (777) -> (911) -> (20) -> NULL
	
	// Map using a function.	
	int sum_ = 0;
	
	void sum(Node *some)
	{
		if(some->data)
		{
			sum_ += some->data;
		}
	}

	map(Head, sum);	
	printf("SUM: %i\n", sum_);
	
	// mutate the Node using a map.
	void Multiply(Node *some)
	{
		if(some->data)
		{
			some->data *= 2 + 1;
		}
	}

	map(Head, Multiply);
	print(Head); // (40 * 2) -> (777 * 2) -> (911 * 2) -> (20 * 2) -> NULL
	
	// Filter List.
	bool isOdd(Node *some)
	{
		if(some != NULL)
		{
			if(some->data != NULL)
			{
			
				bool flag = (some->data % 2 == 0);
			
				if(!flag)
				{
					printf("REMOVE: %i\n", some->data);
				} else {
					printf("NOT_REMOVE: %i\n", some->data);
				}

				return flag;
			}

			return true;
		}
		
		return true;
	};

	// remove Nodes that don't satisfy the rule above (some->data % 2) == 0
	
	Filter(Head, isOdd);
	
	print(Head); 
	print(Head);
	// Free mem.
    free(Head);
    
	return 0;
}
