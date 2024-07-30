//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int n;
    int m;
    
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,1,-1};
    
    bool valid(int i, int j){
        return i<n && i>=0 && j<m && j>=0;
    }
    
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        vis[i][j] =1;
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k =0; k<4;k++){
                int newI = x + row[k];
                int newJ = y + col[k];
                
                if(valid(newI,newJ) && !vis[newI][newJ] && grid[newI][newJ] == 'X'){
                    vis[newI][newJ] =1;
                    q.push({newI,newJ});
                }
            }
        }
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int ans =0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        
        for(int i =0; i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 'X' && !vis[i][j]){
                    ans++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends