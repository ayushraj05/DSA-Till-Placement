# Shortest Path in an Undirected Graph

This repository contains a C++ implementation to determine the shortest path from a source node to all other nodes in an undirected graph using Breadth-First Search (BFS).

## Problem Description

Given an undirected graph with `N` nodes and `M` edges, find the shortest path from a given source node `src` to all other nodes. The graph is represented as a list of edges, and the output should be a list of distances from the source node to each node. If a node is not reachable from the source, its distance should be `-1`.

## Approach

The solution uses Breadth-First Search (BFS) to find the shortest path in an unweighted graph. BFS is suitable for this task as it explores all nodes at the present depth level before moving on to nodes at the next depth level, ensuring the shortest path in an unweighted graph.

1. **Graph Representation**:
   - Use an adjacency list to represent the graph of nodes and edges.

2. **BFS Initialization**:
   - Start BFS from the source node.
   - Initialize the distance to the source node as `0` and all other nodes as `-1`.

3. **BFS Execution**:
   - Use a queue to explore each node level by level.
   - For each node, update the distance for its neighbors if they haven't been visited yet.

## Functions

- **bfs**: Helper function to perform BFS and update distances from the source node.
- **shortestPath**: Main function to determine the shortest path from the source node to all other nodes given the number of nodes, edges, and the source node.

## Edge Cases

- Disconnected nodes (should return `-1` for unreachable nodes).
- Single node graph (distance to itself is `0`).
- No edges (distance to all other nodes should be `-1` except the source node).

## Time Complexity

- **Time Complexity**: \(O(N + M)\), where \(N\) is the number of nodes and \(M\) is the number of edges. Each node and edge are processed once.

## Space Complexity

- **Space Complexity**: \(O(N + M)\), where \(N\) is the number of nodes and \(M\) is the number of edges. This is used for storing the adjacency list, visited array, and distance array.

## Usage

The `main` function is provided for testing purposes. It initializes the necessary variables, reads input values, and calls the `shortestPath` function to get the result. The result is then printed.

```cpp
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    void bfs(int node, vector<vector<int>> &edges, vector<int> &vis, vector<int> &dis) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        dis[node] = 0;

        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int i = 0; i < edges[temp].size(); i++) {
                if (!vis[edges[temp][i]]) {
                    q.push(edges[temp][i]);
                    vis[edges[temp][i]] = 1;
                    dis[edges[temp][i]] = dis[temp] + 1;
                }
            }
        }
    }

    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<int> vis(N, 0);
        vector<int> dis(N, -1);
        vector<vector<int>> adj(N);

        for (int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        bfs(src, adj, vis, dis);
        return dis;
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x; 
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; 
        cin >> src;

        Solution obj;
        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
