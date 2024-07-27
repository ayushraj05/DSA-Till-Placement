# Topological Sorting of a Directed Graph

This repository contains a C++ implementation for performing topological sorting on a directed graph using Depth-First Search (DFS).

## Approach

The code uses a DFS-based method to perform topological sorting:

1. **DFS Traversal**:
   - A `visited` array is initialized to keep track of visited nodes.
   - A stack is used to store the topological order of nodes.

2. **Topological Sorting**:
   - For each unvisited node, a DFS traversal is initiated using the `topoHelp` function.
   - During traversal, each node is pushed onto the stack after all its neighbors are visited.
   - The `topoSort` function collects nodes from the stack to form the final topologically sorted list.

## Edge Cases

- The graph might be disconnected, so the algorithm checks each component of the graph.
- Graph with no edges (single node or multiple nodes with no edges) will return the nodes in arbitrary order.
- Self-loops and cycles are not handled explicitly, and the function assumes the graph is a Directed Acyclic Graph (DAG).

## Time Complexity

- **Time Complexity**: \(O(V + E)\)
  - Each vertex and edge is processed once in the DFS traversal.

## Space Complexity

- **Space Complexity**: \(O(V)\)
  - The `visited` array and the DFS stack use space proportional to the number of vertices.

## Functions

- **topoHelp**: Recursive helper function for DFS traversal.
- **topoSort**: Main function to perform topological sorting and return the sorted list.
- **check**: Utility function to verify if the topological sort is correct.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, vertices, and edges for each test case, constructs the adjacency list, and calls the `topoSort` function to get the topological order. The `check` function verifies the correctness of the topological order.
