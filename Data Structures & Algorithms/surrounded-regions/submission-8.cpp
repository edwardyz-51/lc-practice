class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int rMax = (int)board.size(), cMax = (int)board[0].size();

        for (int row = 0; row < rMax; ++row) {
            for (int col = 0; col < cMax; ++col) {
                if (board[row][col] == 'O') {
                    vector<pair<int,int>> cells;
                    bool enclosed = dfs(row, col, board, cells);
                    for (auto &p : cells) {
                        board[p.first][p.second] = enclosed ? 'X' : 'O';
                    }
                }
            }
        }
    }

    bool dfs(int row, int col, vector<vector<char>>& board, vector<pair<int,int>>& cells) {
        if (board[row][col] == 'X' || board[row][col] == '#') return true;

        // if this region touches the border, it's NOT enclosed
        if (row == 0 || col == 0 || row == (int)board.size() - 1 || col == (int)board[0].size() - 1) {
            board[row][col] = '#';
            cells.push_back({row, col});
            return false;
        }

        board[row][col] = '#';
        cells.push_back({row, col});

        bool surround =
            dfs(row + 1, col, board, cells) &&
            dfs(row - 1, col, board, cells) &&
            dfs(row, col + 1, board, cells) &&
            dfs(row, col - 1, board, cells);

        return surround;
    }
};
