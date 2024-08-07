class Solution {
public:

    int find(int n, vector<int>&dp){
        // if(n<=1)
        // return n;

        if(dp[n]!= -1){
            return dp[n];
        }
        dp[n] = find(n-1,dp) + find(n-2,dp);
        
        return dp[n];
        
    }

    int fib(int n) {
        if(n<= 1){
            return n;
        }
        vector<int> dp(n+1,-1);
        dp[0] =0;
        dp[1] = 1;

        return find(n,dp);
    }
};