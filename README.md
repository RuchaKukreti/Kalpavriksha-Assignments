Requirements:

-Implement a stack using a single queue with a menu-driven approach.

Operations:
**push**: Add an element to the stack.
**pop**: Remove the top element from the stack.
**peek**: Retrieve the top element without removing it.
**isEmpty**: Check if the stack is empty.
**size**: Return the number of elements in the stack.

Time Complexity Analysis:

-push() O(n)
(Where n is the number of elements in the queue. We need to rotate the queue to maintain the stack's behavior.)

-pop() O(1)
(Simply remove the front element of the queue, which corresponds to the top of the stack.)

-peek() O(1)
(Access the front element of the queue directly.)

-isEmpty() O(1)
(Check if the queue is empty.)

Space Complexity Analysis:

-O(N) where N is the maximum number of elements in the stack.

Conclusion:
-Efficiency:
Using one queue to implement a stack involves additional work for the push operation, making it less efficient than typical stack implementations (with O(1) push).
However, the pop and peek operations are efficient and operate in O(1) time.
-Memory management is handled by the underlying queue, with each element dynamically allocated as needed. Since only one queue is used, there is no overhead for managing additional data structures.
Conclusion:
The performance for the push operation is O(n), which may make it less efficient for scenarios that require frequent pushing.
