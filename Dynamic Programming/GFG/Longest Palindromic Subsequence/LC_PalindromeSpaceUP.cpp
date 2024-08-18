class Solution{
  public:
    
    int longestPalinSubseq(string A) {
        //code here
        
        // Space opptmisation :)
        
        int n = A.size();
        string A2 = A;
        reverse(A2.begin(), A2.end());
        vector<int> dp(n+1,0);
        
        int curr, prev;
        for(int i =1;i<n+1;i++){
            curr = prev = 0;
            for(int j =1; j<n+1; j++){
                prev = curr;
                curr = dp[j];
                if(A[i-1] == A2[j-1]){
                    dp[j] = 1+ prev;
                }
                else{
                    dp[j] = max(dp[j-1], dp[j]);
                }
            }
        }
        
        return dp[n];

};