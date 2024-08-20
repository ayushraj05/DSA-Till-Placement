class Solution {
  public:
  
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n= s1.size();
        int m= s2.size();
        int ans = 0;
        
        // will use the Space Optimation for this now for this now :))

        vector<int> dp(m+1,0);
        int curr, prev;
        for(int i =1; i<n+1;i++){
            curr = prev = 0;
            for(int j =1 ; j<m+1;j++){
                prev = curr;
                curr = dp[j];
                int len = 0;
                if(s1[i-1] == s2[j-1]){
                    len = 1 + prev;
                    ans = max(len, ans);
                }
                dp[j] = len;
            }
        }

        return ans;
    }
};