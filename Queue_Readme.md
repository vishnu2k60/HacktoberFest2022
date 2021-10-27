Welcome ,Please feel free To add more Programs+ Algos on Queue applications.

##Queues



1. Problem Statment :
Implementation of  queue with linked list. Menu driven options  have enque, deque, show_rear , show _Front and count_size .

Queue using an array is not suitable when we don't know the size of data which we are going to use.
A queue data structure can be implemented using a linked list data structure. The queue which is implemented using a linked list can work for an unlimited number of values.

How to enqueue an element in Queue using linked list?

If queue size is more than capacity, then show an error. Otherwise continue to next step.

Allocate memory for node of Queue type using malloc(). Say 


Queue *newNode = (Queue *) malloc (sizeof(Queue));.

Make sure that the newly created node points to nothing.

newNode->next = NULL;

Assign data to the new node, may be user input.

If queue is not empty then link rear node to newNode. 

(*rear)->next = newNode;.

Make newNode as rear. Since after each enqueue rear gets changed.

If its first node in queue then make it as front node too. 

*front = *rear;

Finally after each successful enqueue, increment size++ by one.

How to dequeue an element from Queue using linked list?

Removal of an existing element from queue is known as dequeue. You can perform dequeue from front of the queue, if its not empty.

If queue is empty, then there will an empty queue error. 

Get front element from queue, which is our required element to dequeue. Store it in some variable say

Queue *toDequeue = *front;

Also store its data to some variable say

int data = toDequeue->data;

Move front node ahead. To make sure that it points to next node after the first node. 

*front = (*front)->next;.

Decrement size--; by one.

Free the dequeued element from memory to save resources, say free(toDequeue);.

Return data, which is our required dequeued element.


                               _._                                            _._                                     _._



 
