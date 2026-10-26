class Solution {
vector<unordered_set<char>>rows,cols;
vector<vector<unordered_set<char>>>boxes;
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        rows.resize(board.size());
        cols.resize(board.size());
        boxes = vector<vector<unordered_set<char>>>
        (board.size()/3 + 1, vector<unordered_set<char>>(board.front().size()+1));

        for (int row = 0; row < board.size(); ++row){
            for (int col = 0; col < board[0].size(); ++col){
                char cur = board[row][col];
                if (cur == '.') continue;
                pair<int,int> key = {row/3,col/3};
                if (cols[col].count(cur) || rows[row].count(cur) 
                || boxes[row/3][col/3].count(cur)) return false;
                cols[col].insert(cur);
                rows[row].insert(cur);
                boxes[row/3][col/3].insert(cur);
            }
        }
        return true;
    }
};
