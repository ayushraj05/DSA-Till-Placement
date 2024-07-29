# Minimum Time to Rot All Oranges

This repository contains a C++ implementation to find the minimum time required to rot all fresh oranges in a grid. The algorithm uses a Breadth-First Search (BFS) approach to simulate the rotting process.

## Approach

The code uses a BFS-based method to simulate the rotting of fresh oranges:

1. **Initialization**:
   - Dimensions of the grid (`n` and `m`) are determined.
   - Directions arrays `drow` and `dcol` are used to explore all four possible directions (up, down, left, right).
   - A queue is initialized with all the rotten oranges along with their timestamp (starting from 0).
   - A visited matrix is used to keep track of visited cells.

2. **BFS Traversal**:
   - For each rotten orange in the queue, its neighboring cells are checked.
   - If a neighboring cell contains a fresh orange, it is marked as rotten, and the time is incremented by 1.
   - This process continues until the queue is empty.

3. **Checking for Remaining Fresh Oranges**:
   - After the BFS traversal, the grid is checked for any remaining fresh oranges.
   - If any fresh oranges are found, the function returns -1.
   - Otherwise, it returns the maximum time taken to rot all oranges.

## Edge Cases

- The grid might be empty.
- The grid might contain only rotten oranges.
- The grid might contain only fresh oranges.

## Time Complexity

- **Time Complexity**: \(O(N \times M)\)
  - Each cell is processed once in the BFS traversal.

## Space Complexity

- **Space Complexity**: \(O(N \times M)\)
  - The queue used for BFS and the visited matrix both use space proportional to the number of cells.

## Functions

- **orangesRotting**: Main function to find the minimum time required to rot all oranges. It performs BFS traversal to simulate the rotting process and returns the time taken or -1 if not all oranges can rot.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, dimensions of the grid, and the grid itself, and calls the `orangesRotting` function to get the result. The result is printed for each test case.

```cpp
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
