class Solution{
  public:
    
    int longestPalinSubseq(string A) {
        //code here
        
        // bottom up approch :)
        
        int n = A.size();
        string A2 = A;
        reverse(A2.begin(), A2.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int i =1; i< n+1;i++){
            for(int j =1; j< n+1;j++){
                if(A[i-1] == A2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
            }   
        }
        return dp[n][n];
        // return find(0,0,A,A2,dp);
    }
};