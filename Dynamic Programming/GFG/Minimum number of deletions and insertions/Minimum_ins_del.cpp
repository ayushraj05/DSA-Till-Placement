class Solution{
	public:
	
	int help(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
	    // base case;
	    if(i == 0 || j == 0){
	        return 0;
	    }
	    
	    if(dp[i][j] != -1){
	        return dp[i][j];
	    }
	    
	    if(s1[i-1] == s2[j-1]){
	        return dp[i][j] = 1+ help(s1,s2,i-1,j-1,dp);
	    }
	    else{
	        return dp[i][j] = max(help(s1,s2,i-1,j,dp), help(s1,s2,i,j-1,dp));
	    }
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    // i need to use LCS on this then wiil get the longest common subsequence
	    // then will use maths on that....
	    // lets go .... :)
	    int n = str1.size();
	    int m = str2.size();
	    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
	    int LCS = help(str1,str2,n,m,dp);
	    
	    int deleteStr1 = n - LCS;
	    int insertStr1 = m - LCS;
	    
	    return deleteStr1 + insertStr1;
	    
	} 
};