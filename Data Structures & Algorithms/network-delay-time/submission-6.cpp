class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto& node : times)
            adj[node[0]].push_back({node[1], node[2]});
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> active;
        vector<int> dist(n+1, INT_MAX);
        vector<bool> done(n+1, false);
        dist[k] = 0;
        active.push({0, k});
        int time = 0, visited = 0;
        while (visited != n){
            if (active.empty()) return -1;
            auto [t, node] = active.top();
            active.pop();
            if (done[node] || t!=dist[node]) continue;          // already finalized  || stale heap entry
            done[node] = true;
            visited++;
            time = max(time, t);

            for (auto& [vi, ti] : adj[node]) {
                if (!done[vi] && dist[vi] > t + ti) {
                    dist[vi] = t + ti;
                    active.push({dist[vi], vi});
                }
            }
        }

        return time;
    }
};