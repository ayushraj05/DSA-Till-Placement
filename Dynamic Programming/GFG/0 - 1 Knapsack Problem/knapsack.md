# 0/1 Knapsack Problem

This repository contains a C++ implementation to solve the classic 0/1 Knapsack problem using dynamic programming.

## Problem Description

Given weights and values of `n` items, and a knapsack with a capacity `W`, the goal is to determine the maximum value that can be obtained by selecting items such that the total weight does not exceed the capacity of the knapsack. Each item can either be included in the knapsack or excluded (hence the name 0/1 Knapsack).

## Approach

1. **Dynamic Programming**:
   - The problem is solved using dynamic programming by breaking it down into subproblems. The key idea is to build a DP table where each entry `dp[i][w]` represents the maximum value that can be obtained using the first `i` items and a knapsack capacity of `w`.

2. **Recursive Helper Function**:
   - A recursive helper function `find` is used to explore the two possibilities for each item: either include it in the knapsack or exclude it. The results of these subproblems are stored in a DP table to avoid redundant calculations.

3. **Base Cases**:
   - If the remaining capacity `W` is 0 or if no items are left to choose from (i.e., `index` is 0), the maximum value is 0.
   
4. **DP Table Initialization**:
   - The DP table is initialized with `-1` to indicate that a subproblem has not been solved yet.

### Helper Function

- **`find()`**:
  - This function recursively calculates the maximum value that can be obtained for a given knapsack capacity and item index. It uses memoization to store results of subproblems in a DP table.

### Decision-Making

- **Include/Exclude Decision**:
  - If the weight of the current item is greater than the remaining capacity, the item is excluded. Otherwise, the maximum value is obtained by either including the item or excluding it.

## Example Usage

Given the following input:
```cpp
int W = 50;
int wt[] = {10, 20, 30};
int val[] = {60, 100, 120};
int n = sizeof(val)/sizeof(val[0]);
Solution ob;
int ans = ob.knapSack(W, wt, val, n);
cout << ans <<"\n";
