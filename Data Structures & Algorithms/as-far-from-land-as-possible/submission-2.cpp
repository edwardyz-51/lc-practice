class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int N = grid.size(), M = grid[0].size();
        int ans = -1, dist = 0;
        queue<pair<int,int>>bfs;
        for (size_t row(0uz); row < N; ++row)
            for (size_t col(0uz); col < M; ++col)
                if (grid[row][col]==1) bfs.push({row,col});
        constexpr int dir[] = {0,1,0,-1,0};
        while (!bfs.empty()){
            size_t sz = bfs.size();
            for (size_t _(0uz); _ < sz; ++_){
                auto [row,col] = bfs.front();
                bfs.pop();
                for (size_t i(0uz); i < 4; ++i){
                    int nr = row + dir[i], nc = col + dir[i+1];
                    if (nr < 0 || nc < 0 || nr == N || nc == N 
                    || grid[nr][nc] != 0) continue;
                    grid[nr][nc] = 1; 
                    ans = dist+1;
                    bfs.push({nr,nc});
                }
            } dist++;
        }
        return ans;
    }
};
