int nthStair(int n){
		    //  Code here
		int step[2] ={1,2};
        int sizea = sizeof(step) / sizeof(step[0]);
        // vector<vector<int>> dp(sizea+1,vector<int>(n+1,0));
        
        // space optmisation;
        vector<int> dp(n+1,0);
        dp[0] =1;
        
        for(int i =1;i<sizea+1;i++){
            for(int j =1; j<n+1;j++){
                if(j-step[i-1] >= 0)
                dp[j] = dp[j-step[i-1]] + dp[j];
            }
        }
        
        return dp[n];
	}