# Number of Provinces

This repository contains a C++ implementation to find the number of provinces in an undirected graph. A province is defined as a group of directly or indirectly connected cities and no other cities outside of the group.

## Approach

The code uses a Breadth-First Search (BFS) approach to count the number of connected components (provinces) in the given adjacency matrix representation of a graph.

1. **Initialization**:
   - The number of vertices (`V`) is determined.
   - A visited vector (`vis`) is initialized to keep track of visited nodes.
   - The BFS function is defined to traverse the graph starting from a given node.

2. **BFS Traversal**:
   - For each unvisited node, a BFS traversal is performed to mark all reachable nodes as visited.
   - A queue is used to facilitate the BFS traversal.

3. **Counting Provinces**:
   - For each node, if it is unvisited, a new BFS traversal is initiated, and the province count is incremented.
   - The process continues until all nodes have been visited.

## Edge Cases

- The graph might be empty.
- The graph might have no connections, meaning each node is its own province.
- The graph might be fully connected, meaning there is only one province.

## Time Complexity

- **Time Complexity**: \(O(V^2)\)
  - Each cell in the adjacency matrix is processed once.

## Space Complexity

- **Space Complexity**: \(O(V)\)
  - The queue used for BFS and the visited vector both use space proportional to the number of vertices.

## Functions

- **numProvinces**: Main function to find the number of provinces. It performs BFS traversal from each unvisited node to count the number of connected components.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, the number of vertices, and the adjacency matrix, and calls the `numProvinces` function to get the result. The result is printed for each test case.
