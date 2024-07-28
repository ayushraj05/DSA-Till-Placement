#include<iostream>
#include <vector>
class Solution {
public:
    bool check(int node,vector<vector<int>> &adj, vector<int> &color){
        for(int i =0 ; i<adj[node].size();i++){
            if(color[adj[node][i]] == -1){
                color[adj[node][i]] = (color[node]+1)%2;
                if(!check(adj[node][i], adj,color))
                return 0;
            }
            else{
                if(color[adj[node][i]] == color[node]){
                    return 0;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V,-1);
	    
	    for(int i =0 ;i <V;i++){
	        if(color[i] == -1){
	            color[i] = 0;
	            if(!check(i,adj,color))
	            return false;
	        }
	    }
	    return true;
    }
};

int main(){
    return 0;
}