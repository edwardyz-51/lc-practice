class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int>dp(n,INT_MAX);
        for (size_t i(0uz); i < n; ++i){
            int width = 0, height = 0;
            for (int j = i; j >= 0; --j){
                width +=books[j][0];
                if (width > shelfWidth) break;
                height = max(height,books[j][1]);
                dp[i]=min(dp[i], (j==0 ? 0 : dp[j-1]) + height);
            }
        }
        return dp[n-1];
    }
};
