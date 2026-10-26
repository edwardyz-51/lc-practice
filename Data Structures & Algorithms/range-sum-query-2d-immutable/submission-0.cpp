class NumMatrix {
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        prefix = vector<vector<int>>(n,vector<int>(m,0));
        for (int r = 0; r < n; ++r){
            int sum = 0;
            for (int c = 0; c < m; ++c){
                sum += matrix[r][c];
                int temp = r>0 ? prefix[r-1][c] : 0;
                prefix[r][c]=sum+temp;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];
        int topLeft = row1>0  && col1>0 ? prefix[row1-1][col1-1] : 0;
        int above = row1>0 ? prefix[row1-1][col2] : 0;
        int left = col1>0 ? prefix[row2][col1-1] : 0;
        return total+topLeft-above-left;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */