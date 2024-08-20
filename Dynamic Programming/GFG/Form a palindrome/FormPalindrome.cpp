class Solution{
  public:
    
    int help(int n, int m, string &s1, string &s2,vector<vector<int>>&dp){
        /// base case;
        if(n== 0 || m == 0){
            return 0;
        }
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        if(s1[n-1] == s2[m-1] ){
            return dp[n][m] = 1 + help(n-1,m-1,s1,s2,dp);
        }
        else{
            return dp[n][m] = max(help(n-1,m,s1,s2,dp), help(n, m-1, s1,s2,dp));
        }
    }
  
    int countMin(string str){
    //complete the function here
    // in this question we will first use the longest palindromic subsequence :)
    // thn we will use simple maths ... :)))))
        string str2 = str;
        reverse(str2.begin(), str2.end());
        int n = str.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int LPS = help(n,n,str,str2,dp);
        
        return n - LPS;
    
    
    }
};