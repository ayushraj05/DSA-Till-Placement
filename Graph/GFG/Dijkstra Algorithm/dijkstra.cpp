//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int> vis(V,0);
        vector<int> dis(V,INT_MAX);
        
        dis[s]= 0;
        
        // select a node which is not yet explored and whose distance value is minimum
        
        int count = V;
        
        while(count--){
            int node = -1;
            int value = INT_MAX;
            
            for(int i =0 ;i<V;i++){
                if(!vis[i] && value > dis[i]){
                    node = i;
                    value = dis[i];
                }
            }
            
            vis[node] =1;
            
            //relax the edges;
            
            for(int j=0 ;j <adj[node].size();j++){
                int neighbour = adj[node][j][0];
                int weight = adj[node][j][1];
                if(!vis[neighbour] && (dis[node] + weight < dis[neighbour])){
                    dis[neighbour] = dis[node] + weight;
                }
            }
        }
        
        return dis;
    }   
    
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends