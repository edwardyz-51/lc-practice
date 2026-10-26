class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < N; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < N; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<bool>seen(N,false);
        int ans = 0, visited = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            if (seen[node]) continue;
            seen[node] = true;
            ans+=cost;
            visited++;
            if (visited==N) return ans;
            for (auto& [dc, next] : adj[node]){
                if (seen[next]) continue;
                pq.push({dc,next});
            }

        }
        return visited == N ? ans : -1;

    }
};