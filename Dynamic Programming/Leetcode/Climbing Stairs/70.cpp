class Solution {
public:
    int step(int stair, int n, vector<int> &dp){
        if(stair==n)
            return 1;
        if(stair > n)
            return 0;

        //return the result which is already precalculated
        if(dp[stair] != -1){
            return dp[stair];
        }
        dp[stair] = step(stair+1,n,dp) + step(stair+2,n,dp);
        return dp[stair];
    }

    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        dp[n] =1;
        dp[n+1] = 0;
        return step(0,n,dp);
    }
};