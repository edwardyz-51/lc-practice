class Solution {
    using boardT = vector<vector<int>>;
    using ansT = vector<vector<string>>;
    
public:
    vector<vector<string>> solveNQueens(int n) {
        ansT ans;
        boardT board(n,vector<int>(n,0));
        vector<string> sub(n, string(n, '.'));
        for (int col = 0; col < n; ++col){
            dfs(0,col,sub,board,ans,n,0);
            backtrack(0, col, sub, board, n);
        }
        return ans;
    }

    void backtrack(int row, int col, vector<string>& sub, boardT& board, int n){
        int prev = board[row][col];
        sub[row][col] = '.';
        for (int k = 0; k < n; ++k){
            if ((row + k < n) && (col + k < n)) board[row+k][col+k]--; 
            if ((row - k >= 0) && (col - k >= 0)) board[row-k][col-k]--;
            if ((row + k < n) && (col - k >= 0)) board[row+k][col-k]--; 
            if ((row - k >= 0) && (col + k < n)) board[row-k][col+k]--;
            board[k][col]--;
            board[row][k]--;
            }
        board[row][col] = prev-1;   
    }

    void dfs (int row, int col, vector<string>& sub, boardT& board, ansT& ans, int n, int count){
        if (row < 0 || col < 0 || row == n || col == n || board[row][col]) return;
        sub[row][col] = 'Q';
        int prev = board[row][col];
        for (int k = 0; k < n; ++k){
            if ((row + k < n) && (col + k < n)) board[row+k][col+k]++;
            if ((row - k >= 0) && (col - k >= 0)) board[row-k][col-k]++;
            if ((row + k < n) && (col - k >= 0)) board[row+k][col-k]++; 
            if ((row - k >= 0) && (col + k < n)) board[row-k][col+k]++;
            board[k][col]++;
            board[row][k]++;
        }
        board[row][col] = prev+1;
        if (count+1==n) {
            ans.push_back(sub);
            return;
        }
        for(int r = row; r < n; ++r){
            for (int c = 0; c < n; ++c){
                if (!board[r][c]) {
                    dfs(r,c,sub,board,ans,n,count+1);
                    backtrack(r, c, sub, board, n);
                }
            }
        }
    }
};
