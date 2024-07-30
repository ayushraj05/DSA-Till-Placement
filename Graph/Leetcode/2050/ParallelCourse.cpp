static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // kans algo to solve this;

        // Create adjacency list
        vector<vector<int>> adj(n);
        for (const auto& relation : relations) {
            adj[relation[0] - 1].push_back(relation[1] - 1);
        }

        // Calculate in-degree of each node
        vector<int> inDeg(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int node : adj[i]) {
                inDeg[node]++;
            }
        }

        // Initialize queue with all nodes having 0 in-degree
        queue<int> q;
        vector<int> totalTime(n, 0);
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
                totalTime[i] = time[i];
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans = max(ans, totalTime[node]);

            for (int neighbor : adj[node]) {
                inDeg[neighbor]--;
                if (inDeg[neighbor] == 0) {
                    q.push(neighbor);
                }
                totalTime[neighbor] = max(totalTime[neighbor], totalTime[node] + time[neighbor]);
            }
        }

        return ans;

    }
};