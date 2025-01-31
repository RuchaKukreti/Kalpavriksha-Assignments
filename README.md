You are tasked with managing the list of patients in a hospital emergency department. Each patient has an associated ID and severity level, which can be one of three values: Critical, Serious, or Stable.

The hospital wants to prioritize the patients for treatment based on the severity of their conditions. The priority is as follows:

Critical: The highest priority.
Serious: The second-highest priority.
Stable: The lowest priority.
Given a linked list of patients with their severity levels, you need to sort the list in order of priority. The patients with the Critical severity should be treated first, followed by those with Serious severity, and finally the Stable patients.

### Input Format:

-An integer n, representing the number of patients.
-n pairs of inputs: the patient's ID (an integer) and their severity level (a string: "Critical", "Serious", or "Stable").

### Output Format:

-The program should output the list of patients sorted according to their severity (priority), from the most critical to the least critical. For each patient, display their ID followed by their severity.

### Example:

#### Input:

Enter the number of patients: 5
Enter patient 1 : 101
Enter severity : Critical
Enter patient 2 : 102
Enter severity : Serious
Enter patient 3 : 103
Enter severity : Stable
Enter patient 4 : 104
Enter severity : Critical
Enter patient 5 : 105
Enter severity : Serious

#### Output:

Patients List:
101 Critical
102 Serious
103 Stable
104 Critical
105 Serious

Sorted patients List as per priority:
101 Critical
104 Critical
102 Serious
105 Serious
103 Stable

### Time Complexity:

-O(n^2)

### Space Complexity:

- O(1)

### Constraints:

1. Each patient's severity will be one of the following:
   "Critical"
   "Serious"
   "Stable"
2. The patient ID will be a positive integer.
