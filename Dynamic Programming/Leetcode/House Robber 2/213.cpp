class Solution {
public:
    int find(vector<int> & nums, int index, int end, vector<int> &dp){
        // base case;
        if(index > end) return 0;
        //dp condition;
        if(dp[index]!= -1)
            return dp[index];
        // condition;
        return dp[index] = max(nums[index]+find(nums,index+2,end,dp), find(nums,index+1,end,dp));

    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(find(nums,0,n-2,dp1), find(nums,1,n-1,dp2));

    }
};