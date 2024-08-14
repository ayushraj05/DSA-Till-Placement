class Solution {
  public:
    int helper(int i1, int i2, string &str1, string &str2, vector<vector<int>> & dp){
        //base case;
        if(i1 < 0 || i2 < 0){
            return 0;
        }
        
        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }
        
        if(str1[i1] == str2[i2]){
            return dp[i1][i2] = 1 + helper(i1-1,i2-1,str1,str2,dp);
        }
        else{
            return dp[i1][i2] = max(helper(i1-1,i2,str1,str2,dp) , helper(i1,i2-1,str1,str2,dp));
        }
    }
  
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        
        return helper(n-1,m-1,str1,str2,dp);
    }
};