class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        size_t n = arr.size();
        if (n==1) return 1;
        vector<array<int, 2>> dp(n, array<int, 2>{1, 1});
        int ans = 1;
        int prevlow = 1, prevhigh = 1;
        int cur = 1;
        for (size_t i(1uz); i < n; ++i){
            if (arr[i] > arr[i-1]) 
                cur = prevlow + 1, prevhigh = cur, prevlow = 1;
            else if (arr[i] < arr[i-1]) 
                cur = prevhigh + 1, prevlow = cur, prevhigh = 1;
            else prevhigh = 1, prevlow = 1;
            ans = max (ans, cur);
        }
        return ans;
    }
};