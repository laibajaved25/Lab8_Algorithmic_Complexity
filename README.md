
# CS250 - Lab 8: Algorithmic Complexity

## Student Information
- Course: CS250 - Data Structures and Algorithms
- Lab: Lab 8
- Topic: Algorithmic Complexity

## Task 1: Peak Element in a 2D Array

Implemented a peak-finding algorithm using binary search on columns.

A peak element is greater than or equal to its four adjacent neighbors.

Algorithm:
1. Find the middle column.
2. Find the maximum element in that column.
3. Compare it with its left and right neighbors.
4. Search the appropriate half until a peak is found.

Time Complexity: O(N log N)

Space Complexity: O(1), excluding the input matrix.

## Task 2: Knight's Tour

Implemented Knight's Tour using recursive backtracking and Warnsdorff's heuristic.

The knight visits each square exactly once.

Algorithm:
1. Start from a given position.
2. Generate all valid knight moves.
3. Calculate onward moves for each candidate.
4. Try candidates with the fewest onward moves first.
5. Backtrack when no valid continuation exists.

Best-case time: O(N^2)
Worst-case time: Exponential.

## Task 3: Tower of Hanoi

Implemented Tower of Hanoi using an iterative approach and stacks.

The algorithm transfers disks from the source peg to the destination peg while following the rules.

Minimum number of moves:

T(N) = 2^N - 1

Time Complexity: O(2^N)

Space Complexity: O(N)

## Conclusion

All three tasks were implemented using C++.

The lab demonstrates binary search, backtracking, heuristic optimization, iterative algorithms, and asymptotic complexity analysis.

