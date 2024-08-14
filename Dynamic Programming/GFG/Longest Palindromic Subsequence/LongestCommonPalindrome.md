# Longest Palindromic Subsequence

This repository contains a C++ implementation of the `Longest Palindromic Subsequence` problem, which calculates the length of the longest subsequence in a string that reads the same forward and backward.

## Problem Description

Given a string `A`, the task is to find the length of the longest palindromic subsequence in the string. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

## Approach

1. **Dynamic Programming**:
   - A 2D DP table `dp` is used to store the results of subproblems. `dp[s][e]` represents the length of the longest palindromic subsequence in the substring `A[s...e-1]`.

2. **Recursive Helper Function**:
   - The `find` function is a recursive helper function that computes the length of the longest palindromic subsequence for a given substring. It is called with the start index `s` and end index `e`.

3. **Base Cases**:
   - If the start index `s` is greater than or equal to the string length, or if the end index `e` is less than 0, the function returns `0`.
   - If `A[s]` is equal to `A[e-1]`, the characters contribute to a palindromic subsequence, and the function returns `1 + find(s+1, e-1, A, dp)`.

4. **Memoization**:
   - The results of subproblems are stored in the `dp` table to avoid redundant calculations, making the algorithm efficient.

5. **Final Result**:
   - The function `longestPalinSubseq` initializes the DP table and returns the result of the helper function `find(0, n, A, dp)`.

## Example Usage

Given the following input:
```cpp
string A = "bbbab";
Solution ob;
int result = ob.longestPalinSubseq(A);
cout << result << endl;
