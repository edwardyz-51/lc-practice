class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) return false;
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        auto dfs = [&](this auto& dfs, int i, int j, int k)->bool{
            if (k == s3.length()) return true;
            if (dp[i][j] != -1) return dp[i][j];
            bool res = false;
            if (i < s1.length() && s1[i] == s3[k]) 
                res = dfs(i + 1, j, k + 1);
            
            if (!res && j < s2.length() && s2[j] == s3[k]) 
                res = dfs(i, j + 1, k + 1);
            

            dp[i][j] = res;
            return res;
        };
        return dfs(0, 0, 0);
    }
};