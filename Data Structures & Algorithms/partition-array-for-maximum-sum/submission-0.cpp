class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        auto dfs = [&](this auto& dfs,int idx)->int{
            if (idx<0)return 0;
            if (dp[idx]!=-1) return dp[idx];
            int curMax = arr[idx];
            for (int j = idx; idx - j +1 <= k && j >=0; --j){
                curMax=max(curMax,arr[j]);
                dp[idx]=max(curMax * (idx - j +1) + dfs(j-1),dp[idx]);
            }
            return dp[idx];
        };
        return dfs(n-1);

    }
};
