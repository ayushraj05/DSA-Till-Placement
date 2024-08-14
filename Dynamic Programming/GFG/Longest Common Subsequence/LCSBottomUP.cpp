class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        // bottom up approch;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i =1;i < n+1;i++){
            for(int j = 1; j < m+1;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};