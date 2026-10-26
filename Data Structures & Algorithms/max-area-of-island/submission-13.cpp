class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        static constexpr int dir[] = {0,1,0,-1,0};
        auto dfs = [&ans, &grid](this auto&& self,int row, int col)->int{
            grid[row][col]=0;
            int area=1;
            for (size_t i(0uz); i < 4; ++i){
                int nr = row+dir[i], nc = col+dir[i+1];
                if (nr < 0 || nr >= grid.size() || nc < 0 || nc >=grid.front().size() || !grid[nr][nc]) continue;
                area+=self(nr,nc);
            }
            return area;
        };
        for (size_t row(0uz); row < grid.size(); ++row)
            for (size_t col(0uz); col < grid.front().size(); ++col)
                if (grid[row][col]) ans=max(ans,dfs(row,col));
        return ans;
    }
};
