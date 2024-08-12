int find(int index, int W, int wt[], int val[], vector<vector<int>> &dp){
        //base;
        if(W == 0){
            return 0;
        }
        if(index == 0){
            return 0;
        }
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        
        if(wt[index-1] >W){
            return dp[index][W] = find(index-1,W,wt,val,dp);
        }
        else{
            return dp[index][W] = max( val[index-1] + find(index-1,W- wt[index-1],wt,val,dp),find(index-1,W,wt,val,dp));
        }
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return find(n,W,wt,val,dp);
    }