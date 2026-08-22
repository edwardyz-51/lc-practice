
class Solution {
   
public:
        
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rMAX = heights.size();
        int cMAX = heights[0].size();
        vector<vector<bool>> pacific(rMAX, vector<bool>(cMAX, false));
        vector<vector<bool>> atlantic(rMAX, vector<bool>(cMAX, false));
        for (int row = 0; row < rMAX; ++row){
            dfs(row,0,pacific, heights[row][0],heights);
            dfs(row,cMAX-1, atlantic, heights[row][cMAX-1],heights);
        }
        for (int col = 0; col < cMAX; ++col){
            dfs(0,col, pacific, heights[0][col],heights);
            dfs(rMAX-1,col, atlantic, heights[rMAX-1][col],heights);
        }

        vector<vector<int>>ans;
        for (int r = 0; r < rMAX;++r){
            for (int c = 0; c<cMAX;++c){
                if (pacific[r][c] && atlantic[r][c]) ans.push_back({r,c});
            }    
        }
        return ans;
    }

    void dfs(int row, int col, vector<vector<bool>>& visit, int prev, const vector<vector<int>>& heights){
        int rMAX = heights.size();
        int cMAX = heights[0].size();
        if (row < 0 || row ==rMAX || col <0 || col ==cMAX || heights[row][col] < prev || visit[row][col]==true) return;
        visit[row][col]=true;
        dfs(row+1,col,visit,heights[row][col],heights);
        dfs(row-1,col,visit,heights[row][col],heights);
        dfs(row,col+1,visit,heights[row][col],heights);
        dfs(row,col-1,visit,heights[row][col],heights);
    }

    //if row or col = 0, touching pacific
    //if row or col = grid.size()/grid[0].size(), touching atlantic.
};
