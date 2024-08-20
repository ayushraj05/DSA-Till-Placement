# Longest Repeating Subsequence Problem

## Problem Explanation

The problem is to find the length of the longest subsequence that appears at least twice in a given string. The subsequence must consist of characters from the original string in the same order, but the indices of the subsequence should be different in both occurrences.

**Detailed Problem Statement:**
- Given a string `str`, find the length of the longest subsequence which repeats itself.
- The subsequence must not be identical in terms of index positions in the string, meaning that the two subsequences must not have the same characters at the same indices.

For example, in the string `"aab"`, the longest repeating subsequence is `"a"`, which appears twice. The expected output for this example would be `1`.

## Solution Approach

The solution approach uses dynamic programming to find the length of the longest repeating subsequence. The idea is similar to finding the longest common subsequence (LCS) between two strings, but with the additional condition that the characters in the subsequence should not be at the same index in the original string.

1. **Dynamic Programming (DP) Table:**
   - The `dp` table is a 2D vector `dp[i1][i2]`, where:
     - `i1` is the index in the first instance of the string `s1`.
     - `i2` is the index in the second instance of the string `s2`.
   - The value `dp[i1][i2]` represents the length of the longest repeating subsequence found so far.

2. **Recursive Function (find):**
   - The `find` function recursively checks characters at indices `i1` and `i2` in the strings `s1` and `s2`.
   - If the characters match and the indices `i1` and `i2` are not the same, it adds `1` to the result and continues checking the previous indices `i1-1` and `i2-1`.
   - If the characters do not match or the indices are the same, it tries the maximum of ignoring either the current character from `s1` or `s2` and proceeds recursively.
   - The results are stored in the `dp` table to avoid redundant calculations.

3. **Base Case:**
   - If either index `i1` or `i2` becomes less than `0`, the function returns `0` since no valid subsequence can be formed.

4. **Final Result:**
   - The solution starts by calling the `find` function with both indices set to the length of the string `n`, representing the full string.
   - The final result is the length of the longest repeating subsequence, returned by the recursive function.

## Time Complexity

The time complexity of this solution is **O(n^2)**, where `n` is the length of the string. This complexity arises because the solution involves filling an `n x n` DP table, where each cell requires constant time to compute.

## Space Complexity

The space complexity of this solution is **O(n^2)**, required to store the `dp` table with dimensions corresponding to the length of the string. Additional space is used by the recursion stack, but it is also limited by `O(n)`.

