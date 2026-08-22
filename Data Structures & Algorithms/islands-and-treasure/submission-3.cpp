#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return;
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // multi-source BFS: start from every treasure (0)
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) q.push({r, c});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int nextDist = grid[r][c] + 1;

            // up
            if (r - 1 >= 0 && grid[r - 1][c] != -1 && grid[r - 1][c] > nextDist) {
                grid[r - 1][c] = nextDist;
                q.push({r - 1, c});
            }
            // down
            if (r + 1 < m && grid[r + 1][c] != -1 && grid[r + 1][c] > nextDist) {
                grid[r + 1][c] = nextDist;
                q.push({r + 1, c});
            }
            // left
            if (c - 1 >= 0 && grid[r][c - 1] != -1 && grid[r][c - 1] > nextDist) {
                grid[r][c - 1] = nextDist;
                q.push({r, c - 1});
            }
            // right
            if (c + 1 < n && grid[r][c + 1] != -1 && grid[r][c + 1] > nextDist) {
                grid[r][c + 1] = nextDist;
                q.push({r, c + 1});
            }
        }
    }
};
