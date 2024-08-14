class Solution{
  public:
    int find(int s, int e, string &a, vector<vector<int>> &dp){
        //base
        if(s >= a.size() || e <0){
            return 0;
        }
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        
        if(a[s] == a[e-1]){
            return dp[s][e] = 1+ find(s+1,e-1,a,dp);
        }
        else{
            return dp[s][e] = max(find(s,e-1,a,dp),find(s+1,e,a,dp));
        }
    }
    
    
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return find(0,n,A,dp);
    }
};