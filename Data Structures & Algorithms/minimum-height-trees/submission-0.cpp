class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for (vector<int>& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>ans;
        int min_height=n;
        for (int i = 0; i < n; ++i){
            unordered_set<int>seen;
            int h = dfs(i,adj,seen);
            if (h<min_height) {
                min_height = h;
                ans.clear();
                ans.push_back(i);
            } else if (h==min_height) ans.push_back(i);
        }
        return ans;
    }

    int dfs(int i, const vector<vector<int>>&adj, unordered_set<int>& seen){
        seen.insert(i);
        int height = 0;
        for (int node : adj[i]){
            if (seen.count(node)) continue;
            height = max(dfs(node,adj,seen), height);
        }
        return 1+height;
    }
};