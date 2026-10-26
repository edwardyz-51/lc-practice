class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>bfs;
        int fresh = 0;
        for (int row = 0; row < n; ++row){
            for (int col = 0; col < m; ++col){
                int cur = grid[row][col];
                if (cur == 1) fresh++;
                else if (cur==2) bfs.push({row,col});
            }
        }
        if (!fresh) return 0;
        const vector<pair<int,int>> directions = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        int time = 0;
        while (!bfs.empty()){
            time++;
            int sz = bfs.size();
            for (int k = 0; k < sz; ++k){
                auto [row,col]=bfs.front();
                bfs.pop();
                for (auto [dx,dy] : directions){
                    int nr = row+dx, nc = col+dy;
                    if (nr<0 || nc < 0 || nr ==n || nc == m || grid[nr][nc]!=1) continue;
                    grid[nr][nc]=2;
                    fresh--;
                    if (!fresh) return time;
                    bfs.push({nr,nc});
                }
            }
        }
        return -1;
    }
};
