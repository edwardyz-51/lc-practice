class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,vector<bool>>rows;
        unordered_map<int,vector<bool>>cols;
        map<pair<int,int>,vector<bool>> grids;
        for (int row = 0; row < 9; ++row){
            if (rows.find(row)==rows.end()) rows[row]=vector<bool>(10,false);
            for (int col = 0; col < 9; ++col){

                if (cols.find(col)==rows.end()) cols[col]=vector<bool>(10,false);
                pair<int,int>key = {row/3,col/3};
                if (grids.find(key) == grids.end()) grids[key]=vector<bool>(10,false);

                int cur = board[row][col];
                if (cur=='.') continue;
                cur = cur -'0';
                if (rows[row][cur] || cols[col][cur] || grids[key][cur]) return false;
                rows[row][cur] = true;
                cols[col][cur] = true;
                grids[key][cur] = true;

            }
        }
        return true;
    }
    
};
