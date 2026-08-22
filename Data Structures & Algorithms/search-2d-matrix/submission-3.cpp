class Solution {
public:
    bool binarySearch(vector<int>&search, int target){
        int l = 0, r = search.size()-1;
        while (l<=r){
            int m = (l+r)/2;
            if (search[m] < target) l=m+1;
            else if (search[m]>target) r = m-1;
            else return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size()-1;
        int n = matrix.size(), m = matrix[0].size();
        while (top<=bottom){
            int middle = top + (bottom - top) / 2;;
            if (matrix[middle][0] > target) bottom = middle-1;
            else if (matrix[middle][m-1] < target) top = middle+1;
            else return binarySearch(matrix[middle],target);
        }
        return false;
    }
};