# Spreading Infection in a Hospital

This repository contains a C++ implementation for simulating the spread of infection in a hospital and determining the time required to infect all patients.

## Approach

The code uses a Breadth-First Search (BFS) approach to simulate the spread of infection:

1. **Initialization**:
   - Dimensions of the hospital grid (`r` and `c`) are determined.
   - All initially infected patients (represented by `2` in the grid) are added to a queue.

2. **BFS Traversal**:
   - For each infected patient, adjacent cells are checked:
     - If an adjacent cell contains a healthy patient (`1`), it is infected and added to the queue.
   - The timer is incremented after processing each level of the BFS.

3. **Checking Complete Infection**:
   - After the BFS traversal, the grid is checked for any remaining healthy patients. If any are found, the function returns `-1` indicating not all patients could be infected.

4. **Return Result**:
   - The function returns the total time taken to infect all patients, adjusted by subtracting one to account for the initial state.

## Edge Cases

- The grid might be empty, or contain no initially infected patients.
- The grid might already be fully infected at the start.
- There might be isolated healthy patients that cannot be infected.

## Time Complexity

- **Time Complexity**: \(O(R \times C)\)
  - Each cell is processed once in the BFS traversal.

## Space Complexity

- **Space Complexity**: \(O(R \times C)\)
  - The queue used for BFS can contain all cells in the worst case.

## Functions

- **valid**: Utility function to check if a cell is within the grid bounds.
- **helpaterp**: Main function to simulate the infection spread and return the time taken to infect all patients.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, dimensions of the hospital grid, and the grid itself, and calls the `helpaterp` function to get the time taken to infect all patients. The result is printed for each test case.
