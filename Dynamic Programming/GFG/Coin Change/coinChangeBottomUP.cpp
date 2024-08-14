long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1,0));
        // bottom up approch :)
        for(int i =0;i<N+1;i++){
            dp[i][0] = 1;
        }
        for(int i =1; i<N+1;i++){
            for(int j =1; j<sum+1;j++){
                if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i][j - coins[i-1]] + dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
        // return find(N,sum,coins,dp);
    }