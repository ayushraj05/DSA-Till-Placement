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