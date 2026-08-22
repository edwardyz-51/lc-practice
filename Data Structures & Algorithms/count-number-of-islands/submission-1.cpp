class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int vert = 0; vert < grid.size(); ++vert){
            for (int horizontal = 0; horizontal <grid[0].size();++horizontal){
                if (grid[vert][horizontal]=='1') {
                    dfs(grid,{vert,horizontal});
                    count++;
                }
                
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>&grid, pair<int,int>loc){
        grid[loc.first][loc.second] = '0';
        if (!(loc.first-1<0) && grid[loc.first-1][loc.second]=='1'){
            dfs(grid,{loc.first-1,loc.second});
        }
        if (!(loc.second-1<0) && grid[loc.first][loc.second-1]=='1'){
            dfs(grid,{loc.first,loc.second-1});
        }
        if (!(loc.first+1>grid.size()-1) && grid[loc.first+1][loc.second]=='1'){
            dfs(grid,{loc.first+1,loc.second});
        }
        if (!(loc.second+1>grid[0].size()-1) && grid[loc.first][loc.second+1]=='1'){
            dfs(grid,{loc.first,loc.second+1});
        }
    }
};
