# Range Sum of Sorted Subarray Sums

This repository contains a C++ implementation to find the range sum of sorted subarray sums from an input array.

## Problem Description

Given an array `nums` of `n` integers, you need to find the sum of the subarray sums for a specified range `[left, right]` when all possible subarray sums are sorted in non-decreasing order. The result should be returned modulo `1000000007`.

## Approach

The solution involves generating all possible subarray sums, sorting them, and then calculating the sum of the elements in the specified range `[left, right]`.

1. **Generate Subarray Sums**:
   - Iterate over all possible subarrays and calculate their sums.
   - Store these sums in a vector `accu`.

2. **Sort the Subarray Sums**:
   - Sort the `accu` vector containing all subarray sums.

3. **Calculate the Range Sum**:
   - Iterate through the sorted subarray sums from index `left` to `right`.
   - Sum these values and take modulo `1000000007`.

## Functions

- **rangeSum**: Main function to calculate the range sum of sorted subarray sums.

## Time Complexity

- **Time Complexity**: \(O(n^2 \log n)\), where \(n\) is the number of elements in the input array. This is due to the double loop for generating subarray sums and the sorting step.

## Space Complexity

- **Space Complexity**: \(O(n^2)\), for storing all subarray sums in the `accu` vector.

## Usage

The `main` function demonstrates how to use the `rangeSum` function. It initializes the input array, specifies the range, and calls the `rangeSum` function to get the result.

```cpp
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> accu = {0};
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                accu.push_back(sum);
            }
        }
        sort(accu.begin(), accu.end());

        for (int i = left; i <= right; ++i)
        {
            res = (res + accu[i]) % 1000000007;
        }
        
        return res;
    }
};
