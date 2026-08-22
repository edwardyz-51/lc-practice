class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0, r = matrix.size() - 1;

        while ( l < r ) {
            for(int i = 0; i < r - l; i++) {
                int top = l, bottom = r, topLeft = matrix[top][l + i];
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