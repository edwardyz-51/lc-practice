class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid.front().size();
        static constexpr int dir[5] = {0,-1,0,1,0};
        vector<int>sizes;
        int ptr = 2, ans = 0;
        auto dfs = [&](this auto&&dfs, int row, int col) -> int {
            grid[row][col]=ptr;
            int size = 0;
            for (size_t i(0uz); i < 4; ++i){
                int nr = row + dir[i], nc = col + dir[i+1];
                if (nr < 0 || nc < 0 || nr >=N || nc >= M || grid[nr][nc]!=1) continue;
                size+=dfs(nr,nc);
            }
            return 1 + size;
        };
        for (size_t row(0uz); row < N; ++row)
            for (size_t col(0uz); col < M; ++col)
                if (grid[row][col]==1)
                    sizes.push_back(dfs(row,col)),ptr++;
                
        bool flag = true;
        for (size_t row(0uz); row < N; ++row){
            for (size_t col(0uz); col < M; ++col){
                if (grid[row][col]==0) {
                    flag = false;
                    int up = 0, left = 0, down = 0, right = 0; 
                    if (row > 0) up = grid[row-1][col];
                    if (col > 0) left = grid[row][col-1];
                    if (row < N-1) down = grid[row+1][col];
                    if (col < M-1) right = grid[row][col+1];
                    unordered_set<int> unique_islands = {up,left,right,down};
                    int current_size = 1; 
                    for (int island_id : unique_islands) 
                        if (island_id) current_size += sizes[island_id-2];
                    ans = max(ans, current_size);
                }
            }
        }
        return flag ? N * M : ans;


    }
};
