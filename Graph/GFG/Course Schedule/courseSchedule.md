# Course Order Finder

This repository contains a C++ implementation to find a valid order to complete all courses given their prerequisites. This is a typical topological sorting problem, often encountered in graph theory.

## Problem Description

Given `N` courses and `P` prerequisite pairs, where each pair indicates that the second course must be completed before the first course, determine a valid order in which all courses can be completed. If no such order exists, return an empty list.

## Approach

The solution uses Kahn's Algorithm for topological sorting. If the topological sorting can include all `N` nodes, it means there is no cycle in the graph, and hence, a valid order exists to complete all courses. If there is a cycle, it is not possible to complete all courses and an empty list is returned.

1. **Graph Representation**:
   - Use an adjacency list to represent the graph.
   - Use an indegree array to keep track of the number of incoming edges for each node.

2. **Initialization**:
   - Populate the adjacency list and the indegree array using the prerequisite pairs.

3. **Topological Sort Using Kahn's Algorithm**:
   - Initialize a queue with all nodes having zero indegree.
   - Process each node by removing it from the queue, reducing the indegree of its neighbors, adding any neighbor with zero indegree to the queue, and adding the node to the result list.
   - Keep a count of the number of nodes processed.

4. **Check Completion**:
   - If the size of the result list equals `N`, it means a valid order exists to complete all courses. Otherwise, it indicates a cycle, making it impossible to complete all courses, and an empty list is returned.

## Functions

- **findOrder**: Main function to determine a valid order to complete all courses given the prerequisites.

## Edge Cases

- There are no prerequisites.
- All courses are interdependent, forming a single large cycle.
- The prerequisites form a complex graph with multiple interdependencies and cycles.

## Time Complexity

- **Time Complexity**: \(O(N + P)\)
  - Each node and edge is processed once.

## Space Complexity

- **Space Complexity**: \(O(N + P)\)
  - Adjacency list and indegree array use space proportional to the number of nodes and edges.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, the number of courses, the number of prerequisites, and the prerequisite pairs, and calls the `findOrder` function to get the result. The result is printed for each test case. If no valid order is found, it prints "No Ordering Possible".

```cpp
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
