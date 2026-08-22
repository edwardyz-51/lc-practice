class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // if (edges.size() > n - 1) {
        //     return false;
        // }
        vector<vector<int>>adj(n);
        for (auto& v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        unordered_set<int>seen;
        return dfs(0,-1,seen,adj) ? seen.size()==n : false;
    }

    bool dfs(int node, int prev, unordered_set<int>&seen,const vector<vector<int>>&adj){
        
        if (seen.find(node) != seen.end()) return false;
        seen.insert(node);
        for (int nei : adj[node]){
            if (nei==prev) continue;
            if (!dfs(nei,node,seen,adj)) return false;
        }
        return true;
    }
};
