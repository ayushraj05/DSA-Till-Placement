class Solution{
	public:
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    // i need to use LCS on this then wiil get the longest common subsequence
	    // then will use maths on that....
	    // lets go .... :)
	    int n = str1.size();
	    int m = str2.size();
	    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	    
	    // now we will do by bottom up approch :)
	    for(int i =1; i < n+1; i++){
	        for(int j =1; j<m+1;j++){
	            if(str1[i-1] == str2[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	            }
	        }
	    }
	    
	    
	    int LCS = dp[n][m];
	    
	    int deleteStr1 = n - LCS;
	    int insertStr1 = m - LCS;
	    
	    return deleteStr1 + insertStr1;
	    
	} 
};