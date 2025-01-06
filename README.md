# push_swap  

push_swap is a sorting algorithm project written in C. The program sorts a stack of integers using a limited set of operations and an auxiliary stack. The goal is to achieve the sorting in the fewest moves possible, demonstrating proficiency in algorithm design and optimization.

## How It Works  
1. **Input Handling**  
   - The program takes a list of integers as input and stores them in a stack (`stack A`).  
   - It validates the input to ensure there are no duplicates and all values are valid integers.  

2. **Operations**  
   - A set of predefined operations is used to manipulate the stacks:  
     - `sa`, `sb`, `ss`: Swap the top two elements of a stack.  
     - `pa`, `pb`: Push the top element from one stack to another.  
     - `ra`, `rb`, `rr`: Rotate a stack (shift all elements up).  
     - `rra`, `rrb`, `rrr`: Reverse rotate a stack (shift all elements down).  

3. **Sorting Algorithm**  
   - The program determines the most efficient sequence of operations to sort the integers in ascending order.  
   - Different sorting strategies are implemented based on the size of the stack:  
     - **Small stack (3-5 elements)**: Hardcoded or brute force solutions.  
     - **Larger stacks**: Advanced algorithms such as partitioning and chunk-based sorting are used for efficiency.  

4. **Output**  
   - The program outputs the list of operations required to sort the stack.  

5. **Error Handling**  
   - Ensures invalid inputs or incorrect arguments are handled gracefully with clear error messages.  

## What I Learned  
- How to design and implement sorting algorithms optimized for specific constraints.  
- Efficient use of data structures such as stacks.  
- Handling edge cases in sorting, such as duplicate values or already sorted inputs.  
- Understanding and implementing common algorithmic techniques, such as divide
