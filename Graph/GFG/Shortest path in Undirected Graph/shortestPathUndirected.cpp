//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void bfs(int node, vector<vector<int>> &edges,vector<int> &vis, vector<int> &dis){
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        dis[node] = 0;
        int distance = 0;
      
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int temp = q.front();
                q.pop();
                for(int i =0 ;i <edges[temp].size();i++){
                    if(!vis[edges[temp][i]]){
                        q.push(edges[temp][i]);
                        vis[edges[temp][i]] = 1;
                        dis[edges[temp][i]] = dis[temp] +1;
                    }
                }
            }
            
        }
  }
  
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> vis(N,0);
        vector<int> dis(N,-1);
        
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        bfs(src,adj,vis,dis);
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends