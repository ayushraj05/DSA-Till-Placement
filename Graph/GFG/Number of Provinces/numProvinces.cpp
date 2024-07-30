//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void bfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] =1;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            // because this is the matrix not the adjuncy list;
            for (int i = 0; i < adj[temp].size(); i++) {
                if (adj[temp][i] == 1 && !vis[i]) {  
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int ans =0;
        vector<int> vis(V,0);
        for(int i =0 ;i <V;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends