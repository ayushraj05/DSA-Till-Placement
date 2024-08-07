# Dijkstra's Algorithm with Path Reconstruction

This repository contains a C++ implementation of Dijkstra's algorithm to find the shortest path in a graph and reconstruct the path from the source vertex to the destination vertex.

## Problem Description

Given a graph represented by an adjacency list and a set of edges with weights, the goal is to find the shortest path from a source vertex to a destination vertex and reconstruct the path.

## Approach

1. **Initialization**:
   - Create an adjacency list `adj` to represent the graph.
   - Initialize a distance vector `dis` to `INT_MAX` for all vertices except the source vertex, which is initialized to 0.
   - Initialize a parent vector `parent` to keep track of the path.
   - Use a priority queue `p` to select the next vertex to process based on the shortest known distance.

2. **Processing**:
   - Continuously extract the vertex with the smallest known distance from the priority queue.
   - Mark this vertex as explored.
   - Relax the edges of this vertex by updating the shortest known distance to its neighbors.
   - Push the updated distances and corresponding vertices back into the priority queue.
   - Update the parent vector to reconstruct the path.

3. **Output**:
   - After processing all vertices, reconstruct the path from the source vertex to the destination vertex using the parent vector.
   - If the destination vertex is unreachable, return `-1`.
   - Otherwise, return the path and the total distance.

## Functions

- **shortestPath**: Main function to execute Dijkstra's algorithm, reconstruct the path, and return the shortest path and distance.

## Time Complexity

- **Time Complexity**: \(O(E \log V)\), where \(E\) is the number of edges and \(V\) is the number of vertices. This is due to the priority queue operations.

## Space Complexity

- **Space Complexity**: \(O(V + E)\), for storing the graph representation and auxiliary data structures.

## Usage

The `main` function demonstrates how to use the `shortestPath` function. It reads the number of test cases, the number of vertices `V` and edges `E` for each test case, and the edges of the graph. It then calls the `shortestPath` function and prints the shortest path and distance from the source vertex to the destination vertex.

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        // Code here
        //created adjency list;
        vector<pair<int,int>> adj[V+1]; // neighbour,weight
        
        for(int i=0; i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        //dijkstra algorithm;
        vector<bool> explored(V+1,0);
        vector<int> dis(V+1, INT_MAX);
        
        vector<int> parent(V+1,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>p;
        p.push({0,1});
        dis[1] =0;
        
        
        while(!p.empty()){
            int node = p.top().second;
            p.pop();
            if(explored[node]){
                continue;
            }
            explored[node]= 1;
            
            for(int j =0; j<adj[node].size();j++){
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                if(!explored[neighbour] && dis[node] + weight < dis[neighbour]){
                    dis[neighbour] = dis[node]+weight;
                    p.push({dis[neighbour],neighbour});
                    parent[neighbour] = node; // new line;
                }
                
            }
        }
        
        vector<int> path;
          // cant reach the destination;
        if(parent[V] == -1){
            path.push_back(-1);
            return path;
        }
        
        // can reach the destination;
        int dest = V;
        
        while(dest!=-1){
            path.push_back(dest);
            dest = parent[dest];
        }
        
        path.push_back(dis[V]);
        reverse(path.begin(),path.end());
        return path;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
