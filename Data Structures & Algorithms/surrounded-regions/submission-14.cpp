class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int rMax = board.size(), cMax = board[0].size();
        for (int row = 0; row < rMax; ++row){
            for (int col = 0; col < cMax; ++col){
                if (board[row][col] == 'O'){
                    vector<pair<int,int>> repair;
                    bool surrounded = dfs(row,col,board,repair);
                    for (auto &p : repair) {
                        board[p.first][p.second] = surrounded ? 'X' : 'O';
                    }
                }
            }
        }
    }

    bool dfs(int row, int col, vector<vector<char>>& board,vector<pair<int,int>>&repair){
        if (board[row][col] == '#' || board[row][col] == 'X') return true;
        board[row][col] = '#';
        repair.push_back({row, col});
        if (row == 0 || col == 0 ||
            row == board.size() - 1 ||
            col == board[0].size() - 1) return false;
        return 
            dfs(row+1,col,board,repair) &&
            dfs(row-1,col,board,repair) &&
            dfs(row,col+1,board,repair) &&
            dfs(row,col-1,board,repair);
    }
};
