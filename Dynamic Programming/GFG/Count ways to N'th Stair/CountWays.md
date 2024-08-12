# Count Number of Ways to Reach the nth Stair

This repository contains a C++ implementation to count the number of ways to reach the `n`th stair using steps of size 1 and 2. The problem is solved using dynamic programming.

## Problem Description

Given a staircase with `n` stairs, you are allowed to take steps of size 1 or 2 at a time. The task is to find the number of distinct ways to reach the `n`th stair.

## Approach

1. **Dynamic Programming**:
   - Use a dynamic programming approach to solve the problem. Create a helper function `countHelper` that recursively calculates the number of ways to reach a given stair by either taking a 1-step or a 2-step.

2. **Base Cases**:
   - If the index exceeds the number of stairs or the remaining value is negative, return 0 (no valid ways).
   - If the remaining value is 0, return 1 (one valid way found).
   
3. **Memoization**:
   - Use a 2D DP table to store intermediate results and avoid redundant calculations, leading to an optimized solution.

### Helper Functions

- **`countHelper()`**:
  - This function recursively calculates the number of ways to reach the nth stair using the steps available. It uses memoization to store results of subproblems in a DP table.

### Steps Array

- **Steps Array**:
  - The array `step[2] = {1, 2}` defines the allowed steps of size 1 and 2. This array is used within the `countHelper` function to explore all possible step combinations.

## Example Usage

Given the following input:
```cpp
int n = 4;
Solution ob;
int ans  = ob.nthStair(n);
cout << ans <<"\n";
