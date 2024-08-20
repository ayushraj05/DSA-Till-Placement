class Solution {
	public:
	    int find(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp){
	        // base case;
	        if(i1 < 0 || i2 <0){
	            return 0;
	        }
	        if(dp[i1][i2] != -1){
	            return dp[i1][i2];
	        }
	        
	        if(s1[i1-1] == s2[i2-1] && i1 != i2){
	            return dp[i1][i2] = 1+ find(i1-1, i2-1, s1, s2,dp);
	        }
	        else{
	            return dp[i1][i2] = max(find(i1-1, i2, s1, s2,dp), find(i1, i2-1, s1, s2,dp));
	        }
	    }
	    
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    string str2 = str;
		    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
		    return find(n,n,str,str2,dp);
		}

};