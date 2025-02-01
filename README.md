## Requirements:

-Implement a stack using a linked list with a menu-driven approach.

### Operations:

1. push: Add an element to the stack.
2. pop: Remove the top element from the stack.
3. peek: Retrieve the top element without removing it.
4. isEmpty: Check if the stack is empty.
5. size: Return the number of elements in the stack.

## **Time Complexity Analysis**:

**push()** O(1)  
 **pop()** O(1)  
 **peek()** O(1)  
 **isEmpty()** O(1)

## **Space Complexity Analysis**:

-O(N) where N is the maximum number of elements in the stack.
-Additional space used for the stack nodes is constant O(1).

### **Conclusion**:

1.Efficiency: A stack implemented using a linked list ensures constant time complexity (O(1)) for all core operations (push, pop, peek, isEmpty).
2.Flexibility: Unlike array-based stacks, a linked list allows dynamic memory allocation, so the stack size can grow and shrink as needed without worrying about overflow or underutilization.
3.Memory Management: Memory is allocated dynamically for each element, making it more flexible than a fixed-size array, but with the slight overhead of pointer storage in each node.
