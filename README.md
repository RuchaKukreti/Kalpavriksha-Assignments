You are tasked with calculating the H-index for a researcher based on their citation counts. The H-index is a metric used to measure the productivity and citation impact of a scholar. It is defined as the maximum value of h such that the researcher has published at least h papers, each of which has been cited at least h times.

Given a linked list of integers representing the citation counts of a researcher’s papers, the task is to compute the H-index efficiently.

### Input Format:

-The first input will be an integer n, representing the number of papers published by the researcher.
-The next n integers will be the citation counts for each paper. The citation counts will be represented as a singly    linked list of integers, where each node contains the number of citations for the corresponding paper.

### Output Format:

-Research Papers in decreasing order of number of citations
-An integer representing the H-index of the researcher.

### Example:

#### Input:

Enter the number of research papers: 4
Enter number of citations for paper 0 :1
Enter number of citations for paper 1 :3
Enter number of citations for paper 2 :4
Enter number of citations for paper 3 :1

#### Output:

Research Papers in decreasing order of number of citations:
[ 4 3 1 1 ]
H-Index for the publisher is 2

### Time Complexity:

- O(n log n)

### Space Complexity:

- O(n)

### Constraints:

1. The number of research papers, n, will be between 1 and 10,000 (inclusive), i.e., 1 ≤ n ≤ 10,000
2. The citation count for each paper will be a non-negative integer, i.e., 0 ≤ citations[i] ≤ 10^6
