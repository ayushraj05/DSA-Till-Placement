long long int find(int N, int sum, int coins[], vector<vector<long long int>> &dp){
        // base;
        if(sum == 0){
            return 1;
        }
        if(N ==0){
            return 0;
        }
        if(dp[N][sum] != -1){
            return dp[N][sum];
        }
        // if coint is greater than sum , skip 
        if(coins[N-1] > sum)
            return dp[N][sum] = find(N-1,sum,coins,dp);
        // else
        else
            return dp[N][sum] = find(N,sum-coins[N-1],coins,dp) + find(N-1,sum,coins,dp);
    }
  
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1,-1));
        return find(N,sum,coins,dp);
    }