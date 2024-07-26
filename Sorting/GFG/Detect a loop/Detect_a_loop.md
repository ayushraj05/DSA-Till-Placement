# Cycle Detection in an Undirected Graph

This repository contains a C++ implementation for detecting cycles in an undirected graph using a breadth-first search (BFS) approach.

## Approach

The code uses a BFS-based method to detect cycles in an undirected graph:

1. **Initialization**:
   - A `visited` array is initialized to keep track of visited nodes.

2. **BFS Traversal**:
   - For each unvisited node, a BFS traversal is initiated.
   - During traversal, each node is checked against its neighbors:
     - If a neighbor is unvisited, it is added to the queue.
     - If a neighbor is visited and is not the parent of the current node, a cycle is detected.

3. **Cycle Detection**:
   - The `detect` function returns `true` if a cycle is found during BFS traversal.
   - The `isCycle` function iterates through all vertices and checks for cycles using the `detect` function.

## Edge Cases

- The graph might be disconnected, so the algorithm checks each component of the graph.
- Graph with no edges (single node or multiple nodes with no edges) will not have a cycle.
- Self-loops and parallel edges are not explicitly handled and are assumed to be absent.

## Time Complexity

- **Time Complexity**: \(O(V + E)\)
  - Each vertex and edge is processed once in the BFS traversal.

## Space Complexity

- **Space Complexity**: \(O(V)\)
  - The `visited` array and the BFS queue use space proportional to the number of vertices.
