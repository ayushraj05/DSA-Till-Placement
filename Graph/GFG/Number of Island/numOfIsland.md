# Counting the Number of Islands

This repository contains a C++ implementation for counting the number of islands in a grid using a Breadth-First Search (BFS) approach.

## Approach

The code uses a BFS-based method to count the number of islands in a grid:

1. **Initialization**:
   - Dimensions of the grid (`r` and `c`) are determined.
   - Directions arrays `row` and `col` are used to explore all eight possible directions (up, down, left, right, and four diagonals).

2. **BFS Traversal**:
   - For each cell containing a `1` (land), a BFS traversal is initiated.
   - During traversal, each land cell is marked as visited by changing its value to `2`.
   - All connected land cells are visited and marked during the BFS.

3. **Counting Islands**:
   - Each BFS traversal that starts from a new land cell represents a new island.
   - The number of such BFS traversals is counted to determine the total number of islands.

## Edge Cases

- The grid might be empty, or contain no land cells.
- The grid might be fully land or fully water.
- The grid might contain isolated land cells.

## Time Complexity

- **Time Complexity**: \(O(R \times C)\)
  - Each cell is processed once in the BFS traversal.

## Space Complexity

- **Space Complexity**: \(O(R \times C)\)
  - The queue used for BFS can contain all cells in the worst case.

## Functions

- **valid**: Utility function to check if a cell is within the grid bounds.
- **bfs**: Helper function to perform BFS traversal and mark connected land cells.
- **numIslands**: Main function to count the number of islands in the grid.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, dimensions of the grid, and the grid itself, and calls the `numIslands` function to get the number of islands. The result is printed for each test case.
