class Solution {
public:
    // int find(int index, vector<int> &nums, int n, vector<int>& dp){
    //     // base case;
    //     if(index >= n){
    //         return 0;
    //     }
    //     // 
    //     if(dp[index] != -1){
    //         return dp[index];
    //     }
    //             // robb this house;                  // leave this house;
    //     return dp[index] = max(nums[index] + find(index+2,nums,n,dp), find(index+1,nums,n,dp));
        
        
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+2,-1);
        // bottom up approch;
        // dp[n] = dp[n+1] = 0;
        int first = 0;
        int second = 0;
        int third = 0;
        for(int i=n-1;i>-1;i--){
            third = max(nums[i]+ first, second);
            first = second;
            second = third;
            // dp[i] = max(nums[i]+ dp[i+2], dp[i+1]);
        }
        return third;
    }
};