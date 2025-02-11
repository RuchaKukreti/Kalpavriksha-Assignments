Requirements:

-Implement a stack using two queues with a menu-driven approach.

Operations:

**push**: Add an element to the stack.
**pop**: Remove the top element from the stack.
**peek**: Retrieve the top element without removing it.
**isEmpty**: Check if the stack is empty.
**size**: Return the number of elements in the stack.

Time Complexity Analysis:

-push(): O(n), where n is the number of elements in the stack. This is due to the need to move elements between the two queues to simulate the stack's behavior.

-pop(): O(1), since removing the front element of the queue is done in constant time.

-peek(): O(1), since it only accesses the front element of the queue.

-isEmpty(): O(1), checks if the queue is empty.

-size(): O(n), where n is the number of elements in the stack, as it involves traversing the queue to count elements.

Space Complexity Analysis:

-O(N) where N is the maximum number of elements in the stack.

Conclusion:
-The push operation is relatively inefficient with O(n) time complexity because it involves moving elements between two queues.
-Pop and peek operations are efficient with O(1) time complexity, as they only deal with the front of the queue.
