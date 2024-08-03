# Shortest Path in a Directed Acyclic Graph (DAG)

This repository contains a C++ implementation to find the shortest path in a Directed Acyclic Graph (DAG) using topological sorting.

## Problem Description

Given a weighted directed acyclic graph with `N` nodes and `M` edges, the task is to find the shortest path from the source node `0` to all other nodes. If a node is unreachable from the source, the distance to that node should be `-1`.

## Approach

The solution uses Depth-First Search (DFS) to perform topological sorting and then calculates the shortest path from the source node using the topologically sorted order.

1. **Create Adjacency List**:
   - Represent the graph using an adjacency list where each node points to its neighbors along with the edge weights.

2. **Topological Sorting**:
   - Use DFS to perform topological sorting. Nodes are pushed onto a stack in the order of their finishing times.

3. **Initialize Distance Array**:
   - Initialize the distance array with `INT_MAX` for all nodes except the source node, which is set to `0`.

4. **Relax Edges According to Topological Order**:
   - Pop nodes from the stack and relax the edges. Update the shortest distance to each neighbor.

5. **Handle Unreachable Nodes**:
   - Convert all `INT_MAX` values in the distance array to `-1` to indicate unreachable nodes.

## Functions

- **dfs**: Recursive function to perform DFS and push nodes onto the stack in topological order.
- **shortestPath**: Main function to calculate the shortest path using topological sorting.

## Time Complexity

- **Time Complexity**: \(O(N + M)\), where \(N\) is the number of nodes and \(M\) is the number of edges. This is because each node and edge is processed a constant number of times.

## Space Complexity

- **Space Complexity**: \(O(N + M)\), for storing the adjacency list and other auxiliary data structures.

## Usage

The `main` function demonstrates how to use the `shortestPath` function. It initializes the graph with nodes and edges, calls the `shortestPath` function, and prints the result.

```cpp

class Solution {
public:
    void dfs(int node, vector<pair<int,int>> adj[], stack<int>& s, vector<bool>& visited) {
        visited[node] = 1;
        for (int j = 0; j < adj[node].size(); j++) {
            if (!visited[adj[node][j].first]) {
                dfs(adj[node][j].first, adj, s, visited);
            }
        }
        s.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<pair<int,int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
        }

        // Topological sort using DFS
        stack<int> s1;
        vector<bool> visited(N, 0);
        dfs(0, adj, s1, visited);

        // Initialize distance array
        vector<int> ans(N, INT_MAX);
        ans[0] = 0;

        // Relax edges according to topological order
        while (!s1.empty()) {
            int node = s1.top();
            s1.pop();
            if (ans[node] != INT_MAX) {
                for (int i = 0; i < adj[node].size(); i++) {
                    int neighbour = adj[node][i].first;
                    int weight = adj[node][i].second;
                    if (ans[node] + weight < ans[neighbour]) {
                        ans[neighbour] = ans[node] + weight;
                    }
                }
            }
        }

        // Handle unreachable nodes
        for (int i = 0; i < N; i++) {
            if (ans[i] == INT_MAX) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};

