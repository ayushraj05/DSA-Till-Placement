//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    // will use kans algo to solve this first we will find oput the topological sort
	    // if the number fo the node in the topo sort is not equal to N so there is a cycle
	    // hence return false for that case;
	    
	    // Create an adjacency list
        vector<vector<int>> adj(N);
        vector<int> indeg(N, 0);
        
        // Fill the adjacency list and indegree array
        for (int i = 0; i < P; i++) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            indeg[prerequisites[i].first]++;
        }
        
        queue<int> q;
        // Push all nodes with zero indegree into the queue
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            count++;
            
            // Decrease the indegree of its connected nodes
            for (int neighbor : adj[temp]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If count is equal to N, it means we were able to complete topological sorting
        return count == N;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends