class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<long long> prev(cols);
        for (int c = 0; c < cols; c++) prev[c] = points[0][c];
        for (int r = 1; r < rows; r++) {
            vector<long long> cur(cols);
            cur[0] = prev[0];
            long long leftMax = prev[0];
            for (int c = 1; c < cols; c++){
                leftMax = max(prev[c], leftMax - 1);
                cur[c] = leftMax;
            }
            cur[cols - 1] += points[r][cols - 1];
            long long rightMax = prev[cols - 1];
            for (int c = cols - 2; c >= 0; c--) {
                rightMax = max(prev[c], rightMax - 1);
                cur[c] = max(cur[c], rightMax) + points[r][c];
            }
            
            prev = cur;
        }
        return *max_element(prev.begin(), prev.end());
    }
};