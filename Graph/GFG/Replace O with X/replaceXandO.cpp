//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int r;
    int c;

    bool valid(int i, int j){
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    
    void bfs(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &visited) {
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newX = x + row[k];
                int newY = y + col[k];

                if (valid(newX, newY) && mat[newX][newY] == 'O' && !visited[newX][newY]) {
                    visited[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        // will travel across the border of the matrix and apply bfs traversal from all the o's 
        // we encounter from there and mark them visited;
        // after that we will chande all the O's which are on visited to X
        // simple :)
        
        r = mat.size();
        c = mat[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        
    // -------------------x--------------------------------
    // Traverse the first and last row
        for (int j = 0; j < c; ++j) {
            if (mat[0][j] == 'O' && !visited[0][j]) {
                bfs(0, j, mat, visited);
            }
            if (mat[r - 1][j] == 'O' && !visited[r - 1][j]) {
                bfs(r - 1, j, mat, visited);
            }
        }

        // Traverse the first and last column
        for (int i = 0; i < r; ++i) {
            if (mat[i][0] == 'O' && !visited[i][0]) {
                bfs(i, 0, mat, visited);
            }
            if (mat[i][c - 1] == 'O' && !visited[i][c - 1]) {
                bfs(i, c - 1, mat, visited);
            }
        }
    
    // -------------------x--------------------------------  
        
        
        
        for(int i =0 ;i<r;i++){
            for(int j =0 ;j<c;j++){
                if(!visited[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends