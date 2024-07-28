# Bipartite Graph Check

This repository contains a C++ implementation for checking if a graph is bipartite using Depth-First Search (DFS).

## Approach

The code uses a DFS-based method to check if a given graph is bipartite:

1. **Coloring Nodes**:
   - A `color` array is initialized to keep track of the color assigned to each node (-1 indicates uncolored).

2. **DFS Traversal**:
   - For each uncolored node, a DFS traversal is initiated.
   - During traversal, each node is assigned a color (0 or 1).
   - The adjacent nodes are assigned the opposite color. If an adjacent node has the same color as the current node, the graph is not bipartite.

3. **Check Bipartiteness**:
   - The `check` function performs the DFS traversal and color assignment.
   - The `isBipartite` function iterates through all vertices and checks each component using the `check` function.

## Edge Cases

- The graph might be disconnected, so the algorithm checks each component of the graph.
- Graph with no edges (single node or multiple nodes with no edges) is trivially bipartite.
- Self-loops and parallel edges are not explicitly handled and are assumed to be absent.

## Time Complexity

- **Time Complexity**: \(O(V + E)\)
  - Each vertex and edge is processed once in the DFS traversal.

## Space Complexity

- **Space Complexity**: \(O(V)\)
  - The `color` array and the recursive call stack use space proportional to the number of vertices.

## Functions

- **check**: Recursive helper function for DFS traversal and color assignment.
- **isBipartite**: Main function to check if the graph is bipartite.

## Usage

The `isBipartite` function takes the adjacency list representation of the graph and returns `true` if the graph is bipartite, otherwise `false`.
