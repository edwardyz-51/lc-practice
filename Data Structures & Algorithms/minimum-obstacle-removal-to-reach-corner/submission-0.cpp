class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.emplace_front(0, 0);

        constexpr int dir[] = {0, 1, 0, -1, 0};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dir[d], nc = c + dir[d + 1];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;

                int nextCost = dist[r][c] + grid[nr][nc];

                if (nextCost >= dist[nr][nc])
                    continue;

                dist[nr][nc] = nextCost;

                if (grid[nr][nc] == 0)
                    dq.emplace_front(nr, nc);
                else
                    dq.emplace_back(nr, nc);
            }
        }

        return dist[N - 1][M - 1];
    }
};