class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return -1;
        int rMax = grid.size();
        int cMax = grid[0].size();
        queue<pair<pair<int,int>,int>>BFS;
        int total_time = 0;
        int fresh=0;
        for (int row = 0; row<rMax;++row){
            for (int col = 0; col<cMax; ++col){
                if (grid[row][col]==2) BFS.push({{row,col},0});
                if (grid[row][col]==1) fresh++;
            }
        }
        vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        while (!BFS.empty()){
            int curRow = BFS.front().first.first;
            int curCol = BFS.front().first.second;
            int time = BFS.front().second;
            BFS.pop();
            for (const auto &d : directions){
                int newRow = curRow+d.first;
                int newCol = curCol+d.second;
                if (newRow>=0  && newRow<rMax 
                && newCol>=0 && newCol<cMax
                && grid[newRow][newCol]==1){
                    fresh--;
                    grid[newRow][newCol]=2;
                    BFS.push({{newRow,newCol},time+1});
                    total_time =time+1;
                }
            }
        }
        return fresh == 0 ? total_time : -1;
    }
};
