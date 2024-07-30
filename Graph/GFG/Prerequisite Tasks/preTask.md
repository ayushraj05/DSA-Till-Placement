# Course Schedule Checker

This repository contains a C++ implementation to check if it's possible to complete all courses given their prerequisites. The problem is a typical topological sorting problem, often encountered in graph theory.

## Problem Description

Given `N` courses and `P` prerequisite pairs, where each pair indicates that the second course must be completed before the first course, determine if it is possible to complete all courses.

## Approach

The solution uses Kahn's Algorithm for topological sorting. If the topological sorting can include all `N` nodes, it means there is no cycle in the graph, and hence, all courses can be completed. If there is a cycle, it is not possible to complete all courses.

1. **Graph Representation**:
   - Use an adjacency list to represent the graph.
   - Use an indegree array to keep track of the number of incoming edges for each node.

2. **Initialization**:
   - Populate the adjacency list and the indegree array using the prerequisite pairs.

3. **Topological Sort Using Kahn's Algorithm**:
   - Initialize a queue with all nodes having zero indegree.
   - Process each node by removing it from the queue, reducing the indegree of its neighbors, and adding any neighbor with zero indegree to the queue.
   - Keep a count of the number of nodes processed.

4. **Check Completion**:
   - If the count of processed nodes equals `N`, it means all courses can be completed. Otherwise, it indicates a cycle, making it impossible to complete all courses.

## Functions

- **isPossible**: Main function to determine if it is possible to complete all courses given the prerequisites.

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

The `main` function is provided for testing purposes. It reads the number of test cases, the number of courses, the number of prerequisites, and the prerequisite pairs, and calls the `isPossible` function to get the result. The result is printed for each test case.

```cpp
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
