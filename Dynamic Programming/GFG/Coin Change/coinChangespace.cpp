long long int count(int coins[], int N, int sum) {

        // code here.
        // space optmise approch :)
        vector<long long int> dp(sum+1,0);
        dp[0]=1;
        
        for(int i =1;i <N+1;i++){
            for(int j =1; j<sum+1;j++){
                if(j - coins[i-1] >= 0){
                    dp[j] += dp[j - coins[i-1]];
                }
            }
        }
        return dp[sum];
        
    }