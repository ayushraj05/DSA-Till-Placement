class Solution{
  public:
  
    int countMin(string str){
    //complete the function here
    // in this question we will first use the longest palindromic subsequence :)
    // thn we will use simple maths ... :)))))
    
    // will try Space Optimisation approch now wish me luck... :)
    
        string str2 = str;
        reverse(str2.begin(), str2.end());
        int n = str.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        vector<int> dp(n+1,0);
        int prev, curr;
        for(int i =1; i<n+1;i++){
            prev = curr =0;
            for(int j =1; j< n+1;j++){
                prev = curr;
                curr = dp[j];
                if(str[i-1] == str2[j-1]){
                    dp[j] = 1 + prev;
                }
                else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
            }
        }
        
        int LPS = dp[n];
        
        return n - LPS;
    
    
    }
};