You are given a linked list of integers. Your task is to:

Separate the odd and even numbers into two distinct linked lists.
Sort both the odd and even linked lists in ascending order.
Merge the two sorted lists such that the odd numbers come first, followed by the even numbers.

### Input Format:

A linked list containing n integers.

### Output Format:

A linked list where all odd numbers are sorted in ascending order, followed by all even numbers sorted in ascending order.

### Example:

#### Input:

Enter the number of elements of linkedlist: 5
Enter element 1 :1
Enter element 2 :8
Enter element 3 :3
Enter element 4 :7
Enter element 5 :5

#### Output:

List:
->1->8->3->7->5
List after sorting all odd numbers and all even numbers in ascending order.
->1->3->5->7->8

### Time Complexity:

-Sorting the linked list using QuickSort takes O(n^2) in the worst case and O(nlogn).
-Separating odd and even numbers takes O(n).
-Merging the lists takes O(n)

### Space Complexity:

- O(n)

### Constraints:

1. The number of elements in the linked list, n, is between 1 and 100.
