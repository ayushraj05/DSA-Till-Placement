# Minimum Swaps to Group All 1's Together in a Circular Array

This repository contains a C++ implementation to find the minimum number of swaps required to group all 1's together in a circular array.

## Problem Description

Given a binary array (containing only 0's and 1's), the task is to find the minimum number of swaps required to group all 1's together in a circular array. The array is considered circular, meaning that the end of the array wraps around to the beginning.

## Approach

The solution uses a sliding window approach to find the maximum number of 1's in any subarray of length equal to the total number of 1's in the original array. The minimum number of swaps needed will be the difference between the total number of 1's and the maximum number of 1's in any such subarray.

1. **Count Total 1's**:
   - Iterate through the array and count the total number of 1's.

2. **Edge Cases**:
   - If the array has no 1's or is filled with 1's, no swaps are needed.

3. **Sliding Window**:
   - Use a sliding window of size equal to the total number of 1's.
   - Track the number of 1's in the current window.
   - Slide the window across the array, adjusting for the circular nature by using modulo operations.
   - Keep track of the maximum number of 1's in any window.

4. **Calculate Result**:
   - The minimum number of swaps needed will be the total number of 1's minus the maximum number of 1's found in any window.

## Functions

- **minSwaps**: Main function to calculate the minimum number of swaps. It uses the sliding window approach to find the solution.

## Edge Cases

- No 1's in the array (should return `0`).
- All 1's in the array (should return `0`).

## Time Complexity

- **Time Complexity**: \(O(N)\), where \(N\) is the length of the input array. The array is processed a constant number of times.

## Space Complexity

- **Space Complexity**: \(O(1)\), as the solution uses a fixed amount of additional space.

## Usage

The `main` function demonstrates how to use the `minSwaps` function. It initializes a binary array, calls the `minSwaps` function, and prints the result.

```cpp
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;

        for (int num : nums) {
            if (num == 1) {
                totalOnes++;
            }
        }

        if (totalOnes == 0 || totalOnes == n) {
            return 0;
        }

        int currentOnes = 0, maxOnesInWindow = 0;

        for (int i = 0; i < totalOnes; i++) {
            if (nums[i] == 1) {
                currentOnes++;
            }
        }
        maxOnesInWindow = currentOnes;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == 1) {
                currentOnes--;
            }
            if (nums[(i + totalOnes - 1) % n] == 1) {
                currentOnes++;
            }
            maxOnesInWindow = std::max(maxOnesInWindow, currentOnes);
        }

        return totalOnes - maxOnesInWindow;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, 1, 0, 1, 1, 0, 1};
    int result = solution.minSwaps(nums);
    cout << "Minimum swaps required: " << result << endl;
    return 0;
}
