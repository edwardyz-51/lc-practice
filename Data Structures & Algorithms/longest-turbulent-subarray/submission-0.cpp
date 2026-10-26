class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        size_t n = arr.size();
        if (n==1) return 1;
        vector<array<int, 2>> dp(n, array<int, 2>{1, 1});
        int ans = 1;
        for (size_t i(1uz); i < n; ++i){
            if (arr[i] > arr[i-1]) dp[i][0] = dp[i-1][1]+1;
            else if (arr[i] < arr[i-1]) dp[i][1] = dp[i-1][0]+1;
            ans = max ({ans, dp[i][1], dp[i][0]});
        }
        return ans;
    }
};