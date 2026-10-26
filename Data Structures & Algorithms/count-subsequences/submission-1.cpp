class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for (int mdx = 0; mdx < m; ++mdx){
            for (int idx = mdx; idx < n; ++idx){
                if (idx) dp[mdx][idx] = dp[mdx][idx-1];
                if (s[idx]==t[mdx])
                    dp[mdx][idx]=mdx?dp[mdx][idx]+dp[mdx-1][idx-1]:dp[mdx][idx]+1;
                
            }
        }
        return dp[m-1][n-1];

    }
};  
