class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        int count = 0;
        for (size_t row(0uz); row < N; ++row){
            for (size_t col(0uz); col < M; ++col){
                if (matrix[row][col]){
                    if (row > 0 && col > 0) {
                        matrix[row][col] = 1 + min({
                            matrix[row-1][col], matrix[row-1][col-1], matrix[row][col-1]
                        });
                    }
                    count+=matrix[row][col];
                }
            }
        }
        return count;
    }
};