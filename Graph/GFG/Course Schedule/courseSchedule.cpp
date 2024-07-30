//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) 
    {
        // Create an adjacency list
        vector<vector<int>> adj(N);
        vector<int> indeg(N, 0);
        
        // Fill the adjacency list and indegree array
        for (int i = 0; i < P; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        // Push all nodes with zero indegree into the queue
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        vector<int> ans;
        
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            
            // Decrease the indegree of its connected nodes
            for (int neighbor : adj[temp]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if(N == ans.size())
        return ans;
        
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends