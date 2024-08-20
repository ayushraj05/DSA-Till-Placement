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
	    
	    // now we will do by Space Optimisation :)
	    
	    vector<int> dp(m+1, 0);
	    int curr , prev;
	    for(int i =1; i< n+1;i++){
	        curr = prev = 0;
	        for(int j =1;j< m+1;j++){
	            prev =curr;
	            curr = dp[j];
	            if(str1[i-1] == str2[j-1]){
	                dp[j] = 1+prev;
	            }
	            else{
	                dp[j] = max(dp[j], dp[j-1]);
	            }
	        }
	    }
	    
	    int LCS = dp[m];
	    
	    int deleteStr1 = n - LCS;
	    int insertStr1 = m - LCS;
	    
	    return deleteStr1 + insertStr1;
	    
	} 
};