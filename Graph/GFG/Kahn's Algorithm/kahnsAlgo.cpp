//{ Driver Code Starts
// #include <bits/stdc++.h>
#include <iostream>
#include<queue>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<int> InDegree(V,0);
	    
	    for(int i =0 ;i <V;i++){
	        for(int j =0; j<adj[i].size();j++){
	            InDegree[adj[i][j]]++;
	        }
	    }
	    
	    //push all the node of zero indegree intpo the queue
	    
	    queue<int> q;
	    
	    for(int i =0 ;i<V;i++){
	        if(!InDegree[i])
	            q.push(i);
	    }
	        while(!q.empty()){
	            int node = q.front();
	            q.pop();
	            ans.push_back(node);
	            
	            // neighbour indegree should dcrease by 1
	            
	            for(int i =0 ;i<adj[node].size();i++){
	                InDegree[adj[node][i]]--;
	                if(InDegree[adj[node][i]] == 0){
	                    q.push(adj[node][i]);
	                }
	            }
	        }
	    
	    return ans;
	   
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
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
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends