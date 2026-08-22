#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return -1;
        int rMax = grid.size(), cMax = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for (int r = 0; r < rMax; r++) {
            for (int c = 0; c < cMax; c++) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh++;
            }
        }
        int time = 0;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && fresh > 0) {
            int layer = q.size();

            for (int i = 0; i < layer; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto &d : dirs) {
                    int nr = r + d.first;
                    int nc = c + d.second;

                    if (nr >= 0 && nr < rMax && nc >= 0 && nc < cMax
                        && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }

            time++; // finished one minute
        }

        return (fresh == 0) ? time : -1;
    }
};
