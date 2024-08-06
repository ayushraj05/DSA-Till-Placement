# Dijkstra's Algorithm Implementation

This repository contains a C++ implementation of Dijkstra's algorithm to find the shortest distance of all vertices from a source vertex in a graph.

## Problem Description

Given a graph represented by an adjacency list, the goal is to find the shortest distance from a source vertex `S` to all other vertices in the graph.

## Approach

1. **Initialization**:
   - Create a distance vector `dis` initialized to `INT_MAX` for all vertices except the source vertex `S`, which is initialized to 0.
   - Create a visited vector `vis` initialized to `0` for all vertices.
   - Use a priority queue `p` to select the next vertex to process based on the shortest known distance.

2. **Processing**:
   - Continuously extract the vertex with the smallest known distance from the priority queue.
   - Mark this vertex as visited.
   - Relax the edges of this vertex by updating the shortest known distance to its neighbors.
   - Push the updated distances and corresponding vertices back into the priority queue.

3. **Output**:
   - After processing all vertices, the distance vector `dis` contains the shortest distances from the source vertex `S` to all other vertices.

## Functions

- **dijkstra**: Main function to execute Dijkstra's algorithm and return the shortest distance vector.

## Time Complexity

- **Time Complexity**: \(O(E \log V)\), where \(E\) is the number of edges and \(V\) is the number of vertices. This is due to the priority queue operations.

## Space Complexity

- **Space Complexity**: \(O(V + E)\), for storing the graph representation and auxiliary data structures.

## Usage

The `main` function demonstrates how to use the `dijkstra` function. It reads the number of test cases, the number of vertices `V` and edges `E` for each test case, and the edges of the graph. It then calls the `dijkstra` function and prints the shortest distances from the source vertex.

```cpp
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
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
        p.push({0,s});
        
        // select a node which is not yet explored and whose distance value is minimum
        while(!p.empty()) {
            int node = p.top().second;
            p.pop();
            if(vis[node])
            continue;
        
            vis[node] =1;
            
            //relax the edges;
            
            for(int j=0 ;j <adj[node].size();j++){
                int neighbour = adj[node][j][0];
                int weight = adj[node][j][1];
                if(!vis[neighbour] && (dis[node] + weight < dis[neighbour])){
                    dis[neighbour] = dis[node] + weight;
                    p.push({dis[neighbour],neighbour});
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
