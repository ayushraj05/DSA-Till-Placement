# Longest Common Subsequence (LCS) Problem

This repository contains a C++ implementation of the Longest Common Subsequence (LCS) problem, which calculates the length of the longest subsequence common to two given strings.

## Problem Description

Given two strings `str1` and `str2`, the task is to find the length of the longest subsequence that appears in both strings. A subsequence is a sequence that appears in the same relative order but not necessarily contiguous.

### Example

```cpp
string str1 = "abcde";
string str2 = "ace";
Solution ob;
int result = ob.lcs(str1.size(), str2.size(), str1, str2);
cout << result << endl;
