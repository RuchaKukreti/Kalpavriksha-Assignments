Kalpavriksha-Assignments

calculator branch: Assignment 1 Calculator Problem

crud branch: Assignment 2 CRUD Operations
You are given two linked lists containing integers. Your task is to:

Sort each of the linked lists in ascending order.
Merge the two sorted linked lists into one sorted linked list.

### Input Format:

An integer n, the number of elements in the first linked list.
n integers representing the elements of the first linked list.
An integer m, the number of elements in the second linked list.
m integers representing the elements of the second linked list.

### Output Format:

-An integer n, the number of elements in the first linked list.
-n integers representing the elements of the first linked list.
-An integer m, the number of elements in the second linked list.
-m integers representing the elements of the second linked list.

### Example:

#### Input:

Enter the number of elements of linkedlist 1: 3
Enter element 1 :1
Enter element 2 :4
Enter element 3 :2
Enter the number of elements of linkedlist 2: 4
Enter element 1 :2
Enter element 2 :5
Enter element 3 :3
Enter element 4 :6

#### Output:

List 1:
->1->4->2
List 2:
->2->5->3->6
Sorted and merged linked list:
->1->2->2->3->4->5->6

### Time Complexity:

-Sorting each linked list takes O(n^2)
-Merging two sorted linked lists takes O(n + m) where n and m are the lengths of the two linked lists.

### Space Complexity:

- O(1)

### Constraints:

1. The number of elements in each list is between 1 and 10,000.
2. The integer values of the list elements can range from -10^6 to 10^6
