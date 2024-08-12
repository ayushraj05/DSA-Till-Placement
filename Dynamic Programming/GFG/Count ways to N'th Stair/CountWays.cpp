//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		
	int countHelper(int index,int value,int step[],int n,vector<vector<int>> &dp){
            //base;
        if(index >= n || value < 0){
            return 0;
        }
        if(value == 0){
            return dp[index][value] = 1;
        }
        if(dp[index][value] != -1){
            return dp[index][value];
        }
        //condition;
        
        return dp[index][value] = countHelper(index,value - step[index],step,n,dp) + countHelper(index+1,value,step,n,dp);
    }
    //Function to count number of ways to reach the nth stair.
    int nthStair(int n){
		    //  Code here
		int step[2] ={1,2};
        int sizea = sizeof(step) / sizeof(step[0]);
        vector<vector<int>> dp(sizea+1,vector<int>(n+1,-1));
        return countHelper(0,n,step,sizea,dp);
	}
   
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends