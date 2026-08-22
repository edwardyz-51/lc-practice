class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rMax = board.size();
        int cMax = board[0].size();
        for (int row = 0; row < rMax; ++row){
            for (int col = 0; col < cMax; ++col){
                if (board[row][col] == word[0]) {
                    if (dfs(board,word,row,col,0)) return true;
                }
            }
        }
        return false;
    }

        bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int idx) {

        if (idx == word.size()) return true;

        if (r < 0 || c < 0 ||
            r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[idx]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';  // mark visited

        bool found =
            dfs(board, word, r + 1, c, idx + 1) ||
            dfs(board, word, r - 1, c, idx + 1) ||
            dfs(board, word, r, c + 1, idx + 1) ||
            dfs(board, word, r, c - 1, idx + 1);

        board[r][c] = temp; // unmark
        return found;
    }
};
