class Solution {
  public:
    int help(int n, int m, string &s1, string &s2, int &ans, vector<vector<int>> &dp){
        // base;
        if(n == 0 || m == 0){
            return 0;
        }
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        int len = 0;
        
        if(s1[n-1] == s2[m-1]){
            len = 1 + help(n-1,m-1,s1,s2,ans,dp);
            ans = max(ans, len);
        }
        
        help(n,m-1,s1,s2,ans,dp);
        help(n-1, m,s1,s2,ans,dp);
        
        return dp[n][m] = len;
        
    }
  
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n= str1.size();
        int m= str2.size();
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        help(n,m,str1,str2, ans,dp);
        return ans;
    }
};