Requirements:

-Implement a queue using two stacks with a menu-driven approach.

Operations:

-enqueue: Add an element to the queue.
-dequeue: Remove the front element from the queue.
-peek: Retrieve the front element without removing it.
-isEmpty: Check if the queue is empty.
-size: Return the number of elements in the queue.

Code Description:

This implementation simulates a queue using two stacks, stackTop and stackTemp. The key idea behind this implementation is to use the first stack (stackTop) for enqueueing elements, and the second stack (stackTemp) for reversing the order during dequeue operations.

Time Complexity Analysis:

-enqueue(): O(1), as the element is simply pushed onto the stackTop with no additional operations.

-dequeue(): O(n), where n is the number of elements in the queue. This is because elements must be transferred from stackTop to stackTemp and back, which takes linear time relative to the size of the queue.

-peek(): O(n), as it requires traversing the entire stack to access the bottom (front) element.

-isEmpty(): O(1), simply checks if stackTop is empty.

-size(): O(n), as it requires traversing the stack to count the elements.

Space Complexity Analysis:

O(N), where N is the number of elements in the queue.

Conclusion:
The enqueue operation is efficient with O(1) time complexity, as it only involves pushing elements onto the stackTop.
Dequeue and peek operations are slower with O(n) time complexity due to the need to transfer elements between stacks to maintain the correct order.
