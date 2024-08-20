class Solution {
	public:
	    
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    // Space Optimisation :)))
		    int n = str.size();
		    string str2 = str;
		    vector<int> dp (n+1, 0);
		    
		    int curr, prev;
		    for(int i =1; i< n+1; i++){
		        prev = curr = 0;
		        for(int j =1; j< n+1; j++){
		            prev = curr;
		            curr = dp[j];
		            if(str[i-1] == str[j-1] && i!=j){
		                dp[j] = 1+ prev;
		            }
		            else{
		                dp[j] = max(dp[j], dp[j-1]);
		            }
		        }
		    }
		    return dp[n];

		}

};