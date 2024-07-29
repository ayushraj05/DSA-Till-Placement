//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    
    int r;
    int c;
    
    bool valid(int i , int j){
        
        return i>=0 && i<r && j>=0 && j<c;
    }

    int helpaterp(vector<vector<int>> hospital)
    {
        //code here;
        r = hospital.size();
        c = hospital[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i =0; i<r;i++){
            for(int j =0 ;j <c; j++){
                if(hospital[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int timer = 0;
        while(!q.empty()){
            timer++;
            int currPatient = q.size();
            while(currPatient--){
                pair<int,int> temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                
                for(int k = 0; k<4;k++){
                    
                    if(valid(i+row[k], j+ col[k]) && hospital[i+row[k]][j+col[k]] == 1){
                        hospital[i+row[k]][j+col[k]] = 2;
                        q.push({i+row[k],j+col[k]});
                    }
                }
                
            }
           
            
        }
        
        for(int i =0;i<r;i++){
            for(int j =0; j<c;j++){
                if(hospital[i][j] == 1){
                    return -1;
                }
            }
        }
        return timer-1;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends