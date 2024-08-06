# k-th Distinct String Finder

This repository contains a C++ implementation to find the k-th distinct string in an array. A distinct string is one that appears exactly once in the array.

## Problem Description

Given an array of strings and an integer `k`, this program finds the k-th distinct string in the array. If there are fewer than `k` distinct strings, the function returns an empty string.

## Approach

1. **Count Occurrences**:
   - Use an unordered map `count` to store the occurrence of each string in the array.

2. **Find k-th Distinct String**:
   - Iterate through the array again and check if the string's occurrence is exactly one. If it is, decrement `k`.
   - When `k` reaches zero, return the current string.

3. **Return Result**:
   - If fewer than `k` distinct strings are found, return an empty string.

## Functions

- **kthDistinct**: Main function to find the k-th distinct string in the array.

## Time Complexity

- **Time Complexity**: \(O(n)\), where \(n\) is the number of strings in the array. This is due to the two iterations through the array.

## Space Complexity

- **Space Complexity**: \(O(n)\), for storing the counts of the strings in the unordered map.

## Usage

The `main` function demonstrates how to use the `kthDistinct` function. It initializes the input array and the value of `k`, and calls the `kthDistinct` function to get the result.

```cpp
class Solution {
 public:
  string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> count;

    for (const string& a : arr)
      ++count[a];

    for (const string& a : arr)
      if (count[a] == 1 && --k == 0)
        return a;

    return "";
  }
};
