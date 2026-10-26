class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = prices.front(), ans = 0;
        for (int idx = 1; idx < prices.size(); ++idx){
            if (prices[idx]>prev) ans+= prices[idx]-prev;
            prev = prices[idx];
        }
        return ans;
    }
};