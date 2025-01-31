You are given a list of books, each with a certain number of pages. Your task is to distribute the books among a specified number of students, such that the maximum number of pages assigned to any student is minimized. You are required to implement the following:

### Input Format:

The number of books.
The number of pages in each book.
The number of students.

### Output Format:

The minimized value of the maximum number of pages assigned to any student.

### Example:

#### Input:

Enter the number of books: 5
Enter number of pages for book 1 :12
Enter number of pages for book 2 :23
Enter number of pages for book 3 :34
Enter number of pages for book 4 :123
Enter number of pages for book 5 :234
Enter the number of student: 1

#### Output:

Books in sorted order by number of pages:
[ 12 23 34 123 234 ]

The minimized value of maximum number of pages assigned to any student is: 426

### Time Complexity:

-Sorting the books takes O(n^2) (Bubble Sort is used in the solution).
-The binary search takes O(log(maxValue - minValue)).

### Space Complexity:

- O(n)

### Constraints:

1. The number of books, n, is between 1 and 100.
2. The number of pages in each book can range from 1 to 10^5.
3. The number of students, s, is between 1 and n.
