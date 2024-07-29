# Replace 'O' with 'X' Surrounded Regions

This repository contains a C++ implementation to replace all 'O's in a given matrix that are not surrounded by 'X' with 'X'. The algorithm uses a Breadth-First Search (BFS) approach to identify and protect regions that should not be converted.

## Approach

The code uses a BFS-based method to mark 'O' regions connected to the borders:

1. **Initialization**:
   - Dimensions of the matrix (`r` and `c`) are determined.
   - Directions arrays `row` and `col` are used to explore all four possible directions (up, down, left, right).

2. **BFS Traversal from Borders**:
   - For each 'O' on the border of the matrix, a BFS traversal is initiated.
   - During traversal, all connected 'O' cells are marked as visited.
   
3. **Converting Unprotected 'O's**:
   - After the BFS traversal from borders, all 'O' cells that are not visited are converted to 'X'.

## Edge Cases

- The matrix might be empty.
- The matrix might contain only 'X's.
- The matrix might contain only 'O's.

## Time Complexity

- **Time Complexity**: \(O(N \times M)\)
  - Each cell is processed once in the BFS traversal.

## Space Complexity

- **Space Complexity**: \(O(N \times M)\)
  - The queue used for BFS and the visited matrix both use space proportional to the number of cells.

## Functions

- **valid**: Utility function to check if a cell is within the matrix bounds.
- **bfs**: Helper function to perform BFS traversal and mark connected 'O' cells.
- **fill**: Main function to replace surrounded 'O' regions with 'X'.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, dimensions of the matrix, and the matrix itself, and calls the `fill` function to get the updated matrix. The result is printed for each test case.
