class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<pair<int,int>>> adj(26);

        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].emplace_back(cost[i], v);
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for (int start = 0; start < 26; ++start) {
            priority_queue<pair<long long,int>,
                vector<pair<long long,int>>, greater<>> pq;

            dist[start][start] = 0;
            pq.emplace(0, start);

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[start][u]) continue;

                for (auto [weight, v] : adj[u]) {
                    if (d + weight < dist[start][v]) {
                        dist[start][v] = d + weight;
                        pq.emplace(dist[start][v], v);
                    }
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < source.size(); ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if (dist[u][v] == INF) return -1;

            ans += dist[u][v];
        }

        return ans;
    }
};