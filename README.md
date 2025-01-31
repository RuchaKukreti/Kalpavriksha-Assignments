You are tasked with helping a store manage its product inventory. The store stores product names in a singly linked list, where each node represents a product, and the data field of the node stores the name of the product (a string). The store manager wants to search for a specific product by name in the inventory.

Due to memory constraints, you cannot use additional data structures like arrays or vectors to sort or optimize the search. Design an efficient solution to search for a product in the linked list using linear search.

### Input Format:

-A singly linked list of n product names (strings), where each string represents the name of a product.
-An additional string input representing the product name to search for in the linked list.

### Output Format:

-The position of the product in the linked list if found. If the product is not found, output a message indicating the product is not present in the list.

### Example:

#### Input:

Enter the number of products: 5
Enter product 1: Apple
Enter product 2: Banana
Enter product 3: Cherry
Enter product 4: Mango
Enter product 5: Grape
Enter the product to be searched: Mango

#### Output:

Product found at position: 4

### Time Complexity:

- Best Case: O(1)
- Worst Case: O(n)

### Space Complexity:

- O(1)

### Constraints:

1. The search should be done using a linear search.
2. The program should handle an empty list gracefully.
