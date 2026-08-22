class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto& node : times){
            adj[node[0]].push_back({node[1], node[2]});
            // target, time
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> active;
        vector<int> dist(n+1, INT_MAX);
        vector<char> done(n+1, 0);

        dist[k] = 0;
        active.push({0, k});

        int time = 0;
        int visited = 0;

        while (visited != n){
            if (active.empty()) return -1;

            auto [t, u] = active.top();
            active.pop();

            if (done[u]) continue;          // already finalized
            if (t != dist[u]) continue;     // stale heap entry

            done[u] = 1;
            visited++;
            time = max(time, t);

            for (auto& [v, w] : adj[u]) {
                if (!done[v] && dist[v] > t + w) {
                    dist[v] = t + w;
                    active.push({dist[v], v});
                }
            }
        }

        return time;
    }
};