# Longest Increasing Subsequence Problem

## Problem Explanation

The problem is to find the length of the longest increasing subsequence (LIS) in a given array. A subsequence is a sequence derived from the array by deleting some or no elements without changing the order of the remaining elements. The goal is to identify the length of the longest subsequence in which the elements are strictly increasing.

**Detailed Problem Statement:**
- You are given an array `a[]` of integers of length `n`.
- The task is to determine the length of the longest subsequence such that all elements of the subsequence are sorted in strictly increasing order.
  
For example, given the array `[10, 9, 2, 5, 3, 7, 101, 18]`, the longest increasing subsequence is `[2, 3, 7, 101]` with a length of `4`.

## Solution Approach

The solution approach utilizes a combination of dynamic programming and binary search to efficiently find the length of the longest increasing subsequence. 

1. **Initialization:**
   - A vector `LIS` is used to store the current longest increasing subsequence found so far.
   - The first element of `LIS` is initialized to the first element of the array, as any subsequence must start with at least one element.

2. **Iterating Through the Array:**
   - For each element `a[i]` in the array:
     - Use binary search to determine the appropriate position in `LIS` where `a[i]` should be placed to maintain the increasing order.
     - If `a[i]` is larger than all elements in `LIS`, append it to the end.
     - Otherwise, replace the first element in `LIS` that is larger than or equal to `a[i]` to maintain the potential for a longer subsequence.

3. **Binary Search Logic:**
   - The binary search is used to find the index where `a[i]` should be placed. 
   - If `a[i]` is greater than the current middle element of `LIS`, the search continues in the right half. 
   - If `a[i]` is less than or equal to the middle element, the search narrows to the left half, and the position index is updated.
   - This ensures that `LIS` always contains the smallest possible elements while still being in increasing order.

4. **Updating the Size of LIS:**
   - The size of `LIS` is updated whenever a new element is appended or an existing element is replaced.
   - The length of the LIS at the end of the iteration is `size + 1`.

5. **Returning the Result:**
   - The function returns the length of the longest increasing subsequence, which is `size + 1`.

## Time Complexity

The time complexity of this solution is **O(n log n)**, where `n` is the length of the array. This is because each element requires a binary search operation, which is `O(log n)`, and this is done for all `n` elements.

## Space Complexity

The space complexity of this solution is **O(n)**, which is required to store the `LIS` vector that keeps track of the current longest increasing subsequence.

