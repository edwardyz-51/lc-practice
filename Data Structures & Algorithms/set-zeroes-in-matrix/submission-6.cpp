class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool row = false, col = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[0][i]==0) row = true;
            
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[i][0]==0) col = true;
            
        }
        for (int r = 1; r < n; ++r){
            for (int c = 1; c < m; ++c){
                if (matrix[r][c]==0){
                    matrix[0][c]=0;
                    matrix[r][0]=0;
                }
            }
        }
        for (int r = 1; r < n; ++r) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < m; ++c) matrix[r][c] = 0;
            }
        }
        for (int c = 1; c < m; ++c) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < n; ++r) matrix[r][c] = 0;
            }
        }
        if(row){
            for (int i = 0; i < m; ++i){
                matrix[0][i]=0;
            }
        }
        if(col){
            for (int i = 0; i < n; ++i){
                matrix[i][0]=0;
            }
        }
         
    }
};
