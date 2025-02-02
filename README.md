Requirements:

Implement a queue using a linked list with a menu-driven approach.

Operations:

**enqueue**: Add an element to the queue.
**dequeue**: Remove the front element from the queue.
**peek**: Retrieve the front element without removing it.
**isEmpty**: Check if the queue is empty.
**size**: Return the number of elements in the queue.

Time Complexity Analysis:
-enqueue() O(1)
-dequeue() O(1)
-peek() O(1)
-isEmpty() O(1)
-size() O(n)

Space Complexity Analysis:

-O(N) where N is the maximum number of elements in the queue.
Additional space used for the queue nodes is constant O(1).

Conclusion:
-Efficiency: A queue implemented using a linked list ensures constant time complexity (O(1)) for all core operations (enqueue, dequeue, peek, isEmpty). This guarantees fast and efficient performance for dynamic queues.
-Flexibility: Unlike array-based queues, a linked list allows dynamic memory allocation. This means the queue can grow and shrink in size without worrying about overflows or fixed sizes.
-Memory Management: Memory is allocated dynamically for each element in the queue, making it more flexible than a fixed-size array. However, there is a slight overhead due to storing pointers in each node, but this is typically negligible for most applications.
