Sorting Algorithm Description for Push_Swap
The push_swap algorithm sorts a stack of integers using a minimal number of operations by dividing the problem into smaller chunks and handling small stacks separately.

Error Handling and Initialization:

The algorithm begins by handling errors and filling stack_a with the input numbers.
A copy of stack_a is made and sorted.
stack_b is initialized to assist in the sorting process.
Dividing the Problem into Chunks:

A range is initialized with min = 1 and max = sqrt(a->capacity) + a->capacity / 500 + 5.
This range helps in dividing the problem into smaller, manageable chunks.
Sorting Process:

For each number in stack_a, its index (level) in the sorted copy is checked:
If the index is less than min, the number is pushed to stack_b and stack_b is rotated.
If the index is between min and max, the number is pushed to stack_b without rotation.
This process continues until stack_a is empty.
Rebuilding Stack A:

After stack_a is empty, the algorithm looks for the maximum number in stack_b.
The maximum number is pushed back to stack_a until stack_b is empty and stack_a is sorted.
Special Case for Small Stacks:

For small stacks with 5 or fewer elements, a specialized small sort routine is used, bypassing the chunk-based sorting algorithm.
