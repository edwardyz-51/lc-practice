class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));

        for (auto& e : redEdges)
            adj[0][e[0]].push_back(e[1]);

        for (auto& e : blueEdges)
            adj[1][e[0]].push_back(e[1]);

        vector<vector<bool>> seen(2, vector<bool>(n, false));
        vector<int> ans(n, -1);

        queue<pair<int,int>> bfs;
        bfs.push({0, 0});
        bfs.push({0, 1});

        seen[0][0] = seen[1][0] = true;

        int dist = 0;

        while (!bfs.empty()) {
            int sz = bfs.size();

            while (sz--) {
                auto [node, lastColor] = bfs.front();
                bfs.pop();

                if (ans[node] == -1)
                    ans[node] = dist;

                int nextColor = 1 - lastColor;

                for (int next : adj[nextColor][node]) {
                    if (seen[nextColor][next]) continue;

                    seen[nextColor][next] = true;
                    bfs.push({next, nextColor});
                }
            }

            dist++;
        }

        return ans;
    }
};