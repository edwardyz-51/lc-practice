class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }

        int ans = -1, minCount = INT_MAX;

        for (int src = 0; src < n; ++src) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<>> pq;

            dist[src] = 0;
            pq.emplace(0, src);

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;
                if (d > distanceThreshold) break;

                for (auto& [v, w] : adj[u]) {
                    if (d + w < dist[v]) {
                        dist[v] = d + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }

            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (i != src && dist[i] <= distanceThreshold)
                    ++count;
            }

            if (count <= minCount) {
                minCount = count;
                ans = src;
            }
        }

        return ans;
    }
};