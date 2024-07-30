# Alien Dictionary Order Finder

This repository contains a C++ implementation to determine the order of characters in an alien language given a sorted dictionary of words from that language. The goal is to find the correct order of characters (i.e., the alphabet) in the alien language.

## Problem Description

Given a dictionary of `N` words and the number of unique characters `K` in the alien language, determine a valid order of characters that satisfies the given dictionary order. 

## Approach

The solution uses graph theory to determine the character order. Each character is treated as a node, and directed edges represent the order between characters inferred from the given words. The solution uses Kahn's algorithm for topological sorting to find the correct order.

1. **Graph Representation**:
   - Use an adjacency list to represent the graph of character dependencies.
   - Use an indegree array to keep track of the number of incoming edges for each character.

2. **Initialization**:
   - Populate the adjacency list and the indegree array using the words in the dictionary by comparing adjacent words and finding the first differing character.

3. **Topological Sort Using Kahn's Algorithm**:
   - Initialize a queue with all characters having zero indegree.
   - Process each character by removing it from the queue, adding it to the result string, reducing the indegree of its neighbors, and adding any neighbor with zero indegree to the queue.
   - Keep track of the number of characters processed.

4. **Check Completion**:
   - If the result string contains all `K` characters, it means we were able to determine a valid order. Otherwise, return an empty string.

## Functions

- **findOrder**: Main function to determine the order of characters in the alien language given the dictionary.

## Edge Cases

- The dictionary is empty.
- All words are the same.
- The dictionary contains words with a common prefix.
- The dictionary has cycles, making it impossible to determine a valid order.

## Time Complexity

- **Time Complexity**: \(O(N \cdot L + K)\), where \(N\) is the number of words, \(L\) is the average length of the words, and \(K\) is the number of unique characters.
  - Each word comparison takes \(O(L)\) time, and processing the graph takes \(O(K)\) time.

## Space Complexity

- **Space Complexity**: \(O(K + E)\), where \(K\) is the number of unique characters and \(E\) is the number of edges in the graph.

## Usage

The `main` function is provided for testing purposes. It reads the number of test cases, the number of words, the number of unique characters, and the words in the dictionary, and calls the `findOrder` function to get the result. The result is checked for correctness using a custom sorting function.

```cpp
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
