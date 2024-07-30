# Course Schedule with Minimum Time Calculation

This repository contains a C++ implementation to determine the minimum time required to complete all courses given the prerequisites and individual course times. The algorithm leverages topological sorting using Kahn's algorithm to achieve this.

## Problem Description

Given `n` courses, a list of prerequisite relations where `relations[i] = [a, b]` indicates that course `a` must be taken before course `b`, and a list `time` where `time[i]` is the time required to complete the `i-th` course, determine the minimum total time required to complete all courses.

## Approach

The solution uses graph theory to model the problem as a directed acyclic graph (DAG) where nodes represent courses and directed edges represent prerequisite relations. The algorithm uses Kahn's algorithm for topological sorting to compute the minimum time required.

1. **Graph Representation**:
   - Use an adjacency list to represent the graph of course dependencies.
   - Use an indegree array to keep track of the number of incoming edges for each course.

2. **Initialization**:
   - Populate the adjacency list and the indegree array using the given relations.
   - Initialize a queue with all courses having zero indegree.
   - Initialize a total time array to track the cumulative time to complete each course.

3. **Topological Sort Using Kahn's Algorithm**:
   - Process each course by removing it from the queue, updating the total time to complete its dependent courses, and adding any dependent course with zero indegree to the queue.

4. **Calculate Minimum Time**:
   - The minimum time required to complete all courses is the maximum value in the total time array after processing all courses.

## Functions

- **minimumTime**: Main function to determine the minimum time required to complete all courses given the number of courses, the prerequisite relations, and the individual course times.

## Edge Cases

- No prerequisites (all courses are independent).
- Circular dependencies (should not be present as per problem constraints).
- All courses have the same or varying completion times.

## Time Complexity

- **Time Complexity**: \(O(N + E)\), where \(N\) is the number of courses and \(E\) is the number of prerequisite relations. Each node and edge are processed once.

## Space Complexity

- **Space Complexity**: \(O(N + E)\), where \(N\) is the number of courses and \(E\) is the number of prerequisite relations. This is used for storing the adjacency list and the indegree array.

## Usage

The `main` function is provided for testing purposes. It initializes the necessary variables, reads input values, and calls the `minimumTime` function to get the result. The result is then printed.

```cpp
static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // Kahn's algorithm to solve this;

        // Create adjacency list
        vector<vector<int>> adj(n);
        for (const auto& relation : relations) {
            adj[relation[0] - 1].push_back(relation[1] - 1);
        }

        // Calculate in-degree of each node
        vector<int> inDeg(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int node : adj[i]) {
                inDeg[node]++;
            }
        }

        // Initialize queue with all nodes having 0 in-degree
        queue<int> q;
        vector<int> totalTime(n, 0);
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
                totalTime[i] = time[i];
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans = max(ans, totalTime[node]);

            for (int neighbor : adj[node]) {
                inDeg[neighbor]--;
                if (inDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
                totalTime[neighbor] = max(totalTime[neighbor], totalTime[node] + time[neighbor]);
            }
        }

        return ans;
    }
};
