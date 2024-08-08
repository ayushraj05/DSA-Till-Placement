class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp1(n+2,-1);
        vector<int> dp2(n+2,-1);
        
        // bottom up approch :)
        dp1[n-1] = dp1[n] = 0;
        dp2[n] = dp2[n+1] = 0;

        for(int i =n-2;i>-1;i--){
            dp1[i] = max(nums[i]+ dp1[i+2], dp1[i+1]);
        }
        for(int i = n-1;i>0;i--){
            dp2[i] = max(nums[i]+ dp2[i+2], dp2[i+1]);
        }
        return max(dp1[0],dp2[1]);
        // return max(find(nums,0,n-2,dp1), find(nums,1,n-1,dp2));

    }
};