class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int verticalLow = 0;
        int verticalHigh = matrix.size()-1;
        while (verticalLow <= verticalHigh) {
            int verticalMid = (verticalLow + verticalHigh)/2;
            if (matrix[verticalMid].front() <= target && target <= matrix[verticalMid].back() ) {
                int horizontalLow = 0;
                int horizontalHigh = matrix[verticalMid].size()-1;
                while (horizontalLow<=horizontalHigh) {
                    int horizontalMid = (horizontalLow + horizontalHigh)/2;
                    if (matrix[verticalMid][horizontalMid] == target) {
                        return true;
                    }
                    if (target < matrix[verticalMid][horizontalMid]) {
                        horizontalHigh = horizontalMid-1;
                    }
                    if (target > matrix[verticalMid][horizontalMid]) {
                        horizontalLow = horizontalMid+1;
                    }   
                }
                 return false;
            }
            if (matrix[verticalMid].front() > target){
                verticalHigh = verticalMid-1;
            }
            if (matrix[verticalMid].back() < target){
                verticalLow = verticalMid+1;
            }
        }
        return false;
    }
};
