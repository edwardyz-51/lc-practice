class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyAt = INT_MAX, ans = 0;
        for (int i : prices){
            buyAt = min(buyAt,i);
            ans = max(ans,i-buyAt);
        }
        return ans;
    }
};
