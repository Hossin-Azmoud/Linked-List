# About this implementation
## Quick start

- compile with: 
```bash
    $ gcc -o main main.c -lm
```

## Main strcuture
- Linked list Node:

```C
    typedef struct Node {
	T    data;
	Node *Next;
    } Node;
```

## Functions

- `add(Node *Head, int data)`: adds a new node.
```
    Before calling add: (0) -> (NULL)
    After calling add with head of the list and data 1: (1) -> (0) -> (NULL)
    Note that the head changed. so it is the new added element, to keep track we return the new head.
```

- `Find(Node *Head, int data)`: linearly Searching the list for the Node that has `data` as its data field, return NULL if not found!

- `DeleteBydata(Node *Head, int data)`: Deletes the Node that has `data` as its data field. 0 on success and 1 on failure.

- `DeleteByIndex(Node *Head, int i)`: deletes the i-th Node from the list. if i == 0 we just remove the head and make head->Next the new head. 0 on success and 1 on failure.

- `Insert(Node *Head, int data, int i)`: Insert Node with data in the i-th positionj, if it was successfully added it returns the inserted Node, if not returns NULL.

- `At(Node *Head, size_t i)`: get Node in i-th position, NULL returned if i is an invalid index.

- `print(Node *Head)`: Traverses the linked list from Head to NULL.

```
Example:
    (0) -> (1) -> (2) -> (3) -> (NULL)
```

# WHAT IS A LINKED LIST :)

- A linked list is a non-sequential collection of data items. It is a dynamic data structure. 
For every data item in a linked list, there is an associated pointer that would give the 
memory location of the next data item in the linked list.

- The data items in the linked list are not in consecutive memory locations. They may be 
anywhere, but the accessing of these data items is easier as each data item contains 
the address of the next data item.

# ADVANTAGES OF LINKED LISTS

1. Linked lists are dynamic data structures. i.e., they can grow or shrink during 
the execution of a program.

2. Linked lists have efficient memory utilization. Here, memory is not preallocated. Memory is allocated whenever it is required and it is de-allocated (removed) when it is no longer needed.

3. Insertion and Deletions are easier and efficient. Linked lists provide flexibility 
in inserting a data item at a specified position and deletion of the data item 
from the given position.

4. Many complex applications can be easily carried out with linked lists.

# DISADVANTAGES OF LINKED LISTS

1. It consumes more space because every node requires a additional pointer to 
store address of the next node.
2. Searching a particular element in list is difficult and also time consumin

# TYPES

NOTE: T => int, Float, char, size_t..

1. Single Linked List.
```C
    typedef struct Node {
	T data;
	Node *next;
    } Node;
```

2. Double Linked List.
```C
    typedef struct Node {
	T data;
	Node *next;
	Node *prev;
    } Node;
```
3. Circular Linked List.
```C
    typedef struct Node {
	T data;
	Node *next;
    } Node;
```
4. Circular Double Linked List
```C
    typedef struct Node {
	T data;
	Node *next;
	Node *prev;

    } Node;
```

# DIFFERENCE BETWEEN ARRAY AND LINKED LISTS.

----------------------------------------------------------------------------------------------------|
		      ARRAYS   	                |                    LINKEDLISTS                    |
----------------------------------------------------------------------------------------------------|
Size of an array is fixed.	                | Size of a list is not fixed.                      |
                         			|                                                   |
Memory is allocated from stack.			| Memory is allocated from heap.                    |
						|                                                   |
It is necessary to specify the number of        | specifying the size is not required.              |
elements during declaration.			|                                                   |
						|                                                   |
It occupies less memory.			| it requires more memory.                          |
						|                                                   |
Insertion are expansive    	                | Insertion are mostly carried easily.              |
						|                                                   |
Deletions are not possible	                | Deletions are possible.                           |
-----------------------------------------------------------------------------------------------------
