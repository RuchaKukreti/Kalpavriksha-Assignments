Requirements:

-Implement a queue using two stacks with a menu-driven approach.

Operations:

**enqueue**: Add an element to the queue.
**dequeue**: Remove the front element from the queue.
**peek**: Retrieve the front element without removing it.
**isEmpty**: Check if the queue is empty.
**size**: Return the number of elements in the queue.

Time Complexity Analysis:

-enqueue(): O(1), as the element is simply pushed onto the stack.

-dequeue(): O(n), where n is the number of elements in the queue. This is because elements are transferred from the main stack to the temporary stack and back, taking linear time relative to the size of the queue.

-peek(): O(n), as it requires traversing the entire stack to access the bottom (front) element.

-isEmpty(): O(1), simply checks if the stack is empty.

-size(): O(n), as it requires traversing the stack to count the elements.

Space Complexity Analysis:
O(N), where N is the number of elements in the queue, because the space used by the stack grows linearly with the number of elements stored.
Conclusion:
Efficiency:
The enqueue operation is efficient with O(1) time complexity. However, the dequeue and peek operations are slower, with O(n) time complexity due to the need to transfer elements between stacks to maintain the correct order.
