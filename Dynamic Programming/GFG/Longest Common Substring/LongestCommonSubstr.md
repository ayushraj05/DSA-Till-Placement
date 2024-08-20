# Longest Common Substring Problem

## Problem Explanation

The problem is to find the length of the longest common substring between two given strings, `str1` and `str2`. A substring is defined as a contiguous sequence of characters within a string. The objective is to determine the maximum length of any such substring that appears in both strings.

**Detailed Problem Statement:**
- Given two strings `str1` and `str2`, you need to find the length of the longest common substring.
- Unlike subsequences, substrings must be contiguous, meaning that all the characters in the substring must appear together in the same order in both strings.

For example, if `str1 = "abcde"` and `str2 = "abfce"`, the longest common substring is `"ab"`, and the expected output would be `2`.

## Solution Approach

The solution approach uses dynamic programming to efficiently find the length of the longest common substring. The idea is to use a 2D DP table to store the lengths of matching substrings found so far and update the maximum length encountered during the traversal of both strings.

1. **Dynamic Programming (DP) Table:**
   - The `dp` table is a 2D vector `dp[n][m]` where:
     - `n` is the length of the first string `str1`.
     - `m` is the length of the second string `str2`.
   - The value `dp[i][j]` represents the length of the longest common substring ending at indices `i` in `str1` and `j` in `str2`.

2. **Recursive Function (help):**
   - The `help` function is used to recursively calculate the length of the longest common substring between `str1` and `str2` starting from the end of the strings.
   - If the characters at indices `n-1` and `m-1` in `str1` and `str2` match, the length of the common substring is incremented by `1`, and the function checks the previous characters.
   - If they do not match, the function continues to explore the next possible substrings by recursively reducing either `n` or `m` by `1`.
   - The result is stored in the `dp` table to avoid redundant calculations.

3. **Tracking the Maximum Length:**
   - An additional variable `ans` is used to keep track of the maximum length of any common substring found during the recursion.
   - The variable is updated whenever a longer common substring is found.

4. **Final Result:**
   - The solution returns the value of `ans`, which contains the length of the longest common substring after the recursion completes.

## Time Complexity

The time complexity of this solution is **O(n * m)**, where `n` is the length of `str1` and `m` is the length of `str2`. This complexity arises from the need to fill the `n x m` DP table and recursively check all possible substrings.

## Space Complexity

The space complexity of this solution is **O(n * m)**, required to store the `dp` table with dimensions corresponding to the lengths of the two strings. The space used by the recursion stack is also proportional to `O(n * m)`.

