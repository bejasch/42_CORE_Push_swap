# THIRDS-SORT: Optimized Sorting with Two Stacks and Predefined Operations

## Overview

**THIRDS-SORT** is an algorithm I designed to optimize sorting elements by size, using two stacks (A and B) and a predefined set of operations. Instead of analyzing all elements at each sorting step, the algorithm recursively divides the stack into three parts, leveraging the properties of the available operations.

This project is implemented in **C** and uses **doubly linked ring lists** to represent the stacks, providing a speed optimization for the given operations.

_**Project completed: June 2024**_

## Available Operations

The algorithm uses the following stack operations:

1. **Push**: Move the top element from one stack to the other:
   - `pb`: Push from stack A to stack B.
   - `pa`: Push from stack B to stack A.
   
2. **Swap**: Swap the top two elements of a stack:
   - `sa`: Swap the top two elements of stack A.
   - `sb`: Swap the top two elements of stack B.
   - `ss`: Swap the top two elements of both stacks A and B.

3. **Rotate**: Move the top element of a stack to the bottom:
   - `ra`: Rotate stack A.
   - `rb`: Rotate stack B.
   - `rr`: Rotate both stacks A and B.

4. **Reverse Rotate**: Move the bottom element of a stack to the top:
   - `rra`: Reverse rotate stack A.
   - `rrb`: Reverse rotate stack B.
   - `rrr`: Reverse rotate both stacks A and B.

## Sorting Logic

The sorting process is carried out recursively, alternating between stacks A and B. Here’s the general process for sorting from stack A to stack B:

1. **First third**: Move the smallest elements to the bottom of stack B.
2. **Second third**: Move the middle elements to the top of stack B.
3. **Last third**: Move the largest elements to the bottom of stack A.
4. The process is then repeated recursively for each third until all elements are sorted.

This recursive sorting takes advantage of the stack's top perspective, dividing elements into three groups based on their relative size. The `rr` and `rrr` operations optimize the process, allowing two elements to be sorted simultaneously—one from stack A and one from stack B.

## Optimization for Small Stacks

For stacks with fewer than five elements, the algorithm uses optimized functions that improve performance for smaller data sets.

## Performance and Future Improvements

While the algorithm works efficiently within an **O(n * log(n))** time complexity range, there are opportunities for further optimization, including:

- Stopping the sorting process early when two-thirds of the elements are already sorted.
- Implementing buffering techniques to eliminate inverse operations (e.g., `ra-rra`, `pa-pb`).

These improvements are planned for future versions.

## Conclusion

**THIRDS-SORT** is an efficient and optimized sorting algorithm for two stacks, utilizing recursion and special operations to minimize the complexity of sorting steps. The algorithm performs well in typical use cases and has room for future optimization to further enhance performance.
