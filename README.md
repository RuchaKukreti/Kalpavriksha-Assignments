You are given a linked list of integers where each node contains an integer value. Your task is to implement a function that sorts the linked list in ascending order and removes duplicate elements from the list, ensuring that each element appears only once.

### Input Format:

-The first input will be an integer n, representing the number of elements in the linked list.
-The next n integers will be the values of the linked list. Each integer represents a node in the linked list.

### Output Format:

-The program should output the sorted linked list with distinct elements, in ascending order.

### Example:

#### Input:

Enter the number of elements of linkedlist: 5
Enter element 1 :1
Enter element 2 :1
Enter element 3 :2
Enter element 4 :1
Enter element 5 :3

#### Output:

List:
[ 1 1 2 1 3 ]
Distinct sorted List:
[ 1 2 3 ]

### Time Complexity:

- Sorting the linked list takes O(n^2) if using insertion sort (in worst case), where n is the number of elements in the linked list.
- Removing duplicates takes O(n), as you need to traverse the list once to remove duplicates.

### Space Complexity:

- O(1)

### Constraints:

1. The linked list will contain at least 1 and at most 10,000 nodes.
2. You are not allowed to use any additional data structures like arrays.
