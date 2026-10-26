class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        static constexpr int dir[] = {0,1,0,-1,0};
        auto dfs = [&ans, &grid](auto&& dfs,int row, int col)->void{
            for (size_t i(0uz); i < 4; ++i){
                int nr = row+dir[i], nc = col+dir[i+1];
                if (nr < 0 || nr >= grid.size() || nc < 0 || nc >=grid.front().size() || grid[nr][nc]=='0') continue;
                grid[nr][nc]='0';
                dfs(dfs,nr,nc);
            }
        };
        for (size_t row(0uz); row < grid.size(); ++row)
            for (size_t col(0uz); col < grid.front().size(); ++col)
                if (grid[row][col]=='1') ans++, dfs(dfs,row,col);
        return ans;
    }
};