# X Total Shapes

This repository contains a C++ implementation to find the number of 'X' shapes in a 2D grid. An 'X' shape is defined as a group of connected 'X' cells (horizontally or vertically connected).

## Approach

The code uses a Breadth-First Search (BFS) approach to count the number of connected components ('X' shapes) in the given 2D grid.

1. **Initialization**:
   - The dimensions of the grid (`n` and `m`) are determined.
   - A visited matrix (`vis`) is initialized to keep track of visited cells.
   - The BFS function is defined to traverse the grid starting from a given cell.

2. **BFS Traversal**:
   - For each unvisited 'X' cell, a BFS traversal is performed to mark all reachable 'X' cells as visited.
   - A queue is used to facilitate the BFS traversal.

3. **Counting X Shapes**:
   - For each cell, if it is an unvisited 'X', a new BFS traversal is initiated, and the shape count is incremented.
   - The process continues until all 'X' cells have been visited.

## Edge Cases

- The grid might be empty.
- The grid might have no 'X' cells.
- The grid might be fully filled with 'X' cells, forming one large shape.

## Time Complexity

- **Time Complexity**: \(O(n \times m)\)
  - Each cell in the grid is processed once.

## Space Complexity

- **Space Complexity**: \(O(n \times m)\)
  - The queue used for BFS and the visited matrix both use space proportional to the number of cells in the grid.

## Functions

- **xShape**: Main function to find the number of 'X' shapes. It performs BFS traversal from each unvisited 'X' cell to count the number of connected components.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, the dimensions of the grid, and the grid itself, and calls the `xShape` function to get the result. The result is printed for each test case.

```cpp
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.xShape(grid);
        cout << ans << '\n';
    }
    return 0;
}
