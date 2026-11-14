class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        vector<vector<int>>ans(m,vector<int>(n));
        ans.reserve(m);
        for (int i = 0; i < original.size(); ++i) {
            int row = i / n, col = i % n;
            ans[row][col] = original[i];
        }
        return ans;
    }
};
