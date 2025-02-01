## Requirements:

- Implement a stack using an array with a menu driven appproach.

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

- **O(N)** where **N** is the maximum size of the stack.
- Additional space used is constant **O(1)**.

### **Conclusion**:

1.Efficiency: A stack implemented using an array provides fast access to the top element, with push and pop operations having constant time complexity (O(1)).
2.Simplicity: Array-based stack implementation is simple to understand and efficient
3.Memory Management: Since arrays have a fixed size, managing memory is crucial to avoid overflow, and resizing the array can be a complex solution to overcome this limitation.
