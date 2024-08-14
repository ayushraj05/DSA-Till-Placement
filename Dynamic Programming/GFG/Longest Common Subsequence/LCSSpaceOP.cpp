class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
        // your code here
        // Space Optmisation;
        vector<int> dp(m+1,0);
        
        int curr, prev;
        for(int i =1;i <n+1;i++){
            curr =0, prev =0;
            for(int j =1; j< m+1;j++){
                prev = curr;
                curr = dp[j];
                
                if(str1[i-1] == str2[j-1]){
                    dp[j] = 1 + prev;
                }
                else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
            }
        }
        return dp[m];
        
    }
};