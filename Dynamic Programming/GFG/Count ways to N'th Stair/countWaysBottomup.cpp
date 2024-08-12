int nthStair(int n){
		    //  Code here
		int step[2] ={1,2};
        int sizea = sizeof(step) / sizeof(step[0]);
        vector<vector<int>> dp(sizea+1,vector<int>(n+1,0));
        
        // bottom up approch;
        //index, value
        for(int i =0; i<sizea+1;i++){
            dp[i][0] =1;
        }
        for(int i = 1;i<3;i++){
            for(int j = 1; j< n+1;j++){
                if(j-step[i-1] < 0){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i][j-step[i-1]] + dp[i-1][j];
                }
            }
        }
        
        return dp[sizea][n];
	}