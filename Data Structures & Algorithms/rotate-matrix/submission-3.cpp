class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size() - 1;
        //bottom left = matrix[bottom-i][l]
        //bottom right = matrix[bottom][r-i]
        //top left = matrix[top][l+i]
        while ( l < r ) {
            for(int i = 0; i < r - l; i++) {

                int topLeft = matrix[l][l + i];
                //move bottom left into top left
                matrix[l][l + i] = matrix[r - i][l];

                // move bottom right into bottom left
                matrix[r - i][l] = matrix[r][r - i];

                // move top right into bottom right
                matrix[r][r - i] = matrix[l + i][r];

                // move top left into top right
                matrix[l + i][r] = topLeft;

            }
            r--;
            l++;
        }
    }
};