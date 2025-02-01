Requirements:

-Implement a queue using an array with a menu-driven approach.

Operations:

**enqueue**: Adds an element to the rear of the queue.
**dequeue**: Removes the element from the front of the queue.
**peek**: Retrieves the front element without removing it.
**isEmpty**: Checks if the queue is empty.
**size**: Returns the number of elements currently in the queue.

Time Complexity Analysis:

-enqueue(): O(1)
-dequeue(): O(1)
-front(): O(1)
-isEmpty(): O(1)

Space Complexity Analysis:

-O(N) where N is the maximum size of the queue.
-O(1) additional for each operation.

Conclusion:
1.Efficiency: A queue implemented using an array allows for fast constant time (O(1)) operations for enqueue, dequeue, and checking if the queue is empty.
2.Fixed Size Limitation: Since the queue is implemented using an array, it has a fixed size. You need to manage the size of the array to prevent overflow, and resizing the array can be a complex task when the queue grows beyond its initial capacity.
3.Simplicity: Array-based queue implementations are easy to understand and suitable for scenarios where the maximum size of the queue is known in advance and the size doesn’t change significantly.
