class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>connect(n);
        int count = 0;
        for (auto& v : edges){
            connect[v[0]].push_back(v[1]);
            connect[v[1]].push_back(v[0]);
        }
        vector<bool>visited(n);
        for (int node = 0; node < n; ++node){
            if (visited[node]) continue;
            findPath(node, connect,visited);
            count++;
        }
        return count;
    }

    void findPath(int node, const vector<vector<int>>&connect, vector<bool>&visited){
        if (visited[node]) return;
        visited[node] = true;
        for (int cur : connect[node]){
            findPath(cur,connect,visited);
        }
    }
};
