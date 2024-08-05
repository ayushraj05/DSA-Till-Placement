# Dijkstra's Algorithm for Shortest Path

This repository contains a C++ implementation of Dijkstra's algorithm to find the shortest distance from a source vertex to all other vertices in a graph. The graph is represented using an adjacency list.

## Problem Description

Given a graph with `V` vertices and `E` edges, and a source vertex `S`, this program calculates the shortest distance from `S` to every other vertex using Dijkstra's algorithm. The graph is undirected and weighted.

## Approach

1. **Initialize Data Structures**:
   - Use a vector `dis` to store the shortest distance from the source vertex `S` to each vertex. Initialize all distances to `INT_MAX`, except the source vertex which is set to `0`.
   - Use a vector `vis` to keep track of visited vertices.

2. **Dijkstra's Algorithm**:
   - Repeatedly select the vertex with the minimum distance that has not been visited yet.
   - Update the distances of its neighboring vertices.
   - Mark the selected vertex as visited.

3. **Output**:
   - Return the vector `dis` containing the shortest distances from the source vertex to all other vertices.

## Functions

- **dijkstra**: Main function to compute the shortest distances using Dijkstra's algorithm.

## Time Complexity

- **Time Complexity**: \(O(V^2)\), where \(V\) is the number of vertices. This is due to the nested loops for selecting the minimum distance vertex and updating the distances of neighboring vertices.

## Space Complexity

- **Space Complexity**: \(O(V)\), for storing distances and visited vertices.

## Usage

The `main` function demonstrates how to use the `dijkstra` function. It initializes the input graph, specifies the source vertex, and calls the `dijkstra` function to get the result.

```cpp
class Solution
{
public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        vector<int> vis(V,0);
        vector<int> dis(V,INT_MAX);
        
        dis[s]= 0;
        
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
