//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void dfs(int node, vector<pair<int,int>> adj[],stack<int> &s,vector<bool> &visited){
        visited[node]=1;
        for(int j =0;j<adj[node].size();j++){
            if(!visited[adj[node][j].first]){
                dfs(adj[node][j].first,adj,s,visited);
            }
        }
        s.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        // create adjacncecy list;
        
        vector<pair<int,int>> adj[N];
        for(int i =0 ;i <M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v,weight});
        }
        
        // find topological sort using dfs and stack;
        stack <int> s1;
        vector<bool> visited(N,0);
        dfs(0,adj,s1,visited);
        
        
        // make the stack empty and update the answer vector;
        
        vector<int> ans(N,INT_MAX);
        ans[0] =0;
        
        while(!s1.empty()){
            int node = s1.top();
            s1.pop();
            
            // neigbours;
            for(int i =0; i <adj[node].size();i++){
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;
                ans[neighbour] = min(ans[neighbour],weight+ans[node]);
            }
        }
        // -1
        for(int i =0 ;i<N;i++){
            if(ans[i] == INT_MAX){
                ans[i] = -1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends