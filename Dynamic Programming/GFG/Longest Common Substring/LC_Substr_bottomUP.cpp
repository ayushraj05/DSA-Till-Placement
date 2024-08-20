class Solution {
  public:
  
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n= s1.size();
        int m= s2.size();
        int ans = 0;
        
        // will use the bottom down approch for this now :))
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i= 1; i < n+1; i++){
            for(int j =1; j< m+1; j++){
                int len = 0;
                if(s1[i-1] == s2[j-1]){
                    len = 1 + dp[i-1][j-1];
                    ans = max(len, ans);
                }
                dp[i][j] = len;
            }
        }

        return ans;
    }
};