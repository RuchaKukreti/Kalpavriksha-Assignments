You are tasked with managing a singly linked list of integers. The goal is to remove the middle node from the linked list using the two-pointer technique.
The middle node of a list is defined as:

If the list contains an odd number of nodes, the middle node is the exact middle.
If the list contains an even number of nodes, the middle node is the second of the two middle nodes.

### Input Format:

-The first input will be an integer n, which represents the number of elements in the linked list.
-The following n integers will represent the values of the nodes in the linked list.

### Output Format:

-Print the linked list before removing the middle node.
-Print the linked list after removing the middle node.

### Example:

#### Input:

Enter the number of elements of linked list: 5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Enter element 5: 5

#### Output:

List:
->1->2->3->4->5
List after removing the middle node:
->1->2->4->5

### Time Complexity:

- O(n)

### Space Complexity:

- O(1)

### Constraints:

1. The linked list will contain at least one element.
2. You cannot use any additional data structures like arrays.
