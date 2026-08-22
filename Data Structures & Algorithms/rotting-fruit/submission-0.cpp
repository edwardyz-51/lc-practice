class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>BFS;
        int total_time = 0;
        int fresh=0;
        for (int row = 0; row<grid.size();++row){
            for (int col = 0; col<grid[0].size(); ++col){
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
            for (auto d : directions){
                int newRow = curRow+d.first;
                int newCol = curCol+d.second;
                if (newRow>=0  && newRow<grid.size() 
                && newCol>=0 && newCol<grid[0].size() 
                && grid[newRow][newCol]==1){
                    fresh--;
                    grid[newRow][newCol]=2;
                    BFS.push({{newRow,newCol},time+1});
                }
            }
            if (time>total_time) total_time = time;
        }
        cout <<fresh;
        if (fresh==0) return total_time;
        return -1;
    }
};
