class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        vector<int>prev = matrix[0];
        for (size_t row = 1; row < n; ++row){
            vector<int> next(n);
            for (size_t col = 0; col < n; ++col){
                if (!col) next[col] = min(prev[col], prev[col+1]);
                else if (col + 1 == n) next[col] = min(prev[col], prev[col-1]);
                else next[col] = min ({prev[col], prev[col-1], prev[col+1]});
                next[col] += matrix[row][col];
            }
            prev = next;
        }
        return *min_element(prev.begin(),prev.end());
    }
};
