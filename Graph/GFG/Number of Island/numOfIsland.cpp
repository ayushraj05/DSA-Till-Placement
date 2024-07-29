//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    int row[8] = {-1,1,0,0,1,1,-1,-1};
    int col[8] = {0,0,-1,1,1,-1,1,-1};
    
    int r; 
    int c;
    
    bool valid(int i, int j){
        return i>=0 && i<r && j>=0 && j<c ;
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid ){
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()){
            int tempI = q.front().first;
            int tempJ = q.front().second;
            q.pop();
            
            for(int k =0; k<8;k++){
                if(valid(tempI+row[k], tempJ+ col[k]) && grid[tempI+row[k]][tempJ+col[k]] == '1'){
                    grid[tempI+row[k]][tempJ+col[k]] = '2';
                    q.push({tempI+row[k], tempJ + col[k]});
                }
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int island = 0;
        r = grid.size();
        c = grid[0].size();
        
        for(int i =0; i<r;i++){
            for(int j =0; j<c;j++){
                if(grid[i][j] == '1'){
                    bfs(i,j,grid);
                    island++;
                }
            }
        }
        return island;
    }
};

//{ Driver Code Starts.
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
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends