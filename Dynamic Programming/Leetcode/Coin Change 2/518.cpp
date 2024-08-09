class Solution {
public:
    int coinChange(int index, int amount, vector<int> &coins, vector<vector<int>>& dp){
        // base case;
        if( amount < 0 || index >= coins.size()){
            return 0;
        }
        // answer found :)
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        
        if(amount == 0){
            return dp[index][amount] = 1;
        }

        // pick the one at the index;  // not pick
        return dp[index][amount] = coinChange(index,amount - coins[index],coins,dp) + coinChange(index+1, amount,coins,dp); 
        
    }

    int change(int amount, vector<int>& coins) {
        int index =0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return coinChange(index,amount,coins,dp);
    }
};